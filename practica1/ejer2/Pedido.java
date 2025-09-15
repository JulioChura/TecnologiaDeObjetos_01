import java.util.*;

public class Pedido {
    private Cliente cliente;
    private ArrayList<Producto> productos;

    public Pedido(Cliente cliente) {
        this.cliente = cliente;
        this.productos = new ArrayList<>();
    }

    public void agregarProducto(Producto p) {
        productos.add(p);
    }

    public double calcularTotal() {
        double total = 0;
        for (Producto p : productos) {
            total += p.getPrecio();
        }
        return total;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(cliente.getNombre()).append(" pidió:\n");
        for (Producto p : productos) {
            sb.append("- ").append(p).append("\n");
        }
        sb.append("Total: S/.").append(calcularTotal());
        return sb.toString();
    }
}

