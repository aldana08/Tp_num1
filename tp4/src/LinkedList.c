#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int devuelve = -1;
    if(this!=NULL)
    {
        devuelve = this->size;
    }
    return devuelve;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    int i=0;
    Node* pNodeAuxiliar = NULL;
    int size = ll_len(this);

    if(	!(this != NULL &&
        nodeIndex>=0 &&
		nodeIndex<size))
    return NULL;

    pNodeAuxiliar=this->pFirstNode;
    if(pNodeAuxiliar != NULL)
    {
        for(i=0;i<=nodeIndex;i++)
        {
            if(i==nodeIndex)
            {
                return pNodeAuxiliar;
            }
            else if(pNodeAuxiliar->pNextNode != NULL)
            {
                pNodeAuxiliar=pNodeAuxiliar->pNextNode;
            }
        }
    }

    return pNodeAuxiliar;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int devuelve = -1;
    Node* pNodoAnt;
    Node* pNodoNuevo;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        pNodoNuevo = (Node*) malloc(sizeof(Node));
        if(pNodoNuevo != NULL)
        {
            pNodoNuevo->pElement = pElement;
            if(nodeIndex == 0)
            {
                if(this->pFirstNode == NULL) pNodoNuevo->pNextNode = NULL;
                if(this->pFirstNode != NULL)  pNodoNuevo->pNextNode = this->pFirstNode;
                this->pFirstNode = pNodoNuevo;
            }
            else
            {
                pNodoAnt = getNode(this,nodeIndex-1);
                pNodoNuevo->pNextNode = pNodoAnt->pNextNode;
                pNodoAnt->pNextNode = pNodoNuevo;
            }
            this->size++;
            devuelve = 0;
        }
    }
    return devuelve;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int devuelve = -1;
    int size=ll_len(this);

    if(this == NULL)
    {
        return devuelve;
    }
    else
    {
        addNode(this, size, pElement);
        devuelve=0;
    }
    return devuelve;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* devuelve = NULL;
     Node* pNodeAuxiliar;

     if(this!=NULL && index>=0 && index<this->size)
     {
         pNodeAuxiliar=getNode(this,index);
         devuelve=pNodeAuxiliar->pElement;
     }

    return devuelve;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int devuelve = -1;
    Node* pNodeAuxiliar;

    if(this != NULL && index>=0 && index<this->size)
    {
        pNodeAuxiliar=getNode(this,index);
        pNodeAuxiliar->pElement=pElement;
        devuelve=0;
    }

    return devuelve;
}



/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int devuelve = -1;
    Node* pNodeAnt= NULL;
    Node* pNodeProx = NULL;
    Node* pRemoveNode = NULL;

    if(this != NULL  && index >= 0 && index < ll_len(this))
    {
        pRemoveNode = getNode(this,index);

        if(pRemoveNode != NULL) // hay nodo

        {
            if(index == 0)
            {
                this->pFirstNode = pRemoveNode->pNextNode;
                free(pRemoveNode);
                devuelve = 0;
            }
            else
            {
                pNodeAnt= getNode(this, (index - 1));
                pNodeProx = getNode(this,(index + 1));

                pNodeAnt->pNextNode = pNodeProx;
                free(pRemoveNode);
                devuelve = 0;
            }

            this->size = (ll_len(this)-1);
        }
    }

    return devuelve;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int i;
    int devuelve = -1;


    if(this != NULL)
    {
        Node* pNodeAnt = this->pFirstNode;

        if(pNodeAnt != NULL)
        {

            for(i=0 ; i<ll_len(this) ; i++)
            {
                ll_remove(this,i);
            }

            devuelve = 0;

        }
    }
    return devuelve;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int devuelve = -1;

    if(this != NULL)
    {
        ll_clear(this);
        free (this);
        devuelve = 0;
    }

    return devuelve;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int devuelve = -1;
    Node* pNodeAuxiliar;
    int i = 0; //index


    if (this != NULL )
    {
        pNodeAuxiliar = this->pFirstNode;

        for (i=0 ; i<ll_len(this) ; i++)
        {
            if (pNodeAuxiliar->pElement == pElement)
            {
                devuelve = i;
                break;
            }

            pNodeAuxiliar = getNode(this,i);

        }

    }

    return devuelve;
}
/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int devuelve = -1;

    if(this != NULL)
    {
        if(ll_len(this))
        {
            devuelve = 0;
        }
        else
        {
            devuelve = 1;
        }
    }

    return devuelve;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int devuelve = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        addNode(this,index,pElement);
        devuelve = 0;
    }

    return devuelve;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* devuelve = NULL;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        devuelve = ll_get(this,index);
        ll_remove(this,index);
    }

    return devuelve;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int i;
    int devuelve = -1;


    Node* pNodeAuxiliar = NULL;

    if(this != NULL)
    {
        devuelve = 0;
        for (i=0 ; i<ll_len(this) ; i++)
        {
            pNodeAuxiliar = getNode(this,i);

            if(pNodeAuxiliar->pElement == pElement)
            {
                devuelve = 1;
                break;
            }
        }
    }

    return devuelve;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int i;
    Node* pNodeAuxiliar;
    int devuelve = -1;


    if(this != NULL && this2 != NULL)
    {
        devuelve = 1;

        for (i=0 ; i<ll_len(this) ; i++)
        {
            pNodeAuxiliar= getNode(this2,i);

            if(ll_contains(this,pNodeAuxiliar->pElement) == 0)
            {
                devuelve = 0;
                break;
            }
        }
    }

    return devuelve;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    int i;
    LinkedList* cloneArray = NULL;
    Node* pNodeAuxiliar = NULL;

    if (this != NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();

        for (i = from ; i <= to ; i++)
        {
            pNodeAuxiliar = ll_get(this,i);
            ll_add(cloneArray,pNodeAuxiliar);
        }
    }
    else
    {
        cloneArray = NULL;
    }

    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    int i;
    Node* pNodeAuxiliar = NULL;
    LinkedList* cloneArray = NULL;

    if (this != NULL)
    {
        cloneArray = ll_newLinkedList();

        for (i = 0 ; i <= ll_len(this) ; i++)
        {
            pNodeAuxiliar = ll_get(this,i);
            ll_add(cloneArray,pNodeAuxiliar);
        }
    }

    return cloneArray;

}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int i = 0;
    int j= 0;
    void* pAuxiliar;
    int devuelve =-1;

    if( this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
        for(i=0; i< (ll_len(this)-1) ; i++)
        {
            for(j= i+1; j < ll_len(this); j++)
            {
                if(order == 1 && pFunc(ll_get(this,i), ll_get(this,j)) > 0)
                {
                    pAuxiliar = ll_get(this,i);
                    ll_set(this, i, ll_get(this, j));
                    ll_set(this, j, pAuxiliar);
                }
                else if(order == 0 && pFunc(ll_get(this,i), ll_get(this,j)) < 0)
                {
                    pAuxiliar = ll_get(this,i);
                    ll_set(this, i, ll_get(this, j));
                    ll_set(this, j, pAuxiliar);
                }
            }
        }

        devuelve = 0;
    }
    return devuelve;
}

//*******************************************************************************************

//crea una sublista
//segun criterio que retorne dicha funcion

LinkedList* ll_filter(LinkedList* this,int (*pFunc)(void*))
{
    int i;
    void* pElement;
    LinkedList* nuevaLista = NULL;


    if(this != NULL && pFunc != NULL)
    {
        nuevaLista = ll_newLinkedList();

        for(i=0; i < ll_len(this)-1 ; i++)
        {
            pElement = ll_get(this,i);

            if(pFunc(pElement) == 1)
            {
                ll_add(nuevaLista,pElement);
            }
        }
    }
    return nuevaLista;
}

//funcion map

int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int i=0;
    void* pElement;
    Node* pNodeAuxiliar;
    int devuelve = 0;

    if(this != NULL && pFunc != NULL)
    {
        do
        {
            pNodeAuxiliar = getNode(this,i);

            pElement = pNodeAuxiliar->pElement;

            if(pFunc(pElement) == 1)
            {
                devuelve = 1;
            }

            i++;

        }
        while(pNodeAuxiliar->pNextNode != NULL);
    }

    return devuelve;
}

