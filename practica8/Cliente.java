public class Cliente {
    private static int contadorId = 1;
    private int id;
    private String nombre;
    private String telefono;
    private String correo;

    public Cliente(String nombre, String telefono, String correo) {
        this.id = contadorId++;
        this.nombre = nombre;
        this.telefono = telefono;
        this.correo = correo;
    }

    public int getId() {
        return id;
    }

    public String getNombre() {
        return nombre;
    }

    public String getTelefono() {
        return telefono;
    }

    public String getCorreo() {
        return correo;
    }

    @Override
    public String toString() {
        return "ID: " + id + " | Cliente: " + nombre + " | Tel: " + telefono + " | Correo: " + correo;
    }
}
