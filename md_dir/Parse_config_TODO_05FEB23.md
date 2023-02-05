# TODO 05FEB23

## nginx conf parsing
- server만을 기준으로 파싱한다고 가정한다.
- parsing이 가능한지 봐야한다.
- 큰 파트가 나오면 그에 맞게 모듈화한 다른 파싱 함수를 호출한다.
    - {}괄호가 맞아야한다.


1. 파일을 읽어서 ifstream으로 뺀다.
2. getline으로 한줄씩 읽는다.
3. trim으로 양 끝에 whitespace를 제거한다.
4. whitespace를 기준으로 split()을 이용하여 나눈다.
5. 각 문자열을 key_list와 비교하여 해당하는지 확인한다
    - 해당하지 않으면 error처리하며 프로그램 종료
        - 어디서 error 발생했는지 보여준다.
    - 괄호 역시 신경쓴다.
        괄호도 key list에 포함시킨다.
        괄호는 별도 stack에 넣어서 처리한다.
        각 영역마다 괄호를 확인하는 stack을 만들어서 
        실패시 어디에서 쌍이 안맞았는지 확인하게 한다.


## 저장구조
    - std::vector<ServerInfo>
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
        };
        - std::vector<LocationInfo>
            class LocationInfo {
                std::string	fastcgi;
                std::string	root;
                std::string	index;
            };
