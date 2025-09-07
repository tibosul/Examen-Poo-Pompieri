#pragma once
#include "Autospeciala.h"

class Autospeciala_Descarcerare : public Autospeciala
{
protected:
	int numar_departatoare = 0;
	int numar_foarfece = 0;

public:
	Autospeciala_Descarcerare();
	Autospeciala_Descarcerare(int numar_departatoare, int numar_foarfece);
	virtual ~Autospeciala_Descarcerare() override = default;

	inline int get_numar_departatoare() const { return this->numar_departatoare; }
	inline int get_numar_foarfece() const { return this->numar_foarfece; }

	inline void set_numar_departatoare(int numar_departatoare) { this->numar_departatoare = numar_departatoare; }
	inline void set_numar_foarfece(int numar_foarfece) { this->numar_foarfece = numar_foarfece; }

};

