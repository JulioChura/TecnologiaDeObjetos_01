#include "zoologico.h"

int Animal::contadorId = 1;

Animal::Animal(string nom, string esp, float p, string die) {
    id = contadorId++;
    nombre = nom;
    especie = esp;
    peso = p;
    horasDesdeUltimaComida = 8;
    tieneHambre = true;
    dieta = die;
}

Animal::~Animal() {
    // vacío por ahora; liberación específica en derivados si hiciera falta
}

void Animal::mostrarInfo() const {
    cout << nombre << " (" << especie << ") - Peso: " << peso << "kg - "
         << "Horas sin comer: " << horasDesdeUltimaComida;
    if (tieneHambre) {
        cout << " [HAMBRIENTO]";
    } else {
        cout << " [ALIMENTADO]";
    }
    cout << " - ID: " << id << endl;
}

void Animal::alimentar() {
    horasDesdeUltimaComida = 0;
    tieneHambre = false;
    cout << nombre << " ha sido alimentado.\n";
}

void Animal::pasarTiempo(int horas) {
    horasDesdeUltimaComida += horas;
    if (horasDesdeUltimaComida >= 6) {
        tieneHambre = true;
    }
}

ostream& operator<<(ostream& os, const Animal& a) {
    os << a.nombre << " (" << a.especie << ") - Peso: " << a.peso << "kg - ";
    os << "Horas sin comer: " << a.horasDesdeUltimaComida;
    os << (a.tieneHambre ? " [HAMBRIENTO]" : " [ALIMENTADO]");
    os << " - ID: " << a.id;
    return os;
}


int Animal::getId() const { return id; }
string Animal::getNombre() const { return nombre; }
bool Animal::getTieneHambre() const { return tieneHambre; }
int Animal::getHorasSinComer() const { return horasDesdeUltimaComida; }
string Animal::getDieta() const { return dieta; }

/* ---------- Herbivoro ---------- */
Herbivoro::Herbivoro(string nom, string esp, float p, string die, float gramosPorKg)
    : Animal(nom, esp, p, die), gramosVerduraPorKg(gramosPorKg) {}

Animal* Herbivoro::alimentarse() {
    float racion = calcularRacionComida();
    cout << nombre << " come " << racion << " g de vegetales.\n";
    alimentar();
    return this;    
}

float Herbivoro::calcularRacionComida() {
    return gramosVerduraPorKg * peso;
}

/* ---------- Carnivoro ---------- */
Carnivoro::Carnivoro(string nom, string esp, float p, string die, float gramosPorKg)
    : Animal(nom, esp, p, die), gramosCarnePorKg(gramosPorKg) {}

float Carnivoro::calcularRacionComida() {
    return gramosCarnePorKg * peso;
}
Animal* Carnivoro::alimentarse() {
    float racion = calcularRacionComida();
    cout << nombre << " come " << racion << " g de carne.\n";
    alimentar();
    return this;
}

/* ---------- Omnivoro ---------- */
Omnivoro::Omnivoro(string nom, string esp, float p, string die, float verdura, float carne)
    : Animal(nom, esp, p, die), gramosVerduraPorKg(verdura), gramosCarnePorKg(carne) {}

float Omnivoro::calcularRacionComida() {
    return (gramosVerduraPorKg + gramosCarnePorKg) * peso;
}
Animal* Omnivoro::alimentarse() {
    float racionVerdura = gramosVerduraPorKg * peso;
    float racionCarne = gramosCarnePorKg * peso;
    float total = calcularRacionComida();
    cout << nombre << " come " << racionVerdura << " g de vegetales y "
         << racionCarne << " g de carne (total " << total << " g)\n";
    alimentar();
    return this;
}

/* ---------- Cuidador ---------- */
Cuidador::Cuidador(string nom, int exp) {
    nombre = nom;
    experiencia = exp;
    animalesAlimentados = 0;
    horasTrabajadasHoy = 0;
}

void Cuidador::mostrarInfo() {
    cout << "Cuidador: " << nombre << " - Experiencia: " << experiencia << " años\n"
         << "Animales alimentados hoy: " << animalesAlimentados
         << " - Horas trabajadas: " << horasTrabajadasHoy << endl;
}

void Cuidador::alimentarAnimal(Animal &animal) {
    cout << nombre << " está alimentando a " << animal.getNombre() << endl;
    animal.alimentarse();
    animalesAlimentados++;
    horasTrabajadasHoy += 0.5;
}

void Cuidador::resetearDia() {
    animalesAlimentados = 0;
    horasTrabajadasHoy = 0;
}

bool Cuidador::puedeTrabajar() {
    return horasTrabajadasHoy < MAX_HORAS_LABORALES;
}

string Cuidador::getNombre() { return nombre; }
int Cuidador::getAnimalesAlimentados() { return animalesAlimentados; }

/* ---------- Zona ---------- */
Zona::Zona(string nom, string habitat, int cap, float temp) {
    nombre = nom;
    tipoHabitat = habitat;
    capacidadMaxima = cap;
    animalesActuales = 0;
    temperaturaActual = temp;
    cabeza = nullptr;
}

Zona::~Zona() {
    // liberamos los nodos, pero NO los Animal* (el main los gestiona)
    NodoAnimal* actual = cabeza;
    while (actual) {
        NodoAnimal* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    cabeza = nullptr;
}

Zona& Zona::operator+(Animal* animal) {
    agregarAnimal(animal);
    return *this;
}

Animal* Zona::operator-(int id) {
    return removerAnimal(id);
}

bool Zona::puedeAgregarAnimal() {
    return animalesActuales < capacidadMaxima;
}

void Zona::agregarAnimal(Animal *animal) {
    if (!puedeAgregarAnimal()) {
        cout << "No se puede agregar más animales a " << nombre << endl;
        return;
    }

    NodoAnimal* nuevo = new NodoAnimal();
    nuevo->animal = animal;
    nuevo->siguiente = nullptr;

    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        NodoAnimal* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }

    animalesActuales++;
    cout << animal->getNombre() << " agregado a " << nombre << endl;
}

// remover por id
Animal* Zona::removerAnimal(int id) {
    if (!cabeza) {
        cout << "No hay animales en " << nombre << " para remover.\n";
        return nullptr;
    }

    NodoAnimal* actual = cabeza;
    NodoAnimal* previo = nullptr;

    while (actual) {
        if (actual->animal->getId() == id) {
            if (actual == cabeza) {
                cabeza = actual->siguiente;
            } else {
                previo->siguiente = actual->siguiente;
            }

            Animal* eliminado = actual->animal;
            delete actual;
            animalesActuales--;
            cout << "Animal con ID " << id << " removido de " << nombre << endl;
            return eliminado;
        }
        previo = actual;
        actual = actual->siguiente;
    }

    cout << "Animal con ID " << id << " no encontrado en " << nombre << endl;
    return nullptr;
}

void Zona::ajustarTemperatura(float nuevaTemp) {
    temperaturaActual = nuevaTemp;
    cout << "Temperatura de " << nombre << " ajustada a " << nuevaTemp << "°C\n";
}

string Zona::getNombre() { return nombre; }
int Zona::getAnimalesActuales() { return animalesActuales; }

/* ---------- Funciones globales ---------- */

void revisarEstadoNutricional(Animal &animal) {
    cout << "\n=== REVISION NUTRICIONAL (POR VALOR) ===\n";
    cout << "Revisando estado nutricional...\n";
    animal.mostrarInfo();
    cout << "Ración recomendada: " << animal.calcularRacionComida() << " g\n";

    if (animal.getTieneHambre()) {
        cout << "¡ALERTA! Este animal necesita alimentación urgente.\n";
    } else {
        cout << "Estado nutricional: BUENO\n";
    }
}

void procesarAlimentacionDiaria(Animal &animal, Cuidador &cuidador) {
    cout << "\n=== ALIMENTACION DIARIA (POR REFERENCIA) ===\n";
    cout << "Iniciando proceso de alimentación...\n";

    cout << "ANTES de alimentar:\n";
    animal.mostrarInfo();
    cuidador.mostrarInfo();

    if (cuidador.puedeTrabajar() && animal.getTieneHambre()) {
        cuidador.alimentarAnimal(animal);
        cout << "\nDESPUES de alimentar:\n";
        animal.mostrarInfo();
        cuidador.mostrarInfo();
    } else if (!cuidador.puedeTrabajar()) {
        cout << "Cuidador ha completado su jornada laboral.\n";
    } else {
        cout << "El animal no necesita alimentación en este momento.\n";
    }
}

void controlarAmbienteZona(Zona* zona) {
    cout << "\n=== CONTROL AMBIENTAL (POR PUNTERO) ===\n";
    cout << "Controlando condiciones ambientales...\n";

    cout << "Estado actual de la zona:\n";
    zona->mostrarInfo();

    auto calcularTemp = [zona](int animales){ return 22.0f + animales*2.0f; };
    zona->ajustarTemperatura(calcularTemp(zona->getAnimalesActuales()));

    cout << "Estado después del ajuste:\n";
    zona->mostrarInfo();
}

