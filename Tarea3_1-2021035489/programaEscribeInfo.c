#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[10];
    int age;
};

/*            Ejercicio 1.
      Escriba un programa que escriba a un archivo la información de 10 empleados. 
      Luego escriba otro programa que imprima los datos de los empleados que se
      encuentran almacenados en posiciones pares del archivo. 
      Debe usar la función fseek para buscar la información en el archivo (no se permite búsqueda secuencial).

*/

// Guardar empleado en archivo.
void guardarEmpleado(const char* fileName, struct Employee emp, const char* mode) {
    FILE* f = fopen(fileName, mode);
    if (f != NULL) {
        int result = fwrite(&emp, sizeof(struct Employee), 1, f);
        if (result == 0) {
            printf("Error al escribir en el archivo.\n");
            exit(1);
        } else {
            printf("Se guardó empleado en el archivo.\n");
        }
        fclose(f);
    } else {
        printf("Error al abir el archivo.\n");
        exit(1);
    }
}



int main() {
    const char nombreArchivo[] = "nombreArchivo.txt";
    struct Employee emp;     
    //Posiciones pares              0                  2                  4                  6                 8
    const char nombres[10][10] = {"Felipe", "Marco", "Pedro", "Karla", "Maria", "Esteban", "Earl", "Alonso", "Raquel", "Celina"};
    int primerEmpleado = 1;//Bandera para crear archivo de 0 o agregar al final del archivo.
    for (int i = 0; i < 10; i++) {
        //Guarda info de empleado en emp.
        emp.id = i;
        emp.age = 20;
        strcpy(emp.name, nombres[i]);
        if (primerEmpleado) {
            guardarEmpleado(nombreArchivo, emp, "w");
            primerEmpleado = 0;
        }else 
          guardarEmpleado(nombreArchivo, emp, "a");
    }
    return 0;
}
