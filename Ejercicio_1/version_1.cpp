/* 


Problema: se requiere hacer una aplicación que capture los datos de ususarios según tipo de cliente. El resultado será el valor a pagar según la cantidad de canales premium a oagar y conexiones de servicios básicos.
  1.- Inicialmente el usuario deberá digitar el número de cuenta.
  2.- Existen 2 tipos de clientes: r/R (Residencial) y n/N (Negocio).
  3.- El valor si es residencial es igual a 20.7 más 8.8 veces la cantidad_canales_premium.
  4.- El valor si es negocios, vendrá definido por:
      - Si la cantidad de conexiones_servicios_basicos es       mayor a 10: 
        *El valor es igual a el restante de los 10               (conexiones_servicios_basicos) más 78.9 más 18.7           veces cantidad_canales_premium.
  5.- Al final se pregunta al usuario si quiere ingresar otro cliente.
*/


#include <iostream>
#include <vector>

using namespace std;

struct usuario{
  char tipo_cliente;
  int numero_cuenta;
  int cantidad_canales_premium;
  int conexiones_servicios_basicos;
};

int main() {

  vector<usuario> usuarios;
  int continuar;
  int contador = 0;
  do{
    usuarios.resize(contador + 1);
    
    cout << "Ingrese el numero de cuenta: ";
    cin >> usuarios[contador].tipo_cliente;

    cout << "Tipo de cuenta (n/N o r/R): ";
    cin >> usuarios[contador].tipo_cliente;

    cout << "Canales premium: ";
    cin >> usuarios[contador].cantidad_canales_premium;

    cout << "Canales basicos: ";
    cin >> usuarios[contador].conexiones_servicios_basicos;

    if(usuarios[contador].tipo_cliente == 'r' || usuarios[contador].tipo_cliente == 'R'){
      cout << "Cantidad a pagar: " << (usuarios[contador].cantidad_canales_premium * 8.8) + 20.7;
    }
    
    if(usuarios[contador].tipo_cliente == 'n' || usuarios[contador].tipo_cliente == 'N'){
      if(usuarios[contador].conexiones_servicios_basicos >  10){
        cout << "Cantidad a pagar: " << 79.9 + (usuarios[contador].conexiones_servicios_basicos - 10) + (usuarios[contador].cantidad_canales_premium * 18.7);
      }
      else{
        cout << "Cantidad a pagar: " << 79.9 + (usuarios[contador].cantidad_canales_premium * 18.7);
      }
    }

    cout << "\n";
    
    cout << "Desea continuar? \n 1 --- SI\n 0 --- NO\n--> ";
    cin >> continuar;

    
    contador++;
  }while(continuar == 1);

  

  
  return 0;
}
