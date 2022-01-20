#include "ManagerConturi.h"

string ManagerConturi::CreateIban()
{
	return string();
}

void ManagerConturi::adaugareCont()
{
	string nume, prenume, iban;
	cout << "    Introduceti numele persoanei: \n";
	cin >> nume;
	cout<< "    Introduceti prenumele persoanei: \n";
	cin >> prenume;
	
	//TODO: replace iban with createIban() 
	iban = "Test iban";
	ContBancar* cont = new ContBancar(nume, prenume, iban);
	m_listaConturi.push_back(cont);

	system("cls");
}
