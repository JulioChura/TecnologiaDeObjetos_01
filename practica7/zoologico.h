#pragma once
#include <iostream>
#include <string>
using namespace std;
//
class Animal
{
protected:
    int id;
    string nombre;
    string especie;
    float peso;
    int horasDesdeUltimaComida;
    bool tieneHambre;
    string dieta;

    static int contadorId;

public:
    Animal(string nom, string esp, float p, string dieta);
    virtual ~Animal(); // importante para borrar derivados vía Animal*
    void mostrarInfo() const;
    void pasarTiempo(int horas);
    string getNombre() const;
    bool getTieneHambre() const;
    int getHorasSinComer() const;
    int getId() const;
    void alimentar();

    // uso de covarianza
    virtual Animal *alimentarse() = 0;
    virtual float calcularRacionComida() = 0;
    string getDieta() const;

    friend ostream &operator<<(ostream &os, const Animal &a); // friend
};

class Herbivoro : public Animal
{
public:
    float gramosVerduraPorKg;
    Herbivoro(string nom, string esp, float p, string die, float gramosPorKg);
    Animal *alimentarse() override;
    float calcularRacionComida() override;
};

class Carnivoro : public Animal
{
public:
    float gramosCarnePorKg;
    Carnivoro(string nom, string esp, float p, string die, float gramosPorKg);
    Animal *alimentarse() override;
    float calcularRacionComida() override;
};

class Omnivoro : public Animal
{
public:
    float gramosVerduraPorKg;
    float gramosCarnePorKg;
    Omnivoro(string nom, string esp, float p, string die, float verdura, float carne);
    Animal *alimentarse() override;
    float calcularRacionComida() override;
};

class Cuidador
{
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

struct NodoAnimal
{
    Animal *animal;
    NodoAnimal *siguiente;
};

class Zona
{
private:
    string nombre;
    string tipoHabitat;
    int capacidadMaxima;
    int animalesActuales;
    float temperaturaActual;
    NodoAnimal *cabeza;

public:
    Zona(string nom, string habitat, int cap, float temp);
    ~Zona(); // libera nodos de la lista (no libera los Animal* porque el main los gestiona)
    
    inline void mostrarInfo() const
    {
        cout << "Zona: " << nombre << " (" << tipoHabitat << ")\n";
        cout << "Ocupación: " << animalesActuales << "/" << capacidadMaxima
             << " - Temperatura: " << temperaturaActual << "°C\n";
        cout << "--- Animales en esta zona ---\n";
        if (!cabeza)
            cout << "No hay animales\n";
        else
        {
            NodoAnimal *actual = cabeza;
            while (actual)
            {
                cout << *(actual->animal) << endl; // uso friend
                actual = actual->siguiente;
            }
        }
    }

    bool puedeAgregarAnimal();
    void agregarAnimal(Animal *animal);
    void ajustarTemperatura(float nuevaTemp);
    Animal *removerAnimal(int id); // ahora remueve por id
    string getNombre();
    int getAnimalesActuales();

    // uso de carga de operadores
    Zona& operator+(Animal* animal); 
    Animal* operator-(int id);    
};

// funciones globales
void revisarEstadoNutricional(Animal &animal);
void procesarAlimentacionDiaria(Animal &animal, Cuidador &cuidador);
void controlarAmbienteZona(Zona *zona);
