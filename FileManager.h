#pragma once
#include "ContBancar.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class FileManager
{
public:
	void WriteToCSV(string nume, string prenume, string iban, float sold);
	vector <ContBancar*> ReadContBancarFromCSV();
};

