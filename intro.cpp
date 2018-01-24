
#include <windows.h>
#include <iostream>

int main() {
	WSADATA wsaData;
	int iResult;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != 0) {
		std::cout << "WSAStartup failed: " << iResult << "\n";
		return 1;
	}
	
	
}