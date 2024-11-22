#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct matriz Matriz;

// Manter como especificado
Matriz* alocar(int n);
Matriz* desalocar(Matriz *matriz);
void le(Matriz *matriz);
double somaParte(Matriz *matriz, int *cont);

#endif // !MATRIZ_H