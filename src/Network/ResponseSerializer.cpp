#include "ResponseSerializer.hpp"

#include <algorithm>
#include <iostream>

using namespace httpserver;

std::string ResponseSerializer::serialize(Response& response) {
  std::string httpResponse;

  // Write the status line (HTTP version + status code + reason phrase)
  httpResponse += "HTTP/1.1 " + std::to_string(response.code) + " " +
                  getStatusPhrase(response.code) + "\r\n";

  // Add Content-Type and Content-Length headers
  response.mHeaders["Content-Type"] =
      "application/json";  // Content-Type: application/json
  response.mHeaders["Content-Length"] =
      std::to_string(calculateContentLength(response.mBody));

  // Write the headers
  for (const auto& header : response.mHeaders) {
    httpResponse += header.first + ": " + header.second + "\r\n";
  }

  // Write an empty line to separate headers from the body
  httpResponse += "\r\n";

  // Write the response body as JSON
  httpResponse += "{\n";
  bool first = true;
  for (const auto& entry : response.mBody) {
    if (!first) {
      httpResponse += ",\n";
    }
    httpResponse += "\"" + entry.first + "\" : \"" + entry.second + "\"";
    first = false;
  }
  httpResponse += "\n}";
  std::cout << httpResponse << "\n";
  return httpResponse;
}

std::string ResponseSerializer::getStatusPhrase(int code) {
  // Add more status codes and phrases as needed.
  switch (code) {
    case 200:
      return "OK";
    case 404:
      return "Not Found";
    // Add more status codes and corresponding phrases as needed.
    default:
      return "Unknown Status";
  }
}

size_t ResponseSerializer::calculateContentLength(const Body& body) {
  // Calculate the length of the JSON data to be sent in the response.
  std::string jsonString = "{\n";
  bool first = true;
  for (const auto& entry : body) {
    if (!first) {
      jsonString += ",\n";
    }
    jsonString += "\"" + entry.first + "\" : \"" + entry.second + "\"";
    first = false;
  }
  jsonString += "\n}";
  return jsonString.length();
}
