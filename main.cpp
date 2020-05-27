#include <iostream>
#include "Persona.h"
#include "Pelicula.h"
#include "Prestamo.h"

using namespace std;

void menu(){
    cout<<"\n\t\tMENU"<<endl;
    cout<<"1.- Administrar Usuarios"<<endl;
    cout<<"2.- Administrar Peliculas"<<endl;
    cout<<"3.- Administrar Prestamos"<<endl;
    cout<<"4.- Salir"<<endl;
}

void menuUsuarios(){
    cout<<"\n\t\tMENU"<<endl;
    cout<<"1.- Registrar Usuario"<<endl;
    cout<<"2.- Editar Usuario"<<endl;
    cout<<"3.- Consultar Usuario"<<endl;
    cout<<"4.- Eliminar Usuario"<<endl;
    cout<<"5.- Regresar"<<endl;
}

void menuPeliculas(){
    cout<<"\n\t\tMENU"<<endl;
    cout<<"1.- Registrar Pelicula"<<endl;
    cout<<"2.- Editar Pelicula"<<endl;
    cout<<"3.- Consultar Pelicula"<<endl;
    cout<<"4.- Eliminar Pelicula"<<endl;
    cout<<"5.- Regresar"<<endl;
}

void menuPrestamos(){
    cout<<"\n\t\tMENU"<<endl;
    cout<<"1.- Realizar Prestamo"<<endl;
    cout<<"2.- Devolver Pelicula"<<endl;
    cout<<"3.- Consultar Prestgamo"<<endl;
    cout<<"4.- Regresar"<<endl;
}

Persona registrarUsuario(){
    char nombre[100];
    char apellido[100];
    int edad;

    cout<<"Nombre: "; cin>>nombre;
    cout<<"Apellido: "; cin>>apellido;
    cout<<"Edad: "; cin>>edad;

    Persona usuario = Persona(nombre, apellido, edad);
    return usuario;
}

Pelicula registrarPelicula(){
    /*VARIABLES PELICULAS*/
    char titulo[100];
    int annio;
    char genero[100];
    char productora[100];
    int duracion;

    /*VARIABLES DIRECTOR*/
    char nombre[100];
    char apellido[100];
    int edad;

    cout<<"\n\t\t---Datos de la pelicula---"<<endl;
    cout<<"Titulo: "; cin>>titulo;
    cout<<"Annio: "; cin>>annio;
    cout<<"Genero: "; cin>>genero;
    cout<<"Productora: "; cin>>productora;
    cout<<"Duracion: "; cin>>duracion;
    cout<<"\n\t\t---Datos del autor---"<<endl;
    cout<<"Nombre: "; cin>>nombre;
    cout<<"Apellido: "; cin>>apellido;
    cout<<"Edad: "; cin>>edad;

    Persona director = Persona(nombre, apellido, edad);
    Pelicula pelicula = Pelicula(titulo, director, annio, genero, productora, duracion);
    return pelicula;

}

Prestamo registrarPrestamo(int pelicula){
    int usuario;
    char fechaInicial[100];

    cout<<"Ingrese el numero de usuario: "; cin>>usuario;
    cout<<"Ingrese la fecha inicial: "; cin>>fechaInicial;

    Prestamo nuevoPrestamo = Prestamo(usuario, pelicula, fechaInicial);
    return nuevoPrestamo;
}

void mostrarPeliculas(Pelicula peliculas[10], int contPeliculas){
    for (int i = 0; i < contPeliculas; ++i) {
        cout << "< === Pelicula # "<< (i) << endl;
        peliculas[i].toString();
    }
}

int main() {
    int opc, no, contUsuarios = 0, contPeliculas = 0, contPrestamos = 0;
    bool system = true;
    bool usuario = true;
    bool pelicula = true;
    bool prestamo = true;
    bool temp = true;
    char fechaFinal[100];

    Persona usuarios[10];
    Pelicula peliculas[10];
    Prestamo prestamos[10];

    while (system == true) {
        menu();
        cin>>opc;

        usuario = true;
        pelicula = true;
        prestamo = true;

        switch (opc) {
            case 1:
                while (usuario) {
                    menuUsuarios();
                    cin>>opc;
                    switch (opc) {
                        case 1:
                            cout<<"---Registrar Usuario---"<<endl;
                            usuarios[contUsuarios] = registrarUsuario();
                            cout<<"-\n--Registro exitoso---"<<endl;
                            contUsuarios++;
                            break;
                        case 2:
                            cout<<"---Editar Usuario---"<<endl;
                            cout<<"Ingresa el numero del usuario: "; cin>>no;
                            cout<<"\n---Informacion del usuario---"<<endl;
                            usuarios[no].toString();
                            usuarios[no] = registrarUsuario();
                            cout<<"\n---Cambio realizado con exito---"<<endl;
                            break;
                        case 3:
                            cout<<"---Consultar Usuario---"<<endl;
                            cout<<"Ingresa el numero del usuario: "; cin>>no;
                            cout<<"\n---Informacion del usuario---"<<endl;
                            usuarios[no].toString();
                            break;
                        case 4:
                            cout<<"---Eliminar Usuario---"<<endl;
                            cout<<"Ingresa el numero del usuario: "; cin>>no;
                            cout<<"\n---Informacion del usuario---"<<endl;
                            usuarios[no].toString();
                            if(no == prestamos[no].getUsuario() && prestamos[no].getEstado() == 1){
                                cout<<"---No se puede eliminar un usuario con rentas---"<<endl;
                            }
                            else{
                                usuarios[no] = Persona();
                                cout<<"\n---Usuario eliminado---"<<endl;
                            }
                            break;
                        default:
                            usuario = false;
                            break;
                    }
                }
                break;
            case 2:
                while (pelicula) {
                    menuPeliculas();
                    cin>>opc;
                    switch (opc) {
                        case 1:
                            cout<<"---Registrar Pelicula---"<<endl;
                            peliculas[contPeliculas] = registrarPelicula();
                            cout<<"\nRegistro exitoso."<<endl;
                            contPeliculas++;
                            break;
                        case 2:
                            cout<<"---Editar Pelicula---"<<endl;
                            cout<<"Ingresa el numero de la pelicula: "; cin>>no;
                            cout<<"\n---Informacion de la pelicula---"<<endl;
                            peliculas[no].toString();
                            peliculas[no] = registrarPelicula();
                            cout<<"Cambio realizado con exito."<<endl;
                            break;
                        case 3:
                            cout<<"---Consultar Pelicula---"<<endl;
                            cout<<"Ingresa el numero de la pelicula: "; cin>>no;
                            cout<<"\n---Informacion de la pelicula---"<<endl;
                            peliculas[no].toString();
                            break;
                        case 4:
                            cout<<"---Eliminar Pelicula---"<<endl;
                            cout<<"Ingresa el numero de la pelicula: "; cin>>no;
                            peliculas[no].toString();

                            if(no == prestamos[no].getPelicula() && prestamos[no].getEstado() == 1){
                                cout<<"---No se puede eliminar una pelicula en renta---"<<endl;
                            }
                            else{
                                peliculas[no] = Pelicula();
                                cout<<"---Pelicula eliminada---"<<endl;
                            }
                            break;
                        default:
                            pelicula = false;
                            break;
                    }
                }
                break;
            case 3:
                while (prestamo) {
                    menuPrestamos();
                    cin>>opc;
                    switch (opc) {
                        case 1:
                            cout<<"---Realizar Prestamo---"<<endl;
                            mostrarPeliculas(peliculas, contPeliculas);
                            cout<<"Ingresa el numero de la pelicula: "; cin>>no;
                            temp = true;
                            for (int i = 0; i < contPrestamos; i++) {
                                if(no == prestamos[i].getPelicula() && prestamos[i].getEstado() == 1){
                                    temp = false;
                                }
                            }
                            if(temp){
                                prestamos[contPrestamos] = registrarPrestamo(no);
                                contPrestamos++;
                            }
                            else{
                                cout<<"La pelicula ya esta rentada."<<endl;
                            }
                            break;
                        case 2:
                            cout<<"---Devolver Pelicula---"<<endl;
                            cout<<"Ingresa el numero de prestamo: "; cin>>no;
                            usuarios[prestamos[no].getUsuario()].toString();
                            peliculas[prestamos[no].getPelicula()].toString();
                            prestamos[no].toString();
                            if(prestamos[no].getEstado() == 1){
                                cout<<"Ingresa la fecha de devolucion: "; cin>>fechaFinal;
                                prestamos[no].devolucion(fechaFinal);
                                cout<<"\n---Pelicula devuelta---";
                            }
                            else{
                                cout<<"El prestamo ha sido devuelto anteriormente"<<endl;
                            }
                            break;
                        case 3:
                            cout<<"---Consultar Prestamo---"<<endl;
                            cout << "ingresa el numero de prestamo: "<<endl; cin >> no;
                            usuarios[prestamos[no].getUsuario()].toString();
                            peliculas[prestamos[no].getPelicula()].toString();
                            prestamos[no].toString();
                            break;
                        default:
                            prestamo = false;
                            break;
                    }
                }
                break;
            default:
                system = false;
                break;
        }
    }

    return 0;
}
