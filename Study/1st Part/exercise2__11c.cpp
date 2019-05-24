#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int number;
	float x;
	float result = 1, prev = 1.0;


	cout << "Write the number: ";
	cin >> number;
	cout << "Now the x: ";
	cin >> x;
	
	for (int i = 1; i <= number; i++) {
		result += prev * (float)(x/i) * pow(-1,i);
		prev *= prev * (float)(x/i);
	}
			
	cout << result;
	return 0;
}
