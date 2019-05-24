#include <iostream>
#include <string>

using namespace std;

void readIntArray(int a[], int nElem)
{
	for (int i = 0; i < nElem; i++)
	{
		cout << "Index: " << i << endl;
		cin >> a[i];
	}
}

int searchValueInIntArray(const int a[], int nElem, int value)
{
	for (int i = 0; i < nElem; i++)
	{
		if (value == a[i]) return i;
	}
	return -1;
}


int searchMultValueInIntArray(const int a[], int nElem, int value, int index[])
{
	int idx = 0;
	for (int i = 0; i < nElem; i++)
	{
		if (value == a[i])
		{
			index[idx] = i;
			idx++;
		};

	}
	return idx;
}


int main()
{
	int elem, a[100], value, index[100];
	cout << "Numero de elementos: ";
	cin >> elem;

	readIntArray(a, elem);
	cout << "Elemento a procurar: ";
	cin >> value;
	cout << searchValueInIntArray(a, elem, value) << endl;
	cout << searchMultValueInIntArray(a, elem, value, index) << endl;
	return 0;
}
