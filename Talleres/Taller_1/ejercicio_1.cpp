Taller 1 - Ejercicio 1

#include <iostream>

//Se utilizarán las librerias stdlib.h y time.h para generar números aleatorios.
#include <stdlib.h>
#include<time.h>

using namespace std;


int numero_aleatorio();//Función para generar un número aleatorio.

int main(){

  srand(time(NULL));//Se inicializa la semilla.
  
  int array1[10], *ptr;//Se declara el array y el pointer. 

  ptr = array1;//ptr apuntará a la mísma dirección de memoria que array1.

  //Se utiliza un ciclo "for" para llenar el arreglo por medio de la función numero_aleatorio().
  for(int i = 0; i < 10; i++){
    array1[i] = numero_aleatorio();
  }

  cout << "  Dirección\t   Valor\n\n";

  //Se imprime la dirección y el valor en cada dirección por medio de un ciclo "for".
  for(int i = 0; i < 10; i++){

    //se le suman i*4 bytes a ptr por cada ciclo, hasta llegar al final del arreglo.
    cout << (ptr + i) << " - " << *(ptr + i);
    cout << endl;
  }

  return 0;
}

int numero_aleatorio(){

  int num;

  num = rand()%26;//asigna a "num" valores aleatorios entre 0 y 25.
  
  return num;//retorna el numero aleatorio.
}
