#include "Packet.h"

Packet::Packet(unsigned id, vector<string> sites, Date begin, Date end, double pricePerPerson, unsigned maxTickets, unsigned availableTickets)
{
	this->id = id;
	this->places = sites;
	this->begin = begin;
	this->end = end;
	this->pricePerPerson = pricePerPerson;
	this->maxTickets = maxTickets;
	this->availableTickets = availableTickets;
}

/*********************************
 * GET Methods
 ********************************/

unsigned Packet::getId() const
{
	return id;
}

vector<string> Packet::getSites() const
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

unsigned Packet::getMaxPersons() const
{
	return maxPersons;
}

/*********************************
 * SET Methods
 ********************************/

void Packet::setId(unsigned id)
{
	this->id = id;
}

void Packet::setSites(vector<string> sites)
{
	this->places = sites;
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

	this->pricePerPerson=maxPersons;
}

void Packet::setMaxPersons(unsigned maxPersons)
{

	this->maxPersons = maxPersons;
}


/*********************************
 * Show Packet information
 ********************************/  

// shows a packet content 
ostream& operator<<(ostream& out, const Packet & packet)
{

  // REQUIRES IMPLEMENTATION
}
