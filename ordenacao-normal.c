#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "alg.h"

#define N 1000  // tamanho do vetor

// Função para trocar dois elementos utilizando seu endereço de memória (ponteiros)
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para imprimir os 20 primeiros e 20 últimos elementos dos vetores
// ao alterar a váriavel N, talvéz seja necessário alterar esta função
void printVetor(int vetor[], const char *titulo) {
    printf("\n%s\n", titulo);

    printf("Início: ");
    for (int i = 0; i < 20; i++) printf("%d ", vetor[i]);

    printf("\nFim:    ");
    for (int i = N - 20; i < N; i++) printf("%d ", vetor[i]);
    printf("\n");
}

// Algoritmo de ordenação Bubble Sort
// A variável ordemCrescente define se a ordenação é crescente (1) ou decrescente (0)
void bubbleSort(int vetor[], int ordemCrescente) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            // Comparação de acordo com a ordem desejada
            if ((ordemCrescente && vetor[j] > vetor[j + 1]) ||
                (!ordemCrescente && vetor[j] < vetor[j + 1])) {
                trocar(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

// Algoritmo Quick Sort com suporte para ordem crescente ou decrescente
void quickSort(int vetor[], int inicio, int fim, int ordemCrescente) {
    if (inicio >= fim) return; // condição de parada da recursividade

    int pivo = vetor[fim];  // Escolhe o último elemento como pivo
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        // Compara os elementos com o pivo dependendo da ordem
        if ((ordemCrescente && vetor[j] <= pivo) ||
            (!ordemCrescente && vetor[j] >= pivo)) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }
    trocar(&vetor[i + 1], &vetor[fim]);

    // Usa recursividade até que o vetor esteja ordenado
    quickSort(vetor, inicio, i, ordemCrescente);
    quickSort(vetor, i + 2, fim, ordemCrescente);
}

// Copia um vetor para outro para manter o original intacto
void copiarVetor(int origem[], int destino[]) {
    for (int i = 0; i < N; i++) {
        destino[i] = origem[i];
    }
}

int ordenacao_normal() {
    int original[N];
    int vetor1[N], vetor2[N];
    srand(time(NULL));

    // Preenche o vetor original com números aleatórios entre 0 e 9999
    for (int i = 0; i < N; i++) {
        original[i] = rand() % 10000;
    }

    printVetor(original, "Vetor Original");

    // Algoritmo 1: Bubble Sort Crescente
    copiarVetor(original, vetor1);
    bubbleSort(vetor1, 1);
    printVetor(vetor1, "[Bubble Sort - Crescente]");

    // Algoritmo 1: Bubble Sort Decrescente
    copiarVetor(original, vetor1);
    bubbleSort(vetor1, 0);
    printVetor(vetor1, "[Bubble Sort - Decrescente]");

    // Algoritmo 2: Quick Sort Crescente
    copiarVetor(original, vetor2);
    quickSort(vetor2, 0, N - 1, 1);
    printVetor(vetor2, "[Quick Sort - Crescente]");

    // Algoritmo 2: Quick Sort Decrescente
    copiarVetor(original, vetor2);
    quickSort(vetor2, 0, N - 1, 0);
    printVetor(vetor2, "[Quick Sort - Decrescente]");

    return 0;
}