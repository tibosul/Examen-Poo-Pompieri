#include "Autospeciala_Descarcerare.h"
#include "Unitate_Pompieri.h"

Autospeciala_Descarcerare::Autospeciala_Descarcerare()
	:Autospeciala()
{
	Unitate_Pompieri::get_instance().add_autospeciala(this);
}

Autospeciala_Descarcerare::Autospeciala_Descarcerare(int numar_departatoare, int numar_foarfece)
	:Autospeciala()
{
	this->numar_departatoare = numar_departatoare;
	this->numar_foarfece = numar_foarfece;
	Unitate_Pompieri::get_instance().add_autospeciala(this);
}
