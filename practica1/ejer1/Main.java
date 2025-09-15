import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Jugador 1 crea tu Personaje");
        System.out.print("Nombre: ");
        String nombre1 = sc.nextLine();
        System.out.print("Vida: ");
        int vida1 = sc.nextInt();
        System.out.print("Ataque: ");
        int ataque1 = sc.nextInt();
        System.out.print("Defensa: ");
        int defensa1 = sc.nextInt();

        sc.nextLine(); //Limpia buffer

        Personaje jugador1 = new Personaje(nombre1, vida1, ataque1, defensa1);

        System.out.println("\nJugador 2 crea tu personaje");
        System.out.print("Nombre: ");
        String nombre2 = sc.nextLine();
        System.out.print("Vida: ");
        int vida2 = sc.nextInt();
        System.out.print("Ataque: ");
        int ataque2 = sc.nextInt();
        System.out.print("Defensa: ");
        int defensa2 = sc.nextInt();
        Personaje jugador2 = new Personaje(nombre2, vida2, ataque2, defensa2);

        //Batalla
        System.out.println("\n¡Comienza la batalla!");
        int turno = 1;
        while (jugador1.estaVivo() && jugador2.estaVivo()) {
            System.out.println("\nTurno " + turno);

            jugador1.atacar(jugador2);
            if (!jugador2.estaVivo()) break;

            jugador2.atacar(jugador1);
            turno++;
        }

        //Mostrar resultado
        System.out.println("\nResultado de la batalla");
        if (jugador1.estaVivo()) {
            System.out.println(jugador1.getNombre() + " es el ganador con " + jugador1.getVida() + " de vida restante.");
        } else {
            System.out.println(jugador2.getNombre() + " es el ganador con " + jugador2.getVida() + " de vida restante.");
        }

        sc.close();
    }
}
