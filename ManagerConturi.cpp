#include "ManagerConturi.h"
#include <algorithm>

string ManagerConturi::CreateIban()
{
	unsigned int iban = 0;
	srand(unsigned(time(0)));
	iban = rand();
	string stringIban =to_string(iban);
	string stringIbanComplet = "RO44ItSchool" + stringIban;
	cout << "IBAN generat:  " << stringIbanComplet << endl;
	return stringIbanComplet;
}

int ManagerConturi::GetNumarConturi()
{
	int numarConturi = m_listaConturi.size();
	return numarConturi;
}

void ManagerConturi::printAllConturi()
{
	cout << endl;
	for (auto& cont : m_listaConturi)
	{
		cout << endl;
		cout << " Nume : " << cont->getNume() << endl;
		cout << " Prenume : " << cont->getPrenume() << endl;
		cout << " IBAN : " << cont->getIban() << endl;
		cout << " Sold : " << cont->getSold() << endl;
	}
	cout << endl;
	cout << "   Apasati tasta 0 pentru a va intoarce  ";
	char back;
	cin >> back;
}

ContBancar* ManagerConturi::FindAccount()
{
	cout << endl;
	cout << "     Introduceti numele titularului pe care il cautati: ";
	string nume;;
	cin >> nume;

	for (auto& cont : m_listaConturi)
	{
		if (cont->getNume() == nume)
			return cont;
	}
	cout << endl;
	cout << " Titularul nu a fost gasit !" << endl;
	return nullptr;
}

void ManagerConturi::adaugareCont()
{
	string nume, prenume, iban;
	cout << endl;
	cout << "    Introduceti numele beneficiarului: ";
	cin >> nume;
	cout << endl;
	cout << "    Introduceti prenumele beneficiarului: ";
	cin >> prenume;
	iban = CreateIban();
	ContBancar* cont = new ContBancar(nume, prenume, iban);
	m_listaConturi.push_back(cont);
	m_fileManager->WriteToCSV(nume, prenume, iban, cont->getSold());
	system("cls");
}

void ManagerConturi::EraseAccount()
{
	cout << " Introduceti datele pentru contul ce urmeaza sa fie sters \n";
	ContBancar* cont = FindAccount();
	vector <ContBancar*>::iterator it = find(m_listaConturi.begin(), m_listaConturi.end(),cont);
	m_listaConturi.erase(it);
	delete cont;
}

void ManagerConturi::Eliberare_Depunere()
{
	ContBancar* cont = FindAccount();
	if (cont != nullptr)
	{
		float valoare;
		cout << endl;
		cout << " Introduceti valoare :\n";
		cin >> valoare;
		cont->manipulare_sold(valoare);
	}
	else
	{
		cout << endl;
		cout << "  Contul este inexistent\n";
	}
}

void ManagerConturi::ModificaCont()
{
	ContBancar* cont = FindAccount();
	if (cont != nullptr)
	{

		system("cls");
		cout << endl;
		cout << "    Pentru modificare nume de familie beneficiar, apasati tasta -> 1" << endl;
		cout << endl;
		cout << "    Pentru modificare prenume beneficiar, apasati tasta -> 2" << endl;
		int tasta1;
		do
		{
			cout << endl;
			cout << "    Introduceti optiunea dorita: ";
			cin >> tasta1;
			switch (tasta1)
			{
			case 1:
			{
				cout << endl;
				string nume;
				cout << "    Introduceti noul nume de familie: ";
				cin >> nume;
				cont->changeNume(nume);
				break;
			}
			case 2:
			{
				cout << endl;
				string prenume;
				cout << "    Introduceti noul prenume: ";
				cin >> prenume;
				cont->changePrenume(prenume);
				break;
			}
			default:
			{
				cout << endl;
				cout << "    Optiune invalida !\n" << endl;
				cout << "    Pentru revenire la meniul principal, apasati tasta -> 0  " << endl;
				break;
			}
			}
		} while (tasta1 != 0);
	}
	else
	{
		cout << endl;
		cout << "   Cont inexistent !\n" << endl;
	}
}

ManagerConturi::ManagerConturi()
{
	m_fileManager = new FileManager();
	m_listaConturi = m_fileManager->ReadContBancarFromCSV();
}

ManagerConturi::~ManagerConturi()
{
	delete m_fileManager;
}

void ManagerConturi::PrintASpecificCont(const string& cautaNume, const string& cautaPrenume)
{
	bool n = true;
	for (auto& cont : m_listaConturi)
	{
		if (cautaNume == cont->getNume() && cautaPrenume == cont->getPrenume())
		{
			cout << " Nume: " << cont->getNume() << endl;
			cout << " Prenume: " << cont->getPrenume() << endl;
			cout << " IBAN : " << cont->getIban() << endl;
			cout << " Sold: " << cont->getSold() << endl;
		}
		if (!n)
		{
			cout << " Ne pare rau, dar criteriile de cautare nu se potrivesc cu niciun cont existent\n";
		}
		cout << endl;
		cout << "Apasati orice tasta pentru a va intoarce\n";
		char back;
		cin >> back;
	}

}

