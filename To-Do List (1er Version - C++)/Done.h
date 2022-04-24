#pragma once
#include <iostream>
#include<vector>
#include <string>

using namespace std;

class Done {
	vector<string> Done_list;

public:

	void AgregarTarea_Terminada(string actividad_terminada) {
		Done_list.insert(Done_list.end(), actividad_terminada);
		cout << "\nEstado de actividad Actualizado" << endl;
		system("pause");
		system("cls");
	}

	void LeerActividades() {
		char c = 167;

		cout << "\nActividades Completadas: ";
		if (Done_list.size() == 0) {
			cout << "\n\tAun no marca ninguna actividad como completada" << endl;
			system("pause");
			system("cls");
		}
		else {
			cout << "\n\n";
			for (int i = 0; i < Done_list.size(); i++) {
				cout << i + 1 << c << " Tarea Finalizada: " << Done_list.at(i) << endl;
			}
			system("pause");
		}
	}
};



