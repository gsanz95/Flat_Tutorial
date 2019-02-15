#pragma once
#include <iostream>
#include "TCPListener.h"
#include <string>
#include <sstream>
#include "schema/client_generated.h"

#ifndef CLIENT_LISTENER_H
#define CLIENT_LISTENER_H

class ClientListener : TCPListener
{
public:
	ClientListener(const char* addr, int port) : TCPListener(addr, port) {};

	~ClientListener() {};

	// Initialize the listening server
	int Init();

	// Run the server
	int Run();

	void printClientContent(Client::Client& clt) const;

protected:

	// Handler when client connects
	void onClientConnected(int clientSocket);

	// Handler when client disconnects
	void onClientDisconnected(int clientSocket);

	// Handler when message has been received from client
	void onMessageReceived(int clientSocket, const char* msg, int length);

	// Message a specific client
	void sendMessageToClient(int clientSocket, const char* msg, int length);

	// Broadcast message from one client to all others
	void broadcastToClients(int sender, const char* msg, int length);
};
#endif