#ifndef PUBLICACIONES_H_INCLUDED
#define PUBLICACIONES_H_INCLUDED
typedef struct
{
    char cuit[50];
    int idCliente;
    int rubro;
    int archivo;
    //------------
    int id;
    int isEmpty;
}Clientes;



#endif // PUBLICACIONES_H_INCLUDED
int cont_init(Clientes* array,int limite);
int cont_mostrar(Clientes* array,int limite);
int cont_mostrarDebug(Clientes* array,int limite);

int cont_alta(Clientes* arrayC,int limite,
              Clientes* clientes, int lenClientes);

int cont_baja(Clientes* array,int limite, int id);
int cont_modificacion(Clientes* array,int limite, int id);
int cont_ordenar(Clientes* array,int limite, int orden);
int cont_ordenarCuit(Clientes* array,int limite, int orden);
//int buscarLugarLibre(Clientes* array,int limite);
//int proximoId();
//int Clientes_buscarPorId(Clientes* array,int limite, int id);


int cont_altaForzada(Clientes* arrayC,int limite,Clientes* clientess, int lenClientess,int idClientes,char* texto,char* cuit,int rubro);



