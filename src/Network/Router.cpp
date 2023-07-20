#include "Router.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <utility>

#include "API/IHandler.hpp"
#include "Handlers.hpp"
#include "Types/Request.hpp"
#include "Types/Response.hpp"

httpserver::Router::Router(std::unique_ptr<IRequestParser> requestParser)
    : requestParser(std::move(requestParser)) {}

void httpserver::Router::registerRoute(std::string url, Method method,
                                       std::unique_ptr<IHandler> handler) {
  m_routes[std::make_pair(url, method)] = std::move(handler);
}
std::string httpserver::Router::route(std::string httpRequest) {
  Request req = requestParser->parseRequest(httpRequest);
  std::cout << "GOT :" << req.url << " " << req.method << "\n";
  auto handler = std::move(m_routes[std::make_pair(req.url, req.method)]);
  if (handler != nullptr) {
    std::cout << "entered the handler \n";
    Response resp = handler->handle(req);
  }
  return std::string("");
}
