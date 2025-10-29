public class Pila<E> {
    private final int tamano;
    private int superior;
    private E[] elementos;

    @SuppressWarnings("unchecked")
    public Pila() {
        this.tamano = 10;
        this.superior = -1;
        this.elementos = (E[]) new Object[tamano];
    }

    @SuppressWarnings("unchecked")
    public Pila(int s) {
        this.tamano = s;
        this.superior = -1;
        this.elementos = (E[]) new Object[tamano];
    }

    public void push(E valorAMeter) throws Exception {
        if (superior == tamano - 1)
            throw new Exception("ExcepcionPilaLlena");
        elementos[++superior] = valorAMeter;
    }

    public E pop() throws Exception {
        if (superior == -1)
            throw new Exception("ExcepcionPilaVacia");
        return elementos[superior--];
    }
}

class Main {
    public static void main(String[] args) {
        try {
            Pila<Integer> pila = new Pila<>(5);
            pila.push(10);
            pila.push(20);
            pila.push(30);
            System.out.println(pila.pop());
            System.out.println(pila.pop());
            System.out.println(pila.pop());
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
