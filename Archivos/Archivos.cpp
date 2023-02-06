/*
Objetivos:
- Resumen sobre TDA.
- R/W on files.
- Listas.


Estructuras en C++:.
- Tipos de datos definidos por el usuario.
- Permite agrupar diferentes tipos de datos y ser usados de forma encapsulada, como obbjetos.

Desventajas:
- No pueden ser tratados como tipo de datos "nativos" o "propios" de CH.
- Operadores como +/- no pueden ser empleados en variables de la estructura.
- No admite la ocultación de los miembros
- No se puede declarar miembros estáticos dentro de la estructura



*********************************************************************************
OBJETIVOS DE LA ACTIVIDAD:

	- Crear una estructura corta para pedir datos básicos del ususario.
	- Crear una lista de plabaras a ser usadas aleatoriamente
	- Almacenar palabras en un fichero.
	- Leer y presentar en pantalla la lectura de un fichero
	
*********************************************************************************

*/

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

//Se crea una estructura básica para la captura de datos de los usuarios
struct datos_usuarios{
	string nombre;
	string apellido;
	int edad;
};

//Se crea una lista, como conjunto de palabras para jugar
const string lista_palabras[] = {"hola", "mañana", "hoy", "tarde", "noche"};

//Se crea la función principal
int main(){
	
	//Se declaran variables a usar
	int i, j, cantidad;
	
	//Se pide cuantos usuarios
	cout << "Numero de ususarios: ";
	cin >> cantidad;
	
	//Se crea objeto struct del tamaño cantidad
	datos_usuarios personas[cantidad];
	
	//Se piden los datos
	//Se escribe sobre un fichero: se usa "ofstream" para almacenar en el fichero
	//Se crea el objeto tipo ofstream (digital junto con el nombre del fichero (fisico)
	ofstream fichero_escritura("usuarios01.txt");
	
	//Se debe preguntar si hay espacio en memoria para abrir el fichero
	if(fichero_escritura.is_open()){
	
		for (i = 0; i < cantidad; i++){
			
			cout << "Usuario "<< i + 1<<endl;
		
			cout <<"Nombre: ";
			cin >> personas[i].nombre;
			fichero_escritura << personas[i].nombre;
			
			cout <<"Apellido: ";
			cin >> personas[i].apellido;
			fichero_escritura << personas[i].apellido;
			
			cout <<"Edad: ";
			cin >> personas[i].edad;
			fichero_escritura << personas[i].edad;
			
		}
		
	}
	
	

return 0;	
}
