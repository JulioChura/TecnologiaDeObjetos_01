public class Personaje {
    private String nombre;
    private int vida;
    private int ataque;
    private int defensa;
    protected int nivel;

    //constructor
    public Personaje(String nombre, int vida, int ataque, int defensa) {
        this.nombre = nombre;
        this.vida = vida;
        this.ataque = ataque;
        this.defensa = defensa;
        this.nivel = 1; 
    }

    // Getter y Setter 
    public int getVida() {
        return vida;
    }

    public void setVida(int vida) {
        this.vida = vida;
    }

    //lectura para el nombre
    public String getNombre() {
        return nombre;
    }

    //atacar
    public void atacar(Personaje enemigo) {
        int danio = calcularDanio(enemigo.getDefensa());
        enemigo.recibirDanio(danio);
        System.out.println(this.nombre + " ataca a " + enemigo.getNombre() + " causando " + danio + " de daño.");
    }

    //calcular daño
    private int calcularDanio(int defensaEnemigo) {
        int danio = this.ataque - defensaEnemigo;
        return Math.max(danio, 1); //daño mínimo 1
    }

    //recibir daño
    protected void recibirDanio(int danio) {
        this.vida -= danio;
        if (this.vida < 0) this.vida = 0;
    }

    public boolean estaVivo() {
        return this.vida > 0;
    }
}
