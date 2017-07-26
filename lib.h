struct S_LogEntry
{
 char date[11];
 char time[6];
 int serviceId;
 int gravedad;
 char msg[65];
};
typedef struct S_LogEntry LogEntry;

struct S_Service
{
 int id;
 char name[33];
 char email[65];
};
typedef struct S_Service Service;

void menu();

LogEntry* new_log(void);

Service* new_service(void);

LogEntry* new_log_param(char date[11], char time[6], int serviceId, int gravedad, char msg[65]);

Service* new_service_param(int id, char name[33], char email[65]);

int cargarListaLogs(ArrayList* listaLogs);

int cargarListaService(ArrayList* listaService);

//guardar lista logs
void guardarYMostrar(ArrayList* listaLogs, ArrayList* listaServices);
