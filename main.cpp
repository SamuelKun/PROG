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

  cout << agency.getName() << endl;
  cout << agency.getAddress().getLocation() << endl;
  cout << agency.getClients()[0].getName() << endl;
  _getwch();
  return 0;

}
