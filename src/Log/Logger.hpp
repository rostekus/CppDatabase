//
// Created by Rostyslav Mosorov on 07/07/2023.
//

#ifndef YOURPROJECTNAME_LOGGER_HPP
#define YOURPROJECTNAME_LOGGER_HPP

#include <spdlog/spdlog.h>


namespace logger {
    class Logger {

    public:
        void logInfo(const std::string &message);

        void logErr(const std::string &message);

        Logger(std::shared_ptr<spdlog::logger> logger);

    private:
        std::shared_ptr<spdlog::logger> m_logger;
    };
}


#endif //YOURPROJECTNAME_LOGGER_HPP
