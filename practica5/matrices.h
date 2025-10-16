#ifndef MATRIZ2D_H
#define MATRIZ2D_H

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
    Matriz2D(int f, int c);

    inline int getFilas() const { return filas; }
    inline int getColumnas() const { return columnas; }
    inline bool posicionValida(int f, int c) const;

    void mostrarInfo() const;
    void setValor(int f, int c, double valor);
    double getValor(int f, int c) const;

    Matriz2D operator+(const Matriz2D& otra) const;
    Matriz2D operator-(const Matriz2D& otra) const;
    Matriz2D operator*(double escalar) const;

    friend void aplicarCuadrado(Matriz2D& m);
    friend void imprimirMatriz(const Matriz2D& m);
};

#endif
