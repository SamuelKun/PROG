#include <iostream>

using namespace std;

int main()
{
	double a, b, result;
	char operation;
	cout << "a operator b" << endl;
	cin >> a;
	cin >> operation;
	cin >> b;

	switch (operation)
	{
	case '+':
		cout << a + b;
		break;
	case '-':
		cout << a - b;
		break;
	case '*':
		cout << a * b;
		break;
	case '/':
		cout << a / b;
		break;
	}

}
