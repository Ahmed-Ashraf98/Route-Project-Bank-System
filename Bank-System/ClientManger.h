#pragma once
#include "Client.h"
#include "FileManager.h"
#include "FlowManager.h"
class ClientManger
{
public:
	static void printClientMenu();
	static void updatePassword(Person* person);
	static void depositeAmount(Client* client);
	static void withdrawAmount(Client* client);
	static void transferAmount(Client* client);
	static Client* login();
	static bool clientOptions(Client* client);
};

