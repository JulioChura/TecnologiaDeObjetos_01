#include <iostream> 
using namespace std;

float promedio(float *notas, int n) {
    float suma = 0;
    for ( int i = 0; i < n; i++ ) {
        suma = suma + *(notas + i);     
    }
    return suma/n;
}

float mayor(float *notas, int n) {
    float max = *notas;
    for ( int i = 1; i < n; i++ ) {
        if ( *(notas + i) > max  ) {
            max = *(notas  + i);
        }
    }
    return max;
}

float menor(float *notas, int n) {
    float min = *notas;
    for (int i = 1; i < n; i++) {
        if (*(notas + i) < min) {
            min = *(notas + i);
        }
    }
    return min;
}


void mostrarInverso(float *notas, int n) {
    cout << "Notas en orden inverso: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << *(notas + i) << " ";
    }
    cout << endl;
}

int main() {
    int n;
    
    cout << "Cantidad de estudiantes: ";
    cin >> n;
    
    float *ptr = new float[n];
    
    cout << "Ingrese las notas:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Estudiante " << i + 1 << ": ";
        cin >> *(ptr + i);
    }
    
    cout << "\nPromedio: " << promedio(ptr, n) << endl;
    cout << "Nota mayor: " << mayor(ptr, n) << endl;
    cout << "Nota menor: " << menor(ptr, n) << endl;
    mostrarInverso(ptr, n);
    
    delete[] ptr;
    
    return 0;
}