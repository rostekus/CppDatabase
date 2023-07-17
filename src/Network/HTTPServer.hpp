//
// Created by Rostyslav Mosorov on 07/07/2023.
//

#ifndef DB_HTTPSERVER_HPP
#define DB_HTTPSERVER_HPP

// #include <spdlog/spdlog.h>
#include <memory>

#include "API/IRouter.hpp"
namespace httpserver {
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
