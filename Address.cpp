#include "Address.h"
#include <sstream>

using namespace std;

Address::Address()
{

}

Address::Address(string addressString)
{
	stringstream address_info(addressString);
	string temp;
	vector<string> address_temp;

	while (getline(address_info, temp, '/'))
	{
		//Remove leading and trailing spaces
		while (temp[0] == ' ') temp.erase(0, 1);
		while (temp[temp.size() - 1] == ' ') temp.erase(temp.size() - 1, temp.size());

		address_temp.push_back(temp);
	}

	street = address_temp[0];
	doorNumber = stoi(address_temp[1]);
	floor =	address_temp[2];
	postalCode = address_temp[3];
	location =	address_temp[4];
}

Address::Address(string street, unsigned short doorNumber, string floor, string postalCode, string location){


	this->street = street;
	this->doorNumber = doorNumber;
	this->floor = floor;
	this->postalCode = postalCode;
	this->location = location;

}

  // metodos GET


string Address::getStreet() const
{

	return street;
}

unsigned short Address::getDoorNumber() const
{

	return doorNumber;
}

string Address::getFloor() const
{
  
	return floor;
}

string Address::getPostalCode() const
{

	return postalCode;
}

string Address::getLocation() const
{

	return location;
}


  // metodos SET

void Address::setStreet(string street)
{

	this->street = street;
}

void Address::setDoorNumber(unsigned short doorNumber)
{

	this->doorNumber = doorNumber;
}

void Address::setFloor(string floor)
{

	this->floor = floor;
}

void Address::setPostalCode(string postalCode)
{

	this->postalCode = postalCode;
}

void Address::setLocation(string  location)
{

	this->location = location;
}


/*********************************
 * Mostrar Address
 ********************************/  

ostream &operator<<(ostream & out, const Address & address)
{
	out << "Address: " << endl;
	out << "     Street: " << address.getStreet() << endl;
	out << "     Door Number: " << address.getDoorNumber() << endl;
	out << "     Floor: " << address.getFloor() << endl;
	out << "     Postal Code: " << address.getPostalCode() << endl;
	out << "     Location: " << address.getLocation() << endl;
	return out;
}
