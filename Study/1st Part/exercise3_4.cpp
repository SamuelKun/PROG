#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


double round(double x, unsigned n)
{
	return floor(x * n + 0.5) / n;
}

int main()
{
	double number, n;
	cout << "Escreva o numero: ";
	cin >> number;
	cout << "Escreva a precisao: ";
	cin >> n;

	
	cout << fixed << setprecision(n);
	n = pow(10, n);
	cout << round(number, n);
	return 0;
}
