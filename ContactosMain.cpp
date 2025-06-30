#include <iostream>
#include "contactos.h"
using namespace std;

int main() {
    char opcion;

    do {
        cout << endl;
        cout << "---------------------------------------" << endl;
        cout << "-MENU PRINCIPAL DE GESTOR DE CONTACTOS-" << endl;
        cout << "---------------------------------------" << endl;
        cout << endl;
        cout << "***Seleccione una opcion***" << endl;
        cout << "A. Agregar contacto." << endl;
        cout << "B. Eliminar contacto." << endl;
        cout << "C. Mostrar listado general." << endl;
        cout << "D. Mostrar contactos por servidor de correo." << endl;
        cout << "E. Salir del programa." << endl;
        cin >> opcion;
        opcion = toupper(opcion);

        switch (opcion) {
            case 'A': AgregarContacto(); break;
            case 'B': eliminarContacto(); break;
            case 'C': mostrarContactos(); break;
            case 'D': mostrarContactosPorServidor(); break;
            case 'E': cout << "Saliendo del programa..." << endl; break;
            default: cout << "Opcion no valida." << endl;
        }

    } while (opcion != 'E');

    return 0;
}
