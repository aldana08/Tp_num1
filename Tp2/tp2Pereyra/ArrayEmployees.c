
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_strings.h"
static int generarId(void);

int initEmployees(Empleado* pEmpleado,int len)
{
    int i;
    if(pEmpleado!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            pEmpleado[i].idEmpleado=-1;
            pEmpleado[i].isEmpty=1;
        }
    }
    return 0;
}

int employee_findFree(Empleado* pEmpleado, int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pEmpleado[i].isEmpty==1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int addEmployees(Empleado* pEmpleado,int len,int pIndex,char* msgE,int tries)
{
    char bufferName[51];
    char bufferLastName[51];
    char bufferSector[20];
    char bufferSalary[20];
    float auxSalary;
    int auxSector;
    int retorno=-1;
    if((pEmpleado!=NULL)&&(len>0)&&(pIndex!=-1))
    {
        if(((getStringLetras(bufferName,"\nIngrese Apellido: ",msgE,tries)==0)&&
            (getStringLetras(bufferLastName,"\nIngrese Nombre: ",msgE,tries)==0)))
        {
            if((getStringNumerosFloat(bufferSalary,"\nIngrese su Salario: ",msgE,tries)==0)
                &&(getStringNumeros(bufferSector,"\nIngrese Sector N*: (1-2-3-4) ",msgE,tries)==0))
            {
                auxSalary=atof(bufferSalary);
                auxSector=atoi(bufferSector);
                strncpy(pEmpleado[pIndex].name,bufferName,sizeof(bufferName));
                strncpy(pEmpleado[pIndex].lastName,bufferLastName,sizeof(bufferLastName));
                pEmpleado[pIndex].salary=auxSalary;
                pEmpleado[pIndex].sector=auxSector;
                pEmpleado[pIndex].idEmpleado=generarId();
                pEmpleado[pIndex].isEmpty=0;
                retorno=0;
            }
        }
    }
    return retorno;
}

int removeEmployee(Empleado* pEmpleado, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int retorno=-1;
    if(pEmpleado!=NULL && len>0)
    {
        auxID=empleado_getID(pEmpleado,len,msgE,tries);
         if(auxID>=0)
        {
            posOfID=findEmployeeById(pEmpleado,len,auxID);
            if(posOfID!=-1)
            {
               pEmpleado[posOfID].isEmpty=1;
               retorno=0;
            }
        }
     }
    return retorno;
}

int findEmployeeById(Empleado* pEmpleado, int len, int idE)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pEmpleado[i].idEmpleado==idE)
        {
            ret=i;
            break;
        }
    }
    return ret;
}


int emp_mod(Empleado* pEmpleado, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int opcion=0;
    char bufferName[51];
    char bufferLastName[51];
    char bufferSector[20];
    char bufferSalary[20];
    float auxSalary;
    int auxSector;
    int retorno=-1;

    if((pEmpleado!=NULL)&&(len>0))
    {
        auxID=empleado_getID(pEmpleado,len,msgE,tries);
        if(auxID>=0)
        {
            posOfID=findEmployeeById(pEmpleado,len,auxID);
            if(posOfID!=-1)
            {
                while(opcion!=5)
                {
                    printf("\n1- Modificar Apellido\n");
                    printf("2- Modificar Nombre\n");
                    printf("3- Modificar su Salario\n");
                    printf("4- Modificar su Sector\n");
                    printf("5- Volver al Menu principal\n");
                    getIntInRange(&opcion,"\n   INGRESE OPCION (Menu Modificacion): ",msgE,1,1000,tries);
                    switch(opcion)
                    {
                        case 1:
                        {
                            if(!getStringLetras(bufferName,"\nIngrese NUEVO Apellido: ",msgE,tries))
                            {
                                strncpy(pEmpleado[posOfID].name,bufferName,sizeof(bufferName));
                                retorno=0;
                            }
                            break;
                        }
                        case 2:
                        {
                            if(!getStringLetras(bufferLastName,"\nIngrese NUEVO Nombre: ",msgE,tries))
                            {
                                strncpy(pEmpleado[posOfID].lastName,bufferLastName,sizeof(bufferLastName));
                                retorno=0;
                            }
                            break;
                        }
                        case 3:
                        {
                            if(!getStringNumeros(bufferSalary,"\nIngrese NUEVO Salario: ",msgE,tries))
                            {
                                auxSalary=atof(bufferSalary);
                                pEmpleado[posOfID].salary=auxSalary;
                                retorno=0;
                            }
                            break;
                        }
                        case 4:
                        {
                            if(!getStringNumeros(bufferSector,"\nIngrese NUEVO Sector: ",msgE,tries))
                            {
                                auxSector=atoi(bufferSector);
                                pEmpleado[posOfID].sector=auxSector;
                                retorno=0;
                            }
                            break;
                        }
                    }
                }
            }
            else
            {
                printf("\n----No se encontro el ID!-----\n");
            }
        }
    }
    return retorno;
}

int sortEmployees(Empleado* pEmpleado, int len)
{

    Empleado aux;

    int i,j;
    for(i=0; i<len-1; i++)
    {
    for(j=i+1; j<len; j++)
    {
    if(pEmpleado[i].sector>pEmpleado[j].sector)
        {
        aux = pEmpleado[j];
        pEmpleado[j] = pEmpleado[i];
        pEmpleado[i] = aux;
    }
    if (pEmpleado[i].sector == pEmpleado[j].sector)
        {

    if( strcmp(pEmpleado[i].lastName , pEmpleado[j].lastName)>0 )
        {
            aux = pEmpleado[j];
    pEmpleado[j] = pEmpleado[i];
    pEmpleado[i] = aux;
    }
    }
}
}
    return 0;
}

int empleado_getID(Empleado* pEmpleado,int len,char* msgE,int tries)
{
    int retorno=-1;
    char bufferID[20];
    int auxID;
    if(pEmpleado!=NULL && len>0)
    {
        if(!getStringNumeros(bufferID,"\nIngrese ID: ",msgE,tries))
        {
            auxID=atoi(bufferID);
            retorno=auxID;
        }
    }
    return retorno;
}

int empleado_orderByID(Empleado* pEmpleado, int len)
{
    int i;
    int j;
    Empleado buffer;
    for(i=0;i<len-1;i++)
    {
        if(pEmpleado[i].isEmpty==1)
        {
            continue;
        }
        for(j=i+1;j<len;j++)
        {
            if(pEmpleado[j].isEmpty==1)
            {
                continue;
            }
            if(pEmpleado[i].idEmpleado>pEmpleado[j].idEmpleado)
            {
                buffer=pEmpleado[i];
                pEmpleado[i]=pEmpleado[j];
                pEmpleado[j]=buffer;
            }
        }
    }
    return 0;
}

int printEmployees(Empleado* pEmpleado,int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(pEmpleado[i].isEmpty!=1)
        {
            printf("\nID: %d\nApellido: %s\nNombre: %s\nSalario: %.2f\nSector: %d\n-------",
                   pEmpleado[i].idEmpleado,pEmpleado[i].lastName,pEmpleado[i].name,pEmpleado[i].salary,pEmpleado[i].sector);
            flag=0;
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    return 0;
}

int printSalary(Empleado* pEmpleado ,int len)
{
    float TotalSalaries , averageSalary = 0;
    int overAverage = 0 , activeEmployees = 0 , i;

    for (i=0;i<len;i++){
        if (pEmpleado[i].isEmpty == 0){
            activeEmployees ++;
            TotalSalaries = TotalSalaries + pEmpleado[i].salary;
        }
    }

    averageSalary = (TotalSalaries / activeEmployees)  ;

    for(i=0;i<len;i++){

        if (pEmpleado[i].salary > averageSalary && pEmpleado[i].isEmpty == 0){
            overAverage++;
        }
    }
    printf("\nSuma de todos los salarios: %.2f \nSalario promedio: %.2f \nCantidad de empleados por encima del promedio:%d\n",TotalSalaries,averageSalary,overAverage);
     return 0;
    }

static int generarId(void)
{
    static int idEmpleado=0;
    return idEmpleado++;
}



