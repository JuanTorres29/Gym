// Importando la utilidad de Java para listas y otras estructuras de datos
import java.util.*;

// Definición de una clase abstracta llamada ProductoElectronico
// Las clases abstractas no pueden ser instanciadas directamente, sino que sirven como "plantillas" para clases derivadas
abstract class ProductoElectronico {
    // Variables miembro privadas para almacenar información general de cada producto electrónico
    private String nombre;
    private double precio;
    private int garantia;

    // Constructor que recibe nombre, precio y garantia al crear una nueva instancia de la clase
    public ProductoElectronico(String nombre, double precio, int garantia){
        this.nombre = nombre;
        this.precio = precio;
        this.garantia = garantia;
    }

    // Métodos getters para recuperar el valor de las variables miembro
    public String getNombre() {
        return nombre;
    }

    public double getPrecio() {
        return precio;
    }

    public int getGarantia() {
        return garantia;
    }

    // Método abstracto que debe ser implementado por cada clase derivada
    // Representa la operación de carga de un dispositivo electrónico, pero el comportamiento específico dependerá del tipo de dispositivo
    public abstract void cargar(int cargaInicial);
}

// Clase Celular que hereda de ProductoElectronico, añade sus propias características y define el comportamiento del método de cargar
class Celular extends ProductoElectronico {
    private String sistemaOperativo;
    private int capacidadBateria;

    // Constructor que inicializa el celular con información específica, además de la general heredada de ProductoElectronico
    public Celular(String nombre, double precio, int garantia, String sistemaOperativo, int capacidadBateria){
        super(nombre, precio, garantia);  // Llamada al constructor de la clase padre
        this.sistemaOperativo = sistemaOperativo;
        this.capacidadBateria = capacidadBateria;
    }

    // Implementación del método cargar específico para celulares
    @Override
    public void cargar(int cargaInicial) {
        System.out.println("Cargando el celular " + getNombre() + ". Tiempo estimado: " + (capacidadBateria - cargaInicial) + " minutos.");
    }

    // Métodos específicos de la clase Celular
    public void llamar(String numero) {
        System.out.println("Llamando al número " + numero + " desde el celular " + getNombre() + ".");
    }

    public void instalarAplicacion(String nombreAplicacion) {
        System.out.println("Instalando la aplicación " + nombreAplicacion + " en el celular " + getNombre() + ".");
    }

    public void encenderLinterna() {
        System.out.println("Encendiendo linterna del celular " + getNombre() + ".");
    }
}

// Clase Computadora que hereda de ProductoElectronico, añade sus propias características y define el comportamiento del método de cargar
class Computadora extends ProductoElectronico {
    private String sistemaOperativo;
    private int capacidadDiscoDuro;

    // Constructor que inicializa la computadora con información específica, además de la general heredada de ProductoElectronico
    public Computadora(String nombre, double precio, int garantia, String sistemaOperativo, int capacidadDiscoDuro){
        super(nombre, precio, garantia);  // Llamada al constructor de la clase padre
        this.sistemaOperativo = sistemaOperativo;
        this.capacidadDiscoDuro = capacidadDiscoDuro;
    }

    // Implementación del método cargar específico para computadoras
    @Override
    public void cargar(int cargaInicial) {
        System.out.println("Cargando la computadora " + getNombre() + ". Tiempo estimado: " + (capacidadDiscoDuro - cargaInicial) + " minutos.");
    }

    // Métodos específicos de la clase Computadora
    public void instalarPrograma(String nombrePrograma) {
        System.out.println("Instalando el programa " + nombrePrograma + " en la computadora " + getNombre() + ".");
    }

    public void abrirNavegador(String url) {
        System.out.println("Abriendo el navegador en la URL " + url + " en la computadora " + getNombre() + ".");
    }

    public void realizarBackup() {
        System.out.println("Realizando backup del disco duro en la computadora " + getNombre() + ".");
    }
}


class Main {
    public static void main(String[] args) {
        ArrayList<ProductoElectronico> listaProductos = new ArrayList<>();

        // Crear dos celulares
        Celular celular1 = new Celular("Galaxy S10", 500.00, 1, "Android", 4000);
        Celular celular2 = new Celular("iPhone 11", 800.00, 1, "iOS", 3900);

        // Crear dos computadoras
        Computadora computadora1 = new Computadora("HP Pavilion", 1200.00, 2, "Windows 10", 500000);
        Computadora computadora2 = new Computadora("MacBook Pro", 2000.00, 2, "MacOS", 500000);

        // Añadir los productos a la lista
        listaProductos.add(celular1);
        listaProductos.add(celular2);
        listaProductos.add(computadora1);
        listaProductos.add(computadora2);

        // Recorrer la lista y mostrar la información de cada producto
        for (ProductoElectronico producto : listaProductos) {
            System.out.println("\nNombre del producto: " + producto.getNombre());
            System.out.println("Precio del producto: $" + producto.getPrecio());
            System.out.println("Garantía del producto: " + producto.getGarantia() + " años");
            producto.cargar(1000); // Ejemplo de carga inicial de 1000

            // Si el producto es un celular, se ejecutan los métodos específicos de los celulares
            if (producto instanceof Celular) {
                Celular celular = (Celular) producto;
                celular.llamar("1234567890");
                celular.instalarAplicacion("Instagram");
                celular.encenderLinterna();
            }

            // Si el producto es una computadora, se ejecutan los métodos específicos de las computadoras
            else if (producto instanceof Computadora) {
                Computadora computadora = (Computadora) producto;
                computadora.instalarPrograma("Microsoft Office");
                computadora.abrirNavegador("www.google.com");
                computadora.realizarBackup();
            }
        }
    }
}
