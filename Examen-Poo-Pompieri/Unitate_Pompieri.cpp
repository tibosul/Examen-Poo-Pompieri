#include "Unitate_Pompieri.h"
#include "I_Angajat.h"
#include "I_Autospeciala.h"
#include "I_Urgenta.h"
#include "Interventie.h"
#include "Tura.h"
#include "Exceptions.h"

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
            throw InsufficientFirefightersException("Nu sunt suficienți pompieri disponibili");
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
            throw InsufficientVehiclesException("Nu sunt suficiente depărtătoare disponibile");
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
            throw InsufficientVehiclesException("Nu este suficientă pulbere disponibilă");
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
            throw InsufficientVehiclesException("Nu este suficientă spumă disponibilă");
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
    
    // Returnează pompierii
    for (auto* pompier : interventie->get_pompieri_mobilizati()) {
        tura.returneaza_pompier(pompier);
        interventie->returneaza_pompier(pompier);
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


