#include<iostream>
#include<vector>
#include<string>


using namespace std;

void bubblesort(vector<string> &v)
{
	for (int first = 0; first < v.size()-1; first++)
	{
		int iterations = v.size() - first - 1;
		for (int per = 0; per < iterations; per++)
		{
			if (v.at(per) > v.at(per+1))
			{
				string name = v[per];
				v[per] = v[per+1];
				v[per + 1] = name;
			}
		}

	}

}

int main()
{
	vector<string> names = {"Joana", "Maria", "Ana", "Anastasia", "Francisca"};

	bubblesort(names);
	
	for (int i = 0; i < names.size()-1; i++)
		cout << names[i] << " ";
	return 0;
}