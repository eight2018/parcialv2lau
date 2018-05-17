#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    float cuitb;
    int tipo;
    //------------
    int idClientes;
    int isEmpty;
}Clientes;


#endif // CLIENTES_H_INCLUDED
int clientes_init(Clientes* array,int limite);
int clientes_mostrar(Clientes* array,int limite);
int clientes_mostrarDebug(Clientes* array,int limite);
int clientes_alta(Clientes* array,int limite);
int clientes_baja(Clientes* array,int limite, int id);
int clientes_modificacion(Clientes* array,int limite, int id);
int clientes_ordenar(Clientes* array,int limite, int orden);
int clientes_buscarPorId(Clientes* array,int limite, int id);
int clientes_altaForzada(Clientes* array,int limite,char* nombre,char* apellido, float cuitb, int tipo);
//int buscarLugarLibre(Pantalla* array,int limite);
//int proximoId();
//int Clientes_buscarPorId(Clientes* array,int limite, int id);

