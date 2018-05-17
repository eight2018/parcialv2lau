#ifndef PUBLICACIONES_C_INCLUDED
#define PUBLICACIONES_C_INCLUDED



#endif // PUBLICACIONES_C_INCLUDED
static int proximoId(void);
static int buscarPorId(Contratacion* array,int limite, int id);
static int buscarLugarLibre(Contratacion* array,int limite);
//__________________



/** \brief
 * \param array Pantalla*
 * \param limite int
 * \return int
 *
 */
int cont_init(Contratacion* array,int limite)
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

int cont_mostrarDebug(Contratacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            //printf("[DEBUG] - %d - %s - %s - %d - %d\n",array[i].id, array[i].cuit,array[i].archivo,array[i].rubro, array[i].isEmpty);
        }
    }
    return retorno;
}

int cont_mostrar(Contratacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - %d - %s - %s - %d - %d\n",array[i].id, array[i].cuit,array[i].archivo,array[i].rubro, array[i].isEmpty);
        }
    }
    return retorno;
}

int cont_alta(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    int idPant;
    int posPant;
    int diaAux;
    char cuitAux[32];
    char archivoAux[32];


    if(limite > 0 && arrayC != NULL)
    {
        i = buscarLugarLibre(arrayC,limite);
        if(i >= 0)
        {
            getValidInt("ID?","\nNumero no valido\n",&idPant,0,999999,2);
            posPant = pantalla_buscarPorId(pantallas,lenPantallas,idPant);
            if(posPant>=0)
            { // la pantalla existe, idPant es valido
                if (!getValidInt("rubro? 1)electronica, 2)bazar","\nNumero no valido\n",&diaAux,0,2,2))
                {
                    getStringNumeros("Cuit?",cuitAux);
                    {
                        if (!getValidString("Archivo?","Archivo no valido\n","Nombre de Archivo Demaciado Largo",archivoAux,32,2))
                        {
                            arrayC[i].rubro = diaAux;
                            arrayC[i].idPantalla = idPant; // relacion
                            strcpy(arrayC[i].archivo,archivoAux);
                            strcpy(arrayC[i].cuit,cuitAux);
                            arrayC[i].isEmpty=0;
                            arrayC[i].id = proximoId();
                        }

                    }

                }

            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


int cont_baja(Contratacion* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = buscarPorId(array,limite,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty=1;


        retorno=0;
    }
    return retorno;
}


static int buscarLugarLibre(Contratacion* array,int limite)
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


//int pantalla_buscarPorId(Pantalla* array,int limite, int id)
static int buscarPorId(Contratacion* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPantalla==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int cont_altaForzada(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas,
              int idPantalla,char* archivo,char* cuit,int rubro)
{
    int retorno = -1;
    int i;
    int posPant;
    if(limite > 0 && arrayC != NULL)
    {
        i = buscarLugarLibre(arrayC,limite);
        if(i >= 0)
        {

            posPant = pantalla_buscarPorId(pantallas,lenPantallas,idPantalla);
            if(posPant>=0)
            {
                arrayC[i].rubro = rubro;
                strcpy(arrayC[i].cuit,cuit);
                strcpy(arrayC[i].archivo,archivo);
                //TODO
                arrayC[i].idPantalla = idPantalla; // relacion
                arrayC[i].isEmpty=0;
                arrayC[i].id = proximoId();
            }
        }
        retorno = 0;
    }
    return retorno;
}


int cont_ordenarCuit(Contratacion* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Contratacion auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].cuit,array[i+1].cuit) > 0 && orden) || (strcmp(array[i].cuit,array[i+1].cuit) < 0 && !orden)) //******
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


int cont_modificacion(Contratacion* array,int limite, int id)
{
    int retorno=-1;
    int indiceAModificar;
    int diaAux;
    char archivoAux[30];
    char cuitAux[30];
    indiceAModificar=buscarPorId(array,limite,id);
    if (indiceAModificar>=0)
    {
        if (!getValidInt("rubro?","\nNumero no valido\n",&diaAux,0,200,2))
                {
                    getStringNumeros("Cuit?",cuitAux);
                    {
                        if (!getValidString("Archivo?","Archivo no valido\n","Nombre de Archivo Demaciado Largo",archivoAux,32,2))
                        {
                            retorno = 0;
                            strcpy(array[indiceAModificar].cuit,cuitAux);
                            strcpy(array[indiceAModificar].archivo,archivoAux);
                            array[indiceAModificar].rubro = diaAux;
                        }

                    }

                }
    }
    return retorno;
}





