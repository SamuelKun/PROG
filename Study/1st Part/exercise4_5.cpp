#include <iostream>
#include <string>

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
	return 1;
}

struct Fraction
{
	int numerator;
	char op;
	int denominator;
};

Fraction readFracc()
{
	Fraction frac;
	cout << "Write the fraction: ";
	cin >> frac.numerator >> frac.op >> frac.denominator;

	return frac;
}

Fraction reduceFracc(Fraction f)
{
    int div;
    div = mdc(f.numerator, f.denominator);
    f.numerator = f.numerator / div;
    f.denominator = f.denominator / div;
    return f;

}
int main()
{
    Fraction frac = readFracc();
    frac = reduceFracc(frac);
    cout << frac.numerator << frac.op << frac.denominator;
    return 0;
}
