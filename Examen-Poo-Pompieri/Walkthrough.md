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

*[Secțiunea aceasta va fi completată pe măsură ce progresăm prin rezolvarea examenului]*
