#include "I_Angajat.h"
#include "Pompier.h"
#include "Sofer.h"

I_Angajat* I_Angajat_Factory::create_new_Pompier()
{
    return new Pompier();
}

I_Angajat* I_Angajat_Factory::create_new_Pompier(const std::string& nume)
{
    return new Pompier(nume);
}

I_Angajat* I_Angajat_Factory::create_new_Pompier(const std::string& nume, int numar_interventii)
{
    return new Pompier(nume, numar_interventii);
}

I_Angajat* I_Angajat_Factory::create_new_Sofer()
{
    return new Sofer();
}

I_Angajat* I_Angajat_Factory::create_new_Sofer(const std::string& nume)
{
    return new Sofer(nume);
}


