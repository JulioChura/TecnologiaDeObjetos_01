import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        GestorContacto gestor = new GestorContacto();
        Scanner sc = new Scanner(System.in);

        try {
            gestor.agregarContacto("Juan Perez", "1234567890i", "juanex@ample.com");
            gestor.agregarContacto("Maria Lopez", "912345678", "maria@example.com");

            System.out.println("Contactos después de agregar:");
            gestor.mostrarContactos();

            gestor.modificarContacto("Juan Perez", "999888777", "juanp@correo.com");
            System.out.println("\nContactos después de modificar Juan Perez:");
            gestor.mostrarContactos();

            gestor.eliminarContacto("Maria Lopez");
            System.out.println("\nContactos después de eliminar Maria Lopez:");
            gestor.mostrarContactos();

        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }

        sc.close();
    }
}
