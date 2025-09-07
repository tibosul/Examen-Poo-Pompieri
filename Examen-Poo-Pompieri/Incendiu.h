#pragma once
#include "Urgenta.h"

class Incendiu : public Urgenta
{
protected:
	int inaltime = 0;
	double arie = 0.0;

public:
	Incendiu();
	Incendiu(const std::string& adresa, int numar_victime);
	Incendiu(const std::string& adresa, int numar_victime, int inaltime, double arie);
	virtual ~Incendiu() override = default;

	virtual inline int get_inaltime() const override { return this->inaltime; }
	virtual inline double get_arie() const override { return this->arie; }

	virtual inline void set_inaltime(int inaltime) override { this->inaltime = inaltime; }
	virtual inline void set_arie(double arie) override { this->arie = arie; }

};

