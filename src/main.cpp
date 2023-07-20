//
// Created by Rostyslav Mosorov on 07/07/2023.
//
#include <algorithm>
#include <iostream>
#include <memory>

#include "Database/ExtDatabase.hpp"
#include "Network/API/IHandler.hpp"
#include "Network/HTTPServer.hpp"
#include "Network/Handlers.hpp"
#include "Network/RequestParser.hpp"
#include "Network/Router.hpp"
#include "Network/Types/Request.hpp"

int main() {
  httpserver::HTTPServer s;
  auto reqParser = std::make_unique<httpserver::RequestParser>();
  auto router = std::make_unique<httpserver::Router>(std::move(reqParser));
  auto db = std::make_shared<extdb::ExtDatabase>("mydb");
  std::unique_ptr<httpserver::IHandler> handler =
      std::make_unique<httpserver::InsertKeyValueHandler>(std::move(db));
  router->registerRoute("/insert", httpserver::Method::POST,
                        std::move(handler));
  s.registerRouter(std::move(router));
  s.serve();
  return 0;
}
