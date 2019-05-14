#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "defs.h"
#include "Date.h"

using namespace std;

class Packet{
 public:
	 Packet(short id, string places, Date begin, Date end, double pricePerPerson, unsigned maxTickets, unsigned availableTickets);

  // GET methods
  short getId() const;
  string getPlaces() const;
  Date getBeginDate() const;
  Date getEndDate() const;
  double getPricePerPerson() const;
  unsigned getMaxTickets() const;
  unsigned getAvailableTickets() const;

  // SET methods
  void setId(unsigned id);  // to set negatve if "deprecated"
  void setPlaces(string sites);
  void setBeginDate(Date begin);
  void setEndDate(Date end);
  void setPricePerPerson(double pricePerPerson);
  void setMaxTickets(unsigned maxTickets);
  void setAvailableTickets(unsigned avaiabaleTickets);

  //Show methods
  void showPlaces() const;

  friend ostream& operator<<(ostream& out, const Packet &packet);

private:
	short id; // packet unique identifier
	string places; // touristic sites to visit
	Date begin;  // begin date
	Date end;  // end date
	double pricePerPerson; // price per person
	unsigned maxTickets; // máximo de lugares disponíveis
	unsigned availableTickets; // número de lugares já reservados
};
