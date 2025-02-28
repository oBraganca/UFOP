#include "busca.h"

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);

// Partition function
int partition(int arr[], int low, int high) {

    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int* aloca(int n) {
    return (int*)malloc(n * sizeof(int));
}

void desaloca(int** arr) {
    free(*arr);
}

void le(int* arr, int n) {
    for (int i =0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
}

int buscaSequencial(int* arr, int n, int x) {
    for (int i =0; i<n; i++) {
        if (arr[i]==x) {
            return i+1;
        }
    }
    return n;
}

int buscaBinaria(int* arr, int n, int x) {
    int l = 0, r = n - 1;
    int k = 0;

    quickSort(arr, l, r);

    while (l <= r) {
        int mid = l + (r - l) / 2;
        k++;
        if (arr[mid] == x) {
            return k; // Retorna o número de comparações
        }
        if (arr[mid] > x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return k; // Retorna o número de comparações mesmo se não encontrar
}
