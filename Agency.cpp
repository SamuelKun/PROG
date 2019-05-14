#include "Agency.h"

#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

Agency::Agency(string file_name)
{
	
	//Read Agency File
	ifstream info(file_name);
	vector<string> agency_info;
	string name_temp;
	if (info.is_open())
	{
		while (getline(info, name_temp))
		{
			agency_info.push_back(name_temp);
		}
		info.close();
	}
	else cout << "Unable to open file"; 
	
	//Add name, VATnumver, URL and address to agency
	this->name = agency_info[0];
	this->VATnumber = stoi(agency_info[1]);
	this->URL = agency_info[2];
	Address AgencyAddress(agency_info[3]);
	this->address = AgencyAddress;
	
	//Get the name of file with clients and packs info
	this->clientsFile = agency_info[4];
	this->packsFile = agency_info[5];


	//
	// Client Information
	//
	string name_client;
	unsigned VAT;
	unsigned short household;
	vector<string> packs_bought;
	unsigned total_purchases;


	ifstream client_info(agency_info[4]);
	vector<string> client_list;
	vector<Client> vector_client;

	while (getline(client_info, name_client))
	{
		if (name_client != "::::::::::") client_list.push_back(name_client);
		else
		{
			name_client = client_list[0];
			VAT = stoi(client_list[1]);
			household = stoi(client_list[2]);
			Address ClientAddress(client_list[3]);

			//Get Packs
			stringstream pack_info(client_list[4]);
			string temp;
			while (getline(pack_info, temp, ';'))
			{
				//Remove leading and trailing spaces
				while (temp[0] == ' ') temp.erase(0, 1);
				while (temp[temp.size() - 1] == ' ') temp.erase(temp.size() - 1, temp.size());

				packs_bought.push_back(temp);
			}


			total_purchases = stoi(client_list[5]);
			Client temp_client(name_client, VAT, household, ClientAddress, packs_bought, total_purchases);

			vector_client.push_back(temp_client);
			client_list.clear();
			packs_bought.clear();
		}
	}
	
	//Add the last client
	name_client = client_list[0];
	VAT = stoi(client_list[1]);
	household = stoi(client_list[2]);
	Address ClientAddress(client_list[3]);

	//Get Packs
	stringstream getpackla(client_list[4]);
	string temp;
	while (getline(getpackla, temp, ';'))
	{
		//Remove leading and trailing spaces
		while (temp[0] == ' ') temp.erase(0, 1);
		while (temp[temp.size() - 1] == ' ') temp.erase(temp.size() - 1, temp.size());

		packs_bought.push_back(temp);
	}

	total_purchases = total_purchases = stoi(client_list[5]);
	Client temp_client(name_client, VAT, household, ClientAddress, packs_bought, total_purchases);

	vector_client.push_back(temp_client);
	client_list.clear();

	//Add clients
	this->clients = vector_client;

	
	//
	// Packs Information
	//
	unsigned id;
	string locals;
	double price;
	unsigned max;
	unsigned available;

	ifstream pack_info(agency_info[5]);
	vector<string> pack_list;
	vector<Packet> vector_pack;
	string name_pack;
	string lastTravelPack;

	getline(pack_info, lastTravelPack);

	this->lastId = stoi(lastTravelPack); //Get the last Pack added -> First line of packs file
	
	while (getline(pack_info, name_pack))
	{
		if (name_pack != "::::::::::") pack_list.push_back(name_pack);
		else
		{
			id = stoi(pack_list[0]);
			locals = pack_list[1];
			Date start_date(pack_list[2]);
			Date end_date(pack_list[3]);
			price = stoi(pack_list[4]);
			max = stoi(pack_list[5]);
			available = stoi(pack_list[6]);

			Packet temp_packet(id, locals, start_date, end_date, price, max, available);
			vector_pack.push_back(temp_packet);
			pack_list.clear();
		}
	}

	//Add last pack
	id = stoi(pack_list[0]);
	locals = pack_list[1];
	Date start_date(pack_list[2]);
	Date end_date(pack_list[3]);
	price = stoi(pack_list[4]);
	max = stoi(pack_list[5]);
	available = stoi(pack_list[6]);

	Packet temp_packet(id, locals, start_date, end_date, price, max, available);
	vector_pack.push_back(temp_packet);
	pack_list.clear();

	//Add packets do Agency
	this->packets = vector_pack;
}

/*********************************
 * GET Methods					 *
 ********************************/
string Agency::getName() const
{
	return name;
}

unsigned Agency::getVATnumber() const
{
	return VATnumber;
}

Address Agency::getAddress() const
{
	return address;
}

string Agency::getURL() const
{
	return URL;
}

vector<Client> Agency::getClients() const
{
	return clients;
}

vector<Packet> Agency::getPackets() const{

	return packets;
}

/*********************************
 * SET Methods                   *
 ********************************/

void Agency::setName(string name)
{
	this->name = name;
}

void Agency::setVATnumber(unsigned VATnumber)
{
	this->VATnumber = VATnumber;
}

void Agency::setAddress(Address address)
{
	this->address= address;
}

 void Agency::setURL(string url)
{
	 this->URL = url;
}

 void Agency::setClients(vector<Client> & clients)
 {
	 this->clients = clients;
 }

 void Agency::setPackets(vector<Packet> & packets)
 {
	 this->packets = packets;
 }

 /*********************************
 * MANAGE CLIENTS methods         *
 **********************************/

 void Agency::addClient()
 {
	 string client_name; // name of the client
	 unsigned client_VATnumber; // VAT number of client
	 unsigned short client_familySize;  // number of family members
	 string client_street;
	 unsigned short client_doorNumber;
	 string client_floor;
	 string client_postalCode;
	 string client_location;
	 char confirm;

	 cin.ignore(1000, '\n');
	 cout << "Name: " << endl;
	 getline(cin, client_name);
	 cout << "NIF: " << endl;
	 cin >> client_VATnumber;
	 while (cin.fail()) // Used to test if user write a invalid input
	 {
		 cin.clear();
		 cin.ignore();
		 cin.ignore(1000, '\n');
		 cout << "Not a valid number. Please reenter: ";
		 cin >> client_VATnumber;
	 }
	 cout << "Size of household: " << endl;
	 cin >> client_familySize;

	 while (cin.fail())
	 {
		 cin.clear();
		 cin.ignore();
		 cin.ignore(1000, '\n');
		 cout << "Not a valid number. Please reenter: ";
		 cin >> client_familySize;
	 }
	 cin.ignore(1000, '\n');
	 cout << "Adress:" << endl;
	 cout << "	Street: ";
	 getline(cin, client_street);

	 cout << "	Door: ";
	 cin >> client_doorNumber;
	 while (cin.fail())
	 {
		 cin.clear();
		 cin.ignore();
		 cin.ignore(1000, '\n');
		 cout << "Not a valid number. Please reenter: ";
		 cin >> client_doorNumber;
	 }

	 cout << "	Floor: ";
	 cin.ignore(1000, '\n');
	 getline(cin, client_floor);

	 cout << "	Postal Code: ";
	 getline(cin, client_postalCode);

	 cout << "	Locality: ";
	 getline(cin, client_location);

	 cout << endl << "Are you sure about adding " << client_name << "? [Y/N] " << endl;

	 do {
		 cin.clear();
		 cin >> confirm;
		 confirm = tolower(confirm);
	 } while (!(confirm == 'y' || confirm == 'n'));

	 system("CLS");

	 if (confirm == 'y')
	 {
		 Address client_address(client_street, client_doorNumber, client_floor, client_postalCode, client_location);
		 Client newclient(client_name, client_VATnumber, client_familySize, client_address);
		 this->clients.push_back(newclient);
		 cout << "Done! ";
	 }
	 else if(confirm == 'n')
		 cout << "Canceled! ";

 }

 void Agency::changeClient(int position)
 {
	 string client_name; // name of the client
	 unsigned client_VATnumber; // VAT number of client
	 unsigned short client_familySize;  // number of family members
	 string client_street;
	 unsigned short client_doorNumber;
	 string client_floor;
	 string client_postalCode;
	 string client_location;
	 string client_packs;
	 char confirm;

	 cout << "Name: " << endl;
	 getline(cin, client_name);

	 cout << "NIF: " << endl;
	 cin >> client_VATnumber;
	 while (cin.fail())
	 {
		 cin.clear();
		 cin.ignore();
		 cin.ignore(1000, '\n');
		 cout << "Not a valid number. Please reenter: ";
		 cin >> client_VATnumber;
	 }

	 cout << "Size of household: " << endl;
	 cin >> client_familySize;
	 while (cin.fail())
	 {
		 cin.clear();
		 cin.ignore();
		 cin.ignore(1000, '\n');
		 cout << "Not a valid number. Please reenter: ";
		 cin >> client_familySize;
	 }

	 cin.ignore(1000, '\n');
	 cout << "Adress:" << endl;
	 cout << "	Street: ";
	 getline(cin, client_street);

	 cout << "	Door: ";
	 cin >> client_doorNumber;
	 while (cin.fail())
	 {
		 cin.clear();
		 cin.ignore();
		 cin.ignore(1000, '\n');
		 cout << "Not a valid number. Please reenter: ";
		 cin >> client_doorNumber;
	 }

	 cout << "	Floor: ";
	 cin.ignore(1000, '\n');
	 getline(cin, client_floor);

	 cout << "	Postal Code: ";
	 getline(cin, client_postalCode);

	 cout << "	Locality: ";
	 getline(cin, client_location);

	 cout << endl << "Are you sure about adding " << client_name << "? [Y/N] " << endl;

	 do {
		 cin.clear();
		 cin >> confirm;
		 confirm = tolower(confirm);
	 } while (!(confirm == 'y' || confirm == 'n'));

	 system("CLS");

	 if (confirm == 'y')
	 {
		 Address client_address(client_street, client_doorNumber, client_floor, client_postalCode, client_location);
		 clients[position].setName(client_name);
		 clients[position].setVATnumber(client_VATnumber);
		 clients[position].setFamilySize(client_familySize);
		 clients[position].setAddress(client_address);
		 cout << "Done! ";
	 }
	 else if (confirm == 'n')
		 cout << "Canceled! ";

	 //PERGUNTAR AO STOR SOBRE ISTO
	 /*vector<string> all_client_packs = clients[position].getPacketList();

	 cout << "New Packs: "; //DO LOOP HERE!!!
	 cin >> client_packs;

	 all_client_packs.push_back(client_packs);
	 clients[position].setPacketList(all_client_packs);

	 //unsigned total_purchase;
	 //	PERGUNTAR AO STOR
	 clients[position].setTotalPurchased(0);*/
 }

 void Agency::removeClient(int position)
 {
	 char confirm;
	 cout << endl << "Are you sure about adding " << getClients()[position].getName() << "? [Y/N] " << endl;

	 do {
		 cin.clear();
		 cin >> confirm;
		 confirm = tolower(confirm);
	 } while (!(confirm == 'y' || confirm == 'n'));

	 system("CLS");

	 if (confirm == 'y')
	 {
		 clients.erase(clients.begin() + position);
		 cout << "Done! ";
	 }
	 else if (confirm == 'n')
		 cout << "Canceled! ";
 }

 /*******************************
* MANAGE PACKS methods          *
********************************/
 void Agency::addPack()
 {
	 short pack_id; // packet unique identifier
	 string pack_places; // touristic sites to visit
	 double pack_pricePerPerson; // price per person
	 unsigned pack_maxTickets; // máximo de lugares disponíveis
	 unsigned pack_availableTickets; // número de lugares já reservados
	 char confirm; // verificador [Y/N]

	 cout << "Identifier: " << endl;
	 cin >> pack_id;

	 this->lastId = pack_id;

	 while (cin.fail())
	 {
		 cin.clear();
		 cin.ignore();
		 cin.ignore(1000, '\n');
		 cout << "Not a valid number. Please reenter: ";
		 cin >> pack_id;
	 }

	 cout << "Locals: " << endl;
	 cin.ignore(1000, '\n');
	 getline(cin, pack_places);

	 cout << "Start Date: " << endl;
	 Date start_date;
	 start_date.manualDate();

	 cout << "End Date:" << endl;
	 Date end_date;
	 end_date.manualDate();

	 cout << "Price: " << endl;
	 cin >> pack_pricePerPerson;
	 while (cin.fail())
	 {
		 cin.clear();
		 cin.ignore();
		 cin.ignore(1000, '\n');
		 cout << "Not a valid number. Please reenter: ";
		 cin >> pack_pricePerPerson;
	 }

	 cout << "Capacity: " << endl;
	 cin >> pack_maxTickets;
	 while (cin.fail())
	 {
		 cin.clear();
		 cin.ignore();
		 cin.ignore(1000, '\n');
		 cout << "Not a valid number. Please reenter: ";
		 cin >> pack_maxTickets;
	 }

	 cout << "Sold Tickets: " << endl;
	 cin >> pack_availableTickets;
	 while (cin.fail())
	 {
		 cin.clear();
		 cin.ignore();
		 cin.ignore(1000, '\n');
		 cout << "Not a valid number. Please reenter: ";
		 cin >> pack_availableTickets;
	 }

	 cout << endl << "Are you sure about adding the pack with identifier " << pack_id << "? [Y/N] " << endl;

	 do {
		 cin.clear();
		 cin >> confirm;
		 confirm = tolower(confirm);
	 } while (!(confirm == 'y' || confirm == 'n'));

	 system("CLS");

	 if (confirm == 'y')
	 {
		 Packet newPack(pack_id, pack_places, start_date, end_date, pack_pricePerPerson, pack_maxTickets, pack_availableTickets);
		 this->packets.push_back(newPack);
		 cout << "Done! ";
	 }
	 else if (confirm == 'n')
		 cout << "Canceled! ";
 }

 void Agency::changePack(int position)
 {
	 short pack_id; // packet unique identifier
	 string pack_places;
	 double pack_pricePerPerson; // price per person
	 unsigned pack_maxTickets; // máximo de lugares disponíveis
	 unsigned pack_availableTickets; // número de lugares já reservados
	 char confirm; // verifier [Y/N]

	 cout << "Identifier: " << endl;
	 cin >> pack_id;

	 cout << "Locals: " << endl;
	 cin.ignore(1000, '\n');
	 getline(cin, pack_places);

	 cout << "Start Date: " << endl;
	 Date start_date;
	 start_date.manualDate();

	 cout << "End Date:" << endl;
	 Date end_date;
	 end_date.manualDate();

	 cout << "Price: " << endl;
	 cin >> pack_pricePerPerson;
	 while (cin.fail())
	 {
		 cin.clear();
		 cin.ignore();
		 cin.ignore(1000, '\n');
		 cout << "Not a valid number. Please reenter: ";
		 cin >> pack_pricePerPerson;
	 }

	 cout << "Capacity: " << endl;
	 cin >> pack_maxTickets;
	 while (cin.fail())
	 {
		 cin.clear();
		 cin.ignore();
		 cin.ignore(1000, '\n');
		 cout << "Not a valid number. Please reenter: ";
		 cin >> pack_maxTickets;
	 }

	 cout << "Places already reserved: : " << endl;
	 cin >> pack_availableTickets;
	 while (cin.fail())
	 {
		 cin.clear();
		 cin.ignore();
		 cin.ignore(1000, '\n');
		 cout << "Not a valid number. Please reenter: ";
		 cin >> pack_availableTickets;
	 }
	 cout << endl << "Are you sure about changing the pack with identifier " << pack_id << "? [Y/N] " << endl;

	 do {
		 cin.clear();
		 cin >> confirm;
		 confirm = tolower(confirm);
	 } while (!(confirm == 'y' || confirm == 'n'));

	 system("CLS");

	 if (confirm == 'y')
	 {
		 packets[position].setId(pack_id);
		 packets[position].setPlaces(pack_places);
		 packets[position].setBeginDate(start_date);
		 packets[position].setEndDate(end_date);
		 packets[position].setPricePerPerson(pack_pricePerPerson);
		 packets[position].setMaxTickets(pack_maxTickets);
		 packets[position].setAvailableTickets(pack_availableTickets);
		 cout << "Done! ";
	 }
	 else if (confirm == 'n')
		 cout << "Canceled! ";

 }

 void Agency::removePack(int position)
 {
	 char confirm;
	 cout << endl << "Are you sure about removing the pack with identifier " << getPackets()[position].getId() << "? [Y/N] " << endl;

	 do {
		 cin.clear();
		 cin >> confirm;
		 confirm = tolower(confirm);
	 } while (!(confirm == 'y' || confirm == 'n'));

	 system("CLS");

	 if (confirm == 'y')
	 {
		 int newId = -packets[position].getId();
		 this->packets[position].setId(newId);
		 cout << "Done! ";
	 }
	 else if (confirm == 'n')
		 cout << "Canceled! ";

 }


 /*******************************
* SHOW ALL CLIENTS AND PACKS    *
********************************/
 void Agency::showAllClientsName() const
 {
	 for (size_t i = 0; i < getClients().size(); i++)
		 cout << "Order Number " <<i << " - " << getClients()[i].getName() << endl;
 }

 void Agency::showAllPacksID() const
 {
	 cout << "Packs: " << endl;
	 for (size_t i = 0; i < getPackets().size(); i++)
	 {
		 cout << "Order Number " << i << " - " << getPackets()[i].getId() << endl;
	 }
 }

 void Agency::showAllClients() const
 {
	 cout << "Clients: " << endl;
	 for (size_t i = 0; i < clients.size(); i++)
	 {
		 cout << clients[i];
	 }
	 cout << endl;
 }

 void Agency::showAllPackets() const
 {
	 cout << "All Packs: " << endl;
	 for (size_t i = 0; i < packets.size(); i++)
	 {
		 cout << packets[i];
	 }
	 cout << endl;
 }

 /*******************************
* SEARCH SPECIFIC PACKS methods *
********************************/

 void Agency::showDestinyPacks() const
 {
	 string destiny;

	 cin.ignore(1000, '\n');
	 cout << "Choose the destiny you desire: ";
	 getline(cin, destiny);

	 for (size_t i = 0; i < packets.size(); i++)
	 {
			 if (packets[i].getPlaces().find(destiny) != -1)
			 {
				 cout << packets[i];
			 }

	 }
 }

 void Agency::showDatePacks() const
 {

	 cin.ignore(1000, '\n');
	 cout << "Choose the date interval you desire: " << endl;
	 cout << "Choose the start date: " << endl;
	 Date start;
	 start.manualDate();
	 cout << "Choose the end date: " << endl;
	 Date end;
	 end.manualDate();
	 for (size_t i = 0; i < packets.size(); i++)
	 {
		 if ((packets[i].getBeginDate().isEqualTo(start) || packets[i].getBeginDate().isAfter(start)) && (packets[i].getEndDate().isEqualTo(end) || packets[i].getEndDate().isBefore(end)))
		 {
			 cout << packets[i];
		 }
	 }
 }

 void Agency::showDestinyAndDatePacks() const
 {
	 string destiny;

	 cin.ignore(1000, '\n');
	 cout << "Choose the destiny you desire: ";
	 getline(cin, destiny);
	 cout << "Choose the date interval you desire: " << endl;
	 cout << "Choose the start date: " << endl;
	 Date start;
	 start.manualDate();
	 cout << "Choose the end date: " << endl;
	 Date end;
	 end.manualDate();

	 for (size_t i = 0; i < packets.size(); i++)
	 {
			 if (((packets[i].getBeginDate().isEqualTo(start) || packets[i].getBeginDate().isAfter(start)) && (packets[i].getEndDate().isEqualTo(end) || packets[i].getEndDate().isBefore(end))) && packets[i].getPlaces().find(destiny) != -1)
			 {
				 cout << packets[i];
		}
	 }

 }

 void Agency::show1ClientPacks() const
 {
	 string name, number;

	 cin.ignore(1000, '\n');
	 cout << "Type the client's name: ";
	 getline(cin, name);

	 for (size_t i = 0; i < getClients().size(); i++)
	 {
		 if (clients[i].getName().find(name) != -1)
		 {
			 for (size_t j = 0; j < getClients()[i].getPacketList().size(); j++)
			 {
				 for (size_t k = 0; k < getPackets().size(); k++)
				 {
					 if (getPackets()[k].getId() == stoi(getClients()[i].getPacketList()[j]) || getPackets()[k].getId() == -stoi(getClients()[i].getPacketList()[j]))
					 {
						 cout << packets[k];
						
					 }
				 }
			 }
		 }
	 }
 }

 void Agency::show1Client() const
 {
	string name, number;
	cin.ignore(1000, '\n');
	cout << "Type the client name: ";
	getline(cin, name);

	for (size_t i = 0; i < getClients().size(); i++)
	{
		if (clients[i].getName().find(name) != -1)
		{
			cout << clients[i];
		}
	}
 }


 /******************************************
* AMMOUNT SOLD AND EARNED CURRENCY method  *
*******************************************/

 void Agency::ammountSold() const
 {
	 int counter = 0, total = 0;

	 for (size_t i = 0; i < getClients().size(); i++)
	 {
		 for (size_t j = 0; j < getClients()[i].getPacketList().size(); j++)
		 {
			 counter = counter + getClients()[i].getFamilySize();
		 }

		 total = total + getClients()[i].getTotalPurchased();
	 }

	 cout << "There have been sold " << counter << " packs" << endl;
	 cout << "The total value of selling those " << counter << " packs is: " << total << endl;
 }


 /*******************************
* BUYING PACKS method           *
********************************/
 
 void Agency::buyPack()
 {
	 int pack_number, client_number;
	 int idx = getPackets().size();
	 int price, totalsold;
	 char confirm;
	 showAllPackets();
	 showAllPacksID();
	 cout << "What do you want to buy? Insert the order number to choice! " << endl;

	 do {
		 do {
			 cin.clear();
			 cin.ignore(10000, '\n');
			 cout << "You can't buy packages with ' - ' before! Order number: ";
			 cin >> pack_number;
		 } while (pack_number >= idx || pack_number < 0);
	 } while (getPackets()[pack_number].getId() < 0);

	 
	 cout << endl << "Are you sure about purchase the pack with identifier " << getPackets()[pack_number].getId() << "? [Y/N] " << endl;

	 do {
		 cin.clear();
		 cin >> confirm;
		 confirm = tolower(confirm);
	 } while (!(confirm == 'y' || confirm == 'n'));

	 system("CLS");
		switch (confirm)
		{
		case 'y':
			showAllClientsName();
			cout << "Are you one of the above: [Y/N]" << endl;
			do {
				 cin >> confirm;
				 confirm = tolower(confirm);
			} while (!(confirm == 'y' || confirm == 'n'));


				 switch (confirm)
				 {
				 case 'y':
					 cout << "Select your order number: ";
					 do {
						cin.clear();
						cin.ignore(10000, '\n');
						cin >> client_number;
						if(client_number >= getClients().size() || pack_number < 0) cout << "Invalid order number! Order number: ";
					} while (client_number >= getClients().size() || pack_number < 0);

					if (getPackets()[pack_number].getMaxTickets() >= getPackets()[pack_number].getAvailableTickets() + getClients()[client_number].getFamilySize())
					{
						price = getPackets()[pack_number].getPricePerPerson() * getClients()[client_number].getFamilySize();
						totalsold = getPackets()[pack_number].getAvailableTickets() + getClients()[client_number].getFamilySize();
						clients[client_number].addPacket(to_string(getPackets()[pack_number].getId()));
						clients[client_number].addTotalPurchased(price);
						packets[pack_number].setAvailableTickets(totalsold);
					 cout << "Done! ";
					}
					else
					{
						cout << "Due to your family size it is not possible to buy packages for everyone! Try to buy another package! "; 
					}

					 break;
				 case 'n':
					 cout << "You need to create an account before buy packs! Go to Manage Clients to create!" << endl;
					 break;
				 default:
					 break;
			}
			break;

		 case 'n':
			 cout << "Canceled! ";
		 default:
			 break;
		 }
 }

 /*********************************
* MOST VISITED method
********************************/

void Agency::mostVisited(int n) const
 {
	 map <string, int> locais;
	 
	 multimap<int, string, greater<int>> locais_ordered;
	 vector<int> timesvisited;
	 vector<string> visitedLocals;

	 for (size_t i = 0; i < getPackets().size(); i++)
	 {
			 if (locais.find(getPackets()[i].getPlaces()) != locais.end())
			 {
				 locais[getPackets()[i].getPlaces()] += getPackets()[i].getAvailableTickets();
			 }
			 else
			 {
				 locais.insert(pair<string, int>(getPackets()[i].getPlaces(), getPackets()[i].getAvailableTickets()));
			 }
	 }

	 for (auto change : locais)
	 {
		 locais_ordered.insert(pair<int, string>(change.second, change.first));
	 }

	 for (auto p : locais_ordered)
	 {
		 timesvisited.push_back(p.first);
		 visitedLocals.push_back(p.second);
	 }

	 cout << endl;

	 for (size_t i = 0; i < visitedLocals.size(); i++)
	 {
		 if (i < n) {
			 cout << "Position  " << i + 1 << ": " << "[Visited " << timesvisited[i] <<" times.]" << endl;
			 cout << visitedLocals[i] << endl << endl;
		 }
	 }
}

void Agency::ClientMostVisited(int n) const
{
	multimap <int, string, greater<int>> locais;
	vector<int> timesvisited;
	vector<string> visitedLocals;
	vector<string> wishlocals;

	cout << endl;

	for (size_t i = 0; i < getPackets().size(); i++)
	{
		locais.insert(pair<int, string>(getPackets()[i].getAvailableTickets(), getPackets()[i].getPlaces()));
	}

	for (auto p : locais)
	{
		timesvisited.push_back(p.first);
		visitedLocals.push_back(p.second);
	}

	for (size_t i = 0; i < visitedLocals.size(); i++)
	{
		if (i < n) {
			wishlocals.push_back(visitedLocals[i]);
		}
	}

	vector<short> idkwhatimdoing;
	for (size_t i = 0; i < wishlocals.size(); i++)
	{
		for (size_t idx = 0; idx < getPackets().size(); idx++)
		{
			if (getPackets()[idx].getPlaces() == wishlocals[i])
				idkwhatimdoing.push_back(getPackets()[idx].getId());
		}
	}

	vector<string> temp;
	bool setbool;
	for (size_t client_idx = 0; client_idx < getClients().size(); client_idx++)
	{
		cout << getClients()[client_idx].getName() << endl;
		cout << "You have not yet visited the following places that are in the most visited " << n << ": " << endl << endl;
		temp = getClients()[client_idx].getPacketList();
		

		vector<short> short_id;
		short num;
		for (size_t i = 0; i < temp.size(); i++)
		{
			num = stoi(temp[i]);
			short_id.push_back(num);
		}
		
		for (size_t i = 0; i < idkwhatimdoing.size(); i++)
		{
			setbool = true;
			for (size_t j = 0; j < short_id.size(); j++)
			{
				if (short_id[j] == idkwhatimdoing[i] || short_id[j] == -idkwhatimdoing[i])
				{
					setbool = false;
				}
			}

			if (setbool)
			{
				cout << "Position  " << i + 1 << ": " << "[Visited " << timesvisited[i] << " times.]" << endl;
				cout << "Locals: " << wishlocals[i] << endl;
				cout << "Pack id: " << idkwhatimdoing[i] << endl << endl;
			}
		}
		cout << endl;
	}

}


/*********************************
* SAVE TO FILE method
********************************/

void Agency::writeAgency() const
{
	ofstream write_clients(this->clientsFile);
	ofstream write_packs(this->packsFile);

	//Clients
	for (size_t i = 0; i < getClients().size(); i++)
	{
		write_clients << getClients()[i].getName() << endl;
		write_clients << getClients()[i].getVATnumber() << endl;
		write_clients << getClients()[i].getFamilySize() << endl;
		write_clients << getClients()[i].getAddress().getStreet() << " / " << getClients()[i].getAddress().getDoorNumber() << " / " << getClients()[i].getAddress().getFloor() << " / " << getClients()[i].getAddress().getPostalCode() << " / " << getClients()[i].getAddress().getLocation() << endl;
		for (int j = 0; j < getClients()[i].getPacketList().size(); j++)
		{
			write_clients << getClients()[i].getPacketList()[j];
			if (j != getClients()[i].getPacketList().size() - 1) write_clients << " ; ";
		}
		write_clients << endl << getClients()[i].getTotalPurchased() << endl;
		if (i != getClients().size() - 1) write_clients << "::::::::::" << endl;
	}
	
	//TravelPacks

	write_packs << this->lastId << endl; // ADD LAST PACK DO IT LATER

	for (size_t i = 0; i < getPackets().size(); i++)
	{
		write_packs << getPackets()[i].getId() << endl;
		write_packs << getPackets()[i].getPlaces() << endl;
		write_packs << getPackets()[i].getBeginDate().getYear() <<'/' << getPackets()[i].getBeginDate().getMonth() << '/' << getPackets()[i].getBeginDate().getDay() << endl;
		write_packs << getPackets()[i].getEndDate().getYear() << '/' << getPackets()[i].getEndDate().getMonth() << '/' << getPackets()[i].getEndDate().getDay() << endl;
		write_packs << getPackets()[i].getPricePerPerson() << endl;
		write_packs << getPackets()[i].getMaxTickets() << endl;
		write_packs << getPackets()[i].getAvailableTickets();
		if (i != getPackets().size() - 1) write_packs << endl << "::::::::::" << endl;
	}
}

