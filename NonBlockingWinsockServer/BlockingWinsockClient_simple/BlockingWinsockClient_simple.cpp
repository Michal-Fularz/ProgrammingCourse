#ifdef WIN32
#pragma comment(lib, "ws2_32")
#endif

#include <winsock2.h>
#include <iostream>

int main(void)
{
	// initialize Windows Sockets API
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		std::cout << "Error at WSAStartup().";
		std::cout << " Error number: " << WSAGetLastError() << std::endl;
		WSACleanup();
		system("PAUSE");
		return 0;
	}

	// create a socket
	SOCKET Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (Socket == INVALID_SOCKET)
	{
		std::cout << "Error at the socket() function.";
		std::cout << " Error number: " << WSAGetLastError() << std::endl;
		WSACleanup();
		system("PAUSE");
		return 0;
	}

	// resolve IP address for hostname
	struct hostent *host;
	if ((host = gethostbyname("localhost")) == NULL)
	{
		std::cout << "Error at the gethostbyname() function.";
		std::cout << " Error number: " << WSAGetLastError() << std::endl;
		WSACleanup();
		system("PAUSE");
		return 0;
	}

	// setup socket address structure
	SOCKADDR_IN SockAddr;
	SockAddr.sin_port = htons(10000);
	SockAddr.sin_family = AF_INET;
	SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);

	// attempt to connect to the server
	if (connect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) != 0)
	{
		std::cout << "Error at the connect() function.";
		std::cout << " Error number: " << WSAGetLastError() << std::endl;
		WSACleanup();
		system("PAUSE");
		return 0;
	}

	// send the message to server
	char sendBuffer[32];
	// copy string to send to buffer
	strcpy_s(sendBuffer, 32, "Hello Server!");
	send(Socket, sendBuffer, 32, 0);

	// receive the answere from server
	char recvBuffer[32];
	// clear the receive buffer
	memset(recvBuffer, 0, 32);
	int bytesRecv = recv(Socket, recvBuffer, 32, 0);
	std::cout << "Received " << bytesRecv << " bytes. Message: " << recvBuffer << std::endl;

	// shutdown the socket
	shutdown(Socket, SD_BOTH);

	// close the socket entirely
	closesocket(Socket);

	// cleanup Winsock
	WSACleanup();
	system("PAUSE");

	return 0;
}