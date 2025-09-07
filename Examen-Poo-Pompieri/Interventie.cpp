#include "Interventie.h"

using Interventie_ID_Generator = Unique_ID_Generator<Interventie>;

Interventie::Interventie()
{
	this->id_unic = Interventie_ID_Generator::generate_next_id();
}

Interventie::Interventie(int numar_departatoare_necesare, int numar_foarfece_necesare, double pulbere_necesara, double spuma_necesara, int autoscari_necesare, int numar_pompieri_necesari)
{
	this->id_unic = Interventie_ID_Generator::generate_next_id();
	this->numar_departatoare_necesare = numar_departatoare_necesare;
	this->numar_foarfece_necesare = numar_foarfece_necesare;
	this->pulbere_necesara = pulbere_necesara;
	this->spuma_necesara = spuma_necesara;
	this->autoscari_necesare = autoscari_necesare;
	this->numar_pompieri_necesari = numar_pompieri_necesari;
}
