#ifndef HPP_IREQUESTPARSER
#define HPP_IREQUESTPARSER

#include <string>

#include "Types/Request.hpp"
namespace httpserver {
class IRequestParser {
 public:
  virtual Request parseRequest(std::string httpRequest) = 0;
};
}  // namespace httpserver

#endif  // !HPP_IREQUESTPARSER
#define HPP_IREQUESTPARSER
