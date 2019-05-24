#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int number;
	float result = 1, prev = 1.0;


	cout << "Write the number: ";
	cin >> number;
	
	for (int i = 1; i <= number; i++) {
		result += prev * (1.0/i);
		prev *= prev * (1.0/i);
	}
			
	cout << result;
	return 0;
}
