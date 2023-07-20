#ifndef HPP_IHANDLER


#define HPP_IHANDLER

#include "../Types/Request.hpp"
#include "../Types/Response.hpp"

namespace httpserver {
class IHandler {
 public:
  	virtual Response handle(Request req)=0;
};
}  // namespace httpserver
#endif  // HPP_IHANDLER
