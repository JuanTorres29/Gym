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
