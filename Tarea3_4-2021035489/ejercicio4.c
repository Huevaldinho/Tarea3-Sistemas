#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

/*
    Ejercicio 4.
    Escriba un programa que muestre en forma de árbol los diferentes archivos 
    y directorios de un directorio particular. Debe indicar a la par de cada archivo
    su tamaño y fecha de creación.
*/
void printTree(const char *dirname, int depth) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    dir = opendir(dirname);
    if (!dir) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char path[1024];
            snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);
            if (stat(path, &file_stat) == 0) {
                printf("%*s", depth * 4, ""); // Indentation
                printf("%s (Tamaño: %ld bytes, Fecha: %s)", entry->d_name, file_stat.st_size, ctime(&file_stat.st_ctime));
            }else{
                printf("%*s%s (Tamaño: N/A, Fecha: N/A)\n", depth * 4, "", entry->d_name);
            }
            if (entry->d_type == DT_DIR) {
                printTree(path, depth + 1);
            }
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <directorio>\n", argv[0]);
        return 1;
    }
    //$ ./programa directorio

    const char *dirname = argv[1];
    printTree(dirname, 0);

    return 0;
}
