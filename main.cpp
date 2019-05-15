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

int main()
{
	ifstream AgencyFile;
	string filename;
	cout << R"(
  __  __  __     __                _____   ______   _   _    _____  __     __
 |  \/  | \ \   / /       /\      / ____| |  ____| | \ | |  / ____| \ \   / /
 | \  / |  \ \_/ /       /  \    | |  __  | |__    |  \| | | |       \ \_/ / 
 | |\/| |   \   /       / /\ \   | | |_ | |  __|   | . ` | | |        \   /  
 | |  | |    | |       / ____ \  | |__| | | |____  | |\  | | |____     | |   
 |_|  |_|    |_|      /_/    \_\  \_____| |______| |_| \_|  \_____|    |_|
)" << '\n';
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


	ifstream agencyfile(filename);

	vector<string> agency_info;
	string name_temp;
	if (agencyfile.is_open())
	{
		while (getline(agencyfile, name_temp))
		{
			agency_info.push_back(name_temp);
		}

		ifstream clientsfile(agency_info[4]);
		ifstream packsfile(agency_info[5]);
		if (clientsfile.is_open() && packsfile.is_open())
		{
			Agency agency(filename);   // create the agency
			while (!mainMenu(agency)); // Run the main menu
		}
		else cout << "Unable to open clients file or/and packsfile!";
		
	}
	else cout << "Unable to open agency file!";

  
  _getwch();
  return 0;

}
