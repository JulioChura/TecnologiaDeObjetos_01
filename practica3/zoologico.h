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
    string dieta; // a futuro volverlo un vector que guarde varios tipos de alimentos

public:
    Animal(string nom, string esp, float p, string dieta);
    void mostrarInfo();
    void pasarTiempo(int horas);
    string getNombre();
    bool getTieneHambre();
    int getHorasSinComer();
    void alimentar();
    virtual void alimentarse() = 0;
    virtual float calcularRacionComida() = 0;

    string getDieta(); 
};

class Herbivoro : public Animal {
public:
    float gramosVerduraPorKg;
    Herbivoro(string nom, string esp, float p, string die, float gramosPorKg);
    void alimentarse() override;
    float calcularRacionComida() override;
};

class Carnivoro : public Animal {
public:
    float gramosCarnePorKg;
    Carnivoro(string nom, string esp, float p, string die, float gramosPorKg);
    void alimentarse() override;
    float calcularRacionComida() override;
};

class Omnivoro : public Animal {
public:
    float gramosVerduraPorKg;
    float gramosCarnePorKg;
    Omnivoro(string nom, string esp, float p, string die, float verdura, float carne);
    void alimentarse() override;
    float calcularRacionComida() override;
};  

class Cuidador {
private:
    string nombre;
    int experiencia;
    int animalesAlimentados;
    float horasTrabajadasHoy;
    const int MAX_HORAS_LABORALES = 8;

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
