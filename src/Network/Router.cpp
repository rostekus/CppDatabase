#include "Router.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <ostream>
#include <utility>

httpserver::Router::Router(std::unique_ptr<IRequestParser> requestParser)
    : requestParser(std::move(requestParser)) {}

void httpserver::Router::registerRoute(std::string url, Method method,
                                       httpserver::IHandler handler) {
  //	m_routes[std::make_pair(url, method)] = handler;
}
void httpserver::Router::route(std::string httpRequest) {
  Request req = requestParser->parseRequest(httpRequest);
  std::cout << "METHOD " << req.method << "\n";
  std::cout << "URL " << req.url << "\n";
  for (const auto& item : req.body_json) {
    std::cout << item.first << " " << item.second << std::endl;
  }
  // IHandler handler = m_routes[std::make_pair(req.url, req.method)];
  // Response resp = handler.handle(req);
}
