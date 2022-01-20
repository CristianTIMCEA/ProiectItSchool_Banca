#include <iostream>
#include "ContBancar.h"

using namespace std;


int main()
{
	cout << endl;
	cout << "   Alege una din urmatoarele optiuni :\n" << endl;
	cout << "        1 -> Numar conturi\n";
	cout << "        2 -> Creare cont\n";
	cout << "        3 -> Modificare cont\n";
	cout << "        4 -> Stergere conturi\n";
	cout << "        5 -> Eliberare/Depunere\n";
	cout << "        6 -> Detalii cont\n";
	cout << endl;
	int optiune;
	cout << "   Introduceti operatia pe care o doriti: ";
	cin >> optiune;
	cout << endl;
	switch (optiune)
	{
	case 1: 
		cout << "       Ati ales optiunea cu numarul 1\n";
		break;
	case 2:
		cout << "       Ati ales optiunea cu numarul 2\n";
		break;
	case 3:
		cout << "       Ati ales optiunea cu numarul 3\n";
		break;
	case 4:
		cout << "       Ati ales optiunea cu numarul 4\n";
		break;
	case 5:
		cout << "       Ati ales optiunea cu numarul 5\n";
		break; 
	case 6:
		cout << "       Ati ales optiunea cu numarul 6\n";
		break;
	default:
		cout << "       Optiune invalida\n";
		break;
	}
}
