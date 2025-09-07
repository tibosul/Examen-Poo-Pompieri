#pragma once
#include "Incendiu.h"

class Incendiu_Electric : public Incendiu
{
public:
	Incendiu_Electric();
	Incendiu_Electric(const std::string& adresa, int numar_victime);
	Incendiu_Electric(const std::string& adresa, int numar_victime, int inaltime, double arie);
	virtual ~Incendiu_Electric() override = default;
};

