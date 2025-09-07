#include <iostream>
#include <memory>
#include "Unitate_Pompieri.h"
#include "Tura.h"
#include "Interventie.h"
#include "Incendiu_Electric.h"
#include "Incendiu_Vegetatie.h"
#include "Accident.h"
#include "Autoscara.h"
#include "Autospeciala_Descarcerare.h"
#include "Autospeciala_Stingere_Pulbere.h"
#include "Autospeciala_Stingere_Spuma.h"
#include "Pompier.h"
#include "Sofer.h"


int main()
{
    try {
        std::cout << "=== UNITATEA DE POMPIERI - DEMONSTRAȚIE ===\n\n";

        // Obține instanța unității de pompieri
        Unitate_Pompieri& unitate = Unitate_Pompieri::get_instance();
        
        // Încarcă datele din fișier
        std::cout << "1. Încărcarea datelor din fișier...\n";
        unitate.incarca_date_din_fisier("Unitate_Pompieri.txt");
        std::cout << "   ✓ Datele au fost încărcate cu succes!\n\n";

        // Obține instanța turii și adaugă resurse manual
        Tura& tura = Tura::get_instance();
        
        // Adaugă pompieri în tură (din unitate)
        std::cout << "2. Popularea turii cu resurse...\n";
        
        // Pentru demonstrație, adăugăm primii 3 pompieri și primii 2 șoferi
        // În realitate, ai putea avea o logică mai complexă pentru selectarea resurselor
        
        // Adaugă pompieri în tură
        tura.add_pompier(new Pompier("Ion Popescu", 10));
        tura.add_pompier(new Pompier("Maria Ionescu", 5));
        tura.add_pompier(new Pompier("Gheorghe Dumitrescu", 15));
        
        // Adaugă șoferi în tură
        tura.add_sofer(new Sofer("Vasile Petrescu"));
        tura.add_sofer(new Sofer("Elena Georgescu"));
        
        // Adaugă autospeciale în tură
        tura.add_autoscara(new Autoscara(25.5));
        tura.add_autospeciala_descarcerare(new Autospeciala_Descarcerare(2, 1));
        tura.add_autospeciala_stingere_pulbere(new Autospeciala_Stingere_Pulbere(500.0));
        tura.add_autospeciala_stingere_spuma(new Autospeciala_Stingere_Spuma(400.0));
        
        std::cout << "   ✓ Tura a fost populată cu resurse!\n\n";

        // Creează urgențe pentru testare
        std::cout << "3. Crearea urgențelor pentru testare...\n";
        
        I_Urgenta_Factory factory_urgente;
        
        // Accident rutier
        I_Urgenta* accident = factory_urgente.create_new_Accident("Strada Principală, nr. 15", 2, 3);
        std::cout << "   ✓ Accident creat: " << accident->get_adresa() 
                  << " - " << accident->get_numar_victime() << " victime, " 
                  << accident->get_numar_vehicule() << " vehicule\n";
        
        // Incendiu de vegetație
        I_Urgenta* incendiu_veg = factory_urgente.create_new_Incendiu_Vegetatie("Pădurea Comunală", 0, 5, 100.0);
        std::cout << "   ✓ Incendiu de vegetație creat: " << incendiu_veg->get_adresa() 
                  << " - înălțime: " << incendiu_veg->get_inaltime() << "m, "
                  << "arie: " << incendiu_veg->get_arie() << "m²\n";
        
        // Incendiu electric
        I_Urgenta* incendiu_el = factory_urgente.create_new_Incendiu_Electric("Fabrica ABC", 1, 15, 200.0);
        std::cout << "   ✓ Incendiu electric creat: " << incendiu_el->get_adresa() 
                  << " - înălțime: " << incendiu_el->get_inaltime() << "m, "
                  << "arie: " << incendiu_el->get_arie() << "m²\n\n";

        // Demonstrează mobilizarea resurselor
        std::cout << "4. Mobilizarea resurselor pentru accident...\n";
        Interventie* interventie_accident = unitate.mobilizeaza_resurse_pentru_urgenta(accident);
        std::cout << "   ✓ Intervenție creată cu ID: " << interventie_accident->get_id() << "\n";
        std::cout << "   ✓ Pompieri mobilizați: " << interventie_accident->get_pompieri_mobilizati().size() << "\n";
        std::cout << "   ✓ Șoferi mobilizați: " << interventie_accident->get_soferi_mobilizati().size() << "\n";
        std::cout << "   ✓ Autospeciale mobilizate: " << interventie_accident->get_autospeciale_mobilizate().size() << "\n\n";

        // Demonstrează mobilizarea pentru incendiu
        std::cout << "5. Mobilizarea resurselor pentru incendiu de vegetație...\n";
        Interventie* interventie_incendiu = unitate.mobilizeaza_resurse_pentru_urgenta(incendiu_veg);
        std::cout << "   ✓ Intervenție creată cu ID: " << interventie_incendiu->get_id() << "\n";
        std::cout << "   ✓ Pompieri mobilizați: " << interventie_incendiu->get_pompieri_mobilizati().size() << "\n";
        std::cout << "   ✓ Șoferi mobilizați: " << interventie_incendiu->get_soferi_mobilizati().size() << "\n";
        std::cout << "   ✓ Autospeciale mobilizate: " << interventie_incendiu->get_autospeciale_mobilizate().size() << "\n\n";

        // Demonstrează operatorul ++
        std::cout << "6. Demonstrarea operatorului ++ pentru pompieri...\n";
        for (auto* pompier_ptr : interventie_accident->get_pompieri_mobilizati()) {
            if (auto* pompier = dynamic_cast<Pompier*>(pompier_ptr)) {
                std::cout << "   Pompier " << pompier->get_nume() 
                          << " - experiență înainte: " << pompier->get_numar_interventii();
                ++(*pompier);
                std::cout << ", după: " << pompier->get_numar_interventii() << "\n";
            }
        }
        std::cout << "\n";

        // Finalizează intervențiile și returnează resursele
        std::cout << "7. Finalizarea intervențiilor și returnarea resurselor...\n";
        unitate.returneaza_resurse_din_interventie(interventie_accident);
        std::cout << "   ✓ Intervenția " << interventie_accident->get_id() << " finalizată\n";
        
        unitate.returneaza_resurse_din_interventie(interventie_incendiu);
        std::cout << "   ✓ Intervenția " << interventie_incendiu->get_id() << " finalizată\n\n";

        // Demonstrează tratarea excepțiilor
        std::cout << "8. Testarea tratării excepțiilor...\n";
        try {
            // Încearcă să mobilizeze resurse pentru un incendiu mare (care ar putea să nu aibă resurse suficiente)
            I_Urgenta* incendiu_mare = factory_urgente.create_new_Incendiu_Electric("Clădire înaltă", 5, 50, 1000.0);
            Interventie* interventie_mare = unitate.mobilizeaza_resurse_pentru_urgenta(incendiu_mare);
            std::cout << "   ✓ Intervenția pentru incendiu mare a fost creată cu succes!\n";
        }
        catch (const InsufficientFirefightersException& e) {
            std::cout << "   ⚠ Excepție prinsă: " << e.get_message() << " (cod: " << e.get_code() << ")\n";
        }
        catch (const InsufficientVehiclesException& e) {
            std::cout << "   ⚠ Excepție prinsă: " << e.get_message() << " (cod: " << e.get_code() << ")\n";
        }
        catch (const std::exception& e) {
            std::cout << "   ⚠ Excepție generală: " << e.what() << "\n";
        }

        std::cout << "\n=== DEMONSTRAȚIA S-A FINALIZAT CU SUCCES! ===\n";
        std::cout << "Toate funcționalitățile au fost testate:\n";
        std::cout << "✓ Încărcarea datelor din fișier\n";
        std::cout << "✓ Popularea turii cu resurse\n";
        std::cout << "✓ Crearea urgențelor\n";
        std::cout << "✓ Mobilizarea resurselor\n";
        std::cout << "✓ Supraîncărcarea operatorului ++\n";
        std::cout << "✓ Returnarea resurselor\n";
        std::cout << "✓ Tratarea excepțiilor\n";

    }
    catch (const std::exception& e) {
        std::cerr << "Eroare în aplicație: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}