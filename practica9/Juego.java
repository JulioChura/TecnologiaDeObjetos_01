import java.util.Random;

// Elementos del juego
interface Elemento {
    String getNombre();
    int aplicarBonus(int danioBase);
}

class Fuego implements Elemento {
    public String getNombre() { return "Fuego"; }
    public int aplicarBonus(int danioBase) { return danioBase + 5; }
}

class Hielo implements Elemento {
    public String getNombre() { return "Hielo"; }
    public int aplicarBonus(int danioBase) { return danioBase + 3; }
}

// Armas del juego
interface Arma {
    int calcularDanio();
    String getNombre();
}

class Espada implements Arma {
    private Elemento elemento;
    
    public Espada(Elemento elemento) {
        this.elemento = elemento;
    }
    
    public int calcularDanio() {
        int danio = 20;
        if (elemento != null) {
            danio = elemento.aplicarBonus(danio);
        }
        //10% de chance de crítico
        if (new Random().nextDouble() < 0.1) {
            danio *= 2;
            System.out.println("¡Daño crítico!");
        }
        return danio;
    }
    
    public String getNombre() {
        return elemento != null ? "Espada de " + elemento.getNombre() : "Espada";
    }
}

class Arco implements Arma {
    private Elemento elemento;
    
    public Arco(Elemento elemento) {
        this.elemento = elemento;
    }
    
    public int calcularDanio() {
        int danio = 15;
        if (elemento != null) {
            danio = elemento.aplicarBonus(danio);
        }
        //20% de chance de crítico
        if (new Random().nextDouble() < 0.2) {
            danio *= 2;
            System.out.println("¡Daño crítico!");
        }
        return danio;
    }
    
    public String getNombre() {
        return elemento != null ? "Arco de " + elemento.getNombre() : "Arco";
    }
}

class Hacha implements Arma {
    private Elemento elemento;
    
    public Hacha(Elemento elemento) {
        this.elemento = elemento;
    }
    
    public int calcularDanio() {
        int danio = 25;
        if (elemento != null) {
            danio = elemento.aplicarBonus(danio);
        }
        //5% de chance de crítico
        if (new Random().nextDouble() < 0.05) {
            danio *= 2;
            System.out.println("¡Daño crítico!");
        }
        return danio;
    }
    
    public String getNombre() {
        return elemento != null ? "Hacha de " + elemento.getNombre() : "Hacha";
    }
}

// Personajes del juego
abstract class Personaje {
    protected String nombre;
    protected int salud;
    protected Arma arma;
    
    public Personaje(String nombre, int salud) {
        this.nombre = nombre;
        this.salud = salud;
    }
    
    public void equiparArma(Arma arma) {
        this.arma = arma;
        System.out.println(nombre + " equipó: " + arma.getNombre());
    }
    
    public void atacar(Personaje objetivo) {
        if (arma != null && estaVivo() && objetivo.estaVivo()) {
            int danio = arma.calcularDanio();
            System.out.println(nombre + " ataca con " + arma.getNombre() + "!");
            objetivo.recibirDanio(danio);
        }
    }
    
    public void recibirDanio(int danio) {
        salud -= danio;
        System.out.println(nombre + " recibe " + danio + " de daño. Salud: " + salud);
    }
    
    public boolean estaVivo() {
        return salud > 0;
    }
    
    public String getNombre() { return nombre; }
    public int getSalud() { return salud; }
}

class Jugador extends Personaje {
    private int nivel;
    
    public Jugador(String nombre) {
        super(nombre, 100);
        this.nivel = 1;
    }
    
    public void subirNivel() {
        nivel++;
        salud += 20;
        System.out.println(nombre + " subió al nivel " + nivel + "! Salud: " + salud);
    }
}

class Enemigo extends Personaje {
    public Enemigo(String nombre, int salud) {
        super(nombre, salud);
    }
}

//Juego principal
public class Juego {
    public static void main(String[] args) {
        System.out.println("=== INICIO DEL JUEGO ===\n");
        Jugador jugador = new Jugador("Héroe");
        Enemigo goblin = new Enemigo("Goblin", 50);
        Enemigo orco = new Enemigo("Orco", 80);
        Arma espadaFuego = new Espada(new Fuego());
        Arma arcoHielo = new Arco(new Hielo());
        Arma hacha = new Hacha(null);
        jugador.equiparArma(espadaFuego);
        goblin.equiparArma(arcoHielo);
        orco.equiparArma(hacha);
        System.out.println("\n--- Combate 1: " + jugador.getNombre() + " vs " + goblin.getNombre() + " ---");
        while (jugador.estaVivo() && goblin.estaVivo()) {
            jugador.atacar(goblin);
            if (goblin.estaVivo()) goblin.atacar(jugador);
        }
        if (jugador.estaVivo()) {
            System.out.println("\n¡" + jugador.getNombre() + " ganó el combate!");
            jugador.subirNivel();
            System.out.println("\n--- Combate 2: " + jugador.getNombre() + " vs " + orco.getNombre() + " ---");
            while (jugador.estaVivo() && orco.estaVivo()) {
                jugador.atacar(orco);
                if (orco.estaVivo()) orco.atacar(jugador);
            }
            if (jugador.estaVivo()) System.out.println("\n¡" + jugador.getNombre() + " es el campeón!");
            else System.out.println("\n¡" + orco.getNombre() + " ganó el combate!");
        } else {
            System.out.println("\n¡" + goblin.getNombre() + " ganó el combate!");
        }
        System.out.println("\n=== FIN DEL JUEGO ===");
    }
}