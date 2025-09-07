#include "Unitate_Pompieri.h"
#include "I_Angajat.h"
#include "I_Autospeciala.h"
#include "I_Urgenta.h"
#include "Interventie.h"
#include "Tura.h"
#include "Exceptions.h"
#include "Pompier.h"
#include "Sofer.h"
#include "Autoscara.h"
#include "Autospeciala_Descarcerare.h"
#include "Autospeciala_Stingere_Pulbere.h"
#include "Autospeciala_Stingere_Spuma.h"

Unitate_Pompieri& Unitate_Pompieri::get_instance()
{
    static Unitate_Pompieri instance;
    return instance;
}

void Unitate_Pompieri::add_angajat(I_Angajat* angajat)
{
    this->angajati[angajat->get_id()] = angajat;
}

void Unitate_Pompieri::add_autospeciala(I_Autospeciala* autospeciala)
{
    this->autospeciale[autospeciala->get_id()] = autospeciala;
}

void Unitate_Pompieri::add_interventie(Interventie* interventie)
{
    this->interventii[interventie->get_id()] = interventie;
}

void Unitate_Pompieri::add_urgenta(I_Urgenta* urgenta)
{
    this->urgente.push_back(urgenta);
}

Interventie* Unitate_Pompieri::mobilizeaza_resurse_pentru_urgenta(I_Urgenta* urgenta)
{
    if (!urgenta) {
        return nullptr;
    }

    // Creează intervenția
    Interventie* interventie = new Interventie(urgenta);
    
    // Mută pompierii necesari
    int pompieri_necesari = urgenta->get_numar_pompieri_necesari();
    if (pompieri_necesari > 0) {
        if (!tura.destui_pompieri(pompieri_necesari)) {
            throw InsufficientFirefightersException("Pas assez de pompiers disponibles");
        }
        
        auto pompieri_mutati = tura.muta_pompieri(pompieri_necesari);
        for (auto* pompier : pompieri_mutati) {
            interventie->mobiliza_pompier(pompier);
        }
    }
    
    // Mută autospecialele necesare
    std::vector<I_Autospeciala*> autospeciale_mutate;
    
    // Autoscari
    int autoscari_necesare = urgenta->get_autoscari_necesare();
    for (int i = 0; i < autoscari_necesare; i++) {
        auto* autoscara = tura.muta_autoscara();
        if (autoscara) {
            autospeciale_mutate.push_back(autoscara);
            interventie->mobiliza_autospeciala(autoscara);
        }
    }
    
    // Autospeciale de descarcerare
    int departatoare_necesare = urgenta->get_numar_departatoare_necesare();
    if (departatoare_necesare > 0) {
        if (!tura.destule_departatoare(departatoare_necesare)) {
            throw InsufficientVehiclesException("Pas assez d'écarteurs disponibles");
        }
        
        auto autospeciale_desc = tura.muta_autospeciale_descarcerare(1); // Minimum 1 vehicul
        for (auto* autospeciala : autospeciale_desc) {
            autospeciale_mutate.push_back(autospeciala);
            interventie->mobiliza_autospeciala(autospeciala);
        }
    }
    
    // Autospeciale de stingere cu pulbere
    double pulbere_necesara = urgenta->get_pulbere_necesara();
    if (pulbere_necesara > 0) {
        if (!tura.destula_pulbere(pulbere_necesara)) {
            throw InsufficientVehiclesException("Pas assez de poudre disponible");
        }
        
        auto autospeciale_pulbere = tura.muta_autospeciale_stingere_pulbere(pulbere_necesara);
        for (auto* autospeciala : autospeciale_pulbere) {
            autospeciale_mutate.push_back(autospeciala);
            interventie->mobiliza_autospeciala(autospeciala);
        }
    }
    
    // Autospeciale de stingere cu spumă
    double spuma_necesara = urgenta->get_spuma_necesara();
    if (spuma_necesara > 0) {
        if (!tura.destula_spuma(spuma_necesara)) {
            throw InsufficientVehiclesException("Pas assez de mousse disponible");
        }
        
        auto autospeciale_spuma = tura.muta_autospeciale_stingere_spuma(spuma_necesara);
        for (auto* autospeciala : autospeciale_spuma) {
            autospeciale_mutate.push_back(autospeciala);
            interventie->mobiliza_autospeciala(autospeciala);
        }
    }
    
    // Mută șoferii pentru autospeciale
    if (!autospeciale_mutate.empty()) {
        auto soferi_mutati = tura.muta_soferi_pentru_autospeciale(autospeciale_mutate);
        for (auto* sofer : soferi_mutati) {
            interventie->mobiliza_sofer(sofer);
        }
    }
    
    // Adaugă intervenția
    this->add_interventie(interventie);
    
    return interventie;
}

void Unitate_Pompieri::returneaza_resurse_din_interventie(Interventie* interventie)
{
    if (!interventie) return;
    
    // Returnează pompierii și incrementează experiența lor
    for (auto* angajat : interventie->get_pompieri_mobilizati()) {
        // Cast la Pompier pentru a accesa operatorul ++
        if (auto* pompier = dynamic_cast<Pompier*>(angajat)) {
            ++(*pompier); // Incrementează experiența pompierului
        }
        tura.returneaza_pompier(angajat);
        interventie->returneaza_pompier(angajat);
    }
    
    // Returnează șoferii
    for (auto* sofer : interventie->get_soferi_mobilizati()) {
        tura.returneaza_sofer(sofer);
        interventie->returneaza_sofer(sofer);
    }
    
    // Returnează autospecialele
    for (auto* autospeciala : interventie->get_autospeciale_mobilizate()) {
        // Determină tipul și returnează în containerul corespunzător
        // Pentru simplitate, returnează în toate containerele posibile
        tura.returneaza_autoscara(autospeciala);
        tura.returneaza_autospeciala_descarcerare(autospeciala);
        tura.returneaza_autospeciala_stingere_pulbere(autospeciala);
        tura.returneaza_autospeciala_stingere_spuma(autospeciala);
        
        interventie->returneaza_autospeciala(autospeciala);
    }
    
    // Finalizează intervenția
    interventie->finalizeaza_interventia();
}

void Unitate_Pompieri::incarca_date_din_fisier(const std::string& nume_fisier)
{
    std::ifstream fisier(nume_fisier);
    if (!fisier.is_open()) {
        throw FileNotFound("Impossible d'ouvrir le fichier : " + nume_fisier);
    }

    std::string linie;
    while (std::getline(fisier, linie)) {
        // Ignore les lignes vides et les commentaires
        if (linie.empty() || linie[0] == '#') {
            continue;
        }
        
        proceseaza_linie_fisier(linie);
    }
    
    fisier.close();
}

void Unitate_Pompieri::proceseaza_linie_fisier(const std::string& linie)
{
    std::istringstream iss(linie);
    std::string tip_obiect;
    
    if (!std::getline(iss, tip_obiect, '|')) {
        return; // Linie invalidă
    }
    
    // Elimină spațiile
    tip_obiect.erase(0, tip_obiect.find_first_not_of(" \t"));
    tip_obiect.erase(tip_obiect.find_last_not_of(" \t") + 1);
    
    if (tip_obiect == "Pompier") {
        std::string nume;
        int numar_interventii = 0;
        
        if (std::getline(iss, nume, ',')) {
            nume.erase(0, nume.find_first_not_of(" \t"));
            nume.erase(nume.find_last_not_of(" \t") + 1);
            
            std::string interventii_str;
            if (std::getline(iss, interventii_str)) {
                interventii_str.erase(0, interventii_str.find_first_not_of(" \t"));
                interventii_str.erase(interventii_str.find_last_not_of(" \t") + 1);
                numar_interventii = std::stoi(interventii_str);
            }
        }
        
        Pompier* pompier = new Pompier(nume, numar_interventii);
        this->add_angajat(pompier);
    }
    else if (tip_obiect == "Sofer") {
        std::string nume;
        if (std::getline(iss, nume)) {
            nume.erase(0, nume.find_first_not_of(" \t"));
            nume.erase(nume.find_last_not_of(" \t") + 1);
            
            Sofer* sofer = new Sofer(nume);
            this->add_angajat(sofer);
        }
    }
    else if (tip_obiect == "Autoscara") {
        std::string lungime_str;
        if (std::getline(iss, lungime_str)) {
            lungime_str.erase(0, lungime_str.find_first_not_of(" \t"));
            lungime_str.erase(lungime_str.find_last_not_of(" \t") + 1);
            double lungime = std::stod(lungime_str);
            
            Autoscara* autoscara = new Autoscara(lungime);
            this->add_autospeciala(autoscara);
        }
    }
    else if (tip_obiect == "Autospeciala_Descarcerare") {
        std::string departatoare_str, foarfece_str;
        if (std::getline(iss, departatoare_str, ',') && std::getline(iss, foarfece_str)) {
            departatoare_str.erase(0, departatoare_str.find_first_not_of(" \t"));
            departatoare_str.erase(departatoare_str.find_last_not_of(" \t") + 1);
            foarfece_str.erase(0, foarfece_str.find_first_not_of(" \t"));
            foarfece_str.erase(foarfece_str.find_last_not_of(" \t") + 1);
            
            int departatoare = std::stoi(departatoare_str);
            int foarfece = std::stoi(foarfece_str);
            
            Autospeciala_Descarcerare* autospeciala = new Autospeciala_Descarcerare(departatoare, foarfece);
            this->add_autospeciala(autospeciala);
        }
    }
    else if (tip_obiect == "Autospeciala_Stingere_Pulbere") {
        std::string capacitate_str;
        if (std::getline(iss, capacitate_str)) {
            capacitate_str.erase(0, capacitate_str.find_first_not_of(" \t"));
            capacitate_str.erase(capacitate_str.find_last_not_of(" \t") + 1);
            double capacitate = std::stod(capacitate_str);
            
            Autospeciala_Stingere_Pulbere* autospeciala = new Autospeciala_Stingere_Pulbere(capacitate);
            this->add_autospeciala(autospeciala);
        }
    }
    else if (tip_obiect == "Autospeciala_Stingere_Spuma") {
        std::string capacitate_str;
        if (std::getline(iss, capacitate_str)) {
            capacitate_str.erase(0, capacitate_str.find_first_not_of(" \t"));
            capacitate_str.erase(capacitate_str.find_last_not_of(" \t") + 1);
            double capacitate = std::stod(capacitate_str);
            
            Autospeciala_Stingere_Spuma* autospeciala = new Autospeciala_Stingere_Spuma(capacitate);
            this->add_autospeciala(autospeciala);
        }
    }
}


