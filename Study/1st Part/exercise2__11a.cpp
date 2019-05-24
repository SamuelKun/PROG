#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int number;
	float result = 0.0, i = 0.0;


	cout << "Write the number: ";
	cin >> number;

	for (int i = 0; i < number; i++) {
		result += (4.0 / (1 + 2 * i)) * pow((-1), i);
	}
			
	cout << result;
	return 0;
}
