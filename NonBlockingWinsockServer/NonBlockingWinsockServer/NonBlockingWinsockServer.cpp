#include <iostream>
#include "MF_server.h"

int main(void)
{
	const int portNumber = 10000;

	MF::CServer server;

	server.Init(portNumber);

	do
	{
		server.AcceptNewClients();

		server.ReceiveData();

		server.PrepareResponse(true);

		server.SendData();

		Sleep(500);

	} while (true);

	return 1;
}
