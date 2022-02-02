#include "FileManager.h"

void FileManager::WriteToCSV(string nume, string prenume, string iban, float sold)
{
	fstream csv_file;
	csv_file.open("ConturiDataBase.csv", ios::out | ios::app);
	if (csv_file.is_open())
	{
		csv_file << nume << ',' << prenume << ',' << iban << ',' << sold << ',' << '\n';
	}
	else
	{
		cout << " ERROR, file not opened !\n";
	}
}
