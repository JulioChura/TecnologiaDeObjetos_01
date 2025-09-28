#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Animal {
protected:
    string nombre;
    string especie;
    float peso;
    int horasDesdeUltimaComida;
    bool tieneHambre;

public:
    Animal(string nom, string esp, float p);
    virtual void mostrarInfo();
    void mostrarInfo();
    void pasarTiempo(int horas);
    float calcularRacionComida();
    string getNombre();
    bool getTieneHambre();
    int getHorasSinComer();
    void alimentar();
    virtual void alimentarse() = 0;
};

// mas adelante se pueden crear clases para los distintos tipos de alimentos que los animales consumen
class Herbivoro : public Animal {
public:
    string plantas;
    Herbivoro(string nom, string esp, float p, string pla);
    void alimentarse() override;
};

class Carnivoro : public Animal {
public:
    string carne;
    Carnivoro(string nom, float p, string car);
    void alimentarse() override;
};

class Omnivoro : public Animal {
public:
    string comidaMixta; 
    Omnivoro(string nom, float p, string comidaMixta);
    void alimentarse() override;
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
