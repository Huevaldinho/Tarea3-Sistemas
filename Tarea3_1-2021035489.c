
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
  void writeData(const char * fileName, struct Employee emp) {
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
  void readData(const char *fileName, struct Employee * empData) {
    FILE *f = fopen(fileName, "r");
    fseek(f,0,SEEK_END);
    printf("Size file:%ld\n",ftell(f));
    fseek(f,0,SEEK_SET);
    long int pos = 0;
    if (f != NULL) {
      for (int i=0;i<10;i++){
        printf("Pos %ld \n",pos);
        fseek(f,pos,SEEK_SET);
        fread(empData, sizeof(struct Employee), 1, f);
        pos += sizeof(empData);
        printf("Data from file, Id: %d, Age: %d, Name: %s\n", empData->id,empData->age, empData->name);
      }
      fclose(f);
    } else {
      printf("Error opening the file to read data\n");
      exit(1);
    }
  }

  int main(){
      const char nombreArchivo[] =  "nombreArchivo.txt";
      struct Employee empleados[10];
      struct Employee emp;
      struct Employee empResult;
      const char nombres[10][10] = {"Felipe","Marco","Pedro","Karla","Maria","Esteban","Earl","Alonso","Raquel","Celina"}; 
      for (int i = 0; i < 10 ; i++){
          emp.id=i;
          emp.age=20;
          strcpy(emp.name, nombres[i]);
          empleados[i] = emp;
          printf("Se deberia guardar %s %i %i \n",emp.name,emp.id,emp.age);
          writeData(nombreArchivo,emp);
      }
      
      readData(nombreArchivo, &empResult);
      
      //!REVISAR SI SE GUARDAN TODOS LOS NOMBRES.
      //El asunto es saber cuales son las pos pares del archivo.
      //Sacar size del archivo, revisar size de struct Empleado.
      //Size archivo / size struct = cantidad de empleados
      //Revisar pares

      return 0;
  }