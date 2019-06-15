#ifndef FUNC_PEREYRA_H_INCLUDED
#define FUNC_PEREYRA_H_INCLUDED

int getIntInRange (int *pNum,char *msg,char *msgE,int minimo,int maximo,int reintentos);
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 0 si el texto contiene solo números
 */
int getStringNumeros (char* pStr, char* msg, char* msgE,int reintentos);
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return int
 */
int getString(char* pStr, char* msg, char*msgE);
int isNumber (char* pStr);
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 0 si el texto contiene solo letras
 */
int getStringLetras (char* pStr, char* msg, char* msgE,int reintentos);

/** \brief Solicita un texto al usuario , valida que sea solo numeros,elimina saltos de linea
* \param var_dondeAsignar es donde se guarda el valor
* \param longitudMaxString es la cantidad maxima de caracteres que puede ingresar el usuario
* \param mensaje Es el mensaje a ser mostrado
* \return void
*/
void PedirStringSoloNumeros(char var_dondeAsignar[],int longitudMaxString,char mensaje[]);

/** \brief Solicita un texto al usuario , valida que sea solo letras y espacios, vuelve la primer letra Mayuscula y el resto minuscula despues de cada espacio
 * elimina saltos de linea
 * \param var_dondeAsignar es donde se guarda el valor
 * \param longitudMaxString es la cantidad maxima de caracteres que puede ingresar el usuario
 * \param mensaje Es el mensaje a ser mostrado
 * \return void
 */
void PedirNombre(char var_dondeAsignar[],int longitudMaxString, char mensaje[]);



#endif // FUNC_PEREYRA_H_INCLUDED
