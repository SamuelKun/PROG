#pragma once

#include <iostream>
#include <string>
#include <vector>


#include "defs.h"
#include "Packet.h"
#include "Address.h"

using namespace std;

class Client{

public:
	Client(string name, unsigned VATnumber, unsigned short familySize, Address address);  // for a new client
	Client(string name, unsigned VATnumber, unsigned short familySize, Address address, vector<string> &packets, unsigned totalPurchased);  // client read from file

	// GET methods

	string getName() const;
	unsigned getVATnumber() const;
	unsigned short getFamilySize() const;
	Address getAddress() const;
	vector<string> getPacketList() const;
	unsigned getTotalPurchased() const;

	// SET methods
	void setName(string name);
	void setVATnumber(unsigned VATnumber);
	void setFamilySize(unsigned short familySize);
	void setAddress(Address address);
	void addPacket(string packets);
	void setPacketList(vector<string> &packets);
	void addTotalPurchased(unsigned totalPurchased);
	void setTotalPurchased(unsigned totalPurchased);


 private:
  string name; // name of the client
  unsigned VATnumber; // VAT number of client
  unsigned short familySize;  // number of family members
  Address address; // client's address
  vector<string> packets; // vector to store client's packets bought
  unsigned totalPurchased; // total value spent by the client

 
};
