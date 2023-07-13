#include <map>
#include <stdexcept>
#include <string>

#include "Network/BodyParser.hpp"
#include "gtest/gtest.h"

TEST(BodyParser, testEmptyMap) {
  std::map<std::string, std::string> testMap;
  testMap["testKey"] = "testValue";
  try {
    BodyParser::parseBody("", testMap);
    FAIL();
  } catch (std::invalid_argument& err) {
    EXPECT_EQ(err.what(), std::string("map must be empty"));
  }
}
TEST(BodyParser, testEmptyBodyString) {
  std::map<std::string, std::string> testMap;
  try {
    BodyParser::parseBody("", testMap);
    FAIL();
  } catch (std::invalid_argument& err) {
    EXPECT_EQ(err.what(), std::string("invalid JSON string format"));
  }

  EXPECT_EQ(testMap.empty(), true);
}

TEST(BodyParser, testKeyValueParsing) {
  std::map<std::string, std::string> testMap;
  std::string jsonString = R"({"hello" : "key"})";
  BodyParser::parseBody(jsonString, testMap);
  EXPECT_EQ(testMap["hello"], std::string("key"));
}
