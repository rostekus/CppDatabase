#ifndef HPP_ROUTER
#define HPP_ROUTER

#include <map>
#include <memory>

#include "IHandler.hpp"
#include "IRouter.hpp"
#include "RequestParser.hpp"
#include "Types/Request.hpp"

namespace httpserver {

typedef std::map<std::pair<std::string, Method>, IHandler> Routes;

class Router : public IRouter {
 public:
  Router(std::unique_ptr<IRequestParser> requestParser);
  void registerRoute(std::string url, Method method, IHandler handler);
  void route(std::string request);

 private:
  std::unique_ptr<IRequestParser> requestParser;
  Routes m_routes;
};
}  // namespace httpserver
#endif  // !HPP_ROUTER
