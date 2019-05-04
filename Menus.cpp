#include <iostream>
using namespace std;

#include "Address.h"
#include "Agency.h"
#include "Client.h"
#include "Date.h"
#include "Packet.h"



Agency NiceHolydays("agency.txt");

unsigned mainMenu(Agency agency)
{
	char menu;

	system("CLS");    //Clear Screen

	cout << "Main Menu" << endl <<  endl;

	cout << "[1] Manage Clients" << endl;
	cout << "[2] Manage Packs" << endl;
	cout << "[3] View Information " << endl;
	cout << "[4] Buy Packs " << endl;

	
	cin >> menu;

	switch (menu)
	{
	case('1'):        //Manage Clients
		manageClients(agency);
		break;

	case('2'):        //Manage Packs
		managePacks(agency);
		break;
	case('3'):        //View Information
		viewInformation(agency);
		break;
	case('4'):        //Buy Packs
		//agency.buyPacks();
		break;
	}
  
  return 0;
}

void manageClients(Agency agency)
{
	char menu;

	system("CLS");    //Clear Screen

	cout << "[1] Adicionar clientes " << endl;
	cout << "[2] Remover clientes " << endl;

	cin >> menu;


	switch (menu)
	{
	case('1'):        //Add Clients
		agency.addClient();
		break;
	case('2'):        //Remove Clients
		//agency.removeClient();
		break;
	}

}

void managePacks(Agency agency)
{
	char menu;

	system("CLS");    //Clear Screen
	cout << "Introduza a operacao que deseja efetuar  " << endl << endl;

	cout << "[1] Add Packs " << endl;
	cout << "[2] Remove Packs " << endl;

	cin >> menu;

	switch (menu)
	{
	case('1'):        //Add Packs
		//agency.addPack();
		break;
	case('2'):        //Remove packs
		//agency.removePack();
		break;
	}

}

void viewInformation(Agency agency)
{
	char menu;

	system("CLS");    //Clear Screen

	cout << "[1] View Clients " << endl;
	cout << "[2] View Packs " << endl;
	cout << "[3] View the ammount of packs sold and earned currency " << endl;
	
	cin >> menu;

	switch (menu)
	{
	case('1'):        //View Clients
		viewClients(agency);
		break;
	case('2'):        //View Packs
		viewPacks(agency);
		break;
	case('3'):        //View the ammount of packs sold and earned currency
		//agency.sold();
		break;
	}
}

void viewClients(Agency agency)
{
	char menu;

	system("CLS");    //Clear Screen

	cout << "[1] View All Clients " << endl;
	cout << "[2] View 1 client " << endl;

	cin >> menu;

	switch (menu)
	{
	case('1'):        //View All Clients
		agency.showClients();
		break;
	case('2'):        //View 1 Client
		//agency.show1Client();
		break;
	}
}


void viewPacks(Agency agency)
{
	char menu;

	system("CLS");    //Clear Screen

	cout << "[1] View All Packs " << endl;
	cout << "[2] View Specific Packs " << endl;

	cin >> menu;

	switch (menu)
	{
	case('1'):        //View All Packs
		agency.showPackets();
		break;
	case('2'):        //View Specific Packs

		break;
	}
}

void viewSpecificPacks(Agency agency)
{
	char menu;

	system("CLS");    //Clear Screen

	cout << "[1] Destiny " << endl;
	cout << "[2] Date " << endl;
	cout << "[3] Destiny and Date" << endl;
	cout << "[4] Client" << endl;

	cin >> menu;

	switch (menu)
	{
	case('1'):        //Destiny

		break;
	case('2'):        //Date

		break;
	case('3'):        //Destiny and Date

		break;
	case('4'):        //Client

		break;
	}
}
