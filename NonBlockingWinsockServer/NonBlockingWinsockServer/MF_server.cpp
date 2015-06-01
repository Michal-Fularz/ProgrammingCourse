#ifdef WIN32
#pragma comment(lib, "ws2_32")
#endif 

#include "MF_server.h"

namespace MF
{
	CServerClient::CServerClient(SOCKET _socket, int _ID)
	{
		this->socketUsed = _socket;
		this->ID = _ID;

		this->flagNewDataRecv = false;
		this->flagNewDataSend = false;

		memset(this->recvBuffer, 0, this->bufferSize);
		memset(this->sendBuffer, 0, this->bufferSize);
	}

	bool CServerClient::Receive(void)
	{
		bool flagClientConnected = true;

		int bytesRecv = recv(this->socketUsed, this->recvBuffer, this->bufferSize, 0);
		int nError = WSAGetLastError();

		if (nError != WSAEWOULDBLOCK && nError != WSAENOTSOCK && nError != 0)
		{
			std::cout << "Winsock error code: " << nError << std::endl;
			if (nError == WSAECONNRESET)
			{
				std::cout << "Client disconnected!" << std::endl;

				// shutdown the socket
				shutdown(this->socketUsed, SD_SEND);

				// close the socket entirely
				closesocket(this->socketUsed);

				flagClientConnected = false;
			}
		}
		else
		{
			if (bytesRecv > 0)
			{
				this->flagNewDataRecv = true;
			}
			else
			{
				this->flagNewDataRecv = false;
			}
		}

		return flagClientConnected;
	}

	void CServerClient::PrepareResponse(bool printReceivedData)
	{
		if (this->flagNewDataRecv)
		{
			if (printReceivedData)
			{
				std::cout << "Received data from client ID " << this->ID << ": " << this->recvBuffer << std::endl;
			}

			if (0 == strcmp(this->recvBuffer, "Hello Server!"))
			{
				strcpy_s(this->sendBuffer, this->bufferSize, "Hello Client!");
			}
			else if (0 == strcmp(this->recvBuffer, "Ask question"))
			{
				strcpy_s(this->sendBuffer, this->bufferSize, "2+2*2 = ?");
			}
			else if (0 == strcmp(this->recvBuffer, "6"))
			{
				strcpy_s(this->sendBuffer, this->bufferSize, "Correct!");
			}
			else
			{
				strcpy_s(this->sendBuffer, this->bufferSize, "Unknown command!");
			}

			memset(this->recvBuffer, 0, this->bufferSize);
			this->flagNewDataRecv = false;
			this->flagNewDataSend = true;
		}
	}

	void CServerClient::Send(void)
	{
		if (this->flagNewDataSend)
		{
			send(this->socketUsed, this->sendBuffer, this->bufferSize, 0);
			memset(this->sendBuffer, 0, this->bufferSize);
			this->flagNewDataSend = false;
		}
	}

	CServer::CServer(void)
	{
		this->socketUsed = NULL;
		this->numberOfClients = 0;
	}

	void CServer::Init(int _portNumber)
	{
		// initialize Windows Sockets API
		WSADATA wsaData;
		int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != NO_ERROR)
		{
			this->CleanUp("Error at WSAStartup().");
		}

		// create a socket
		this->socketUsed = socket(AF_INET, SOCK_STREAM, 0);
		if (this->socketUsed == INVALID_SOCKET)
		{
			this->CleanUp("Error at the socket() function.");
		}

		// change the server socket to a non-blocking state
		u_long NonBlock = 1;
		if (ioctlsocket(this->socketUsed, FIONBIO, &NonBlock) == SOCKET_ERROR)
		{
			this->CleanUp("Setting non blocking mode failed.");
		}

		// bind the socket
		sockaddr_in server_service;
		server_service.sin_family = AF_INET;
		server_service.sin_addr.s_addr = INADDR_ANY;
		server_service.sin_port = htons(_portNumber);
		if (bind(this->socketUsed, (SOCKADDR*)&server_service, sizeof(server_service)) == SOCKET_ERROR)
		{
			this->CleanUp("Error during the bind() operation.");
		}

		// listen on the socket
		if (listen(this->socketUsed, 10) == SOCKET_ERROR)
		{
			this->CleanUp("Error listening on the socket.");
		}

		std::cout << "Server initialized" << std::endl;
	}

	void CServer::AcceptNewClients(void)
	{
		if (this->numberOfClients <= this->maxNumberOfClients)
		{
			sockaddr sockAddrClient;
			int size = sizeof(sockaddr);
			SOCKET newClientSocket = accept(this->socketUsed, &sockAddrClient, &size);
			if (newClientSocket != SOCKET_ERROR)
			{
				std::cout << "Client connected, assigned slot:" << this->numberOfClients << std::endl;

				CServerClient newClient(newClientSocket, this->numberOfClients);

				listOfClients.push_back(newClient);
				this->numberOfClients++;
			}
		}
	}

	void CServer::ReceiveData(void)
	{
		// for all available clients receive the data, in case of disconnection remove client from the list
		for (auto itr = this->listOfClients.begin(); itr != this->listOfClients.end(); /* important to leave empty*/)
		{
			bool flagClientConnected = (*itr).Receive();

			if (flagClientConnected)
			{
				++itr;
			}
			else
			{
				std::cout << "Client disconnected" << std::endl;
				this->numberOfClients--;
				itr = listOfClients.erase(itr);
			}
		}
	}

	void CServer::PrepareResponse(bool printReceivedData)
	{
		for (auto itr = this->listOfClients.begin(); itr != this->listOfClients.end(); ++itr)
		{
			(*itr).PrepareResponse(printReceivedData);
		}
	}

	void CServer::SendData(void)
	{
		// for all available clients send the prepared data
		for (auto itr = this->listOfClients.begin(); itr != this->listOfClients.end(); ++itr)
		{
			(*itr).Send();
		}
	}

	void CServer::CleanUp(const char* error)
	{
		std::cout << error << " Error number: " << WSAGetLastError() << std::endl;

		if (this->socketUsed != NULL)
		{
			closesocket(this->socketUsed);
		}
		WSACleanup();

		std::exception e(error);
		throw e;
	}
}
