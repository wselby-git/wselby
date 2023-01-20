// Author: William Selby

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char** argv){
	int sock, result;
	struct sockaddr_in router_addr;
	unsigned int router_ip;

	//Get the router IP from the command line argument
	if(argc < 2){
		printf("Usage: %s <router_ip>\n", argv[0]);
		return 1;
	}
	router_ip = inet_addr(argv[1]);

	//Create a socket for communication with the router
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0){
		printf("Error creating socket\n");
		return 1;
	}
	
	//Setup the router address structure
	router_addr.sin_family = AF_INET;
	router_addr.sin_port = htons(80);
	router_addr.sin_addr.s_addr = router_ip;

	//Loop to continuously connect to the router
	while(1){
		//Connect to the router
		result = connect(sock, (struct sockaddr *)&router_addr, sizeof(router_addr));
		if(result < 0){
			printf("Error connecting to router\n");
			break;
		}
		
		//Sleep for a short amount of time
		sleep(1);
	}
	
	//Close the socket
	close(sock);

	return 0;
}
