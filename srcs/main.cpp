#include <iostream>
#include "../include/webserv.hpp"

int main(int argc, char **argv)
{
	if (argc > 2) {
		std::cout << "Usage : ./webserv [config file]" << std::endl;
		return (1);
	}
	const char* config;

	if (argc == 1) {
		// config = ~~/default.conf
	}
	else {
		config = argv[1];
	}

	try {
		std::vector<ServerInfo> server_block = parse_config(config);
		//std::cout << config_content << std::endl;

	}
	catch (std::exception& e) {
		e.what();
	}

	return (0);
}