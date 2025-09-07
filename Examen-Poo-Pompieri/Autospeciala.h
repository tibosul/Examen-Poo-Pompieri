#pragma once
#include "I_Autospeciala.h"
#include "Unique_ID_Generator.h"
#include "Exceptions.h"

class Autospeciala : public I_Autospeciala
{
protected:
	int id_unic = 0;

public:
	Autospeciala();
	virtual ~Autospeciala() override = default;

	virtual inline int get_id() const override { return this->id_unic; }
	virtual inline void set_id(int id) override { this->id_unic = id; }

	virtual inline double get_lungime_scara() const { throw Wrong_Autospeciala_Type("Nu e autoscara"); }
	virtual inline void set_lungime_scara(double lungime_scara) { throw Wrong_Autospeciala_Type("Nu e autoscara"); }

	virtual inline int get_numar_departatoare() const override { throw Wrong_Autospeciala_Type("Nu e autospeciala de descarcerare"); }
	virtual inline int get_numar_foarfece() const override { throw Wrong_Autospeciala_Type("Nu e autospeciala de descarcerare"); }
	virtual inline void set_numar_departatoare(int numar_departatoare) override { throw Wrong_Autospeciala_Type("Nu e autospeciala de descarcerare"); }
	virtual inline void set_numar_foarfece(int numar_foarfece) override { throw Wrong_Autospeciala_Type("Nu e autospeciala de descarcerare"); }

	virtual inline double get_capacitate_material() const override { throw Wrong_Autospeciala_Type("Nu e autospeciala de stingere"); }
	virtual inline void set_capacitate_material(double capacitate_material) override { throw Wrong_Autospeciala_Type("Nu e autospeciala de stingere"); }
};

