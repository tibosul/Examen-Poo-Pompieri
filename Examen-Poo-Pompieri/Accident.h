#pragma once
#include "Urgenta.h"

class Accident : public Urgenta
{
protected:
	int numar_vehicule = 0;

public:
	Accident();
	Accident(const std::string& adresa, int numar_victime);
	Accident(const std::string& adresa, int numar_victime, int numar_vehicule);
	virtual ~Accident() override = default;

	virtual inline int get_numar_vehicule() const override { return this->numar_vehicule; }
	virtual inline void set_numar_vehicule(int numar_vehicule) override { this->numar_vehicule = numar_vehicule; }
};

