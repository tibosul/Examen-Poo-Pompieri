#include "Urgenta.h"

Urgenta::Urgenta()
	:I_Urgenta()
{
}

Urgenta::Urgenta(const std::string& adresa, int numar_victime)
	:I_Urgenta()
{
	this->adresa = adresa;
	this->numar_victime = numar_victime;
}
