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

**Pompier** - moștenește de la Angajat (fără membri suplimentari încă)

**Sofer** - moștenește de la Angajat (fără membri suplimentari încă)

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

**Următorul pas**: Implementarea interfețelor și metodelor virtuale
