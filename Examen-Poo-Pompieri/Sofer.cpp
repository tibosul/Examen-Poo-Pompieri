#include "Sofer.h"
#include "Unitate_Pompieri.h"

Sofer::Sofer()
	:Angajat()
{
	Unitate_Pompieri::get_instance().add_angajat(this);
}

Sofer::Sofer(const std::string& nume)
	:Angajat(nume)
{
	Unitate_Pompieri::get_instance().add_angajat(this);
}
