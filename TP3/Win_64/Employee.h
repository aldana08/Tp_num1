#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Crea posicion de memoria para un nuevo empleado.
 *
 * \return Employee* posición de memoria de employee.
 */
Employee* employee_new();
/** \brief Crea un nuevo empleado con posicion de memoria y contenido basado en strings.
 *
 * \param char* ID
 * \param char* nombre
 * \param char* horasTrabajadas
 * \param char* sueldo
 * \return retorno Employee*. Devuelve el empleado si todo salio bien, o NULL si se pasaron mal parametros o no se pudo completar la operacion.
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
/** \brief Elimina un empleado.
 *
 * \param this Employee* Empleado a eliminar.
 * \return -.
 */
void employee_delete();
/** \brief Devuelve el resultado de una comparación entre 2 nombres de empleado.
 *
 * \param emplA void* Primer empleado.
 * \param emplB void* Segundo empleado
 * \return retorno int. (0) si los nombres son iguales, (1) si el primero es mayor y (-1) si el segundo es mayor.
 */
int empleado_orden(void* emplA, void* emplB);
/** \brief Define el ID de un empleado.
 *
 * \param this Employee* Empleado a tomar.
 * \param id int id
 * \return retorno int. (0) si salio todo correctamente. (-1) Si se pasaron parametros nulos o no se encontró.
 */
int employee_setId(Employee* this,int id);
/** \brief Obtiene el ID de un empleado.
 *
 * \param this Employee* Empleado a tomar.
 * \param resultado int* ID donde se encuentra.
 * \return retorno int. (0) si salio todo correctamente. (-1) Si se pasaron parametros nulos o no se encontró.
 */
int employee_getId(Employee* this,int* id);
/** \brief Define el nombre de un empleado.
 *
 * \param this Employee* Empleado a tomar.
 * \param nombre char* nombre
 * \return retorno int. (0) si salio todo correctamente. (-1) Si se pasaron parametros nulos o no es valido.
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief Obtiene el nombre de un empleado.
 *
 * \param this Employee* Empleado a tomar.
 * \param resultado char* nombre
 * \return retorno int. (0) si salio todo correctamente. (-1) Si se pasaron parametros nulos.
 */
int employee_getNombre(Employee* this,char* nombre);
/** \brief Define las horas trabajadas de un empleado.
 *
 * \param this Employee* Empleado a tomar.
 * \param horasTrabajadas int horasTrabajadas
 * \return retorno int. (0) si salio todo correctamente. (-1) Si se pasaron parametros nulos o no son validos.
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief Obtiene las horas trabajadas de un empleado.
 *
 * \param this Employee* Empleado a tomar.
 * \param resultado int* horasTrabajadas
 * \return retorno int. (0) si salio todo correctamente. (-1) Si se pasaron parametros nulos o no son validos.
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/** \brief Define el sueldo de un empleado.
 *
 * \param this Employee* Empleado a tomar.
 * \param sueldo int sueldo
 * \return retorno int. (0) si salio todo correctamente. (-1) Si se pasaron parametros nulos o no son validos.
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief Obtiene el sueldo de un empleado.
 *
 * \param this Employee* Empleado a tomar.
 * \param resultado int* sueldo
 * \return retorno int. (0) si salio todo correctamente. (-1) Si se pasaron parametros nulos.
 */
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED
