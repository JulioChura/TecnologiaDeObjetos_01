#include <iostream>
#include "zoologico.cpp"
using namespace std;
int main() {
    cout << "=== SISTEMA DE GESTION DE ALIMENTACION - ZOOLOGICO ===\n";
    
    // Creacion de objetos dinámicamente con new
    Animal* leon = new Animal("Simba", "Leon Africano", 180.0);
    Animal* elefante = new Animal("Dumbo", "Elefante Africano", 4000.0);
    Animal* panda = new Animal("Bamboo", "Oso Panda", 120.0);
    
    Cuidador* maria = new Cuidador("Maria Rodriguez", 5);
    Cuidador* carlos = new Cuidador("Carlos Mendez", 8);
    
    Zona* sabana = new Zona("Sabana Africana", "Pradera", 8, 25.0);
    Zona* bosqueTropical = new Zona("Bosque Tropical", "Selva", 12, 28.0);
    Zona* montaña = new Zona("Montañas Asiáticas", "Montaña", 6, 18.0);
    
    sabana->agregarAnimal(leon); // Leon
    sabana->agregarAnimal(elefante); // Elefante  
    montaña->agregarAnimal(panda); // Panda
    
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
    
    // DEMOSTRAR LAS 3 FUNCIONES REQUERIDAS
    
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
    
    // Simular más paso de tiempo para crear hambre
    cout << "\n=== SIMULACION: PASO DE 3 HORAS MAS ===\n";
    leon->pasarTiempo(3);
    elefante->pasarTiempo(3);
    panda->pasarTiempo(3);
    
    cout << "\n=== ESTADO FINAL DEL SISTEMA ===\n";
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
    
    // Liberar memoria
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