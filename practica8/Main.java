import java.util.Scanner;

public class Main {
    private static final Scanner sc = new Scanner(System.in);
    private static final Cafeteria cafeteria = new Cafeteria();

    public static void main(String[] args) {
        System.out.println("====================================");
        System.out.println("    SISTEMA DE GESTIÓN CAFETERÍA    ");
        System.out.println("====================================");
        mostrarMenu();
        sc.close();
    }

    public static void mostrarMenu() {
        int opcion;
        do {
            System.out.println("\n=== MENÚ PRINCIPAL ===");
            System.out.println("1. Registrar cliente");
            System.out.println("2. Registrar pedido");
            System.out.println("3. Mostrar pedidos pendientes");
            System.out.println("4. Gestionar pedidos");
            System.out.println("5. Mostrar todos los clientes");
            System.out.println("0. Salir");
            System.out.print("Elige una opción: ");
            opcion = sc.nextInt();
            sc.nextLine();

            switch (opcion) {
                case 1 -> registrarCliente();
                case 2 -> registrarPedido();
                case 3 -> cafeteria.mostrarPedidos();
                case 4 -> gestionarPedidos();
                case 5 -> cafeteria.mostrarClientes();
                case 0 -> System.out.println("Saliendo del sistema...");
                default -> System.out.println("Opción inválida.");
            }
        } while (opcion != 0);
    }

    private static void registrarCliente() {
        System.out.println("\n=== REGISTRAR NUEVO CLIENTE ===");
        System.out.print("Nombre: ");
        String nombre = sc.nextLine();
        System.out.print("Teléfono: ");
        String telefono = sc.nextLine();
        System.out.print("Correo: ");
        String correo = sc.nextLine();

        Cliente c = new Cliente(nombre, telefono, correo);
        cafeteria.registrarCliente(c);
        System.out.println("Cliente registrado con ID: " + c.getId());
    }

    private static void registrarPedido() {
        if (cafeteria.getProductos().isEmpty()) {
            System.out.println("No hay productos disponibles.");
            return;
        }

        if (cafeteria.getClientes().isEmpty()) {
            System.out.println("No hay clientes registrados. Registra un cliente primero.");
            return;
        }

        System.out.println("\n=== REGISTRAR NUEVO PEDIDO ===");
        cafeteria.mostrarClientes();
        
        System.out.print("\nIngresa el ID del cliente: ");
        int idCliente = sc.nextInt();
        sc.nextLine();

        Cliente cliente = cafeteria.buscarClientePorId(idCliente);
        if (cliente == null) {
            System.out.println("Cliente no encontrado.");
            return;
        }

        Pedido pedido = new Pedido(cliente);
        int opcionProducto;
        
        System.out.println("\n--- SELECCIÓN DE PRODUCTOS ---");
        do {
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
                System.out.println("Productos en pedido: " + pedido.calcularTotal() + " soles");
            } else if (opcionProducto != 0) {
                System.out.println("Opción inválida.");
            }
        } while (opcionProducto != 0);

        if (pedido.calcularTotal() > 0) {
            cafeteria.registrarPedido(pedido);
            System.out.println("Pedido registrado con ID: " + pedido.getId());
            System.out.println("Total a pagar: S/." + pedido.calcularTotal());
        } else {
            System.out.println("Pedido cancelado (no se agregaron productos).");
        }
    }

    private static void gestionarPedidos() {
        int opcion;
        do {
            System.out.println("\n=== GESTIÓN DE PEDIDOS ===");
            System.out.println("Pedidos pendientes: " + cafeteria.getCantidadPedidosPendientes());
            System.out.println("1. Ver siguiente pedido");
            System.out.println("2. Entregar siguiente pedido");
            System.out.println("3. Mostrar todos los pedidos pendientes");
            System.out.println("4. Cambiar estado de un pedido");
            System.out.println("5. Cancelar pedido");
            System.out.println("0. Volver al menú principal");
            System.out.print("Elige una opción: ");
            opcion = sc.nextInt();
            sc.nextLine();

            switch (opcion) {
                case 1 -> cafeteria.verSiguientePedido();
                case 2 -> cafeteria.entregarSiguientePedido();
                case 3 -> cafeteria.mostrarPedidos();
                case 4 -> cambiarEstadoPedido();
                case 5 -> cancelarPedido();
                case 0 -> System.out.println("↩ Volviendo al menú principal...");
                default -> System.out.println("Opción inválida.");
            }
        } while (opcion != 0);
    }

    private static void cambiarEstadoPedido() {
        System.out.print("\nIngresa el ID del pedido: ");
        int idPedido = sc.nextInt();
        sc.nextLine();
        
        System.out.println("\nEstados disponibles:");
        System.out.println("1. PENDIENTE");
        System.out.println("2. EN PREPARACIÓN"); 
        System.out.println("3. LISTO PARA ENTREGAR");
        System.out.println("4. ENTREGADO");
        System.out.print("Elige el nuevo estado (1-4): ");
        int estadoOp = sc.nextInt();
        sc.nextLine();
        
        String nuevoEstado = "";
        switch (estadoOp) {
            case 1 -> nuevoEstado = "PENDIENTE";
            case 2 -> nuevoEstado = "EN PREPARACIÓN";
            case 3 -> nuevoEstado = "LISTO PARA ENTREGAR";
            case 4 -> nuevoEstado = "ENTREGADO";
            default -> {
                System.out.println("Estado inválido");
                return;
            }
        }
        
        cafeteria.cambiarEstadoPedido(idPedido, nuevoEstado);
    }

    private static void cancelarPedido() {
        System.out.print("\nIngresa el ID del pedido a cancelar: ");
        int idPedido = sc.nextInt();
        sc.nextLine();
        
        System.out.print("¿Estás seguro de cancelar el pedido #" + idPedido + "? (s/n): ");
        String confirmacion = sc.nextLine();
        
        if (confirmacion.equalsIgnoreCase("s")) {
            cafeteria.cancelarPedido(idPedido);
        } else {
            System.out.println("Cancelación abortada.");
        }
    }
}
