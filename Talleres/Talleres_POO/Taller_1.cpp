#include <iostream>
#include <math.h>

using namespace std;

class triangulo{
  private:
  float lado_a;
  float lado_b;
  float hipotenusa;
  public:
  void obtener_datos(){
    cout << "Lado a: ";
    cin >> lado_a;
    cout << "Lado b: ";
    cin >> lado_b;
  }
  void calcular_hipotenusa(){
    hipotenusa = sqrt((lado_a*lado_a)+(lado_b*lado_b));
    cout << "La hipotenusa es: "<<hipotenusa<<endl<<endl;
  }

};

class fecha{

  private:
  short dia;
  short mes;
  short ano;

  public:
  void pedir_datos(){
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Año: ";
    cin >> ano;
  }
  void mostrar_fecha(){
    cout << "La fecha de hoy es "<<dia<<"-"<<mes<<"-"<<ano<<endl<<endl;
  }
};

  class celcius_a_farenheit{
    private:
    float celcius;
    float farenheit;
    public:
    void obtener_datos(){
      cout << "Temperatura en celcius: ";
      cin >> celcius;
    }
    void conversion(){
      farenheit = (celcius*(9/5)) + 32;
      cout << "Temperatura en farenheit: "<<farenheit<<endl<<endl;
    }

  };

int main() {

  int op;
  do{

  cout << "Digite una opcion: "<<endl;
  cout << "1 -- Calcular hipotenusa"<<endl;
  cout << "2 -- Farenheit a celcius"<<endl;
  cout << "3 -- Fecha"<<endl;
  cout << "0 -- Salir"<<endl;
  cout << "---> ";
  cin >> op;

  switch(op){


    case 1:
      triangulo triangulo1;
      triangulo1.obtener_datos();
      triangulo1.calcular_hipotenusa();
    break;
    case 2:
      celcius_a_farenheit calculo1;
      calculo1.obtener_datos();
      calculo1.conversion();
    break;


    case 3:
      fecha calcular_fecha;
      calcular_fecha.pedir_datos();
      calcular_fecha.mostrar_fecha();
    break;

    
    case 0:
      cout << "Feliz Dia :)";
    break;

    default:
      cout << "Opcion erronea"<<endl;
    break;
  }
  }while(op != 0);
  
}
