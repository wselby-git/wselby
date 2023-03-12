#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <openssl/aes.h>

#define PORT 8080
#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFSIZE];
    char key[] = "MySecretKey12345"; // 16-byte AES256 key
    char iv[] = "0123456789abcdef"; // 16-byte initialization vector
    AES_KEY aes_key;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Get server hostname from command line arguments
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    // Initialize server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Initialize AES key
    AES_set_encrypt_key(key, 256, &aes_key);

    // Get user input
    printf("Enter message: ");
    bzero(buffer, BUFSIZE);
    fgets(buffer, BUFSIZE-1, stdin);

    // Encrypt message using AES256
    int len = strlen(buffer);
    int padlen = len % AES_BLOCK_SIZE == 0 ? 0 : AES_BLOCK_SIZE - len % AES_BLOCK_SIZE;
    memset(buffer + len, padlen, padlen); // padding
    AES_cbc_encrypt(buffer, buffer, len + padlen, &aes_key, iv, AES_ENCRYPT);

    // Send encrypted message to server
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Print message sent
    printf("Message sent: %s", buffer);

    // Close socket
    close(sockfd);
    return 0;
}
