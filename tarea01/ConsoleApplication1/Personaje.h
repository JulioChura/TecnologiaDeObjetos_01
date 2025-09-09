#pragma once
/*
Juego: Duelo de Titanes

Atributos del personaje:
- double vida: salud actual del personaje
- int defensa: puntos de escudo que absorben da�o antes de afectar la vida
- int ataqueBase: da�o base que el personaje puede causar
- int nivel: nivel actual del personaje
- bool estaVivo: indica si el personaje sigue en combate
- bool habilidadLista: indica si la habilidad especial est� disponible
- std::string nombre: nombre del personaje
- std::vector<Item> items: colecci�n de armas

Estructura Item:
- std::string nombre: nombre del arma
- int da�o: da�o adicional que aporta al ataque

Mec�nicas del juego:
- Juego por turnos: cada personaje puede atacar o defender.
- Al atacar, se selecciona autom�ticamente un arma aleatoria para aumentar el da�o.
- El da�o primero reduce la defensa (escudo), luego la vida.
- Cada personaje puede usar su habilidad especial una vez por pelea. Esta puede aumentar o reducir el ataque seg�n un valor aleatorio.
- Si la vida llega a 0 o menos, el personaje pierde.
- El ganador sube de nivel:
  - Su ataque base aumenta en +2
  - Su vida y defensa se restauran
  - Su habilidad especial se recarga
  - Obtiene el arma m�s poderosa del enemigo derrotado
*/

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

struct Item {
	string nombre;
	int da�o;
};

class Personaje {
private:
	string nombre;
	double vida;
	int defensa;
	int ataqueBase;
	bool estaVivo;
	bool habilidadLista;
	vector<Item> items;

	// aplica da�o al personaje, primero a defensa, luego a la vida
	void recibirDa�o(int cantidad);
	Item obtenerMejorArma();

protected:
	Item obtenerMejorArma();

public:
	Personaje(const string& n, double v, int d, int a, const vector<Item>& armas);

	void atacar(Personaje& enemigo);
	void defender();
	void usarHabilidadEspecial();
	void mostrarEstado();

	// Getters y setters
	double getVida();
	void setVida(double nuevaVida);

	int getDefensa();
	void setDefensa(int nuevaDefensa);

	bool getEstaVivo();
	void setEstaVivo(bool estado);

	string getNombre();
	void setNombre(string nuevoNombre);

	void setAtaqueBase(int nuevoAtaque);
	int getAtaqueBase();

	void setHabilidadLista(bool nuevoEstado);
	bool getHabilidadLista();

};

