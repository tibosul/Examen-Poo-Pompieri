#include "Autospeciala_Stingere_Pulbere.h"
#include "Unitate_Pompieri.h"

Autospeciala_Stingere_Pulbere::Autospeciala_Stingere_Pulbere()
	:Autospeciala_Stingere()
{
	Unitate_Pompieri::get_instance().add_autospeciala(this);
}

Autospeciala_Stingere_Pulbere::Autospeciala_Stingere_Pulbere(double capacitate_material)
	:Autospeciala_Stingere(capacitate_material)
{
	Unitate_Pompieri::get_instance().add_autospeciala(this);
}
