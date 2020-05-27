//
// Created by Laloparkour on 23/05/2020.
//

#include "Persona.h"
#include <cstring>
#include <iostream>

using namespace std;

Persona::Persona() {}

Persona::Persona(char nombre[100], char apellido[100], int edad) {
    strcpy(this->nombre, nombre);
    strcpy(this->apellido, apellido);
    this->edad = edad;
}

void Persona::toString() {
    cout<<"Nombre: "<<this->nombre<<endl;
    cout<<"Apellido: "<<this->apellido<<endl;
    cout<<"Edad: "<<this->edad<<endl;
}