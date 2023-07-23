//
// Created by Rostyslav Mosorov on 07/07/2023.
//

#ifndef DB_IDATABASE_HPP
#define DB_IDATABASE_HPP

#include <map>
#include <string>

#include "filesystem"
namespace db {

class IDatabase {
 public:
  IDatabase(std::string dbname, std::filesystem::path fullpath);

  IDatabase(std::string dbname);

  IDatabase() = default;

  virtual ~IDatabase() noexcept = default;

  virtual void setKeyValue(const std::string& key,
                           const std::string& value) = 0;

  virtual std::string getValueKey(const std::string& key) = 0;

  virtual std::map<std::string, std::string> getAllKeyValue() = 0;
  virtual std::filesystem::path getFullpath() const = 0;
};
}  // namespace db
#endif  // DB_IDATABASE_HPP
