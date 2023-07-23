#include <gtest/gtest.h>

#include "Network/ResponseSerializer.hpp"
#include "Network/Types/Response.hpp"

// Test fixture for ResponseSerializer tests
class ResponseSerializerTest : public testing::Test {
 protected:
};

TEST(ResponseSerializerTest, SerializeResponseWithStatusCode200AndJsonBody) {
  httpserver::Response response(200, {{"Server", "TestServer"}},
                                {{"key1", "value1"}, {"key2", "value2"}});

  httpserver::ResponseSerializer serializer;
  std::string serializedResponse = serializer.serialize(response);

  std::string expectedResponse =
      "HTTP/1.1 200 OK\r\n"
      "Content-Length: 40\r\n"
      "Content-Type: application/json\r\n"
      "Server: TestServer\r\n"
      "\r\n"
      "{\n"
      "\"key1\" : \"value1\",\n"
      "\"key2\" : \"value2\"\n"
      "}";
  EXPECT_EQ(serializedResponse, expectedResponse);
}

TEST(ResponseSerializerTest, SerializeResponseWithStatusCode404AndEmptyBody) {
  httpserver::Response response(404, {{"Server", "TestServer"}}, {});

  httpserver::ResponseSerializer serializer;
  std::string serializedResponse = serializer.serialize(response);

  std::string expectedResponse =
      "HTTP/1.1 404 Not Found\r\n"
      "Content-Length: 4\r\n"
      "Content-Type: application/json\r\n"
      "Server: TestServer\r\n"
      "\r\n"
      "{\n\n}";
  EXPECT_EQ(serializedResponse, expectedResponse);
}
