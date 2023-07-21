#ifndef HPP_ROUTER
#define HPP_ROUTER

#include <map>
#include <memory>
#include <string>

#include "API/IHandler.hpp"
#include "API/IRouter.hpp"
#include "Handlers.hpp"
#include "RequestParser.hpp"
#include "ResponseSerializer.hpp"
#include "Types/Request.hpp"
#include "Types/Response.hpp"

namespace httpserver {

typedef std::map<std::pair<std::string, Method>, std::unique_ptr<IHandler>>
    Routes;

class Router : public IRouter {
 public:
  Router(std::unique_ptr<IRequestParser> requestParser);
  void registerRoute(std::string url, Method method,
                     std::unique_ptr<IHandler> handler) override;
  std::string route(std::string request) override;

 private:
  std::unique_ptr<IRequestParser> requestParser;
  std::unique_ptr<ResponseSerializer> responseSerializer;
  Routes m_routes;
};
}  // namespace httpserver
#endif  // !HPP_ROUTER
