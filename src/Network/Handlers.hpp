#ifndef HPP_HANDLERS
#define HPP_HANDLERS

#include <algorithm>
#include <memory>

#include "../Database/IDatabase.hpp"
#include "API/IHandler.hpp"
#include "Types/Request.hpp"
#include "Types/Response.hpp"

namespace httpserver {

class DBHandler : public IHandler {
 public:
  DBHandler(std::shared_ptr<db::IDatabase> db) : database(std::move(db)) {}
  std::shared_ptr<db::IDatabase> getDB();

 private:
  std::shared_ptr<db::IDatabase> database;
};

class InsertKeyValueHandler : public DBHandler {
 public:
  InsertKeyValueHandler(std::shared_ptr<db::IDatabase> db)
      : DBHandler(std::move(db)){};
  Response handle(Request req) override;
};

class GetKeyValueHandler : public DBHandler {
 public:
  GetKeyValueHandler(std::shared_ptr<db::IDatabase> db)
      : DBHandler(std::move(db)){};
  Response handle(Request req) override;
};

}  // namespace httpserver

#endif  // !HPP_HANDLERS
