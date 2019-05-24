#include<iostream>
#include<vector>

using namespace std;

void readIntVector(const vector<int> &v, int nElem)
{
	for (int i = 0; i < nElem; i++)
		cout << "Index: " << i << "\t Value :" << v[i] << endl;

}

int searchValueInIntVector(const vector<int> &v, int value)
{
	int counter = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i) == value)
		{
			return i;
		}
	}
	return -1;
}


int searchMultValueInIntVector(const vector<int> &v, int value)
{
	vector<int> index;
	int counter = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i) == value)
		{
			counter++;
		}
	}

	if (counter != 0) return counter; else return -1;

}

int main()
{
	vector<int> v = {5,7,8,3,5};
	readIntVector(v, 5);
	int elem;
	cout << "Número a procurar: " ;
	cin >> elem;
	cout << searchValueInIntVector(v, elem) <<endl;

	cout << searchMultValueInIntVector(v, elem) << endl;

	return 0;
}
