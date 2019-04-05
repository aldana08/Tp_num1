
#include <stdio.h>
#include <stdlib.h>
#include "operacionesPereyra.h"

int main()
{
    int A;
    int B;
    char salir = 'n';
    int opcion;

    do
        {

        printf("\n *------Menu de opciones------* \n\n");
        printf("Ingresar 1er operando (A = x).\n");
        scanf("%d",&A);

        printf("Ingresar 2do operando (B = y).\n");
        scanf("%d",&B);

        printf("Los numeros ingresados son: (%d y %d)\n",A,B,"\n");
        printf("\n\n=============================\n\n");


        do
            {

                if(A==0 && B==0){

                    printf("Error. No se puede realizar operaciones con 0");
                    salir = 's';

            }else

            {

                printf("*------Seleccione la operacion a realizar------*.\n");
                printf("\n\n=============================\n\n");
                printf("1- Calcular Suma (%d + %d)\n",A,B,"\n");
                printf("2- Calcular Resta (%d - %d)\n",A,B,"\n");
                printf("3- Calcular Division (%d / %d)\n",A,B,"\n");
                printf("4- Calcular Multiplicacion (%d * %d)\n",A,B,"\n");
                printf("5- Calcular Factorial de (%d) y (%d)\n",A,B);
                printf("6- Salir\n");
                printf("\n\n=============================\n\n");
                printf("\nIngrese opcion: ");

                scanf("%d",&opcion);

                switch(opcion)
                {
                    case 1:
                        printf("\na- El resultado de %d + %d es: %d\n",A, B, sumarDosNumeros(A, B));
                        printf("\n\n=============================\n\n");
                        break;
                    case 2:
                        printf("\nb- El resultado de %d - %d es: %d\n",A, B, restarDosNumeros(A, B));
                        printf("\n\n=============================\n\n");
                        break;
                    case 3:
                        printf("\nc- El resultado de %d / %d es: %.2f\n",A, B, dividirDosNumeros(A, B));
                        printf("\n\n=============================\n\n");
                        break;
                    case 4:
                        printf("\nd- El resultado de %d * %d es: %d\n",A, B, multiplicarDosNumeros(A, B));
                        printf("\n\n=============================\n\n");
                        break;
                    case 5:
                        printf("\ne- El factorial de %d es: %d y el factorial de %d es: %d\n",A, factorial(A), B, factorial(B));
                        printf("\n\n=============================\n\n");
                        break;
                    case 6:
                        printf("\n*Desea salir? s / n ");
                        scanf(" %c",&salir);
                        printf("\nOpcion seleccionada: %c", salir);
                        printf("\n\n=============================\n\n");
                        break;

                    default:

                        printf("\n\nError. No ingreso una opcion valida. Seleccionar una opcion entre 1 y 6\n\n");
                    }//fin del switch

                }//fin del else



        }while(salir == 'n');

        if(A==0 && B==0)
        {
            salir = 'n';
        }

    }while(salir == 'n');

    return 0;

}


