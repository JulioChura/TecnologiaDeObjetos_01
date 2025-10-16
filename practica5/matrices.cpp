#include "Matriz2D.h"

Matriz2D::Matriz2D(int f, int c) : filas(f), columnas(c) {
    datos.resize(filas, vector<double>(columnas, 0.0));
}

bool Matriz2D::posicionValida(int f, int c) const {
    return (f >= 0 && f < filas && c >= 0 && c < columnas);
}

void Matriz2D::mostrarInfo() const {
    cout << "Matriz " << filas << "x" << columnas << endl;
}

void Matriz2D::setValor(int f, int c, double valor) {
    if (posicionValida(f, c)) {
        datos[f][c] = valor;
    }
}

double Matriz2D::getValor(int f, int c) const {
    if (posicionValida(f, c)) {
        return datos[f][c];
    }
    return 0;
}

Matriz2D Matriz2D::operator+(const Matriz2D& otra) const {
    Matriz2D resultado(filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado.datos[i][j] = datos[i][j] + otra.datos[i][j];
        }
    }
    return resultado;
}

Matriz2D Matriz2D::operator-(const Matriz2D& otra) const {
    Matriz2D resultado(filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado.datos[i][j] = datos[i][j] - otra.datos[i][j];
        }
    }
    return resultado;
}

Matriz2D Matriz2D::operator*(double escalar) const {
    Matriz2D resultado(filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado.datos[i][j] = datos[i][j] * escalar;
        }
    }
    return resultado;
}

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
