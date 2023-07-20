#ifndef HPP_RESPONSE
#define HPP_RESPONSE
#include <map>
#include <string>

namespace httpserver {
typedef std::map<std::string, std::string> Headers;
typedef std::string Body;
class Response {
 public:
  Response(int code, Headers headers, Body body)
      : code(code), mHeaders(headers), mBody(body) {}
  int code;
  Headers mHeaders;
  Body mBody;
};
}  // namespace httpserver

#endif  // !HPP_RESPONSE
