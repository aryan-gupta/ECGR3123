#include <string>
#include <iostream>
#include <winsock2.h>

// #define _WIN32_WINNT 0x501
#include <ws2tcpip.h>

int main() {
	WSADATA wsadata;
	int result = WSAStartup(MAKEWORD(2,2),&wsadata);
	if (result != 0) std::cout << "WSAStartup failed: " << result << '\n';
	
	sockaddr_in address;
	address.sin_family = AF_INET;
    address.sin_port = htons(27015);
	
	while (true) {
		std::cout << "Please enter the ip to look up\n";
		std::cout << ":: ";
		
		std::string ipaddress;
		std::cin >> ipaddress;
		
		address.sin_addr.s_addr = inet_addr(ipaddress.c_str()); // converts ip
		// string into a binary ip address (32 bits long), effectively checks
		// if the ip is valid or not, if the ip is valid, next condition passes
		// and we leave loop
		if (address.sin_addr.s_addr != INADDR_NONE) {
			std::cout << "Looking up DNS entry for " << ipaddress << '\n';			
			break;
		}
		
		std::cout << ipaddress << "is an invalid address. Please try again.\n";
	}
	
	// https://msdn.microsoft.com/en-us/library/ms738520.aspx
	char hostname[NI_MAXHOST], servInfo[NI_MAXSERV];
	int status = getnameinfo((sockaddr*) &address, sizeof(sockaddr),
				 hostname, NI_MAXHOST, servInfo, NI_MAXSERV, 0);
				 
	if (status != 0) std::cout << "Something Failed: " << status << '\n';
	
	std::cout << "Hostname is " << hostname << '\n';
}


