#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "lib.h"

int main()
{
    ArrayList* listaNotas=al_newArrayList();
    ArrayList* listaNotasAux=al_newArrayList();
    ArrayList* listaMelodiaAux=al_newArrayList();

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
                    if(cargarNotas(listaNotas,listaNotasAux,listaMelodiaAux) == 1)
                    {
                        printf("Notas cargadas\n");
                    }else{
                        printf("Error al cargar.\n");
                    }
                break;
            case 2:
                    //guardarYMostrar(listaLogs, listaServices);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                printf("ERROR: opcion inexistente.\n");
                break;
        }
        system("pause");
        system("cls");
    }
    while(opcion!=5);
    return 0;
}
