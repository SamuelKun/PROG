#include <iostream>
#include <cmath>
using namespace std;

int distance(double x1, double y1, double x2, double y2)
{
	double lenght = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	return lenght;
}



int area(double x1, double y1, double x2, double y2, double x3, double y3)
{
	float a = distance(x1, y1, x2, y2);
		float b = distance(x3, y3, x1, y1);
		float c = distance(x3, y3, x2, y2);
	float s = (a + b + c) / 2;
	float integral = sqrt(s * (s - a) * (s - b) * (s - c));
	return integral;
}


int main() {
	float x1, y1, x2, y2, x3, y3;

	cout << "Insert the coordinates of the first point: ";
	cin >> x1 >> y1;
	cout << "Insert the coordinates of the second point: ";
	cin >> x2 >> y2;
	cout << "Insert the coordinates of the third point: ";
	cin >> x3 >> y3;	
	

	cout << "The area of the triangle is " << area(x1, y1, x2, y2, x3, y3) << " a. u.";
}
