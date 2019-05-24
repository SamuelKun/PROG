#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>



using namespace std;

class Date
{
public:
	Date();
	Date(unsigned int year, unsigned int month, unsigned int day);
	Date(string yearMonthDay); // yearMonthDay must be in format "yyyy/mm/dd"
	void setYear(unsigned int year);
	void setMonth(unsigned int month);
	void setDay(unsigned int day);
	void setDate(unsigned int year, unsigned int month, unsigned int day);
	unsigned int getYear() const;
	unsigned int getMonth() const;
	unsigned int getDay() const;
	string getDate() const; // returns the date in format "yyyy/mm/dd"
	void show() const; // shows the date on the screen in format "yyyy/mm/dd"
	bool isvalid();
	bool isEqualTo(const Date &date);
	bool isNotEqualTo(const Date &date);
	bool isAfter(const Date &date);
	bool isBefore(const Date &date);
private:
	unsigned int year;
	unsigned int month;
	unsigned int day;
};

// -----------------------------------------------------------------------
// MEMBER FUNCTIONS DEFINITIONS
// -----------------------------------------------------------------------

Date::Date()
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);

	year =  1900 + ltm.tm_year;
	month =  1 + ltm.tm_mon;
	day = ltm.tm_mday;

}
Date::Date(unsigned int year, unsigned int month, unsigned int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

Date::Date(string yearMonthDay)
{
	stringstream date_info(yearMonthDay);
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

void Date::setYear(unsigned int year) 
{
	this->year = year;
}
void Date::setMonth(unsigned int month)
{
	this->month = month;
}
void Date::setDay(unsigned int day)
{
	this->day = day;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

unsigned int Date::getYear() const
{
	return year;
}

unsigned int Date::getMonth() const
{
	return month;
}

unsigned int Date::getDay() const
{
	return day;
}

string Date::getDate() const
{
	string y = to_string(year), m = to_string(month), d = to_string(day);
	string yyyymmdd = y+ '/' + m + '/' + d;
	return yyyymmdd;
}

void Date::show() const
{
	cout << year << '/' << month << '/' << day;
}

bool Date::isvalid()
{
	if (month > 0 && month < 13)
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day <= 31) return true;
			else return false;
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day <= 30) return true;
			else return false;
		}
		if (month == 2)
		{
			if (day <= 28) return true;
			else return false;
		}
	}
	else return false;
}

bool Date::isEqualTo(const Date &date)
{
	if (date.getYear() == year || date.getMonth() == month || date.getDay() == day) return true;
	else return false;
}

bool Date::isNotEqualTo(const Date &date)
{
	if (date.getYear() == year || date.getMonth() == month || date.getDay() == day) return false;
	else return true;
}

bool Date::isAfter(const Date &date)
{
	if (date.getYear() > year) return true;
	else
	{
		if (date.getYear() == year && date.getMonth() > month) return true;
		else
		{
			if ((date.getYear() == year) && (date.getMonth() == month) && (date.getDay() > day)) return true;
			else return false;
		}
	}
}

bool Date::isBefore(const Date &date)
{
	if (date.getYear() > year) return false;
	else
	{
		if (date.getYear() == year && date.getMonth() > month) return false;
		else
		{
			if (date.getYear() == year && date.getMonth() == month && date.getDay() < day) return true;
			else return false;
		}
	}
}

int main()
{
	Date data1(2000, 06, 28), data2("2000/06/28"), data3;
	
	cout << "Data 1:" << data1.getDate() << endl;
	cout << "Data 2:" << data2.getDate() << endl;
	cout << "Current Date: " << data3.getDate();
	
	return 0;
}