#ifndef DB_REQUEST
#define DB_REQUEST

#include <cctype>
#include <map>
#include <string>

#include "Response.hpp"
namespace httpserver {

enum Method { GET, POST, DELETE, PUT, PATCH };
typedef std::map<std::string, std::string> Headers;
typedef std::map<std::string, std::string> BodyJson;

class Request {
 public:
  std::string url;
  Method method;
  Headers headers;
  BodyJson body_json;
  Request(Method method, std::string url, Headers headers, BodyJson body)
      : method(method), headers(headers), body_json(body), url(url){};
};
}  // namespace httpserver
#endif  // !DB_REQUEST
