
//NURIA MIR GARCÍA

/* EJERCICIO 5
Escribir una función que reciba la tabla semanal de calorías gastadas con ejercicios y el vector de número de ejercicios semanales y devuelva
un vector que contenga el promedio de calorías gastadas para cada día de la semana.*/

#include <stdio.h>
#include <stdlib.h>

#define NDIAS 7 //Los días de las semana
#define N 10 //Esta es la constante que me piden para la tabla de calorías gastadas, pero puedo reutilizar la constante


void mediaCalsGast (float calGast[][N], int vecEjs[NDIAS], float vecMedEjs[NDIAS]);

void main()
{
    //Tabla (matriz) semanal de calorías gastadas con ejercicios
    float calGast[NDIAS][N] =
    {
        {250.5, 125.4, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {180.6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {300.0, 150.3, 75.4, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {450.7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {120.1, 230.5, 400.8, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {300.0, 230.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    };

    //Vector número de ejercicios semanales
    int vecEjs[NDIAS] = {2, 1, 3, 0, 1, 3, 2};

    int i;
    float vecMedEjs[NDIAS];

    mediaCalsGast(calGast, vecEjs, vecMedEjs);//Llamada a la función, devuelve el vector

    printf("La media de calorias quemadas es: {");

    for(i = 0; i < NDIAS-1; i++)//Impresión del vector
    {
        printf("%.2f, ", vecMedEjs[i]);
    }
    printf("%.2f}", vecMedEjs[i] );//Cuando llegue al último elemento, se imprime sin la coma

}

void mediaCalsGast (float calGast[][N], int vecEjs[NDIAS], float vecMedEjs[NDIAS])
{
    int i, j;
    float suma;

    for(i = 0; i < NDIAS; i++)//Recorre los días de la semana
    {
        if (vecEjs[i] == 0)
        {
            vecMedEjs[i] = 0; //Si dicho día no se han realizado ejercicios, directamente las calorías gastadas son cero
        }
        else
        {
            suma = 0;
            for(j = 0; j < vecEjs[i]; j++)
            {
                suma += calGast[i][j];//Suma de las calorías gastadas al día
            }
            vecMedEjs[i] = suma / vecEjs[i];//Media de las calorías gastadas en dicho día
        }
    }
}


