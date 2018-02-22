

#include <iostream>
#include <winsock2.h>

// compile with c++17 please

int main() {
	WSADATA wsaData;
	
	if (int iResult = WSAStartup(MAKEWORD(2,2), &wsaData); iResult != 0) {
		std::cout << "WSAStartup failed: " << iResult << "\n";
		return 1;
	}
	
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	sockaddr_in addr;
	memset(&addr, 0, sizeof(sockaddr_in));
	
	sockAddr.sin_family = PF_INET;  //
	sockAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	sockAddr.sin_port = htons(1234);
	
	bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
}