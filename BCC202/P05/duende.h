# ifndef duende_h
# define duende_h

typedef struct duende Duende;
typedef struct time Time;

typedef enum {
    NAO=0,
    SIM
} ESCALADO;

//Manter como especificado
void lerQuantidade(int *qtd);

//Manter como especificado
Duende *alocaDuendes(int qtd);

//Manter como especificado
Time *alocaTimes(int qtd);

//Manter como especificado
Duende* desalocaDuendes(Duende *duendes);

//Manter como especificado
Time* desalocaTimes(Time *times);

//Manter como especificado
void lerDuendes(Duende *duendes, int qtd);

//Manter como especificado
void escalarTimes(Duende *duendes, Time *times, int qtdDuendes);

//Manter como especificado
int proximoMaisVelho(Duende *duendes, int qtd);

//Manter como especificado
void printTimes(Time *times, int qtd);

# endif