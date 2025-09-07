#include "Unitate_Pompieri.h"
#include "I_Angajat.h"
#include "I_Autospeciala.h"
#include "I_Urgenta.h"
#include "Interventie.h"
#include "Tura.h"

Unitate_Pompieri& Unitate_Pompieri::get_instance()
{
    static Unitate_Pompieri instance;
    return instance;
}

void Unitate_Pompieri::add_angajat(I_Angajat* angajat)
{
    this->angajati[angajat->get_id()] = angajat;
}

void Unitate_Pompieri::add_autospeciala(I_Autospeciala* autospeciala)
{
    this->autospeciale[autospeciala->get_id()] = autospeciala;
}

void Unitate_Pompieri::add_interventie(Interventie* interventie)
{
    this->interventii[interventie->get_id()] = interventie;
}

void Unitate_Pompieri::add_urgenta(I_Urgenta* urgenta)
{
    this->urgente.push_back(urgenta);
}


