
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_strings.h"
#define REINTENTOS 2
#define LIS_EMPLEADOS 1000


int main()
{
    int flag=0;
    int posLibre;
    Empleado listaEmp[LIS_EMPLEADOS];
    int opcion=0;

    initEmployees(listaEmp,1000);

     flag=1;

    while(opcion!=5)
    {
        printf("\n\n*** Menu Empleados ***");
        printf("\n\n----------------------------\n\n");
        getIntInRange(&opcion,"\n1)Alta de Empleados\n2)Modificar empleados\n3)Baja de empleados\n4)Informar\n\n    INGRESE OPCION: ","ERROR\n",1,1000,2);
        switch(opcion)
        {
            case 1:
            {
                posLibre=employee_findFree(listaEmp,LIS_EMPLEADOS);
                if(posLibre>=0)
                {
                    printf("\n----Se encontro lugar para dar de alta----\n");
                    if(!addEmployees(listaEmp,LIS_EMPLEADOS,posLibre,"DATO INCORRECTO\n",REINTENTOS))
                    {
                        flag=1;
                        printf("\n----Se dio de ALTA exitosamente!----\n");
                    }
                    else
                    {
                        printf("\n----No se realizo el ALTA!----\n");
                    }
                }
                else
                {
                    printf("\n----No se encontro lugar libre!----\n");
                }
                break;
            }
            case 2:
                {
                if(flag)
                {
                    if(emp_mod(listaEmp,LIS_EMPLEADOS,"DATO NO VALIDO\n",REINTENTOS))//alter
                    {
                        printf("\n----Se modifico exitosamente----\n");
                    }
                }
                else
                {
                    printf("\n----No hay ALTAS en la NOMINA!----\n");
                }
                break;
            }
            case 3:
            {
                if(flag)
                {
                    if(removeEmployee(listaEmp,LIS_EMPLEADOS,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        printf("\n----La BAJA se realizo con exito!----\n");
                    }
                }
                else
                {
                    printf("\n----No hay ALTAS en la NOMINA!----\n");
                }
                break;
            }
            case 4:
            {
                if(flag)
                {
                    sortEmployees(listaEmp,LIS_EMPLEADOS);
                    printEmployees(listaEmp,LIS_EMPLEADOS);
                    printSalary(listaEmp , LIS_EMPLEADOS);
                }
                break;
            }

}
    }
    return 0;
}
