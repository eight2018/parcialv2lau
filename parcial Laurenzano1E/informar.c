#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Publicaciones.h"
#include "utn.h"
#include "Clientes.h"


int informar_ConsultaFacturacion(Clientes* arrayC,int limite,
              Clientes* clientes, int lenclientes, char* cuit)
{
    int retorno = -1;
    int i;
    int indexPantalla;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
            if(!arrayC[i].isEmpty && !strcmp(arrayC[i].cuit,cuit))
            {
                indexPantalla = pantalla_buscarPorId(clientes,lenclientes,arrayC[i].idPantalla);
                printf("\n\nCuit: %s - Unitario: %.2f - Total: %.2f - rubro: %d\n",
                                    arrayC[i].cuit,
                                    clientes[indexPantalla].cuitb,
                                    (arrayC[i].rubro * clientes[indexPantalla].cuitb),
                                    arrayC[i].rubro );
            }
        }

        retorno = 0;
    }
    return retorno;
}



int informar_ListarContrataciones(Clientes* arrayC,int limite,Pantalla* clientes, int lenclientes)
{
    int retorno = -1;
    int i;
    int indexPantalla;
    int acumrubro=0;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
                if(!arrayC[i].isEmpty)
                {
                    indexPantalla = pantalla_buscarPorId(clientes,lenclientes,arrayC[i].idPantalla);
                    printf("\n%d,Cuit: %s - Nombre: %s - Video: %s - rubro: %d\n",arrayC[i].id,
                    arrayC[i].cuit,clientes[indexPantalla].nombre,arrayC[i].archivo,arrayC[i].rubro );

                    //acumrubro=acumrubro+arrayC[i].rubro;
                    //printf("%d",acumrubro);


                }


        }

        retorno = 0;
    }
    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Clientes* arrayC,int limite,
              Pantalla* clientes, int lenclientes)
{
    int retorno = -1;
    int i;
    //int indexPantalla;
    char ultimoCuit[50];

    cont_ordenarCuit(arrayC,limite,0);
    strcpy(ultimoCuit,"");
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
                if(!arrayC[i].isEmpty)
                {
                    if(strcmp(ultimoCuit,arrayC[i].cuit) != 0)
                    {
                        printf("\nCuit: %s", arrayC[i].cuit);
                        strcpy(ultimoCuit,arrayC[i].cuit);
                    }


                    //indexPantalla = pantalla_buscarPorId(clientes,lenclientes,arrayC[i].idPantalla);
                    /*printf("\nCuit: %s - Nombre: %s - Video: %s - rubro: %d\n",
                                        arrayC[i].cuit,
                                        clientes[indexPantalla].nombre,
                                        arrayC[i].archivo,
                                        arrayC[i].rubro );*/

                }


        }

        retorno = 0;
    }
    return retorno;
}
