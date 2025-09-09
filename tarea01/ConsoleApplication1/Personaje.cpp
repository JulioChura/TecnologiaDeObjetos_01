#include "Personaje.h"
#include <iostream>
#include <cstdlib>
#include <ctime>	
#include <string>

using namespace std;


const int INCREMENTO_MAXIMO = 5;
const int INCREMENTO_MINIMO = 1;

Personaje::Personaje(const string& n, double v, int d, int a, const vector<Item>& armas) {
	nombre = n;
	vida = v;
	defensa = d;
	ataqueBase = a;
	estaVivo = true;
	habilidadLista = true;
	items = armas;
}

// metodo privado 
void Personaje::recibirDaño(int cantidad, Personaje& enemigo) {
	if (getDefensa() >= cantidad) {
		setDefensa(getDefensa() - cantidad);
	}
	else {	
		int dañoTotal = cantidad - getDefensa();
		setDefensa(0);
		setVida(getVida() - dañoTotal);

		if (getVida() <= 0) {
			setVida(0);
			setEstaVivo(false);

			if ( items.empty() ) {
				cout << nombre << " no tiene armas para entregar." << endl;
				return;
			}

			Item item = obtenerMejorArma();
			item.disponible = true;
			asignarArma(item, enemigo);
			cout << nombre << " ha sido derrotado! " << endl;

		}
	}
}

// Metodo privado: devuelve el arma con mayor daño
Item Personaje::obtenerMejorArma() {
	if (items.empty()) {
		return {"Puños", 0}; 
	}
	Item mejorArma = items[0];	
	for (auto arma : items) {
		if (arma.daño > mejorArma.daño && arma.disponible ) {
			mejorArma = arma;
			mejorArma.disponible = false;
		}
	}
	return mejorArma;
}

void Personaje::asignarArma(const Item& item, Personaje& enemigo) {
	enemigo.items.push_back(item);
}


void Personaje::atacar(Personaje& enemigo) {
	cout << nombre << " ataca a " << enemigo.getNombre() << "!" << endl;	
	int ataqueArma = obtenerMejorArma().daño;
	int ataqueTotal = getAtaqueBase() + ataqueArma;
	enemigo.recibirDaño(ataqueTotal);
}
 
// aumenta el ataque base 
void Personaje::usarHabilidadEspecial() {
	if (!getHabilidadLista()) {
		cout << "Habilidad especial no está lista para " << nombre << "!" << endl;
		return;
	}
	srand(time(0)); // mandar al main
	int incremento = rand() % (INCREMENTO_MAXIMO - INCREMENTO_MINIMO + 1) + INCREMENTO_MINIMO;
	setAtaqueBase(getAtaqueBase() + incremento);
	cout << nombre << " usa su habilidad especial! Ataque incrementado en " << incremento << " puntos." << endl;
	setHabilidadLista(false);
}


void Personaje::mostrarEstado() {

}

// Getters y setters
double Personaje::getVida() { 
	return vida; 
}

void Personaje::setVida(double nuevaVida) { 
	vida = nuevaVida; 
}

int Personaje::getDefensa() { 
	return defensa; 
}

void Personaje::setDefensa(int nuevaDefensa) { 
	defensa = nuevaDefensa; 
}

bool Personaje::getEstaVivo() { 
	return estaVivo; 
}

void Personaje::setEstaVivo(bool estado) { 
	estaVivo = estado; 
}

string Personaje::getNombre() { 
	return nombre; 
}

void Personaje::setNombre(string nuevoNombre) { 
	nombre = nuevoNombre; 
}

int Personaje::getAtaqueBase() {
	return ataqueBase;
}

void Personaje::setAtaqueBase(int nuevoAtaque) {
	ataqueBase = nuevoAtaque;
}

void Personaje::setHabilidadLista(bool nuevoEstado) {
	habilidadLista = nuevoEstado;
}
bool Personaje::getHabilidadLista() {
	return habilidadLista;
}
