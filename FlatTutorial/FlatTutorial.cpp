// FlatTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include "schema/client_generated.h"
#include "ClientListener.h"

using namespace Client;

int main()
{
	ClientListener client("127.0.0.1", 54000);

	client.Init();

	while (true)
	{
		client.Run();
	}



    std::cout << "Hello World!\n"; 
}