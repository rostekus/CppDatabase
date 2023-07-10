#include "HTTPServer.hpp"

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstdlib>
#include <cstring>

using namespace httpserver;

HTTPServer::HTTPServer(int port) : mPort(port){};

HTTPServer::HTTPServer() : mPort(8080){};
void HTTPServer::serve() {
  int server_fd, new_socket;
  long valread;
  struct sockaddr_in address;
  int addrlen = sizeof(address);

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("In sockets");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(mPort);

  std::memset(address.sin_zero, '\0', sizeof address.sin_zero);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("In bind");
    exit(EXIT_FAILURE);
  }
  if (listen(server_fd, 10) < 0) {
    perror("In listen");
    exit(EXIT_FAILURE);
  }
  printf("HTTP Server Initialized\nPort: %d\n", mPort);

  int client_socket;
  while (1) {
    char client_msg[4096] = "";

    client_socket = accept(server_fd, NULL, NULL);

    read(client_socket, client_msg, 4095);

    // parsing client socket header to get HTTP method, route
    char *method = "";
    char *urlRoute = "";

    char *client_http_header = strtok(client_msg, "\n");

    char *header_token = strtok(client_http_header, " ");

    int header_parse_counter = 0;

    while (header_token != NULL) {
      switch (header_parse_counter) {
        case 0:
          method = header_token;
        case 1:
          urlRoute = header_token;
      }
      header_token = strtok(NULL, " ");
      header_parse_counter++;
    }

    close(client_socket);
  }
};
