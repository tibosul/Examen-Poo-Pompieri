#pragma once
#include "Autospeciala.h"

class Autospeciala_Stingere : public Autospeciala
{
protected:
	double capacitate_material = 0.0;

public:
	Autospeciala_Stingere();
	Autospeciala_Stingere(double capacitate_material);
	virtual ~Autospeciala_Stingere() override = default;

	virtual inline double get_capacitate_material() const override { return this->capacitate_material; }
	virtual inline void set_capacitate_material(double capacitate_material) override { this->capacitate_material = capacitate_material; }

};

