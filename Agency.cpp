#include "Agency.h"
#include <fstream>
#include <sstream>
#include <string>

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


			total_purchases = packs_bought.size();
			Client temp_client(name_client, VAT, household, ClientAddress, packs_bought, total_purchases);

			vector_client.push_back(temp_client);
			client_list.clear();
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


	total_purchases = packs_bought.size();
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

	this->packets = vector_pack;
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////// OKAY YOU ARE SAFE */
		///////////////////////////////////////////////////////////////////////////////////////////////////////// FOR NOW HAHAHA
}

  // metodos GET
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

  
  // SET Methods

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
