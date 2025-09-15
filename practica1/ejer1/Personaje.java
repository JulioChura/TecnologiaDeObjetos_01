public class Personaje {
    
    private String nombre;           // String
    private int vida;               // int
    private double fuerza;          // double
    private boolean esVivo;         // boolean
    private boolean pocionUsada;    // Controla si ya usó la poción
    private int turnosBoost;        // Turnos restantes de boost
    
    // Constructor
    public Personaje(String nombre, int vida, double fuerza) {
        this.nombre = nombre;
        this.vida = vida;
        this.fuerza = fuerza;
        this.esVivo = true; // Al crear el personaje está vivo
        this.pocionUsada = false;
        this.turnosBoost = 0;
    }
    
    // Método PUBLIC - para atacar a otro personaje
    public void atacar(Personaje objetivo) {
        if (!this.esVivo) {
            System.out.println(this.nombre + " no puede atacar porque está muerto.");
            return;
        }
        
        double dmg = calcularDamage(); // Usa método privado
        objetivo.recibirDamage((int)dmg);
        System.out.println(this.nombre + " ataca a " + objetivo.nombre + 
                          " causando " + (int)dmg + " puntos de dmg!");
    }
    
    // Método PRIVATE - para calcular dmg interno
    private double calcularDamage() {
        double dmgBase = this.fuerza * (0.8 + Math.random() * 0.4); //rango de 80% - 120% de la fuerza
        
        // Aplicar boost si está activo
        if (this.turnosBoost > 0) {
            dmgBase *= 1.5;  
            this.turnosBoost--; 
        }
        
        return dmgBase;
    }
    
    // Método PROTECTED - para regenerar vida 
    protected void regenerarVida(int cantidad) {
        if (this.esVivo) {
            this.vida += cantidad;
            if (this.vida > 100) {
                this.vida = 100; // Máximo 100 de vida
            }
            System.out.println(this.nombre + " regenera " + cantidad + 
                              " puntos de vida. Vida actual: " + this.vida);
        }
    }
    
    // Método PUBLIC - para mostrar el estado del personaje
    public void mostrarEstado() {
        String estado = esVivo ? "Vivo" : "Muerto";
        System.out.println("=== Estado de " + nombre + " ===");
        System.out.println("Vida: " + vida);
        System.out.println("Fuerza: " + fuerza);
        System.out.println("Estado: " + estado);
        System.out.println("========================");
    }
    
    // Método para recibir dmg
    public void recibirDamage(int dmg) {
        this.vida -= dmg;
        if (this.vida <= 0) {
            this.vida = 0;
            this.esVivo = false;
            System.out.println(this.nombre + " ha sido derrotado!");
        }
    }
    
    // GETTER para nombre
    public String getNombre() {
        return nombre;
    }
    
    // SETTER para nombre
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    
    // GETTER para vida
    public int getVida() {
        return vida;
    }
    
    // SETTER para vida
    public void setVida(int vida) {
        this.vida = vida;
        if (this.vida <= 0) {
            this.esVivo = false;
        } else {
            this.esVivo = true;
        }
    }
    
    // GETTER para fuerza
    public double getFuerza() {
        return fuerza;
    }
    
    // SETTER para fuerza
    public void setFuerza(double fuerza) {
        this.fuerza = fuerza;
    }
    
    // GETTER para esVivo
    public boolean isVivo() {
        return esVivo;
    }
    
    // Método para usar una poción de daño (10% probabilidad, una vez por batalla)
    public boolean intentarUsarPocion() {
        if (!this.pocionUsada && this.esVivo && Math.random() < 0.1) {
            this.pocionUsada = true;
            this.turnosBoost = 2; // Boost por 2 turnos
            regenerarVida(15); // Usa método protected
            System.out.println(this.nombre + " usa una poción de combate. Dmg boosteado por 2 turnos");
            return true;
        }
        return false;
    }
    
    
}