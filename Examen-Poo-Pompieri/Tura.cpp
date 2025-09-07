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

// Metode pentru mutarea resurselor din tură
std::vector<I_Angajat*> Tura::muta_pompieri(int numar_necesar)
{
	std::vector<I_Angajat*> pompieri_mutati;
	
	if (numar_necesar > 0 && this->pompieri_disponibili.size() >= static_cast<size_t>(numar_necesar)) {
		int mutati = 0;
		for (auto& pair : this->pompieri_disponibili) {
			if (mutati >= numar_necesar) break;
			pompieri_mutati.push_back(pair.second);
			this->pompieri_disponibili.erase(pair.first);
			mutati++;
		}
	}
	
	return pompieri_mutati;
}

std::vector<I_Angajat*> Tura::muta_soferi_pentru_autospeciale(const std::vector<I_Autospeciala*>& autospeciale)
{
	std::vector<I_Angajat*> soferi_mutati;
	
	for (auto* autospeciala : autospeciale) {
		// Găsește un șofer disponibil
		for (auto& pair : this->soferi_disponibili) {
			soferi_mutati.push_back(pair.second);
			this->soferi_disponibili.erase(pair.first);
			break; // Un șofer per vehicul
		}
	}
	
	return soferi_mutati;
}

I_Autospeciala* Tura::muta_autoscara()
{
	if (!this->autoscari_disponibile.empty()) {
		auto it = this->autoscari_disponibile.begin();
		I_Autospeciala* autoscara = it->second;
		this->autoscari_disponibile.erase(it);
		return autoscara;
	}
	return nullptr;
}

std::vector<I_Autospeciala*> Tura::muta_autospeciale_descarcerare(int numar_necesar)
{
	std::vector<I_Autospeciala*> autospeciale_mutate;
	
	if (numar_necesar > 0 && this->autospeciale_descarcerare_disponibile.size() >= static_cast<size_t>(numar_necesar)) {
		int mutate = 0;
		for (auto& pair : this->autospeciale_descarcerare_disponibile) {
			if (mutate >= numar_necesar) break;
			autospeciale_mutate.push_back(pair.second);
			this->autospeciale_descarcerare_disponibile.erase(pair.first);
			mutate++;
		}
	}
	
	return autospeciale_mutate;
}

std::vector<I_Autospeciala*> Tura::muta_autospeciale_stingere_pulbere(double cantitate_necesara)
{
	std::vector<I_Autospeciala*> autospeciale_mutate;
	double cantitate_mutata = 0.0;
	
	for (auto& pair : this->autospeciale_stingere_pulbere_disponibile) {
		if (cantitate_mutata >= cantitate_necesara) break;
		
		autospeciale_mutate.push_back(pair.second);
		cantitate_mutata += pair.second->get_capacitate_material();
		this->autospeciale_stingere_pulbere_disponibile.erase(pair.first);
	}
	
	return autospeciale_mutate;
}

std::vector<I_Autospeciala*> Tura::muta_autospeciale_stingere_spuma(double cantitate_necesara)
{
	std::vector<I_Autospeciala*> autospeciale_mutate;
	double cantitate_mutata = 0.0;
	
	for (auto& pair : this->autospeciale_stingere_spuma_disponibile) {
		if (cantitate_mutata >= cantitate_necesara) break;
		
		autospeciale_mutate.push_back(pair.second);
		cantitate_mutata += pair.second->get_capacitate_material();
		this->autospeciale_stingere_spuma_disponibile.erase(pair.first);
	}
	
	return autospeciale_mutate;
}

// Metode pentru returnarea resurselor în tură
void Tura::returneaza_pompier(I_Angajat* pompier)
{
	if (pompier) {
		this->pompieri_disponibili[pompier->get_id()] = pompier;
	}
}

void Tura::returneaza_sofer(I_Angajat* sofer)
{
	if (sofer) {
		this->soferi_disponibili[sofer->get_id()] = sofer;
	}
}

void Tura::returneaza_autoscara(I_Autospeciala* autoscara)
{
	if (autoscara) {
		this->autoscari_disponibile[autoscara->get_id()] = autoscara;
	}
}

void Tura::returneaza_autospeciala_descarcerare(I_Autospeciala* autospeciala)
{
	if (autospeciala) {
		this->autospeciale_descarcerare_disponibile[autospeciala->get_id()] = autospeciala;
	}
}

void Tura::returneaza_autospeciala_stingere_pulbere(I_Autospeciala* autospeciala)
{
	if (autospeciala) {
		this->autospeciale_stingere_pulbere_disponibile[autospeciala->get_id()] = autospeciala;
	}
}

void Tura::returneaza_autospeciala_stingere_spuma(I_Autospeciala* autospeciala)
{
	if (autospeciala) {
		this->autospeciale_stingere_spuma_disponibile[autospeciala->get_id()] = autospeciala;
	}
}





