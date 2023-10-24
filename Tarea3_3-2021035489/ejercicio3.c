
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

/*
    Ejercicio 3.
    Escriba un programa que reciba el nombre de un archivo y lo
    busque recursivamente a través de una serie de directorios. 
    Se deberá indicar toda la ruta en donde se encontró el archivo.
*/

int searchFile(const char * filename, const char * dirname) {
    DIR * dir;
    struct dirent * entry;
    int found = 0;
    dir = opendir(dirname);
    if (!dir) {
        perror("opendir");
        return 1;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, filename) == 0){
            printf("Ruta del archivo buscado: %s/%s\n", dirname, filename);
            found = 1;
        }else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char path[1024];
            snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);
            if (searchFile(filename, path)) {
                found = 1;
            }
        }
    }

    closedir(dir);
    return found;
}

int main(int argc, char *argv[]) {
     /*
    gcc -o programa ejercicio3.c
    $ ./programa fileToBeFound.txt root_dir
    */
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <nombre_archivo> <directorio>\n", argv[0]);
        return 1;
    }

    const char * filename = argv[1];
    const char * dirname = argv[2];

    if (searchFile(filename, dirname)) {
        return 0; // El archivo se encontró.
    } else {
        printf("Archivo no encontrado en el directorio especificado.\n");
        return 1; // El archivo no se encontró.
    }
}
