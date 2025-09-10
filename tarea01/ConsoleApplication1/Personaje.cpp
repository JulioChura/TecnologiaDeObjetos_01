#include "Personaje.h"
#include <iostream>
#include <cstdlib>
#include <ctime>	
#include <string>

using namespace std;



Personaje::Personaje(const string& n, double v, int d, int a, const vector<Item>& armas) {
	nombre = n;
	vida = v;
	defensa = d;
	ataqueBase = a;
	estaVivo = true;
	items = armas;
}

// metodo privado 
void Personaje::recibirDanio(int cantidad, Personaje& enemigo) {
	if (getDefensa() >= cantidad) {
		setDefensa(getDefensa() - cantidad);
	}
	else {	
		int danioTotal = cantidad - getDefensa();
		setDefensa(0);
		setVida(getVida() - danioTotal);

		if (getVida() <= 0) {
			setVida(0);
			setEstaVivo(false);

			if ( items.empty() ) {
				cout << nombre << " no tiene armas para entregar." << endl;
				return;
			}

			Item item = obtenerArmaParaEntregar();  
			item.disponible = true;          
			asignarArma(item, enemigo);

			cout << nombre << " ha sido derrotado! " << endl;

		}
	}
}

Item* Personaje::buscarMejorArma(bool soloDisponibles) {
	Item* mejorArma = nullptr;
	for (Item& arma : items) {
		if (soloDisponibles && !arma.disponible) continue;

		// Si aún no hay mejor arma o esta arma es mejor, actualizar
		if (!mejorArma || arma.danio > mejorArma->danio) {
			mejorArma = &arma;
		}
	}
	return mejorArma;
}


// Usar para atacar
Item Personaje::obtenerArmaParaAtacar() {
	Item* arma = buscarMejorArma(true); // solo disponibles
	if (!arma) return { "Puños", 0 };
	arma->disponible = false; 
	return *arma;
}

// Usar para entregar la arma al enemigo
Item Personaje::obtenerArmaParaEntregar() {
	Item* arma = buscarMejorArma(false); // ignora si está o no disponible
	if (!arma) return { "Puños", 0 };
	return *arma; 
}


void Personaje::asignarArma(const Item& item, Personaje& enemigo) {
	enemigo.items.push_back(item);
}


void Personaje::atacar(Personaje& enemigo) {
	cout << nombre << " ataca a " << enemigo.getNombre() << "!" << endl;	
	Item arma = obtenerArmaParaAtacar();  
	int ataqueTotal = getAtaqueBase() + arma.danio;
	enemigo.recibirDanio(ataqueTotal, *this);  
}


void Personaje::mostrarEstado() {
    if(estaVivo){
        cout<<"Estado de " <<nombre << endl;
        cout<<"Vida: " <<vida << endl;
        cout<<"Defensa: "<< defensa << endl;
        cout<<"Ataque: "<< ataqueBase << endl;
		mostrarItems();
    }
    else
        cout<< nombre << " está muerto" <<endl;
}

void Personaje::mostrarItems() {
	if (items.empty()) {
		cout << nombre << " no tiene armas." << endl;
		return;
	}
	else {
		cout << "Armas de " << nombre << ":" << endl;
		for (const Item& arma : items) {
			cout << "- " << arma.nombre << " (Daño: " << arma.danio 
				 << ", " << (arma.disponible ? "Disponible" : "No disponible") << ")" << endl;
		}
	}
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

