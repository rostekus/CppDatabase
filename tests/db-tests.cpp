#include "Database/ExtDatabase.hpp"
#include "gtest/gtest.h"

using namespace extdb;
TEST(ExtDatabaseTest, SetGetValueKeyTest) {
  std::string dbName = "test_db";
  std::string key = "test_key";
  std::string value = "test_value";

  ExtDatabase db(dbName);

  db.setKeyValue(key, value);

  std::string retrievedValue = db.getValueKey(key);

  EXPECT_EQ(retrievedValue, value);
  db.destroy();
}
