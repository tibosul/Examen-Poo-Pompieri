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

	inline int get_inaltime() const { return this->inaltime; }
	inline double get_arie() const { return this->arie; }

	inline void set_inaltime(int inaltime) { this->inaltime = inaltime; }
	inline void set_arie(double arie) { this->arie = arie; }

};

