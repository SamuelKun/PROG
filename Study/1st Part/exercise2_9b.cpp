#include <iostream>
#include <math.h>

using namespace std;

void main()
{
	double mean;
	int comp;

	int n, lowest = 9999, greatest = 0, sum = 0, counter = 0;
	cout << "comprimento ";
	cin >> comp

	while (c < comp) {
		if (n > greatest) 
			greatest = n;
		
		if (n < lowest && n != 0) 
			lowest = n;
		
		
		c++;
		counter += 1;
		sum += n;

	}

	cout << "The sum of the numbers is " << sum << ", the mean is " << sum / counter << ", the greatest one is " << greatest << " and the lowest is " << lowest << ".";


}

c)
#include <iostream>
#include <math.h>
#include <iterator>

using namespace std;

void main()
{
	double mean;

	int n, lowest = 9999, greatest = 0, sum = 0, counter = 0;
	

	while (cin >> n) {
		if (n > greatest) 
			greatest = n;
		
		if (n < lowest) 
			lowest = n;
		
		

		counter += 1;
		sum += n;

	}

	cout << "The sum of the numbers is " << sum << ", the mean is " << sum / counter << ", the greatest one is " << greatest << " and the lowest is " << lowest << ".";


}
