#ifndef DB_REQUEST
#define DB_REQUEST

#include <cctype>
#include <string>
namespace request {
class RequestInsertValueKey {
 public:
  RequestInsertValueKey() = default;
  void parseRequest(std::string request);
  std::string getKey();
  std::string getValue();

 private:
  std::string mKye;
  std::string mValue;
};
}  // namespace request
#endif  // !DB_REQUEST
