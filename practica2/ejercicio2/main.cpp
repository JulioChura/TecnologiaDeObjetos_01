// funciones externas para gestionar la alimentacion

void revisarEstadoNutricional(Animal animal) {
    cout << "\n=== REVISION NUTRICIONAL (POR VALOR) ===\n";
    cout << "Revisando estado nutricional...\n";
    animal.mostrarInfo();
    cout << "Ración recomendada: " << animal.calcularRacionComida() << "kg\n";
    
    if (animal.getTieneHambre()) {
        cout << "¡ALERTA! Este animal necesita alimentación urgente.\n";
    } else {
        cout << "Estado nutricional: BUENO\n";
    }
}

// funcion por referencia
void procesarAlimentacionDiaria(Animal &animal, Cuidador &cuidador) {
    cout << "\n=== ALIMENTACION DIARIA (POR REFERENCIA) ===\n";
    cout << "Iniciando proceso de alimentación...\n";
    
    cout << "ANTES de alimentar:\n";
    animal.mostrarInfo();
    cuidador.mostrarInfo();
    
    if (cuidador.puedeTrabajar() && animal.getTieneHambre()) {
        cuidador.alimentarAnimal(animal);
        cout << "\nDESPUES de alimentar:\n";
        animal.mostrarInfo();
        cuidador.mostrarInfo();
    } else if (!cuidador.puedeTrabajar()) {
        cout << "Cuidador ha completado su jornada laboral.\n";
    } else {
        cout << "El animal no necesita alimentación en este momento.\n";
    }
}

// funcion por puntero
void controlarAmbienteZona(Zona* zona) {
    cout << "\n=== CONTROL AMBIENTAL (POR PUNTERO) ===\n";
    cout << "Controlando condiciones ambientales...\n";
    
    cout << "Estado actual de la zona:\n";
    zona->mostrarInfo();
    
    // Simular ajuste de temperatura segun ocupación
    float nuevaTemp = 22.0 + (zona->getAnimalesActuales() * 2.0);
    zona->ajustarTemperatura(nuevaTemp);
    
    cout << "Estado después del ajuste:\n";
    zona->mostrarInfo();
}
