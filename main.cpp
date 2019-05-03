#include <iostream>
#include <string>
#include <vector>

#include "Address.h"
#include "Agency.h"
#include "Client.h"
#include "Date.h"
#include "Packet.h"

using namespace std;

int main()
{
  Agency agency("Agency.txt");   // create the agency
  /*
  cout << agency.getName() << endl;
  cout << agency.getAddress().getLocation() << endl;
  cout << agency.getClients()[0].getName() << endl;

  */
  cout << agency.getClients()[0].getName() << endl;
  agency.showClients();
  cout << endl;
  agency.showPackets();
 

  for (size_t i = 0; i < agency.getPackets().size(); i++)
  {
	  cout << endl;
	  cout << agency.getPackets()[i].getId() << endl;
	  for (size_t j = 0; j < agency.getPackets()[i].getPlaces().size(); j++)
	  {
		  cout << agency.getPackets()[i].getPlaces()[j];
		  if (j != agency.getPackets()[i].getPlaces().size())
			  cout << " , ";
	  }
	  cout << endl << agency.getPackets()[i].getBeginDate().getDay() << endl;
	  cout << agency.getPackets()[i].getEndDate().getDay() << endl;
	  cout << agency.getPackets()[i].getPricePerPerson() << endl;
	  cout << agency.getPackets()[i].getMaxTickets() << endl;
	  cout << agency.getPackets()[i].getAvailableTickets() << endl;
  }

  _getwch();
  return 0;

}
