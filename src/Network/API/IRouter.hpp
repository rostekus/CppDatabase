#ifndef HPP_IROUTER_DB
#define HPP_IROUTER_DB
#include <cstdlib>
#include <memory>
#include <string>

#include "IHandler.hpp"

namespace httpserver {

class IRouter {
 public:
  virtual void registerRoute(std::string url, Method method,
                             std::unique_ptr<IHandler> handler) = 0;
  virtual std::string route(std::string) = 0;
};
}  // namespace httpserver
#endif
