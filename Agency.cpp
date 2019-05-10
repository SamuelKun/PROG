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
	else cout << "Unable to open file"; //Add later: TRY AGAIN
	

	this->name = agency_info[0];
	this->VATnumber = stoi(agency_info[1]);
	this->URL = agency_info[2];
	Address AgencyAddress(agency_info[3]);
	this->address = AgencyAddress;
	

	///////////////////////////////////////////////////////////////////////////////////////////////////////// DONT TOUCH THIS FOR NOW MAGIC HAPPENS HERE
	//
	// Client Information
	//
	string name_client;
	unsigned VAT;
	unsigned short household;
	//Address ClientAddress(client_list[3]);
	vector<string> packs_bought;
	unsigned total_purchases;
	//
	//
	//


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

	this->clients = vector_client;

	
	///////////////////////////////////////////////////////////////////////////////////////////////////////// AND HERE TOO
	
	//
	// Packs Information
	//
	unsigned id;
	string locals;
	//Date start_date(pack_list[2]);
	//Date end_date(pack_list[3]);
	double price;
	unsigned max;
	unsigned available;
	//
	//

	ifstream pack_info(agency_info[5]);
	vector<string> pack_list;
	vector<Packet> vector_pack;
	string name_pack;
	string lastTravelPack;

	getline(pack_info, lastTravelPack);
	
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

	this->packets = vector_pack;
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////// OKAY YOU ARE SAFE */
		///////////////////////////////////////////////////////////////////////////////////////////////////////// FOR NOW HAHAHA
}

/*********************************
 * GET Methods
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
 * SET Methods
 ********************************/

void Agency::setName(string name){

	this->name = name;
}

void Agency::setVATnumber(unsigned VATnumber){

	this->VATnumber = VATnumber;
}

void Agency::setAddress(Address address){

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
 * MANAGE CLIENTS methods
 ********************************/

 void Agency::addClient()
 {
	 string client_name; // name of the client
	 unsigned client_VATnumber; // VAT number of client
	 unsigned short client_familySize;  // number of family members
	 //Address client_address(); 
	 // Client Address
	 string client_street;
	 unsigned short client_doorNumber;
	 string client_floor;
	 string client_postalCode;
	 string client_location;

	 cin.ignore(1000, '\n');
	 cout << "Name: " << endl;
	 getline(cin, client_name);
	 cout << "NIF: " << endl;
	 cin >> client_VATnumber;
	 while (cin.fail())
	 {
		 cin.clear();
		 cin.ignore();
		 cout << "Not a valid number. Please reenter: ";
		 cin >> client_VATnumber;
	 }
	 cout << "Size of household: " << endl;
	 cin >> client_familySize;
	 cin.ignore(1000, '\n');
	 cout << "Adress:" << endl;
	 cout << "	Street: ";
	 getline(cin, client_street);
	 cout << "	Door: ";
	 cin >> client_doorNumber;
	 cout << "	Floor: ";
	 cin.ignore(1000, '\n');
	 getline(cin, client_floor);
	 cout << "	Postal Code: ";
	 getline(cin, client_postalCode);
	 cout << "	Locality: ";
	 getline(cin, client_location);

	 Address client_address(client_street, client_doorNumber, client_floor, client_postalCode, client_location);
	 Client newclient(client_name, client_VATnumber, client_familySize, client_address);
	 
	 this->clients.push_back(newclient);
 }

 void Agency::changeClient(int position)
 {
	 string client_name; // name of the client
	 unsigned client_VATnumber; // VAT number of client
	 unsigned short client_familySize;  // number of family members
	 //Address client_address(); 
	 // Client Address
	 string client_street;
	 unsigned short client_doorNumber;
	 string client_floor;
	 string client_postalCode;
	 string client_location;
	 string client_packs;

	 cout << "Name: " << endl;
	 getline(cin, client_name);
	 cout << "NIF: " << endl;
	 cin >> client_VATnumber;
	 cout << "Size of household: " << endl;
	 cin >> client_familySize;
	 cin.ignore(1000, '\n');
	 cout << "Adress:" << endl;
	 cout << "	Street: ";
	 getline(cin, client_street);
	 cout << "	Door: ";
	 cin >> client_doorNumber;
	 cout << "	Floor: ";
	 cin.ignore(1000, '\n');
	 getline(cin, client_floor);
	 cout << "	Postal Code: ";
	 getline(cin, client_postalCode);
	 cout << "	Locality: ";
	 getline(cin, client_location);

	 Address client_address(client_street, client_doorNumber, client_floor, client_postalCode, client_location);
	 clients[position].setName(client_name);
	 clients[position].setVATnumber(client_VATnumber);
	 clients[position].setFamilySize(client_familySize);
	 clients[position].setAddress(client_address);
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
	 clients.erase(clients.begin() + position);
 }

 /*********************************
* MANAGE PACKS methods
********************************/
 void Agency::addPack()
 {
	 short pack_id; // packet unique identifier
	 string pack_places; // touristic sites to visit
	 string begin_date;  // begin date
	 string end_date;  // end date
	 double pack_pricePerPerson; // price per person
	 unsigned pack_maxTickets; // máximo de lugares disponíveis
	 unsigned pack_availableTickets; // número de lugares já reservados

	 cout << "Identifier: " << endl;
	 cin >> pack_id;
	 cout << "Locals: " << endl;
	 cin.ignore(1000, '\n');
	 getline(cin, pack_places);
	 cout << "Start Date: (Year/Month/Day)" << endl;
	 getline(cin, begin_date);
	 cout << "End Date: (Year/Month/Day)" << endl;
	 getline(cin, end_date);
	 cout << "Price: " << endl;
	 cin >> pack_pricePerPerson;
	 cout << "Capacity: " << endl;
	 cin >> pack_maxTickets;
	 cout << "Sold Tickets: " << endl;
	 cin >> pack_availableTickets;
	
	 Date pack_begin(begin_date);
	 Date pack_end(end_date);
	 
	 Packet newPack(pack_id, pack_places, pack_begin, pack_end, pack_pricePerPerson, pack_maxTickets, pack_availableTickets);

	 this->packets.push_back(newPack);
 }

 void Agency::changePack(int position)
 {
	 short pack_id; // packet unique identifier
	 string pack_places; // touristic sites to visit
	 string begin_date;  // begin date
	 string end_date;  // end date
	 double pack_pricePerPerson; // price per person
	 unsigned pack_maxTickets; // máximo de lugares disponíveis
	 unsigned pack_availableTickets; // número de lugares já reservados

	 cout << "Identifier: " << endl;
	 cin >> pack_id;
	 cout << "Locals: " << endl;
	 cin.ignore(1000, '\n');
	 getline(cin, pack_places);
	 cout << "Start Date: (Year/Month/Day)" << endl;
	 getline(cin, begin_date);
	 cout << "End Date: (Year/Month/Day)" << endl;
	 getline(cin, end_date);
	 cout << "Price: " << endl;
	 cin >> pack_pricePerPerson;
	 cout << "Capacity: " << endl;
	 cin >> pack_maxTickets;
	 cout << "Places already reserved: : " << endl;
	 cin >> pack_availableTickets;

	 Date pack_begin(begin_date);
	 Date pack_end(end_date);

	 packets[position].setId(pack_id);
	 packets[position].setPlaces(pack_places);
	 packets[position].setBeginDate(pack_begin);
	 packets[position].setEndDate(pack_end);
	 packets[position].setPricePerPerson(pack_pricePerPerson);
	 packets[position].setMaxTickets(pack_maxTickets);
	 packets[position].setAvailableTickets(pack_availableTickets);
 }

 void Agency::removePack(int position)
 {
	 int newId = -packets[position].getId();
	 this->packets[position].setId(newId);
 }


 /*******************************
* SHOW ALL methods
********************************/
 void Agency::showAllClientsName() const
 {
	 for (size_t i = 0; i < getClients().size(); i++)
		 cout << i << " - " << getClients()[i].getName() << endl;
 }

 void Agency::showAllPacksID() const
 {
	 cout << "Packs: " << endl;
	 for (size_t i = 0; i < getPackets().size(); i++)
	 {
		 cout << i << " - " << getPackets()[i].getId() << endl;
	 }
 }

 void Agency::showAllClients() const
 {
	 for (size_t i = 0; i < getClients().size(); i++)
	 {
		 cout << endl;
		 cout << "Name: " << getClients()[i].getName() << endl;
		 cout << "NIF: "  << getClients()[i].getVATnumber() << endl;
		 cout << "FamilySize: " << getClients()[i].getFamilySize() << endl;
		 cout << "Address: " << endl;
		 cout << "     Street: " << getClients()[i].getAddress().getStreet() << endl;
		 cout << "     Door Number: " << getClients()[i].getAddress().getDoorNumber() << endl;
		 cout << "     Floor: " << getClients()[i].getAddress().getFloor() << endl;
		 cout << "     Postal Code: " << getClients()[i].getAddress().getPostalCode() << endl;
		 cout << "     Location: " << getClients()[i].getAddress().getLocation() << endl;
		 cout << "Pack List: ";
		 for (size_t j = 0; j < getClients()[i].getPacketList().size(); j++)
		 {
			 cout << getClients()[i].getPacketList()[j];
			 if (j != getClients()[i].getPacketList().size()-1)
				 cout << " , ";
		 }
		 cout << endl;
		 cout << "Total Purchases: " << getClients()[i].getTotalPurchased() << endl;
	 }
 }

 void Agency::showAllPackets() const
 {
	 for (size_t i = 0; i < packets.size(); i++)
	 {
		 cout << endl;
		 cout << "Identifier: " << packets[i].getId() << endl;
		 cout << "Places: ";
		 packets[i].showPlaces();
		 cout << endl << "Departure Date: "; 
		 packets[i].getBeginDate().showDate(); 
		 cout << "Arrival Date: "; 
		 packets[i].getEndDate().showDate(); 
		 cout << "Price per Person: " << packets[i].getPricePerPerson() << endl;
		 cout << "Capacity: " << packets[i].getMaxTickets() << endl;
		 cout << "Places already reserved: " << packets[i].getAvailableTickets() << endl;
	 }
 }

 /*********************************
* SHOW SPECIFIC methods
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
				 cout << endl;
				 cout << "Identifier: " << packets[i].getId() << endl;
				 cout << "Places: ";
				 packets[i].showPlaces();
				 cout << endl << "Departure Date: ";
				 packets[i].getBeginDate().showDate();
				 cout << "Arrival Date: ";
				 packets[i].getEndDate().showDate();
				 cout << "Price per Person: " << packets[i].getPricePerPerson() << endl;
				 cout << "Capacity: " << packets[i].getMaxTickets() << endl;
				 cout << "Places already reserved: " << packets[i].getAvailableTickets() << endl;
			 }
	 }
 }

 void Agency::showDatePacks() const
 {
	 string start, end;

	 cin.ignore(1000, '\n');
	 cout << "Choose the date interval you desire: " << endl;
	 cout << "Choose the beginning date: ";
	 getline(cin, start);
	 cout << "Choose the ending date: ";
	 getline(cin, end);

	 for (size_t i = 0; i < packets.size(); i++)
	 {
		 if ((packets[i].getBeginDate().isEqualTo(start) || packets[i].getBeginDate().isAfter(start)) && (packets[i].getEndDate().isEqualTo(end) || packets[i].getEndDate().isBefore(end)))
		 {
			 cout << endl;
				 cout << "Identifier: " << packets[i].getId() << endl;
				 cout << "Places: ";
				 packets[i].showPlaces();
				 cout << endl << "Departure Date: ";
				 packets[i].getBeginDate().showDate();
				 cout << "Arrival Date: ";
				 packets[i].getEndDate().showDate();
				 cout << "Price per Person: " << packets[i].getPricePerPerson() << endl;
				 cout << "Capacity: " << packets[i].getMaxTickets() << endl;
				 cout << "Places already reserved: " << packets[i].getAvailableTickets() << endl;
		 }
	 }
 }

 void Agency::showDestinyAndDatePacks() const
 {
	 string start, end, destiny;

	 cin.ignore(1000, '\n');
	 cout << "Choose the destiny you desire: ";
	 getline(cin, destiny);
	 cout << "Choose the date interval you desire: " << endl;
	 cout << "Choose the beginning date: ";
	 getline(cin, start);
	 cout << "Choose the ending date: ";
	 getline(cin, end);

	 for (size_t i = 0; i < packets.size(); i++)
	 {
			 if (((packets[i].getBeginDate().isEqualTo(start) || packets[i].getBeginDate().isAfter(start)) && (packets[i].getEndDate().isEqualTo(end) || packets[i].getEndDate().isBefore(end))) && packets[i].getPlaces().find(destiny) != -1)
			 {
				 cout << endl;
				 cout << "Identifier: " << packets[i].getId() << endl;
				 cout << "Places: ";
				 packets[i].showPlaces();
				 cout << endl << "Departure Date: ";
				 packets[i].getBeginDate().showDate();
				 cout << "Arrival Date: ";
				 packets[i].getEndDate().showDate();
				 cout << "Price per Person: " << packets[i].getPricePerPerson() << endl;
				 cout << "Capacity: " << packets[i].getMaxTickets() << endl;
				 cout << "Places already reserved: " << packets[i].getAvailableTickets() << endl;
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
						 cout << endl;
						 cout << "Identifier: " << packets[k].getId() << endl;
						 cout << "Places: ";
						 packets[k].showPlaces();
						 cout << endl << "Departure Date: ";
						 packets[k].getBeginDate().showDate();
						 cout << "Arrival Date: ";
						 packets[k].getEndDate().showDate();
						 cout << "Price per Person: " << packets[k].getPricePerPerson() << endl;
						 cout << "Capacity: " << packets[k].getMaxTickets() << endl;
						 cout << "Places already reserved: " << packets[k].getAvailableTickets() << endl;
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
		if (getClients()[i].getName().find(name) != -1)
		{
		cout << endl;
		cout << "Name: " << getClients()[i].getName() << endl;
		cout << "NIF: " << getClients()[i].getVATnumber() << endl;
		cout << "FamilySize: " << getClients()[i].getFamilySize() << endl;
		cout << "Address: " << endl;
		cout << "     Street: " << getClients()[i].getAddress().getStreet() << endl;
		cout << "     Door Number: " << getClients()[i].getAddress().getDoorNumber() << endl;
		cout << "     Floor: " << getClients()[i].getAddress().getFloor() << endl;
		cout << "     Postal Code: " << getClients()[i].getAddress().getPostalCode() << endl;
		cout << "     Location: " << getClients()[i].getAddress().getLocation() << endl;
		cout << "Pack List: ";
		for (size_t j = 0; j < getClients()[i].getPacketList().size(); j++)
		{
			cout << getClients()[i].getPacketList()[j];
			if (j != getClients()[i].getPacketList().size() - 1) cout << " , ";
		}
		cout << endl;
		cout << "Total Purchases: " << getClients()[i].getTotalPurchased() << endl;
		}
	}
 }


 /*********************************
* AMMOUNT SOLD AND EARNED CURRENCY method
********************************/

 void Agency::ammountSold()
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


 /*********************************
* BUYING PACKS method
********************************/
 
 void Agency::buyPack()
 {
	 int  total;
	 string name, number, id;
	 vector<string> v_packs;
	 bool b_name = true , b_number = true , b_id = true;

	 cin.ignore(1000, '\n');
	 cout << "Type the client's name: ";
	 getline(cin, name);
	 for (size_t i = 0; i < getClients().size(); i++)
		 if (getClients()[i].getName() == name) b_name = false;

	 while (b_name)
	 {
		 cout << "Incorrect name" << endl;
		 cout << "Type the client's name: ";
		 getline(cin, name);
		 for (size_t i = 0; i < getClients().size(); i++)
			 if (getClients()[i].getName() == name) b_name = false;
	 }

	 cout << "Type the client's VAT number: ";
	 getline(cin, number);

	 for (size_t i = 0; i < getClients().size(); i++)
		 if (getClients()[i].getName() == name)
			 if (getClients()[i].getVATnumber() == stoi(number))
				 b_number = false;

	 while (b_number)
	 {
		 cout << "Incorrect VAT number" << endl;
		 cout << "Type the client's vat number: ";
		 getline(cin, number);
		 for (size_t i = 0; i < getClients().size(); i++)
			 if (getClients()[i].getName() == name)
				 if (getClients()[i].getVATnumber() == stoi(number))
					 b_number = false;
	 }


	 cout << "\nThis are all the packs available " << endl;

	 showAllPackets();

	 cout << endl << "Select the identifier of the pack you wish to purchase: ";
	 getline(cin, id);

	 while (b_id)
	 {
		 cout << "Incorrect identifier" << endl;
		 cout << "Select the identifier of the pack you wish to purchase (type 0 to leave) : ";
		 getline(cin, id);
		 for (size_t i = 0; i < getPackets().size(); i++)
			 if (getPackets()[i].getId() == stoi(id) || stoi(id) == 0 )
				 b_id = false;
	 }

	 for (size_t i = 0; i < getPackets().size(); i++)
	 {
		 if (getPackets()[i].getId() == stoi(id))
		 {
			 for (size_t j = 0; j < getClients().size(); j++)
			 {
				 if (getClients()[j].getName() == name && getClients()[j].getVATnumber() == stoi(number))
				 {
					 for (size_t k = 0; k < getClients()[j].getPacketList().size(); k++)
					 {
						 v_packs.push_back(getClients()[j].getPacketList()[k]);
					 }
					 v_packs.push_back(id);
					 clients[j].setPacketList(v_packs);
					 total = getClients()[j].getTotalPurchased() + getClients()[j].getFamilySize() * getPackets()[i].getPricePerPerson();
					 clients[j].setTotalPurchased(total);
				 }
			 }
		 }	 
	 } 
 }

 /*********************************
* N MOST VISITED method
********************************/

void Agency::mostVisited(int n)
 {
	 map <string, int> m;
	 vector <int> v;
	 vector <string> places;
	 int result = 1;
	 int counter = 0;

	 cout << endl;

	 
	 for (size_t i = 0; i < getPackets().size(); i++)
	 {
		 
		if (m.find(getPackets()[i].getPlaces()) != m.end())
		{
			m[getPackets()[i].getPlaces()] = m[getPackets()[i].getPlaces()] + getPackets()[i].getAvailableTickets();
		}
		else
		{
			m.insert(pair<string, int>(getPackets()[i].getPlaces(), getPackets()[i].getAvailableTickets()));
		}
		 
	 }

	 for (auto p : m)
	 {
		 v.push_back(p.second);
	 }
	 sort(v.begin(), v.end(), greater<int>());
	 v.erase(unique(v.begin(), v.end()), v.end());

	 for (size_t i = 0; i < v.size(); i++)
	 {
		 for (auto p2 : m)
		 {
			 if (v[i] == p2.second)
			 {
				 places.push_back(p2.first);
				 counter++;
			 }
			 if (counter == n) break;
		 }
		 if (counter == n) break;
	 }

	 for (size_t i = 0; i < places.size(); i++)
	 {
		 cout << places[i] << endl << endl;
	 }
 }


