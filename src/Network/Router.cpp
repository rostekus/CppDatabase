#include "Router.hpp"
#include "Types/Request.hpp"
#include "Types/Response.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <utility>

httpserver::Router::Router(std::unique_ptr<IRequestParser> requestParser)
    : requestParser(std::move(requestParser)) {}

void httpserver::Router::registerRoute(std::string url, Method method,
                                       httpserver::IHandler handler)  {
  //	m_routes[std::make_pair(url, method)] = handler;
}
std::string httpserver::Router::route(std::string httpRequest) {
  Request req = requestParser->parseRequest(httpRequest);
  // IHandler handler = m_routes[std::make_pair(req.url, req.method)];
  // Response resp = handler.handle(req);
  return std::string("");
}
