
#include <stdio.h>
#include <stdlib.h>
#include "operacionesPereyra.h"

int main()
{
    int A;
    int B;
    char salir = 'n';
    int opcion;

    do{

        printf("\n *------Menu de opciones------* \n\n");
        printf("Ingresar 1er operando (A = x).\n");
        scanf("%d",&A);

        printf("Ingresar 2do operando (B = y).\n");
        scanf("%d",&B);

        printf("Los numeros ingresados son: (%d y %d)\n",A,B,"\n");
        printf("\n\n=============================\n\n");


        do{

            if(A==0 && B==0){

                printf("Error. No se puede realizar operaciones con 0");
                salir = 's';

            }else{

                printf("*------Seleccione la operacion a realizar------*.\n");
                printf("\n\n=============================\n\n");
                printf("1- Calcular Suma (%d + %d)\n",A,B,"\n");
                printf("2- Calcular Resta (%d - %d)\n",A,B,"\n");
                printf("3- Calcular Division (%d / %d)\n",A,B,"\n");
                printf("4- Calcular Multiplicacion (%d * %d)\n",A,B,"\n");
                printf("5- Calcular Factorial de (!%d) y (!%d)\n",A,B);
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
                        printf("\ne- El factorial de !%d es: %d y el factorial de !%d es: %d\n",A, factorial(A), B, factorial(B));
                        printf("\n\n=============================\n\n");
                        break;
                    case 6:
                        printf("\n*Desea salir? s / n ");
                        scanf(" %c",&salir);
                        printf("\nOpcion seleccionada: %c", salir);
                        printf("\n\n=============================\n\n");
                        //system("pause");
                        break;
                }
            //system("pause");
            }//fin del else

        }while(salir == 'n');

    }while(salir == 'n');

    return 0;

}

/*

int main()
{
    char salir = 'n';
    int i = 0;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    int num1;
    int num2;
    int opcion;

    do
    {

     if(flag1 == 0 && flag2 == 0)
   {
    printf("\n *------Menu de opciones------* \n\n");
    printf("1- Ingresar 1er operando (A = x).\n");
    printf("2- Ingresar 2do operando (B = y).\n");
    printf("3- Calcular todas las operaciones.\n");
    printf("4- Informar resultados.\n");
    printf("5- Salir.\n");
    printf("\n\n=============================\n\n");
    printf("\nIngrese opcion: ");

    scanf("%d",&opcion);
   }
    else if(flag1 == 1 && flag2 == 0)
   {
    printf("\n *------Menu de opciones------* \n\n");
    printf("1- Ingresar 1er operando (A = %d).\n",num1);
    printf("2- Ingresar 2do operando (B = y).\n");
    printf("3- Calcular todas las operaciones.\n");
    printf("4- Informar resultados.\n");
    printf("5- Salir.\n");
    printf("\n\n=============================\n\n");
    printf("\nIngrese opcion: ");

    scanf("%d",&opcion);
   }
   else if(flag1 == 0 && flag2 == 1)
   {
    printf("\n *------Menu de opciones------* \n\n");
    printf("1- Ingresar 1er operando (A = x).\n");
    printf("2- Ingresar 2do operando (B = %d).\n", num2);
    printf("3- Calcular todas las operaciones.\n");
    printf("4- Informar resultados.\n");
    printf("5- Salir.\n");
    printf("\n\n=============================\n\n");
    printf("\nIngrese opcion: ");

    scanf("%d",&opcion);
   }

   else
   {
    printf("\n *------Menu de opciones------* \n\n");
    printf("1- Ingresar 1er operando (A = %d).\n",num1);
    printf("2- Ingresar 2do operando (B = %d).\n",num2);
    printf("3- Calcular todas las operaciones.\n");
    printf("4- Informar resultados.\n");
    printf("5- Salir.\n");
    printf("\n\n=============================\n\n");
    printf("\nIngrese opcion: ");

    scanf("%d",&opcion);
   }

        switch(opcion)
        {
            case 1:
                printf("\n*Ingresar primer numero: ");
                scanf("%d",&num1);
                flag1 = 1;
                system("pause");
            break;
            case 2:
                printf("\n*Ingresar segundo numero: ");
                scanf("%d",&num2);
                flag2 = 1;
                system("pause");
            break;
            case 3:
                if(flag1 == 0 || flag2 == 0)
                {
                    printf("\nNo es posible calcular. No se ha ingresado uno o ambos numeros.\n");
                }
                else
                {
                    printf("\na- Calcular la suma de (%d + %d)\n",num1,num2);
                    printf("b- Calcular la resta de (%d - %d)\n",num1,num2);
                    printf("c- Calcular la division de (%d / %d)\n",num1,num2);
                    printf("d- Calcular la  multiplicacion de (%d * %d)\n",num1,num2);
                    printf("e- Calcular el factorial de (!%d) y (!%d)\n",num1,num2);
                    flag3 = 1;
                    system("pause");
                }
            break;
            case 4:
                    if(flag1 == 0 || flag2 == 0)
                {
                    printf("\nNo es posible mostrar los resultados. Falta ingresar uno o ambos numeros.\n");
                }
                    else if(flag3 == 0)
                {
                        printf("\nNo es posible mostrar los resultados. Falta realizar las operaciones (opcion 3).");
                }

                else
                {
                    printf("\na- El resultado de %d + %d es: %d\n",num1, num2, sumarDosNumeros(num1, num2));
                    printf("b- El resultado de %d - %d es: %d\n",num1, num2, restarDosNumeros(num1, num2));
                    printf("c- El resultado de %d / %d es: %f\n",num1, num2, dividirDosNumeros(num1, num2));
                    printf("d- El resultado de %d * %d es: %d\n",num1, num2, multiplicarDosNumeros(num1, num2));
                    printf("e- El factorial de !%d es: %d y el factorial de !%d es: %d\n",num1, factorial(num1), num2, factorial(num2));
                    system("pause");
                }

            break;
            case 5:
                    printf("\n*Desea salir? s / n: ");
                    scanf(" %c",&salir);
            break;

        }

        i++;

    } while ( salir == 'n');



    return 0;
}
*/
