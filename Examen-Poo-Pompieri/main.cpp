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
        std::cout << "=== UNITÉ DE POMPIERS - DÉMONSTRATION ===\n\n";

        // Obtient l'instance de l'unité de pompiers
        Unitate_Pompieri& unitate = Unitate_Pompieri::get_instance();
        
        // Charge les données depuis le fichier
        std::cout << "1. Chargement des données depuis le fichier...\n";
        unitate.incarca_date_din_fisier("Unitate_Pompieri.txt");
        std::cout << "   ✓ Les données ont été chargées avec succès !\n\n";

        // Obtient l'instance du tour et ajoute des ressources manuellement
        Tura& tura = Tura::get_instance();
        
        // Ajoute des pompiers au tour (depuis l'unité)
        std::cout << "2. Population du tour avec des ressources...\n";
        
        // Pour la démonstration, nous ajoutons les 3 premiers pompiers et les 2 premiers conducteurs
        // En réalité, vous pourriez avoir une logique plus complexe pour la sélection des ressources
        
        // Ajoute des pompiers au tour
        tura.add_pompier(new Pompier("Ion Popescu", 10));
        tura.add_pompier(new Pompier("Maria Ionescu", 5));
        tura.add_pompier(new Pompier("Gheorghe Dumitrescu", 15));
        
        // Ajoute des conducteurs au tour
        tura.add_sofer(new Sofer("Vasile Petrescu"));
        tura.add_sofer(new Sofer("Elena Georgescu"));
        
        // Ajoute des véhicules spéciaux au tour
        tura.add_autoscara(new Autoscara(25.5));
        tura.add_autospeciala_descarcerare(new Autospeciala_Descarcerare(2, 1));
        tura.add_autospeciala_stingere_pulbere(new Autospeciala_Stingere_Pulbere(500.0));
        tura.add_autospeciala_stingere_spuma(new Autospeciala_Stingere_Spuma(400.0));
        
        std::cout << "   ✓ Le tour a été populé avec des ressources !\n\n";

        // Crée des urgences pour les tests
        std::cout << "3. Création d'urgences pour les tests...\n";
        
        I_Urgenta_Factory factory_urgente;
        
        // Accident routier
        I_Urgenta* accident = factory_urgente.create_new_Accident("Rue Principale, n° 15", 2, 3);
        std::cout << "   ✓ Accident créé : " << accident->get_adresa() 
                  << " - " << accident->get_numar_victime() << " victimes, " 
                  << accident->get_numar_vehicule() << " véhicules\n";
        
        // Incendie de végétation
        I_Urgenta* incendiu_veg = factory_urgente.create_new_Incendiu_Vegetatie("Forêt Communale", 0, 5, 100.0);
        std::cout << "   ✓ Incendie de végétation créé : " << incendiu_veg->get_adresa() 
                  << " - hauteur : " << incendiu_veg->get_inaltime() << "m, "
                  << "superficie : " << incendiu_veg->get_arie() << "m²\n";
        
        // Incendie électrique
        I_Urgenta* incendiu_el = factory_urgente.create_new_Incendiu_Electric("Usine ABC", 1, 15, 200.0);
        std::cout << "   ✓ Incendie électrique créé : " << incendiu_el->get_adresa() 
                  << " - hauteur : " << incendiu_el->get_inaltime() << "m, "
                  << "superficie : " << incendiu_el->get_arie() << "m²\n\n";

        // Démontre la mobilisation des ressources
        std::cout << "4. Mobilisation des ressources pour l'accident...\n";
        Interventie* interventie_accident = unitate.mobilizeaza_resurse_pentru_urgenta(accident);
        std::cout << "   ✓ Intervention créée avec ID : " << interventie_accident->get_id() << "\n";
        std::cout << "   ✓ Pompiers mobilisés : " << interventie_accident->get_pompieri_mobilizati().size() << "\n";
        std::cout << "   ✓ Conducteurs mobilisés : " << interventie_accident->get_soferi_mobilizati().size() << "\n";
        std::cout << "   ✓ Véhicules spéciaux mobilisés : " << interventie_accident->get_autospeciale_mobilizate().size() << "\n\n";

        // Démontre la mobilisation pour l'incendie
        std::cout << "5. Mobilisation des ressources pour l'incendie de végétation...\n";
        Interventie* interventie_incendiu = unitate.mobilizeaza_resurse_pentru_urgenta(incendiu_veg);
        std::cout << "   ✓ Intervention créée avec ID : " << interventie_incendiu->get_id() << "\n";
        std::cout << "   ✓ Pompiers mobilisés : " << interventie_incendiu->get_pompieri_mobilizati().size() << "\n";
        std::cout << "   ✓ Conducteurs mobilisés : " << interventie_incendiu->get_soferi_mobilizati().size() << "\n";
        std::cout << "   ✓ Véhicules spéciaux mobilisés : " << interventie_incendiu->get_autospeciale_mobilizate().size() << "\n\n";

        // Démontre l'opérateur ++
        std::cout << "6. Démonstration de l'opérateur ++ pour les pompiers...\n";
        for (auto* pompier_ptr : interventie_accident->get_pompieri_mobilizati()) {
            if (auto* pompier = dynamic_cast<Pompier*>(pompier_ptr)) {
                std::cout << "   Pompier " << pompier->get_nume() 
                          << " - expérience avant : " << pompier->get_numar_interventii();
                ++(*pompier);
                std::cout << ", après : " << pompier->get_numar_interventii() << "\n";
            }
        }
        std::cout << "\n";

        // Finalise les interventions et retourne les ressources
        std::cout << "7. Finalisation des interventions et retour des ressources...\n";
        unitate.returneaza_resurse_din_interventie(interventie_accident);
        std::cout << "   ✓ Intervention " << interventie_accident->get_id() << " finalisée\n";
        
        unitate.returneaza_resurse_din_interventie(interventie_incendiu);
        std::cout << "   ✓ Intervention " << interventie_incendiu->get_id() << " finalisée\n\n";

        // Démontre le traitement des exceptions
        std::cout << "8. Test du traitement des exceptions...\n";
        try {
            // Essaie de mobiliser des ressources pour un grand incendie (qui pourrait ne pas avoir assez de ressources)
            I_Urgenta* incendiu_mare = factory_urgente.create_new_Incendiu_Electric("Bâtiment élevé", 5, 50, 1000.0);
            Interventie* interventie_mare = unitate.mobilizeaza_resurse_pentru_urgenta(incendiu_mare);
            std::cout << "   ✓ L'intervention pour le grand incendie a été créée avec succès !\n";
        }
        catch (const InsufficientFirefightersException& e) {
            std::cout << "   ⚠ Exception capturée : " << e.get_message() << " (code : " << e.get_code() << ")\n";
        }
        catch (const InsufficientVehiclesException& e) {
            std::cout << "   ⚠ Exception capturée : " << e.get_message() << " (code : " << e.get_code() << ")\n";
        }
        catch (const std::exception& e) {
            std::cout << "   ⚠ Exception générale : " << e.what() << "\n";
        }

        std::cout << "\n=== LA DÉMONSTRATION S'EST TERMINÉE AVEC SUCCÈS ! ===\n";
        std::cout << "Toutes les fonctionnalités ont été testées :\n";
        std::cout << "✓ Chargement des données depuis le fichier\n";
        std::cout << "✓ Population du tour avec des ressources\n";
        std::cout << "✓ Création d'urgences\n";
        std::cout << "✓ Mobilisation des ressources\n";
        std::cout << "✓ Surcharge de l'opérateur ++\n";
        std::cout << "✓ Retour des ressources\n";
        std::cout << "✓ Traitement des exceptions\n";

    }
    catch (const std::exception& e) {
        std::cerr << "Erreur dans l'application : " << e.what() << std::endl;
        return 1;
    }

    return 0;
}