
//NURIA MIR GARCÍA

/* EJERCICIO 1

Dada la tabla semanal de calorías adquiridas en las comidas, desarrolle un programa que encuentre la primera comida para cada día que supere
un umbral mínimo de calorías solicitado al usuario por teclado. Si se encuentra, se debe mostrar por pantalla tanto el día, el tipo de comida y la
cantidad de calorías de dicha comida. Si no se alcanzara el umbral de calorías para algún día, también se deberá mostrar.*/

#include <stdio.h>
#include <stdlib.h>

#define NDIAS 7 //Los días de las semana 
#define N 10 //Esta es la constante que me piden para la tabla de calorías gastadas, pero puedo reutilizar la constante

void main()
{
    // Tabla (matriz) semanal calorías adquiridas en las comidas
    float calAdq[NDIAS][N] =
    {
        {80.5, 250.0, 60.1, 120.4},
        {75.2, 320.5, 0.0, 100.6},
        {90.4, 280.6, 85.1, 90.5},
        {85.1, 350.2, 49.4, 0.0},
        {88.4, 420.5, 0.0, 110.0},
        {78.6, 370.9, 90.5, 96.6},
        {84.7, 275.3, 75.0, 105.0}
    };

    //Días de la semana
    char diaSem[][N] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};

    //Comidas diarias
    char comida[][N] = {"Desayuno", "Almuerzo", "Merienda", "Cena"};


    int i,j, exito;
    float umbralCal;

    printf("Seleccione un minimo de calorias consumidas: \n");
    scanf("%f", &umbralCal);

    exito = 0;
    i = 0;
    while (i < NDIAS && !exito) //Recorre los días de la semana
    {
        j = 0;
        while (j < N && !exito) //Recorre las comidas diarias
        {
            if (umbralCal <= calAdq[i][j]) //En este caso se sobrepasan las calorías diarias, salta el printf y se pasa de día
            {
                printf ("El %s para %s se ha ingerido %.2f calorias\n", diaSem[i], comida[j], calAdq[i][j]);
                exito = 1;
            }
            j++;
        }
        if (!exito) //En este caso no se sobrepasan las calorías para ninguna comida, se indica y se pasa de día
        {
            printf ("El %s no se alcanzo comida para dicho umbral\n", diaSem[i]);
        }
        exito = 0; //Exito se iguala a cero para volver a entrar en el bucle y estudiar los siguientes días aunque ya se haya alcanzado el exito para un dia
        i++;
    }
}
