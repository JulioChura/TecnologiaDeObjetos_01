#include <iostream>
#include <vector>
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
    Animal(string nom, string esp, float p);
    void mostrarInfo();
    void alimentar();
    void pasarTiempo(int horas);
    float calcularRacionComida();
    string getNombre();
    bool getTieneHambre();
    int getHorasSinComer();
};

class Cuidador {
private:
    string nombre;
    int experiencia;
    int animalesAlimentados;
    float horasTrabajadasHoy;

public:
    Cuidador(string nom, int exp);
    void mostrarInfo();
    void alimentarAnimal(Animal &animal);
    void resetearDia();
    bool puedeTrabajar();
    string getNombre();
    int getAnimalesAlimentados();
};

class Zona {
private:
    string nombre;
    string tipoHabitat;
    int capacidadMaxima;
    int animalesActuales;
    float temperaturaActual;
    vector<Animal*> animales;

public:
    Zona(string nom, string habitat, int cap, float temp);
    void mostrarInfo();
    bool puedeAgregarAnimal();
    void agregarAnimal(Animal *animal);
    void ajustarTemperatura(float nuevaTemp);
    string getNombre();
    int getAnimalesActuales();
};

void revisarEstadoNutricional(Animal &animal);
void procesarAlimentacionDiaria(Animal &animal, Cuidador &cuidador);
void controlarAmbienteZona(Zona* zona);
