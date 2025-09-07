#include "Incendiu_Vegetatie.h"

Incendiu_Vegetatie::Incendiu_Vegetatie()
	:Incendiu()
{
}

Incendiu_Vegetatie::Incendiu_Vegetatie(const std::string& adresa, int numar_victime)
	:Incendiu(adresa, numar_victime)
{
}

Incendiu_Vegetatie::Incendiu_Vegetatie(const std::string& adresa, int numar_victime, int inaltime, double arie)
	:Incendiu(adresa, numar_victime, inaltime, arie)
{
}
