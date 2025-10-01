#include "zoologico.h"

int Animal::contadorId = 1;

Animal::Animal(string nom, string esp, float p, string die) {
    id = contadorId++; //Asigna el id
    nombre = nom;
    especie = esp;
    peso = p;
    horasDesdeUltimaComida = 8;
    tieneHambre = true;
    dieta = die;
}

void Animal::mostrarInfo() {
    cout << nombre << " (" << especie << ") - Peso: " << peso << "kg - "
         << "Horas sin comer: " << horasDesdeUltimaComida;
    if (tieneHambre) {
        cout << " [HAMBRIENTO]";
    } else {
        cout << " [ALIMENTADO]";
    }
    cout << endl;
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

//Metodo para obtener el id de animal
int Animal::getId() const { return id; }

string Animal::getNombre() { return nombre; }
bool Animal::getTieneHambre() { return tieneHambre; }
int Animal::getHorasSinComer() { return horasDesdeUltimaComida; }


Herbivoro::Herbivoro(string nom, string esp, float p, string die, float gramosPorKg)
    : Animal(nom, esp, p, die), gramosVerduraPorKg(gramosPorKg) {}

void Herbivoro::alimentarse() {
    float racion = calcularRacionComida(); 
    cout << nombre << " come " << racion << " g de vegetales.\n";
    alimentar(); // se marca como alimentado
}
float Herbivoro::calcularRacionComida() {
    return gramosVerduraPorKg * peso;
}

Carnivoro::Carnivoro(string nom, string esp, float p, string die, float gramosPorKg)
    : Animal(nom, esp, p, die), gramosCarnePorKg(gramosPorKg) {}
float Carnivoro::calcularRacionComida() {
    return gramosCarnePorKg * peso;
}
void Carnivoro::alimentarse() {
    float racion = calcularRacionComida();
    cout << nombre << " come " << racion << " g de carne.\n";
    alimentar(); 
}


Omnivoro::Omnivoro(string nom, string esp, float p, string die, float verdura, float carne)
    : Animal(nom, esp, p, die), gramosVerduraPorKg(verdura), gramosCarnePorKg(carne) {}
float Omnivoro::calcularRacionComida() {
    return (gramosVerduraPorKg + gramosCarnePorKg) * peso;
}
void Omnivoro::alimentarse() {
    float racionVerdura = gramosVerduraPorKg * peso;
    float racionCarne = gramosCarnePorKg * peso;
    float total = calcularRacionComida();
    cout << nombre << " come " << racionVerdura << " g de vegetales y "
         << racionCarne << " g de carne (total " << total << " g)\n";
    alimentar();
}


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

Zona::Zona(string nom, string habitat, int cap, float temp) {
    nombre = nom;
    tipoHabitat = habitat;
    capacidadMaxima = cap;
    animalesActuales = 0;
    temperaturaActual = temp;
    cabeza = nullptr; 
}

void Zona::mostrarInfo() {
    cout << "Zona: " << nombre << " (" << tipoHabitat << ")\n"
         << "Ocupación: " << animalesActuales << "/" << capacidadMaxima
         << " - Temperatura: " << temperaturaActual << "°C" << endl;
    cout << "--- Animales en esta zona ---";
    
    /*for (Animal* a : animales) {
        a->mostrarInfo();
    }
    if ( animales.empty() ) {
        cout << "No hay animales en esta zona";
    }*/
    
    if (!cabeza) {
        cout << "No hay animales en esta zona\n";
        return;
    }

    NodoAnimal* actual = cabeza;
    while (actual) {
        actual->animal->mostrarInfo();
        actual = actual->siguiente;
    }

}

bool Zona::puedeAgregarAnimal() {
    return animalesActuales < capacidadMaxima;
}

void Zona::agregarAnimal(Animal *animal) {
    if (!puedeAgregarAnimal()) {
        cout << "No se puede agregar más animales a " << nombre << endl;
        return;
    } else {
        NodoAnimal* nuevo = new NodoAnimal();
        if ( cabeza == nullptr ) {
            cabeza = nuevo;
            cabeza->animal = animal;
            cabeza->siguiente = nullptr;
        } else {
            NodoAnimal* actual = cabeza;
            while(actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            nuevo->animal = animal;
            nuevo->siguiente = nullptr;
            actual->siguiente = nuevo;

            cout << animal->getNombre() << " agregado a " << nombre << endl;
        }
    }
    animalesActuales++;
}

// remover por nombre
Animal* Zona::removerAnimal(Animal *animal) {
    if ( cabeza == nullptr ) {
        cout << "No hay animales en " << nombre << " para remover.\n";
        return;
    }
    NodoAnimal* retornar = nullptr;
    NodoAnimal* aux = nullptr;
    NodoAnimal* actual = cabeza;
    while (actual != nullptr ) {
        if ( actual->animal->getNombre() == animal->getNombre() ) {
            // a-b-c-d
            // a
            /*
            si cabeza es igual a actual
                auxiliar = cabeza
                cabeza.animal = nullptr
                return auxiliar

            nodoTemporal = actual
            mientras nodoTemporal.siguiente no es nulo y el nodo siguiente no es igual
                nodoTemporal = nodoTemporal.siguiente

            si nodoTemporal.siguiente es nulo
                no se encontro
                return
            
            auxiliar = nodoTemporal.siguiente // recuperé el nodo
            nodoTemporal.siguiente = auxuiliar.siguiente // salteo el nodo
            
            retorno auxiliar 
            
            */

            aux = actual;
            retornar = actual;

            animalesActuales--;
        }
        actual = actual->siguiente;
    }
    
}

void Zona::ajustarTemperatura(float nuevaTemp) {
    temperaturaActual = nuevaTemp;
    cout << "Temperatura de " << nombre << " ajustada a " << nuevaTemp << "°C\n";
}

string Zona::getNombre() { return nombre; }
int Zona::getAnimalesActuales() { return animalesActuales; }

void revisarEstadoNutricional(Animal &animal) {
    cout << "\n=== REVISION NUTRICIONAL (POR VALOR) ===\n";
    cout << "Revisando estado nutricional...\n";
    animal.mostrarInfo();
    cout << "Ración recomendada: " << animal.calcularRacionComida() << "kg\n";
    
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
    
    float nuevaTemp = 22.0 + (zona->getAnimalesActuales() * 2.0);
    zona->ajustarTemperatura(nuevaTemp);
    
    cout << "Estado después del ajuste:\n";
    zona->mostrarInfo();
}
