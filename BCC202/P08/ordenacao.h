# ifndef ordenacao_h
# define ordenacao_h

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

// Manter como especificado
void MergeSort(Pessoa *vetor, int esquerda, int direita);

// Manter como especificado
void merge(Pessoa *vetor, int esquerda, int meio, int direita);

// Manter como especificado
Pessoa *alocaVetor(int n);

// Manter como especificado
void desalocaVetor(Pessoa **vetor);

# endif
