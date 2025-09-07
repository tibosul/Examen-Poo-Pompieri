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

	inline int get_numar_interventii() const { return this->numar_interventii; }

	inline void set_numar_interventii(int numar_interventii) { this->numar_interventii = numar_interventii; }
};

