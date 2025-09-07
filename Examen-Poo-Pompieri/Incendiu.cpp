#include "Incendiu.h"

Incendiu::Incendiu()
	:Urgenta()
{
}

Incendiu::Incendiu(const std::string& adresa, int numar_victime)
	:Urgenta(adresa, numar_victime)
{
}

Incendiu::Incendiu(const std::string& adresa, int numar_victime, int inaltime, double arie)
	:Urgenta(adresa, numar_victime)
{
	this->inaltime = inaltime;
	this->arie = arie;
}
