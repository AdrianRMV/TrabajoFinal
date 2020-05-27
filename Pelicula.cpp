//
// Created by Laloparkour on 23/05/2020.
//

#include "Pelicula.h"
#include <cstring>
#include <iostream>

using namespace std;

Pelicula::Pelicula() {}

Pelicula::Pelicula(char titulo[100], Persona director, int annio, char genero[100], char productora[100], int duracion) {
    strcpy(this->titulo, titulo);
    this->director = director;
    this->annio = annio;
    strcpy(this->genero, genero);
    strcpy(this->productora, productora);
    this->duracion = duracion;
}

void Pelicula::toString() {
    cout<<"Titulo: "<<this->titulo<<endl;
    cout<<"Annio: "<<this->annio<<endl;
    cout<<"Genero: "<<this->genero<<endl;
    cout<<"Productora: "<<this->productora<<endl;
    cout<<"Duracion: "<<this->duracion<<endl;
    cout<<"---Datos del director---"<<endl;
    this->director.toString();
}