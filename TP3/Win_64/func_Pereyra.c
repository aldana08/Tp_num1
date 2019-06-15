#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "func_Pereyra.h"

int getIntInRange(  int *pNum,
                    char *msg,
                    char *msgE,
                    int minimo,
                    int maximo,
                    int reintentos)
{
    int retorno = -1;
    char bufferStr[20];
    int bufferInt;
    do
    {

        if((pNum != NULL)&&(!getStringNumeros(bufferStr,msg,msgE,reintentos)))
        {
            bufferInt = atoi(bufferStr);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                retorno = 0;
                *pNum = bufferInt;
            }
            else
            {
                printf("El numero esta fuera del rango!\n");
                reintentos--;
            }
        }
        else
        {
            printf("No es un numero valido!\n");
            reintentos--;
        }
    }
    while(retorno==-1 && reintentos>0);
    return retorno;
}
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 0 si el texto contiene solo números
 */
int getStringNumeros (char* pStr, char* msg, char* msgE,int reintentos)
{
    char bufferStr[20];
    int retorno=-1;
    while(retorno==-1 && reintentos>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pStr!=NULL)&&(isNumber(bufferStr)))
        {
            strncpy(pStr,bufferStr,sizeof(bufferStr));
            retorno=0;
        }
        else
        {
            printf(msgE);
            retorno=-1;
        }
    }
    return retorno;
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return int
 */
int getString(char* pStr, char* msg, char*msgE)
{
    char bufferStr[20];
    printf("%s",msg);
    fgets(bufferStr,sizeof(bufferStr),stdin);
    bufferStr[strlen(bufferStr)-1] = '\0';
    if(pStr!=NULL)
    {
        strncpy(pStr,bufferStr,sizeof(bufferStr));
    }
    return 0;
}

int isNumber (char* pStr)
{
    int i=0;
    while(pStr[i]!='\0')
    {
        if(pStr[i]<'0' || pStr[i]>'9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/** \brief Solicita un texto al usuario , valida que sea solo numeros,elimina saltos de linea
* \param var_dondeAsignar es donde se guarda el valor
* \param longitudMaxString es la cantidad maxima de caracteres que puede ingresar el usuario
* \param mensaje Es el mensaje a ser mostrado
* \return void
*/
void PedirStringSoloNumeros(char var_dondeAsignar[],int longitudMaxString,char mensaje[])
{

    int i;
    int invalido = 0;
    char auxiliar [longitudMaxString];

    fflush(stdin);
    printf("%s\n",mensaje);

    do
    {

        fflush(stdin);
        fgets(auxiliar,longitudMaxString,stdin);

        for (i=0; i<strlen(auxiliar)-1; i++)
        {
            if (auxiliar[i]<'0' || auxiliar[i]>'9')
            {
                invalido = 1;
                printf("\nError, ingrese solo numeros \n");
                break;
            }
            else
            {
                invalido = 0;
            }

        }

    }
    while (invalido);

    //elimino saltos de linea//
    int len = strlen(auxiliar);

    if(auxiliar[len-1]=='\n')
    {

        auxiliar[len-1]='\0';

    };
    strcpy(var_dondeAsignar,auxiliar);
    return;
}
/** \brief Solicita un texto al usuario , valida que sea solo letras y espacios, vuelve la primer letra Mayuscula y el resto minuscula despues de cada espacio
 * elimina saltos de linea
 * \param var_dondeAsignar es donde se guarda el valor
 * \param longitudMaxString es la cantidad maxima de caracteres que puede ingresar el usuario
 * \param mensaje Es el mensaje a ser mostrado
 * \return void
 */

void PedirNombre(char var_dondeAsignar[],int longitudMaxString, char mensaje[])
{
    int i;
    int no_es_un_nombre;
    char auxiliar[longitudMaxString];

    do
    {
        fflush(stdin);
        printf("%s\n",mensaje);

        fgets(auxiliar,longitudMaxString,stdin);

        for (i=0; i<strlen(auxiliar)-1; i++)
        {
            auxiliar[i] = tolower(auxiliar[i]);
            if ((auxiliar[i]<'a' || auxiliar[i]>'z') && auxiliar[i] != ' ')
            {
                no_es_un_nombre = -1;
                printf("\nError, ingrese solo letras y espacios\n");
                break;
            }
            else
            {
                if (i == 0 || auxiliar[i-1] == ' ')
                {
                    auxiliar[i] = toupper(auxiliar[i]);
                }
                no_es_un_nombre = 0;
            }
        }
    }
    while (no_es_un_nombre);

    int len = strlen(auxiliar);

    if(auxiliar[len-1]=='\n')
    {

        auxiliar[len-1]='\0';

    };

    strcpy(var_dondeAsignar, auxiliar);
    return;
}



