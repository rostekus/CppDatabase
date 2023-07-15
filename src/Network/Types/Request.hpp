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
  Method method;
  Headers headers;
  BodyJson body_json;
};
}  // namespace httpserver
#endif  // !DB_REQUEST
