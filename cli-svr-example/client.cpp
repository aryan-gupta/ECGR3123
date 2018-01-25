#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <winsock2.h>

// load ws2_32.dll
#pragma comment (lib, "ws2_32.lib")  //
using namespace std;
int main() {
	
	// initialize winsock
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	
	// create a socket
	SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	// bind socket to IP_ADDRESS:PORT
	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));  
	sockAddr.sin_family = PF_INET;
	sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	sockAddr.sin_port = htons(1234);
	
	// connect to the server
	connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
	
	// receive message from the server
	char szBuffer[MAXBYTE] = { 0 };
	recv(sock, szBuffer, MAXBYTE, NULL);
	cout << "Message form server:" << endl << szBuffer <<endl;
	// close the socket
	closesocket(sock);
	cout << "Close the socket ..." << endl;
	// clean up the winsock
	WSACleanup();
	system("pause");
	return 0;
}