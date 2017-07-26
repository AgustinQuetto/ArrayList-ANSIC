#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "lib.h"

int main()
{
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
                break;
            case 2:
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
    while(opcion!=7);
    return 0;
}
