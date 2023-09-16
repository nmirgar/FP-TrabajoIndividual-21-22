
//NURIA MIR GARCÍA

/* EJERCICIO 3

Utilizando la tabla semanal de calorías gastadas con los ejercicios y el vector de número de ejercicios semanales, desarrolle un programa que
recoja por teclado un número de calorías mínimo e imprima por pantalla el primer día de la semana donde se gasten, en total en dicho día, más
calorías que dicho mínimo. Imprimir asimismo las calorías gastadas en cada uno de los ejercicios de dicho día.*/

#include <stdio.h>
#include <stdlib.h>

#define NDIAS 7 //Los días de las semana
#define N 10 //Esta es la constante que me piden para la tabla de calorías gastadas, pero puedo reutilizar la constante

void main()
{
    // Tabla (matriz) semanal de calorías gastadas con ejercicios
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

    //Días de la semana
    char diaSem[][N] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};

    float umbralCal, suma;
    int i, j, exito, k, diaenc;

    printf("Seleccione un numero minimo de calorias: ");
    scanf("%f", &umbralCal);

    exito = 0;
    i = 0;
    diaenc = 0; //Lo inicializo para que no tenga basura
    while (i < NDIAS && !exito)//Recorre los días de la semana
    {
        j = 0;
        suma = 0;
        while (j < N && !exito)//Recorre los ejercicios diarios
        {
            suma = 0;
            for (k = 0; k < vecEjs[i] && !exito; k++)//Recorre el vector de los ejercicios semanales
            {
                suma += calGast[i][k];

                if(umbralCal <= suma)//En este caso se gastan más calorías del mínimo establecido
                {
                    exito = 1;
                    diaenc = i;//Este es el día de la semana que se va a imprimir
                }
            }
            j++;
        }
        i++;
    }
    //Caso en el que no se alcance la cantidad mínima de calorías para ningún día
    if (umbralCal > suma)
    {
        printf("Ningun dia se ha alcanzado esa cantidad de calorias");
    }

    //Imprimo la solución según el formato del enunciado
    if(exito)
    {
        int exito2;//Exito del while de impresión

        printf("%s: ( ", diaSem[diaenc]);

        exito2 = 0;
        j = 0;
        while(j < N && !exito2)
        {
            if (calGast[diaenc][j+1] == 0) //Última posición del vector, se imprime sin coma al final
            {
                printf("EJ%d: %.2f ", j, calGast[diaenc][j]);
                exito2 = 1;
            }
            else if (calGast[diaenc][j] != 0)//Resto de posiciones del vector
            {
                printf("EJ%d: %.2f,  ", j, calGast[diaenc][j]);
            }
            j++;
        }
        printf(")");
    }
}

