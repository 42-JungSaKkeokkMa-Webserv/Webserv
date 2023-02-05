#ifndef WEBSERV_HPP
#define WEBSERV_HPP

#include "LocationInfo.hpp"
#include "ServerInfo.hpp"

// PARSER
std::vector<ServerInfo> parse_config(const char *config);


#endif