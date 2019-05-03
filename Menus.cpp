Agency NiceHolydays("agency.txt");

unsigned mainMenu(Agency agency)
{
	char menu;
	cout << "Main Menu" << endl <<  endl;

	cout << "[1] Show all Clients" << endl;
	cout << "[2] Show all Packs" << endl;
	
	cin >> menu;

	switch (menu)
	{
	case('1'):
		
		NiceHolydays.showClients();
		break;

	case('2'):
		NiceHolydays.showPackets();
		break;

	}


  

  
  return 0;
}
    
