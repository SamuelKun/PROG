#include <iostream>
#include <cmath>

using namespace std;

int factorial_ite(int n)
{
	long int result;
	result = n;
	n = n - 1;
	for(n; n > 0; n--)
	{
		result = result * n;
	}
	return result;

}

int main()
{
	int number;
	cout << "Escreva o número ";
	cin >> number;

	cout << factorial_ite(number);
	return 0;
}