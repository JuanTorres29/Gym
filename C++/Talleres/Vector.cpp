/*	Autor: Juan Torres
        Fecha: 8-2-2023
        Tema: Clase vector (biblioteca de funciones y métodos de la clase
   vector)
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {

  // Se declaran los vectores a usar
  vector<int> vector01;

  // Se asigna un tamaño y se inicializa en un valor
  vector01.assign(10, 304); // vector con 10 elementos cuyo valor es 304

  // Se imprime primera versión del vector
  for (int i = 0; i < vector01.size(); i++) {
    cout << vector01[i] << " ";
  }

  cout << "\n";

  // Añade el elemento 2 al final del vector
  vector01.push_back(2);

  // Se imprime la segunda versión del vector
  for (int i = 0; i < vector01.size(); i++) {
    cout << vector01[i] << " ";
  }

  cout << "\n";

  // Quita el último elemento del vector
  vector01.pop_back();

  // Se imprime la tercera versión del vector
  for (int i = 0; i < vector01.size(); i++) {
    cout << vector01[i] << " ";
  }

  cout << "\n";

  // insertamos un valor en el primer elemento
  // Si necesitamos insertarlo en otro elemento, le sumamos al primer parametro.
  // vector01.begin() + 1 --> Se inserta en el segundo elemento del vector.
  vector01.insert(vector01.begin(), 1000);

  // Se imprime la cuarta versión del vector
  for (int i = 0; i < vector01.size(); i++) {
    cout << vector01[i] << " ";
  }

  cout << "\n";

  // Vaciamos el vector
  vector01.clear();

  // Se imprime la quinta versión del vector
  for (int i = 0; i < vector01.size(); i++) {
    cout << vector01[i] << " ";
  }

  cout << "\n";

  // Se declara otro vector
  vector<int> vector02{1, 2, 3, 4, 5};

  // Imprimimos el vector con el ciclo for que recorre las direcciones de
  // memoria
  // El vector tiene que estar lleno para que funcione
  for (const int &i : vector02) {
    cout << i << " ";
  }

  cout << "\n\n**********************************\n\n";

  //***DIFERENCIA ENTRE VECTOR Y ARRAY***

  // declaramos 2 nuevos vectores
  vector<int> vector03(6, 201);
  vector<int> vector04(4, 400);

  // Se crea un iterador de tipo vector
  vector<int>::iterator it;

  int myarray[] = {501, 502, 503, 304, 404};

  for (it = vector03.begin(); it < vector03.end(); it++) {
    cout << *it << " ";
  }
  cout << "\n";

  // El iterador deja de funcionar ya que toma un valor null, asi que toca
  // volverlo a declararc
  it = vector03.begin();
  it = vector03.insert(it, 200);

  vector03.insert(it, 2, 300);

  for (it = vector03.begin(); it < vector03.end(); it++) {
    cout << *it << " ";
  }
  cout << "\n";

  //"it" No valido, asignar de nuevo:
  it = vector03.begin();
  it = vector03.insert(it + 2, vector04.begin(), vector04.end());

  // Se inserta hasta el tercer elemento del array (la posicion 0, 1 y 2)
  it = vector03.insert(vector03.begin(), myarray, myarray + 3);

  cout << "My vector contains:\n";

  for (it = vector03.begin(); it < vector03.end(); it++) {
    cout << *it << " ";
  }
  cout << "\n";

  return 0;
}
