#include "Date.h"
#include <fstream>
#include <sstream>
Date::Date(){
}

Date::Date(string date){
  
	stringstream date_info(date);
	string temp;
	vector<string> date_temp;

	while (getline(date_info, temp, '/'))
	{
		date_temp.push_back(temp);
	}

	year = stoi(date_temp[0]);
	month = stoi(date_temp[1]);
	day = stoi(date_temp[2]);
}


Date::Date(unsigned short day, unsigned short month, unsigned year){

	this->day = day;
	this->month = month;
	this->year = year;

}

/*********************************
 * GET Methods
 ********************************/
unsigned short Date::getDay() const{

  // REQUIRES IMPLEMENTATION

}

  
unsigned short Date::getMonth() const{

  // REQUIRES IMPLEMENTATION

}
    
unsigned Date::getYear() const{

  // REQUIRES IMPLEMENTATION

}

/*********************************
 * SET Methods
 ********************************/

void Date::setDay(unsigned short day){
  
  // REQUIRES IMPLEMENTATION

}
void Date::setMonth(unsigned short month){
  
  // REQUIRES IMPLEMENTATION

}

void Date::setYear(unsigned year){

  // REQUIRES IMPLEMENTATION

}


/*********************************
 * Show Date
 ********************************/  

// disply a Date in a nice format
ostream& operator<<(ostream& out, const Date & date){

  // REQUIRES IMPLEMENTATION

}
