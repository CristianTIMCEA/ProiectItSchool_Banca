#pragma once
#include <string>


using namespace std;

enum class TipMoneda
{
	RON,
	EUR
};

class ContBancar
{
	string m_nume;
	string m_prenume;
	float m_sold;
	string m_IBAN;
	//TODO: tipului soldului va trebui sa fie modificat intr-un enum 0=RON, 1=EUR (clasa enum de mai sus)
	TipMoneda m_tipSold;
public:
	ContBancar(string nume, string prenume, string iban);

	string getNume() const;
};

