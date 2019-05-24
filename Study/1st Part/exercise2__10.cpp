#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int number, len=0, test, first, last;
	bool palindrome = true;

	cout << "Write your number: ";
	cin >> number; 
	test = number;

	do{
		test = test / 10;
		len++;
	} while (test);

	while (len > 1) 
	{
		first = number / pow(10, len-1);
		last = number % 10;

		if (last != first)
		{
			palindrome = false;
			break;
		}
		
		number = number - first*pow(10, len-1);
		number = number / 10;
		len = len - 2;
	}

	if (palindrome)
		cout << "The number is a palindrome!";
	else
		cout << "The number isn't a palindrome!";
}
