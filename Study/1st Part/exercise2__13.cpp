#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int number;
	bool mult_simbol = false;

	cout << "Write the number: ";
	cin >> number;
	
	while (number != 1)
	{
		for (int div = 2; div <= number; div++)
		{
			if (mult_simbol)
			{
				mult_simbol = false;
				cout << "x ";

			}
			if (number%div == 0)
			{
				number = number / div;
				cout << div << " ";
				mult_simbol = true;
				break;
			}
		}
	}
}
