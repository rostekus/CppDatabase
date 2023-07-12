#include "HTTPServer.hpp"

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstdlib>
#include <cstring>
#include <regex>
#include <sstream>
#include <string>

#include "../Types/Request.hpp"

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
  int client_socket;
  while (1) {
    std::string client_msg;
    client_socket = accept(server_fd, NULL, NULL);
    std::string httpRequest;
    char buffer[4096];
    ssize_t bytesRead;
    while ((bytesRead = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
      httpRequest.append(buffer, bytesRead);
      if (httpRequest.find("\r\n\r\n") != std::string::npos) {
        break;
      }
    }

    std::string method;
    std::string url;
    std::string body;

    std::regex requestLineRegex(R"((\w+)\s+([^\s]+)\s+HTTP\/\d+\.\d+)");
    std::smatch requestLineMatch;
    if (std::regex_search(httpRequest, requestLineMatch, requestLineRegex)) {
      method = requestLineMatch[1];
      url = requestLineMatch[2];
    }

    std::regex bodyRegex("\r\n\r\n(.*)$");
    std::smatch bodyMatch;
    if (std::regex_search(httpRequest, bodyMatch, bodyRegex)) {
      body = bodyMatch[1];
    }

    request::RequestInsertValueKey req;
    req.parseRequest(body);
    close(client_socket);
  }
};
