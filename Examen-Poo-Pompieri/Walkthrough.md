# Walkthrough - Examen POO Unitate de Pompieri

## Funcționalități pregătite înainte de examen

Aceste trei funcționalități sunt create înainte de primirea subiectului, deoarece sunt folosite de majoritatea cerințelor și permit o dezvoltare mai rapidă și organizată a soluției.

### 1. Exceptions.h - Sistem de Excepții Flexibil

**Scopul**: Oferă un sistem flexibil pentru gestionarea excepțiilor în aplicație.

**Caracteristici**:
- Clasă de bază `Exception` cu cod numeric și mesaj
- Template `Derived_Exception` pentru crearea rapidă de excepții specifice
- Macro `DEFINE_EXCEPTION` pentru definirea excepțiilor cu sintaxă simplă
- Destructor virtual pentru gestionarea corectă a ierarhiilor

**Utilizare**:
```cpp
// Definirea excepțiilor specifice
DEFINE_EXCEPTION(NoSuitableDriverException, 1001);
DEFINE_EXCEPTION(InsufficientVehiclesException, 1002);
DEFINE_EXCEPTION(InsufficientFirefightersException, 1003);

// Aruncarea excepțiilor
throw NoSuitableDriverException("Nu există șofer potrivit pentru autoscarea necesară");
```

**Avantaje**:
- Flexibilitate maximă în crearea de excepții specifice
- Cod numeric pentru identificarea rapidă a tipului de excepție
- Mesaje descriptive pentru debugging
- Ușurință în adăugarea de noi tipuri de excepții pe măsură ce apar nevoile

### 2. Unique_ID_Generator.h - Generator de ID-uri Unice

**Scopul**: Gestionează automat atribuirea de ID-uri unice pentru diferite tipuri de obiecte.

**Caracteristici**:
- Template class pentru tipuri diferite de obiecte
- Static member pentru contorul de ID-uri
- Clasă non-instanțiată (constructor și destructor șterși)
- Inițializare cu -1 (primul ID generat va fi 0)

**Utilizare**:
```cpp
// Pentru diferite tipuri de obiecte
int emp_id = Unique_ID_Generator<Employee>::generate_next_id();     // 0, 1, 2...
int vehicle_id = Unique_ID_Generator<Vehicle>::generate_next_id();  // 0, 1, 2...
int intervention_id = Unique_ID_Generator<Intervention>::generate_next_id(); // 0, 1, 2...
```

**Avantaje**:
- Type-safe: fiecare tip de obiect are propriul contor
- Thread-safe pentru aplicații single-threaded
- Elimină necesitatea gestionării manuale a ID-urilor
- Previne conflictele de ID-uri între tipuri diferite de obiecte

### 3. Number_Generator.h - Generator de Numere Random

**Scopul**: Oferă funcționalitate de generare a numerelor aleatoare pentru simularea datelor.

**Caracteristici**:
- Lazy initialization a seed-ului (se inițializează doar la prima utilizare)
- Template cu parametri default pentru intervalul `[min, max]`
- Clasă non-instanțiată
- Folosește `time(nullptr)` pentru seed unic

**Utilizare**:
```cpp
// Cu interval specificat
int random_age = Number_Generator::generate_number<18, 65>();     // vârsta între 18-65
int random_area = Number_Generator::generate_number<10, 500>(); // suprafața între 10-500

// Cu interval default [0, 1000]
int random_value = Number_Generator::generate_number();
```

**Avantaje**:
- Flexibil: permite specificarea intervalului sau folosește default-ul
- Eficient: seed-ul se inițializează o singură dată
- Simplu de folosit pentru simularea datelor în teste
- Distribuție uniformă în intervalul specificat

## De ce aceste funcționalități înainte de examen?

1. **Eficiență**: Elimină timpul petrecut pe implementarea utilitarelor de bază
2. **Consistență**: Asigură un stil uniform de cod în toată aplicația
3. **Focus**: Permite concentrarea pe logica de business și conceptele POO importante
4. **Flexibilitate**: Ușurează modificările și adăugările pe măsură ce apar cerințe noi
5. **Calitate**: Implementări testate și optimizate pentru performanță

---

## Pași de rezolvare a examenului

### Pasul 1: Crearea arhitecturii generale a aplicației ✅ COMPLETAT

**Obiectiv**: Crearea tuturor claselor cu respectarea ierarhiilor și derivărilor, plus Factory-uri pentru Design Patterns.

**Clase create**:

#### Interfețe (I_*)
- `I_Angajat` - interfața pentru angajați
- `I_Autospeciala` - interfața pentru vehicule speciale  
- `I_Urgenta` - interfața pentru urgențe

#### Factory-uri (Design Pattern)
- `I_Angajat_Factory` - pentru crearea angajaților
- `I_Autospeciala_Factory` - pentru crearea vehiculelor
- `I_Urgenta_Factory` - pentru crearea urgențelor

#### Ierarhia Angajaților
```
I_Angajat
    └── Angajat
            ├── Pompier
            └── Sofer
```

#### Ierarhia Vehiculelor Speciale
```
I_Autospeciala
    └── Autospeciala
            ├── Autoscara
            ├── Autospeciala_Descarcerare
            └── Autospeciala_Stingere
                    ├── Autospeciala_Stingere_Pulbere
                    └── Autospeciala_Stingere_Spuma
```

#### Ierarhia Urgențelor
```
I_Urgenta
    └── Urgenta
            ├── Incendiu
            │       ├── Incendiu_Electric
            │       └── Incendiu_Vegetatie
            └── Accident
```

#### Clase de Management
- `Interventie` - pentru gestionarea intervențiilor
- `Tura` - pentru gestionarea turilor de serviciu
- `Unitate_Pompieri` - entitatea principală (Singleton)

**Puncte obținute**: 3p (Crearea claselor și arhitectura generală) + 1p (Design Patterns - Factory)

### Pasul 2: Implementarea membrilor de bază ai claselor ✅ COMPLETAT

**Obiectiv**: Adăugarea membrilor de bază și metodelor fundamentale pentru fiecare clasă, fără a complica relațiile între clase.

**Principii urmărite**:
- Fiecare clasă conține doar datele specifice ei
- Nu se stochează relații complexe între clase (ex: șoferii nu stochează lista de autospeciale)
- Relațiile vor fi gestionate în `Unitate_Pompieri` pentru cod mai curat

**Implementări realizate**:

#### Clasa Angajat
- `id_unic` - ID generat automat cu `Unique_ID_Generator`
- `nume` - numele angajatului
- Constructori: default, cu nume
- Getters/setters pentru toți membrii

#### Clasa Autospeciala
- `id_unic` - ID generat automat
- Constructor: default
- Destructor virtual pentru polimorfism
- Getters/setters pentru ID

#### Clasa Urgenta
- `adresa` - adresa unde s-a produs urgența
- `numar_victime` - numărul de victime
- Constructori: default, cu parametri
- Getters/setters pentru toți membrii

#### Clase derivate specifice:

**Pompier** - moștenește de la Angajat cu membri suplimentari:
- `numar_interventii` - experiența pompierului
- Constructori: default, cu nume, cu nume și experiență

**Sofer** - moștenește de la Angajat:

**Autoscara**:
- `lungime_scara` - lungimea scării în metri

**Autospeciala_Descarcerare**:
- `numar_departatoare` - numărul de depărtătoare hidraulice
- `numar_foarfece` - numărul de foarfece hidraulice

**Incendiu**:
- `inaltime` - înălțimea incendiului în metri
- `arie` - suprafața incendiului în metri pătrați

**Accident**:
- `numar_vehicule` - numărul de vehicule implicate

**Avantaje ale acestei abordări**:
1. **Cod curat** - fiecare clasă are responsabilități clare
2. **Flexibilitate** - relațiile pot fi gestionate centralizat
3. **Testabilitate** - clasele pot fi testate independent
4. **Mentenabilitate** - modificările sunt localizate

### Pasul 3: Implementarea interfețelor și Factory Pattern-ului ✅ COMPLETAT

**Obiectiv**: Implementarea interfețelor cu metode virtuale și Factory Pattern pentru crearea obiectelor.

**Implementări realizate**:

#### Interfețe cu metode virtuale
- `I_Angajat` - interfața de bază pentru angajați cu destructor virtual
- `I_Autospeciala` - interfața de bază pentru vehicule speciale cu destructor virtual  
- `I_Urgenta` - interfața de bază pentru urgențe cu destructor virtual

#### Factory Pattern implementat

**I_Angajat_Factory**:
- `create_new_Pompier()` - constructor default
- `create_new_Pompier(const std::string& nume)` - cu nume
- `create_new_Pompier(const std::string& nume, int numar_interventii)` - cu nume și experiență
- `create_new_Sofer()` - constructor default
- `create_new_Sofer(const std::string& nume)` - cu nume

**I_Autospeciala_Factory**:
- `create_new_Autoscara()` și `create_new_Autoscara(double lungime_scara)`
- `create_new_Autospeciala_Descarcerare()` și cu parametri pentru echipamente
- `create_new_Autospeciala_Stingere_Pulbere()` și cu capacitate material
- `create_new_Autospeciala_Stingere_Spuma()` și cu capacitate material

**I_Urgenta_Factory**:
- `create_new_Accident()` cu toate variantele de constructori
- `create_new_Incendiu_Electric()` cu toate variantele de constructori
- `create_new_Incendiu_Vegetatie()` cu toate variantele de constructori

**Avantaje**:
1. **Polimorfism** - destructorii virtuali permit gestionarea corectă a obiectelor prin pointeri la interfețe
2. **Factory Pattern** - centralizează crearea obiectelor și ascunde complexitatea
3. **Flexibilitate** - multiple variante de constructori pentru diferite scenarii
4. **Encapsulare** - Factory-urile ascund detaliile de implementare

**Puncte obținute**: 1p (Interfețe și metode virtuale) + 1p (Design Patterns - Factory)

### Pasul 4: Implementarea metodelor virtuale și polimorfismului ✅ COMPLETAT

**Obiectiv**: Implementarea metodelor virtuale în interfețe și clasele derivate pentru polimorfism corect.

**Implementări realizate**:

#### Interfețe cu metode pure virtuale (= 0)
- `I_Angajat` - toate metodele sunt pure virtuale
- `I_Autospeciala` - toate metodele sunt pure virtuale  
- `I_Urgenta` - toate metodele sunt pure virtuale

#### Clase de bază cu implementări și excepții
**Angajat**:
- Implementează metodele comune (`get_id`, `get_nume`, `set_id`, `set_nume`)
- Aruncă `Wrong_Angajat_Type` pentru metodele specifice pompierilor (`get_numar_interventii`)

**Autospeciala**:
- Implementează metodele comune (`get_id`, `set_id`)
- Aruncă `Wrong_Autospeciala_Type` pentru metodele specifice fiecărui tip de vehicul

**Urgenta**:
- Implementează metodele comune (`get_adresa`, `get_numar_victime`, `set_adresa`, `set_numar_victime`)
- Aruncă `Wrong_Urgenta_Type` pentru metodele specifice fiecărui tip de urgență

#### Clase derivate cu override
**Pompier**:
- Override pentru `get_numar_interventii()` și `set_numar_interventii()`

**Accident**:
- Override pentru `get_numar_vehicule()` și `set_numar_vehicule()`

**Incendiu**:
- Override pentru `get_inaltime()`, `get_arie()`, `set_inaltime()`, `set_arie()`

#### Excepții definite
```cpp
DEFINE_EXCEPTION(Wrong_Angajat_Type, 1001);
DEFINE_EXCEPTION(Wrong_Autospeciala_Type, 1002);
DEFINE_EXCEPTION(Wrong_Urgenta_Type, 1003);
```

**Avantaje**:
1. **Polimorfism corect** - metodele virtuale permit gestionarea obiectelor prin pointeri la interfețe
2. **Type safety** - excepțiile previne accesarea metodelor greșite
3. **Extensibilitate** - ușor de adăugat noi tipuri de obiecte
4. **Encapsulare** - fiecare clasă implementează doar metodele relevante

**Puncte obținute**: 1p (Interfețe și metode virtuale) - consolidat

### Pasul 5: Implementarea structurii de date în Unitate_Pompieri ✅ COMPLETAT

**Obiectiv**: Crearea structurii de date centralizate pentru gestionarea tuturor obiectelor din aplicație.

**Implementări realizate**:

#### Structura de date în Unitate_Pompieri
```cpp
private:
    std::map<int, I_Angajat*> angajati;           // id -> angajat
    std::map<int, I_Autospeciala*> autospeciale;  // id -> vehicul
    std::map<int, Interventie*> interventii;      // id -> intervenție
    std::vector<I_Urgenta*> urgente;              // urgențe active
    
    std::vector<std::pair<int, int>> soferi_autospeciale; // experiența șoferilor
```

#### Metode de management
- `add_angajat(I_Angajat* angajat)` - adaugă angajat în map
- `add_autospeciala(I_Autospeciala* autospeciala)` - adaugă vehicul în map
- `add_interventie(Interventie* interventie)` - adaugă intervenție în map
- `add_urgenta(I_Urgenta* urgenta)` - adaugă urgență în vector

#### Auto-inserare în constructori
**Pompier**:
- Toți constructorii apelează `Unitate_Pompieri::get_instance().add_angajat(this)`
- Angajatul se înregistrează automat la creare

**Sofer**:
- Toți constructorii apelează `Unitate_Pompieri::get_instance().add_angajat(this)`
- Șoferul se înregistrează automat la creare

**Autospeciala**:
- Constructorul generează ID automat cu `Unique_ID_Generator`
- ID-ul este atribuit automat la creare

**Avantaje**:
1. **Centralizare** - toate obiectele sunt gestionate într-un singur loc
2. **Auto-registrare** - obiectele se înregistrează automat la creare
3. **Căutări rapide** - prin ID în maps
4. **Singleton Pattern** - o singură instanță pentru toată aplicația
5. **Experiență șoferi** - stocată în `soferi_autospeciale` pentru verificări ulterioare

### Pasul 6: Implementarea calculului resurselor necesare ✅ COMPLETAT

**Obiectiv**: Calculul automat al resurselor necesare pentru fiecare tip de urgență în clasa de bază `Urgenta`.

**Implementări realizate**:

#### Membri pentru resurse în clasa Urgenta
```cpp
protected:
    // Resursele necesare pentru intervenție
    int numar_departatoare_necesare = 0;
    int numar_foarfece_necesare = 0;
    double pulbere_necesara = 0.0;
    double spuma_necesara = 0.0;
    int autoscari_necesare = 0;
    int numar_pompieri_necesari = 0;
```

#### Calculul resurselor în constructori

**Accident**:
- `numar_departatoare_necesare = numar_vehicule - 1`
- `numar_foarfece_necesare = 1`
- `spuma_necesara = 0` (implicit, nu este necesară)

**Incendiu_Electric**:
- `pulbere_necesara = arie / 20.0`
- `numar_departatoare_necesare = 0` (implicit, nu sunt necesare)

**Incendiu_Vegetatie**:
- `spuma_necesara = arie / 15.0`
- `numar_departatoare_necesare = 0` (implicit, nu sunt necesare)

**Incendiu** (clasa de bază):
- `autoscari_necesare = (inaltime > 2) ? (1 + numar_victime / 20) : 0`
- `numar_pompieri_necesari = (inaltime > 10) ? (1 + arie / 20.0) : (1 + arie / 25.0)`

#### Avantaje ale acestei abordări:
1. **Centralizare** - toate resursele sunt în clasa de bază
2. **Valori implicite** - resursele neaplicabile rămân 0
3. **Calcul automat** - resursele se calculează la crearea urgenței
4. **Flexibilitate** - ușor de adăugat noi tipuri de resurse
5. **Consistență** - toate urgențele au aceeași structură de resurse

**Următorul pas**: Implementarea logicii de mutare a resurselor din tură
