#include "ManagerConturi.h"

string ManagerConturi::CreateIban()
{
	int iban = 11111 + (rand() % (99999));
	string stringIban =to_string(iban);
	string stringIbanComplet = "RO44ItSchool" + stringIban;
	cout << "IBAN generat:  " << stringIbanComplet << endl;
	return stringIbanComplet;
}

void ManagerConturi::adaugareCont()
{
	string nume, prenume, iban;
	cout << "    Introduceti numele persoanei: \n";
	cin >> nume;
	cout<< "    Introduceti prenumele persoanei: \n";
	cin >> prenume;
	
	iban = CreateIban();
	ContBancar* cont = new ContBancar(nume, prenume, iban);
	m_listaConturi.push_back(cont);

	system("cls");
}

int ManagerConturi::GetNumarConturi()
{
	int numarConturi = m_listaConturi.size();
	return numarConturi;
}

void ManagerConturi::printAllConturi()
{
	for (auto& cont : m_listaConturi)
	{
		cout << " Nume : " << cont->getNume() << endl;
		cout << " Prenume : " << cont->getPrenume() << endl;
		cout << " IBAN : " << cont->getIban() << endl;
		cout << " Sold : " << cont->getSold() << endl;
	}
	cout << endl;
	cout << "   Apasati tasta 0 pentru a va intoarce\n";
	char back;
	cin >> back;
}
