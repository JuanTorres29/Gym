import java.io.*;
import java.util.*;

class ConjuntoDeDatos implements Serializable {
    private String nombre;
    private int tamaño;

    public ConjuntoDeDatos(String nombre, int tamaño) {
        this.nombre = nombre;
        this.tamaño = tamaño;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getTamaño() {
        return tamaño;
    }

    public void setTamaño(int tamaño) {
        this.tamaño = tamaño;
    }

    public String describir() {
        return "Nombre: " + nombre + "\n" +
                "Tamaño: " + tamaño;
    }
}

class ConjuntoDeDatosTabular extends ConjuntoDeDatos {
    private int numeroDeColumnas;
    private int numeroDeFilas;

    public ConjuntoDeDatosTabular(String nombre, int tamaño, int numeroDeColumnas, int numeroDeFilas) {
        super(nombre, tamaño);
        this.numeroDeColumnas = numeroDeColumnas;
        this.numeroDeFilas = numeroDeFilas;
    }

    public int getNumeroDeColumnas() {
        return numeroDeColumnas;
    }

    public void setNumeroDeColumnas(int numeroDeColumnas) {
        this.numeroDeColumnas = numeroDeColumnas;
    }

    public int getNumeroDeFilas() {
        return numeroDeFilas;
    }

    public void setNumeroDeFilas(int numeroDeFilas) {
        this.numeroDeFilas = numeroDeFilas;
    }

    @Override
    public String describir() {
        return super.describir() + "\n" +
                "Tipo: Tabular" + "\n" +
                "Filas: " + numeroDeFilas + "\n" +
                "Columnas: " + numeroDeColumnas;
    }
}

class ConjuntoDeDatosImagen extends ConjuntoDeDatos {
    private int ancho;
    private int alto;

    public ConjuntoDeDatosImagen(String nombre, int tamaño, int ancho, int alto) {
        super(nombre, tamaño);
        this.ancho = ancho;
        this.alto = alto;
    }

    public int getAncho() {
        return ancho;
    }

    public void setAncho(int ancho) {
        this.ancho = ancho;
    }

    public int getAlto() {
        return alto;
    }

    public void setAlto(int alto) {
        this.alto = alto;
    }

    @Override
    public String describir() {
        return super.describir() + "\n" +
                "Tipo: Imagen" + "\n" +
                "Ancho: " + ancho + "\n" +
                "Alto: " + alto;
    }
}

class AnalizadorDeDatos {
    private List<ConjuntoDeDatos> conjuntosDeDatos;

    public AnalizadorDeDatos() {
        conjuntosDeDatos = new ArrayList<>();
    }

    public void añadirConjuntoDeDatos(ConjuntoDeDatos conjuntoDeDatos) {
        conjuntosDeDatos.add(conjuntoDeDatos);
    }

    public void eliminarConjuntoDeDatos(String nombre) {
        conjuntosDeDatos.removeIf(conjunto -> conjunto.getNombre().equals(nombre));
    }

    public List<String> describirConjuntosDeDatos() {
        List<String> descripciones = new ArrayList<>();
        for (ConjuntoDeDatos conjunto : conjuntosDeDatos) {
            descripciones.add(conjunto.describir());
        }
        return descripciones;
    }

    public void deserializarConjuntosDeDatos(String archivoRuta) {
        try {
            FileInputStream fis = new FileInputStream(archivoRuta);
            ObjectInputStream ois = new ObjectInputStream(fis);
            conjuntosDeDatos = (List<ConjuntoDeDatos>) ois.readObject();
            ois.close();
            fis.close();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    public String obtenerEstadisticasConjuntosDeDatos() {
        int totalConjuntos = conjuntosDeDatos.size();
        int totalTabulares = 0;
        int totalImagenes = 0;
        int pesoTabulares = 0;
        int pesoImagenes = 0;

        for (ConjuntoDeDatos conjunto : conjuntosDeDatos) {
            if (conjunto instanceof ConjuntoDeDatosTabular) {
                totalTabulares++;
                pesoTabulares += conjunto.getTamaño();
            } else if (conjunto instanceof ConjuntoDeDatosImagen) {
                totalImagenes++;
                pesoImagenes += conjunto.getTamaño();
            }
        }

        double porcentajeTabulares = (double) pesoTabulares / pesoImagenes * 100;
        double porcentajeImagenes = 100 - porcentajeTabulares;

        return "Total Conjuntos: " + totalConjuntos + "\n" +
                "Total Tabulares: " + totalTabulares + "\n" +
                "Total Imágenes: " + totalImagenes + "\n" +
                "Peso Total Tabulares: " + pesoTabulares + "\n" +
                "Peso Total Imágenes: " + pesoImagenes + "\n" +
                "Porcentaje Tabulares: " + porcentajeTabulares + "%" + "\n" +
                "Porcentaje Imágenes: " + porcentajeImagenes + "%";
    }

    public void ordenarConjuntosDeDatosPorTamaño() {
        Collections.sort(conjuntosDeDatos, (conjunto1, conjunto2) -> Integer.compare(conjunto1.getTamaño(), conjunto2.getTamaño()));
    }

    public List<ConjuntoDeDatos> getConjuntosDeDatos() {
        return conjuntosDeDatos;
    }

    public void setConjuntosDeDatos(List<ConjuntoDeDatos> conjuntosDeDatos) {
        this.conjuntosDeDatos = conjuntosDeDatos;
    }
}

public class Main {
    public static void main(String[] args) {
        ConjuntoDeDatosTabular conjuntoTabular = new ConjuntoDeDatosTabular("Datos de estudiantes", 1000, 5, 200);
        ConjuntoDeDatosImagen conjuntoImagen1 = new ConjuntoDeDatosImagen("Imágenes de satélite", 2000, 1080, 720);
        ConjuntoDeDatosImagen conjuntoImagen2 = new ConjuntoDeDatosImagen("Imágenes de satélite", 2000, 1080, 720);

        AnalizadorDeDatos analizador = new AnalizadorDeDatos();
        analizador.añadirConjuntoDeDatos(conjuntoTabular);
        analizador.añadirConjuntoDeDatos(conjuntoImagen1);
        analizador.añadirConjuntoDeDatos(conjuntoImagen2);

        List<String> descripciones = analizador.describirConjuntosDeDatos();
        for (String descripcion : descripciones) {
            System.out.println(descripcion);
            System.out.println("------------------------------");
        }

        System.out.println(analizador.obtenerEstadisticasConjuntosDeDatos());

        analizador.ordenarConjuntosDeDatosPorTamaño();
        List<ConjuntoDeDatos> conjuntosOrdenados = analizador.getConjuntosDeDatos();
        for (ConjuntoDeDatos conjunto : conjuntosOrdenados) {
            System.out.println(conjunto.describir());
            System.out.println("------------------------------");
        }
    }
}
