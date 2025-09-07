#pragma once
#include "I_Urgenta.h"
#include <string>

class Urgenta : public I_Urgenta
{
protected:
	std::string adresa;
	int numar_victime = 0;

public:
	Urgenta();
	Urgenta(const std::string& adresa, int numar_victime);
	virtual ~Urgenta() override = default;

	inline const std::string& get_adresa() const { return this->adresa; }
	inline int get_numar_victime() const { return this->numar_victime; }

	inline void set_adresa(const std::string& adresa) { this->adresa = adresa; }
	inline void set_numar_victime(int numar_victime) { this->numar_victime = numar_victime; }
};

