#include<stdio.h>
#include"funciones.h"
#include <string.h>

void imprimirAlumnos(char alumnos[][2][20],double notas[][3]){
    printf("Nombre\t\tApellido\t\tNota 1\t\tNota 2\t\tNota 3\t\tPromedio\n");
    for (int i = 0; i < 6 ; i++) {
        double promedio = (notas[i][0] + notas[i][1] + notas[i][2])/3;

        printf("%s\t\t%s\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf", alumnos[i][0], alumnos[i][1], notas[i][0], notas[i][1], notas[i][2], promedio);
        if (promedio >=6 ) {
            printf("\tEstudiante Aprobado\n");
        } else {
            printf("\tEstudiante Reprobado\n");
        }
    }
}

void buscarAlumnoXApellido(char alumnos[][2][20], double notas[][3]){
    char buscaApellido[40];
    int noExiste=0;
    printf("Ingrese el apellido: ");
    scanf("%s", &buscaApellido);
    printf("Apellido\t\tNota 1\t\tNota 2\t\tNota 3\t\tPromedio\n");
    for (int i = 0; i < 6; i++) {
        if (strcmp(alumnos[i][1], buscaApellido)==0) {
            double promedio = (notas[i][0] + notas[i][1] + notas[i][2])/3;
            printf("%s\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf", alumnos[i][1], notas[i][0], notas[i][1], notas[i][2], promedio);
            if (promedio >=6 ) {
            printf("Estudiante Aprobado\n");
        } else {
            printf("Estudiante Reprobado\n");
        }
        noExiste=1;
        }
        if(noExiste==0) {
            printf("El alumno no existe\n");
        }
    } 
}

void editarCalificaciones(char alumnos[][2][20], double notas[][3]){
    char buscarApellido[40], buscarNombre[40];
    double NuevaNota1, NuevaNota2, NuevaNota3;
    int noExiste =0;
    imprimirAlumnos(alumnos, notas);
    printf("\nIngrese el apellido del alumno que desea editar: ");
    scanf("%s", &buscarApellido);
    printf("Nombre\t\tApellido\t\tNota 1\t\tNota 2\t\tNota 3\t\tPromedio\n");
   for (int i = 0; i < 6; i++) {
        if (strcmp(alumnos[i][1], buscarApellido)==0) {
            double promedio = (notas[i][0] + notas[i][1] + notas[i][2])/3;
            printf("%s\t\t%s\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf", alumnos[i][0], alumnos[i][1], notas[i][0], notas[i][1], notas[i][2], promedio);
            if (promedio >=6 ) {
            printf("Estudiante Aprobado\n");
        } else {
            printf("Estudiante Reprobado\n");
        }
        noExiste=1;
        }
        if(noExiste==0) {
            printf("El alumno no existe\n");
        }
    } 
    printf("\nConfirme el alumno por su nombre: ");
    scanf("%s", &buscarNombre);
    for (int j = 0; j < 6; j++){
        if (strcmp(alumnos[j][0], buscarNombre)==0) {
            printf("Ingrese la nueva nota 1: ");
            scanf("%lf", &NuevaNota1);
            printf("Ingrese la nueva nota 2: ");
            scanf("%lf", &NuevaNota2);
            printf("Ingrese la nueva nota 3: ");
            scanf("%lf", &NuevaNota3);
            notas[j][0]=NuevaNota1;
            notas[j][1]=NuevaNota2;
            notas[j][2]=NuevaNota3;
        }else {
        printf("Alumno no encontrado\n");
        }
    } 
     imprimirAlumnos(alumnos, notas);
}