#include <stdio.h>
#include <stdlib.h>
#include "operacionesPereyra.h"


int sumarDosNumeros (int A, int B)
{
    int sumar;

    sumar = A + B;

    return sumar;
}

int restarDosNumeros (int A, int B)
{
    int resta;

    resta = A - B;

    return resta;
}

int multiplicarDosNumeros (int A, int B)
{
    int producto;

    producto = A * B;

    return producto;
}

float dividirDosNumeros (int A, int B)
{
    float resto;

    if( B == 0 )
    {
        printf("Error. No se puede dividir por 0.");
    }
    else
    {
        resto =(float) A / B;
    }

    return resto;
}

int factorial (int A)
{
    if ( A == 0 )
    {
        A = 1;
    }
    else
    {
        A = A * factorial(A-1);
    }

    return A;
}

