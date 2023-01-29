#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// This function handles incoming connections
void handle_connection(int connection_fd) {
    char client_message[256];
    int read_size;

    // Receive a message from the client
    while((read_size = recv(connection_fd, client_message, 256, 0)) > 0 ) {
        // Send the client's message back
        write(connection_fd, client_message, read_size);
    }
}

// This function is the entry point for the TCP server
int main(int argc, char *argv[]) {
    // Create the server socket
    int server_socket_fd;
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    // Bind the socket to a port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons( 8888 );

    // Bind the socket to the address
    if (bind(server_socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding to port\n");
        return -1;
    }

    // Listen for incoming connections
    listen(server_socket_fd, 5);

    int connection_fd;
    struct sockaddr_in client_addr;
    socklen_t client_addr_size;

    while(1) {
        // Accept an incoming connection
        connection_fd = accept(server_socket_fd, (struct sockaddr *)&client_addr, &client_addr_size);
        if (connection_fd < 0) {
            printf("Error accepting connection\n");
            return -1;
        }

        // Handle the connection
        handle_connection(connection_fd);

        // Close the connection
        close(connection_fd);
    }
}// Author: William Selby
// TCP server written in c

