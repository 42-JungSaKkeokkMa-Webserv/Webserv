#include "../include/libft.hpp"

std::vector<std::string> ft_split(std::string str, char *delimiters)
{
    std::vector<std::string> result;
    char *cstr = const_cast<char*>(str.c_str());
    char *current;
    current = strtok(cstr, delimiters);
    while (current != NULL) {
        result.push_back(current);
        current = strtok(NULL, delimiters);
    }
    return result;
}