#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "clientes.h"
#include "utn.h"
#include "Contratacion.h"
#include "informar.h"

#define QTY 10
#define LEN_CONT    1000
int menuDeOpciones(void);
int main()
{
    clientes array[QTY];
    Contratacion contrataciones[LEN_CONT];
    int menu;
    int auxiliarId;
    int auxiliarIdbaja;
    clientes_init(array,QTY);
    cont_init(contrataciones,LEN_CONT);

    /*clientes_altaForzada(array,QTY,"Martin","Las Flores 50",50,0);
    clientes_altaForzada(array,QTY,"Juan","Belgrano 250",2000,0);
    clientes_altaForzada(array,QTY,"Miguel","Cerrito 300",3000,0);
    clientes_altaForzada(array,QTY,"Lorena","Lavalle 450",1000,1);
    clientes_altaForzada(array,QTY,"Zaira","Mitre 150",5000,1);

    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video.avi","10911911915",100);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video1.avi","20911911915",400);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video2.avi","30911911915",300);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video3.avi","50911911915",400);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video4.avi","60911911915",500);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video5.avi","40911911915",600);
*/
    informar_ListarCantidadContratacionesImporte(contrataciones,LEN_CONT,array,QTY);
    do
    {
       menu=menuDeOpciones();
        switch(menu)
        {
            case 1://Alta de clientes
                clientes_alta(array,QTY);
                break;
            case 2://Modificar datos de clientes
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                clientes_modificacion(array,QTY,auxiliarId);
                break;
            case 3://Baja de clientes
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                clientes_baja(array,QTY,auxiliarId);
                break;
            case 4://Contratar una publicidad
                cont_alta(contrataciones,LEN_CONT,array,QTY);
                break;
            case 5://Modificar condiciones de publicación
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                cont_modificacion(contrataciones,LEN_CONT,&auxiliarId);
                break;
            case 6://Cancelar contratación
                getValidInt("ID?","\nNumero valida\n",&auxiliarIdbaja,0,200,2);
                    cont_baja(contrataciones,LEN_CONT,&auxiliarIdbaja);
                break;
            case 7://Consulta facturación
                informar_ConsultaFacturacion(contrataciones,LEN_CONT,array,QTY,"20911911915");

                break;
            case 8://Listar contrataciones
                //clientes_ordenar(array,QTY, 1);
                informar_ListarContrataciones(contrataciones,LEN_CONT,array,QTY);
                break;
            case 9://Listar​ ​clientess
                clientes_mostrar(array,QTY);
                break;
            case 10://Informar
                break;
            case 11://Salir
                break;
        }

    }while(menu != 11);

    return 0;
}
int menuDeOpciones(void)
{
    int menu;
   printf("\n1-Alta de clientes.\n");
   printf("2-Modificar datos de clientes.\n");
   printf("3-Baja de clientes.\n");
   printf("4-Contratar una publicidad.\n");
   printf("5-Modificar condiciones de publicacion.\n");
   printf("6-Cancelar contratacion.\n");
   printf("7-Consulta facturacion.\n");
   printf("8-Listar contrataciones.\n");
   printf("9-Listar clientes.\n");
   printf("10-Informar.\n");
   getValidInt("11-salir.","la opcion no exite",&menu,1,11,2);
   return menu;

}
