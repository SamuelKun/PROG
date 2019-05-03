#include "Client.h"

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address){
  
	this->name = name;
	this->VATnumber = VATnumber;
	this->familySize = familySize;
	this->address = address;

}

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address, vector<Packet> & packets, unsigned totalPurchased){
  
  // REQUIRES IMPLEMENTATION 
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

vector<Packet> Client::getPacketList() const
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
void Client::setPacketList(vector<Packet> &packets)
{
	this->packets = packets;
}
unsigned Client::setTotalPurchased(unsigned totalPurchased)
{
	this->totalPurchased = totalPurchased;
}
  
  // outros metodos

ostream& operator<<(ostream& out, const Client & client){

  // REQUIRES IMPLEMENTATION 

}
