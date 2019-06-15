#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "func_Pereyra.h"

/** \brief Crea posicion de memoria para un nuevo empleado.
 *
 * \return Employee* posición de memoria de employee.
 */
Employee* employee_new()
{
    Employee* e_empNew = (Employee*)malloc(sizeof(Employee));
    return e_empNew;
}
/** \brief Devuelve el resultado de una comparación entre 2 nombres de empleado.
 *
 * \param emplA void* Primer empleado.
 * \param emplB void* Segundo empleado
 * \return retorno int. (0) si los nombres son iguales, (1) si el primero es mayor y (-1) si el segundo es mayor.
 */
int empleado_orden(void* emplA, void* empB)
{
    int devuelve =-1;
    char auxEmpA[200];
    char auxEmpB[200];
    if(emplA!=NULL && empB!=NULL)
    {
        employee_getNombre((Employee*)emplA,auxEmpA);
        employee_getNombre((Employee*)empB,auxEmpB);
        devuelve = strcmp(auxEmpA,auxEmpB);
    }
    return devuelve;
}
/** \brief Obtiene el nombre de un empleado.
 *
 * \param this Employee* Empleado a tomar.
 * \param resultado char* name
 * \return retorno int. (0) si salio todo correctamente. (-1) Si se pasaron parametros nulos.
 */
int employee_getNombre(Employee* e_Empl, char* name)
{
    int devuelve = 0;

    if(e_Empl != NULL && name != NULL)
    {
        strcpy(name, e_Empl->nombre);
        devuelve = 1;
    }
    return devuelve;
}
/** \brief Define el nombre de un empleado.
 *
 * \param this Employee* Empleado a tomar.
 * \param nombre char* name
 * \return retorno int. (0) si salio todo correctamente. (-1) Si se pasaron parametros nulos o no es valido.
 */
int employee_setNombre(Employee* e_Empl, char* name)
{
    int devuelve = 0;

    if(e_Empl != NULL && name != NULL)
    {
        strncpy(e_Empl->nombre, name, sizeof(e_Empl->nombre));
        devuelve = 1;
    }
    return devuelve;
}
/** \brief Obtiene el ID de un empleado.
 *
 * \param this Employee* Empleado a tomar.
 * \param resultado int* ID donde se encuentra.
 * \return retorno int. (0) si salio todo correctamente. (-1) Si se pasaron parametros nulos o no se encontró.
 */
int employee_getId(Employee* e_Empl, int* id)
{

    int devuelve = 0;
    if(e_Empl != NULL)
    {
        *id = e_Empl->id ;
        devuelve = 1;
    }
    return devuelve;
}
/** \brief Define el ID de un empleado.
 *
 * \param this Employee* Empleado a tomar.
 * \param int id
 * \return retorno int. (0) si salio todo correctamente. (-1) Si se pasaron parametros nulos o no se encontró.
 */
int employee_setId(Employee* e_Empl, int id)
{
    int devuelve = 0;

    if(e_Empl != NULL && id > 0)
    {
        e_Empl->id = id;
        devuelve = 1;
    }
    return devuelve;
}
/** \brief Obtiene el sueldo de un empleado.
 *
 * \param this Employee* Empleado a tomar.
 * \param resultado int* sueldo
 * \return retorno int. (0) si salio todo correctamente. (-1) Si se pasaron parametros nulos.
 */
int employee_getSueldo(Employee* e_Empl, int* sueldo)
{
    int devuelve = 0;

    if(e_Empl != NULL)
    {
        *sueldo = e_Empl->sueldo ;
        devuelve = 1;
    }
    return devuelve;
}
/** \brief Define el sueldo de un empleado.
 *
 * \param this Employee* Empleado a tomar.
 * \param sueldo int sueldo
 * \return retorno int. (0) si salio todo correctamente. (-1) Si se pasaron parametros nulos o no son validos.
 */
int employee_setSueldo(Employee* e_Empl, int sueldo)
{
    int devuelve = 0;

    if(e_Empl != NULL)
    {
        e_Empl->sueldo = sueldo;
        devuelve = 1;
    }
    return devuelve;
}
/** \brief Obtiene las horas trabajadas de un empleado.
 *
 * \param this Employee* Empleado a tomar.
 * \param resultado int* horasTrabajadas
 * \return retorno int. (0) si salio todo correctamente. (-1) Si se pasaron parametros nulos o no son validos.
 */
int employee_getHorasTrabajadas(Employee* e_Empl, int* horasTrabajadas)
{
    int devuelve = 0;

    if(e_Empl != NULL)
    {
        *horasTrabajadas = e_Empl->horasTrabajadas;
        devuelve = 1;
    }
    return devuelve;
}
/** \brief Define las horas trabajadas de un empleado.
 *
 * \param this Employee* Empleado a tomar.
 * \param horasTrabajadas int horasTrabajadas
 * \return retorno int. (0) si salio todo correctamente. (-1) Si se pasaron parametros nulos o no son validos.
 */
int employee_setHorasTrabajadas(Employee* e_Empl, int horasTrabajadas)
{
    int devuelve = 0;

    if(e_Empl != NULL)
    {
        e_Empl->horasTrabajadas = horasTrabajadas;
        devuelve = 1;
    }
    return devuelve;
}






