#include "Incendiu_Electric.h"

Incendiu_Electric::Incendiu_Electric()
	:Incendiu()
{
}

Incendiu_Electric::Incendiu_Electric(const std::string& adresa, int numar_victime)
	:Incendiu(adresa, numar_victime)
{
}

Incendiu_Electric::Incendiu_Electric(const std::string& adresa, int numar_victime, int inaltime, double arie)
	:Incendiu(adresa, numar_victime, inaltime, arie)
{
}
