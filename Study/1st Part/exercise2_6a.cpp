#include <iostream>

using namespace std;

void main()
{
	int number;
	bool prime = true;
	cout << "Escreva o numero: ";
	cin >> number;


	for (int i = 2; i <= (int)sqrt(number); i++) 
	{
		if (number % i == 0) 
		{
			prime = false;
			break;
		}
	}

	if (prime) {
		cout << "The number is prime";
	}

	else {
		cout << "The number is not prime";
	}
}
