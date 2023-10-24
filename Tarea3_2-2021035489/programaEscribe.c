
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>



/*      Ejercicio 2.
    Escriba dos programas. Un programa llenará el archivo con información
    de 10 empleados de forma incremental. Es decir, agrega un empleado,
    duerme por unos 2 segundos y luego agrega otro empleado. 
    Un segundo programa deberá leer períodicamente (cada 2 segundos) 
    la información del archivo e imprimirla. Note que usted debe usar
    bloqueos para impedir que el archivo de lectura obtenga información 
    inconsistente.
*/


#define numEmpleados 10

struct Employee {
    char name[50];
    int id;
};

int main() {
        int file = open("archivo.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);

    if (file == -1) {
        perror("Error al abrir el archivo");
        exit(1);
    }
    struct Employee emp;
    for (int i = 1; i <= numEmpleados; i++) {
        emp.id = i;
        sprintf(emp.name, "Empleado%d", i);//Copia nombre
        flock(file, LOCK_EX); // Adquiere un bloqueo exclusivo.
        dprintf(file, "id: %d, name: %s\n", emp.id, emp.name);
        fsync(file); // Asegura que los datos se escriban en disco.
        flock(file, LOCK_UN); // Libera el bloqueo exclusivo.
        printf("Empleado %d agregado.\n", i);
        sleep(2); // Espera 2 segundos antes de agregar el siguiente empleado.
    }
    close(file);
    return 0;
}
