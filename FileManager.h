#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileManager
{
public:
	void WriteToCSV(string nume, string prenume, string iban, float sold);
};

