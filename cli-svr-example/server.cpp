#include <iostream>
#include <winsock2.h>

// load ws2_32.dll
#pragma comment (lib, "ws2_32.lib")  

using namespace std;

int main() {
	// initialize winsock
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	// create a socket
	SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	// bind the socket to IP_ADDRESS:PORT
	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));  //
	sockAddr.sin_family = PF_INET;  //
	sockAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	sockAddr.sin_port = htons(1234);  //
	bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
	cout << "Bind socket ..." << endl;
	// start listening
	listen(servSock, 20);
	cout << "Start listening on port: 1234" << endl;
	// connect to the client
	SOCKADDR clntAddr;
	int nSize = sizeof(SOCKADDR);
	SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);
	cout << "Connecting ..." << endl;
	// send message to the client
	char str[] = "Hello World!";
	cout << "Send Hello World! to the client..." << endl;
	send(clntSock, str, strlen(str) + sizeof(char), NULL);
	// close the socket
	closesocket(clntSock);
	closesocket(servSock);
	cout << "Close the socket ..." << endl;
	// clean up winsock
	WSACleanup();
	system("pause");
	return 0;
}