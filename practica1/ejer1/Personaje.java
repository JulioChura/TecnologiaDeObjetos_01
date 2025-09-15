public class Personaje {
    
    private String nombre;          
    private int vida;               
    private double fuerza;         
    private boolean esVivo;         
    private boolean pocionUsada;    
    private int turnosBoost;       
    
    public Personaje(String nombre, int vida, double fuerza) {
        this.nombre = nombre;
        this.vida = vida;
        this.fuerza = fuerza;
        this.esVivo = true; 
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

    public String getNombre() {
        return nombre;
    }
    
    public void setNombre(String nombre) {
        if (nombre != null && !nombre.trim().isEmpty()) {
            this.nombre = nombre;
        }
    }
    
    public int getVida() {
        return vida;
    }
    
    public void setVida(int vida) {
        if (vida < 0) {
            this.vida = 0;
            this.esVivo = false;
        } else if (vida > 100) {
            this.vida = 100;
        } else {
            this.vida = vida;
            this.esVivo = true;
        }
    }
    
    public double getFuerza() {
        return fuerza;
    }
    
    public void setFuerza(double fuerza) {
        if (fuerza > 0) {
            this.fuerza = fuerza;
        }
    }
    
    public boolean isVivo() {
        return esVivo;
    }
    
    public boolean isPocionUsada() {
        return pocionUsada;
    }
    
    public int getTurnosBoost() {
        return turnosBoost;
    }
    
    public void setTurnosBoost(int turnosBoost) {
        if (turnosBoost >= 0) {
            this.turnosBoost = turnosBoost;
        }
    }
}