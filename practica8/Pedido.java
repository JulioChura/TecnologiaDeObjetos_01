
import java.util.*;

public class Pedido {
    private static int contadorId = 1;
    private int id;
    private Cliente cliente;
    private ArrayList<Producto> productos;
    private String estado;

    public Pedido(Cliente cliente) {
        this.id = contadorId++;
        this.cliente = cliente;
        this.productos = new ArrayList<>();
        this.estado = "PENDIENTE";
    }

    public int getId() {
        return id;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public String getEstado() {
        return estado;
    }

    public void setEstado(String estado) {
        this.estado = estado;
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
        sb.append("----------------------------------\n");
        sb.append("Pedido #").append(id).append(" - ").append(estado).append("\n");
        sb.append("Cliente: ").append(cliente.getNombre()).append(" (ID: ").append(cliente.getId()).append(")\n");
        sb.append("Productos:\n");
        for (Producto p : productos) {
            sb.append("  - ").append(p).append("\n");
        }
        sb.append("TOTAL: S/.").append(calcularTotal()).append("\n");
        sb.append("----------------------------------");
        return sb.toString();
    }
}