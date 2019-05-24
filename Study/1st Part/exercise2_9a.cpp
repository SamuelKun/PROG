#include <iostream>
#include <math.h>

using namespace std;

void main()
{
	double mean;

	int n, lowest = 9999, greatest = 0, sum = 0, counter = 0;
	

	while (n != 0) {
		if (n > greatest) 
			greatest = n;
		
		if (n < lowest) 
			lowest = n;
		
		

		counter += 1;
		sum += n;

	}

	cout << "The sum of the numbers is " << sum << ", the mean is " << sum / counter << ", the greatest one is " << greatest << " and the lowest is " << lowest << ".";


}
