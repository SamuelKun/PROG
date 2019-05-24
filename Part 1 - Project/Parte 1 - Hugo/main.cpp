#include<sstream>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

//Structs a ser utilizadas

struct agency
{
	string nome, nif, url, morada, clients, packs;
};
struct clients
{
	//Struct para os daddos dos clientes
	string nome, nif, agregado, morada, pacotes_comprados, total_compras;
};
struct packs
{
	//Struct para os pacotes dos clientes
	string identificador, locais, data_inicio, data_fim, preco_pessoa, maximo_pessoas, total_comprados;
};
struct morada
{
	//Struct para a morada dos clientes
	string rua, porta, andar, codigo_postal, localidade;
};
struct date
{
	//Struct para as data dos pacotes
	string ano, mes, dia;
};

//Variáveis globais para utilizar nas funções:

vector<agency> v_agency = {};   //Vetor onde estão guardadas a agencias
vector<clients> v_clients = {}; //Vetor onde estão guardados os clientes
vector<packs> v_packs = {};     //vetor onde estão guardados os pacotes
vector<morada> v_morada = {};   //vetor onde estão guardadas as moradas
vector<date> v_date = {};       //Ainda não tem nada xD

//Funções para ler os dados dos ficheiros
vector<string> readAgency(string filename)
{
	vector<string> _agency = {};
	string line;

	ifstream fin(filename);
	while (getline(fin, line))
	{
		_agency.push_back(line);
	}
	fin.close();
	return _agency;
}
vector<string> readClients(string filename)
{
	vector<string> _clients = {};
	string line;

	ifstream fin(filename);
	while (getline(fin, line))
	{
		_clients.push_back(line);
	}
	return _clients;
	fin.close();
}
vector<string> readPacks(string filename)
{
	vector<string> _packs = {};
	string line;

	ifstream fin(filename);
	while (getline(fin, line))
	{
		_packs.push_back(line);
	}
	fin.close();
	return _packs;
}

//Verificação da existência do ficheiro
bool is_file_exist(string fileName)
{
	//Verificação da existência de umficheiro
	ifstream infile(fileName);
	return infile.good();
}

//Funções para passar os dados para vetores
void save_agency(vector <string> v)
{
	// Guardar a agencia no vetor v_agency
	agency a;
	a.nome = v[0];
	a.nif = v[1];
	a.url = v[2];
	a.morada = v[3];
	a.clients = v[4];
	a.packs = v[5];

	v_agency.push_back(a);

}
void save_clients(vector <string> v)
{
	//Guardar os clientes no vetor v_clients
	clients c;
	int counter = 0;
	for (size_t i = 0; i < v.size(); i++) if (v[i] == "::::::::::") counter++;
	for (int j = 0; j <= counter; j++)
	{
		int k = j * 6;
		c.nome = v[k];
		c.nif = v[k + 1];
		c.agregado = v[k + 2];
		c.morada = v[k + 3];
		c.pacotes_comprados = v[k + 4];
		c.total_compras = v[k + 4];

		v_clients.push_back(c);
	}
}
void save_packs(vector <string> v)
{
	//Guardar os pacotes no vetor v_packs
	packs p;
	int counter = 0;
	for (size_t i = 0; i < v.size(); i++) if (v[i] == "::::::::::") counter++;
	for (int j = 0; j <= counter; j++)
	{
		int k = 8 * j + 1;
		p.identificador = v[k];
		p.locais = v[k + 1];
		p.data_inicio = v[k + 2];
		p.data_fim = v[k + 3];
		p.preco_pessoa = v[k + 4];
		p.maximo_pessoas = v[k + 5];
		p.total_comprados = v[k + 6];

		v_packs.push_back(p);
	}
}

//Não encontrei qualquer necessidade de utilizar a struct morada durante a realização do trabalho 
//porque achei mais simples trabalhar com strings
void saveMorada(morada &m, clients c, int num)
{
	//guardar os dados na struct morada
	int j = (num - 1) * 6;
	int place = c.morada.find("/", j);
	for (int i = j; i < place; i++)
		m.rua.push_back(c.morada[i]);
	int fim = c.morada.find("/", place + 1);
	for (int i = place + 1; i < fim; i++)
		m.porta.push_back(c.morada[i]);
	place = fim;
	fim = c.morada.find("/", place + 1);

	for (int i = place + 1; i < fim; i++)
		m.andar.push_back(c.morada[i]);
	place = fim;
	fim = c.morada.find("/", place + 1);
	for (int i = place + 1; i < fim; i++)
		m.codigo_postal.push_back(c.morada[i]);
	for (int i = fim + 1; i < c.morada.size(); i++)
		m.localidade.push_back(c.morada[i]);
}

int menor_ou_igual_data(string data1, string data2)
{
	//Esta função compara entre duas datas para ver qual é a maior
	int a1, a2, m1, m2, d1, d2;
	int index1, index2;


	index1 = data1.find('/');
	a1 = stoi(data1.substr(0, index1));
	data1.erase(0, index1 + 1);


	index1 = data1.find('/');
	m1 = stoi(data1.substr(0, index1));
	data1.erase(0, index1 + 1);

	d1 = stoi(data1);

	index2 = data2.find('/');
	a2 = stoi(data2.substr(0, index2));
	data2.erase(0, index2 + 1);

	index2 = data2.find('/');
	m2 = stoi(data2.substr(0, index2));
	data2.erase(0, index2 + 1);

	d2 = stoi(data2);


	//return 1 significa data1 menor que data2
	//return 0 significa data1 maior que data2

	if (a1 < a2) return 1;       //Comparar anos
	else if (a2 < a1) return 0;
	else if (m1 < m2) return 1;  //Comparar meses
	else if (m2 < m1) return 0;
	else if (d1 < d2) return 1;  //Comparar dias
	else if (d2 < d1) return 0;
	else if (d2 == d1) return 1;
	else return 0;

}

vector<int> packs_int(string str)
{
	//Esta função transforma a string de pacotes num vetor de pacotes
	vector<int> v;
	int temp, index, num;
	int counter = 0;

	for (int i = 0; i < str.length(); i++) if (str[i] == ';') counter++;

	for (int i = 0; i <= counter; i++)
	{
		if (str.find('\n') != -1) v.push_back(num);
		else
		{
			index = str.find(';');
			num = stoi(str.substr(0, index));
			v.push_back(num);
			str.erase(0, index + 1);
		}
	}

	return v;
}

int main()
{

	string filename;                //ficheiro

	cout << "Qual o nome do ficheiro da agencia a usar? : ";
	cin >> filename;
	filename = filename + ".txt";

	save_agency(readAgency(filename));                //Guardar a agencia no vetor v_agency
	save_clients(readClients(v_agency[0].clients));   //Guardar os clientes no vetor v_clients
	save_packs(readPacks(v_agency[0].packs));         //Guardar os pacotes no vetor v_packs


	/* Código antigo (não apagar por enquanto!!)

	saveMorada(m1, c1, 1);    //Guardar a morada do primeiro cliente na struct m1
	v_morada.push_back(m1);   //Guardar a struct m1 no vetor v_morada
	saveMorada(m2, c2, 2);    //Guardar a morada do segundo cliente na struct m2
	v_morada.push_back(m2);   //Guardar a struct m2 no vetor v_morada

	*/

	// Verificação da existência do ficheiro

	if (!is_file_exist(filename) || !is_file_exist(v_agency[0].clients) || !is_file_exist(v_agency[0].packs))
	{
		cout << "ERROR";
		return 0;             // terminar o programa em casa de erro de leitura
	}

	bool test = true;

	while (test)
	{
		
		system("CLS");
		char menu_1;            //Menu Principal

		cout << "Menu Principal" << endl << endl;
		cout << "Introduza a operacao que deseja efetuar  " << endl << endl;

		cout << "[1] Gestao de clientes " << endl;
		cout << "[2] Gestao de pacotes turisticos " << endl;
		cout << "[3] Visualizacao de informacao " << endl;
		cout << "[4] Comprar pacotes " << endl;
		cout << "[0] Sair do programa " << endl << endl;

		cin >> menu_1;

		switch (menu_1)
		{
		case('1'):               //Gestão de clientes
		{
			char menu_2;

			system("CLS");     //Limpar o ecrã
			cout << "Introduza a operacao que deseja efetuar  " << endl << endl;

			cout << "[1] Adicionar clientes " << endl;
			cout << "[2] Remover clientes " << endl;
			cout << "[0] Sair do programa " << endl << endl;

			cin >> menu_2;

			switch (menu_2)
			{
			case('1'):          //Adicionar clientes
			{
				test = false;
				system("CLS");

				clients c;
				cin.ignore(1000, '\n');
				cout << "Introduza o nome do cliente : "; getline(cin, c.nome);
				cout << "\nIntroduza o nif do cliente : "; getline(cin, c.nif);
				cout << "\nIntroduza o agregado do cliente : "; getline(cin, c.agregado);
				cout << "\nIntroduza a morada do cliente : "; getline(cin, c.morada);
				c.pacotes_comprados = "0";
				c.total_compras = c.pacotes_comprados;

				v_clients.push_back(c);

				break;
			}
			case('2'):          //Remover clientes
			{
				test = false;
				system("CLS");

				string nome;
				cin.ignore(1000, '\n');
				cout << "Qual o nome do cliente que pretende eliminar? :";
				getline(cin, nome);

				for (size_t i = 0; i < v_clients.size(); i++)          //Percorrer os nomes dos clientes
					if (v_clients[i].nome == nome)                     //Encontrar o index do cliente
					{
						v_clients.erase(v_clients.begin() + i);        //Apagar o cliente desejado
						break;
					}

				break;
			}
			case('0'):          //Sair do Programa
			{
				return 0;
				break;
			}
			}
			break;
		}
		case('2'):              //Gestão de pacotes turisticos
		{
			char menu_2;

			system("CLS");    //Limpar o ecrã
			cout << "Introduza a operacao que deseja efetuar  " << endl << endl;

			cout << "[1] Adicionar pacotes " << endl;
			cout << "[2] Remover pacotes " << endl;
			cout << "[0] Sair do programa " << endl << endl;

			cin >> menu_2;

			switch (menu_2)
			{
			case('1'):          //Adicionar pacotes
			{
				test = false;
				system("CLS");     //Limpar o ecrã

				packs p;           //Recolher os dados dos pacotes
				cin.ignore(1000, '\n');
				cout << "Introduza o identificador do pacote : "; getline(cin, p.identificador);
				cout << "\nIntroduza os locais do pacote : "; getline(cin, p.locais);
				cout << "\nIntroduza a data de inicio do pacote : "; getline(cin, p.data_inicio);
				cout << "\nIntroduza a data de fim do pacote : "; getline(cin, p.data_fim);
				cout << "\nIntroduza o preço por pessoa do pacote : "; getline(cin, p.preco_pessoa);
				cout << "\nIntroduza o numero maximo de pessoas do pacote: "; getline(cin, p.maximo_pessoas);
				p.total_comprados = "0";

				break;
			}
			case('2'):          //Remover pacotes
			{
				test = false;
				system("CLS");     //Limpar o ecrã

				string identificador;      //Eliminar o pacote através do identificador
				cin.ignore(1000, '\n');
				cout << "Introduza o identificador do pacotes que deseja remover : ";
				getline(cin, identificador);

				for (size_t i = 0; i < v_packs.size(); i++)
					if (v_packs[i].identificador == identificador)
					{
						v_packs.erase(v_packs.begin() + i);
						break;
					}
				break;
			}
			case('0'):          //Sair do Programa
			{
				return 0;
				break;
			}
			}
			break;
		}
		case('3'):              //visualizar informação
		{
			char menu_2;

			system("CLS");    //Limpar o ecrã
			cout << "Introduza a operacao que deseja efetuar  " << endl << endl;

			cout << "[1] Visualizar clientes " << endl;
			cout << "[2] Visualizar pacotes " << endl;
			cout << "[3] Visualizar o numero e valor total de pacotes vendidos " << endl;
			cout << "[0] Sair do programa " << endl << endl;

			cin >> menu_2;

			switch (menu_2)
			{
			case('1'):          //Visualizar clientes
			{
				char menu_3;

				system("CLS");    //Limpar o ecrã
				cout << "Introduza a operacao que deseja efetuar  " << endl << endl;

				cout << "[1] Visualizar todos os clientes " << endl;
				cout << "[2] Visualizar um so cliente " << endl;
				cout << "[3] Sair do programa " << endl << endl;
				cin >> menu_3;

				switch (menu_3)
				{
				case('1'):          //Visualizar todos os clientes
				{
					test = false;
					system("CLS");
					for (size_t i = 0; i < v_clients.size(); i++)              //Visualizar cliente a cliente
					{
						cout << v_clients[i].nome << endl;                     //Visualizar o nome do cliente
						cout << v_clients[i].nif << endl;                      //Visualizar o nif do cliente
						cout << v_clients[i].agregado << endl;                 //Visualizar o agregado familiar do cliente
						cout << v_clients[i].morada << endl;                   //Visualizar a morada do cliente
						cout << v_clients[i].pacotes_comprados << endl << endl;//Visualizar os pacotes comprados pelo cliente
																				//Proximo cliente, se existir
					}

					break;
				}
				case('2'):          //Visualizar um só cliente
					test = false;
					system("CLS");

					string nome;
					cin.ignore(1000, '\n');
					cout << "Introduza o nome do cliente : ";
					getline(cin, nome);

					int index;
					for (size_t i = 0; i < v_clients.size(); i++) if (v_clients[i].nome == nome) index = i;

					cout << v_clients[index].nome << endl;                     //Visualizar o nome do cliente
					cout << v_clients[index].nif << endl;                      //Visualizar o nif do cliente
					cout << v_clients[index].agregado << endl;                 //Visualizar o agregado familiar do cliente
					cout << v_clients[index].morada << endl;                   //Visualizar a morada do cliente
					cout << v_clients[index].pacotes_comprados << endl;        //Visualizar os pacotes comprados pelo cliente

					break;
				}
				break;
			}
			case('2'):          //Visualizar pacotes
			{
				
				char menu_3;

				system("CLS");    //Limpar o ecrã
				cout << "Introduza a operacao que deseja efetuar  " << endl << endl;

				cout << "[1] Visualizar todos os pacotes " << endl;
				cout << "[2] Visualizar pacotes especificos " << endl;
				cout << "[0] Sair do programa " << endl << endl;
				cin >> menu_3;

				switch (menu_3)
				{
				case('1'):      //Visualizar todos os pacotes
					test = false;
					system("CLS");   //Limpar o ecrâ

					for (size_t i = 0; i < v_packs.size(); i++)                //Visualizar pacote a pacote
					{
						cout << v_packs[i].identificador << endl;              //Visualizar o identificador do pacote
						cout << v_packs[i].locais << endl;                     //Visualizar os locais do pacotes
						cout << v_packs[i].data_inicio << endl;                //Visualizar a data de inicio do pacote
						cout << v_packs[i].data_fim << endl;                   //Visualizar a data de fim do pacote
						cout << v_packs[i].preco_pessoa << endl;               //Visualizar o preço por pessoa do pacote
						cout << v_packs[i].maximo_pessoas << endl;             //Visualizar o numero maximo de pessoas do pacote
						cout << v_packs[i].total_comprados << endl << endl;    //Visualizar o numero total de pacotes comprados
																				//Proximo pacote, se existir
					}
					break;
				case('2'):       //Visualizar um so pacote
					
					char menu_4;

					system("CLS");    //Limpar o ecrã
					cout << "Introduza o criterio de busca de pacotes  " << endl << endl;

					cout << "[1] Destinos " << endl;
					cout << "[2] Datas " << endl;
					cout << "[3] Destinos e datas" << endl;
					cout << "[4] Cliente" << endl;
					cout << "[0] Sair do programa " << endl << endl;
					cin >> menu_4;


					switch (menu_4)
					{
					case('1'):   //Visualizar um so pacote tendo em conta o destino
					{
						test = false;
						system("CLS");  //Limpar o ecrâ
						string destino;
						cin.ignore(1000, '\n');
						cout << "Introduza o destino do pacote : ";
						getline(cin, destino);
						cout << endl;


						vector<int> index;                                     //Procurar o pacote através do destino
						for (size_t i = 0; i < v_packs.size(); i++) if (v_packs[i].locais == destino) index.push_back(i);

						for (size_t i = 0; i < index.size(); i++)              //Percorrer os pacotes que têm esse destino
						{
							cout << v_packs[index[i]].identificador << endl;          //Visualizar o identificador do pacote
							cout << v_packs[index[i]].locais << endl;                 //Visualizar os locais do pacotes
							cout << v_packs[index[i]].data_inicio << endl;            //Visualizar a data de inicio do pacote
							cout << v_packs[index[i]].data_fim << endl;               //Visualizar a data de fim do pacote
							cout << v_packs[index[i]].preco_pessoa << endl;           //Visualizar o preço por pessoa do pacote
							cout << v_packs[index[i]].maximo_pessoas << endl;         //Visualizar o numero maximo de pessoas do pacote
							cout << v_packs[index[i]].total_comprados << endl << endl;//Visualizar o numero total de pacotes comprados
																						//Proximo pacote, se existir
						}
						break;
					}
					case('2'):   //Visualizar um so pacote tendo em conta as datas de inicio e fim
					{
						test = false;
						system("CLS");  //Limpar o ecrâ

						vector<int> v_index;
						string inicio, fim;
						cin.ignore(1000, '\n');
						cout << "Introduza a data de inicio do pacote : ";
						getline(cin, inicio);
						cout << "Introduza a data de fim do pacote : ";
						getline(cin, fim);
						cout << endl;



						//Este ciclo tem como objetivo verificar se as datas se encontram dentro dos intevalos possiveis
						for (size_t i = 0; i < v_packs.size(); i++)
						{
							if (menor_ou_igual_data(inicio, v_packs[i].data_inicio) && menor_ou_igual_data(v_packs[i].data_fim, fim))
								v_index.push_back(i);
						}
						//Este ciclo é executado se tiver sido encontrado um pacote dentro das datas possiveis
						for (size_t i = 0; i < v_index.size(); i++)
						{
							cout << v_packs[v_index[i]].identificador << endl;          //Visualizar o identificador do pacote
							cout << v_packs[v_index[i]].locais << endl;                 //Visualizar os locais do pacotes
							cout << v_packs[v_index[i]].data_inicio << endl;            //Visualizar a data de inicio do pacote
							cout << v_packs[v_index[i]].data_fim << endl;               //Visualizar a data de fim do pacote
							cout << v_packs[v_index[i]].preco_pessoa << endl;           //Visualizar o preço por pessoa do pacote
							cout << v_packs[v_index[i]].maximo_pessoas << endl;         //Visualizar o numero maximo de pessoas do pacote
							cout << v_packs[v_index[i]].total_comprados << endl << endl;//Visualizar o numero total de pacotes comprados
																						//Proximo pacote, se existir

						}
						break;
					}
					case('3')://Visualizar um so pacote tendo em conta o destino e as datas de inicio e fim
					{
						test = false;
						system("CLS");  //Limpar o ecrâ

						vector<int> v_index;
						string destino, inicio, fim;

						cin.ignore(1000, '\n');
						cout << "Introduza o destino do pacote : ";
						getline(cin, destino);
						cout << "Introduza a data de inicio do pacote : ";
						getline(cin, inicio);
						cout << "Introduza a data de fim do pacote : ";
						getline(cin, fim);
						cout << endl;

						//Este ciclo verifica se as datas se encontram dentro dos intevalos possiveis, para um determinado destino
						for (size_t i = 0; i < v_packs.size(); i++)
						{
							if (menor_ou_igual_data(inicio, v_packs[i].data_inicio) && menor_ou_igual_data(v_packs[i].data_fim, fim) && v_packs[i].locais == destino)
								v_index.push_back(i);
						}
						//Este ciclo é executado se tiver sido encontrado um pacote dentro das datas possiveis e para o destino escolhido
						for (size_t i = 0; i < v_index.size(); i++)
						{
							cout << v_packs[v_index[i]].identificador << endl;          //Visualizar o identificador do pacote
							cout << v_packs[v_index[i]].locais << endl;                 //Visualizar os locais do pacotes
							cout << v_packs[v_index[i]].data_inicio << endl;            //Visualizar a data de inicio do pacote
							cout << v_packs[v_index[i]].data_fim << endl;               //Visualizar a data de fim do pacote
							cout << v_packs[v_index[i]].preco_pessoa << endl;           //Visualizar o preço por pessoa do pacote
							cout << v_packs[v_index[i]].maximo_pessoas << endl;         //Visualizar o numero maximo de pessoas do pacote
							cout << v_packs[v_index[i]].total_comprados << endl << endl;//Visualizar o numero total de pacotes comprados
																						//Proximo pacote, se existir
						}
						break;
					}
					case('4'): //Visualizar um pacote tendo em conta o cliente
					{
						test = false;
						system("CLS");  //Limpar o ecrâ
						string name;
						vector<int> c_index;  //Vetor que contem o index do cliente com o nome pedido
						vector<int> v_index;  //Vetor que contem os indexs dos pacotes que o cliente possui

						cin.ignore(1000, '\n');
						cout << "Introduza o nome do cliente : ";
						getline(cin, name);

						for (size_t i = 0; i < v_clients.size(); i++)
						{
							if (v_clients[i].nome == name) c_index.push_back(i);
						}
						for (size_t i = 0; i < c_index.size(); i++)
						{
							for (size_t j = 0; j < packs_int(v_clients[c_index[i]].pacotes_comprados).size(); j++)
							{
								for (size_t k = 0; k < v_packs.size(); k++)
								{
									if (stoi(v_packs[k].identificador) == packs_int(v_clients[c_index[i]].pacotes_comprados)[j])
									{
										v_index.push_back(k);
									}
								}
							}
						}
						// string identificador, locais, data_inicio, data_fim, preco_pessoa, maximo_pessoas;
						for (size_t i = 0; i < v_index.size(); i++)
						{
							cout << v_packs[v_index[i]].identificador << endl;          //Visualizar o identificador do pacote
							cout << v_packs[v_index[i]].locais << endl;                 //Visualizar os locais do pacotes
							cout << v_packs[v_index[i]].data_inicio << endl;            //Visualizar a data de inicio do pacote
							cout << v_packs[v_index[i]].data_fim << endl;               //Visualizar a data de fim do pacote
							cout << v_packs[v_index[i]].preco_pessoa << endl;           //Visualizar o  preço por pessoa do pacote
							cout << v_packs[v_index[i]].maximo_pessoas << endl;         //Visualizar o numero maximo de pessoas do pacote
							cout << v_packs[v_index[i]].total_comprados << endl << endl;//Visualizar o numero total de pacotes comprados
																							//Proximo pacote, se existir
						}

						break;
					}
					case('0'):
						return 0;
						break;
						break;
					}
					// Neste lugar eu tinha um  return 0 mas estava me a estragar o codigo todo somehow
				}
				break;
			}
			case('3'):          //Visualizar o valor e o numero de pacotes vendidos
			{
				test = false;
				system("CLS");

				int counter = 0;            //Contador do numero de pacotes vendidos
				int valor = 0;              //Contador do valor total de pacotes vendidos

				for (size_t i = 0; i < v_packs.size(); i++)
				{
					for (size_t j = 0; j < v_clients.size(); j++)
					{
						for (size_t k = 0; k < packs_int(v_clients[j].pacotes_comprados).size(); k++)
						{
							//Esta condição verifica se, dentro dos pacotes existentes, existe um cliente que o tenha comprado
							//Caso isso se verifique, incrementa o numero de pacotes vendidos
							//E também adiciona o valor desse pacote tendo em conta o preço por pessoa e o numero de pessoas
							if (packs_int(v_clients[j].pacotes_comprados)[k] == stoi(v_packs[i].identificador))
							{
								counter++;
								valor += stoi(v_clients[j].agregado) * stoi(v_packs[i].preco_pessoa);

							}
						}

					}
				}
				cout << "Foram vendidos " << counter << " pacotes" << endl << endl;
				cout << "O valor total de pacotes vendidos e : " << valor << " euros";

				break;
			}
			case('0'):          //Sair do Programa
			{
				return 0;
				break;
			}
			}

			break;
		}
		case('4'):              //Comprar pacotes
		{
			test = false;
			system("CLS");    //Limpar ecrâ

			string nome, pacote, nif, morada, agregado;
			int  index;
			bool exists = false;

			cin.ignore(1000, '\n');
			cout << "Qual e o seu nome ? ";
			getline(cin, nome);
			cout << endl << "Que pacote pretende comprar ?";
			getline(cin, pacote);

			//Avaliar se o cliente já existe ou não
			for (size_t i = 0; i < v_clients.size(); i++)
				if (v_clients[i].nome == nome)
				{
					exists = true;
					index = i;
				}

			//Adicionar aos pacotes comprados, em caso de o cliente já existir
			if (exists) v_clients[index].pacotes_comprados += " ; " + pacote;

			//Criar um novo cliente no caso de ele não existir
			else
			{
				clients c;

				cout << "\nQual e o seu NIF ? ";
				getline(cin, nif);
				cout << "\nQual e a sua morada ? ";
				getline(cin, morada);
				cout << "\nQual e o seu agregado familiar ? ";
				getline(cin, agregado);

				c.nome = nome;
				c.morada = morada;
				c.nif = nif;
				c.agregado = agregado;
				c.pacotes_comprados = pacote;

				v_clients.push_back(c);
			}

			//Incrementar o numero de vezes que o pacote foi comprado
			for (size_t i = 0; i < v_packs.size(); i++)
			{
				if (v_packs[i].identificador == pacote)
				{
					int temp = stoi(v_packs[i].total_comprados);
					temp++;
					v_packs[i].total_comprados = to_string(temp);
				}
			}


			break;

		}
		case('0'):              //Sair do Programa
		{
			return 0;
			break;
		}

		}
	}

	//Por fim, vamos passar todos os dados alterados para um novo ficheiro

	//Passar os dados dos clientes para um ficheiro

	ofstream fout;
	fout.open("clients.txt", ofstream::out | ofstream::trunc);

	for (size_t i = 0; i < v_clients.size(); i++)
	{
		fout << v_clients[i].nome << endl;
		fout << v_clients[i].nif << endl;
		fout << v_clients[i].agregado << endl;
		fout << v_clients[i].morada << endl;
		fout << v_clients[i].pacotes_comprados;
		if (i != v_clients.size() - 1) fout << endl;
		if (i != v_clients.size() - 1) fout << "::::::::::" << endl;
	}

	fout.close();

	//passar os dados dos pacotes para um ficheiro
	ofstream fout2;
	fout2.open("packs.txt", ofstream::out | ofstream::trunc);

	fout2 << v_packs[v_packs.size() - 1].identificador << endl;
	for (size_t i = 0; i < v_packs.size(); i++)
	{
		fout2 << v_packs[i].identificador << endl;
		fout2 << v_packs[i].locais << endl;
		fout2 << v_packs[i].data_inicio << endl;
		fout2 << v_packs[i].data_fim << endl;
		fout2 << v_packs[i].preco_pessoa << endl;
		fout2 << v_packs[i].maximo_pessoas << endl;
		fout2 << v_packs[i].total_comprados;
		if (i != v_packs.size() - 1) fout2 << endl;
		if (i != v_packs.size() - 1) fout2 << "::::::::::" << endl;
	}

	fout2.close();
	

	_getwch();
	return 0;
}