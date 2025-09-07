#include "Accident.h"

Accident::Accident()
	:Urgenta()
{
}

Accident::Accident(const std::string& adresa, int numar_victime)
	:Urgenta(adresa, numar_victime)
{
}

Accident::Accident(const std::string& adresa, int numar_victime, int numar_vehicule)
	:Urgenta(adresa, numar_victime)
{
	this->numar_vehicule = numar_vehicule;
	this->numar_departatoare_necesare = numar_vehicule - 1;
	this->numar_foarfece_necesare = 1;
}
