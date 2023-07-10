//
// Created by Rostyslav Mosorov on 07/07/2023.
//

#ifndef DB_HTTPSERVER_HPP
#define DB_HTTPSERVER_HPP

// #include <spdlog/spdlog.h>
namespace httpserver {
class HTTPServer {
 public:
  HTTPServer();
  HTTPServer(int port);
  ~HTTPServer() = default;
  void serve();
  void testLog();

 private:
  int mPort;
};
}  // namespace httpserver
#endif  // DB_HTTPSERVER_HPP
