#pragma once
#include <iostream>
#include <vector>
#include "ContBancar.h"

using namespace std;


class ManagerConturi
{
private:
	vector<ContBancar*> m_listaConturi;
	//TODO: metoda iban trebuie sa genereze un iban unic care sa fie folosit pentru a crea conturi iban
	string CreateIban();
public:
	void adaugareCont();

};

