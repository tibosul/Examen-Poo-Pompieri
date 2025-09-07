#include "I_Autospeciala.h"
#include "Autoscara.h"
#include "Autospeciala_Descarcerare.h"
#include "Autospeciala_Stingere_Pulbere.h"
#include "Autospeciala_Stingere_Spuma.h"

I_Autospeciala* I_Autospeciala_Factory::create_new_Autoscara()
{
    return new Autoscara();
}

I_Autospeciala* I_Autospeciala_Factory::create_new_Autoscara(double lungime_scara)
{
    return new Autoscara(lungime_scara);
}

I_Autospeciala* I_Autospeciala_Factory::create_new_Autospeciala_Descarcerare()
{
    return new Autospeciala_Descarcerare();
}

I_Autospeciala* I_Autospeciala_Factory::create_new_Autospeciala_Descarcerare(int numar_departatoare, int numar_foarfece)
{
    return new Autospeciala_Descarcerare(numar_departatoare, numar_foarfece);
}

I_Autospeciala* I_Autospeciala_Factory::create_new_Autospeciala_Stingere_Pulbere()
{
    return new Autospeciala_Stingere_Pulbere();
}

I_Autospeciala* I_Autospeciala_Factory::create_new_Autospeciala_Stingere_Pulbere(double cantitate_material)
{
    return new Autospeciala_Stingere_Pulbere(cantitate_material);
}

I_Autospeciala* I_Autospeciala_Factory::create_new_Autospeciala_Stingere_Spuma()
{
    return new Autospeciala_Stingere_Spuma();
}

I_Autospeciala* I_Autospeciala_Factory::create_new_Autospeciala_Stingere_Spuma(double cantitate_material)
{
    return new Autospeciala_Stingere_Spuma(cantitate_material);
}

