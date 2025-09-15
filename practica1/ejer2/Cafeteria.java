import java.util.*;

public class Cafeteria {
    private ArrayList<Cliente> clientes;
    private ArrayList<Producto> productos;
    private ArrayList<Pedido> pedidos;

    public Cafeteria() {
        clientes = new ArrayList<>();
        productos = new ArrayList<>();
        pedidos = new ArrayList<>();

        productos.add(new Producto("Café", 3.5));
        productos.add(new Producto("Té", 2.5));
        productos.add(new Producto("Sandwich", 5.0));
        productos.add(new Producto("Pastel", 4.0));
    }

    public void registrarCliente(Cliente c) {
        clientes.add(c);
    }

    public ArrayList<Producto> getProductos() {
        return productos;
    }

    public void registrarPedido(Pedido p) {
        pedidos.add(p);
    }

    public void mostrarPedidos() {
        for (Pedido p : pedidos) {
            System.out.println(p);
            System.out.println("--------------");
        }
    }
}
