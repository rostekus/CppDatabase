//
// Created by Rostyslav Mosorov on 07/07/2023.
//

#include "ExtDatabase.hpp"

using namespace extdb;

class ExtDatabase::Imp : public db::IDatabase {
public:
    Imp(const std::string &dbname, const std::filesystem::path &fullpath);
    Imp(const std::string &dbname);
    Imp() = default;
    ~Imp() = default;
    std::filesystem::path getFullpath() const override;

    void setKeyValue(const std::string &key, const std::string &value) override;
    std::string getValueKey(const std::string &key) override;

private:
    const std::string mDbName;
    const std::string mFullpath;
};

ExtDatabase::Imp::Imp(const std::string &dbname) : mDbName(dbname) {}

std::string ExtDatabase::Imp::getValueKey(const std::string &key) {
  return std::string();
}

std::filesystem::path ExtDatabase::Imp::getFullpath() const {
  return std::filesystem::path("hello");
}

void ExtDatabase::Imp::setKeyValue(const std::string &key,
                                   const std::string &value) {}

ExtDatabase::Imp::Imp(const std::string &dbname,
                      const std::filesystem::path &fullpath)
        : mDbName(dbname), mFullpath(fullpath) {}

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
