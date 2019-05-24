#include <iostream>
#include <cmath>

using namespace std;

bool bi(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	else return false;
}

int main()
{
	int year;
	cout << "Year: ";
	cin >> year;
	cout << bi(year);
	return 0;
}
