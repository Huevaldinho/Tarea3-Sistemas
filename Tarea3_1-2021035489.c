
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 


/* 
                            EJERCICIO 1
    Escriba un programa que escriba a un archivo la información de 10 empleados. 
    Luego escriba otro programa que imprima los datos de los empleados que se 
    encuentran almacenados en posiciones pares del archivo. 
    Debe usar la función fseek para buscar la información en el archivo (no se permite búsqueda secuencial).
*/

struct Employee{
  int id;
  char  name[10];
  int age;
};
//Guardar empleado en archivo.
void writeData(char * fileName, struct Employee emp) {
  FILE * f = fopen(fileName, "w");
  if (f != NULL) {
    //fseek(f,pos,SEEK_SET);
    int result = fwrite(&emp, sizeof(struct Employee), 1, f);
    if (result == 0) {
      printf("Error writing to the given file\n");
      exit(1);
    } else {
      printf("Structure is written to the file successfully!\n");
    }
    fclose(f);
  } else {
    printf("Error opening the file to write data\n");
    exit(1);
  }
}
//Debe imprimir la info de empleados en posiciones pares
void imprimirEmpleados(){

}

void crearArchivo(const char * nombreArchivo){

}

int main(){
    const char nombreArchivo[] =  "nombreArchivo.txt";
    struct Employee empleados[10];
    struct Employee emp;
    const char nombres[10][10] = {"Felipe","Marco","Pedro","Karla","Maria","Esteban","Earl","Alonso","Raquel","Celina"}; 
    for (int i = 0; i < 10 ; i++){
        emp.id=i;
        emp.age=20;
        strcpy(emp.name, nombres[i]);
        empleados[i] = emp;
        printf("Nombre %s - Pos:%i - Age:%i\n",empleados[i].name,empleados[i].id,empleados[i].age);
        writeData(nombreArchivo,emp);
    }
    //!REVISAR SI SE GUARDAN TODOS LOS NOMBRES.

    //El asunto es saber cuales son las pos pares del archivo.
    //Sacar size del archivo, revisar size de struct Empleado.
    //Size archivo / size struct = cantidad de empleados
    //Revisar pares

    return 0;
}