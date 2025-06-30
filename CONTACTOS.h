#ifndef CONTACTOS_H
#define CONTACTOS_H

#include <string>
using namespace std;

struct contactoEmail {
    string nombres;
    char sexo;
    int edad;
    string telefono;
    string email;
    string nacionalidad;
};

extern const int ContactosLimite;
extern contactoEmail contactos[];
extern int TotalContactos;

void AgregarContacto();
void eliminarContacto();
void mostrarContactos();
void mostrarContactosPorServidor();
string obtenerServidorCorreo(string email);

#endif

