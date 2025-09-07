#pragma once
#include "Unique_ID_Generator.h"
#include <vector>

class I_Urgenta;
class I_Angajat;
class I_Autospeciala;

class Interventie
{
protected:
	I_Urgenta* urgenta_declansatoare = nullptr;
	int id_unic = 0;

	// Resursele mobilizate efectiv
	std::vector<I_Angajat*> pompieri_mobilizati;
	std::vector<I_Angajat*> soferi_mobilizati;
	std::vector<I_Autospeciala*> autospeciale_mobilizate;

	bool activa = true;

public:
	Interventie();
	Interventie(I_Urgenta* urgenta);
	~Interventie() = default;

	// Getters pentru urgență și resurse
	inline int get_id() const { return this->id_unic; }
	inline I_Urgenta* get_urgenta() const { return this->urgenta_declansatoare; }
	inline bool este_activa() const { return this->activa; }

	// Getters pentru resursele mobilizate
	inline const std::vector<I_Angajat*>& get_pompieri_mobilizati() const { return this->pompieri_mobilizati; }
	inline const std::vector<I_Angajat*>& get_soferi_mobilizati() const { return this->soferi_mobilizati; }
	inline const std::vector<I_Autospeciala*>& get_autospeciale_mobilizate() const { return this->autospeciale_mobilizate; }

	// Metode pentru mobilizarea resurselor
	void mobiliza_pompier(I_Angajat* pompier);
	void mobiliza_sofer(I_Angajat* sofer);
	void mobiliza_autospeciala(I_Autospeciala* autospeciala);

	// Metode pentru returnarea resurselor
	void returneaza_pompier(I_Angajat* pompier);
	void returneaza_sofer(I_Angajat* sofer);
	void returneaza_autospeciala(I_Autospeciala* autospeciala);

	// Finalizare intervenție
	void finalizeaza_interventia();
};

