//
// Created by Laloparkour on 24/05/2020.
//

#ifndef TAREA_7_PRESTAMO_H
#define TAREA_7_PRESTAMO_H


class Prestamo {
private:
    int usuario;
    int pelicula;
    char fechaInicial[100];
    char fechaFinal[100];
    int estado;
public:
    Prestamo();
    Prestamo(int, int, char []);
    void devolucion(char []);
    int getUsuario();
    int getPelicula();
    int getEstado();
    void toString();
};


#endif //TAREA_7_PRESTAMO_H
