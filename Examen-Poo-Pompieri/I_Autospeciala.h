#pragma once

class I_Autospeciala
{
public:
	I_Autospeciala() = default;
	virtual ~I_Autospeciala() = default;
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