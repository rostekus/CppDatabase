//
// Created by Rostyslav Mosorov on 07/07/2023.
//

#ifndef DB_HTTPSERVER_HPP
#define DB_HTTPSERVER_HPP

// #include <spdlog/spdlog.h>
#include <memory>
#include <string>

#include "API/IRouter.hpp"
namespace httpserver {

typedef std::string HTTPRequest;
typedef std::string HTTPResponse;
const int BUFFER_SIZE = 4096;
class HTTPServer {
 public:
  HTTPServer();
  HTTPServer(int port);
  ~HTTPServer() = default;
  void serve();
  void testLog();
  void registerRouter(std::unique_ptr<IRouter> router);

 private:
  std::unique_ptr<IRouter> mRouter;
  int mPort;
};
}  // namespace httpserver
#endif  // DB_HTTPSERVER_HPP
