#include <vector>
#include "Client.h"

using namespace std;

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address)
{
	//New CLIENT
	this->name = name;
	this->VATnumber = VATnumber;
	this->familySize = familySize;
	this->address = address;
	this->totalPurchased = 0;
}

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address,vector<string> &packets, unsigned totalPurchased)
{
	//Open FILE
	this->name = name;
	this->VATnumber = VATnumber;
	this->familySize = familySize;
	this->address = address;
	this->packets = packets;
	this->totalPurchased = totalPurchased;
}

/*********************************
 * GET Methods
 ********************************/

string Client::getName() const
{  
	return name;
}
  
unsigned Client::getVATnumber() const
{  
	return  VATnumber;
}

unsigned short Client::getFamilySize() const
{ 
	return familySize;
}

Address Client::getAddress() const
{  
	return address;
}

vector<string> Client::getPacketList() const
{ 
	return packets;
}

unsigned Client::getTotalPurchased() const
{ 
	return totalPurchased;
}
  
/*********************************
 * SET Methods
 ********************************/
	  
void Client::setName(string name)
{ 
	this->name = name;
}

void Client::setVATnumber(unsigned VATnumber)
{
	this->VATnumber = VATnumber;
}

void Client::setFamilySize(unsigned short familySize)
{
	this->familySize = familySize;
}
void Client::setAddress(Address address)
{
	this->address = address;
}
void Client::addPacket(string pack)
{
	this->packets.push_back(pack);
}

void Client::setPacketList(vector<string> &packets)
{
	this->packets = packets;
}

void Client::addTotalPurchased(unsigned totalPurchased)
{
	this->totalPurchased += totalPurchased;
}

void Client::setTotalPurchased(unsigned totalPurchased)
{
	this->totalPurchased = totalPurchased;
}
  
  // outros metodos

ostream& operator<<(ostream& out, const Client &client)
{
	out << endl;
	out << "Name: " << client.getName() << endl;
	out << "NIF: " << client.getVATnumber() << endl;
	out << "FamilySize: " << client.getFamilySize() << endl;
	out << client.getAddress();
	out << "Pack List: ";
	for (size_t j = 0; j < client.getPacketList().size(); j++)
	{
		cout << client.getPacketList()[j];
		if (j != client.getPacketList().size() - 1) cout << " , ";
	}
	out << endl;
	out << "Money spent with purchases: " << client.getTotalPurchased() << endl;
	out << endl << "----------------------------------------------------" << endl;

	return out;
}

