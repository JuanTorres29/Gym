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
