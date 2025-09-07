#include "I_Urgenta.h"
#include "Accident.h"
#include "Incendiu_Electric.h"
#include "Incendiu_Vegetatie.h"

I_Urgenta* I_Urgenta_Factory::create_new_Accident()
{
    return new Accident();
}

I_Urgenta* I_Urgenta_Factory::create_new_Accident(const std::string& adresa, int numar_victime)
{
    return new Accident(adresa, numar_victime);
}

I_Urgenta* I_Urgenta_Factory::create_new_Accident(const std::string& adresa, int numar_victime, int numar_vehicule)
{
    return new Accident(adresa, numar_victime, numar_vehicule);
}

I_Urgenta* I_Urgenta_Factory::create_new_Incendiu_Electric()
{
    return new Incendiu_Electric();
}

I_Urgenta* I_Urgenta_Factory::create_new_Incendiu_Electric(const std::string& adresa, int numar_victime)
{
    return new Incendiu_Electric(adresa, numar_victime);
}

I_Urgenta* I_Urgenta_Factory::create_new_Incendiu_Electric(const std::string& adresa, int numar_victime, int inaltime, double arie)
{
    return new Incendiu_Electric(adresa, numar_victime, inaltime, arie);
}

I_Urgenta* I_Urgenta_Factory::create_new_Incendiu_Vegetatie()
{
    return new Incendiu_Vegetatie();
}

I_Urgenta* I_Urgenta_Factory::create_new_Incendiu_Vegetatie(const std::string& adresa, int numar_victime)
{
    return new Incendiu_Vegetatie(adresa, numar_victime);
}

I_Urgenta* I_Urgenta_Factory::create_new_Incendiu_Vegetatie(const std::string& adresa, int numar_victime, int inaltime, double arie)
{
    return new Incendiu_Vegetatie(adresa, numar_victime, inaltime, arie);
}

