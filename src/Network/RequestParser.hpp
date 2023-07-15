#ifndef HPP_BODYPARSER
#define HPP_BODYPARSER
#include <map>
#include <string>

#include "Types/Request.hpp"

namespace httpserver {
class RequestParser {
 public:
  static Request parseBody(std::string);
};
}  // namespace httpserver
#endif
