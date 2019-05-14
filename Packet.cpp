#include <fstream>
#include <sstream>
#include "Packet.h"


using namespace std;

Packet::Packet(short id, string places, Date begin, Date end, double pricePerPerson, unsigned maxTickets, unsigned availableTickets)
{
	this->id = id;
	this->places = places;
	this->begin = begin;
	this->end = end;
	this->pricePerPerson = pricePerPerson;
	this->maxTickets = maxTickets;
	this->availableTickets = availableTickets;
}



/*********************************
 * GET Methods
 ********************************/

short Packet::getId() const
{
	return id;
}

string Packet::getPlaces() const
{
	return places;
}

Date Packet::getBeginDate() const
{
	return begin;
}

Date Packet::getEndDate() const
{
	return end;
}

double Packet::getPricePerPerson() const
{
	return pricePerPerson;
}

unsigned Packet::getMaxTickets() const
{
	return maxTickets;
}

unsigned Packet::getAvailableTickets() const
{
	return availableTickets;
}

/*********************************
 * SET Methods
 ********************************/

void Packet::setId(unsigned id)
{
	this->id = id;
}

void Packet::setPlaces(string sites)
{
	this->places = places;
}

void Packet::setBeginDate(Date begin)
{

	this->begin = begin;
}

void Packet::setEndDate(Date end)
{

	this->end = end;
}

void Packet::setPricePerPerson(double pricePerPerson)
{

	this->pricePerPerson=pricePerPerson;
}

void Packet::setMaxTickets(unsigned maxTickets)
{

	this->maxTickets = maxTickets;
}

void Packet::setAvailableTickets(unsigned availableTickets)
{
	this->availableTickets = availableTickets;
}

/*********************************
 * Show Packet information
 ********************************/

void Packet::showPlaces() const
{
		cout << places;
}


ostream& operator<<(ostream& out, const Packet &packet)
{
	out << endl;
	out << "Identifier: " << packet.getId() << endl;
	out << "Places: ";
	packet.showPlaces();
	out << endl << "Departure Date: ";
	out << packet.getBeginDate();
	out << "Arrival Date: ";
	out << packet.getEndDate();
	out << "Price per Person: " << packet.getPricePerPerson() << endl;
	out << "Capacity: " << packet.getMaxTickets() << endl;
	out << "Places already reserved: " << packet.getAvailableTickets() << endl;
	out << endl << "----------------------------------------------------" << endl;
	return out;
}
