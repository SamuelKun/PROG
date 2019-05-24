#include <string>
#include<vector>

using namespace std;

struct Date{
	int year, month, day;
};

struct Address {
	string Street, Door, Floor, Postal_Code, Locality;
};

struct Client {
	string name;
	string nif;
	string household;
	Address address;
	vector<string> packs_bought;
	int total_purchases;
};

struct TravelPack {
	string identifier;
	string locals;
	Date start_date;
	Date end_date;
	string capacity;
	int price, sold;
};

struct Agency {
	string name, url;
	int NIF;
	Address address;
	string lastTravelPack;
	vector<Client> clients;
	vector<TravelPack> packages;
};
