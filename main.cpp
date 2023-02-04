#include <iostream>

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

	//std::vector<Server> server_block;

	try {
		// loop
	}
	catch (std::exception& e) {
		e.what();
	}

	return (0);
}