#include <iostream>

using namespace std;

struct gym_usuario{
	
	int edad;
	string nombre;

	
	struct gym_hijo{
		
		int cantidad;
		long long id;
			
	};

		gym_hijo hijo_usuario;
};

int main(){
	
	
	//Variables globales
	int i;
	int cantidad_usuarios;
	
	//Bienvenida y presentacion
	cout <<"\n****************************\n";
	cout <<"\n************GYM*************\n";
	cout <<"\n****************************\n";
	
	//Se solicita el numero de usuarios a registrar
	cout << "Cuantos usuarios va a registrar?: ";
	cin >> cantidad_usuarios;

	//Se crea un arreglo del TDA gym_usuario de tamaño cantidad_usuarios
	gym_usuario registro_persona[cantidad_usuarios];
	
	//Se crea un ciclo para capturar los datos
	for(i = 0; i < cantidad_usuarios; i++){
		
		cout << "Nombre: ";
		cin >> registro_persona[i].nombre;
		cout << "Edad: ";
		cin >> registro_persona[i].edad;
		
		cout << "Cantidad hijos: ";
		cin >> registro_persona[i].hijo_usuario.cantidad;
		
		//Condición para inscribir al hijo
		if (registro_persona[i].hijo_usuario.cantidad > 0){
			cout << "------------ ID del hijo: ";
			cin >> registro_persona[i].hijo_usuario.id;
		}
		
	}
	
	for (int j = 0; j < cantidad_usuarios; j++){
		cout <<j + 1<<": "<<registro_persona[j].nombre<<"\n";
	}



	return 0;
}
