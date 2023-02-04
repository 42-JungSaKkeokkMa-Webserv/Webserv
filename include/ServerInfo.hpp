#ifndef SERVERINFO_HPP
#define SERVERINFO_HPP

#include <iostream>
#include <vector>
#include "LocationInfo.hpp"

class ServerInfo
{
  private:
	std::vector<std::string>	server_name;
	unsigned int				port;
	std::string					root;
	std::vector<LocationInfo>	location;
	std::vector<std::string>	allow_methods;
	std::vector<std::string>	cgi;
	std::vector<std::string>	cgi_path;
	//ErrorPage					error_page;
	unsigned int				client_max_body_size;
	bool						auto_index;

  public:
	/* SETTER */
	
};

#endif