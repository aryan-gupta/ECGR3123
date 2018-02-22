
//#include <windows.h>
#include <iostream>
#include <winsock2.h>

int main() {
	WSADATA wsaData;

	// Initialize Winsock
	int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != 0) {
		std::cout << "WSAStartup failed: " << iResult << "\n";
		return 1;
	}
	
	SOCKET sock = socket(PF_INET, SOCKET_STREAM)
	
}