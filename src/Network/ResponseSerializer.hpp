#ifndef RESPONSE_SERIALIZER_HPP
#define RESPONSE_SERIALIZER_HPP
#include <string>

#include "Types/Response.hpp"

namespace httpserver {

class ResponseSerializer {
 public:
  static std::string serialize(Response& response);

 private:
  static std::string getStatusPhrase(int code);
  static size_t calculateContentLength(const Body& body);
};
}  // namespace httpserver
#endif  // RESPONSE_SERIALIZER_HPP
