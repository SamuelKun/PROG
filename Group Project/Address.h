#pragma once

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Address{

public:
	Address();
	Address(string addressString);
	Address(string street, unsigned short doorNumber, string floor, string postalCode, string location);

	// metodos GET
	string getStreet() const;
	unsigned short getDoorNumber() const;
	string getFloor() const;
	string getPostalCode() const;
	string getLocation() const;

	// metodos SET
	void setStreet(string street);
	void setDoorNumber(unsigned short doorNumber);
	void setFloor(string floor);
	void setPostalCode(string postalCode);
	void setLocation(string  location);

	friend ostream& operator<<(ostream& out, const Address &address);
	


 private:
  string street; // street name
  unsigned short doorNumber; // doro number
  string floor; // floor number ("-" is not applicable)
  string postalCode; // postal code
  string location; // site

 
};
