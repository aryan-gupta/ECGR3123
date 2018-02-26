
#include <iostream>
#include <winsock.h>
#include <cstring>
#include <cassert>

int main() {
	WSADATA wsaData;	
	int status{};
	
	status = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (status != 0)
		std::cout << "WSAStartup failed: " << std::to_string(status);
	
	char hostname[128];
	if (gethostname(hostname, sizeof(hostname)))
		std::cout << "Could not get hostname" << std::endl;
	
	std::cout << "Hostname is " << hostname << std::endl; 
	
	SOCKET svrSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	
	sockaddr_in svrAddress;
	std::memset(&svrAddress, 0, sizeof(svrAddress));
	
	svrAddress.sin_family = PF_INET;
	svrAddress.sin_addr.S_un.S_addr = INADDR_ANY;
	svrAddress.sin_port = htons(1234);
	
	bind(svrSocket, (SOCKADDR*) &svrAddress, sizeof(SOCKADDR));
	std::cout << "Bound address to socket" << std::endl;
	
	std::cout << "Starting to listen for client" << std::endl;
	listen(svrSocket, 20);
	
	SOCKADDR cliAddress;
	int cliAddrSize = sizeof(cliAddress);
	SOCKET cliSocket = accept(svrSocket, &cliAddress, &cliAddrSize);
	
	std::cout << "Waiting for client" << std::endl;
	
	send(cliSocket, hostname, strlen(hostname) + sizeof(char), 0);
	
	closesocket(cliSocket);
	closesocket(svrSocket);
	
	WSACleanup();
	
	
	std::cout << "Sent message, ending..." << std::endl;
	
	return 0;	
}