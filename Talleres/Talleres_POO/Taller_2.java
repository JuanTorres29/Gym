/*

Juan Andres Torres
31 de marzo del 2023

Instrucciones:

1. Círculo:

Área, Perímetro, Diámetro

2. Triángulo Rectángulo:

Perímetro, Hipotenusa, Altura

3. Crear 3 clases (Persona, Profesor, estudiante), que se pueden presentar. El estudiante que curse 9no o superior, puede inscribirse en el curso de programación. En el programa principal, se presentan los 3 objetos, y si el estudiante puede o no hacer el curso de programación.

Los datos miembros necesarios de la clase, son definidos por el programador

La cantidad de métodos de cada clase, son definidos por el programador

<Más es mejor, calidad ante todo>.*/

// Clase Círculo

import java.util.Scanner;

class Circulo {
    private double radio;

    public Circulo(double radio) {
        this.radio = radio;
    }

    public double calcularArea() {
        return Math.PI * Math.pow(radio, 2);
    }

    public double calcularPerimetro() {
        return 2 * Math.PI * radio;
    }

    public double calcularDiametro() {
        return 2 * radio;
    }
}

// Clase Triángulo Rectángulo
class TrianguloRectangulo {
    private double catetoA;
    private double catetoB;

    public TrianguloRectangulo(double catetoA, double catetoB) {
        this.catetoA = catetoA;
        this.catetoB = catetoB;
    }

    public double calcularPerimetro() {
        return catetoA + catetoB + calcularHipotenusa();
    }

    public double calcularHipotenusa() {
        return Math.sqrt(Math.pow(catetoA, 2) + Math.pow(catetoB, 2));
    }

    public double calcularAltura() {
        return (catetoA * catetoB) / calcularHipotenusa();
    }
}

// Clase Persona
class Persona {
    protected String nombre;

    public Persona(String nombre) {
        this.nombre = nombre;
    }

    public void presentarse() {
        System.out.println("Hola, mi nombre es " + nombre);
    }
}

// Clase Profesor, hereda de persona
class Profesor extends Persona {
    public String materia;
  
    public Profesor(String nombre, String materia) {
        super(nombre);
        this.materia = materia;
    }

    public void presentarse() {
        System.out.println("Hola, mi nombre es " + nombre + " y soy profesor de " + materia);
    }
}

// Clase Estudiante, hereda de persona
class Estudiante extends Persona {
    private int grado;

    public Estudiante(String nombre, int grado) {
        super(nombre);
        this.grado = grado;
    }

    public void presentarse() {
        System.out.println("Hola, mi nombre es " + nombre + " y soy estudiante en el grado " + grado);
    }

    public boolean puedeInscribirseEnProgramacion() {
        return grado >= 9;
    }
}

public class Main {
    public static void main(String[] args) {

        Scanner entrada  = new Scanner(System.in);
       System.out.println("--------Bienvenid@--------\n");
        byte op;
        do{ 

        System.out.println("         Menu \n");
        System.out.println("1. Circulo");
        System.out.println("2. Triangulo rectangulo");
        System.out.println("3. Persona, profesor y estudiante");
        System.out.println("0. Salir\n");
          
        System.out.print("Digite una opción: ");
        op = entrada.nextByte();
        

        
        switch(op){

          case 1:

            double radio;
            System.out.print("Radio del circulo: ");
            radio = entrada.nextDouble();
            Circulo circulo = new Circulo(radio);
            System.out.println("Perimetro: " + circulo.calcularPerimetro());
            System.out.println("Diametro: " + circulo.calcularDiametro());
            System.out.println("Area: " + circulo.calcularArea());
            circulo.calcularArea();
            break;
          case 2:

            double catetoA, catetoB;
            System.out.print("Cateto 1: ");
            catetoA = entrada.nextDouble();
            System.out.print("Cateto 2: ");
            catetoB = entrada.nextDouble();

            TrianguloRectangulo triangulorectangulo = new TrianguloRectangulo(catetoA, catetoB);

            System.out.println("Perimetro: " + triangulorectangulo.calcularPerimetro());
            System.out.println("Hipotenusa: " + triangulorectangulo.calcularHipotenusa());
            System.out.println("Altura: " + triangulorectangulo.calcularAltura());

            break;
          case 3:
          
            Persona persona = new Persona("Juan");
            Profesor profesor = new Profesor("Pedro", "Programacion");
            Estudiante estudiante = new Estudiante("Lucia", 8);
    
            persona.presentarse();
            profesor.presentarse();
            estudiante.presentarse();
    
            if (estudiante.puedeInscribirseEnProgramacion()) {
                System.out.println("El estudiante " + estudiante.nombre + " puede inscribirse en el curso de programación.");
            } else {
                System.out.println("El/La estudiante " + estudiante.nombre + " no puede inscribirse en el curso de programación.");
        }
            break;
          case 0:
            System.out.println("Adios :)");
            break;
          default:
            System.out.println("Opcion Incorrecta");
        }
        System.out.print("\n");
            
    }while(op != 0);
}
}
