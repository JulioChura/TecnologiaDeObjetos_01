public class Main {
    public static void main(String[] args) {
        GestorContacto gestor = new GestorContacto();

        System.out.println("PRUEBA DE EXCEPCIONES CON DOS CONTACTOS\n");

        // 1agregar dos contactos válidos
        gestor.agregarContacto("Juan Perez", "912345678", "juan@example.com");
        gestor.agregarContacto("Maria Lopez", "923456789", "maria@example.com");

        // intentar agregar contactos con datos inválidos
        gestor.agregarContacto("", "912345678", "test1@example.com");           // Nombre vacío
        gestor.agregarContacto("Ana88", "912305678", "test2@example.com");     // Nombre con números
        gestor.agregarContacto("Luis", "", "test3@example.com");                 // Teléfono vacío
        gestor.agregarContacto("Pedro", "12345", "test4@example.com");           // Teléfono corto
        gestor.agregarContacto("Marta", "999999999", "test5@example.com");       // Teléfono todos iguales
        gestor.agregarContacto("Sofia", "012345678", "test6@example.com");       // Teléfono empieza con 0
        gestor.agregarContacto("Carlos", "934567890", "correo-invalido");       // Email inválido

        // ntentar agregar duplicados
        gestor.agregarContacto("Juan Perez", "987654321", "nuevo@example.com"); // Nombre duplicado
        gestor.agregarContacto("Otro", "912345678", "otro@example.com");        // Teléfono duplicado
        gestor.agregarContacto("Otro2", "934567890", "juan@example.com");       // Email duplicado

        // modificaciones inválidas
        gestor.modificarContacto("Inexistente", "987654321", "nuevo@mail.com"); // Contacto no existe
        gestor.modificarContacto("Juan Perez", "000000000", "nuevo@mail.com");  // Teléfono inválido
        gestor.modificarContacto("Juan Perez", "987654321", "maria@example.com");// Email duplicado

        // probar eliminacion de contacto inexistente
        gestor.eliminarContacto("NoExiste");
        System.out.println("\nContactos existentes:");
        gestor.mostrarContactos();
    }
}
