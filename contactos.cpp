#include <iostream>
#include "contactos.h"

const int ContactosLimite = 100;
contactoEmail contactos[ContactosLimite];
int TotalContactos = 0;

void AgregarContacto() {
    char RPTA;
    do {
        if (TotalContactos >= ContactosLimite) {
            cout << "Limite de contactos excedido." << endl;
            break;
        }

        cin.ignore();
        cout << "--------------------------------------" << endl;
        cout << "PROTOCOLO DE INCORPORACION DE CONTACTO" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Digite su nombre: ";
        getline(cin, contactos[TotalContactos].nombres);

        cout << "Sexo (M - F): ";
        cin >> contactos[TotalContactos].sexo;

        cout << "Edad: ";
        cin >> contactos[TotalContactos].edad;

        cin.ignore();

        cout << "Telefono: ";
        getline(cin, contactos[TotalContactos].telefono);

        cout << "Email: ";
        getline(cin, contactos[TotalContactos].email);

        cout << "Nacionalidad: ";
        getline(cin, contactos[TotalContactos].nacionalidad);

        TotalContactos++;
        cout << "Contacto guardado exitosamente." << endl;
        cout << "Desea guardar otro contacto? (S/N): ";
        cin >> RPTA;
        RPTA = toupper(RPTA);

    } while (RPTA == 'S');

    cout << "Regresando al MENU principal..." << endl;
}

void eliminarContacto() {
    char RESP;
    bool validador = false;
    do {
        if (TotalContactos == 0) {
            cout << "Aun no hay contactos registrados." << endl;
            return;
        }

        cin.ignore();
        string nombre;
        cout << "--------------------------------------" << endl;
        cout << "PROTOCOLO DE ELIMINACION DE CONTACTO" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Nombre del contacto a eliminar: ";
        getline(cin, nombre);

        for (int i = 0; i < TotalContactos; i++) {
            if (nombre == contactos[i].nombres) {
                for (int j = i; j < TotalContactos - 1; j++) {
                    contactos[j] = contactos[j + 1];
                }
                TotalContactos--;
                cout << "Contacto eliminado exitosamente." << endl;
                validador = true;
                return;
            }
        }

        if (!validador) {
            cout << "El contacto no fue encontrado." << endl;
            break;
        }
        cout << "Desea ELIMINAR otro contacto? (S/N): ";
        cin >> RESP;
        RESP = toupper(RESP);

    } while (RESP == 'S');

    cout << "Regresando al MENU principal..." << endl;
}

void mostrarContactos() {
    cout << "---------------------------------" << endl;
    cout << "PROTOCOLO DE MUESTRA DE CONTACTOS" << endl;
    cout << "---------------------------------" << endl;
    if (TotalContactos == 0) {
        cout << "Aun no hay contactos registrados." << endl;
        return;
    }

    for (int i = 0; i < TotalContactos; i++) {
        cout << "Nombre: " << contactos[i].nombres
             << " | Sexo: " << contactos[i].sexo
             << " | Edad: " << contactos[i].edad
             << " | Telefono: " << contactos[i].telefono
             << " | Email: " << contactos[i].email
             << " | Nacionalidad: " << contactos[i].nacionalidad << endl;
        cout << "------------------------------------------------------------------------------------------------------" << endl;
    }
}

string obtenerServidorCorreo(string email) {
    int pos = email.find('@');
    if (pos != -1) {
        return email.substr(pos + 1);
    }
    return "desconocido";
}

void mostrarContactosPorServidor() {
    cout << "----------------------------------------------" << endl;
    cout << "PROTOCOLO DE MUESTRA DE CONTACTOS POR SERVIDOR" << endl;
    cout << "----------------------------------------------" << endl;

    if (TotalContactos == 0) {
        cout << "No hay contactos registrados." << endl;
        return;
    }

    contactoEmail copia[ContactosLimite];
    for (int i = 0; i < TotalContactos; i++) {
        copia[i] = contactos[i];
    }

    for (int i = 0; i < TotalContactos - 1; i++) {
        for (int j = i + 1; j < TotalContactos; j++) {
            if (obtenerServidorCorreo(copia[i].email) > obtenerServidorCorreo(copia[j].email)) {
                contactoEmail temp = copia[i];
                copia[i] = copia[j];
                copia[j] = temp;
            }
        }
    }

    for (int i = 0; i < TotalContactos; i++) {
        cout << "Servidor: " << obtenerServidorCorreo(copia[i].email)
             << "\nNombre: " << copia[i].nombres
             << "\nEmail: " << copia[i].email
             << "\n--------------------------\n";
    }
}

