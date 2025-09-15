
public class Main {
    public static void main(String[] args) {
        System.out.println(" SIMULACIÓN DE COMBATE ");

        Personaje guerrero = new Personaje("Aragorn", 100, 25.5);
        Personaje mago = new Personaje("Gandalf", 80, 30.0);
        
        System.out.println("Estado inicial de los personajes:");
        guerrero.mostrarEstado();
        mago.mostrarEstado();
        
        System.out.println(" COMIENZA EL COMBATE ");
        
        // Simular combate
        int ronda = 1;
        while (guerrero.isVivo() && mago.isVivo()) {
            System.out.println("\n--- Ronda " + ronda + " ---");
            guerrero.atacar(mago);
            
            if (mago.isVivo()) {
                mago.atacar(guerrero);
            }
            
            // Intentar usar pociones (10% probabilidad cada turno)
            if (guerrero.intentarUsarPocion()) {
                guerrero.setNombre(guerrero.getNombre() + " [POTENCIADO]"); // Marca visual
            }
            if (mago.intentarUsarPocion()) {
                mago.setNombre(mago.getNombre() + " [POTENCIADO]"); // Marca visual
            }
            
            // Mostrar vida restante
            System.out.println(guerrero.getNombre() + " - Vida: " + guerrero.getVida());
            System.out.println(mago.getNombre() + " - Vida: " + mago.getVida());
            
            ronda++;
            
            // Evitar combate infinito
            if (ronda > 20) {
                System.out.println("\nEl combate es demasiado largo... ¡Empate!");
                break;
            }
        }
        
        System.out.println("\n FIN DEL COMBATE ");
        
        // Determinar ganador
        if (guerrero.isVivo() && !mago.isVivo()) {
            System.out.println("¡" + guerrero.getNombre() + " es el ganador!");
        } else if (!guerrero.isVivo() && mago.isVivo()) {
            System.out.println("¡" + mago.getNombre() + " es el ganador!");
        }
        
    }
}
