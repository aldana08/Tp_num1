#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty; ///0=ocupado - 1=vacio
    int idEmpleado; ///identificador de empleado
}Empleado;
/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Empleado* pEmpleado,int len);
int employee_findFree(Empleado* pEmpleado, int len);
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */

int addEmployees(Empleado* pEmpleado,int len,int pIndex,char* msgE,int tries);
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */

int findEmployeeById(Empleado* pEmpleado, int len, int idE);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Empleado* pEmpleado, int len,char* msgE,int tries);
int emp_mod(Empleado* pEmpleado, int len,char* msgE,int tries);
int empleado_getID (Empleado* pEmpleado,int len,char* msgE,int tries);
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */

int printEmployees(Empleado* pEmpleado,int len);
int empleado_orderByID(Empleado* pEmpleado, int len);
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Empleado * pEmpleado, int len);
int printSalary(Empleado* pEmpleado , int len);
void limpiar (void);

#endif // ARRAYEMPLOYEES_H_INCLUDED
