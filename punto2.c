#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarea{
int tareaID;//Numérico autoincremental comenzando en 1000
char *descripcion; //
int duracion; // entre 10 – 100
} Tarea;
typedef struct Nodo{
Tarea T;
Nodo *siguiente;
} Nodo;

Nodo *CrearListaVacia();
Nodo * CrearNodo(Tarea T);
void InsertarNodo(Nodo ** Start , Nodo *Nodo);
void InsertarNodoAlFinal(Nodo ** Start,Nodo *Nodo);
Nodo * BuscarNodo(Nodo ** Start,Tarea T);
Nodo * QuitarNodo(Nodo ** Start,Tarea T);
Nodo * QuitarNodoConAnterior(Nodo **Start, Tarea T);
Nodo * EliminarNodo(Nodo * nodo);

int main (){

    return 0;
}


Nodo * EliminarNodo(Nodo * nodo)
{
  free(nodo);
}

Nodo * QuitarNodo(Nodo **Start,Tarea T) {
    Nodo ** aux = Start;  // Usamos un puntero doble para apuntar al puntero actual.
    
    // Iteramos sobre la lista hasta encontrar el dato o alcanzar el final de la lista.
    while (*aux != NULL && (*aux)->T.tareaID != T.tareaID) {
        aux = &(*aux)->siguiente;
    }

    // Si encontramos el nodo con el dato especificado, lo quitamos de la lista y retornamos al programa para su posterior eliminación.
    if (*aux) {
        Nodo *temp = *aux;  // Guardamos el nodo a eliminar en una variable temporal.
        *aux = (*aux)->siguiente;  // Desvinculamos el nodo de la lista.
        temp->siguiente =NULL; // Ponemos en NULL el puntero siguiente para asegura no llevar vinculos por fuera de la lista
        return temp;
    }
    return NULL;
}

// quitar nodo con seguimiento de de un nodo anterior
Nodo * QuitarNodoConAnterior(Nodo **Start, Tarea T)
{
    Nodo *nodoAux = (*Start);
    Nodo *nodoAnt = NULL;
    while (nodoAux != NULL && nodoAux->T.tareaID != T.tareaID)
    {
        nodoAnt = nodoAux;
        nodoAux = nodoAux->siguiente;
    }

    if (nodoAux != NULL)
    {
        if (nodoAux == (*Start))
        {
            (*Start) = nodoAux->siguiente;
        }
        else
        {
            nodoAnt->siguiente = nodoAux->siguiente;
        }
        nodoAux->siguiente = NULL;
    }
    return (nodoAux);
}


Nodo * BuscarNodo(Nodo ** Start,Tarea T)
{
  Nodo * Aux = *Start;
  while (Aux && Aux-> T.tareaID != T.tareaID)
  {
    Aux = Aux->siguiente;
  }
  return Aux;
}


Nodo * CrearListaVacia()
{
    return NULL;
}

Nodo * CrearNodo(Tarea T)
{
  Nodo * nodo = (Nodo *) malloc(sizeof(Nodo));
  nodo->T = T;
  nodo->siguiente = NULL;
  return nodo;
}

void InsertarNodo(Nodo ** Start, Nodo *Nodo)
{
    Nodo->siguiente = *Start;
    *Start  = Nodo ;
}


void InsertarNodoAlFinal(Nodo ** Start,Nodo * nodo)
{
  Nodo * Aux = *Start;

  while (Aux->siguiente)
  {
    Aux = Aux->siguiente;
  }
   Aux->siguiente = nodo;
}

