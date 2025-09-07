#include "Autospeciala_Stingere_Spuma.h"
#include "Unitate_Pompieri.h"

Autospeciala_Stingere_Spuma::Autospeciala_Stingere_Spuma()
	:Autospeciala_Stingere()
{
	Unitate_Pompieri::get_instance().add_autospeciala(this);
}

Autospeciala_Stingere_Spuma::Autospeciala_Stingere_Spuma(double capacitate_material)
	:Autospeciala_Stingere(capacitate_material)
{
	Unitate_Pompieri::get_instance().add_autospeciala(this);
}
