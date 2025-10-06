import java.util.ArrayList;
import java.util.regex.Pattern;

class GestorContacto {
    private ArrayList<Contacto> contactos;

    public GestorContacto() {
        contactos = new ArrayList<>();
    }

    private void validarNombre(String nombre) throws Exception {
        if (nombre == null || nombre.trim().isEmpty())
            throw new Exception("Nombre vacío");
        for (char c : nombre.toCharArray()) {
            if (Character.isDigit(c))
                throw new Exception("Nombre inválido");
        }
        for (Contacto c : contactos) {
            if (c.getNombre().equalsIgnoreCase(nombre))
                throw new Exception("Nombre duplicado: ya existe en la agenda");
        }
    }

    private void validarTelefono(String telefono) throws Exception {
        if (telefono == null || telefono.trim().isEmpty())
            throw new Exception("Teléfono vacío");

        telefono = telefono.trim();

        if (telefono.length() != 9)
            throw new Exception("Teléfono inválido (debe tener 9 dígitos)");

        if (!telefono.matches("\\d+"))
            throw new Exception("Teléfono inválido: solo se permiten números");

        boolean todosIguales = true;
        char primerDigito = telefono.charAt(0);
        for (int i = 1; i < telefono.length(); i++) {
            if (telefono.charAt(i) != primerDigito) {
                todosIguales = false;
                break;
            }
        }
        if (todosIguales)
            throw new Exception("Teléfono inválido: todos los dígitos son iguales");

        if (telefono.charAt(0) == '0')
            throw new Exception("Teléfono inválido: no puede comenzar con 0");

        for (Contacto c : contactos) {
            if (c.getTelefono().equals(telefono))
                throw new Exception("Teléfono duplicado");
        }
    }

    private void validarEmail(String email) throws Exception {
        String regex = "^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+$";
        if (!Pattern.matches(regex, email))
            throw new Exception("Email inválido");
        for (Contacto c : contactos) {
            if (c.getEmail().equalsIgnoreCase(email))
                throw new Exception("Email duplicado");
        }
    }

    public void agregarContacto(String nombre, String telefono, String email) {
        try {
            validarNombre(nombre);
            validarTelefono(telefono);
            validarEmail(email);
            contactos.add(new Contacto(nombre, telefono, email));
            System.out.println("Contacto agregado: " + nombre);
        } catch (Exception e) {
            System.out.println("Error al agregar contacto: " + e.getMessage());
        }
    }

    public void modificarContacto(String nombre, String nuevoTelefono, String nuevoEmail) {
        try {
            Contacto c = null;
            for (Contacto con : contactos) {
                if (con.getNombre().equalsIgnoreCase(nombre))
                    c = con;
            }
            if (c == null)
                throw new Exception("Contacto no encontrado");

            contactos.remove(c);
            validarTelefono(nuevoTelefono);
            validarEmail(nuevoEmail);

            c.setTelefono(nuevoTelefono);
            c.setEmail(nuevoEmail);
            contactos.add(c);

            System.out.println("Contacto modificado: " + nombre);
        } catch (Exception e) {
            System.out.println("Error al modificar contacto: " + e.getMessage());
        }
    }

    public void eliminarContacto(String nombre) {
        try {
            Contacto c = null;
            for (Contacto con : contactos) {
                if (con.getNombre().equalsIgnoreCase(nombre))
                    c = con;
            }
            if (c == null)
                throw new Exception("Contacto no encontrado");
            contactos.remove(c);
            System.out.println("Contacto eliminado: " + nombre);
        } catch (Exception e) {
            System.out.println("Error al eliminar contacto: " + e.getMessage());
        }
    }

    public void mostrarContactos() {
        if (contactos.isEmpty()) {
            System.out.println("No hay contactos");
            return;
        }
        for (Contacto c : contactos)
            System.out.println(c);
    }
}
