#include <iostream>
#include <string>

using namespace std;

bool sequenceSearch(string s, int nc, char c)
{
	int len = s.length(), count = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == c) count += 1;
		else count = 0;
		
		if (count == nc) return true;

	}
	return false;
}



int main()
{
	string grupo;
	int nc;
	char c;
	cout << "Escreva a string, o carater e o numero de ocorrencias: ";
	cin >> grupo >> c >> nc;
	
	cout << sequenceSearch(grupo, nc, c);
}