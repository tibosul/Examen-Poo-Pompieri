#pragma once
#include "Unique_ID_Generator.h"

class I_Urgenta;

class Interventie
{
protected:

	I_Urgenta* urgenta_declansatoare = nullptr;
	int id_unic = 0;

	int numar_departatoare_necesare = 0;
	int numar_foarfece_necesare = 0;

	double pulbere_necesara = 0.0;
	double spuma_necesara = 0.0;
	int autoscari_necesare = 0;

	int numar_pompieri_necesari = 0;

public:
	Interventie();
	Interventie(int numar_departatoare_necesare, int numar_foarfece_necesare, double pulbere_necesara, double spuma_necesara, int autoscari_necesare, int numar_pompieri_necesari);
	~Interventie() = default;

	inline int get_id() const { return this->id_unic; }
	inline int get_numar_departatoare_necesare() const { return this->numar_departatoare_necesare; }
	inline int get_numar_foarfece_necesare() const { return this->numar_foarfece_necesare; }
	inline double get_pulbere_necesara() const { return this->pulbere_necesara; }
	inline double get_spuma_necesara() const { return this->spuma_necesara; }
	inline int get_autoscari_necesare() const { return this->autoscari_necesare; }
	inline int get_numar_pompieri_necesari() const { return this->numar_pompieri_necesari; }

	inline void set_id(int id) { this->id_unic = id; }
	inline void set_numar_departatoare_necesare(int numar_departatoare_necesare) { this->numar_departatoare_necesare = numar_departatoare_necesare; }
	inline void set_numar_foarfece_necesare(int numar_foarfece_necesare) { this->numar_foarfece_necesare = numar_foarfece_necesare; }
	inline void set_pulbere_necesara(double pulbere_necesara) { this->pulbere_necesara = pulbere_necesara; }
	inline void set_spuma_necesara(double spuma_necesara) { this->spuma_necesara = spuma_necesara; }
	inline void set_autoscari_necesare(int autoscari_necesare) { this->autoscari_necesare = autoscari_necesare; }
	inline void set_numar_pompieri_necesari(int numar_pompieri_necesari) { this->numar_pompieri_necesari = numar_pompieri_necesari; }
};

