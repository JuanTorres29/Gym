/*
Problema: Crearemos una jerarquía de clases para modelar animales en un zoológico. 
Los animales pueden ser mamíferos o reptiles, y cada uno puede realizar varias acciones como comer, moverse, y hacer sonidos. 
Además, queremos garantizar que todos los animales puedan ser identificados por un ID único.
*/

//Primero, crearemos una interfaz Identificable para asegurar que todos los animales puedan ser identificados:
public interface Identificable {
    String getId();
}


//Luego, crearemos una clase abstracta Animal que implementa la interfaz Identificable:
public abstract class Animal implements Identificable {
    private String id;

    public Animal(String id) {
        this.id = id;
    }

    public String getId() {
        return this.id;
    }

    public abstract void comer();
    public abstract void mover();
    public abstract void hacerSonido();
}


//Después, crearemos clases concretas Mamifero y Reptil que extienden Animal:
public class Mamifero extends Animal {
    public Mamifero(String id) {
        super(id);
    }

    public void comer() {
        System.out.println("El mamífero está comiendo.");
    }

    public void mover() {
        System.out.println("El mamífero está moviéndose.");
    }

    public void hacerSonido() {
        System.out.println("El mamífero hace un sonido.");
    }
}

public class Reptil extends Animal {
    public Reptil(String id) {
        super(id);
    }

    public void comer() {
        System.out.println("El reptil está comiendo.");
    }

    public void mover() {
        System.out.println("El reptil está moviéndose.");
    }

    public void hacerSonido() {
        System.out.println("El reptil hace un sonido.");
    }
}


//Finalmente, podemos crear instancias de Mamifero y Reptil, y ejecutar sus métodos:
public class Main {
    public static void main(String[] args) {
        Mamifero leon = new Mamifero("123");
        Reptil cocodrilo = new Reptil("456");

        System.out.println("ID del león: " + leon.getId());
        leon.comer();
        leon.mover();
        leon.hacerSonido();

        System.out.println("ID del cocodrilo: " + cocodrilo.getId());
        cocodrilo.comer();
        cocodrilo.mover();
        cocodrilo.hacerSonido();
    }
}


