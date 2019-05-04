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

	// SHOW methods
	void showAllClientsName() const;
	void showAllPacksID() const;
	void showAllClients() const;
	void showAllPackets() const;

 private:
  string name; // name of the  agency
  unsigned int VATnumber; // VAT number of the agency
  Address address; // address of the agency
  string URL; // URL of the agency Web site
  vector<Client> clients; // vector to store the existing clients
  vector<Packet> packets; // vector to store the existing packets
  
  bool clientsInfoHasChanged; // flag that is set to "true" if at least one client has been changed/added/deleted
  bool packetsInfoHasChanged; // flag that is set to "true" if at least one packet has been changed/added/deleted
  unsigned int maxClientsId; // maximum value among all clients identifiers
  unsigned int maxPacketsId; // maximum value among all packets identifiers

};
