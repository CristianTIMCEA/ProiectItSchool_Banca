#include "ContBancar.h"

ContBancar::ContBancar(string nume, string prenume, string iban)
{
	m_nume = nume;
	m_prenume = prenume;
	m_IBAN = iban;
	m_sold = 0;
	m_tipSold = TipMoneda::RON;
}

string ContBancar::getNume() const
{
	return m_nume;
}

string ContBancar::getPrenume() const
{
	return m_prenume;
}

string ContBancar::getIban() const
{
	return m_IBAN;
}

float ContBancar::getSold() const
{
	return m_sold;
}

void ContBancar::manipulare_sold(float suma)
{
	m_sold += suma;
}

void ContBancar::changeNume(const string& changenume)
{
	m_nume = changenume;
}

void ContBancar::changePrenume(const string& changeprenume)
{
	m_prenume = changeprenume;
}
