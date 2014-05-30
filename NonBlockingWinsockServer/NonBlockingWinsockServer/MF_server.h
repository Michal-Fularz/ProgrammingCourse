#ifndef __MF_SERVER_H__
#define __MF_SERVER_H__

#include <winsock2.h>
#include <iostream>
#include <exception>
#include <list>

namespace MF
{
	class CServerClient
	{
	public:
		CServerClient(SOCKET _socket, int _ID);

		bool Receive(void);

		void PrepareResponse(bool printReceivedData = true);

		void Send(void);

	private:
		static const int bufferSize = 32;
		int ID;
		bool flagNewDataRecv;
		char recvBuffer[bufferSize];
		bool flagNewDataSend;
		char sendBuffer[bufferSize];
		SOCKET socketUsed;
	};

	class CServer
	{
	public:
		CServer(void);

		void Init(int _portNumber);

		void AcceptNewClients(void);

		void ReceiveData(void);

		void PrepareResponse(bool printReceivedData = true);

		void SendData(void);

	private:

		static const int maxNumberOfClients = 10;
		int numberOfClients;
		SOCKET socketUsed;
		std::list<CServerClient> listOfClients;

		void CleanUp(const char* error);
	};
}

#endif __MF_SERVER_H__