#include <iostream>
#include <math.h>

using namespace std;

void main()
{
	float n, q,j;
	cout << "Taxa de juros";
	cin >> j;
	cout << "Quantia";
	cin >> q;
	cout << "Número de anos";
	cin >> n;
	
	cout << q*pow(n, (1 + j)) << endl;
}
