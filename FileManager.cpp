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
	csv_file.close();
}

vector<ContBancar*> FileManager::ReadContBancarFromCSV()
{
    ifstream  fileInput("ConturiDataBase.csv");
    //fileInput.open("ConturiDataBase.csv", std::ios::in);
    vector<ContBancar*> conturiDinCsv;
    vector<string> randuri;
    string linie;
    if (!fileInput.is_open())
    {
        cout << "Error file cannot be accesed\n";
    }
    //parsam toate liniile din fisier
    while (getline(fileInput, linie))
    {
        randuri.push_back(linie);
    }
    std::vector<string> cuvinte;
    //parsam rand cu rand si spargem in cuvinte 
    //instantam conturile si le pushuim in vecotrul nostru
    for (auto& rand : randuri)
    {
        cuvinte.clear();
        string nume, prenume, iban, cuvant;
        float sold;
        stringstream s(rand);
        while (getline(s, cuvant, ','))
        {
            if (!cuvant.empty())
                cuvinte.push_back(cuvant);
        }
        if (!cuvinte.empty()) 
        {
            ContBancar* cont = new ContBancar(cuvinte[0], cuvinte[1], cuvinte[2]);//ToDo:mai un construcotr pentru sold
            conturiDinCsv.push_back(cont);
        }

    }
    return conturiDinCsv;
}
