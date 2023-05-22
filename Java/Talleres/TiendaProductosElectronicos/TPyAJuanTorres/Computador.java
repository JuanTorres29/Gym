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
