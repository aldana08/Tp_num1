#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "func_Pereyra.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path, "r");
    int devuelve = 0;

    if (pFile != NULL && path != NULL && pArrayListEmployee != NULL)
    {
        devuelve = parser_EmployeeFromText(pFile, pArrayListEmployee);
    }
    else
    {
        printf("EROR AL CARGAR ARCHIVO.\n");
    }

    fclose(pFile);

    return devuelve;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path, "rb");
    int devuelve = 0;

    if (pFile != NULL && path != NULL && pArrayListEmployee != NULL)
    {
        devuelve = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }
    else
    {
        printf("EROR AL CARGAR ARCHIVO.\n");
    }

    fclose(pFile);

    return devuelve;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* e_EmpNew = employee_new();
    char* aux = (char*) malloc(sizeof(char)*128);
    int auxId;
    char* auxHs = (char*) malloc(sizeof(char)*128);
    char* auxSueldo = (char*) malloc(sizeof(char)*128);

    int devuelve = 0;

    if(pArrayListEmployee == NULL || e_EmpNew == NULL)
    {
        devuelve=0;
    }
    else
    {
        PedirNombre(aux,128,"Ingrese nombre del empleado\n");
        PedirStringSoloNumeros(auxHs,128,"\nIngrese horas trabajadas\n");
        PedirStringSoloNumeros(auxSueldo,128,"\nIngrese sueldo del empleado\n");
        auxId = ll_len(pArrayListEmployee);
        employee_setId(e_EmpNew, auxId + 1 );
        employee_setNombre(e_EmpNew,aux);
        employee_setHorasTrabajadas(e_EmpNew,atoi(auxHs) );
        employee_setSueldo(e_EmpNew,atoi(auxSueldo) );
        if(ll_add(pArrayListEmployee,e_EmpNew)==0)
        {
            devuelve = 1;
        }
    }
    free(aux);
    free(auxSueldo);
    free(auxHs);
    return devuelve;
}



/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

    int devuelve = 0;
    int index = -2;
    int id;
    int i;
    char auxId[5];
    char* datoAux = (char*)malloc(sizeof(char)*128);
    int opc;

    Employee* e_EmpNew;

    if(pArrayListEmployee != NULL)
    {
       PedirStringSoloNumeros(auxId,5,"\nIngrese el id a modificar\n");
       id = atoi(auxId);
       for(i=0;i<ll_len(pArrayListEmployee);i++)
       {
           e_EmpNew = ll_get(pArrayListEmployee,i);
           if(e_EmpNew->id == id)
           {
               index = i;
               break;
           }
       }
       if(index != -2)
       {
           e_EmpNew = ll_get(pArrayListEmployee,index);
                    printf("\n1- Modificar Nombre\n");
                    printf("2- Modificar Sueldo\n");
                    printf("3- Modificar Horas trabajadas\n");
                    printf("4-Volver \n");
                    getIntInRange(&opc,"Opcion:","ERROR\n",1,5,2);
            switch(opc)
                    {
                        case 1:
                            PedirNombre(datoAux,128,"Ingrese nombre del empleado a modificar\n");
                            employee_setNombre(e_EmpNew,datoAux);
                            devuelve = 1;
                            break;
                        case 2:
                            PedirStringSoloNumeros(datoAux,128,"\nIngrese sueldo a modificar\n");
                            employee_setSueldo(e_EmpNew,atoi(datoAux));
                            devuelve = 1;
                            break;
                        case 3:
                            PedirStringSoloNumeros(datoAux,128,"\nIngrese horas a modificar\n");
                            employee_setHorasTrabajadas(e_EmpNew,atoi(datoAux));
                            devuelve = 1;
                            break;
                        case 4:
                            devuelve = 0;
                            break;
                        default:
                            printf("Opcion invalida.");
                            break;
                    }
       }
    }
    free(datoAux);
    return devuelve;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

    int devuelve = 0;
    int index = -2;
    int id;
    int i;
    char auxId[5];

    Employee* e_EmpNew;

    if(pArrayListEmployee != NULL)
    {
       PedirStringSoloNumeros(auxId,5,"\nIngrese el id a dar de baja\n");
       id = atoi(auxId);
       for(i=0;i<ll_len(pArrayListEmployee);i++)
       {
           e_EmpNew = ll_get(pArrayListEmployee,i);
           if(e_EmpNew->id == id)
           {
               index = i;
               break;
           }
       }
       if(index != -2)
       {
           ll_remove(pArrayListEmployee,index);
           devuelve = 1;
       }
    }
    return devuelve;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    {
    int devuelve =0 ;
    int i;
    Employee *emp;
    emp = employee_new();

    if(pArrayListEmployee != NULL && emp != NULL)
    {
        if(ll_len(pArrayListEmployee) != 0)
        {
            printf("Id------Nombre-----Horas----Salaro\n");
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                emp = ll_get(pArrayListEmployee,i);
                if(emp != NULL&&emp->id != -1)
                {
                printf("%5d %20s %4d %8d\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
                }
            }
        devuelve =1;
        }
        else
        {
        printf("No hay ningun empleado cargado en la lista\n");
        }
    }
    else
    {
        devuelve = 0;
    }

    return devuelve;
}
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int devuelve = 0;
    printf("\nORDENANDO...\n");
    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee,(*empleado_orden),0);
        devuelve = 1;
    }
    printf("\n----ORDENADO EXITOSAMENTE----\n");
    return devuelve;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{

    int i=0;
    FILE* pFile;
    Employee* emp;
    int devuelve = 1;

    pFile = fopen(path,"w");
    if(pArrayListEmployee == NULL ||  path == NULL || pFile == NULL)
    {
        devuelve = 0;
    }
    else
    {
        emp = employee_new();

         while (i < ll_len(pArrayListEmployee))
        {
         emp = (Employee*) ll_get(pArrayListEmployee,i);
         fprintf(pFile,"%d,%s,%d,%d\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
         i++;
        }
    }
    fclose(pFile);

    return devuelve;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int i=0;
    FILE* pFile;
    Employee* emp;
    int devuelve = 1;

     pFile = fopen(path,"wb");
    if(pArrayListEmployee == NULL || path == NULL || pFile == NULL)
    {
        devuelve = 0;
    }
    else
    {
        while (i < ll_len(pArrayListEmployee))
        {
            emp = (Employee*) ll_get(pArrayListEmployee,i);
            fwrite(emp,sizeof(Employee),1,pFile);
            i++;
        }

        fclose(pFile);
    }
    return devuelve;

}

