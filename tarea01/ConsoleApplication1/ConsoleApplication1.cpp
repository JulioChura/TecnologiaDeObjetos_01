#include <iostream>
#include <vector>
#include <string>
#include "Personaje.h"

using namespace std;

int main() {
    //Semilla para números aleatorios
    srand(time(0));

    string nombre1, nombre2;
    double vida1, vida2;
    int defensa1, defensa2, ataque1, ataque2;

    cout << "Jugador 1 crea tu personaje" << endl;
    cout << "Nombre: ";
    cin >> nombre1;
    cout << "Vida: ";
    cin >> vida1;
    cout << "Defensa: ";
    cin >> defensa1;
    cout << "Ataque base: ";
    cin >> ataque1;
    //la primer arma
    vector<Item> armas1 = {  };
    Personaje jugador1(nombre1, vida1, defensa1, ataque1, armas1);

    cout << "\nJugador 2 crea tu personaje" << endl;
    cout << "Nombre: ";
    cin >> nombre2;
    cout << "Vida: ";
    cin >> vida2;
    cout << "Defensa: ";
    cin >> defensa2;
    cout << "Ataque base: ";
    cin >> ataque2;
    //segunda arma
    vector<Item> armas2 = { {"hacha", 4} };
    Personaje jugador2(nombre2, vida2, defensa2, ataque2, armas2);

    cout << "\n" << jugador1.getNombre() << " VS " << jugador2.getNombre() << "\n" << endl;
    jugador1.mostrarEstado();
    cout << endl;
    jugador2.mostrarEstado();
    cout << endl;

    cout << "Comienza el enfrentamiento" << endl;

    int turno = 1;
    while (jugador1.getEstaVivo() && jugador2.getEstaVivo()) {
        cout << "\nTurno " << turno << endl;

        if (turno % 2 == 1) {
            jugador1.atacar(jugador2);
        }
        else {
            jugador2.atacar(jugador1);
        }

        cout << endl;
        jugador1.mostrarEstado();
        cout << endl;
        jugador2.mostrarEstado();

        turno++;
    }

    cout << "\nFin del enfrentamiento" << endl;
    if (jugador1.getEstaVivo()) {
        cout << jugador1.getNombre() << " es el ganador!" << endl;
    }
    else {
        cout << jugador2.getNombre() << " es el ganador!" << endl;
    }

    return 0;
}