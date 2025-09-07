#include "Autoscara.h"
#include "Unitate_Pompieri.h"

Autoscara::Autoscara()
	:Autospeciala()
{
	Unitate_Pompieri::get_instance().add_autospeciala(this);
}

Autoscara::Autoscara(double lungime_scara)
	:Autospeciala()
{
	this->lungime_scara = lungime_scara;
	Unitate_Pompieri::get_instance().add_autospeciala(this);
}
