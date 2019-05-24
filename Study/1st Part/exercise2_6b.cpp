#include <iostream>

using namespace std;




void main()
{
	int number = 5, count = 2;
	bool prime = true;
	cout << "2";
	cout << "3";
	while (count < 100)
	{
		for (int i = 2; i <= (int)sqrt(number); i++)
		{
			if (number % i == 0)
			{
				prime = false;
				break;
			}
		}

		if (prime)
		{
			cout << number << endl;
			count++;
		}
		prime = true;
		number++;
	}
}
