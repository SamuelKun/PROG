#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cout << "a, b, c: ";
	cin >> a >> b >> c;

	if (a > b && a > c)
			cout << "A, o maior: " << a <<endl;
	else
	{
		if (b > c && b > a)
		{
			cout << "B, o maior: " << b << endl;
		}
		else
			cout << "C, o maior: " << c << endl;
	}

	if (a < b && a < c)
		cout << "A, o menor: " << a << endl;
	else
	{
		if (b < c && b < a)
		{
			cout << "B, o menor: " << b << endl;
		}
		else
			cout << "C, o menor: " << c << endl;
	}


	if (a < b && a < c)
	{
		if (b < c) cout << a << b << c;

		else cout << a << c << b;
	}
	else 
		if (b < a && b < c)
		{
			if (a < c) cout << b << a << c;
			else cout << b << c << a;
		}
		else
		{
			if (c < a && c < b)
			{
				if (b < a) cout << c << b << a;
				else cout << c << a << b;
			}
		}
	}
