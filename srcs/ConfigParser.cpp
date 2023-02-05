#include <fstream>
#include <string>
#include <iostream>
#include "../include/ConfigParser.hpp"

/*
TODO
- split

config parse에 어떤 것들이 필요한가?
- isspace? for string
- split

*/
/*
TODO
1. buffer에 담는다.
2. parsing 된 각 항목을 저장한다.
	순서들
	-1 http 파싱
		whitespace로 공백처리
	-2 괄호 체크
		- substr을 이용해서 처리한다.
		- stack 사용

	-n 각 파트를 모듈화해서 파싱한다.
		- e.g)
			- server_name
			- location
				server
			- listen
			-

*/

std::string &ltrim(std::string &s)
{
	s.erase(0, s.find_first_not_of(ConfigParser::whitespace));
	return s;
}
// trim from right
std::string &rtrim(std::string &s)
{
	s.erase(s.find_last_not_of(ConfigParser::whitespace) + 1);
	return s;
}
// trim from left & right
const std::string &trim(std::string &s)
{
	return ltrim(rtrim(s));
}

void ConfigParser::parseConfig(const char *file)
{
	std::ifstream ifs(file);
	if (ifs.fail())
	{
		exit(1);
	}
	std::string str;
	int count = 0;
	config.clear();

	while (!ifs.eof())
	{
		if (ifs.bad()) exit(1);
		std::getline(ifs, str);
		str = trim(str);
		if (str[0] == '#' || str.length() <= 0)
			continue;
		 size_t pos = str.find_first_of(";{}");
		 if (pos == std::string::npos)
		 	exit(1);
		 str = str.substr(0, pos + 1);
		config.append(str + '\n');
	}
	for (int i = 0; i < config.size(); i++) {
		if (config[i] == '{')
			count++;
		if (config[i] == '}')
			count--;
	}
	if (count) exit(1);
}

void ConfigParser::parseServer() {
	size_t start = 0;
	size_t end = 0;
	std::string tmp;

	while (end != std::string::npos) {
		start = config.find_first_not_of(whitespace, end);
		end = config.find_first_of(" \t\n\r\f\v{", start);
		tmp = config.substr(start, end - start);
		std::cout << tmp << std::endl;
		if (tmp != "server") exit(1);
		server_block.push_back(parseServerBlock(end));
	}
	
}

ServerInfo ConfigParser::parseServerBlock(size_t it) {
	ServerInfo res;
	std::string key;
	std::string value;

	while (it != std::string::npos) {
		// aa
	}

	return (res);
}

int main(int argc, char *argv[])
{
	// std::string line;

	// if (argc > 2) {
	//	std::cout << "Usage : string" << std::endl;
	//	return (1);
	//}
	// line = std::string(argv[1]);
	// ft_split(line, white_space);
	// std::string str = "   \n\thi!  \r\n ";
	// std::cout << trim(str) << std::endl;

	ConfigParser configParser;
	configParser.parseConfig(argv[1]);
	//std::cout << configParser.config << std::endl;

	configParser.parseServer();


	return (0);
}