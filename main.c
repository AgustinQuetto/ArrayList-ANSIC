#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "lib.h"

int main()
{
    ArrayList* listaLogs=al_newArrayList();
    ArrayList* listaServices=al_newArrayList();

    int opcion;
    do
    {
        opcion=0;
        menu();
        printf("Opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                    if(cargarListaLogs(listaLogs)==0)
                    {
                        printf("Logs cargados\n");
                    }else{
                        printf("Error al cargar.\n");
                    }
                    if(cargarListaService(listaServices)==0)
                    {
                        printf("Servicios cargados\n");
                    }else{
                        printf("Error al cargar.\n");
                    }
                break;
            case 2:
                    guardarYMostrar(listaLogs, listaServices);
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                printf("ERROR: opcion inexistente.\n");
                break;
        }
        system("pause");
        system("cls");
    }
    while(opcion!=4);
    return 0;
}
