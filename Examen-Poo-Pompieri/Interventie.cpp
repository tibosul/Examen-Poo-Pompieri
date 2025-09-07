#include "Interventie.h"
#include "I_Urgenta.h"
#include "I_Angajat.h"
#include "I_Autospeciala.h"
#include <algorithm>

using Interventie_ID_Generator = Unique_ID_Generator<Interventie>;

Interventie::Interventie()
{
	this->id_unic = Interventie_ID_Generator::generate_next_id();
}

Interventie::Interventie(I_Urgenta* urgenta)
{
	this->id_unic = Interventie_ID_Generator::generate_next_id();
	this->urgenta_declansatoare = urgenta;
}

void Interventie::mobiliza_pompier(I_Angajat* pompier)
{
	if (pompier && this->activa) {
		this->pompieri_mobilizati.push_back(pompier);
	}
}

void Interventie::mobiliza_sofer(I_Angajat* sofer)
{
	if (sofer && this->activa) {
		this->soferi_mobilizati.push_back(sofer);
	}
}

void Interventie::mobiliza_autospeciala(I_Autospeciala* autospeciala)
{
	if (autospeciala && this->activa) {
		this->autospeciale_mobilizate.push_back(autospeciala);
	}
}

void Interventie::returneaza_pompier(I_Angajat* pompier)
{
	if (pompier) {
		auto it = std::find(this->pompieri_mobilizati.begin(), this->pompieri_mobilizati.end(), pompier);
		if (it != this->pompieri_mobilizati.end()) {
			this->pompieri_mobilizati.erase(it);
		}
	}
}

void Interventie::returneaza_sofer(I_Angajat* sofer)
{
	if (sofer) {
		auto it = std::find(this->soferi_mobilizati.begin(), this->soferi_mobilizati.end(), sofer);
		if (it != this->soferi_mobilizati.end()) {
			this->soferi_mobilizati.erase(it);
		}
	}
}

void Interventie::returneaza_autospeciala(I_Autospeciala* autospeciala)
{
	if (autospeciala) {
		auto it = std::find(this->autospeciale_mobilizate.begin(), this->autospeciale_mobilizate.end(), autospeciala);
		if (it != this->autospeciale_mobilizate.end()) {
			this->autospeciale_mobilizate.erase(it);
		}
	}
}

void Interventie::finalizeaza_interventia()
{
	this->activa = false;
	// Resursele rămân în intervenție pentru evidență, dar nu mai sunt active
}
