#pragma once

#include <iostream>
#include <string>
#include <vector>


#include "defs.h"

using namespace std;

class Date{
 public:
  Date();
  Date(string date);
  Date(unsigned short day, unsigned short month, unsigned year);

  // GET methods
  unsigned short getDay() const;
  unsigned short getMonth() const;
  unsigned getYear() const;
  
  //Set Manual Date
  void manualDate();

  // SET methods
  
  void setDay(unsigned short day);
  void setMonth(unsigned short month);
  void setYear(unsigned year);

  // COMPARE methods
  bool isEqualTo(const Date & date);
  bool isAfter(const Date & date);
  bool isBefore(const Date & date);

  //Show methods
  void showDate() const;

  
	
private:
	unsigned short day;
	unsigned short month;
	unsigned year;
};
