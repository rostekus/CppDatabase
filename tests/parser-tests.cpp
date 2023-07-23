#include <gtest/gtest.h>

#include "Network/RequestParser.hpp"

class RequestParserTest : public testing::Test {
 protected:
};

TEST(RequestParserTest, ParseValidGETRequest) {
  httpserver::RequestParser parser;
  std::string httpRequest =
      "GET /path HTTP/1.1\r\n"
      "Host: example.com\r\n"
      "\r\n";

  httpserver::Request request = parser.parseRequest(httpRequest);

  EXPECT_EQ(request.method, httpserver::Method::GET);
  EXPECT_EQ(request.url, "/path");
  EXPECT_TRUE(request.body_json.empty());
}

TEST(RequestParserTest, ParseValidPOSTRequestWithJsonBody) {
  httpserver::RequestParser parser;
  std::string httpRequest =
      "POST /api/data HTTP/1.1\r\n"
      "Host: example.com\r\n"
      "Content-Type: application/json\r\n"
      "\r\n"
      "{ \"key1\": \"value1\", \"key2\": \"value2\" }";

  httpserver::Request request = parser.parseRequest(httpRequest);

  EXPECT_EQ(request.method, httpserver::Method::POST);
  EXPECT_EQ(request.url, "/api/data");
  EXPECT_EQ(request.body_json["key1"], "value1");
  EXPECT_EQ(request.body_json["key2"], "value2");
}

TEST(RequestParserTest, InvalidMethodString) {
  httpserver::RequestParser parser;
  std::string httpRequest =
      "INVALID_METHOD /path HTTP/1.1\r\n"
      "Host: example.com\r\n"
      "\r\n";

  EXPECT_THROW(parser.parseRequest(httpRequest), std::invalid_argument);
}

TEST(RequestParserTest, InvalidJsonBody) {
  httpserver::RequestParser parser;
  std::string httpRequest =
      "POST /api/data HTTP/1.1\r\n"
      "Host: example.com\r\n"
      "Content-Type: application/json\r\n"
      "\r\n"
      "{ \"key1\": \"value1\", \"key2\": \"value2\"";

  EXPECT_THROW(parser.parseRequest(httpRequest), std::invalid_argument);
}
