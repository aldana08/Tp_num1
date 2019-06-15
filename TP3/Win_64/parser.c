#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "func_Pereyra.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char id[60];
    char nombre[60];
    char horasTrabajadas[60];
    char salario[60];

    int devuelve = 0;
    int ok = 0;


    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        devuelve = 1;

        do
        {
            Employee* nuevo = employee_new();
            if(nuevo != NULL)
            {
                ok = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,salario);

                if(ok == 4)
                {

                    employee_setId(nuevo, atoi(id) );
                    employee_setNombre(nuevo,nombre);
                    employee_setHorasTrabajadas(nuevo,atoi(horasTrabajadas) );
                    employee_setSueldo(nuevo,atoi(salario) );

                    ll_add(pArrayListEmployee,nuevo);
                }
                else
                {
                    devuelve = 0;
                    break;
                }
            }
            else
            {
                devuelve = 0;
                break;
            }

        }
        while(!feof(pFile));

        fclose(pFile);
    }
    else
    {
        devuelve = 0;
    }
    return devuelve;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int devuelve = 1;
    int ok;

    if(pFile == NULL || pArrayListEmployee == NULL)
    {
        devuelve=0;
    }
    else
    {
        do
        {
            Employee* nuevo = employee_new();
            ok = fread(nuevo,sizeof(Employee),1,pFile);
            if(ok == 1)
            {
                ll_add(pArrayListEmployee,nuevo);
            }
        } while(!feof(pFile));
    }
    return devuelve;
}
