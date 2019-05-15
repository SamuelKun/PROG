#include <iostream>
using namespace std;

#include "Address.h"
#include "Agency.h"
#include "Client.h"
#include "Date.h"
#include "Packet.h"

/*********************************
 * [1] MANAGE CLIENTS
 ********************************/

int manageClients(Agency &agency)
{
	char menu;
	int idx;
	system("CLS");   //Clear Screen
	cout << "Manage Clients" << endl << endl;

	cout << "[1] Add clients " << endl;
	cout << "[2] Remove clients " << endl;
	cout << "[3] Change clients " << endl;
	cout << "[0] Back to Main Menu " << endl;

	cin >> menu;


	switch (menu)
	{
	case '1':        //Add Clients
		system("CLS");
		agency.addClient();
		cout << "Press a letter to go back to the previous Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '2':        //Remove Clients
		system("CLS");
		agency.showAllClients();
		agency.showAllClientsName();
		cout << "Wich one you want to remove? ";
		do {
			do {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Order number: ";
				cin >> idx;
			} while (cin.fail());
		} while (idx >= agency.getClients().size() || idx < 0);

		cin.ignore(10000, '\n');
		agency.removeClient(idx);
		cout << "Press a letter to go back to the previous Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '3':        //Change clients
		system("CLS");
		agency.showAllClients();
		agency.showAllClientsName();
		cout << "Wich one you want to change? ";
		do {
			do {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Order number: ";
				cin >> idx;
			} while (cin.fail());
		} while (idx >= agency.getClients().size() || idx < 0);

		agency.changeClient(idx);
		cout << "Press a letter to go back to the previous Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '0':
		return 1;
		break;
	default:
		manageClients(agency);
		break;
	}
	return 0;
}

/*********************************
 * [2] MANAGE PACKS
 ********************************/
int managePacks(Agency &agency)
{
	char menu;
	int idx;
	system("CLS");
	cout << "Manage Packs" << endl << endl;

	cout << "[1] Add Packs " << endl;
	cout << "[2] Remove Packs " << endl;
	cout << "[3] Change Packs " << endl;
	cout << "[0] Back to Main Menu" << endl;

	cin >> menu;

	switch (menu)
	{
	case'1':        //Add Packs
		system("CLS");
		agency.addPack();
		cout << "Press a letter to go back to the previous Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case'2':        //Remove Packs
		system("CLS");
		agency.showAllPackets();
		agency.showAllPacksID();
		cout << "Wich one you want to remove? ";
			do {
				do {
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Order number: ";
					cin >> idx;
				} while (cin.fail());
			} while (idx >= agency.getPackets().size() || idx < 0);

		agency.removePack(idx);
		cout << "Press a letter to go back to the previous Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case'3':        //Change Packs
		system("CLS");
		agency.showAllPackets();
		agency.showAllPacksID();
		cout << "Wich one you want to change? ";
		do {
			do {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Order number: ";
				cin >> idx;
			} while (cin.fail());
		} while (idx >= agency.getPackets().size() || idx < 0);

		agency.changePack(idx);
		cout << "Press a letter to go back to the previous Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '0':
		return 1;
		break;
	default:
		managePacks(agency);
		break;
	}
	return 0;
}

/*********************************
 * [3] VIEW PACKS
 ********************************/

 /*********************************
  * VIEW METHODS
  ********************************/

int viewSpecificPacks(Agency &agency)
{
	char menu;

	system("CLS");    //Clear Screen
	cout << "Search for a pack" << endl << endl;

	cout << "[1] Destiny " << endl;
	cout << "[2] Date " << endl;
	cout << "[3] Destiny and Date" << endl;
	cout << "[4] Client" << endl;
	cout << "[0] Back to the previous Menu" << endl;

	cin >> menu;

	switch (menu)
	{
	case '1':        //Destiny

		system("CLS");
		agency.showDestinyPacks();
		cout << "Done! Press a letter to go back to the previous Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '2':        //Date
		system("CLS");
		agency.showDatePacks();
		cout << "Done! Press a letter to go back to the previous Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '3':        //Destiny and Date
		system("CLS");
		agency.showDestinyAndDatePacks();
		cout << "Done! Press a letter to go back to the previous Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '4':        //Client
		system("CLS");
		agency.show1ClientPacks();
		cout << "Done! Press a letter to go back to the previous Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '0':
		return 1;
	default:
		viewSpecificPacks(agency);
		break;
	}
	return 0;
}

int viewPacks(Agency &agency)
{
	char menu;

	system("CLS");    //Clear Screen
	cout << "View Packs" << endl << endl;

	cout << "[1] View all packs " << endl;
	cout << "[2] View all packs IDs " << endl;
	cout << "[3] View Specific Packs " << endl;
	cout << "[0] Back to the previous Menu" << endl;

	cin >> menu;

	switch (menu)
	{
	case '1':        //View All Packs
		system("CLS");
		agency.showAllPackets();
		cout << "Done! Press a letter to go back to the previous Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '2':
		system("CLS");
		agency.showAllPacksID();
		cout << "Done! Press a letter to go back to the previous Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '3':        //View Specific Packs
		system("CLS");
		viewSpecificPacks(agency);
		cout << "Done! Press a letter to go back to the previous Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '0':
		return 1;
		break;
	default:
		viewPacks(agency);
		break;
	}
	return 0;
}


int viewClients(Agency &agency)
{
	char menu;

	system("CLS");    //Clear Screen
	cout << "View Clients" << endl << endl;

	cout << "[1] View all clients " << endl;
	cout << "[2] View all clients name " << endl;
	cout << "[3] View one client " << endl;
	cout << "[0] Back to the previous Menu" << endl;

	cin >> menu;

	switch (menu)
	{
	case '1':        //View All Clients
		system("CLS");
		agency.showAllClients();
		cout << "Done! Press a letter to go back to the previous Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '2':
		system("CLS");
		agency.showAllClientsName();
		cout << "Done! Press a letter to go back to the previous Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '3':        //View 1 Client
		system("CLS");
		agency.show1Client();
		cout << "Done! Press a letter to go back to the previous Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '0':
		return 1;
		break;
	default:
		viewClients(agency);
		break;
	}
	return 0;
}

/*********************************
 * VIEW MAIN MENU
 ********************************/

int viewInformation(Agency &agency)
{
	char menu;
	int n;
	system("CLS");    //Clear Screen
	cout << "View Information" << endl << endl;

	cout << "[1] View Clients " << endl;
	cout << "[2] View Packs " << endl;
	cout << "[3] Search for a Pack " << endl;
	cout << "[4] View the ammount of packs sold and earned currency" << endl;
	cout << "[5] View the most visited places" << endl;
	cout << "[6] Popular places not yet visited by all clients" << endl;
	cout << "[0] Back to Main Menu" << endl;

	cin >> menu;

	switch (menu)
	{
	case '1':        //View Clients
		while(!viewClients(agency));
		break;
	case '2':        //View Packs
		while(!viewPacks(agency));
		break;
	case '3':
		while(!viewSpecificPacks(agency));
		break;
	case '4':        //View the ammount of packs sold and earned currency
		system("CLS");
		agency.ammountSold();
		cout << "Done! Press a letter to go back to the previous Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '5':        //View the most visited places
		system("CLS");
		cout << "How many places do you want to view? ";
		cin >> n;
		while (n < 0)
		{
			cout << "Value must be positive: ";
			cin.ignore(1000, '\n');
			cin.clear();
			cin >> n;
		}
		agency.mostVisited(n);
		cout << "Done! Press a letter to go back to the previous Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '6':
		system("CLS");
		int n;
		cout << "How many places do you want to view of top? ";
		cin >> n;
		while (n < 0)
		{
			cout << "Value must be positive: ";
			cin.ignore(1000, '\n');
			cin.clear();
			cin >> n;
		}
		agency.ClientMostVisited(n);
		cout << "Done! Press a letter to go back to the previous Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '0':
		return 1;
		break;
	default:
		viewInformation(agency);
		break;
	}
	return 0;
}

/*********************************
 * [4] BUY PACKS
 ********************************/

int buyPacks(Agency &agency)
{
	char menu;
	system("CLS");
	agency.buyPack();
	cout << "Press a letter to go back to Main Menu! ";
	cin >> menu;
	cin.ignore(10000, '\n');
	return 1;
}

/*********************************
 * [5] Agency Information
 ********************************/

int agencyInformation(Agency &agency)
{
	char menu;
	system("CLS");
	cout << "Agency: " << agency.getName() << endl << endl;
	cout << "URL: " << agency.getURL() << endl;
	cout << "NIF: " << agency.getVATnumber() << endl;
	cout << agency.getAddress() << endl;
	cout << "Press a letter to go back to Main Menu! ";
	cin >> menu;
	cin.ignore(10000, '\n');
	return 1;
}



unsigned mainMenu(Agency &agency)
{
	char menu;

	system("CLS");    //Clear Screen
	cout << "Main Menu" << endl << endl;

	cout << "[1] Manage Clients" << endl;
	cout << "[2] Manage Packs" << endl;
	cout << "[3] View Information " << endl;
	cout << "[4] Buy Packs " << endl;
	cout << "[5] Agency Information" << endl;
	cout << "[0] Close Program " << endl;

		cin >> menu;

		switch (menu)
		{
		case '1':        //Manage Clients
			while(!manageClients(agency));
			break;
		case '2':        //Manage Packs
			while(!managePacks(agency));
			break;
		case '3':        //View Information
			while(!viewInformation(agency));
			break;
		case '4':        //Buy Packs
			while(!buyPacks(agency));
			break;
		case '5':        //Agency Information
			while (!agencyInformation(agency));
			break;
		case '0':
			agency.writeAgency();
			return 0;
			break;
		default:
			mainMenu(agency);
			break;
		}

	return 1;
}