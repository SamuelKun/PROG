#pragma once

#include <iostream>
#include <string>
#include <vector>


#include "defs.h"
#include "Address.h"
#include "Client.h"
#include "Packet.h"

using namespace std;

class Agency{
public:
	Agency(string fileName);

	// GET methods
	string getName() const;
	unsigned getVATnumber() const;
	Address getAddress() const;
	string getURL() const;
	vector<Client> getClients() const;
	vector<Packet> getPackets() const;

	// SET methods
	void setName(string name);
	void setVATnumber(unsigned VATnumber);
	void setAddress(Address address);
	void setURL(string url);
	void setClients(vector<Client> & clients);
	void setPackets(vector<Packet> & packets);

	// MANAGE CLIENTS methods
	void addClient();
	void changeClient(int position);
	void removeClient(int position);

	// MANAGE PACKS methods
	void addPack();
	void changePack(int position);
	void removePack(int position);

	// SHOW ALL methods
	void showAllClientsName() const;
	void showAllPacksID() const;
	void showAllClients() const;
	void showAllPackets() const;

	// SHOW SPECIFIC methods
	void showDestinyPacks() const;
	void showDatePacks() const;
	void showDestinyAndDatePacks() const;
	void show1ClientPacks() const;
	void show1Client() const;

	// AMMOUNT SOLD AND EARNED CURRENCY methods
	void ammountSold() const;

	// BUYING PACKS method
	void buyPack();

	// N MOST VISITED method
	void mostVisited(int n) const;
	void ClientMostVisited(int n) const;

 private:
  string name; // name of the  agency
  unsigned int VATnumber; // VAT number of the agency
  Address address; // address of the agency
  string URL; // URL of the agency Web site
  vector<Client> clients; // vector to store the existing clients
  vector<Packet> packets; // vector to store the existing packets
};
