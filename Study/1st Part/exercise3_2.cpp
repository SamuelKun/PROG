#include <iostream>

using namespace std;

bool isPrime(int number)
{
	
	for (int i = 2; i <= (int)sqrt(number); i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}


int main()
{
	int number;
	cout << "Escreva o numero: ";
	cin >> number;

	if (isPrime(number)) {
		cout << "The number is prime";
	}

	else {
		cout << "The number is not prime";
	}
}
