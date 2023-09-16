
//NURIA MIR GARCÍA

/* EJERCICIO 2

Solicitar al usuario un número mínimo de ejercicios realizados por día y un número mínimo de calorías ingeridas por comida. Usando el vector
de número de ejercicios semanales y la tabla semanal de calorías adquiridas en las comidas, encontrar el primer día en el que se hayan realizado
al menos el mínimo de ejercicios indicados por el usuario. Por ejemplo, si el mínimo fuese 3, con los datos de prueba del enunciado general, el
primer día que se hacen al menos 3 ejercicios es el miércoles.

El programa a realizar debe imprimir también un mensaje para cada día hasta encontrar el día buscado, expresando que no se alcanzó el número
mínimo de ejercicios indicado por el usuario, así como si hubo en cada día alguna comida cuyas calorías superase el mínimo de calorías. En
este caso, imprimir el tipo de comida (desayuno, almuerzo, etc.) y las calorías de dicha comida.*/

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

    //Vector número de ejercicios semanales
    int vecEjs[NDIAS] = {2, 1, 3, 0, 1, 3, 2};

    //Días de la semana
    char diaSem[][N] = {"Lunes","Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};

    //Comidas diarias
    char comida[][N] = {"Desayuno","Almuerzo","Merienda", "Cena"};


    int i, j, exito, exito2, ejercicios;
    float umbralCal;

    printf("Indique el numero minimo de ejercicios: ");
    scanf("%d", &ejercicios);

    printf("Indique el umbral minimo de calorias: ");
    scanf("%f", &umbralCal);


    i = 0;
    exito = 0;
    while (i < NDIAS && !exito) //Recorre los días de la semana
    {
        if (ejercicios <= vecEjs[i]) //Verifica si se alcanza el número mínimo de ejercicios
        {
            printf("\nEl %s se realizaron %d ejercicios", diaSem[i], vecEjs[i]);
            exito = 1; //Como se alcanza el número mínimo de ejercicios, se sale y no continua la búsqueda
        }
        else //En el caso de que no se alcance el número mínimo ejercicios entramos en otro bucle
        {
            printf ("\nEl %s no se realizo el numero minimo de ejercicios y ", diaSem[i]);

            j = 0;
            exito2 = 0;//Exito del segundo while
            while (j < N && !exito2) //Recorre las comidas diarias y comprueba si se alcanza el umbral de calorías
            {
                if (umbralCal <= calAdq[i][j]) //En este caso se alcanza el umbral de calorías mínimas
                {
                    printf("para %s se ingirieron %.2f calorias\n", comida[j], calAdq[i][j]);//Imprime cuántas calorías se consumen
                    exito2 = 1;
                }
                else //En este caso no se alcanza el umbral de calorías mínimas
                {
                    j++; //Pasa a la siguiente comida
                }
            }
            if (!exito2) //Si recorre todas las comidas del día y en ninguna se alcanza el umbral, no se alcanza para ninguna comida de ese día
                {
                    printf("no se alcanzo el umbral de la ingesta minima para ninguna comida\n");
                }
        }
        i++; //Pasa de día
    }
}
