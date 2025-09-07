# Guide d'implémentation - Examen POO Unité de Pompiers

## Fonctionnalités préparées avant l'examen

Ces trois fonctionnalités sont créées avant la réception du sujet, car elles sont utilisées par la plupart des exigences et permettent un développement plus rapide et organisé de la solution.

### 1. Exceptions.h - Système d'Exceptions Flexible

**Objectif** : Offre un système flexible pour la gestion des exceptions dans l'application.

**Caractéristiques** :
- Classe de base `Exception` avec code numérique et message
- Template `Derived_Exception` pour la création rapide d'exceptions spécifiques
- Macro `DEFINE_EXCEPTION` pour la définition d'exceptions avec une syntaxe simple
- Destructeur virtuel pour la gestion correcte des hiérarchies

**Utilisation** :
```cpp
// Définition d'exceptions spécifiques
DEFINE_EXCEPTION(NoSuitableDriverException, 1001);
DEFINE_EXCEPTION(InsufficientVehiclesException, 1002);
DEFINE_EXCEPTION(InsufficientFirefightersException, 1003);

// Lancement d'exceptions
throw NoSuitableDriverException("Aucun conducteur approprié pour l'échelle nécessaire");
```

**Avantages** :
- Flexibilité maximale dans la création d'exceptions spécifiques
- Code numérique pour l'identification rapide du type d'exception
- Messages descriptifs pour le débogage
- Facilité d'ajout de nouveaux types d'exceptions selon les besoins

### 2. Unique_ID_Generator.h - Générateur d'ID Uniques

**Objectif** : Gère automatiquement l'attribution d'ID uniques pour différents types d'objets.

**Caractéristiques** :
- Classe template pour différents types d'objets
- Membre statique pour le compteur d'ID
- Classe non-instanciable (constructeur et destructeur supprimés)
- Initialisation avec -1 (le premier ID généré sera 0)

**Utilisation** :
```cpp
// Pour différents types d'objets
int emp_id = Unique_ID_Generator<Employee>::generate_next_id();     // 0, 1, 2...
int vehicle_id = Unique_ID_Generator<Vehicle>::generate_next_id();  // 0, 1, 2...
int intervention_id = Unique_ID_Generator<Intervention>::generate_next_id(); // 0, 1, 2...
```

**Avantages** :
- Type-safe : chaque type d'objet a son propre compteur
- Thread-safe pour les applications mono-thread
- Élimine la nécessité de gestion manuelle des ID
- Prévient les conflits d'ID entre différents types d'objets

### 3. Number_Generator.h - Générateur de Nombres Aléatoires

**Objectif** : Offre une fonctionnalité de génération de nombres aléatoires pour la simulation de données.

**Caractéristiques** :
- Initialisation paresseuse du seed (s'initialise seulement à la première utilisation)
- Template avec paramètres par défaut pour l'intervalle `[min, max]`
- Classe non-instanciable
- Utilise `time(nullptr)` pour un seed unique

**Utilisation** :
```cpp
// Avec intervalle spécifié
int random_age = Number_Generator::generate_number<18, 65>();     // âge entre 18-65
int random_area = Number_Generator::generate_number<10, 500>(); // superficie entre 10-500

// Avec intervalle par défaut [0, 1000]
int random_value = Number_Generator::generate_number();
```

**Avantages** :
- Flexible : permet de spécifier l'intervalle ou utilise celui par défaut
- Efficace : le seed s'initialise une seule fois
- Simple à utiliser pour la simulation de données dans les tests
- Distribution uniforme dans l'intervalle spécifié

## Pourquoi ces fonctionnalités avant l'examen ?

1. **Efficacité** : Élimine le temps consacré à l'implémentation d'utilitaires de base
2. **Consistance** : Assure un style de code uniforme dans toute l'application
3. **Focus** : Permet de se concentrer sur la logique métier et les concepts POO importants
4. **Flexibilité** : Facilite les modifications et ajouts selon les nouvelles exigences
5. **Qualité** : Implémentations testées et optimisées pour les performances

---

## Étapes de résolution de l'examen

### Étape 1 : Création de l'architecture générale de l'application ✅ TERMINÉ

**Objectif** : Création de toutes les classes en respectant les hiérarchies et dérivations, plus les Factory pour les Design Patterns.

**Classes créées** :

#### Interfaces (I_*)
- `I_Angajat` - interface pour les employés
- `I_Autospeciala` - interface pour les véhicules spéciaux  
- `I_Urgenta` - interface pour les urgences

#### Factory (Design Pattern)
- `I_Angajat_Factory` - pour la création des employés
- `I_Autospeciala_Factory` - pour la création des véhicules
- `I_Urgenta_Factory` - pour la création des urgences

#### Hiérarchie des Employés
```
I_Angajat
    └── Angajat
            ├── Pompier
            └── Sofer
```

#### Hiérarchie des Véhicules Spéciaux
```
I_Autospeciala
    └── Autospeciala
            ├── Autoscara
            ├── Autospeciala_Descarcerare
            └── Autospeciala_Stingere
                    ├── Autospeciala_Stingere_Pulbere
                    └── Autospeciala_Stingere_Spuma
```

#### Hiérarchie des Urgences
```
I_Urgenta
    └── Urgenta
            ├── Incendiu
            │       ├── Incendiu_Electric
            │       └── Incendiu_Vegetatie
            └── Accident
```

#### Classes de Gestion
- `Interventie` - pour la gestion des interventions
- `Tura` - pour la gestion des tours de service
- `Unitate_Pompieri` - entité principale (Singleton)

**Points obtenus** : 3p (Création des classes et architecture générale) + 1p (Design Patterns - Factory)

### Étape 2 : Implémentation des membres de base des classes ✅ TERMINÉ

**Objectif** : Ajout des membres de base et des méthodes fondamentales pour chaque classe, sans compliquer les relations entre classes.

**Principes suivis** :
- Chaque classe contient seulement les données qui lui sont spécifiques
- Pas de stockage de relations complexes entre classes (ex: les conducteurs ne stockent pas la liste des véhicules spéciaux)
- Les relations seront gérées dans `Unitate_Pompieri` pour un code plus propre

**Implémentations réalisées** :

#### Classe Angajat
- `id_unic` - ID généré automatiquement avec `Unique_ID_Generator`
- `nume` - nom de l'employé
- Constructeurs : par défaut, avec nom
- Getters/setters pour tous les membres

#### Classe Autospeciala
- `id_unic` - ID généré automatiquement
- Constructeur : par défaut
- Destructeur virtuel pour le polymorphisme
- Getters/setters pour l'ID

#### Classe Urgenta
- `adresa` - adresse où s'est produite l'urgence
- `numar_victime` - nombre de victimes
- Constructeurs : par défaut, avec paramètres
- Getters/setters pour tous les membres

#### Classes dérivées spécifiques :

**Pompier** - hérite d'Angajat avec des membres supplémentaires :
- `numar_interventii` - expérience du pompier
- Constructeurs : par défaut, avec nom, avec nom et expérience

**Sofer** - hérite d'Angajat :

**Autoscara** :
- `lungime_scara` - longueur de l'échelle en mètres

**Autospeciala_Descarcerare** :
- `numar_departatoare` - nombre d'écarteurs hydrauliques
- `numar_foarfece` - nombre de cisailles hydrauliques

**Incendiu** :
- `inaltime` - hauteur de l'incendie en mètres
- `arie` - superficie de l'incendie en mètres carrés

**Accident** :
- `numar_vehicule` - nombre de véhicules impliqués

**Avantages de cette approche** :
1. **Code propre** - chaque classe a des responsabilités claires
2. **Flexibilité** - les relations peuvent être gérées de manière centralisée
3. **Testabilité** - les classes peuvent être testées indépendamment
4. **Maintenabilité** - les modifications sont localisées

### Étape 3 : Implémentation des interfaces et du Factory Pattern ✅ TERMINÉ

**Objectif** : Implémentation des interfaces avec méthodes virtuelles et Factory Pattern pour la création d'objets.

**Implémentations réalisées** :

#### Interfaces avec méthodes virtuelles
- `I_Angajat` - interface de base pour les employés avec destructeur virtuel
- `I_Autospeciala` - interface de base pour les véhicules spéciaux avec destructeur virtuel  
- `I_Urgenta` - interface de base pour les urgences avec destructeur virtuel

#### Factory Pattern implémenté

**I_Angajat_Factory** :
- `create_new_Pompier()` - constructeur par défaut
- `create_new_Pompier(const std::string& nume)` - avec nom
- `create_new_Pompier(const std::string& nume, int numar_interventii)` - avec nom et expérience
- `create_new_Sofer()` - constructeur par défaut
- `create_new_Sofer(const std::string& nume)` - avec nom

**I_Autospeciala_Factory** :
- `create_new_Autoscara()` et `create_new_Autoscara(double lungime_scara)`
- `create_new_Autospeciala_Descarcerare()` et avec paramètres pour équipements
- `create_new_Autospeciala_Stingere_Pulbere()` et avec capacité matériel
- `create_new_Autospeciala_Stingere_Spuma()` et avec capacité matériel

**I_Urgenta_Factory** :
- `create_new_Accident()` avec toutes les variantes de constructeurs
- `create_new_Incendiu_Electric()` avec toutes les variantes de constructeurs
- `create_new_Incendiu_Vegetatie()` avec toutes les variantes de constructeurs

**Avantages** :
1. **Polymorphisme** - les destructeurs virtuels permettent la gestion correcte des objets via des pointeurs vers les interfaces
2. **Factory Pattern** - centralise la création d'objets et cache la complexité
3. **Flexibilité** - multiples variantes de constructeurs pour différents scénarios
4. **Encapsulation** - les Factory cachent les détails d'implémentation

**Points obtenus** : 1p (Interfaces et méthodes virtuelles) + 1p (Design Patterns - Factory)

### Étape 4 : Implémentation des méthodes virtuelles et du polymorphisme ✅ TERMINÉ

**Objectif** : Implémentation des méthodes virtuelles dans les interfaces et classes dérivées pour un polymorphisme correct.

**Implémentations réalisées** :

#### Interfaces avec méthodes purement virtuelles (= 0)
- `I_Angajat` - toutes les méthodes sont purement virtuelles
- `I_Autospeciala` - toutes les méthodes sont purement virtuelles  
- `I_Urgenta` - toutes les méthodes sont purement virtuelles

#### Classes de base avec implémentations et exceptions
**Angajat** :
- Implémente les méthodes communes (`get_id`, `get_nume`, `set_id`, `set_nume`)
- Lance `Wrong_Angajat_Type` pour les méthodes spécifiques aux pompiers (`get_numar_interventii`)

**Autospeciala** :
- Implémente les méthodes communes (`get_id`, `set_id`)
- Lance `Wrong_Autospeciala_Type` pour les méthodes spécifiques à chaque type de véhicule

**Urgenta** :
- Implémente les méthodes communes (`get_adresa`, `get_numar_victime`, `set_adresa`, `set_numar_victime`)
- Lance `Wrong_Urgenta_Type` pour les méthodes spécifiques à chaque type d'urgence

#### Classes dérivées avec override
**Pompier** :
- Override pour `get_numar_interventii()` et `set_numar_interventii()`

**Accident** :
- Override pour `get_numar_vehicule()` et `set_numar_vehicule()`

**Incendiu** :
- Override pour `get_inaltime()`, `get_arie()`, `set_inaltime()`, `set_arie()`

#### Exceptions définies
```cpp
DEFINE_EXCEPTION(Wrong_Angajat_Type, 1001);
DEFINE_EXCEPTION(Wrong_Autospeciala_Type, 1002);
DEFINE_EXCEPTION(Wrong_Urgenta_Type, 1003);
```

**Avantages** :
1. **Polymorphisme correct** - les méthodes virtuelles permettent la gestion des objets via des pointeurs vers les interfaces
2. **Type safety** - les exceptions préviennent l'accès aux mauvaises méthodes
3. **Extensibilité** - facile d'ajouter de nouveaux types d'objets
4. **Encapsulation** - chaque classe implémente seulement les méthodes pertinentes

**Points obtenus** : 1p (Interfaces et méthodes virtuelles) - consolidé

### Étape 5 : Implémentation de la structure de données dans Unitate_Pompieri ✅ TERMINÉ

**Objectif** : Création de la structure de données centralisée pour la gestion de tous les objets de l'application.

**Implémentations réalisées** :

#### Structure de données dans Unitate_Pompieri
```cpp
private:
    std::map<int, I_Angajat*> angajati;           // id -> employé
    std::map<int, I_Autospeciala*> autospeciale;  // id -> véhicule
    std::map<int, Interventie*> interventii;      // id -> intervention
    std::vector<I_Urgenta*> urgente;              // urgences actives
    
    std::vector<std::pair<int, int>> soferi_autospeciale; // expérience des conducteurs
```

#### Méthodes de gestion
- `add_angajat(I_Angajat* angajat)` - ajoute employé dans map
- `add_autospeciala(I_Autospeciala* autospeciala)` - ajoute véhicule dans map
- `add_interventie(Interventie* interventie)` - ajoute intervention dans map
- `add_urgenta(I_Urgenta* urgenta)` - ajoute urgence dans vector

#### Auto-insertion dans les constructeurs
**Pompier** :
- Tous les constructeurs appellent `Unitate_Pompieri::get_instance().add_angajat(this)`
- L'employé s'enregistre automatiquement à la création

**Sofer** :
- Tous les constructeurs appellent `Unitate_Pompieri::get_instance().add_angajat(this)`
- Le conducteur s'enregistre automatiquement à la création

**Autospeciala** :
- Le constructeur génère l'ID automatiquement avec `Unique_ID_Generator`
- L'ID est attribué automatiquement à la création

**Avantages** :
1. **Centralisation** - tous les objets sont gérés en un seul endroit
2. **Auto-enregistrement** - les objets s'enregistrent automatiquement à la création
3. **Recherches rapides** - par ID dans les maps
4. **Singleton Pattern** - une seule instance pour toute l'application
5. **Expérience conducteurs** - stockée dans `soferi_autospeciale` pour vérifications ultérieures

### Étape 6 : Implémentation du calcul des ressources nécessaires ✅ TERMINÉ

**Objectif** : Calcul automatique des ressources nécessaires pour chaque type d'urgence dans la classe de base `Urgenta`.

**Implémentations réalisées** :

#### Membres pour ressources dans la classe Urgenta
```cpp
protected:
    // Ressources nécessaires pour l'intervention
    int numar_departatoare_necesare = 0;
    int numar_foarfece_necesare = 0;
    double pulbere_necesara = 0.0;
    double spuma_necesara = 0.0;
    int autoscari_necesare = 0;
    int numar_pompieri_necesari = 0;
```

#### Calcul des ressources dans les constructeurs

**Accident** :
- `numar_departatoare_necesare = numar_vehicule - 1`
- `numar_foarfece_necesare = 1`
- `spuma_necesara = 0` (implicite, n'est pas nécessaire)

**Incendiu_Electric** :
- `pulbere_necesara = arie / 20.0`
- `numar_departatoare_necesare = 0` (implicite, ne sont pas nécessaires)

**Incendiu_Vegetatie** :
- `spuma_necesara = arie / 15.0`
- `numar_departatoare_necesare = 0` (implicite, ne sont pas nécessaires)

**Incendiu** (classe de base) :
- `autoscari_necesare = (inaltime > 2) ? (1 + numar_victime / 20) : 0`
- `numar_pompieri_necesari = (inaltime > 10) ? (1 + arie / 20.0) : (1 + arie / 25.0)`

#### Méthodes d'accès implémentées
**Dans I_Urgenta** (interface) :
- Toutes les méthodes sont purement virtuelles (`= 0`)
- Getters et setters pour toutes les ressources nécessaires

**Dans Urgenta** (classe de base) :
- Implémentations avec `override` pour toutes les méthodes
- Retourne les valeurs des membres protégés
- Setters pour modifier les valeurs

#### Avantages de cette approche :
1. **Centralisation** - toutes les ressources sont dans la classe de base
2. **Valeurs par défaut** - les ressources non applicables restent à 0
3. **Calcul automatique** - les ressources se calculent à la création de l'urgence
4. **Flexibilité** - facile d'ajouter de nouveaux types de ressources
5. **Consistance** - toutes les urgences ont la même structure de ressources
6. **Accès complet** - getters et setters pour toutes les ressources

### Étape 7 : Implémentation de la logique de déplacement des ressources ✅ TERMINÉ

**Objectif** : Implémentation de la fonctionnalité de déplacement des ressources du tour vers l'intervention et retour.

**Implémentations réalisées** :

#### Modification de la classe Interventie
- **Supprimé** : membres pour les ressources nécessaires (maintenant accessibles via `urgenta_declansatoare`)
- **Ajouté** : vecteurs pour les ressources effectivement mobilisées
- **Ajouté** : méthodes pour la mobilisation et le retour des ressources
- **Ajouté** : flag `activa` pour l'état de l'intervention

#### Méthodes dans Tura pour le déplacement des ressources
- `muta_pompieri(int numar_necesar)` - déplace les pompiers du tour
- `muta_soferi_pentru_autospeciale()` - déplace les conducteurs pour les véhicules
- `muta_autoscara()` - déplace une échelle
- `muta_autospeciale_descarcerare()` - déplace les véhicules de désincarcération
- `muta_autospeciale_stingere_pulbere()` - déplace les véhicules à poudre
- `muta_autospeciale_stingere_spuma()` - déplace les véhicules à mousse

#### Méthodes dans Tura pour le retour des ressources
- `returneaza_pompier()`, `returneaza_sofer()`, `returneaza_autoscara()`, etc.
- Les ressources sont retournées dans les conteneurs correspondants

#### Méthode principale dans Unitate_Pompieri
- `mobilizeaza_resurse_pentru_urgenta(I_Urgenta* urgenta)` - mobilise toutes les ressources nécessaires
- `returneaza_resurse_din_interventie(Interventie* interventie)` - retourne les ressources au tour

#### Exceptions ajoutées
- `InsufficientFirefightersException` - pompiers insuffisants
- `InsufficientVehiclesException` - véhicules insuffisants
- `NoSuitableDriverException` - conducteur approprié manquant

#### Logique de mobilisation
1. **Vérifie la disponibilité** des ressources dans le tour
2. **Déplace les ressources** du tour vers l'intervention (pas de clonage !)
3. **Mobilise les ressources** dans l'intervention
4. **Ajoute l'intervention** dans Unitate_Pompieri
5. **Retourne les ressources** à la finalisation de l'intervention

**Avantages** :
1. **Déplacement, pas clonage** - les ressources se déplacent effectivement du tour vers l'intervention
2. **Vérifications complètes** - disponibilité, quantités, équipements
3. **Gestion centralisée** - toutes les opérations via Unitate_Pompieri
4. **Flexibilité** - facile d'ajouter de nouveaux types de ressources
5. **Registre complet** - les ressources restent en registre après finalisation

### Étape 8 : Implémentation de la surcharge de l'opérateur ++ ✅ TERMINÉ

**Objectif** : Surcharge de l'opérateur ++ pour incrémenter l'expérience des pompiers après chaque intervention.

**Implémentations réalisées** :

#### Surcharge de l'opérateur ++ dans la classe Pompier
```cpp
// Pré-incrément (++pompier)
Pompier& operator++();

// Post-incrément (pompier++)
Pompier operator++(int);
```

#### Implémentation des opérateurs
- **Pré-incrément** : incrémente `numar_interventii` et retourne la référence à l'objet
- **Post-incrément** : incrémente `numar_interventii` et retourne une copie de la valeur précédente

#### Intégration dans la logique de retour des ressources
- À la finalisation d'une intervention, l'expérience des pompiers s'incrémente automatiquement
- Utilise `dynamic_cast` pour vérifier si l'employé est un Pompier
- Applique l'opérateur `++(*pompier)` pour chaque pompier mobilisé

#### Exemple d'utilisation
```cpp
Pompier pompier("Ion", 5);  // 5 interventions
++pompier;                  // maintenant a 6 interventions
pompier++;                  // maintenant a 7 interventions, retourne la valeur 6
```

**Avantages** :
1. **Syntaxe naturelle** - utilise l'opérateur ++ standard
2. **Automatisation** - l'expérience s'incrémente automatiquement à la finalisation des interventions
3. **Flexibilité** - supporte tant le pré-incrément que le post-incrément
4. **Intégration** - s'intègre parfaitement dans la logique existante

**Points obtenus** : 1p (Surcharge de l'opérateur ++)

### Étape 9 : Implémentation du chargement des données depuis un fichier ✅ TERMINÉ

**Objectif** : Implémentation de la fonctionnalité de chargement des employés et véhicules spéciaux depuis un fichier pour peupler l'unité.

**Implémentations réalisées** :

#### Fichier de données Unitate_Pompieri.txt
```
# Format: type_objet|parametres_separes_par_virgule

# Pompiers
Pompier|Ion Popescu,10
Pompier|Maria Ionescu,5

# Conducteurs
Sofer|Vasile Petrescu
Sofer|Elena Georgescu

# Échelles
Autoscara|25.5
Autoscara|30.0

# Véhicules spéciaux de désincarcération
Autospeciala_Descarcerare|2,1
Autospeciala_Descarcerare|3,2

# Véhicules spéciaux d'extinction à poudre
Autospeciala_Stingere_Pulbere|500.0
Autospeciala_Stingere_Pulbere|750.0

# Véhicules spéciaux d'extinction à mousse
Autospeciala_Stingere_Spuma|400.0
Autospeciala_Stingere_Spuma|600.0
```

#### Méthodes implémentées dans Unitate_Pompieri
- `incarca_date_din_fisier(const std::string& nume_fisier)` - charge les données depuis le fichier
- `proceseaza_linie_fisier(const std::string& linie)` - traite chaque ligne du fichier

#### Logique de traitement
1. **Ouvre le fichier** et vérifie s'il s'est ouvert correctement
2. **Lit ligne par ligne** et ignore les commentaires (#) et les lignes vides
3. **Parse chaque ligne** en utilisant le séparateur `|`
4. **Crée les objets** selon le type spécifié
5. **Ajoute les objets** dans l'unité de pompiers

#### Types d'objets supportés
- **Pompier** : `Pompier|nom,nombre_interventions`
- **Sofer** : `Sofer|nom`
- **Autoscara** : `Autoscara|longueur_echelle`
- **Autospeciala_Descarcerare** : `Autospeciala_Descarcerare|ecarteurs,cisailles`
- **Autospeciala_Stingere_Pulbere** : `Autospeciala_Stingere_Pulbere|capacite`
- **Autospeciala_Stingere_Spuma** : `Autospeciala_Stingere_Spuma|capacite`

#### Traitement des erreurs
- Vérifie si le fichier s'est ouvert correctement
- Ignore les lignes invalides ou vides
- Élimine les espaces en trop des paramètres
- Utilise `std::stoi()` et `std::stod()` pour des conversions sûres

**Avantages** :
1. **Flexibilité** - facile de modifier les données en éditant le fichier
2. **Séparation des données** - les données sont séparées du code de l'application
3. **Réutilisation** - le même fichier peut être utilisé pour différents tests
4. **Extensibilité** - facile d'ajouter de nouveaux types d'objets
5. **Robustesse** - traitement des erreurs et validation des données

**Points obtenus** : 1p (Chargement des données depuis des fichiers)

### Étape 10 : Implémentation de la fonction main et test complet ✅ TERMINÉ

**Objectif** : Création d'une fonction main complète qui démontre toutes les fonctionnalités implémentées.

**Implémentations réalisées** :

#### Fonction main complète
```cpp
int main() {
    // 1. Chargement des données depuis le fichier
    // 2. Population du tour avec des ressources
    // 3. Création d'urgences pour les tests
    // 4. Mobilisation des ressources pour l'accident
    // 5. Mobilisation des ressources pour l'incendie
    // 6. Démonstration de l'opérateur ++
    // 7. Finalisation des interventions
    // 8. Test de la gestion des exceptions
}
```

#### Fonctionnalités démontrées
1. **Chargement des données depuis le fichier** - utilise `incarca_date_din_fisier()`
2. **Population du tour** - ajoute manuellement pompiers, conducteurs et véhicules spéciaux
3. **Création d'urgences** - utilise Factory Pattern pour différents types
4. **Mobilisation des ressources** - démontre le déplacement du tour vers l'intervention
5. **Surcharge de l'opérateur ++** - incrémente l'expérience des pompiers
6. **Retour des ressources** - finalise les interventions et retourne les ressources
7. **Gestion des exceptions** - démontre la gestion des erreurs

#### Types d'urgences testés
- **Accident routier** - avec 3 véhicules impliqués
- **Incendie de végétation** - avec hauteur 5m et superficie 100m²
- **Incendie électrique** - avec hauteur 15m et superficie 200m²
- **Grand incendie** - pour tester les exceptions

#### Sortie du programme
Le programme affiche :
- Le progrès de chaque étape
- Détails sur les urgences créées
- Nombre de ressources mobilisées
- Expérience des pompiers avant et après intervention
- Messages de succès pour chaque opération
- Gestion des exceptions quand elles surviennent

**Avantages** :
1. **Démonstration complète** - teste toutes les fonctionnalités
2. **Sortie informative** - affiche le progrès et les résultats
3. **Gestion des erreurs** - démontre la gestion des exceptions
4. **Réalisme** - simule des scénarios réels d'intervention
5. **Facilité de compréhension** - les étapes sont claires et logiques

**Points obtenus** : Démonstration complète de toutes les fonctionnalités

**RÉSULTAT FINAL** : L'application est complète et fonctionnelle ! 🎉
