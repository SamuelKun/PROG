#include "Agency.h"
#include <fstream>
#include <sstream>
#include <string>



Agency::Agency(string file_name)
{

	//Read Agency File
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
	else cout << "Unable to open file"; //Add later: TRY AGAIN

	this->name = agency_info[0];
	this->VATnumber = stoi(agency_info[1]);
	this->URL = agency_info[2];
	Address AgencyAddress = agency_info[3];
	this->address = AgencyAddress;

	//
	// Client Information
	//

	ifstream client_info(agency_info[4]);
	string name;
	vector<string> client_list;
	vector<Client> vector_client;

	while (getline(client_info, name))
	{
		if (name != "::::::::::") client_list.push_back(name);
		else
		{
			string name = client_list[0];
			unsigned VAT = stoi(client_list[1]);
			unsigned short household = stoi(client_list[2]);
			Address ClientAddress(client_list[3]);
			//Get Packs
			vector<string> packs_bought;
			stringstream pack_info(client_list[4]);
			string temp;
			while (getline(pack_info, temp, ';'))
			{
				//Remove leading and trailing spaces
				while (temp[0] == ' ') temp.erase(0, 1);
				while (temp[temp.size() - 1] == ' ') temp.erase(temp.size() - 1, temp.size());

				packs_bought.push_back(temp);
			}
			unsigned total_purchases = packs_bought.size();
			Client temp_client(name, VAT, household, ClientAddress, packs_bought, total_purchases);

			vector_client.push_back(temp_client);
			client_list.clear();
		}
	}

	//Add the last client
	string name = client_list[0];
	unsigned VAT = stoi(client_list[1]);
	unsigned short household = stoi(client_list[2]);
	Address ClientAddress(client_list[3]);
	//Get Packs
	vector<string> packs_bought;
	stringstream pack_info(client_list[4]);
	string temp;
	while (getline(pack_info, temp, ';'))
	{
		//Remove leading and trailing spaces
		while (temp[0] == ' ') temp.erase(0, 1);
		while (temp[temp.size() - 1] == ' ') temp.erase(temp.size() - 1, temp.size());

		packs_bought.push_back(temp);
	}
	unsigned total_purchases = packs_bought.size();
	Client temp_client(name, VAT, household, ClientAddress, packs_bought, total_purchases);

	vector_client.push_back(temp_client);
	client_list.clear();

	this->clients = vector_client;

	//
	// Packs Information
	//

	ifstream pack_info(agency_info[5]);
	vector<string> pack_list;
	vector<Packet> vector_pack;
	string lastTravelPack;

	getline(pack_info, lastTravelPack);

	while (getline(pack_info, name))
	{
		if (name != "::::::::::") pack_list.push_back(name);
		else
		{
			unsigned id = stoi(pack_list[0]);
			string locals = pack_list[1];
			Date start_date(pack_list[2]);
			Date end_date(pack_list[3]);
			double price = stoi(pack_list[4]);
			unsigned max = stoi(pack_list[5]);
			unsigned available = stoi(pack_list[6]);

			Packet temp_packet(id, locals, start_date, end_date, price, max, available);
			vector_pack.push_back(temp_packet);
			pack_list.clear();
		}
	}

	//Add the last pack
	unsigned id = stoi(pack_list[0]);
	string locals = pack_list[1];
	Date start_date(pack_list[2]);
	Date end_date(pack_list[3]);
	double price = stoi(pack_list[4]);
	unsigned max = stoi(pack_list[5]);
	unsigned available = stoi(pack_list[6]);

	Packet temp_packet(id, locals, start_date, end_date, price, max, available);
	vector_pack.push_back(temp_packet);
	pack_list.clear();

	this->packets = vector_pack;

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

/*********************************
 * Mostrar Loja
 ********************************/  

// mostra o conteudo de uma agencia
ostream& operator<<(ostream& out, const Agency & agency){

  // A IMPLEMENTATION REQUIRED 
}
