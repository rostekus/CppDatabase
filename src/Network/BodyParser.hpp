#ifndef HPP_BODYPARSER
#define HPP_BODYPARSER
#include <map>
#include <string>
class BodyParser {
 public:
  static void parseBody(std::string body,
                        std::map<std::string, std::string>& bodyMap);
};

#endif
