#include "Handlers.hpp"

#include <iostream>
#include <memory>

#include "Types/Response.hpp"

using namespace httpserver;
Response InsertKeyValueHandler::handle(Request req) {
  auto db = getDB();
  auto keyValuesMap = req.body_json;
  for (auto it = keyValuesMap.begin(); it != keyValuesMap.end(); it++) {
    db->setKeyValue(it->first, it->second);
  }
  Headers headers;
  Body body;
  Response resp(200, headers, body);
  return resp;
}

std::shared_ptr<db::IDatabase> DBHandler::getDB() { return database; }
