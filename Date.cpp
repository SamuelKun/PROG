#include "Date.h"
#include <fstream>
#include <sstream>

using namespace std;

Date::Date()
{
}

Date::Date(string date)
{
  
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


Date::Date(unsigned short day, unsigned short month, unsigned year)
{
	this->day = day;
	this->month = month;
	this->year = year;

}

/*********************************
 * GET Methods
 ********************************/
unsigned short Date::getDay() const 
{
	return day;
}


unsigned short Date::getMonth() const
{
	return month;
}

unsigned Date::getYear() const 
{
	return year;
}

/*********************************
 * SET Methods
 ********************************/

void Date::manualDate()
{
	int this_year, this_month, this_day;
	cout << "	Year: ";
	cin >> this_year;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cin.ignore(1000, '\n');
		cout << "Not a valid number. Please reenter: ";
		cin >> this_year;
	}
	cout << "	Month: ";
	cin >> this_month;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cin.ignore(1000, '\n');
		cout << "Not a valid number. Please reenter: ";
		cin >> this_month;
	}
	cout << "	Day: ";
	cin >> this_day;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cin.ignore(1000, '\n');
		cout << "Not a valid number. Please reenter: ";
		cin >> this_day;
	}

	year = this_year;
	month = this_month;
	day = this_day;
}

void Date::setDay(unsigned short day) 
{
	this->day = day;
}
void Date::setMonth(unsigned short month) 
{
	this->month = month;
}

void Date::setYear(unsigned year) 
{
	this->year = year;
}

bool Date::isEqualTo(const Date & date)
{
	if (date.getYear() == year && date.getMonth() == month && date.getDay() == day)
		return true;
	return false;
}

bool Date::isAfter(const Date &date)
{
	if (year > date.year) return true;
	if (year == date.year && month > date.month) return true;
	if (year == date.year && month == date.month && day > date.day) return true;
	return false;
}

bool Date::isBefore(const Date &date)
{
	if (year < date.year) return true;
	if (year == date.year && month < date.month) return true;
	if (year == date.year && month == date.month && day < date.day) return true;
	return false;
}

/*********************************
 * ostream 
 ********************************/ 

ostream& operator<<(ostream& out, const Date &date) 
{
	out << date.getYear() << '/' << date.getMonth() << '/' << date.getDay() << endl;
	return out;
}
