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
	TipMoneda m_tipSold;
public:
	ContBancar(string nume, string prenume, string iban);

	string getNume() const;
};