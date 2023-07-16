#include "RequestParser.hpp"

#include <csignal>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "Types/Request.hpp"

const std::unordered_map<std::string, httpserver::Method>
    httpserver::RequestParser::methodMap = {
        {"GET", httpserver::Method::GET},
        {"POST", httpserver::Method::POST},
        {"DELETE", httpserver::Method::DELETE},
        {"PUT", httpserver::Method::PUT},
        {"PATCH", httpserver::Method::PATCH}};

httpserver::Method httpserver::RequestParser::getMethod(
    std::string methodString) {
  auto it = methodMap.find(methodString);
  if (it != methodMap.end()) {
    return it->second;
  }
  throw std::invalid_argument("invalid method");
}
httpserver::Request httpserver::RequestParser::parseRequest(
    std::string httpRequest) {
  std::string method;
  std::string url;
  std::string body;

  std::map<std::string, std::string> headers;
  std::regex requestLineRegex(R"((\w+)\s+([^\s]+)\s+HTTP\/\d+\.\d+)");
  std::smatch requestLineMatch;
  if (std::regex_search(httpRequest, requestLineMatch, requestLineRegex)) {
    method = requestLineMatch[1];
    url = requestLineMatch[2];
  }
    std::regex headerRegex(R"(([^:]+): ([^\r\n]+))");
    std::sregex_iterator headerIter(httpRequest.begin(), httpRequest.end(), headerRegex);
    std::sregex_iterator headerEnd;

    while (headerIter != headerEnd) {
        std::smatch headerMatch = *headerIter;
        std::string headerName = headerMatch[1];
        std::string headerValue = headerMatch[2];
        headers[headerName] = headerValue;
        ++headerIter;
    }


  std::regex bodyRegex("\r\n\r\n(.*)$");
  std::smatch bodyMatch;
  if (std::regex_search(httpRequest, bodyMatch, bodyRegex)) {
    body = bodyMatch[1];
  }
  std::map<std::string, std::string> requestBodyJson;
  if (body.empty() || body.front() != '{' || body.back() != '}') {
    throw std::invalid_argument("invalid JSON string format");
  }

  std::string jsonContent = body.substr(1, body.length() - 2);

  size_t startPos = 0;
  while (startPos < jsonContent.length()) {
    // Find the next comma separator
    size_t commaPos = jsonContent.find(',', startPos);
    if (commaPos == std::string::npos) {
      commaPos = jsonContent.length();
    }

    std::string pairString = jsonContent.substr(startPos, commaPos - startPos);

    // Split the pair by colon separator
    size_t colonPos = pairString.find(':');
    if (colonPos == std::string::npos) {
      throw std::runtime_error("Invalid key-value pair :" + pairString);
    }

    // Extract the key and value substrings
    std::string key = pairString.substr(0, colonPos);
    std::string value = pairString.substr(colonPos + 1);

    // Remove leading and trailing whitespace from key and value
    key.erase(0, key.find_first_not_of(" \t"));
    key.erase(key.find_last_not_of(" \t") + 1);
    value.erase(0, value.find_first_not_of(" \t"));
    value.erase(value.find_last_not_of(" \t") + 1);

    // Remove quotation marks from the key and value
    if (key.front() == '"' && key.back() == '"') {
      key = key.substr(1, key.length() - 2);
    }
    if (value.front() == '"' && value.back() == '"') {
      value = value.substr(1, value.length() - 2);
    }

    requestBodyJson[key] = value;

    startPos = commaPos + 1;
  }

  Request r(getMethod(method), url, headers, requestBodyJson);
  return r;
}
