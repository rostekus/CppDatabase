//
// Created by Rostyslav Mosorov on 07/07/2023.
//

#ifndef DB_HTTPSERVER_HPP
#define DB_HTTPSERVER_HPP

//#include <spdlog/spdlog.h>


class HTTPServer {
public:
    HTTPServer() = default;
   ~HTTPServer() = default;
    void serve();
    void testLog();

};

#endif //DB_HTTPSERVER_HPP
