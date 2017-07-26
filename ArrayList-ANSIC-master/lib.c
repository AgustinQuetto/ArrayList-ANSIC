#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "lib.h"

void menu()
{
    printf("1. Leer archivos\n");
    printf("2. Reproducir\n");
    printf("3. Ecualizar\n");
    printf("4- Correccion\n");
    printf("5- Salir\n");
}

s_Nota* new_nota(void)
{
    s_Nota* returnNota;
    returnNota=(s_Nota*)malloc(sizeof(s_Nota));
    if(returnNota!=NULL)
    {
        strcpy(returnNota->nombre," ");
        returnNota->freq=0;
        returnNota->duration=0;
        returnNota->volume=0;
    }
    return returnNota;
}

s_NotaAux* new_notaAux(void)
{
    s_NotaAux* returnNota;
    returnNota=(s_NotaAux*)malloc(sizeof(s_NotaAux));
    if(returnNota!=NULL)
    {
        strcpy(returnNota->nombre," ");
        returnNota->freq=0;
    }
    return returnNota;
}

s_MelodiaAux* new_melodiaAux(void)
{
    s_MelodiaAux* returnMelodia;
    returnMelodia=(s_MelodiaAux*)malloc(sizeof(s_MelodiaAux));
    if(returnMelodia!=NULL)
    {
        strcpy(returnMelodia->nombre," ");
        returnMelodia->duration=0;
        returnMelodia->volume=0;
    }
    return returnMelodia;
}

/*s_Nota* new_nota_param(char nombre, int freq, int duration, int volume)
{

    s_Nota* returnNota;
    returnNota=(s_Nota*)malloc(sizeof(s_Nota));
    if(returnNota!=NULL)
    {
        strcpy(returnNota->nombre,nombre);
        returnNota->duration=freq;
        returnNota->volume=duration;
        returnNota->volume=volume;
    }
    return returnNota;
}*/




int cargarNotas(ArrayList* listaNotas, ArrayList* listaNotasAux, ArrayList* listaMelodiaAux)
{
    FILE *f,*p;
    int returnAux=-1;
    char* nombre=(char*)malloc(sizeof(char)*11);
    char* freq=(char*)malloc(sizeof(char)*6);
    char* duration=(char*)malloc(sizeof(char)*10);
    char* volume=(char*)malloc(sizeof(char)*10);
    p = fopen("melodia.txt","r");
    f = fopen("notas.txt","r");
    s_NotaAux* unaNota;
    s_MelodiaAux* unaMelodia;
    if(f!=NULL)
    {

        while(!feof(f))
        {
            unaNota=new_notaAux();

            if(unaNota!=NULL)
            {
                fscanf(f,"%[^=]=%[^\n]\n",nombre, freq);

                strcpy(unaNota->nombre,nombre);
                unaNota->freq=atoi(freq);


                listaNotasAux->add(listaNotasAux,unaNota);
                printf("-%d\n", unaNota->freq);
            }
        }
        returnAux=0;
    }else{
        printf("debug\n");
    }

   if(p!=NULL)
    {
        while(!feof(p))
        {
            unaMelodia=new_melodiaAux();
            if(unaMelodia!=NULL)
            {
                fscanf(p,"%[^;];%[^;];%[^\n]\n",nombre, duration, volume);

                strcpy(unaMelodia->nombre,nombre);
                unaMelodia->duration=atoi(duration);
                unaMelodia->volume=atoi(volume);


                listaMelodiaAux->add(listaMelodiaAux,unaMelodia);
                printf("-%d\n", unaMelodia->duration);
            }
        }
        returnAux=1;
    }else{
        printf("debug\n");
    }

    fclose(f);
    fclose(p);
    return returnAux;
}
/*
//guardar lista logs
void guardarYMostrar(ArrayList* listaLogs, ArrayList* listaServices)
{
    FILE *f,*p;
    int i,j;
    LogEntry* unLog;
    Service* unService;

    f=fopen("warnings-procesados.txt","w");
    p=fopen("errors-procesados.txt","w");
    if(f!=NULL && p!=NULL)
    {
        for(i=0; i<listaServices->len(listaServices); i++)
        {

            for(j=0; j<listaLogs->len(listaLogs); j++)
            {

                unService=listaServices->get(listaServices,i);
                unLog=listaLogs->get(listaLogs,j);
                if(unLog->gravedad < 3)
                {
                    printf("Log descartado %d.\n", unLog->gravedad);
                }
                if(unLog->gravedad==3 && unLog->serviceId != 45)
                {
                    fprintf(f,"%s\n",unLog->msg);
                    printf("Escrito.");
                }

                if(unLog->gravedad >= 4 && unLog->gravedad <=7)
                {
                    printf("%s;%s;%s;%s;%d\n",unLog->date,unLog->time,unService->name,unLog->msg,unLog->gravedad);
                    printf("Mostrado.");
                }

                if(unLog->gravedad > 7)
                {
                    fprintf(p,"%s;%s;%s;%s;%s\n",unLog->date,unLog->time,unService->name,unLog->msg,unService->email);
                    printf("Escrito.");
                }
            }
        }
        fclose(f);
        fclose(p);
    }
    else
    {
        printf("No se pudieron crear o sobreescribir los archivos.");
    }
}*/
