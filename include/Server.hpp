#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <vector>

class Server
{
  private:
	std::vector<std::string>	server_name;
	unsigned int				port;
	std::string					root;
	std::vector<Location>		location;
	std::vector<std::string>	allow_methods;
	std::vector<std::string>	cgi;
	std::vector<std::string>	cgi_path;
};

class Location {
	std::string	fastcgi;
};

#endif