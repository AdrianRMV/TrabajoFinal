//
// Created by Laloparkour on 23/05/2020.
//

#ifndef TAREA_7_PELICULA_H
#define TAREA_7_PELICULA_H

#include "Persona.h"

class Pelicula {
private:
    char titulo[100];
    Persona director;
    int annio;
    char genero[100];
    char productora[100];
    int duracion;
public:
    Pelicula();
    Pelicula(char [], Persona, int, char [], char [], int);
    void toString();
};


#endif //TAREA_7_PELICULA_H
