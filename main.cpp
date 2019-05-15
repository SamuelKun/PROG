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

  Agency agency(filename);   // create the agency

  bool dontEnd = true;
  while (dontEnd)
  {
	  dontEnd = mainMenu(agency);
  }
  _getwch();
  return 0;

}
