//
// Created by Rostyslav Mosorov on 07/07/2023.
//

#include "Logger.hpp"

using namespace logger;

Logger::Logger(std::shared_ptr<spdlog::logger> logger) : m_logger(logger){
}

void Logger::logInfo(const std::string &message) {
  m_logger->info(message);
}

void Logger::logErr(const std::string &message) {
  m_logger->error(message);
}
