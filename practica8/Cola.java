public class Cola<T> {
    private Nodo<T> frente;
    private Nodo<T> fin;
    private int tamaño;
    
    public Cola() {
        this.frente = null;
        this.fin = null;
        this.tamaño = 0;
    }
    
    public void encolar(T dato) {
        Nodo<T> nuevoNodo = new Nodo<>(dato);
        if (estaVacia()) {
            frente = nuevoNodo;
        } else {
            fin.setSiguiente(nuevoNodo);
        }
        fin = nuevoNodo;
        tamaño++;
    }
    
    public T desencolar() {
        if (estaVacia()) {
            return null;
        }
        T dato = frente.getDato();
        frente = frente.getSiguiente();
        if (frente == null) {
            fin = null;
        }
        tamaño--;
        return dato;
    }
    
    public T verFrente() {
        return estaVacia() ? null : frente.getDato();
    }
    
    public boolean estaVacia() {
        return frente == null;
    }
    
    public int getTamaño() {
        return tamaño;
    }
    
    public void mostrar() {
        if (estaVacia()) {
            System.out.println("Cola vacía");
            return;
        }
        Nodo<T> actual = frente;
        int contador = 1;
        while (actual != null) {
            System.out.println("[" + contador + "] " + actual.getDato());
            actual = actual.getSiguiente();
            contador++;
        }
    }
}