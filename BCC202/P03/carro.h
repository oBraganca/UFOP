#ifndef CARRO_H
#define CARRO_H

typedef struct funcionario Funcionario;
typedef struct carro Carro;

Funcionario* FuncionarioAloca();
void FuncionarioDesaloca(Funcionario**);
Carro* CarroAloca(int);
void CarroDesaloca(Carro**, int);
void le(Carro*, int);
int conta(Carro*, int, const int, const int);
void imprime(Carro*, int, const char*);

#endif // !CARRO_H