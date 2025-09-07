#pragma once
#include "I_Urgenta.h"
#include "Exceptions.h"

class Urgenta : public I_Urgenta
{
protected:
	std::string adresa;
	int numar_victime = 0;

	int numar_departatoare_necesare = 0;
	int numar_foarfece_necesare = 0;

	double pulbere_necesara = 0.0;
	double spuma_necesara = 0.0;
	int autoscari_necesare = 0;

	int numar_pompieri_necesari = 0;

public:
	Urgenta();
	Urgenta(const std::string& adresa, int numar_victime);
	virtual ~Urgenta() override = default;

	virtual inline const std::string& get_adresa() const override { return this->adresa; }
	virtual inline int get_numar_victime() const override { return this->numar_victime; }

	virtual inline void set_adresa(const std::string& adresa) override { this->adresa = adresa; }
	virtual inline void set_numar_victime(int numar_victime) override { this->numar_victime = numar_victime; }

	virtual inline int get_numar_vehicule() const override { throw Wrong_Urgenta_Type("Nu e accident"); }
	virtual inline void set_numar_vehicule(int numar_vehicule) override { throw Wrong_Urgenta_Type("Nu e accident"); }

	virtual inline int get_inaltime() const { throw Wrong_Urgenta_Type("Nu e incendiu"); }
	virtual inline double get_arie() const { throw Wrong_Urgenta_Type("Nu e incendiu"); }

	virtual inline void set_inaltime(int inaltime) { throw Wrong_Urgenta_Type("Nu e incendiu"); }
	virtual inline void set_arie(double arie) { throw Wrong_Urgenta_Type("Nu e incendiu"); }

};

