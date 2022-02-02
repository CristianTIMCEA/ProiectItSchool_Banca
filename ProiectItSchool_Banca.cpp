#include <iostream>
#include "ManagerConturi.h"

using namespace std;

int main()
{
	int optiune;
	ManagerConturi manager;

	do
	{
		cout << endl;
		cout << "   Alege una din urmatoarele optiuni :\n" << endl;
		cout << "        1 -> Numar conturi\n";
		cout << "        2 -> Creare cont\n";
		cout << "        3 -> Modificare cont\n";
		cout << "        4 -> Stergere conturi\n";
		cout << "        5 -> Eliberare/Depunere\n";
		cout << "        6 -> Detalii cont\n";
		cout << "        0 -> EXIT\n";
		cout << endl;

		cout << "   Introduceti operatia pe care o doriti: ";
		cin >> optiune;
		cout << endl;
		switch (optiune)
		{
		case 1:
			cout << "       Ati ales optiunea cu numarul 1\n\n";
			cout << "       Numarul total de conturi este : " << manager.GetNumarConturi() << endl;
			break;
		case 2:
			cout << "       Ati ales optiunea cu numarul 2\n";
			system("cls");
			manager.adaugareCont();
			break;
		case 3:
			system("cls");
			cout << endl;
			cout << "       Ati ales optiunea cu numarul 3\n";
			cout << endl;
			cout << "   Pentru modificarea unui cont, apasati tasta -> 1" << endl;
			cout << endl;
			cout << "   Pentru a reveni la meniul principal, apasati tasta -> 0" << endl;
			cout << endl;
			int modifica;
			do 
			{
				cout << endl;
				cout << "     Introduceti operatia dorita: ";
				cin >> modifica;
				switch (modifica)
				{
				case 1:
				{
					manager.ModificaCont();
					break;
				}
				}

			} while (modifica != 0);
			system("cls");
			break;
		case 4:
			cout << "       Ati ales optiunea cu numarul 4\n";
			manager.EraseAccount();
			break;
		case 5:
			cout << "       Ati ales optiunea cu numarul 5\n";
			cout << endl;
			manager.Eliberare_Depunere();
			break;
		case 6:
			cout << "       Ati ales optiunea cu numarul 6\n";
			system("cls");
			cout << endl;
			cout << "     Pentru a afisa un cont dorit apasati tasta -> 1" << endl;
			cout << endl;
			cout << "     Pentru a afisa toate conturile, apasati tasta -> 2" << endl;
			cout << endl;
			int tasta;
			do
			{
				cout << endl;
				cout << "     Introduceti operatia dorita: ";
				cin >> tasta;
				switch (tasta)
				{
				case 1:
				{
					cout << endl;
					string cautaNume;
					string cautaPrenume;
					cout << "   Va rugam sa introduceti numele beneiciarului: ";
					cin >> cautaNume;
					cout << endl;
					cout << "   Va rugam sa introduceti prenumele beneficiarului: ";
					cin >> cautaPrenume;
					cout << endl;
					manager.PrintASpecificCont(cautaNume, cautaPrenume);
					break;
				}
				case 2:
				{
					cout << endl;
					cout << "   Ati ales sa afisati toti benefiaciarii";
					manager.printAllConturi();
					break;
				}
				default :
				{
					cout << endl;
					cout << "   Optiune invalida\n" << endl;
					cout << "   Apasati orice tasta pentru revenire la meniul principal  ";
					break;
				}
				}
			} while (tasta != 0);
			break;
		case 0:
		{
			cout << endl;
			cout << "       Multumim ! La Revedere !\n";
			break;
		}
		default:
		{
			cout << endl;
			cout << "       Optiune invalida !\n";
			break;
		}
		}
	} while (optiune != 0);
	
}
