#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Address.h"
#include "Agency.h"
#include "Client.h"
#include "Date.h"
#include "Packet.h"

using namespace std;

int main()
{
	ifstream AgencyFile;
	string filename;
	cout << "Enter the agency file: ";
	cin >> filename;

	AgencyFile.open(filename);
	while (AgencyFile.fail())
	{
		//AgencyFile.clear();
		cout << "Incorrect filename, please enter again: ";
		cin >> filename;
		AgencyFile.open(filename);
	}

  Agency agency(filename);   // create the agency

  cout << agency.getClients()[0].getName() << endl;
  agency.showClients();
  cout << endl;
  agency.showPackets();
 
  _getwch();
  return 0;

}
