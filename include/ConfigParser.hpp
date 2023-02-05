#ifndef CONFIG_PARSER_HPP
#define CONFIG_PARSER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "webserv.hpp"

class ConfigParser
{
  public:
	void parseConfig(const char *file);
	void parseServer();
	ServerInfo parseServerBlock(size_t it);
    std::vector<std::string> split(const std::string line, const std::string delimeter);
	
  public:
	const static std::string whitespace;
	std::string config;

  private:
	//std::string config;
	std::vector<ServerInfo> server_block;
};

 const std::string ConfigParser::whitespace = " \t\n\r\f\v";



#endif