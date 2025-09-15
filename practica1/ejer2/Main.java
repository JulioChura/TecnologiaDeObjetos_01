import java.util.Scanner;

public class Main {
    private static final Scanner sc = new Scanner(System.in);
    private static final Cafeteria cafeteria = new Cafeteria();

    public static void main(String[] args) {
        mostrarMenu();
        sc.close();
    }

    public static void mostrarMenu() {
        int opcion;
        do {
            System.out.println("\n=== CAFETERÍA ===");
            System.out.println("1. Registrar cliente");
            System.out.println("2. Registrar pedido");
            System.out.println("3. Mostrar pedidos");
            System.out.println("0. Salir");
            System.out.print("Elige una opción: ");
            opcion = sc.nextInt();
            sc.nextLine();

            switch (opcion) {
                case 1 -> registrarCliente();
                case 2 -> registrarPedido();
                case 3 -> cafeteria.mostrarPedidos();
                case 0 -> System.out.println("Saliendo...");
                default -> System.out.println("Opción inválida.");
            }
        } while (opcion != 0);
    }

    private static void registrarCliente() {
        System.out.print("Nombre: ");
        String nombre = sc.nextLine();
        System.out.print("Teléfono: ");
        String telefono = sc.nextLine();
        System.out.print("Correo: ");
        String correo = sc.nextLine();

        Cliente c = new Cliente(nombre, telefono, correo);
        cafeteria.registrarCliente(c);
        System.out.println("Cliente registrado!");
    }

    private static void registrarPedido() {
        if (cafeteria.getProductos().isEmpty()) {
            System.out.println("No hay productos disponibles.");
            return;
        }

        System.out.print("Nombre del cliente: ");
        String nombreCliente = sc.nextLine();

        Cliente cliente = cafeteria.buscarClientePorNombre(nombreCliente);
        if (cliente == null) {
            System.out.println("Cliente no encontrado. Regístralo primero.");
            return;
        }

        Pedido pedido = new Pedido(cliente);
        int opcionProducto;
        do {
            System.out.println("\n--- MENU DE PRODUCTOS ---");
            int i = 1;
            for (Producto p : cafeteria.getProductos()) {
                System.out.println(i + ". " + p);
                i++;
            }
            System.out.println("0. Terminar pedido");
            System.out.print("Elige producto: ");
            opcionProducto = sc.nextInt();
            sc.nextLine();

            if (opcionProducto > 0 && opcionProducto <= cafeteria.getProductos().size()) {
                Producto seleccionado = cafeteria.getProductos().get(opcionProducto - 1);
                pedido.agregarProducto(seleccionado);
                System.out.println("Producto agregado: " + seleccionado.getNombre());
            }
        } while (opcionProducto != 0);

        cafeteria.registrarPedido(pedido);
        System.out.println("Pedido registrado!");
    }
}
