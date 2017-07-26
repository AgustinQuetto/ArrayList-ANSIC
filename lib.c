#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "lib.h"

void menu()
{
    printf("1. Leer Log\n");
    printf("2. Procesar informacion\n");
    printf("3. Mostrar estadisticas\n");
    printf("4- Salir\n");
}

LogEntry* new_log(void)
{
    LogEntry* returnLog;
    returnLog=(LogEntry*)malloc(sizeof(LogEntry));
    if(returnLog!=NULL)
    {
        strcpy(returnLog->date," ");
        strcpy(returnLog->time," ");
        returnLog->serviceId=0;
        returnLog->gravedad=0;
        strcpy(returnLog->msg," ");
    }
    return returnLog;
}

Service* new_service(void)
{
    Service* returnService;
    returnService=(Service*)malloc(sizeof(Service));
    if(returnService!=NULL)
    {
        returnService->id=0;
        strcpy(returnService->name," ");
        strcpy(returnService->email," ");
    }
    return returnService;
}

LogEntry* new_log_param(char date[11], char time[6], int serviceId, int gravedad, char msg[65])
{

    LogEntry* returnLog;
    returnLog=(LogEntry*)malloc(sizeof(LogEntry));
    if(returnLog!=NULL)
    {
        strcpy(returnLog->date,date);
        strcpy(returnLog->time,time);
        returnLog->serviceId=serviceId;
        returnLog->gravedad=gravedad;
        strcpy(returnLog->msg,msg);
    }
    return returnLog;
}

Service* new_service_param(int id, char name[33], char email[65])
{
    Service* returnService;
    returnService=(Service*)malloc(sizeof(Service));
    if(returnService!=NULL)
    {
        returnService->id=id;
        strcpy(returnService->name,name);
        strcpy(returnService->email,email);
    }
    return returnService;
}

int cargarListaLogs(ArrayList* listaLogs)
{
    FILE *fp;
    int returnAux=-1;
    char* date=(char*)malloc(sizeof(char)*11);
    char* time=(char*)malloc(sizeof(char)*6);
    char* serviceId=(char*)malloc(sizeof(char)*10);
    char* gravedad=(char*)malloc(sizeof(char)*10);
    char* msg=(char*)malloc(sizeof(char)*65);
    fp = fopen("log.txt","r");
    LogEntry* unLog;
    if(fp!=NULL)
    {
        while(!feof(fp))
        {
            unLog=new_log();
            if(unLog!=NULL)
            {
                fscanf(fp,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",date,time,serviceId,gravedad,msg);

                strcpy(unLog->date,date);
                strcpy(unLog->time,time);
                unLog->serviceId=atoi(serviceId);
                unLog->gravedad=atoi(gravedad);
                strcpy(unLog->msg,msg);

                listaLogs->add(listaLogs,unLog);
                //printf("-%d\n", unLog->serviceId);
            }
        }
        returnAux=0;
    }
    fclose(fp);
    return returnAux;
}

int cargarListaService(ArrayList* listaService)
{
    FILE *fp;
    int returnAux=-1;
    char* id=(char*)malloc(sizeof(char)*10);
    char* name=(char*)malloc(sizeof(char)*33);
    char* email=(char*)malloc(sizeof(char)*65);
    fp = fopen("services.txt","r");
    Service* unService;
    if(fp!=NULL)
    {
        while(!feof(fp))
        {
            unService=new_log();
            if(unService!=NULL)
            {
                fscanf(fp,"%[^;];%[^;];%[^\n]\n",id,name,email);

                unService->id=atoi(id);
                strcpy(unService->name,name);
                strcpy(unService->email,email);

                listaService->add(listaService,unService);
                //printf("-%d\n", unService->id);
            }
        }
        returnAux=0;
    }
    fclose(fp);
    return returnAux;
}

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
}
