#include <iostream>
#include <cmath>

using namespace std;

int factorial_rec(int n)
{
	if (n == 0 | n == 1)
	{
		return 1;
	}
	else
	{
		return n * factorial_rec(n - 1);
	}

}

int main()
{
	int number;
	cout << "Escreva o número ";
	cin >> number;

	cout << factorial_rec(number);
	return 0;
}