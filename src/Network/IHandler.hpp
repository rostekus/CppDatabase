#ifndef HPP_IHANDLER
#define HPP_IHANDLER

#include "Types/Request.hpp"
#include "Types/Response.hpp"

namespace httpserver {
class IHandler {
 public:
  virtual Response handle(Request req);
};
}  // namespace httpserver
#endif  // HPP_IHANDLER
