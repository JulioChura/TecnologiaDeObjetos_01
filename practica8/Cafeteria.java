import java.util.*;

public class Cafeteria {
    private ArrayList<Cliente> clientes;
    private ArrayList<Producto> productos;
    private Cola<Pedido> pedidosPendientes;

    public Cafeteria() {
        clientes = new ArrayList<>();
        productos = new ArrayList<>();
        pedidosPendientes = new Cola<>();
        
        // Productos predefinidos
        productos.add(new Producto("Café Expreso", 3.5));
        productos.add(new Producto("Café Americano", 4.0));
        productos.add(new Producto("Café Latte", 5.5));
        productos.add(new Producto("Té Verde", 2.5));
        productos.add(new Producto("Té Negro", 2.5));
        productos.add(new Producto("Sandwich Jamón y Queso", 5.0));
        productos.add(new Producto("Sandwich Pollo", 6.0));
        productos.add(new Producto("Pastel de Chocolate", 4.0));
        productos.add(new Producto("Galletas", 2.0));
        productos.add(new Producto("Jugo Natural", 3.0));
    }

    public Cliente buscarClientePorNombre(String nombre) {
        for (Cliente c : clientes) {
            if (c.getNombre().equalsIgnoreCase(nombre)) {
                return c;
            }
        }
        return null;
    }

    public Cliente buscarClientePorId(int id) {
        for (Cliente c : clientes) {
            if (c.getId() == id) {
                return c;
            }
        }
        return null;
    }

    private Pedido buscarPedidoEnCola(int id) {
        Cola<Pedido> temp = new Cola<>();
        Pedido encontrado = null;
        
        while (!pedidosPendientes.estaVacia()) {
            Pedido actual = pedidosPendientes.desencolar();
            if (actual.getId() == id) {
                encontrado = actual;
            }
            temp.encolar(actual);
        }
        
        while (!temp.estaVacia()) {
            pedidosPendientes.encolar(temp.desencolar());
        }
        
        return encontrado;
    }

    public void registrarCliente(Cliente c) {
        clientes.add(c);
    }

    public ArrayList<Producto> getProductos() {
        return productos;
    }

    public void registrarPedido(Pedido p) {
        pedidosPendientes.encolar(p);
    }

    public void mostrarPedidos() {
        if (pedidosPendientes.estaVacia()) {
            System.out.println("No hay pedidos pendientes.");
            return;
        }
        System.out.println("\n=== PEDIDOS PENDIENTES (EN COLA) ===");
        pedidosPendientes.mostrar();
    }

    public void mostrarClientes() {
        if (clientes.isEmpty()) {
            System.out.println("No hay clientes registrados.");
            return;
        }
        System.out.println("\n=== CLIENTES REGISTRADOS ===");
        for (Cliente c : clientes) {
            System.out.println(c);
        }
    }

    public void entregarSiguientePedido() {
        Pedido pedido = pedidosPendientes.desencolar();
        if (pedido != null) {
            pedido.setEstado("ENTREGADO");
            System.out.println("\nPEDIDO ENTREGADO EXITOSAMENTE:");
            System.out.println(pedido);
        } else {
            System.out.println("No hay pedidos pendientes para entregar.");
        }
    }

    public void verSiguientePedido() {
        Pedido pedido = pedidosPendientes.verFrente();
        if (pedido != null) {
            System.out.println("\nSIGUIENTE PEDIDO EN COLA:");
            System.out.println(pedido);
        } else {
            System.out.println("No hay pedidos pendientes.");
        }
    }

    public void cambiarEstadoPedido(int id, String nuevoEstado) {
        Pedido pedido = buscarPedidoEnCola(id);
        if (pedido != null) {
            String estadoAnterior = pedido.getEstado();
            pedido.setEstado(nuevoEstado);
            System.out.println("\nEstado del pedido #" + id + " cambiado:");
            System.out.println("De: " + estadoAnterior + " → A: " + nuevoEstado);
        } else {
            System.out.println("No se encontró el pedido con ID: " + id);
        }
    }

    public void cancelarPedido(int id) {
        Cola<Pedido> temp = new Cola<>();
        boolean encontrado = false;
        
        while (!pedidosPendientes.estaVacia()) {
            Pedido actual = pedidosPendientes.desencolar();
            if (actual.getId() == id) {
                System.out.println("\nPEDIDO CANCELADO:");
                System.out.println(actual);
                encontrado = true;
            } else {
                temp.encolar(actual);
            }
        }
        
        while (!temp.estaVacia()) {
            pedidosPendientes.encolar(temp.desencolar());
        }
        
        if (!encontrado) {
            System.out.println("No se encontró el pedido con ID: " + id);
        }
    }

    public int getCantidadPedidosPendientes() {
        return pedidosPendientes.getTamaño();
    }

    public ArrayList<Cliente> getClientes() {
        return clientes;
    }
}