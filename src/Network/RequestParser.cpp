#include "RequestParser.hpp"

#include <csignal>
#include <stdexcept>

void httpserver::RequestParser::parseBody(
    std::string jsonString, std::map<std::string, std::string>& bodyMap) {
  if (!bodyMap.empty()) {
    throw std::invalid_argument("map must be empty");
  }

  if (jsonString.empty() || jsonString.front() != '{' ||
      jsonString.back() != '}') {
    throw std::invalid_argument("invalid JSON string format");
  }

  std::string jsonContent = jsonString.substr(1, jsonString.length() - 2);

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

    bodyMap[key] = value;

    startPos = commaPos + 1;
  }
}
