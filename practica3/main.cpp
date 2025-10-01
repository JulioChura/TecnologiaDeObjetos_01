#include <iostream>
#include "zoologico.h"
using namespace std;

int main() {
    cout << "=== SISTEMA DE GESTION DE ALIMENTACION - ZOOLOGICO ===\n";

    // crear ejemplos usando clases derivadas (Animal es abstracta)
    Animal* leon = new Carnivoro("Simba", "Leon Africano", 180.0, "Carne", 50.0); // 50 g por kg
    Animal* elefante = new Herbivoro("Dumbo", "Elefante Africano", 4000.0, "Hierba", 30.0); // 30 g/kg
    Animal* panda = new Omnivoro("Bamboo", "Oso Panda", 120.0, "Mixta", 20.0, 10.0); // verd 20g/kg, carne 10g/kg

    Cuidador* maria = new Cuidador("Maria Rodriguez", 5);
    Cuidador* carlos = new Cuidador("Carlos Mendez", 8);

    Zona* sabana = new Zona("Sabana Africana", "Pradera", 8, 25.0);
    Zona* bosqueTropical = new Zona("Bosque Tropical", "Selva", 12, 28.0);
    Zona* montaña = new Zona("Montañas Asiáticas", "Montaña", 6, 18.0);

    sabana->agregarAnimal(leon);
    sabana->agregarAnimal(elefante);
    montaña->agregarAnimal(panda);

    cout << "\n=== ESTADO INICIAL DEL ZOOLOGICO ===\n";
    cout << "\n--- ANIMALES ---\n";
    leon->mostrarInfo();
    elefante->mostrarInfo();
    panda->mostrarInfo();

    cout << "\n--- CUIDADORES ---\n";
    maria->mostrarInfo();
    carlos->mostrarInfo();

    cout << "\n--- ZONAS ---\n";
    sabana->mostrarInfo();
    bosqueTropical->mostrarInfo();
    montaña->mostrarInfo();

    // 1. Función por VALOR - Revisiones nutricionales
    revisarEstadoNutricional(*leon);
    revisarEstadoNutricional(*panda);

    // 2. Función por REFERENCIA - Proceso de alimentación
    procesarAlimentacionDiaria(*leon, *maria);
    procesarAlimentacionDiaria(*elefante, *maria);
    procesarAlimentacionDiaria(*panda, *carlos);

    // Simular paso del tiempo
    cout << "\n=== SIMULACION: PASO DE 4 HORAS ===\n";
    leon->pasarTiempo(4);
    elefante->pasarTiempo(4);
    panda->pasarTiempo(4);

    // Intentar alimentar animales que ya no tienen hambre
    procesarAlimentacionDiaria(*leon, *carlos);

    // 3. Función por PUNTERO - Control ambiental
    controlarAmbienteZona(sabana);
    controlarAmbienteZona(montaña);

    // borrando animal de una zona (remover panda de montaña)
    Animal* eliminado = montaña->removerAnimal(panda->getId());
    if (eliminado) {
        cout << "Eliminado: " << eliminado->getNombre() << endl;
    }

    // Simular más paso de tiempo
    cout << "\n=== SIMULACION: PASO DE 3 HORAS MAS ===\n";
    leon->pasarTiempo(3);
    elefante->pasarTiempo(3);

    cout << "\n=== ESTADO FINAL DEL SISTEMA ===\n";
    cout << "\n--- ANIMALES ---\n";
    leon->mostrarInfo();
    elefante->mostrarInfo();

    cout << "\n--- CUIDADORES ---\n";
    maria->mostrarInfo();
    carlos->mostrarInfo();

    cout << "\n--- ZONAS ---\n";
    sabana->mostrarInfo();
    bosqueTropical->mostrarInfo();
    montaña->mostrarInfo();

    //eliminar objetos (zonas liberan nodos pero no los Animal*)
    delete leon;
    delete elefante;
    delete panda;
    delete maria;
    delete carlos;
    delete sabana;
    delete bosqueTropical;
    delete montaña;

    cout << "\nSistema finalizado correctamente.\n";
    return 0;
}

