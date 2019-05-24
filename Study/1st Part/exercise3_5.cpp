// Falta alínea D e E

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int mdc(int m, int n)
{
	int div = m;
	while (div != 0)
	{
		if ((m%div == 0) && (n%div == 0))
		{
			return div;
		}
		div -= 1;
	}
}

void reduceFracc(int &numerator, int &denominator)
{
	int div;
	div = mdc(numerator, denominator);
	cout << endl << numerator / div << '/' << denominator / div;
}


void writeFracc(int numerator, int denominator)
{
	cout << endl << numerator << '/' << denominator;
}



bool readFracc(int &numerator, char &op, int &denominator)
{
	if ((numerator && denominator) != 0 && (op == '/')) return true;
	else return false;
}


int main()
{
	int numerator, denominator;
	char op;
	cout << "Fraction: ";
	cin >> numerator >> op >> denominator;
	cout << readFracc(numerator, op, denominator);
	writeFracc(numerator, denominator);
	reduceFracc(numerator, denominator);
	return 0;
}
