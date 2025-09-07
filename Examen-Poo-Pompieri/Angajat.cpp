#include "Angajat.h"

using Angajat_ID_Generator = Unique_ID_Generator<Angajat>;

Angajat::Angajat()
	:I_Angajat()
{
}

Angajat::Angajat(const std::string& nume)
	:I_Angajat()
{
	this->nume = nume;
	this->id_unic = Angajat_ID_Generator::generate_next_id();
}