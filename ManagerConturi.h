#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include "ContBancar.h"
#include "FileManager.h"

using namespace std;


class ManagerConturi
{
private:
	vector<ContBancar*> m_listaConturi;
	string CreateIban(); // ToDo : modificat chestia asta ca nu da iban unic, le repeta cand rerulezi programul
	ContBancar* FindAccount();
	FileManager* m_fileManager;
public:
	void adaugareCont();
	int GetNumarConturi();
	void printAllConturi();
	void PrintASpecificCont(const string& cautaNume,const string& cautaPrenume);
	void EraseAccount();
	void Eliberare_Depunere();
	void ModificaCont();
	ManagerConturi();
	~ManagerConturi();
};

