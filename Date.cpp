#include "Date.h"
#include <fstream>
#include <sstream>

using namespace std;

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
unsigned short Date::getDay() const {
	return day;
}


unsigned short Date::getMonth() const {
	return month;
}

unsigned Date::getYear() const {
	return year;
}

/*********************************
 * SET Methods
 ********************************/

void Date::setDay(unsigned short day) {
	this->day = day;
}
void Date::setMonth(unsigned short month) {
	this->month = month;
}

void Date::setYear(unsigned year) {

	this->year = year;

}


/*********************************
 * Show Date
 ********************************/  
