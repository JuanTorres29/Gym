// Importamos la clase ArrayList y la interfaz List del paquete java.util
import java.util.*;

// Definimos una clase abstracta llamada Modelo
abstract class Modelo{

  // Atributos de la clase Modelo
  private String nombre; 
  private int numeroParametros;

  // Constructor de la clase Modelo
  public Modelo(String nombre, int numeroParametros){
    this.nombre = nombre;
    this.numeroParametros = numeroParametros;
  };

  // Getters de la clase Modelo
  public String getNombre() {
    return nombre;
  }

  public int getNumeroParametros() {
    return numeroParametros;
  }
  
  // Setters de la clase Modelo
  public void setNombre(String nombre) {
    this.nombre = nombre;
  }

  public void setNumeroParametros(int numeroParametros) {
    this.numeroParametros = numeroParametros;
  }

  // Método abstracto que será implementado en las clases hijas
  public abstract void entrenar();
}

// Definimos la clase ModeloLineal que hereda de Modelo
public class ModeloLineal extends Modelo{

  // Atributos específicos de la clase ModeloLineal
  private double coeficienteCorrelacion;
  private double errorCuadraticoMedio;

  // Constructor de la clase ModeloLineal
  public ModeloLineal(String nombre, int numeroParametros, double coeficienteCorrelacion, double errorCuadraticoMedio){
    super(nombre,numeroParametros);
    this.coeficienteCorrelacion = coeficienteCorrelacion;
    this.errorCuadraticoMedio = errorCuadraticoMedio;
  }

  // Getters y Setters de la clase ModeloLineal
  public double getCoeficienteCorrelacion() {
    return coeficienteCorrelacion;
  }

  public double getErrorCuadraticoMedio() {
    return errorCuadraticoMedio;
  }
  
  public void setCoeficienteCorrelacion(double coeficienteCorrelacion) {
    this.coeficienteCorrelacion = coeficienteCorrelacion;
  }

  public void setErrorCuadraticoMedio(double errorCuadraticoMedio) {
    this.errorCuadraticoMedio = errorCuadraticoMedio;
  }

  // Implementación del método abstracto entrenar heredado de la clase Modelo
  @Override
  public void entrenar(){
    System.out.println("\nEntrenando modelo lineal: " + getNombre());
    System.out.println("Número de parámetros: " + getNumeroParametros());                   
    System.out.println("Coeficiente de correlación inicial: " + getCoeficienteCorrelacion());                       
    System.out.println("Error cuadrático medio inicial: " + getErrorCuadraticoMedio());
    System.out.println("Entrenamiento completado.");
  }
}

// Definimos la clase ModeloArbolDecision que también hereda de Modelo
public class ModeloArbolDecision extends Modelo{

  // Atributos específicos de la clase ModeloArbolDecision
  private int profundidaArbol;
  private int cantidadNodos;

  // Constructor de la clase ModeloArbolDecision
  public ModeloArbolDecision(String nombre, int numeroParametros, int profundidaArbol, int cantidadNodos){
    super(nombre,numeroParametros);
    this.profundidaArbol = profundidaArbol;
    this.cantidadNodos = cantidadNodos;
  }

  // Getters y Setters de la clase ModeloArbolDecision
  public int getProfundidaArbol() {
    return profundidaArbol;
  }

  public int getCantidadNodos() {
    return cantidadNodos;
  }
  
  public void setProfundidaArbol(int profundidaArbol) {
    this.profundidaArbol = profundidaArbol;
  }

  public void setCantidadNodos(int cantidadNodos) {
    this.cantidadNodos = cantidadNodos;
  }

  // Implementación del método abstracto entrenar heredado de la clase Modelo
  @Override
  public void entrenar(){
    System.out.println("\nEntrenando modelo de arbol de decision:" +getNombre());
    System.out.println("Numero de parámetros:"+getNumeroParametros());
    System.out.println("Profundidad del arbol:" +getProfundidaArbol());                    
    System.out.println("Numero de nodos hoja:" +getCantidadNodos());
    System.out.println("Entrenamiento completado.");
  };
}

// Definimos la clase Validador que se encargará de validar los modelos
class Validador {
  
  // Método que recibe un modelo y lo valida dependiendo de su tipo
  public void validarModelo(Modelo modelo) {
    modelo.entrenar();

    if (modelo instanceof ModeloLineal) {
      validarModeloLineal((ModeloLineal) modelo);
    } else if (modelo instanceof ModeloArbolDecision) {
      validarModeloArbolDecision((ModeloArbolDecision) modelo);
    } else {
      System.out.println("Tipo de modelo no soportado: " + modelo.getClass().getSimpleName());
    }
  }

  // Método para validar un modelo de tipo ModeloLineal
  private void validarModeloLineal(ModeloLineal modeloLineal) {
    if (modeloLineal.getCoeficienteCorrelacion() > 0.8 && modeloLineal.getErrorCuadraticoMedio()<0.2) {
      System.out.println("El modelo: " + modeloLineal.getNombre() + " ha pasado la validación.");
    } else {
      System.out.println("El modelo: " + modeloLineal.getNombre() + " no ha pasado la validacion");
    }
  }

  // Método para validar un modelo de tipo ModeloArbolDecision
  private void validarModeloArbolDecision(ModeloArbolDecision modeloArbolDecision) {
    if (modeloArbolDecision.getProfundidaArbol() < 10 && modeloArbolDecision.getCantidadNodos() > 5) {
      System.out.println("El modelo: " + modeloArbolDecision.getNombre() + " ha pasado la validación.");
    } else {
      System.out.println("El modelo: " + modeloArbolDecision.getNombre() + " no ha pasado la validacion");
    }
  }
}

// Clase principal del programa
class Main {
  public static void main(String[] args) {
    // Se crean varios modelos y se añaden a una lista de modelos
    ArrayList<Modelo> listaModelos = new ArrayList<>();
    Validador validadorModelos = new Validador();
    ModeloLineal modeloLinealFork = new ModeloLineal("FORK", 5, 0.2, 0.5);
    ModeloArbolDecision modeloArbolDecisionChaid = new ModeloArbolDecision("CHAID", 3, 10, 2);

    listaModelos.add(modeloLinealFork);
    listaModelos.add(modeloArbolDecisionChaid);

    // Se recorren todos los modelos y se valida cada uno de ellos
    for (Modelo modeloActual : listaModelos) {
      validadorModelos.validarModelo(modeloActual);
    }
  }
}

