#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include<time.h>
#include <vector>


using namespace std;

struct resultados{//Se crea TDA con los datos del array con el que se hará el histograma

  int max_valor;
  int size_array;
  int *int_array;

};

resultados generar_vector_aleatorio(int array1[]);
void generarHistograma(resultados arg_generar);
int menu();

int main() {

  resultados valores_principal;
  int op;
  int *array = new int[100];//Se crea arreglo dinámico de max 100 para guardar los números aleatorios. Este no puede ser iniciado dentro de las funciones ya que sería un arreglo local y todo se borraría al salir de la función, por lo tanto, se pasará como parametro a la primera función (que genera los números aleatorios).

  do{
    op = menu();//op guarda lo que retorne el menú
    switch(op){
      case 1:{
        valores_principal = generar_vector_aleatorio(array);//valores_principal almacena a valores_generados
        cout << "Valor máximo: "<<valores_principal.max_valor<<endl;
      break;}
      case 2:{
       generarHistograma(valores_principal);
      break;}
      case 3:{
      break;}
      default:{
       cout << "**Ingrese una opción valida**"<<endl;}
      }
    }while(op != 3);
    
  delete[] array;//Se libera el espacio
  return 0;
}

resultados generar_vector_aleatorio(int array1[]){
  
  srand(time(NULL));

  resultados valores_generados;

  cout << "Ingrese la cantidad de datos(100 max): ";
  cin >> valores_generados.size_array;
  
  //int array1[valores_generados.size_array];

  int num;
  
  for(int i = 0; i < valores_generados.size_array; i++){//Se llena el array con números aleatorios del 0 al 20.
    num = rand()%21;
    array1[i] = num;
    }

  for(int i = 0; i < valores_generados.size_array; i++){//Se muestra el arreglo creado.
    cout << array1[i] << " ";
    }
  int max = 0;
  for(int i = 0; i < valores_generados.size_array; i++){//Se obtiene el valor máximo
    if(max < array1[i]){
      max = array1[i];
    }
  }
  cout << "\n";
  
  valores_generados.max_valor = max;
  valores_generados.int_array = array1;
  //Los datos se guardan en valores_generados

  return valores_generados; 
}

void generarHistograma(resultados arg_generar){

  cout<<endl;
  
  int *histograma = new int[100];//Se crea arreglo dinámico de máximo 100 para guardar el número de veces que se repite cada numero.
  vector <int> numeros;//Se crea un vector para guardar los números que ya 

  
  for(int i = 0; i < arg_generar.size_array; i++){//Se crea función para guardar en histograma el número de veces que se repite cada número. Si ese número ya ha sido contado, continúa con la siguiente iteración del ciclo sin hacer ningún cambio.
    bool repetido = false;
    for(int j = 0; j < numeros.size();j++){
      if(*(arg_generar.int_array + i) == numeros[j]){
        repetido = true;
      }
    }
    if(repetido == false){
      numeros.push_back(*(arg_generar.int_array + i));
     for(int k = 0; k < arg_generar.size_array; k++){
        if(*(arg_generar.int_array + i)== *(arg_generar.int_array + k)){
          histograma[i]++;
          }
        }
      }
  }
  int indice = 1;
  cout <<"Indice:\t""Numero:\tHistograma:"<<endl;
  
  for(int i = 0; i < arg_generar.size_array; i++){//Muestra el número de veces que aparece cada número en el arreglo por medio de un histograma.
    if(histograma[i]>0){
    cout <<indice<<"\t\t"<<*(arg_generar.int_array + i)<<"\t\t";
    for(int j = 0; j < histograma[i]; j++){
    cout << "*";
      }
      cout<<endl;
      indice++;
  }
    
  }

  cout<<endl;
  delete[] histograma;//Se libera la memoria
  }



int menu(){//Menú para consultarle al usuario qué desea hacer.
  int x;
  cout << "Que desea hacer?\n1 -- Generar vector aleatorio\n2 -- Generar histograma\n3 -- Salir\n---> ";
  cin >> x;

  return x;
}
