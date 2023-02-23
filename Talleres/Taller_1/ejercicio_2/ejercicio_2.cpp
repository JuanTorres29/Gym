//Taller 1 - ejercicio 2

#include <iostream>
#include <fstream>

using namespace std;

//Se crea una estructura básica para la captura de datos de los usuarios.
struct clientes{
  string nombre;
  int edad;
  char genero;
};

clientes solicitar_datos();//Se declara la función para solicitar datos.
void escribir_en_fichero(clientes *ptr, int cantidad_clientes);//Se declara la función para pasar datos al fichero.

int main(){
  
  int cantidad_clientes;//Variable para guardar cuántos usuarios serán ingresados.
  
  cout << "Cuantos clientes desea ingresar?: ";
  cin >> cantidad_clientes;

  clientes usuarios_main[cantidad_clientes], *ptr;//Se crea un arreglo de tipo clientes y de tamaño cantidad_clientes.
  ptr = usuarios_main;//ptr guardará la misma dirección de memoria que el arreglo usuarios_main.

  for(int i = 0; i < cantidad_clientes; i++){
    cout << "******USUARIO "<<i+1<<"******\n";
    usuarios_main[i] = solicitar_datos();//Se utiliza la funcion solicitar_datos para guardar los datos en el arreglo usuarios_main.
  }

  escribir_en_fichero(ptr, cantidad_clientes);//Se llama a la función escribir_en_fichero (con parametros ptr (direccion de memoria del array) y cantidad_clientes) para pasar los datos al fichero


  return 0;
}

clientes solicitar_datos(){

  //Declaramos una variable tipo clientes para llenar y retornar de la función, además de un apuntador del mísmo tipo.
  clientes usuario_funcion, *ptr;
  ptr = &usuario_funcion;//ptr almacenará la dirección de usuario_funcion.

  //A continuación, se piden los datos.
  cout << "Nombre: ";
  cin >> ptr->nombre;
  cout << "Edad: ";
  cin >> ptr->edad;
  cout << "Genero(M/F); ";
  cin >> ptr->genero;
  
  return usuario_funcion;//Se retorna la variable en la cual se guardaron los datos.
}
void escribir_en_fichero(clientes *ptr, int cantidad_clientes){
  
  //Se escribe sobre un fichero: se usa "ofstream" para almacenar en el fichero
	//Se crea el objeto tipo ofstream (digital junto con el nombre del fichero (fisico)
	ofstream fichero_escritura("usuarios01.txt");
	
	//Se debe preguntar si hay espacio en memoria para abrir el fichero
	if(fichero_escritura.is_open()){
    //Escribimos en el fichero recorriendo las direcciones de memoria en las que guardamos los datos de los clientes con un ciclo for.
    for(int i = 0; i < cantidad_clientes; i++){
      fichero_escritura << (ptr+i)->nombre <<",";
      fichero_escritura << (ptr+i)->edad <<",";
      fichero_escritura << (ptr+i)->genero <<",";
      fichero_escritura << "\n";
      }
    }
	fichero_escritura.close();
}
