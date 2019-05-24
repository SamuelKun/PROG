#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

void main()
{
	double pi = 3.14159265358979323846264338327950288419716939937510582097;
	cout << "ang\t\t sen\t\t cos\t\t tan" << endl;

	for (float i = 0; i <= 90; i = i + 15)
	{
		cout << fixed << setprecision(10) << (int)i << "\t" << (float)sin(i*pi/180) << "\t" << (float)cos(i*pi / 180) << "\t" << (float)tan(i*pi / 180) << "\t" << endl;

	}

}
