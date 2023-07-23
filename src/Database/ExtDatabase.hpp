//
// Created by Rostyslav Mosorov on 06/07/2023.
//

#ifndef DB_ExtDATABASE_HPP
#define DB_ExtDATABASE_HPP
#include "IDatabase.hpp"
#include "filesystem"

namespace extdb {
class ExtDatabase : public db::IDatabase {
 public:
  ExtDatabase(std::string dbname, std::filesystem::path fullpath);
  ExtDatabase(std::string dbname);

  ExtDatabase() = default;

  ~ExtDatabase() noexcept;

  void setKeyValue(const std::string& key, const std::string& value) override;

  std::string getValueKey(const std::string& key) override;
  std::filesystem::path getFullpath() const override;

  std::map<std::string, std::string> getAllKeyValue() override;
  void destroy();

 private:
  const std::filesystem::path mFullpath;

  class Imp;

  const std::unique_ptr<Imp> mImp;
};
}  // namespace extdb
#endif  // DB_ExtDATABASE_HPP
