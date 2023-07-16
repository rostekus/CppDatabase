#ifndef HPP_IREQUESTPARSER
#define HPP_IREQUESTPARSER


#include "Types/Request.hpp"
#include <string>
namespace httpserver{
class IRequestParser{

	public:
		virtual Request parseRequest(std::string httpRequest) =0;
};
}

#endif // !HPP_IREQUESTPARSER
#define HPP_IREQUESTPARSER


