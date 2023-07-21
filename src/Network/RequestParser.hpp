#ifndef HPP_BODYPARSER
#define HPP_BODYPARSER
#include <map>
#include <string>
#include <unordered_map>

#include "API/IRequestParser.hpp"
#include "Types/Request.hpp"
#include "Types/Response.hpp"

namespace httpserver {
class RequestParser : public IRequestParser {
 public:
  Request parseRequest(std::string httpRequest) override;
  static const std::unordered_map<std::string, Method> methodMap;

 private:
  Method getMethod(std::string);
};
}  // namespace httpserver
#endif
