//
// Created by Laloparkour on 24/05/2020.
//

#include "Prestamo.h"
#include <iostream>
#include <cstring>

using namespace std;

Prestamo::Prestamo() {}

Prestamo::Prestamo(int usuario, int pelicula, char fechaInicial[100]) {
    this->usuario = usuario;
    this-> pelicula = pelicula;
    strcpy(this->fechaInicial, fechaInicial);
    this->estado = 1;
}

void Prestamo::devolucion(char fechaFinal[100]) {
    strcpy(this->fechaInicial, fechaFinal);
    this->estado = 0;
}

int Prestamo::getUsuario() {
    return this->usuario;
}

int Prestamo::getPelicula() {
    return this->pelicula;
}

int Prestamo::getEstado() {
    return this->estado;
}

void Prestamo::toString() {
    cout << "Fecha Inicial "<< this->fechaInicial << endl;
    if(this->estado == 1){
        cout << "Estado del prestamo: Rentada"<<endl;
    }else{
        cout << "Estado del prestamo: Disponible"<<endl;
        cout << "Fecha final "<< this->fechaFinal << endl;
    }
}