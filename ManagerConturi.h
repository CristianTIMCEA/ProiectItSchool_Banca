#pragma once
#include <iostream>
#include <vector>
#include "ContBancar.h"

using namespace std;


class ManagerConturi
{
private:
	vector<ContBancar*> m_listaConturi;
	string CreateIban();
public:
	void adaugareCont();
	int GetNumarConturi();
	void printAllConturi();
};

