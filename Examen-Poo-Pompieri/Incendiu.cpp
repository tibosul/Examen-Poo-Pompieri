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

	this->autoscari_necesare = (this->inaltime > 2) ? (1 + this->numar_victime / 20) : 0;
	this->numar_pompieri_necesari = (this->inaltime > 10) ? (1 + this->arie / 20.0) : (1 + this->arie / 25.0);
}
