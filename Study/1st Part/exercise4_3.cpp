#include <iostream>
#include <string>

using namespace std;

void decompose(string compound)
{
	string chara;
	int code;
	for (int i = 0; i < compound.length(); i++) 
	{
		code = (long)compound[i];
		if (65 <= code && code <= 90)
		{
			if (chara == "")
			{
				chara += compound[i];
			}
			else
			{
				cout << chara << endl;
				chara = "";
				chara += compound[i];
			}
		}
		else
		{
			if (97 <= code && code <= 122) 
			chara += compound[i];
		}
	}
	if (chara != "") cout << chara << endl;
}



int main()
{
	string chem;
	cout << "Write the chemical compound: ";
	cin >> chem;
	decompose(chem);
	
	return 0;
}


