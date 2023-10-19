
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 


/* 
                            EJERCICIO 1
    Escriba un programa que escriba a un archivo la información de 10 empleados. 
    Luego escriba otro programa que imprima los datos de los empleados que se 
    encuentran almacenados en posiciones pares del archivo. 
    Debe usar la función fseek para buscar la información en el archivo (no se permite búsqueda secuencial).
*/
struct Empleado{
    int ID;
    const char * nombre;
};
//Guardar empleado en archivo.
void guardarInformacionEmpleado(struct Empleado empleado){

}
//Debe imprimir la info de empleados en posiciones pares
void imprimirEmpleados(){

}

int main(){
    const char nombreArchivo[] =  "nombreArchivo.txt";
    struct Empleado empleados[10];

    const char nombres[10][10] = {"Felipe","Marco","Pedro","Karla","Maria","Esteban","Earl","Alonso","Raquel","Celina"}; 
    for (int i = 0; i < 10 ; i++){
        empleados[i].ID=i;
        empleados[i].nombre=nombres[i];
        printf("Nombre %s - Pos:%i\n",empleados[i].nombre,empleados[i].ID);
    }

    //El asunto es saber cuales son las pos pares del archivo.
    //Sacar size del archivo, revisar size de struct Empleado.
    //Size archivo / size struct = cantidad de empleados
    //Revisar pares

    return 0;
}