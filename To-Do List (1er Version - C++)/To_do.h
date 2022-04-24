#pragma once
#include <iostream>
#include<vector>
#include <string>
#include "Done.h"

using namespace std;

class To_do {
	vector<string> To_dolist;

public:

	void AgregarElemento(string nuevaactividad) {
		To_dolist.push_back(nuevaactividad);
		cout << "\nActividad Agregada Exitosamente" << endl;
		system("pause");
		system("cls");
	}

	void LeerActividades() {
		char c = 167;

		cout << "\nPendientes Registrados: ";
		if (To_dolist.size() == 0) {
			cout << "\n\tAun no se tiene registrada ninguna actividad" << endl;
			system("pause");
			system("cls");
		}
		else {
			cout << "\n\n";
			for (int i = 0; i < To_dolist.size(); i++) {
				cout << i + 1 << c << " Pendiente: " << To_dolist.at(i) << endl;
			}
			system("pause");
		}
	}

	void ModificarActividades(int index, string cambio_actividad) {
		To_dolist.at(index) = cambio_actividad;
		cout << "\nActividad Actualizada Exitosamente" << endl;
		system("pause");
		system("cls");
	}

	void CompletarActividad(int index) {
		Done DoneList;
		string actividad_completada;

		actividad_completada = To_dolist.at(index);
		To_dolist.erase(To_dolist.begin() + index);
	}

	string ObtenerDato(int index) {
		string actividad_completada;
		actividad_completada = To_dolist.at(index);
		return actividad_completada;
	}

	int NumActividades() {
		int num_act = 0;
		num_act = To_dolist.size();
		return num_act;
	}
};


