#pragma once

#include <iostream>
#include <string>
#include <vector>

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


  // SET methods
  
  void setDay(unsigned short day);
  void setMonth(unsigned short month);
  void setYear(unsigned year);

  // COMPARE methods
  bool isEqualTo(const Date &date);
  bool isAfter(const Date &date);
  bool isBefore(const Date &date);

  // ostream
  friend ostream& operator<<(ostream& out, const Date & date);
  friend istream& operator>>(istream& in, Date & date);
	
private:
	unsigned short day;
	unsigned short month;
	unsigned year;
};
