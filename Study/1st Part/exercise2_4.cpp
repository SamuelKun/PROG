#include <iostream>

using namespace std;

int main()
{
	float peso;
	double dinheiro;

	cout << "Escreva o peso (em gramas): ";
	cin >> peso;

	if (peso < 500) 
		cout << "Custa 5 euros";
	else
	{
		if (500 <= peso && peso <= 1000)
		{
			dinheiro = 5 + 1.5 * (peso - 500) / 100;
			cout << "Custa " << dinheiro;
		}
		else
		{
			dinheiro = 12.5 + 5 * (peso - 1000) / 250;
				cout << "Custa " << dinheiro;
		}
	}
}
