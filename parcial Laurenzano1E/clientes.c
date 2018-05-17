#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "clientes.h"
#include "utn.h"

#define DEFINE_DEL_ARCHIVO  "hola"

//Funciones privadas
static int proximoId(void);
static int buscarLugarLibre(Clientes* array,int limite);
//__________________



/** \brief
 * \param array Clientes*
 * \param limite int
 * \return int
 *
 */
int clientes_init(Clientes* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int clientes_mostrarDebug(Clientes* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %s - %f - %d - %d\n",array[i].idClientes, array[i].nombre,array[i].apellido,array[i].cuitb,array[i].tipo, array[i].isEmpty);
        }
    }
    return retorno;
}

int clientes_mostrar(Clientes* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
             if((array[i].cuitb)<1000)
            {

                printf("\nId:%d  Nombre: %s  apellido: %  cuitb: %.2f  Tipo: %d\n",array[i].idClientes, array[i].nombre, array[i].apellido,array[i].cuitb,array[i].tipo);
            }
        }

    }
    return retorno;
}

int clientes_alta(Clientes* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char apellido[50];
    float cuitb;
    int tipo;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                getString("\napellido? ",apellido);

                    if(!getValidFloat("\ncuitb? ","\nEso no es un cuitb",&cuitb,0,4000000,2))
                    {
                        if(!getValidInt("\nTipo? ","\nEso no es un cuitb",&tipo,0,1,2))
                        {
                            retorno = 0;
                            strcpy(array[i].nombre,nombre);
                            strcpy(array[i].apellido,apellido);
                            array[i].cuitb = cuitb;
                            array[i].tipo = tipo;
                            //------------------------------
                            //------------------------------
                            array[i].idClientes = proximoId();
                            array[i].isEmpty = 0;
                        }
                    }

            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


int clientes_baja(Clientes* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = Clientes_buscarPorId(array,limite,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}




int clientes_modificacion(Clientes* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char nombre[50];
    char apellido[50];
    float cuitb;
    int tipo;

    indiceAModificar = Clientes_buscarPorId(array,limite,id);
    if(indiceAModificar>=0)
    {
        if(!getValidString("\nNuevo Nombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                getString("\nNueva apellido? ",apellido);

                    if(!getValidFloat("\nNuevo cuitb? ","\nEso no es un cuitb",&cuitb,0,9999999,2))
                    {
                        if(!getValidInt("\nTipo? ","\nEso no es un cuitb",&tipo,0,1,2))
                        {
                            retorno = 0;
                            strcpy(array[indiceAModificar].nombre,nombre);
                            strcpy(array[indiceAModificar].apellido,apellido);
                            array[indiceAModificar].cuitb = cuitb;
                            array[indiceAModificar].tipo = tipo;
                            //------------------------------
                            //------------------------------

                        }
                    }

            }
        else
        {
            retorno = -3;
        }
    }
    return retorno;
}

int clientes_ordenar(Clientes* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Clientes auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

static int buscarLugarLibre(Clientes* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


int clientes_buscarPorId(Clientes* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idClientes==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



int clientes_altaForzada(Clientes* array,int limite,char* nombre,char* apellido, float cuitb, int tipo)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            strcpy(array[i].apellido,apellido);
            array[i].cuitb = cuitb;
            array[i].tipo = tipo;
            //------------------------------
            //------------------------------
            array[i].idClientes = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}








