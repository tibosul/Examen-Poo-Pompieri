#include "Tura.h"
#include "I_Angajat.h"
#include "I_Autospeciala.h"

Tura& Tura::get_instance()
{
	static Tura instance;
	return instance;
}

void Tura::add_pompier(I_Angajat* pompier)
{
	this->pompieri_disponibili[pompier->get_id()] = pompier;
}

void Tura::add_sofer(I_Angajat* sofer)
{
	this->soferi_disponibili[sofer->get_id()] = sofer;
}

void Tura::remove_pompier(I_Angajat* pompier)
{
	this->pompieri_disponibili.erase(pompier->get_id());
}

void Tura::remove_sofer(I_Angajat* sofer)
{
	this->soferi_disponibili.erase(sofer->get_id());
}

void Tura::add_autoscara(I_Autospeciala* autoscara)
{
	this->autoscari_disponibile[autoscara->get_id()] = autoscara;
}

void Tura::add_autospeciala_descarcerare(I_Autospeciala* autospeciala)
{
	this->autospeciale_descarcerare_disponibile[autospeciala->get_id()] = autospeciala;
}

void Tura::add_autospeciala_stingere_pulbere(I_Autospeciala* autospeciala)
{
	this->autospeciale_stingere_pulbere_disponibile[autospeciala->get_id()] = autospeciala;
}

void Tura::add_autospeciala_stingere_spuma(I_Autospeciala* autospeciala)
{
	this->autospeciale_stingere_spuma_disponibile[autospeciala->get_id()] = autospeciala;
}

void Tura::remove_autoscara(I_Autospeciala* autoscara)
{
	this->autoscari_disponibile.erase(autoscara->get_id());
}

void Tura::remove_autospeciala_descarcerare(I_Autospeciala* autospeciala)
{
	this->autospeciale_descarcerare_disponibile.erase(autospeciala->get_id());
}

void Tura::remove_autospeciala_stingere_pulbere(I_Autospeciala* autospeciala)
{
	this->autospeciale_stingere_pulbere_disponibile.erase(autospeciala->get_id());
}

void Tura::remove_autospeciala_stingere_spuma(I_Autospeciala* autospeciala)
{
	this->autospeciale_stingere_spuma_disponibile.erase(autospeciala->get_id());
}

bool Tura::destule_departatoare(int departatoare_necesare)
{
	int total_departatoare = 0;
	for (const auto& pair : this->autospeciale_descarcerare_disponibile)
	{
		total_departatoare += pair.second->get_numar_departatoare();
		if (total_departatoare >= departatoare_necesare)
			return true;
	}
	return false;
}

bool Tura::destule_foarfece(int foarfece_necesare)
{
	int total_foarfece = 0;
	for (const auto& pair : this->autospeciale_descarcerare_disponibile)
	{
		total_foarfece += pair.second->get_numar_foarfece();
		if (total_foarfece >= foarfece_necesare)
			return true;
	}
	return false;
}

bool Tura::destula_pulbere(double pulbere_necesara)
{
	double total_pulbere = 0.0;
	for (const auto& pair : this->autospeciale_stingere_pulbere_disponibile)
	{
		total_pulbere += pair.second->get_capacitate_material();
		if (total_pulbere >= pulbere_necesara)
			return true;
	}
	return false;
}

bool Tura::destula_spuma(double spuma_necesara)
{
	double total_spuma = 0.0;
	for (const auto& pair : this->autospeciale_stingere_spuma_disponibile)
	{
		total_spuma += pair.second->get_capacitate_material();
		if (total_spuma >= spuma_necesara)
			return true;
	}
	return false;
}

bool Tura::destule_autoscari(int autoscari_necesare)
{
	return this->autoscari_disponibile.size() >= static_cast<size_t>(autoscari_necesare);
}

bool Tura::destui_pompieri(int pompieri_necesari)
{
	return this->pompieri_disponibili.size() >= static_cast<size_t>(pompieri_necesari);
}





