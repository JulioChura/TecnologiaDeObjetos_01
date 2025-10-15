#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Matriz2D {
private:
    int filas;
    int columnas;
    vector<vector<double>> datos;

public:
    Matriz2D(int f, int c) : filas(f), columnas(c) {
        datos.resize(filas, vector<double>(columnas, 0.0));
    }
    
    inline int getFilas() const { return filas; }
    inline int getColumnas() const { return columnas; }
    
    inline bool posicionValida(int f, int c) const {
        return (f >= 0 && f < filas && c >= 0 && c < columnas);
    }
    
    void mostrarInfo() const {
        cout << "Matriz " << filas << "x" << columnas << endl;
    }
    
    void setValor(int f, int c, double valor) {
        if (posicionValida(f, c)) {
            datos[f][c] = valor;
        }
    }
    
    double getValor(int f, int c) const {
        if (posicionValida(f, c)) {
            return datos[f][c];
        }
        return 0;
    }
    
    Matriz2D operator+(const Matriz2D& otra) const {
        Matriz2D resultado(filas, columnas);
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                resultado.datos[i][j] = datos[i][j] + otra.datos[i][j];
            }
        }
        return resultado;
    }
    
    Matriz2D operator-(const Matriz2D& otra) const {
        Matriz2D resultado(filas, columnas);
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                resultado.datos[i][j] = datos[i][j] - otra.datos[i][j];
            }
        }
        return resultado;
    }
    
    Matriz2D operator*(double escalar) const {
        Matriz2D resultado(filas, columnas);
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                resultado.datos[i][j] = datos[i][j] * escalar;
            }
        }
        return resultado;
    }
    
    friend void aplicarCuadrado(Matriz2D& m);
    friend void imprimirMatriz(const Matriz2D& m);
};

void aplicarCuadrado(Matriz2D& m) {
    auto cuadrado = [](double x) { return x * x; };
    
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            m.datos[i][j] = cuadrado(m.datos[i][j]);
        }
    }
}

void imprimirMatriz(const Matriz2D& m) {
    for (int i = 0; i < m.filas; i++) {
        cout << "| ";
        for (int j = 0; j < m.columnas; j++) {
            cout << setw(8) << m.datos[i][j] << " ";
        }
        cout << "|" << endl;
    }
}

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
    
    cout << "\n3. Sobre carga de operadores:" << endl;
    cout << "Suma (A + B):" << endl;
    imprimirMatriz(A + B);
    
    cout << "Resta (A - B):" << endl;
    imprimirMatriz(A - B);
    
    cout << "Multiplicación por escalar (A * 2.5):" << endl;
    imprimirMatriz(A * 2.5);

    cout << "\n4. Función friend con lambda dentro:" << endl;
    cout << "Aplicando cuadrado a matriz A:" << endl;
    aplicarCuadrado(A);
    imprimirMatriz(A);

    return 0;
}