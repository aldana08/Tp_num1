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

int menuOpciones ()
{
    int opcion;

    printf("\n *------Menu de opciones------* \n\n");
    printf("1- Ingresar 1er operando (A = x).\n");
    printf("2- Ingresar 2do operando (B = y).\n");
    printf("3- Calcular todas las operaciones.\n");
    printf("4- Informar resultados.\n");
    printf("5- Salir.\n");
    printf("\n\n=============================\n\n");
    printf("\nIngrese opcion: ");

    scanf("%d",&opcion);

    return opcion;
}
