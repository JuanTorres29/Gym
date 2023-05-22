import java.util.*;

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