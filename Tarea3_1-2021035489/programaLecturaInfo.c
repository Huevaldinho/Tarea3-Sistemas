#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[10];
    int age;
};
// Debe imprimir la info de empleados en posiciones pares.
void readData(const char* fileName) {
    FILE * f = fopen(fileName, "r");
    if (f != NULL) {
        fseek(f, 0, SEEK_END);
        long int tamannoArchivo = ftell(f);
        long int totalEmpleados = tamannoArchivo / sizeof(struct Employee);
        printf("Total de empleados en el archivo %ld\n", totalEmpleados);
        struct Employee empData; //Size of struct employee = 20
        for (int i = 0; i < totalEmpleados; i += 2) {
            //Posiciona el puntero del archivo en las posiciones par.
            //Posiciona en i * 20 bytes desde el inicio del archivo.
            //Queda algo asi: 0, 40, 80, 120, 160, 200, 240, 280, 320, 360
            fseek(f, i * sizeof(struct Employee), SEEK_SET);
            fread(&empData, sizeof(struct Employee), 1, f);
            printf("Empleado, id: %d, Age: %d, Nombre: %s\n", empData.id, empData.age, empData.name);
        }
        fclose(f);
    } else {
        printf("Error opening the file to read data\n");
        exit(1);
    }
}

int main() {
    const char nombreArchivo[] = "nombreArchivo.txt";
    readData(nombreArchivo);//Lee e imprime la info de los empleados pares.
    return 0;
}