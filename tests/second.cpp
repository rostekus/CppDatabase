#include "Database/ExtDatabase.hpp"
#include "gtest/gtest.h"

TEST(ExtDatabase, insert) {
  extdb::ExtDatabase db("");
  db.setKeyValue("key", "value");
  EXPECT_EQ("value", db.getValueKey("key"));
  db.destroy();
}
TEST(test, two) { EXPECT_EQ(1000, 1000); }
