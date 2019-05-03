#include <iostream>
#include <string>
#include <vector>

#include "Address.h"
#include "Agency.h"
#include "Client.h"
#include "Date.h"
#include "Menus.h"
#include "Packet.h"

// #include "utils.h"


int main(){
  Agency agency(AGENCY_FILE_NAME);   // create the agency

  mainMenu(agency); // initial menu inicial with the major options of the application


  
  return 0;

}
