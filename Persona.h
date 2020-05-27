//
// Created by Laloparkour on 23/05/2020.
//

#ifndef TAREA_7_PERSONA_H
#define TAREA_7_PERSONA_H


class Persona {
private:
    char nombre[100];
    char apellido[100];
    int edad;
public:
    Persona();
    Persona(char [], char [], int);
    void toString();
};


#endif //TAREA_7_PERSONA_H
