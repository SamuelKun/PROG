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
		cout << "Done! Press a letter to go back to Main Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '2':        //Remove Clients
		system("CLS");
		agency.showAllClientsName();
		cout << "Wich one you want to remove? ";
		cin >> idx;
		cin.ignore(10000, '\n');
		agency.removeClient(idx);
		cout << "Done! Press a letter to go back to Main Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '3':
		system("CLS");
		agency.showAllClientsName();
		cout << "Wich one you want to change? ";
		cin >> idx;
		cin.ignore(1000, '\n');
		agency.changeClient(idx);
		cout << "Done! Press a letter to go back to Main Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '0':
		return 0;
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
	system("CLS");    //Clear Screen
	cout << "Introduza a operacao que deseja efetuar  " << endl << endl;

	cout << "[1] Add Packs " << endl;
	cout << "[2] Remove Packs " << endl;
	cout << "[3] Change Packs " << endl;
	cout << "[0] Back to Main Menu" << endl;

	cin >> menu;

	switch (menu)
	{
	case'1':        //Add Packs
		agency.addPack();
		cout << "Done! Press a letter to go back to Main Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case'2':        //Remove Packs
		system("CLS");
		agency.showAllPacksID();
		cout << "Wich one you want to remove? ";
		cin >> idx;
		cin.ignore(10000, '\n');
		agency.removePack(idx);
		cout << "Done! Press a letter to go back to Main Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case'3':        //Change Packs
		system("CLS");
		agency.showAllPacksID();
		cout << "Wich one you want to change? ";
		cin >> idx;
		cin.ignore(10000, '\n');
		agency.changePack(idx);
		cout << "Done! Press a letter to go back to Main Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '0':
		return 0;
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

	cout << "[1] Destiny " << endl;
	cout << "[2] Date " << endl;
	cout << "[3] Destiny and Date" << endl;
	cout << "[4] Client" << endl;
	cout << "[0] Back to Main Menu" << endl;

	cin >> menu;

	switch (menu)
	{
	case '1':        //Destiny

		system("CLS");
		agency.showDestinyPacks();
		cout << "Done! Press a letter to go back to Main Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '2':        //Date
		system("CLS");
		agency.showDatePacks();
		cout << "Done! Press a letter to go back to Main Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '3':        //Destiny and Date
		system("CLS");
		agency.showDestinyAndDatePacks();
		cout << "Done! Press a letter to go back to Main Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '4':        //Client
		system("CLS");
		agency.show1ClientPacks();
		cout << "Done! Press a letter to go back to Main Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '0':
		return 0;
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

	cout << "[1] View all packs " << endl;
	cout << "[2] View all packs IDs " << endl;
	cout << "[3] View Specific Packs " << endl;
	cout << "[0] Back to Main Menu" << endl;

	cin >> menu;

	switch (menu)
	{
	case '1':        //View All Packs
		system("CLS");
		agency.showAllPackets();
		cout << "Done! Press a letter to go back to Main Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '2':
		system("CLS");
		agency.showAllPacksID();
		cout << "Done! Press a letter to go back to Main Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '3':        //View Specific Packs
		system("CLS");
		viewSpecificPacks(agency);
		cout << "Done! Press a letter to go back to Main Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '0':
		return 0;
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

	cout << "[1] View all clients " << endl;
	cout << "[2] View all clients' name " << endl;
	cout << "[3] View 1 client " << endl;
	cout << "[0] Back to Main Menu" << endl;

	cin >> menu;

	switch (menu)
	{
	case '1':        //View All Clients
		system("CLS");
		agency.showAllClients();
		cout << "Done! Press a letter to go back to Main Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '2':
		system("CLS");
		agency.showAllClientsName();
		cout << "Done! Press a letter to go back to Main Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '3':        //View 1 Client
		system("CLS");
		agency.show1Client();
		cout << "Done! Press a letter to go back to Main Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '0':
		return 0;
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

	system("CLS");    //Clear Screen

	cout << "[1] View Clients " << endl;
	cout << "[2] View Packs " << endl;
	cout << "[3] Search for a Pack " << endl;
	cout << "[4] View the ammount of packs sold and earned currency " << endl;
	cout << "[0] Back to Main Menu" << endl;

	cin >> menu;

	switch (menu)
	{
	case '1':        //View Clients
		viewClients(agency);
		break;
	case '2':        //View Packs
		viewPacks(agency);
		break;
	case '3':
		viewSpecificPacks(agency);
		break;
	case '4':        //View the ammount of packs sold and earned currency
		system("CLS");
		agency.ammountSold();
		cout << "Done! Press a letter to go back to Main Menu! ";
		cin >> menu;
		cin.ignore(10000, '\n');
		break;
	case '0':
		return 0;
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


//
//
//
//
//



unsigned mainMenu(Agency &agency)
{
	char menu;

	system("CLS");    //Clear Screen

	cout << "Main Menu" << endl << endl;

	cout << "[1] Manage Clients" << endl;
	cout << "[2] Manage Packs" << endl;
	cout << "[3] View Information " << endl;
	cout << "[4] Buy Packs " << endl;
	cout << "[0] Close Program " << endl;

		cin >> menu;

		switch (menu)
		{
		case '1':        //Manage Clients
			manageClients(agency);
			break;

		case '2':        //Manage Packs
			managePacks(agency);
			break;
		case '3':        //View Information
			viewInformation(agency);
			break;
		case '4':        //Buy Packs
			system("CLS");
			agency.buyPack();
			cin >> menu;
			cin.ignore(10000, '\n');
			break;
		case '0':
			return 0;
			break;
		default:
			mainMenu(agency);
			break;
		}

	return 1;
}