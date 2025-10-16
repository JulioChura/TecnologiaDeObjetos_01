#include "Matriz2D.h"

int main() {
    cout << " PROGRAMA DE MATRICES 2D " << endl;

    Matriz2D A(2, 3);
    Matriz2D B(2, 3);

    A.setValor(0, 0, 1.0);
    A.setValor(0, 1, 2.0);
    A.setValor(0, 2, 3.0);
    A.setValor(1, 0, 4.0);
    A.setValor(1, 1, 5.0);
    A.setValor(1, 2, 6.0);

    B.setValor(0, 0, 2.0);
    B.setValor(0, 1, 3.0);
    B.setValor(0, 2, 4.0);
    B.setValor(1, 0, 5.0);
    B.setValor(1, 1, 6.0);
    B.setValor(1, 2, 7.0);

    cout << "\n1. Matrices base:" << endl;
    cout << "Matriz A:" << endl;
    imprimirMatriz(A);
    cout << "Matriz B:" << endl;
    imprimirMatriz(B);

    cout << "\n2. Funcion (mostrarInfo):" << endl;
    A.mostrarInfo();
    B.mostrarInfo();

    cout << "\n3. Sobrecarga de operadores:" << endl;
    cout << "Suma (A + B):" << endl;
    imprimirMatriz(A + B);

    cout << "Resta (A - B):" << endl;
    imprimirMatriz(A - B);

    cout << "Multiplicacion por escalar (A * 2.5):" << endl;
    imprimirMatriz(A * 2.5);

    cout << "\n4. Funcion friend con lambda dentro:" << endl;
    cout << "Aplicando cuadrado a matriz A:" << endl;
    aplicarCuadrado(A);
    imprimirMatriz(A);

    return 0;
}
