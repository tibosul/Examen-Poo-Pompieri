#pragma once
#include "Angajat.h"

class Pompier : public Angajat
{
protected:
	int numar_interventii = 0;

public:
	Pompier();
	Pompier(const std::string& nume);
	Pompier(const std::string& nume, int numar_interventii);
	virtual ~Pompier() override = default;

	virtual inline int get_numar_interventii() const override { return this->numar_interventii; }
	virtual inline void set_numar_interventii(int numar_interventii) override { this->numar_interventii = numar_interventii; }
};

