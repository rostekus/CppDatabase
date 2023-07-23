#include "Handlers.hpp"

#include <iostream>
#include <locale>
#include <memory>
#include <tuple>
#include <utility>

#include "Types/Response.hpp"

using namespace httpserver;
Response InsertKeyValueHandler::handle(Request req) {
  auto db = getDB();
  Body body;
  auto keyValuesMap = req.body_json;
  for (auto it = keyValuesMap.begin(); it != keyValuesMap.end(); it++) {
    db->setKeyValue(it->first, it->second);
    body[it->first] = "SET";
  }
  Headers headers;
  Response resp(200, headers, body);
  return resp;
}

Response GetKeyValueHandler::handle(Request req) {
  auto db = getDB();
  auto keyValuesMap = req.body_json;
  Body body;
  std::string value;
  if (db != nullptr) {
    for (auto it = keyValuesMap.begin(); it != keyValuesMap.end(); it++) {
      try {
        value = db->getValueKey(it->first);
      } catch (...) {
        value = std::string("KEY DOES NOT EXIST");
      }
      body[it->first] = value;
    }
  }
  Headers headers;
  Response resp(200, headers, body);
  return resp;
}

std::shared_ptr<db::IDatabase> DBHandler::getDB() { return database; }

Response GetAllKeyValueHandler::handle(Request req) {
  auto db = getDB();
  std::cout << "in all "
            << "\n";
  auto allKeyValuesMap = db->getAllKeyValue();
  Headers h;
  Response resp(200, h, allKeyValuesMap);
  return resp;
}
