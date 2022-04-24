#pragma once
#include <iostream>
#include <string>
#include "To_do.h"
#include "Done.h"

using namespace std;


class Menu {
	To_do lista1;
	Done lista2;

public:

	void ImprimirMenu() {
		int opcion = 0;
		int reinicio = 0;
		string String_act = "";

		do {
			system("cls");
			cout << "Bienvenido a tu agenda de Actividades (To Do List) Personal" << endl;
			cout << "Opciones de Configuración Disponibles:" << endl;
			cout << "1. Ver Actividaes Registradas" << endl;
			cout << "2. Registrar nuevo pendiente" << endl;
			cout << "3. Modificar una Actividad" << endl;
			cout << "4. Marcar una actividad como completada" << endl;
			cout << "5. Ver Actividades Completadas" << endl;
			cout << "6. Salir" << endl;
			cout << "Ingrese la opcion deseada: ";
			cin >> opcion;
			cin.ignore(INT_MAX, '\n');

			switch (opcion) {
			case 1:
				lista1.LeerActividades();
				break;

			case 2:
				cout << "Ingrese la nueva actividad a registrar: ";
				getline(cin, String_act);
				lista1.AgregarElemento(String_act);
				break;

			case 3: {
				if (lista1.NumActividades() == 0) {
					cout << "\n\tAun no se tiene registrada ninguna actividad" << endl;
					system("pause");
					system("cls");
				}
				else {
					int opcion_cambio;
					lista1.LeerActividades();

					cout << "\nIngrese el numero de actividad a modificar: ";
					cin >> opcion_cambio;
					opcion_cambio -= 1;
					cin.ignore(INT_MAX, '\n');

					cout << "Ingrese la actividad actualizada: ";
					getline(cin, String_act);
					lista1.ModificarActividades(opcion_cambio, String_act);
				}
			}
				  break;

			case 4: {
				if (lista1.NumActividades() == 0) {
					cout << "\n\tAun no se tiene registrada ninguna actividad" << endl;
					system("pause");
					system("cls");
				}
				else {
					int opcion_actualizar;
					lista1.LeerActividades();


					cout << "\nIngrese el numero de la actividad completada: ";
					cin >> opcion_actualizar;
					opcion_actualizar -= 1;
					cin.ignore(INT_MAX, '\n');
					lista2.AgregarTarea_Terminada(lista1.ObtenerDato(opcion_actualizar));
					lista1.CompletarActividad(opcion_actualizar);
					//lista2.AgregarTarea_Terminada("Algo que no se puede");
					//AgregarTarea_Terminada("");
				}
			}
				  break;

			case 5:
				lista2.LeerActividades();
				break;

			case 6:
				reinicio = 1;
				break;

			default:
				cout << "\nIngrese una opcion valida" << endl;
				system("pause");
				system("cls");
				break;

			}
		} while (reinicio == 0);

		cout << "\nCerrando Sesion..." << endl;
		system("pause");
	}
};
