#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/*


    Thayllon Bragança
    24.1.9902
    Turma-31




                            ██████╗░███████╗███╗░░░███╗  ██╗░░░██╗██╗███╗░░██╗██████╗░░█████╗░  ░█████╗░░█████╗░
                            ██╔══██╗██╔════╝████╗░████║  ██║░░░██║██║████╗░██║██╔══██╗██╔══██╗  ██╔══██╗██╔══██╗
                            ██████╦╝█████╗░░██╔████╔██║  ╚██╗░██╔╝██║██╔██╗██║██║░░██║██║░░██║  ███████║██║░░██║
                            ██╔══██╗██╔══╝░░██║╚██╔╝██║  ░╚████╔╝░██║██║╚████║██║░░██║██║░░██║  ██╔══██║██║░░██║
                            ██████╦╝███████╗██║░╚═╝░██║  ░░╚██╔╝░░██║██║░╚███║██████╔╝╚█████╔╝  ██║░░██║╚█████╔╝
                            ╚═════╝░╚══════╝╚═╝░░░░░╚═╝  ░░░╚═╝░░░╚═╝╚═╝░░╚══╝╚═════╝░░╚════╝░  ╚═╝░░╚═╝░╚════╝░

                            ░██████╗░██╗░░░██╗███████╗██████╗░██████╗░░█████╗░░░░░░░░█████╗░░█████╗░██████╗░███████╗░█████╗░░█████╗░░██████╗
                            ██╔═══██╗██║░░░██║██╔════╝██╔══██╗██╔══██╗██╔══██╗░░░░░░██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔════╝
                            ██║██╗██║██║░░░██║█████╗░░██████╦╝██████╔╝███████║█████╗██║░░╚═╝███████║██████╦╝█████╗░░██║░░╚═╝███████║╚█████╗░
                            ╚██████╔╝██║░░░██║██╔══╝░░██╔══██╗██╔══██╗██╔══██║╚════╝██║░░██╗██╔══██║██╔══██╗██╔══╝░░██║░░██╗██╔══██║░╚═══██╗
                            ░╚═██╔═╝░╚██████╔╝███████╗██████╦╝██║░░██║██║░░██║░░░░░░╚█████╔╝██║░░██║██████╦╝███████╗╚█████╔╝██║░░██║██████╔╝
                            ░░░╚═╝░░░░╚═════╝░╚══════╝╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝░░░░░░░╚════╝░╚═╝░░╚═╝╚═════╝░╚══════╝░╚════╝░╚═╝░░╚═╝╚═════╝░


    TASKS:

    [X] Estilizar o menu
    [X] Implementar a opção de sair
    [X] Implementar a opção de novo jogo
    [X] Implementar a opção de continuar jogo
    [X] Implementar a opção de carregar jogo
    [X] Implementar a opção de ajuda
    [X] Trocar logica das matrizes para o uso de struct
    [X] Implementar funções de criar e liberar matriz
    [X] Trocar todos vetores estaticos por dinamicos e liberar
    [X] Checar o embaralhamento (se o rand desfizer o movimento anterior, sortear novamente)
    [X] Conferir todas as validações e suas mensagens de erro
    [X] Conferir se podemos voltar em qualquer lugar
    [X] Conferir se temos que deixar somente as opções do menu devem aceitar maiusculas e minusculas (com o professor)
        - SIM
    [X] Criar função para lowercase
    [X] Deixar todas as entradas com lowercase
    [x] Adicionar todos os comentarios
    [-] Revisar logica e tentar melhorar printBoard (talvez)
    [X] Conferir se o barra n atrapalha na hora de ler string dentro de um loop
    [X] Conferir se o nome do arquivo pode ter espaço (com o professor)
        - Não
    [X] Conferir se estou movendo para parede, se sim, oque é pra fazer

*/

// cores e formato de texto
#define ANSI_RESET            "\x1b[0m"  // desativa os efeitos anteriores
#define ANSI_BOLD             "\x1b[1m"  // coloca o texto em negrito
#define ANSI_COLOR_BLACK      "\x1b[30m"
#define ANSI_COLOR_RED        "\x1b[31m"
#define ANSI_COLOR_GREEN      "\x1b[32m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_BLUE       "\x1b[34m"
#define ANSI_COLOR_MAGENTA    "\x1b[35m"
#define ANSI_COLOR_CYAN       "\x1b[36m"
#define ANSI_COLOR_WHITE      "\x1b[37m"
#define ANSI_BG_COLOR_BLACK   "\x1b[40m"
#define ANSI_BG_COLOR_RED     "\x1b[41m"
#define ANSI_BG_COLOR_GREEN   "\x1b[42m"
#define ANSI_BG_COLOR_YELLOW  "\x1b[43m"
#define ANSI_BG_COLOR_BLUE    "\x1b[44m"
#define ANSI_BG_COLOR_MAGENTA "\x1b[45m"
#define ANSI_BG_COLOR_CYAN    "\x1b[46m"
#define ANSI_BG_COLOR_WHITE   "\x1b[47m"

// macros para facilitar o uso
#define BOLD(string)       ANSI_BOLD             string ANSI_RESET
#define BLACK(string)      ANSI_COLOR_BLACK      string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define RED(string)        ANSI_COLOR_RED        string ANSI_RESET
#define GREEN(string)      ANSI_COLOR_GREEN      string ANSI_RESET
#define YELLOW(string)     ANSI_COLOR_YELLOW     string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define MAGENTA(string)    ANSI_COLOR_MAGENTA    string ANSI_RESET
#define CYAN(string)       ANSI_COLOR_CYAN       string ANSI_RESET
#define WHITE(string)      ANSI_COLOR_WHITE      string ANSI_RESET
#define BG_BLACK(string)   ANSI_BG_COLOR_BLACK   string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_RED(string)     ANSI_BG_COLOR_RED     string ANSI_RESET
#define BG_GREEN(string)   ANSI_BG_COLOR_GREEN   string ANSI_RESET
#define BG_YELLOW(string)  ANSI_BG_COLOR_YELLOW  string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_MAGENTA(string) ANSI_BG_COLOR_MAGENTA string ANSI_RESET
#define BG_CYAN(string)    ANSI_BG_COLOR_CYAN    string ANSI_RESET
#define BG_WHITE(string)   ANSI_BG_COLOR_WHITE   string ANSI_RESET

// caracteres uteis para tabelas
#define TAB_HOR "\u2501" // ━ (horizontal)
#define TAB_VER "\u2503" // ┃ (vertical)
#define TAB_TL  "\u250F" // ┏ (top-left)
#define TAB_ML  "\u2523" // ┣ (middle-left)
#define TAB_BL  "\u2517" // ┗ (bottom-left)
#define TAB_TJ  "\u2533" // ┳ (top-join)
#define TAB_MJ  "\u254B" // ╋ (middle-join)
#define TAB_BJ  "\u253B" // ┻ (bottom-join)
#define TAB_TR  "\u2513" // ┓ (top-right)
#define TAB_MR  "\u252B" // ┫ (middle-right)
#define TAB_BR  "\u251B" // ┛ (bottom-right)

#define TAM 20

typedef struct{
    int **matriz;
    int jogadas;
    int lineCol;
}RoundGame;

/**
 * Libera a memória alocada para uma matriz.
 *
 * @param **matriz Ponteiro duplo que representa a matriz.
 * @param size O tamanho da matriz (número de linhas).
 * @author Thayllon Bragança
 */
void liberaMatriz(int **, int);

/**
 * Cria uma matriz dinâmica de inteiros.
 *
 * @param size O tamanho da matriz (número de linhas e colunas).
 * @return Um ponteiro duplo para a matriz criada.
 * @author Thayllon Bragança
 */
int **createMatriz(int);

/**
 * Função principal do jogo. Realiza uma rodada do jogo.
 *
 * @param *roundGame Ponteiro para a estrutura que contém os dados do jogo.
 * @return Retorna o status do jogo após a rodada.
 * @author Thayllon Bragança
 */
int game(RoundGame*);

/**
 * Exibe o menu principal do jogo.
 * @author Thayllon Bragança
 */
void menu();

/**
 * Executa as opções do menu de acordo com a escolha do jogador.
 *
 * @param *option String contendo a opção selecionada pelo usuário.
 * @param *roundGame Ponteiro para a estrutura de dados do jogo.
 * @return Retorna 1 caso a opção foi bem sucedida e 0 para bem sucedida mas finaliza o jogo.
 * @author Thayllon Bragança
 */
int menuOptions(char*, RoundGame*);

/**
 * Imprime o tabuleiro do jogo.
 *
 * @param **matriz Ponteiro duplo que representa a matriz do tabuleiro.
 * @param size Tamanho da matriz (número de linhas e colunas).
 * @author Thayllon Bragança
 */
void printBoard(int**, int);

/**
 * Cria e inicializa o tabuleiro do jogo.
 *
 * @param *roundGame Ponteiro para a estrutura que contém os dados do jogo.
 * @author Thayllon Bragança
 */
void createBoard(RoundGame*);

/**
 * Preenche o tabuleiro de forma aleatória.
 *
 * @param **matriz Ponteiro duplo que representa a matriz do tabuleiro.
 * @param size Tamanho da matriz (número de linhas e colunas).
 * @return Retorna 1 se o tabuleiro foi preenchido com sucesso.
 * @author Thayllon Bragança
 */
int randBoard(int**, int);

/**
 * Move um número no tabuleiro.
 *
 * @param **matriz Ponteiro duplo que representa a matriz do tabuleiro.
 * @param size Tamanho da matriz (número de linhas e colunas).
 * @param number O número a ser movido.
 * @param *direction Quantidade de movimentos.
 * @return Retorna 1 se o movimento foi realizado com sucesso, 0 caso contrário e -1 caso não exista o elemento.
 * @author Thayllon Bragança
 */
int mooveNumberBoard(int**, int, int, int*);

/**
 * Verifica se o jogador venceu o jogo.
 *
 * @param **matriz Ponteiro duplo que representa a matriz do tabuleiro.
 * @param size Tamanho da matriz (número de linhas e colunas).
 * @return Retorna 1 se o usuaro completou, 0 caso contrário.
 * @author Thayllon Bragança
 */
int checkWinner(int**, int);

/**
 * Salva o nome do jogador e o estado do jogo.
 *
 * @param **matriz Ponteiro duplo que representa a matriz do tabuleiro.
 * @param *name Nome do jogo.
 * @param lineCol Tamanho do tabuleiro.
 * @param jogadas Quantidade de jogadas do jogador.
 * @return Retorna 1 se o jogo foi salvo com sucesso, 0 caso contrário.
 * @author Thayllon Bragança
 */
int saveName(int**, char*, int , int);

/**
 * Carrega um jogo salvo.
 *
 * @param *roundGame Ponteiro para a estrutura que contém os dados do jogo.
 * @param *nome Nome do arquivo cujo jogo será carregado.
 * @return Retorna 1 se o jogo foi carregado com sucesso, 0 caso contrário.
 * @author Thayllon Bragança
 */
int loadGame(RoundGame*, char*);

/**
 * Converte todos os caracteres de uma string para minúsculas.
 *
 * @param *str Ponteiro para a string que será convertida.
 * @author Thayllon Bragança
 */
void toLowerCase(char *);

/**
 * Limpa todo o buffer do teclado;
 *
 * @author Thayllon Bragança
 */
void clearInputBuffer();

int main(){
    char *option = (char*)malloc(TAM*sizeof(char));

    int optResult=1;
    RoundGame roundGame={NULL, 0, 0};
    do{
        menu();
        printf(ANSI_BOLD BLUE("[*]")" Escolha a opção (digite “voltar” em qualquer lugar para voltar ao menu principal): ");
        scanf("%s", option);
        clearInputBuffer();

        toLowerCase(option);

        optResult = menuOptions(option, &roundGame);
    }while(optResult);

    free(option);
    return 0;
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Descarta todos os caracteres até nova linha
}
void liberaMatriz(int** matriz, int lineCol){
    if(matriz != NULL){
        for(int i=0; i<lineCol; i++){
            free(*(matriz+i));
        }

        free(matriz);
    }
}

void toLowerCase(char *str) {
    int i = 0;
    while (*(str+i) != '\0') {
        *(str+i) = tolower(*(str+i));
        i++;
    }
}

void menu(){
    system("clear");


    printf("\n");
    for(int i =0 ; i<9; i++){
        printf(BG_WHITE("\u200A")"\u200A");
        fflush(stdout);  // Garante que a saída é atualizada imediatamente
        usleep(50000);  // Espera 500000 microssegundos (500ms)
    }
    printf("Bem vindo ao Quebra-Cabeças ");
    for(int i =0 ; i<9; i++){
        printf(BG_WHITE("\u200A")"\u200A");
        fflush(stdout);  // Garante que a saída é atualizada imediatamente
        usleep(50000);  // Espera 500000 microssegundos (500ms)
    }




    printf("\n\n");
    printf(TAB_TL);
    for(int i=0; i<63; i++){
        printf(TAB_HOR);
    }
    printf(TAB_TR"\n");
    printf(TAB_VER "\t\t\t\t\t\t\t\t" TAB_VER "\n");
    printf(TAB_VER "\t\tX. Sair do Jogo\t\t\t\t\t" TAB_VER "\n");
    printf(TAB_VER "\t\tN. Iniciar um novo jogo\t\t\t\t" TAB_VER "\n");
    printf(TAB_VER "\t\tC. Continuar o jogo atual\t\t\t" TAB_VER "\n");
    printf(TAB_VER "\t\tS. Continuar um jogo salvo\t\t\t" TAB_VER "\n");
    printf(TAB_VER "\t\tA. Ajuda com as instruções do jogo\t\t" TAB_VER "\n");
    printf(TAB_VER "\t\t\t\t\t\t\t\t" TAB_VER "\n");
    printf(TAB_BL);
    for(int i=0; i<63; i++){
        printf(TAB_HOR);
    }
    printf(TAB_BR"\n");
    printf("\n\n");

}

void printBoard(int** matriz, int licol){
    printf("\n"TAB_TL);


    char *buffer = (char*)malloc(3*sizeof(char));


    sprintf(buffer, "%d", licol*licol); // Passa o dado formatado para uma string
    int licolTam = strlen(buffer);

    for(int i=0;i<licol;i++){
        for(int j=0; j<2+licolTam;j++){
            printf(TAB_HOR);
        }
        i != licol-1 ? printf(TAB_TJ):printf(TAB_TR);
    }
    printf("\n");

    for(int i=0;i<licol-1;i++){
        for(int j=0; j<licol; j++){

            if(*(*(matriz+i)+j) == 0){
            printf(TAB_VER " "BG_WHITE("%*s")" ",licolTam,"");
                continue;
            }
           printf(TAB_VER" %*d ",licolTam, *(*(matriz+i)+j));
        }
        printf(TAB_VER"\n");

        printf(TAB_ML);


        for(int i=0;i<licol;i++){
            for(int j=0; j<2+licolTam;j++){
                printf(TAB_HOR);
            }
            i != licol-1 ? printf(TAB_MJ):printf(TAB_MR"\n");
        }
    }

    for(int j=0; j<licol; j++){
        if(*(*(matriz+licol-1)+j) == 0){
            printf(TAB_VER " "BG_WHITE("%*s")" ",licolTam,"");
            continue;
        }
        printf(TAB_VER" %*d ",licolTam,*(*(matriz+licol-1)+j));
    }


    printf(TAB_VER"\n");

    printf(TAB_BL);


    for(int i=0;i<licol;i++){
        for(int j=0; j<licolTam+2;j++){
            printf(TAB_HOR);
        }

        i != licol-1 ? printf(TAB_BJ):printf(TAB_BR"\n");
    }
    free(buffer);
    printf("\n");
}

int** createMatriz(int licol){

    int **matriz=NULL;
    matriz = malloc(licol*sizeof(int*));
    for(int i=0; i<licol; i++){
        *(matriz+i) = malloc(licol*sizeof(int));
    }

    return matriz;
}

void createBoard(RoundGame *roundGame){
    char *out = (char *)malloc(32*sizeof(char));
    do{
        printf(ANSI_BOLD YELLOW("[*]")" Digite a dimensão do tabuleiro (3 ≤ n ≤ 10): ");
        scanf("%9s", out);
        clearInputBuffer();
        toLowerCase(out);
        if(sscanf(out, "%d", &roundGame->lineCol)!=1 && !strcmp(out, "voltar")){ // Pega um dado de uma string e passa para outra variavel dependendo do tipo
            free(out);
            return;
        }
        if(roundGame->lineCol<3 || roundGame->lineCol > 10){
            printf("\n"ANSI_BOLD RED("[!]")" Comando invalido!\n");
        }
    }while(roundGame->lineCol<3 || roundGame->lineCol > 10);

    roundGame->matriz = createMatriz(roundGame->lineCol);


    int a=1;
    for(int i=0; i<roundGame->lineCol; i++){
        for(int j=0; j<roundGame->lineCol; j++){
            *(*(roundGame->matriz+i)+j) = a;
            a++;
        }
    }
    *(*(roundGame->matriz+(roundGame->lineCol)-1)+(roundGame->lineCol)-1) = 0;
    free(out);
}

int randBoard(int ** matriz, int licol){

    int op=1, nivel=0;
    char *dif = (char*)malloc(32*sizeof(char));
    do{
        printf(ANSI_BOLD BLUE("[*]")" Digite o nível de dificuldade para embaralhar, fácil"BLUE("(F)") ", médio" YELLOW("(M)")" ou difícil" RED("(D)"": "));
        scanf("%9s", dif);
        clearInputBuffer();
        toLowerCase(dif);

        if(!strcmp(dif,"f")){
            nivel = 5*licol;
        }else if(!strcmp(dif,"m")){
            nivel = 10*licol;
        }else if(!strcmp(dif,"d")){
            nivel = 20*licol;
        }else if(!strcmp(dif,"voltar")){
            liberaMatriz(matriz, licol);
            free(dif);
            return 0;
        }else{
            printf(ANSI_BOLD RED("[!]")" Comando invalido, tente novamente.\n");
            continue;
        }

        op=0;

    }while(op);

    free(dif);

    int l=licol-1,c = licol-1, fLine = 0, fColumn = 0, count= 0, sort=0, aux=0, anterior=0;

    srand(time(NULL));
    while(count<nivel){


        sort = (rand()%4)+1;
        if(
            (
                (anterior%2==0  && sort%2==0 && anterior!=sort) ||
                (anterior%2!=0 && sort%2!=0 && anterior!=sort)
            ) && anterior!=0){
            continue;
        }

        if(sort ==1 && l-1 >=fLine){
            aux = *(*(matriz+l-1)+c);
            *(*(matriz+l-1)+c) = *(*(matriz+l)+c);
            *(*(matriz+l)+c) = aux;
            l--;
        }else if(sort ==3 && l+1<licol){
            aux = *(*(matriz+l+1)+c);
            *(*(matriz+l+1)+c) = *(*(matriz+l)+c);
            *(*(matriz+l)+c) = aux;
            l++;
        }else if(sort ==2 && c-1>=fColumn){
            aux = *(*(matriz+l)+c-1);
            *(*(matriz+l)+c-1) = *(*(matriz+l)+c);
            *(*(matriz+l)+c) = aux;
            c--;
        }else if(sort ==4 && c+1<licol){
            aux = *(*(matriz+l)+c+1);
            *(*(matriz+l)+c+1) = *(*(matriz+l)+c);
            *(*(matriz+l)+c) = aux;
            c++;
        }else{
            continue;

        }


        count++;
        anterior = sort;

    }

    return 1;
}

int mooveNumberBoard(int**matriz, int lineCol, int number, int *count){
    int aux=0;
    for(int i=0; i<lineCol; i++){
        for(int j=0; j<lineCol; j++){
            if(number == *(*(matriz+i)+j)){//matriz[i][j]
                if( i+1 <= lineCol-1 && *(*(matriz+i+1)+j) == 0){
                    aux = *(*(matriz+i+1)+j);
                    *(*(matriz+i+1)+j) = *(*(matriz+i)+j);
                    *(*(matriz+i)+j) = aux;
                }else if(i-1 >= 0 && *(*(matriz+i-1)+j) == 0){
                    aux = *(*(matriz+i-1)+j);
                    *(*(matriz+i-1)+j) = *(*(matriz+i)+j);
                    *(*(matriz+i)+j) = aux;
                }else if(j+1 <= lineCol-1 && *(*(matriz+i)+j+1) == 0){
                    aux = *(*(matriz+i)+j+1);
                    *(*(matriz+i)+j+1) = *(*(matriz+i)+j);
                    *(*(matriz+i)+j) = aux;
                }else if(j-1 >= 0 && *(*(matriz+i)+j-1) == 0){
                    aux = *(*(matriz+i)+j-1);
                    *(*(matriz+i)+j-1) = *(*(matriz+i)+j);
                    *(*(matriz+i)+j) = aux;
                }else{
                    return 0;
                }
                *count+=1;
                return 1;
            }
        }
    }

    return -1;
}

int checkWinner(int **matriz, int lineCol){
    for(int i=0; i<lineCol; i++){
        for(int j=1; j<lineCol; j++){
            if(*(*(matriz+i)+j) !=0 && *(*(matriz+i)+j)<*(*(matriz+i)+j-1)){
               return 0;
            }
        }
    }

    return 1;
}

int saveName(int **matriz, char *name, int lineCol, int jogadas){

    FILE *file;
    file = fopen(name, "w");

    if (file == NULL) {
        return 0;
    }

    fprintf(file, "%d\n", lineCol);

    for(int i =0; i<lineCol; i++){
        for(int j=0; j< lineCol-1; j++){
            fprintf(file, "%d ",*(*(matriz+i)+j));
        }
        fprintf(file, "%d",*(*(matriz+i)+lineCol-1));
        fprintf(file, "\n");
    }


    fprintf(file, "%d", jogadas);
    fclose(file);

    return 1;

}

int game(RoundGame* roundGame){
    int op=1;
    char *command = (char*)malloc(32*sizeof(char));
    char *name = (char*)malloc(32*sizeof(char));
    int number=0, mooved=0;
    int save=0;
    do{
        printBoard(roundGame->matriz,roundGame->lineCol);
        printf(ANSI_BOLD BLUE("[*]")" Digite um comando ou número da peça que quer mover: ");
        scanf("%9s", command);
        toLowerCase(command);
        if(!strcmp(command, "salvar")){
            scanf("%9s", name);
            clearInputBuffer();
            save = saveName(roundGame->matriz, name, roundGame->lineCol, roundGame->jogadas);
            if (save == 0){
                printf(ANSI_BOLD RED("[!]")" Não foi possivel salvar o jogo, tente novamente!\n");
            }else{
                printf(ANSI_BOLD CYAN("[-]")" Arquivo \"%s\" salvo com sucesso!\n",name);
            }
            continue;
        }else if(!strcmp(command, "voltar")){
            free(command);
            free(name);
            clearInputBuffer();
            return 1;
        }else{
            number = atoi(command); // Pega os primeiros numero validos da string e converte em inteiro
        }


        clearInputBuffer();

        mooved = mooveNumberBoard(roundGame->matriz, roundGame->lineCol, number, &roundGame->jogadas);

        if(mooved == -1 || number == 0){
            printf("\n" ANSI_BOLD RED("[!]") " Peça invalida, verifique o tabuleiro e tente novamente\n");
            continue;
        }else if(mooved == 0){
            printf("\n" ANSI_BOLD RED("[!]") " Não é possível mover a peça %d.\n", number);
            continue;
        }else{

            if(*(*(roundGame->matriz+roundGame->lineCol-1)+roundGame->lineCol-1)==0){
                if(checkWinner(roundGame->matriz, roundGame->lineCol)){
                    printf(ANSI_BOLD MAGENTA("[!]")" Parabéns! Você completou o quebra-cabeças com %d movimentos.\n", roundGame->jogadas);
                    op=0;


                    printBoard(roundGame->matriz,roundGame->lineCol);

                    liberaMatriz(roundGame->matriz, roundGame->lineCol);
                    free(command);
                    free(name);
                    return 0;
                }
            }
            printf(ANSI_BOLD CYAN("[-]")" Quantidade de jogadas até agora: %d.\n", roundGame->jogadas);
        }

    }while(op);
}

int loadGame(RoundGame* roundGame, char *name){

    char buffer;
    FILE *file;
    file = fopen(name, "r");
    if (file == NULL) {
        return 0;
    }



    int t;
    char k;
    fscanf(file, "%d%c", &roundGame->lineCol, &buffer);


    roundGame->matriz = createMatriz(roundGame->lineCol);

    for(int i =0; i<roundGame->lineCol; i++){
        for(int j=0; j<roundGame->lineCol; j++){
            fscanf(file, "%d%c", (*(roundGame->matriz+i)+j), &buffer);
        }
    }


    fscanf(file, "%d", &roundGame->jogadas);
    fclose(file);

    return 1;

}

int menuOptions(char*option, RoundGame* roundGame){
    if(!strcmp(option,"x")){
        printf(ANSI_BOLD WHITE("[*]")" Obrigado por jogar\n");
        if(roundGame->matriz!=NULL){
            liberaMatriz(roundGame->matriz, roundGame->lineCol);
        }
        return 0;
    }else if(!strcmp(option,"n")){
        roundGame->jogadas = 0;
        createBoard(roundGame);
        if(roundGame->matriz==NULL){
            return 1;
        }
        printBoard(roundGame->matriz, roundGame->lineCol);
        printf(ANSI_BOLD CYAN("[-]")" Tabuleiro ordenado!\n");


        if(!randBoard(roundGame->matriz, roundGame->lineCol)){
            return 1;
        }
        printf(ANSI_BOLD CYAN("[-]")" Tabuleiro embaralhado. Vamos começar o jogo!\n");

        return game(roundGame);
    }else if(!strcmp(option,"c")){
        if(roundGame->matriz == NULL){
            printf(ANSI_BOLD YELLOW("[!]")" Nenhum jogo em andamento.\n");
            return 1;
        }


        return game(roundGame);
    }else if(!strcmp(option,"s")){
        char *fileName = (char*)malloc(32*sizeof(char));
        int loaded=0;
        do{

            printf(ANSI_BOLD BLUE("[*]")" Digite o nome do arquivo: ");
            scanf("%9s", fileName);

            clearInputBuffer();
            if(!strcmp(fileName, "voltar")){
                return 1;
            }

            loaded = loadGame(roundGame, fileName);

            if (loaded == 0){
                printf(ANSI_BOLD RED("[!]")" Não foi possivel carregar o jogo, tente novamente!\n");
            }else{
                printf(ANSI_BOLD CYAN("[-]")" Arquivo \"%s\" carregado com sucesso!\n",fileName);
            }

        }while(loaded == 0);


        free(fileName);
        return game(roundGame);
    }else if(!strcmp(option,"a")){
        system("clear");


        printf("\n");
        for(int i =0 ; i<9; i++){
            printf(BG_WHITE("\u200A")"\u200A");
            fflush(stdout);  // Garante que a saída é atualizada imediatamente
            usleep(50000);  // Espera 500000 microssegundos (500ms)
        }
        printf("Tela de Ajuda ");
        for(int i =0 ; i<9; i++){
            printf(BG_WHITE("\u200A")"\u200A");
            fflush(stdout);  // Garante que a saída é atualizada imediatamente
            usleep(50000);  // Espera 500000 microssegundos (500ms)
        }

        printf("\n");
        printf("\n");

        printf(ANSI_BOLD BLUE("[*]") " Instruções de como jogar o Jogo do 15:\n");
        printf(ANSI_BOLD BLUE("[*]") " Esse jogo é um quebra-cabeça deslizante composto por n*n - 1 peças numeradas dispostas em um quadro de NxN, com um espaço vazio.\n");
        printf(ANSI_BOLD BLUE("[*]") " O objetivo do jogo é reorganizar as peças para que estejam em ordem crescente, movendo as peças adjacentes ao espaço vazio.\n");
        printf(ANSI_BOLD BLUE("[*]") " Você pode encontrar mais informações sobre como resolver o jogo aqui: https://pt.wikihow.com/Resolver-o-Jogo-do-15\n");

        printf("\n");
        printf("\n");

        printf(ANSI_BOLD BLUE("[*]") " Além disso, temos as seguintes opções do nosso jogo:\n\n");
        printf(ANSI_BOLD MAGENTA("[*]") " X - Sair do jogo (Função para sair do jogo)\n");
        printf(ANSI_BOLD MAGENTA("[*]") " N - Iniciar um novo jogo (Função de iniciar um novo jogo)\n");
        printf("\t"ANSI_BOLD BLUE("[-]") " Você podera salvar o jogo quando depois do novo jogo estiver embaralhado\n");
        printf(ANSI_BOLD MAGENTA("[*]") " C - Continuar o jogo atual\n");
        printf("\t"ANSI_BOLD BLUE("[-]") " C - Caso você tenha voltado para o menu inicial durante um jogo e quer continuar, você pode usar essa opção\n");
        printf(ANSI_BOLD MAGENTA("[*]") " S - Continuar um jogo salvo (Aqui você carrega um jogo já salvo)\n");
        printf(ANSI_BOLD MAGENTA("[*]") " A - Ajuda\n");

        printf("\n");
        printf("\n");

        printf(ANSI_BOLD BLUE("[*]") " Escolha a opção (digite “voltar” em qualquer lugar para voltar ao menu principal): ");
        scanf("%9s", option);

        clearInputBuffer();
        menuOptions(option,roundGame);
    }else if(!strcmp(option,"voltar")){
        return 1;
    }else{
        printf(ANSI_BOLD RED("[!]")" Opção invalida (Cheque o manual para ver como jogar)!\n");
        printf(ANSI_BOLD BLUE("[*]")" Escolha a opção (digite “voltar” em qualquer lugar para voltar ao menu principal): ");
        scanf("%9s", option);

        clearInputBuffer();
        menuOptions(option,roundGame);
    }

    return 1;
}
