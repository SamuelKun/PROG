#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Address.h"
#include "Agency.h"
#include "Client.h"
#include "Date.h"
#include "Packet.h"
#include "Menus.h"

using namespace std;

void menu(Agency agency)
{
	system("CLS");
	char menu_1;            //Menu Principal

	cout << "Main Menu" << endl << endl;
	cout << "Select the number of the correct operation  " << endl << endl;

	cout << "[1] Manage Clients " << endl;
	cout << "[2] Manage Packs " << endl;
	cout << "[3] View Information " << endl;
	cout << "[4] Buy Packs " << endl;
	cout << "[0] Leave the programm " << endl << endl;

	cin >> menu_1;
}


int main()
{
	ifstream AgencyFile;
	string filename;
	cout << "Enter the agency file: ";
	cin >> filename;

	AgencyFile.open(filename);
	while (AgencyFile.fail())
	{
		cin.clear();
		cout << "Incorrect filename, please enter again: ";
		cin >> filename;
		AgencyFile.open(filename);
	}

  Agency agency(filename);   // create the agency

  bool dontEnd = true;
  while (dontEnd)
  {
	  dontEnd = mainMenu(agency);
  }
  _getwch();
  return 0;

}
