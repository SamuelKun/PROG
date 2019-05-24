#include <iostream>

using namespace std;

int mdc(int m, int n)
{
	if (m % n == 0)
	{
		return n;
	}
	else
	{
		return mdc(n, m%n);
	}
}

bool test()
{
	if (mdc(5, 1) != 1) return false;
	if (mdc(15, 5) != 5) return false;
	if (mdc(35, 15) != 5) return false;

	return true;

}

int main()
{
	int number1, number2;
	cout << "Escreva o número ";
	cin >> number1 >> number2;

	cout << mdc(number1, number2) << endl;
	cout << test();
	return 0;
}