#include "Request.hpp"

std::string request::RequestInsertValueKey::getKey() { return mKye; }

std::string request::RequestInsertValueKey::getValue() { return mValue; }

void request::RequestInsertValueKey::parseRequest(std::string request) {}
