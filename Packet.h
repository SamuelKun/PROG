#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "defs.h"
#include "Date.h"

using namespace std;

class Packet{
 public:
	 Packet(unsigned id, vector<string> places, Date begin, Date end, double pricePerPerson, unsigned maxTickets, unsigned availableTickets);

  // GET methods
  unsigned getId() const;
  vector<string> getSites() const;
  Date getBeginDate() const;
  Date getEndDate() const;
  double getPricePerPerson() const;
  unsigned getMaxPersons() const;

  // SET methods
  void setId(unsigned id);  // to set negatve if "deprecated"
  void setSites(vector<string> sites);
  void setBeginDate(Date begin);
  void setEndDate(Date end);
  void setPricePerPerson(double pricePerPerson);
  void setMaxPersons(unsigned maxPersons);

  // other methods

  friend ostream& operator<<(ostream& out, const Packet & packet);

private:
	unsigned id; // packet unique identifier
	vector<string> places; // touristic sites to visit
	Date begin;  // begin date
	Date end;  // end date
	double pricePerPerson; // price per person
	unsigned maxTickets; // máximo de lugares disponíveis
	unsigned availableTickets; // número de lugares já reservados
};
