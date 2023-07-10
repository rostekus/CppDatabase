//
// Created by Rostyslav Mosorov on 07/07/2023.
//

#include "ExtDatabase.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
using namespace extdb;
namespace fs = std::filesystem;

class ExtDatabase::Imp : public db::IDatabase {
 public:
  Imp(const std::string &dbname, const std::filesystem::path &fullpath);
  Imp(const std::string &dbname);
  Imp() = default;
  ~Imp() = default;
  std::filesystem::path getFullpath() const override;

  void destroy();
  void setKeyValue(const std::string &key, const std::string &value) override;
  std::string getValueKey(const std::string &key) override;

 private:
  const std::string mDbName;
  const std::string mFullpath;
};
void ExtDatabase::Imp::destroy() {
  std::cout << "deleted" << std::endl;
  fs::remove_all(".groundupdb");
}
ExtDatabase::Imp::Imp(const std::string &dbname)
    : mDbName(dbname), mFullpath(".groundupdb/" + dbname) {
  std::string basedir(".groundupdb");
  if (!fs::exists(basedir)) {
    fs::create_directory(basedir);
  }
  if (!fs::exists(mFullpath)) {
    fs::create_directory(mFullpath);
  }
}

std::string ExtDatabase::Imp::getValueKey(const std::string &key) {
  std::ifstream t(mFullpath + "/" + key + "_string.kv");
  std::string value;
  t.seekg(0, std::ios::end);
  value.reserve(t.tellg());
  t.seekg(0, std::ios::beg);

  value.assign((std::istreambuf_iterator<char>(t)),
               std::istreambuf_iterator<char>());

  return value;
}

void ExtDatabase::Imp::setKeyValue(const std::string &key,
                                   const std::string &value) {
  std::ofstream os;
  os.open(mFullpath + "/" + key + "_string.kv",
          std::ios::out | std::ios::trunc);
  os << value;
  os.close();
}

std::filesystem::path ExtDatabase::Imp::getFullpath() const {
  return std::filesystem::path(mFullpath);
}

ExtDatabase::Imp::Imp(const std::string &dbname,
                      const std::filesystem::path &fullpath)
    : mDbName(dbname), mFullpath(fullpath) {
  std::string basedir(".groundupdb");
  if (!fs::exists(basedir)) {
    fs::create_directory(basedir);
  }
  std::string dbfolder(basedir + "/" + dbname);
  if (!fs::exists(dbfolder)) {
    fs::create_directory(dbfolder);
  }
}

std::filesystem::path ExtDatabase::getFullpath() const {
  return mImp->getFullpath();
}

std::string ExtDatabase::getValueKey(const std::string &key) {
  return mImp->getValueKey(key);
}

void ExtDatabase::setKeyValue(const std::string &key,
                              const std::string &value) {
  return mImp->setKeyValue(key, value);
}

ExtDatabase::ExtDatabase(std::string dbname)
    : mImp(std::unique_ptr<Imp>(std::make_unique<Imp>(dbname))) {}

ExtDatabase::~ExtDatabase() noexcept = default;

void ExtDatabase::destroy() { return mImp->destroy(); }
