
#include <iostream>
#include <cmath>
#include <iomanip> 

using namespace std;

int main()
{
	int number, pre;
	float x;
	float result = 1, prev = 1.0;


	cout << "Write the number: ";
	cin >> number;
	cout << "Now the x: ";
	cin >> x;
	cout << "Set precision: ";
	cin >> pre;
	
	for (int i = 1; i <= number; i++) {
		result += prev * (float)(x/i) * pow(-1,i);
		prev *= prev * (float)(x/i);
	}
			
	cout << fixed << setprecision(pre) << result;
	return 0;
}
