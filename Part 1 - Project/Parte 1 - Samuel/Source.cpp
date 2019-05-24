/*
1. Ler e guardar a informa��o da ag�ncia, dos clientes e dos pacotes tur�sticos armazenada em ficheiros. Done V
2. Gerir os clientes e pacotes tur�sticos: criar, alterar e remover um cliente ou um pacote tur�stico. DONE
3. Gerar e visualizar de modo formatado a informa��o de um cliente especificado. DONE
4. Gerar e visualizar de modo formatado a informa��o de todos os clientes da ag�ncia. DONE
5. Gerar e visualizar de modo formatado os pacotes tur�sticos dispon�veis . DONE
(todos, todos relativos a um destino espec�fico, todos entre duas datas, todos os relativos a um destino espec�fico e entre duas datas).
Almost DONE
6. Gerar e visualizar de modo formatado os pacotes tur�sticos vendidos (a um cliente espec�fico, a todos os clientes). DONE
7. Efetuar a compra de um pacote tur�stico por um cliente. DONE
8. Calcular e visualizar o n�mero e o valor total de pacotes vendidos. DONE
*/


#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "structs.h"

using namespace std;


//Function to get the Date
Date getDate(string info)
{
	stringstream date_info(info);
	string temp;
	vector<string> date_temp;
	while (getline(date_info, temp, '/'))
	{
		date_temp.push_back(temp);
	}

	Date date_comp;
	date_comp.year = stoi(date_temp[0]);
	date_comp.month = stoi(date_temp[1]);
	date_comp.day = stoi(date_temp[2]);
	return date_comp;
}

//Function to get the address of Agency and each client
Address getAddress(string info)
{
	stringstream address_info(info);
	string temp;
	vector<string> address_temp;

	while (getline(address_info, temp,  '/'))
	{
		//Remove leading and trailing spaces
		while (temp[0] == ' ') temp.erase(0, 1);
		while (temp[temp.size() - 1] == ' ') temp.erase(temp.size() - 1, temp.size());

		address_temp.push_back(temp);
	}

	Address address_comp;
	address_comp.Street = address_temp[0];
	address_comp.Door = address_temp[1];
	address_comp.Floor = address_temp[2];
	address_comp.Postal_Code = address_temp[3];
	address_comp.Locality = address_temp[4];
	
	return address_comp;
}

//Function to get the pack list of each client
vector<string> getPacks(string info)
{
	stringstream pack_info(info);
	string temp;
	vector<string> pack_temp;
	while (getline(pack_info, temp, ';'))
	{
		//Remove leading and trailing spaces
		while (temp[0] == ' ') temp.erase(0, 1);
		while (temp[temp.size() - 1] == ' ') temp.erase(temp.size() - 1, temp.size());

		pack_temp.push_back(temp);
	}


	return pack_temp;
}

//Read Agency File
vector<string> ReadAgencyFile(string file_name)
{
	ifstream info(file_name);
	vector<string> agency_info;
	string name;
	if (info.is_open())
	{
		while (getline(info, name))
		{
			agency_info.push_back(name);
		}
		info.close();
	}
	else cout << "Unable to open file";

	return agency_info;
}//

//Put Agency Details into a struct
void DefAgency(Agency &NiceHolidays, vector<string> agency_info)
{
	NiceHolidays.name = agency_info[0];
	NiceHolidays.NIF = stoi(agency_info[1]);
	NiceHolidays.url = agency_info[2];
	NiceHolidays.address = getAddress(agency_info[3]);
	
	//
	// Client Information
	ifstream client_info(agency_info[4]);
	string name;
	vector<string> client_list;
	vector<Client> vector_client;
	Client temp_client;

	while (getline(client_info, name))
	{
		if (name != "::::::::::") client_list.push_back(name);
		else
		{
			temp_client.name= client_list[0];
			temp_client.nif = client_list[1];
			temp_client.household = client_list[2];
			temp_client.address = getAddress(client_list[3]);
			temp_client.packs_bought = getPacks(client_list[4]);
			temp_client.total_purchases = temp_client.packs_bought.size();
			vector_client.push_back(temp_client);
			client_list.clear();
		}
	}

	//Add the last client
	temp_client.name = client_list[0];
	temp_client.nif = client_list[1];
	temp_client.household = client_list[2];
	temp_client.address = getAddress(client_list[3]);
	temp_client.packs_bought = getPacks(client_list[4]);
	temp_client.total_purchases = temp_client.packs_bought.size();
	vector_client.push_back(temp_client);
	client_list.clear();
	NiceHolidays.clients = vector_client;
	client_info.close();

	//
	// TravelPack Information
	ifstream pack_info(agency_info[5]);
	vector<string> pack_list;
	vector<TravelPack> vector_pacote;
	TravelPack pacote;

	getline(pack_info, NiceHolidays.lastTravelPack);

	while (getline(pack_info, name))
	{
		if (name != "::::::::::") pack_list.push_back(name);
		else
		{
			pacote.identifier = pack_list[0];
			pacote.locals = pack_list[1];
			pacote.start_date = getDate(pack_list[2]);
			pacote.end_date = getDate(pack_list[3]);
			pacote.price = stoi(pack_list[4]);
			pacote.capacity = pack_list[5];
			pacote.sold = stoi(pack_list[6]);
			vector_pacote.push_back(pacote);
			pack_list.clear();
		}
	}

	//Add the last pack
	pacote.identifier = pack_list[0];
	pacote.locals = pack_list[1];
	pacote.start_date = getDate(pack_list[2]);
	pacote.end_date = getDate(pack_list[3]);
	pacote.price = stoi(pack_list[4]);
	pacote.capacity = pack_list[5];
	pacote.sold = stoi(pack_list[6]);
	vector_pacote.push_back(pacote);
	pack_list.clear();


	pack_info.close();
	NiceHolidays.packages = vector_pacote;
}

//Confirm [Y/N] Function
bool confirmFunction(char confirm)
{
	switch (confirm)
	{
	case 'y':
		return true;
		break;
	case 'n':
		return true;
		break;
	default:
		cout << "Invalid Output![Y/N] ";
		return false;
		break;
	}
	
}

//
// Save Function
void Save(Agency &NiceHolidays, string clients_file, string packs_file)
{
	ofstream write_clients(clients_file);
	ofstream write_packs(packs_file);

	//Clients
	for (size_t i = 0; i < NiceHolidays.clients.size(); i++)
	{
		write_clients << NiceHolidays.clients[i].name << endl << NiceHolidays.clients[i].nif << endl;
		write_clients << NiceHolidays.clients[i].household << endl;
		write_clients << NiceHolidays.clients[i].address.Street << " / " << NiceHolidays.clients[i].address.Door << " / " << NiceHolidays.clients[i].address.Floor << " / " << NiceHolidays.clients[i].address.Postal_Code << " / " << NiceHolidays.clients[i].address.Locality <<endl;
		for (int j = 0; j < NiceHolidays.clients[i].total_purchases; j++)
		{
			write_clients << NiceHolidays.clients[i].packs_bought[j];
			if (j != NiceHolidays.clients[i].total_purchases - 1) write_clients << " ; ";
		}
		if (i != NiceHolidays.clients.size() - 1) write_clients << endl << "::::::::::" << endl;
	}

	//TravelPacks
	write_packs << NiceHolidays.lastTravelPack << endl;

		for (size_t i = 0; i < NiceHolidays.packages.size(); i++)
		{
			write_packs << NiceHolidays.packages[i].identifier << endl << NiceHolidays.packages[i].locals << endl;
			write_packs << NiceHolidays.packages[i].start_date.year << '/' << NiceHolidays.packages[i].start_date.month << '/' << NiceHolidays.packages[i].start_date.day << endl;
			write_packs << NiceHolidays.packages[i].end_date.year << '/' << NiceHolidays.packages[i].end_date.month << '/' << NiceHolidays.packages[i].end_date.day << endl;
			write_packs << NiceHolidays.packages[i].price << endl << NiceHolidays.packages[i].capacity << endl << NiceHolidays.packages[i].sold;
			if (i != NiceHolidays.packages.size() - 1) write_packs << endl << "::::::::::" << endl;
		}
}


//
//	CLIENTS AREA
//Show Clients name in a list
void showClientsName(Agency &NiceHolidays)
{
	cout << "The clients are as follows: " << endl;
	for (size_t i = 1; i <= NiceHolidays.clients.size(); i++)
	{
		cout << i << ": " << NiceHolidays.clients[i - 1].name << endl;
	}
}

//Show specific information about one client
void showSelectedClient(Agency &NiceHolidays, int n)
{
	int last;
	cout << "\n----------------------- Information about " << NiceHolidays.clients[n].name << " -----------------------\n";
	cout << "Name: " << NiceHolidays.clients[n].name << "\nNIF: " << NiceHolidays.clients[n].nif
		<< "\nSize of Household " << NiceHolidays.clients[n].household << "\nStreet: " << NiceHolidays.clients[n].address.Street
		<< "\nDoor: " << NiceHolidays.clients[n].address.Door << "\nFloor: " << NiceHolidays.clients[n].address.Floor
		<< "\nPostal_Code: " << NiceHolidays.clients[n].address.Postal_Code << "\nLocality: " << NiceHolidays.clients[n].address.Locality << "\nPacks: ";
	for (int i = 0; i < NiceHolidays.clients[n].total_purchases - 1; i++)
	{
		cout << NiceHolidays.clients[n].packs_bought[i] << " / ";
	}
	last = NiceHolidays.clients[n].total_purchases - 1;
	cout << NiceHolidays.clients[n].packs_bought[last];
	cout << "\nTotal Purchases: " << NiceHolidays.clients[n].total_purchases;
}

//Add a new client
void AddClient(Agency &NiceHolidays)
{
	Client NewClient;
	string temp;
	cin.ignore(1000, '\n');
	cout << "Name: " << endl;
	getline(cin, NewClient.name);
	cout << "NIF: " << endl;
	getline(cin, NewClient.nif);
	cout << "Size of household: " << endl;
	cin >> NewClient.household;
	cin.ignore(1000, '\n');
	cout << "Adress:" << endl;
	cout << "	Street: ";
	getline(cin, NewClient.address.Street);
	cout << "	Door: ";
	getline(cin, NewClient.address.Door);
	cout << "	Floor: ";
	getline(cin, NewClient.address.Floor);
	cout << "	Postal Code: ";
	getline(cin, NewClient.address.Postal_Code);
	cout << "	Locality: ";
	getline(cin, NewClient.address.Locality);
	cout << "Packages: (Separate with ;)" << endl;
	getline(cin, temp);
	NewClient.packs_bought = getPacks(temp);
	NewClient.total_purchases = NewClient.packs_bought.size();

	NiceHolidays.clients.push_back(NewClient);
	system("CLS");
}

//Change a client details
void ChangeClient(Agency &NiceHolidays)
{
	string temp;
	char confirm;

	showClientsName(NiceHolidays);
	cout << "Wich one you want to change? ";
	int n; cin >> n;
	cout << "Are you sure about change " << NiceHolidays.clients[n - 1].name << " data? [Y/N] ";

	do {
		cin >> confirm;
		confirm = tolower(confirm);
	} while (!confirmFunction(confirm));

	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Name: " << endl;
	getline(cin, NiceHolidays.clients[n - 1].name);
	cout << "NIF: " << endl;
	getline(cin,NiceHolidays.clients[n - 1].nif);
	cout << "Size of household: " << endl;
	cin >> NiceHolidays.clients[n - 1].household;
	cin.ignore(1000, '\n');
	cout << "Adress:" << endl;
	cout << "	Street: ";
	getline(cin, NiceHolidays.clients[n - 1].address.Street);
	cout << "	Door: ";
	getline(cin, NiceHolidays.clients[n - 1].address.Door);
	cout << "	Floor: ";
	getline(cin, NiceHolidays.clients[n - 1].address.Floor);
	cout << "	Postal Code: ";
	getline(cin, NiceHolidays.clients[n - 1].address.Postal_Code);
	cout << "	Locality: ";
	getline(cin, NiceHolidays.clients[n - 1].address.Locality);
	cout << "Packages: (Separate with ;)" << endl;
	getline(cin, temp);
	NiceHolidays.clients[n - 1].packs_bought = getPacks(temp);
	NiceHolidays.clients[n - 1].total_purchases = NiceHolidays.clients[n - 1].packs_bought.size();

	cout << endl << "Done! Press a button to go back to main menu: ";
	cin >> confirm;
}

//Remove a client
void RemoveClient(Agency &NiceHolidays)
{
	showClientsName(NiceHolidays);
	cout << "Wich one you want to remove? ";
	int n; cin >> n;
	cout << "Are you sure about delete " << NiceHolidays.clients[n - 1].name << "data? [Y/N] " << endl;
	
	char confirm;

	do {
		cin >> confirm;
		confirm = tolower(confirm);
	}
	while (!confirmFunction(confirm));
	
	NiceHolidays.clients.erase(NiceHolidays.clients.begin() + n - 1);

	char button;
	cout << endl << "Press a button to go back to main menu: ";
	cin >> button;
}



//
//	TRAVELPACKS AREA
//Show TravelPacks in a list
void showPacksIds(Agency &NiceHolidays)
{
	cout << "Available TravelPacks: " << endl;
	for (size_t i = 1; i <= NiceHolidays.packages.size(); i++)
	{
		cout << i << ": " << NiceHolidays.packages[i - 1].identifier << endl;
	}

}

//Show specific information about one TravelPack
void showSelectedPack(Agency &NiceHolidays, int n)
{
	cout << "\n----------------------- Information about " << NiceHolidays.packages[n].identifier << " -----------------------\n";
	cout << "Identifier: " << NiceHolidays.packages[n].identifier << "\nLocals: " << NiceHolidays.packages[n].locals
		<< "\nStart Date: " << NiceHolidays.packages[n].start_date.year << '/' << NiceHolidays.packages[n].start_date.month << '/'
		<< NiceHolidays.packages[n].start_date.day << "\nEnd Date: " << NiceHolidays.packages[n].end_date.year << '/' 
		<< NiceHolidays.packages[n].start_date.year << '/' << NiceHolidays.packages[n].start_date.month << '/' 
		<< NiceHolidays.packages[n].start_date.day << "\nPrice: " << NiceHolidays.packages[n].price 
		<< "\nCapacity: " << NiceHolidays.packages[n].capacity << "\nSold Tickets: " << NiceHolidays.packages[n].sold;
}

//Add a new Pack
void AddPack(Agency &NiceHolidays)
{
	TravelPack NewPack;
	cin.clear();
	cin.ignore(10000, '\n');
	string info, id;

	cout << "Identifier: " << endl;
	getline(cin, id);
	NewPack.identifier = id;
	NiceHolidays.lastTravelPack = id;
	cout << "Locals: " << endl;
	getline(cin, NewPack.locals);
	cout << "Start Date: (Year/Month/Day)" << endl;
	getline(cin, info);
	NewPack.start_date = getDate(info);
	cout << "End Date: (Year/Month/Day)" << endl;
	getline(cin, info);
	NewPack.end_date = getDate(info);
	cin.clear();
	cout << "Price: " << endl;
	cin >> NewPack.price;
	cout << "Capacity: " << endl;
	cin >> NewPack.capacity;
	cout << "Sold: " << endl;
	cin >> NewPack.sold;

	NiceHolidays.packages.push_back(NewPack);
	system("CLS");
}

//Change a Pack details
void ChangePack(Agency &NiceHolidays)
{
	string info;
	showPacksIds(NiceHolidays);
	cout << "Wich one you want to change? ";
	int n; cin >> n; n -= 1;
	cout << "Are you sure about change " << NiceHolidays.packages[n].identifier << " data? [Y/N] " << endl;

	char confirm;
	do {
		cin >> confirm;
		confirm = tolower(confirm);
	} while (!confirmFunction(confirm));

	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Identifier: " << endl;
	cin >> NiceHolidays.packages[n].identifier;
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Locals: " << endl;
	getline(cin, NiceHolidays.packages[n].locals);
	cout << "Start Date: (Year/Month/Day)" << endl;
	getline(cin, info);
	NiceHolidays.packages[n].start_date = getDate(info);
	cout << "End Date: (Year/Month/Day)" << endl;
	getline(cin, info);
	NiceHolidays.packages[n].end_date = getDate(info);
	cin.clear();
	cout << "Price: " << endl;
	cin >> NiceHolidays.packages[n].price;
	cout << "Capacity: " << endl;
	cin >> NiceHolidays.packages[n].capacity;
	cout << "Sold: " << endl;
	cin >> NiceHolidays.packages[n].sold;

	system("CLS");
}

//Remove a Pack
void RemovePack(Agency &NiceHolidays)
{
	showPacksIds(NiceHolidays);
	cout << "Wich one you want to remove? ";
	int n; cin >> n;
	cout << "Are you sure about delete " << NiceHolidays.packages[n - 1].identifier << " data? [Y/N] ";
	char confirm;

	do {
		cin >> confirm;
		confirm = tolower(confirm);
	} while (!confirmFunction(confirm));

	NiceHolidays.packages.erase(NiceHolidays.packages.begin() + n - 1);

	char button;
	cout << endl << "Press a button to go back to main menu: ";
	cin >> button;
}

//
//Packs Sold
void PacksSold(Agency &NiceHolidays)
{
	char char_type;
	cout << "[a] One Client \n[b] All Clients\nSelect One: " ;
	cin >> char_type;
	int last;
	bool invalid;
	do{
		switch (char_type)
		{
		case 'a':
			invalid = false;
			showClientsName(NiceHolidays);
			cout << "Select One: ";
			int n; cin >> n;
			n = n - 1;
			cout << endl << NiceHolidays.clients[n].name << " bought the following packs: " << endl;
			for (int i = 0; i < NiceHolidays.clients[n].total_purchases -1; i++)
			{
				cout << NiceHolidays.clients[n].packs_bought[i] << " / ";
			}
			last = NiceHolidays.clients[n].total_purchases - 1;
			cout << NiceHolidays.clients[n].packs_bought[last];
			break;
		case 'b':
			invalid = false;
			for(size_t client_number = 0; client_number < NiceHolidays.clients.size(); client_number++)
			{ 
				cout << endl << NiceHolidays.clients[client_number].name << " bought the following packs: " << endl;
				for (int i = 0; i < NiceHolidays.clients[client_number].total_purchases - 1; i++)
				{
					cout << NiceHolidays.clients[client_number].packs_bought[i] << " / ";
				}
				last = NiceHolidays.clients[client_number].total_purchases-1;
				cout << NiceHolidays.clients[client_number].packs_bought[last];
			}
			break;
		default:
			invalid = true;
			cout << "Invalid Input! Try again: ";
			break;
		}
		}while (invalid);
	}

//Find TravelPacks between two given dates
void BetweenDates(vector<TravelPack> packages, Date start, Date end)
{
	for (size_t i = 0; i < packages.size(); i++)
	{
		if (packages[i].start_date.year > start.year && packages[i].end_date.year < end.year)
		{
			cout << packages[i].locals << endl;
		}
		else
		{
			if (packages[i].start_date.year == start.year && packages[i].start_date.month > start.month && packages[i].end_date.year == end.year && packages[i].end_date.month < end.month)
			{
				cout << packages[i].locals << endl;
			}
			else
			{
				if (packages[i].start_date.year == start.year && packages[i].start_date.month == start.month && packages[i].start_date.day >= start.day)
				{
					if (packages[i].end_date.year == end.year && packages[i].end_date.month == end.month && packages[i].end_date.day <= end.day)
					{
						cout << packages[i].locals << endl;
					}
				}
			}
		}
	}
}

//Search Packs
void SearchPacks(Agency &NiceHolidays)
{
	string place, temp;
	vector<TravelPack> temp_packs;
	Date start, end;
	char a;
	cin >> a;
	switch (a)
	{
	case 'a':
		cout << "Write the location: ";
		cin.clear();
		cin.ignore(10000, '\n');
		getline(cin, place);
		for (size_t i = 0; i < NiceHolidays.packages.size(); i++)
		{
			if (NiceHolidays.packages[i].locals.find(place) != string::npos)
			{
				cout << NiceHolidays.packages[i].locals << endl;
			}
		}
		break;
	case 'b':

		cout << "Write the start date: (YYYY/MM/DD)\n";
		cin.ignore(100, '\n');
		getline(cin, temp);
		start = getDate(temp);
		cout << "Write the end date: (YYYY/MM/DD)\n";
		getline(cin, temp);
		end = getDate(temp);

		BetweenDates(NiceHolidays.packages, start, end);

		break;
	case 'c':
		cout << "Write the location: ";
		cin.clear();
		cin.ignore(10000, '\n');
		getline(cin, place);

		for (size_t i = 0; i < NiceHolidays.packages.size(); i++)
		{
			if (NiceHolidays.packages[i].locals.find(place) != string::npos)
			{
				temp_packs.push_back(NiceHolidays.packages[i]);
			}
		}

		cout << "Write the start date: (YYYY/MM/DD)\n";
		getline(cin, temp);
		start = getDate(temp);
		cout << "Write the end date: (YYYY/MM/DD)\n";
		getline(cin, temp);
		end = getDate(temp);
		BetweenDates(temp_packs, start, end);
		break;
	default:
		cout << "Error";
		break;
	}
}

void PurchasePack(Agency &NiceHolidays)
{
	int pack_number, client_number;
	int lenght = NiceHolidays.packages.size();
	char confirm;
	showPacksIds(NiceHolidays);
	cout << "What do you want to buy? You can't buy packages with '-' before!\n";
	do{
		do {
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> pack_number;
			pack_number = pack_number - 1;
		} while (pack_number >=  lenght || pack_number < 0);
	}
	while (NiceHolidays.packages[pack_number].identifier[0] == '-');
	
	showSelectedPack(NiceHolidays, pack_number);
	cout << endl << "Are you sure about purchase " << NiceHolidays.packages[pack_number].identifier << " pack? [Y/N] " << endl;
	do {
		cin >> confirm;
		confirm = tolower(confirm);
	} while (!confirmFunction(confirm));


	switch (confirm)
	{
	case 'y':
		showClientsName(NiceHolidays);
		cout << "Are you one of the above: [Y/N]" << endl;
		do {
			cin >> confirm;
			confirm = tolower(confirm);
		} while (!confirmFunction(confirm));

		switch (confirm)
		{
		case 'y':
			cout << "Select the number that correspond to your name: ";
			cin >> client_number;
			client_number = client_number - 1;
			NiceHolidays.clients[client_number].packs_bought.push_back(NiceHolidays.packages[pack_number].identifier);
			NiceHolidays.clients[client_number].total_purchases += 1;
			break;
		case 'n':
			cout << "Creating a new profile..." << endl;
			AddClient(NiceHolidays);
			break;
		default:
			break;
		}
		break;
	case 'n':
		cout << "Canceled";
		break;
	default:
		break;
	}
}

void TotalValue(Agency &NiceHolidays)
{
	cout << "VALUE OF SOLD PACKAGES\n\n";
	cout << "Total:" << endl;
	int total_sold = 0, value = 0;
	for (size_t i = 0; i < NiceHolidays.packages.size(); i++)
	{
		total_sold += NiceHolidays.packages[i].sold;
		value += (NiceHolidays.packages[i].price * NiceHolidays.packages[i].sold);
	}
	cout << "Total number of packages sold: " << total_sold << endl;
	cout << "Total value of packages sold: " << value;
	cout << "\n\nTotal (only packs bought by clients of this agency):" << endl;
	
	int total_client = 0, value_client = 0;
	for (size_t pack = 0; pack < NiceHolidays.packages.size(); pack++)
		for (size_t i = 0; i < NiceHolidays.clients.size(); i++)
		{
			for (int p = 0; p < NiceHolidays.clients[i].total_purchases; p++)
			{
				if (stoi(NiceHolidays.packages[pack].identifier) == stoi(NiceHolidays.clients[i].packs_bought[p]) || stoi(NiceHolidays.packages[pack].identifier) == -stoi(NiceHolidays.clients[i].packs_bought[p]))
				{
					total_client += 1;
					value_client += (NiceHolidays.packages[pack].price);
				}

			}
		}
	cout << "Total number of packages sold: " << total_client << endl;
	cout << "Total value of packages sold: " << value_client << endl;

}

// MAIN MENU
void Menu(Agency &NiceHolidays)
{
		bool invalid;
		char char_type;
		cout << "NICEHOLIDAYS \n-------------\nMain Menu \n\n[a] Manage Clients \n[b] Clients Information \n[c] Manage Packs\n[d] Packs Information\n";
		cout << "[e] Make a purchase\n[f] Number and total value of packages sold" << endl;
		do {
			cin >> char_type;
			char_type = tolower(char_type);
			switch (char_type)
			{
			case 'a':
				invalid = false;
				system("CLS");
				cout << "Manage Clients\n[a] Add a New Client \n[b] Change a Client Information\n[c] Remove a Client \n[d] Back to main menu\nSelect one option: " << endl;

				do {
					cin >> char_type;
					char_type = tolower(char_type);
					switch (char_type)
					{
					case 'a':
						invalid = false;
						system("CLS");
						AddClient(NiceHolidays);
						break;
					case 'b':
						invalid = false;
						system("CLS");
						ChangeClient(NiceHolidays);
						break;
					case 'c':
						invalid = false;
						system("CLS");
						RemoveClient(NiceHolidays);
						break;
					case 'd':
						invalid = false;
						system("CLS");
						Menu(NiceHolidays);
						break;
					default:
						cout << "Invalid Input! Try again: ";
						invalid = true;
						break;
					}
				} while (invalid);
				break;

			case 'b':
				invalid = false;
				system("CLS");
				cout << "Clients Information\n[a] Detailed information about one client\n[b] Information about all clients\n[c] Back to main menu\nSelect one option: "<< endl;


				do {
					cin >> char_type;
					char_type = tolower(char_type);
					switch (char_type)
					{
					case 'a':
						invalid = false;
						showClientsName(NiceHolidays);
						cout << "Select one client: ";
						int n; cin >> n; n -= 1;

						showSelectedClient(NiceHolidays, n);
						cout << "\nWrite to go back to main menu: ";
						char a;
						cin >> a;
						break;
					case 'b':
						invalid = false;
						for (size_t i = 0; i < NiceHolidays.clients.size(); i++)
						showSelectedClient(NiceHolidays, i);
						cout << "\nWrite to go back to main menu: ";
						cin >> char_type;
						break;
					case 'c':
						invalid = false;
						system("CLS");
						Menu(NiceHolidays);
						break;
					default:
						cout << "Invalid Input! Try again: ";
						invalid = true;
						break;
					}
				} while (invalid);
				break;

			case 'c':
				invalid = false;
				system("CLS");
				cout << "Manage Packs\n[a] Add a New Pack \n[b] Change a Pack Information\n[c] Remove a Pack \n[d] Back to main menu" << endl;

				do {
					cin >> char_type;
					switch (char_type)
					{
					case 'a':
						invalid = false;
						system("CLS");
						AddPack(NiceHolidays);
						break;
					case 'b':
						invalid = false;
						system("CLS");
						ChangePack(NiceHolidays);
						break;
					case 'c':
						invalid = false;
						system("CLS");
						RemovePack(NiceHolidays);
						break;
					case 'd':
						invalid = false;
						system("CLS");
						Menu(NiceHolidays);
						break;
					default:
						cout << "Invalid Input! Try again: ";
						invalid = true;
						break;
					}
				} while (invalid);
				break;

			case 'd':
				invalid = false;
				system("CLS");
				showPacksIds(NiceHolidays);
				cout << "--------------------------\n[a] Search \n[b] Open by index\n[c] See all packs\n[d] Packs Sold\n[e] Back to main menu\nSelect a option: ";
				char char_pack;
				
				do {
					cin >> char_pack;
					switch (char_pack)
					{
					case 'a':

						invalid = false;
						cout << "[a] Search by Location \n[b] Search by Date\n[c] Search by Date and Location\n";
						SearchPacks(NiceHolidays);
						cout << endl << "Done! Press a letter to go back to main menu: ";
						cin >> char_type;
						break;
					case 'b':
						int n;
						invalid = false;
						cout << "What do you want to see? " << endl;
						cin >> n;
						n = n - 1;
						showSelectedPack(NiceHolidays, n);
						cout << endl << "Done! Press a letter to go back to main menu: " ;
						cin >> char_type;
						break;
					case 'c':
						invalid = false;
						for (size_t i = 0; i < NiceHolidays.packages.size(); i++)
							showSelectedPack(NiceHolidays, i);
						cout << "\nWrite to go back to main menu: ";
						cin >> char_type;
						break;
					case 'd':
						invalid = false;
						PacksSold(NiceHolidays);
						cout << "\nWrite to go back to main menu: ";
						cin >> char_type;
						system("ClS");
						break;
					case 'e':
						invalid = false;
						system("CLS");
						Menu(NiceHolidays);
						break;
					default:
						cout << "Invalid Input! Try again: ";
						invalid = true;
						break;
					}
				} while (invalid);
				break;
			case 'e':
				invalid = false;
				system("CLS");
				PurchasePack(NiceHolidays);
				cout << endl << "Press a letter to go back to main menu: ";
				cin >> char_type;
				break;
			case 'f':
				invalid = false;
				system("CLS");
				TotalValue(NiceHolidays);
				cout << endl << "Done! Press a letter to go back to main menu: ";
				cin >> char_type;
				break;
			default:
				cin.clear();
				cin.ignore(100000, '\n');
				cout << "Invalid Input! Try again: ";
				invalid = true;
				break;
			break;
			}
		}while (invalid);
}


//Main Function
int main()
{ 
	string file_name;
	cout << "Write Agency File (with filename extension): ";
	cin >> file_name;
	system("CLS");
	vector<string> agency_info = ReadAgencyFile(file_name); // Read Agency Information
	Agency NiceHolidays;
	
	//Put Agency information into a struct
	DefAgency(NiceHolidays, agency_info); 

	while (true) {
		Menu(NiceHolidays);
		cin.clear();
		cin.ignore(1000, '\n');
		system("CLS");
		Save(NiceHolidays, agency_info[4], agency_info[5]);
	}
	return 0; 
}