#pragma once
#include "Incendiu.h"

class Incendiu_Vegetatie : public Incendiu
{
public:
	Incendiu_Vegetatie();
	Incendiu_Vegetatie(const std::string& adresa, int numar_victime);
	Incendiu_Vegetatie(const std::string& adresa, int numar_victime, int inaltime, double arie);
	virtual ~Incendiu_Vegetatie() override = default;
};

