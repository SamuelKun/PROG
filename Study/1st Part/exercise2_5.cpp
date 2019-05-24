#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	float a, b, c, delta;
	cout << "Escreva o valor de a, b e c: ";
	cin >> a >> b >> c;
	
	delta = (b*b) - 4 * a*c;
	
	if (delta > 0)
	{
		cout << ((-1 * b) - (sqrt(delta))) / (2 * a) << " e " << ((-1 * b) + (sqrt(delta))) / (2 * a);
	}
	else 
	{
		cout << (-1 * b)/(2*a) << "-" << (sqrt(-delta))  / (2 * a) << "i e " << (-1 * b)/(2*a) << "+" << (sqrt(-delta)) / (2 * a) << "i";
	
	}

}
