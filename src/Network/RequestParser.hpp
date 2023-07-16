#ifndef HPP_BODYPARSER
#define HPP_BODYPARSER
#include <map>
#include <string>
#include <unordered_map>

#include "IRequestParser.hpp"
#include "Types/Request.hpp"

namespace httpserver {
class RequestParser : public IRequestParser {
 public:
  Method getMethod(std::string);
  Request parseRequest(std::string httpRequest) override;
  static const std::unordered_map<std::string, Method> methodMap;
};
}  // namespace httpserver
#endif
