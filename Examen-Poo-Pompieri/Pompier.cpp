#include "Pompier.h"

Pompier::Pompier()
	:Angajat()
{
}

Pompier::Pompier(const std::string& nume)
	:Angajat(nume)
{
}

Pompier::Pompier(const std::string& nume, int numar_interventii)
	:Angajat(nume)
{
	this->numar_interventii = numar_interventii;
}
