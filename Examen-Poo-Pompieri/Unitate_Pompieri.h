#pragma once
#include "Tura.h"
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


class I_Angajat;
class I_Autospeciala;
class Interventie;
class I_Urgenta;

class Unitate_Pompieri
{
protected:
	Unitate_Pompieri() = default;
	Unitate_Pompieri(const Unitate_Pompieri&) = delete;
	Unitate_Pompieri& operator=(const Unitate_Pompieri&) = delete;
	Unitate_Pompieri(Unitate_Pompieri&&) = delete;
	Unitate_Pompieri& operator=(Unitate_Pompieri&&) = delete;
	~Unitate_Pompieri() = default;

	std::map<int, I_Angajat*> angajati;
	std::map<int, I_Autospeciala*> autospeciale;
	std::map<int, Interventie*> interventii;
	std::vector<I_Urgenta*> urgente;

	std::vector<std::pair<int, int>> soferi_autospeciale;
	std::map<int, int> autospeciala_sofer; // -1 pour conducteur si véhicule spécial n'a pas de conducteur à un moment donné

	Tura& tura = Tura::get_instance();



public:
	static Unitate_Pompieri& get_instance();

	void add_angajat(I_Angajat* angajat);
	void add_autospeciala(I_Autospeciala* autospeciala);
	void add_interventie(Interventie* interventie);
	void add_urgenta(I_Urgenta* urgenta);

	// Metoda principală de mobilizare
	Interventie* mobilizeaza_resurse_pentru_urgenta(I_Urgenta* urgenta);
	
	// Metode pentru returnarea resurselor
	void returneaza_resurse_din_interventie(Interventie* interventie);

	// Metode pentru încărcarea datelor din fișier
	void incarca_date_din_fisier(const std::string& nume_fisier);
	void proceseaza_linie_fisier(const std::string& linie);
};

