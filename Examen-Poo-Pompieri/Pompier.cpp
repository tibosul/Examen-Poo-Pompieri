#include "Pompier.h"
#include "Unitate_Pompieri.h"

Pompier::Pompier()
	:Angajat()
{
	Unitate_Pompieri::get_instance().add_angajat(this);
}

Pompier::Pompier(const std::string& nume)
	:Angajat(nume)
{
	Unitate_Pompieri::get_instance().add_angajat(this);
}

Pompier::Pompier(const std::string& nume, int numar_interventii)
	:Angajat(nume)
{
	this->numar_interventii = numar_interventii;
	Unitate_Pompieri::get_instance().add_angajat(this);
}

// Supraîncărcarea operatorului ++ pentru incrementarea experienței
Pompier& Pompier::operator++()
{
	this->numar_interventii++;
	return *this;
}

Pompier Pompier::operator++(int)
{
	Pompier temp = *this;
	this->numar_interventii++;
	return temp;
}