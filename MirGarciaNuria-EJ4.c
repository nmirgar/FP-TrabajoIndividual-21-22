
//NURIA MIR GARCÍA

/* EJERCICIO 4

Escriba una función que reciba la tabla semanal de calorías adquiridas en las comidas, el vector de número de ejercicios semanales y un número
entero que indique un día de la semana entre 1 (lunes) y 7 (domingo) y devuelva un valor booleano que indique si en dicho día de la semana ha
habido alguna falta de comida (cero calorías) y, además, en dicho día no se haya hecho ningún ejercicio.*/

#include <stdio.h>
#include <stdlib.h>

#define NDIAS 7 //Los días de las semana
#define N 10 //Esta es la constante que me piden para la tabla de calorías gastadas, pero puedo reutilizar la constante


int controlEjsCals (float calAdq[][N], int vecEjs[NDIAS], int dia);

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

    int dia, res;

    printf("Seleccione un dia de la semana: ");
    scanf("%d", &dia);

    res = controlEjsCals (calAdq, vecEjs, dia);
    printf("%d", res);
}

int controlEjsCals (float calAdq[][N], int vecEjs[NDIAS], int dia)
{
    int faltacomida, faltaejercicio;
    int j, exito, res;

    /*El valor booleano solo será 1 cuando se de el caso de que:
    1) Dicho día se haya saltado alguna comida
    2) Dicho día no se haya hecho ningún ejercicio*/

    faltacomida = 0;
    faltaejercicio = 0;
    if (dia >= 1 && dia <= 7)
    {
        //Búsqueda condición 1: Falta alguna comida diaria
        j = 0;
        exito = 0;
        while(j < NDIAS && !exito)
        {
            if(calAdq[dia-1][j] == 0)
            {
                faltacomida = 1;
            }
            j++;
        }

        //Búsqueda condición 2: Falta algún día por hacer ejercicio
        if(vecEjs[dia-1] == 0)
        {
            faltaejercicio = 1;
        }

        //Return cuando se cumplen ambas condiciones
        if (faltaejercicio && faltacomida)
        {
            res = 1;
        }
        else
        {
            res = 0;
        }
    }
    else
    {
        res = -1;//La función falla (devuelve -1) cuando se introduce algún valor no válido
    }

    return res;
}
