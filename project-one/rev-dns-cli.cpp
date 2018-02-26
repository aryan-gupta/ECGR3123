
#include <iostream>
#include <winsock.h>
#include <cstring>
#include <cassert>

constexpr char IP_ADDRESS[] = "127.0.0.1";

int main() {
	WSADATA wsaData;	
	int status{};
	
	status = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (status != 0)
		std::cout << "WSAStartup failed: " << std::to_string(status);
	
	SOCKET cliSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	
	sockaddr_in svrAddress;
	std::memset(&svrAddress, 0, sizeof(svrAddress));
	
	svrAddress.sin_family = PF_INET;
	svrAddress.sin_addr.s_addr = inet_addr(IP_ADDRESS);
	svrAddress.sin_port = htons(1234);
	
	connect(cliSocket, (SOCKADDR*) &svrAddress, sizeof(SOCKADDR));
	
	char buffer[128];
	
	recv(cliSocket, buffer, 128, 0);
	
	std::cout << "The host name of the server is: " << buffer << std::endl;
	
	closesocket(cliSocket);
	WSACleanup();
	
}