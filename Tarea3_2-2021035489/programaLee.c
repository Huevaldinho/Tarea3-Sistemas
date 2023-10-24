#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h> // Agregar esta línea para resolver el problema
#include <sys/file.h>


int main() {
    int file = open("archivo.txt", O_RDONLY);
    if (file == -1) {
        perror("Error al abrir el archivo");
        exit(1);
    }
    ssize_t bytes_read;
    char buffer[100];
    while (1) {
        flock(file, LOCK_SH); // Adquiere un bloqueo compartido para lectura.
        while ((bytes_read = read(file, buffer, sizeof(buffer))) > 0) {
            write(STDOUT_FILENO, buffer, bytes_read);
        }
        flock(file, LOCK_UN); // Libera el bloqueo compartido.
        sleep(2); // Lee periódicamente cada 2 segundos.
    }
    close(file);
    return 0;
}
