#pragma once

class I_Autospeciala
{
public:
	I_Autospeciala() = default;
	virtual ~I_Autospeciala() = default;

	virtual inline int get_id() const = 0;
	virtual inline void set_id(int id) = 0;

	virtual inline double get_lungime_scara() const = 0;
	virtual inline void set_lungime_scara(double lungime_scara) = 0;

	virtual inline int get_numar_departatoare() const = 0;
	virtual inline int get_numar_foarfece() const = 0;
	virtual inline void set_numar_departatoare(int numar_departatoare) = 0;
	virtual inline void set_numar_foarfece(int numar_foarfece) = 0;

	virtual inline double get_capacitate_material() const = 0;
	virtual inline void set_capacitate_material(double capacitate_material) = 0;
};

class I_Autospeciala_Factory
{
	I_Autospeciala* create_new_Autoscara();
	I_Autospeciala* create_new_Autoscara(double lungime_scara);

	I_Autospeciala* create_new_Autospeciala_Descarcerare();
	I_Autospeciala* create_new_Autospeciala_Descarcerare(int numar_departatoare, int numar_foarfece);

	I_Autospeciala* create_new_Autospeciala_Stingere_Pulbere();
	I_Autospeciala* create_new_Autospeciala_Stingere_Pulbere(double cantitate_material);

	I_Autospeciala* create_new_Autospeciala_Stingere_Spuma();
	I_Autospeciala* create_new_Autospeciala_Stingere_Spuma(double cantitate_material);
};