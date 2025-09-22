#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string nombre;
    string especie;
    float peso;
    int horasDesdeUltimaComida;
    bool tieneHambre;

public:
    Animal(string nom, string esp, float p) {
        nombre = nom;
        especie = esp;
        peso = p;
        horasDesdeUltimaComida = 8; // Inicia con hambre
        tieneHambre = true;
    }
    
    void mostrarInfo() {
        cout << nombre << " (" << especie << ") - Peso: " << peso << "kg - "
             << "Horas sin comer: " << horasDesdeUltimaComida;
        if (tieneHambre) {
            cout << " [HAMBRIENTO]";
        } else {
            cout << " [ALIMENTADO]";
        }
        cout << endl;
    }
    
    void alimentar() {
        horasDesdeUltimaComida = 0;
        tieneHambre = false;
        cout << nombre << " ha sido alimentado.\n";
    }
    
    void pasarTiempo(int horas) {
        horasDesdeUltimaComida += horas;
        if (horasDesdeUltimaComida >= 6) {
            tieneHambre = true;
        }
    }
    
    float calcularRacionComida() {
        return peso * 0.05; // 5% del peso corporal
    }
    
    string getNombre() { return nombre; }
    bool getTieneHambre() { return tieneHambre; }
    int getHorasSinComer() { return horasDesdeUltimaComida; }
};

class Cuidador {
private:
    string nombre;
    int experiencia;
    int animalesAlimentados;
    float horasTrabajadasHoy;

public:
    Cuidador(string nom, int exp) {
        nombre = nom;
        experiencia = exp;
        animalesAlimentados = 0;
        horasTrabajadasHoy = 0;
    }
    
    void mostrarInfo() {
        cout << "Cuidador: " << nombre << " - Experiencia: " << experiencia << " años\n"
             << "Animales alimentados hoy: " << animalesAlimentados 
             << " - Horas trabajadas: " << horasTrabajadasHoy << endl;
    }
    
    void alimentarAnimal(Animal &animal) {
        cout << nombre << " está alimentando a " << animal.getNombre() << endl;
        animal.alimentar();
        animalesAlimentados++;
        horasTrabajadasHoy += 0.5; 
    }
    
    void resetearDia() {
        animalesAlimentados = 0;
        horasTrabajadasHoy = 0;
    }
    
    bool puedeTrabajar() {
        return horasTrabajadasHoy < 8.0;
    }
    
    string getNombre() { return nombre; }
    int getAnimalesAlimentados() { return animalesAlimentados; }
};

// zona del zoologico
class Zona {
private:
    string nombre;
    string tipoHabitat;
    int capacidadMaxima;
    int animalesActuales;
    float temperaturaActual;

public:
    Zona(string nom, string habitat, int cap, float temp) {
        nombre = nom;
        tipoHabitat = habitat;
        capacidadMaxima = cap;
        animalesActuales = 0;
        temperaturaActual = temp;
    }
    
    void mostrarInfo() {
        cout << "Zona: " << nombre << " (" << tipoHabitat << ")\n"
             << "Ocupación: " << animalesActuales << "/" << capacidadMaxima
             << " - Temperatura: " << temperaturaActual << "°C" << endl;
    }
    
    bool puedeAgregarAnimal() {
        return animalesActuales < capacidadMaxima;
    }
    
    void agregarAnimal() {
        if (puedeAgregarAnimal()) {
            animalesActuales++;
        }
    }
    
    void ajustarTemperatura(float nuevaTemp) {
        temperaturaActual = nuevaTemp;
        cout << "Temperatura de " << nombre << " ajustada a " << nuevaTemp << "°C\n";
    }
    
    string getNombre() { return nombre; }
    int getAnimalesActuales() { return animalesActuales; }
};
