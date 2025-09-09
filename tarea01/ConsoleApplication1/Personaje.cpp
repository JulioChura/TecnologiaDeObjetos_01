#include "Personaje.h"
#include <iostream>
#include <cstdlib>
#include <ctime>	
#include <string>

using namespace std;


const double VIDA_BASE = 20.0;
const int DEFENSA_BASE = 10;
const int ATAQUE_INCREMENTO_NIVEL = 2;

Personaje::Personaje(const string& n, double v, int d, int a, const vector<Item>& armas) {
	nombre = n;
	vida = v;
	defensa = d;
	ataqueBase = a;
	nivel = 1;
	estaVivo = true;
	habilidadLista = true;
	items = armas;
}

// metodo privado 
void Personaje::recibirDaño(int cantidad) {
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
			cout << nombre << " ha sido derrotado! " << endl;
		}
	}
}

// Metodo privado: devuelve el arma con mayor daño
Item Personaje::obtenerMejorArma() {
	

}

// Método protegido: restaura vida y defensa al subir de nivel
void Personaje::restaurarEstado() {

}

void Personaje::atacar(Personaje& enemigo) {
	enemigo.recibirDaño(ataqueBase);
}



void Personaje::usarHabilidadEspecial() {

}

void Personaje::subirNivel(Personaje& enemigoDerrotado) {

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