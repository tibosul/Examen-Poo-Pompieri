#pragma once
#include <set>
#include <vector>
#include <map>

class I_Angajat;
class I_Autospeciala;

class Tura
{
protected:

	Tura() = default;
	Tura(const Tura&) = delete;
	Tura& operator=(const Tura&) = delete;
	~Tura() = default;

	std::map<int, I_Angajat*> pompieri_disponibili;
	std::map<int, I_Angajat*> soferi_disponibili;

	std::map<int, I_Autospeciala*> autoscari_disponibile;
	std::map<int, I_Autospeciala*> autospeciale_descarcerare_disponibile;
	std::map<int, I_Autospeciala*> autospeciale_stingere_pulbere_disponibile;
	std::map<int, I_Autospeciala*> autospeciale_stingere_spuma_disponibile;

public:
	static Tura& get_instance();

	void add_pompier(I_Angajat* pompier);
	void add_sofer(I_Angajat* sofer);

	void remove_pompier(I_Angajat* pompier);
	void remove_sofer(I_Angajat* sofer);

	void add_autoscara(I_Autospeciala* autoscara);
	void add_autospeciala_descarcerare(I_Autospeciala* autospeciala);
	void add_autospeciala_stingere_pulbere(I_Autospeciala* autospeciala);
	void add_autospeciala_stingere_spuma(I_Autospeciala* autospeciala);

	void remove_autoscara(I_Autospeciala* autoscara);
	void remove_autospeciala_descarcerare(I_Autospeciala* autospeciala);
	void remove_autospeciala_stingere_pulbere(I_Autospeciala* autospeciala);
	void remove_autospeciala_stingere_spuma(I_Autospeciala* autospeciala);

	bool destule_departatoare(int departatoare_necesare);
	bool destule_foarfece(int foarfece_necesare);
	bool destula_pulbere(double pulbere_necesara);
	bool destula_spuma(double spuma_necesara);
	bool destule_autoscari(int autoscari_necesare);
	bool destui_pompieri(int pompieri_necesari);

	// Metode pentru mutarea resurselor din tură
	std::vector<I_Angajat*> muta_pompieri(int numar_necesar);
	std::vector<I_Angajat*> muta_soferi_pentru_autospeciale(const std::vector<I_Autospeciala*>& autospeciale);
	
	// Mutare autospeciale specifice
	I_Autospeciala* muta_autoscara();
	std::vector<I_Autospeciala*> muta_autospeciale_descarcerare(int numar_necesar);
	std::vector<I_Autospeciala*> muta_autospeciale_stingere_pulbere(double cantitate_necesara);
	std::vector<I_Autospeciala*> muta_autospeciale_stingere_spuma(double cantitate_necesara);

	// Metode pentru returnarea resurselor în tură
	void returneaza_pompier(I_Angajat* pompier);
	void returneaza_sofer(I_Angajat* sofer);
	void returneaza_autoscara(I_Autospeciala* autoscara);
	void returneaza_autospeciala_descarcerare(I_Autospeciala* autospeciala);
	void returneaza_autospeciala_stingere_pulbere(I_Autospeciala* autospeciala);
	void returneaza_autospeciala_stingere_spuma(I_Autospeciala* autospeciala);
};

