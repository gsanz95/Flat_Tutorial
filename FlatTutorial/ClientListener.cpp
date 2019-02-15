#include "ClientListener.h"
#include <flatbuffers/flatbuffers.h>
#include "schema/client_generated.h"

int ClientListener::Init()
{
	TCPListener::Init();
	return 0;
}

int ClientListener::Run()
{
	TCPListener::Run();
	return 0;
}

void ClientListener::printClientContent(Client::Client& clt) const
{
	std::cout << clt.id() << std::endl;
	std::cout << clt.pos()->x() << std::endl;
	std::cout << clt.pos()->y() << std::endl;
	std::cout << clt.pos()->z() << std::endl;
	std::cout << clt.msg()->c_str() << std::endl;
}

void ClientListener::onClientConnected(int clientSocket)
{
	std::cout << "New Client Connected!" << std::endl;
}

void ClientListener::onClientDisconnected(int clientSocket)
{
	std::cout << "New Client Disconnected!" << std::endl;
}

void ClientListener::onMessageReceived(int clientSocket, const char * msg, int length)
{
	std::cout << "Client Info Received" << std::endl;

	auto client = Client::GetClient(msg);


	TCPListener::onMessageReceived(clientSocket, msg, length);
}

void ClientListener::sendMessageToClient(int clientSocket, const char * msg, int length)
{
	TCPListener::sendMessageToClient(clientSocket, msg, length);
}

void ClientListener::broadcastToClients(int sender, const char * msg, int length)
{
	TCPListener::broadcastToClients(sender, msg, length);
}
