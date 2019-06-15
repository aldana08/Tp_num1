#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "func_Pereyra.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
                    fflush(stdin);
        printf("\n************MENU DATOS************\n");
        getIntInRange(&option,"\n1)Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
                      "2)Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
                      "3)Alta de empleado\n"
                      "4)Modificar datos de empleado\n"
                      "5)Baja de empleado\n"
                      "6)Listar empleados\n"
                      "7)Ordenar empleados\n"
                      "8)Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
                      "9)Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
                      "10)Salir\n\n INGRESAR OPCION: ","ERROR\n",1,11,2);

        switch(option)
        {
            case 1:
            if(listaEmpleados!=NULL)
            {
                if(controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("\nSe cargaron los datos!!\n");
                }
                else
                {
                    printf("\nError al cargar los datos!!\n");
                }
            }
            else
            {
                printf("\nError en la lista!!!\n");
            }
                break;
            case 2:
            if(listaEmpleados!=NULL)
            {
                if(controller_loadFromBinary("data.csv",listaEmpleados))
                {
                    printf("\nSe cargaron los datos!!\n");
                }
                else
                {
                    printf("\nError al cargar los datos!!\n");
                }
            }
            else
            {
                printf("\nError en la lista!!!\n");
            }
                break;
            break;
        case 3:
            if(listaEmpleados!=NULL)
            {
                if(controller_addEmployee(listaEmpleados))
                {
                    printf("\nSe cargo el empleado!!\n");
                }
                else
                {
                    printf("\nError al cargar empleado!!\n");
                }
            }
            else
            {
                printf("\nError en la lista!!!\n");
            }
            break;
        case 4:
            if(listaEmpleados!=NULL)
            {
                if(controller_editEmployee(listaEmpleados))
                {
                    printf("\nModificacion Exitosa!!\n");
                }
                else
                {
                    printf("\nError al modificar empleado!!\n");
                }
            }
            else
            {
                printf("\nError en la lista!!!\n");
            }
            break;
        case 5:
            if(listaEmpleados!=NULL)
            {
            if(controller_removeEmployee(listaEmpleados))
                {
                    printf("\nBAJA EXITOSA!!\n");
                }
                else
                {
                    printf("\nERROR EN LA BAJA!!\n");
                }
            }
            else
            {
                printf("\nError en la lista!!!\n");
            }

            break;
        case 6:
            if(listaEmpleados!=NULL)
            {
            if(controller_ListEmployee(listaEmpleados))
                {
                    printf("\nLISTADO EXITOSO!!\n");
                }
                else
                {
                    printf("\nERROR AL LISTAR!!\n");
                }
            }
            else
            {
                printf("\nError en la lista!!!\n");
            }
            break;
        case 7:
            if(listaEmpleados!=NULL)
            {
                if(controller_sortEmployee(listaEmpleados))
                {
                    printf("\nModificacion Exitosa!!\n");
                }
                else
                {
                    printf("\nError al modificar empleado!!\n");
                }
            }
            else
            {
                printf("\nError en la lista!!!\n");
            }
            break;
        case 8:
            if(listaEmpleados!=NULL)
            {
                if(controller_saveAsText("data.csv",listaEmpleados))
                {
                    printf("\nSe guardo exitosamente!!\n");
                }
                else
                {
                    printf("\nError al guardar archivo!!\n");
                }
            }
            else
            {
                printf("\nError en la lista!!!\n");
            }
            break;
        case 9:
            if(listaEmpleados!=NULL)
            {
                if(controller_saveAsBinary("data.csv",listaEmpleados))
                {
                    printf("\nSe guardo exitosamente!!\n");
                }
                else
                {
                    printf("\nError al guardar archivo!!\n");
                }
            }
            else
            {
                printf("\nError en la lista!!!\n");
            }
            break;
        case 10:
            ll_deleteLinkedList(listaEmpleados);
            break;
        }

    }while(option != 10);
    return 0;
}

