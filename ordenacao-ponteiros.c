#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "alg.h"

#define N 1000

typedef struct reg {
    int conteudo;
    struct reg *prox;
} No;

// Cria lista com N elementos aleatórios
No* criarListaAleatoria(int tamanho) {
    No *inicio = NULL, *fim = NULL;
    for (int i = 0; i < tamanho; i++) {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = rand() % 10000;
        novo->prox = NULL;

        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
    }
    return inicio;
}

// Copia a lista encadeada
No* copiarLista(No *origem) {
    if (!origem) return NULL;

    No *nova = NULL, *fim = NULL;
    while (origem) {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = origem->conteudo;
        novo->prox = NULL;

        if (!nova) {
            nova = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        origem = origem->prox;
    }
    return nova;
}

// Imprime os 20 primeiros e últimos elementos da lista
void printLista(No *lista, const char *titulo) {
    printf("\n%s\n", titulo);

    int i = 0, valores[N];
    while (lista && i < N) {
        valores[i++] = lista->conteudo;
        lista = lista->prox;
    }

    printf("Início: ");
    for (int j = 0; j < 20 && j < i; j++)
        printf("%d ", valores[j]);

    printf("\nFim:    ");
    for (int j = i - 20; j < i; j++)
        if (j >= 0) printf("%d ", valores[j]);

    printf("\n");
}

// Bubble Sort
void bubbleSortLista(No *inicio, int ordemCrescente) {
    if (!inicio) return;

    int trocado;
    do {
        trocado = 0;
        No *atual = inicio;
        while (atual->prox) {
            if ((ordemCrescente && atual->conteudo > atual->prox->conteudo) ||
                (!ordemCrescente && atual->conteudo < atual->prox->conteudo)) {
                int temp = atual->conteudo;
                atual->conteudo = atual->prox->conteudo;
                atual->prox->conteudo = temp;
                trocado = 1;
            }
            atual = atual->prox;
        }
    } while (trocado);
}

// Particiona a lista para o Quick Sort
No* particao(No *inicio, No *fim, No **novoInicio, No **novoFim, int ordemCrescente) {
    No *pivo = fim;
    No *anterior = NULL, *atual = inicio, *cauda = pivo;

    *novoInicio = NULL;
    *novoFim = NULL;

    while (atual != pivo) {
        No *proximo = atual->prox;
        int compara = ordemCrescente ? atual->conteudo < pivo->conteudo : atual->conteudo > pivo->conteudo;

        if (compara) {
            if (*novoInicio == NULL)
                *novoInicio = atual;
            anterior = atual;
        } else {
            if (anterior)
                anterior->prox = atual->prox;
            atual->prox = NULL;
            cauda->prox = atual;
            cauda = atual;
        }
        atual = proximo;
    }

    if (*novoInicio == NULL)
        *novoInicio = pivo;

    *novoFim = cauda;
    return pivo;
}

// Quick Sort recursivo
No* quickSortRec(No *inicio, No *fim, int ordemCrescente) {
    if (!inicio || inicio == fim)
        return inicio;

    No *novoInicio = NULL, *novoFim = NULL;
    No *pivo = particao(inicio, fim, &novoInicio, &novoFim, ordemCrescente);

    if (novoInicio != pivo) {
        No *tmp = novoInicio;
        while (tmp->prox != pivo) tmp = tmp->prox;
        tmp->prox = NULL;

        novoInicio = quickSortRec(novoInicio, tmp, ordemCrescente);

        tmp = novoInicio;
        while (tmp->prox) tmp = tmp->prox;
        tmp->prox = pivo;
    }

    pivo->prox = quickSortRec(pivo->prox, novoFim, ordemCrescente);

    return novoInicio;
}

// Inicia Quick Sort
No* quickSortLista(No *inicio, int ordemCrescente) {
    No *fim = inicio;
    while (fim && fim->prox) fim = fim->prox;
    return quickSortRec(inicio, fim, ordemCrescente);
}

// Libera memória
void liberarLista(No *lista) {
    while (lista) {
        No *tmp = lista;
        lista = lista->prox;
        free(tmp);
    }
}

int ordenacao_ponteiros() {
    srand(time(NULL));

    No *original = criarListaAleatoria(N);
    printLista(original, "Lista Original");

    No *lista1 = copiarLista(original);
    bubbleSortLista(lista1, 1);
    printLista(lista1, "[Bubble Sort - Crescente]");

    liberarLista(lista1);
    lista1 = copiarLista(original);
    bubbleSortLista(lista1, 0);
    printLista(lista1, "[Bubble Sort - Decrescente]");

    liberarLista(lista1);
    No *lista2 = copiarLista(original);
    lista2 = quickSortLista(lista2, 1);
    printLista(lista2, "[Quick Sort - Crescente]");

    liberarLista(lista2);
    lista2 = copiarLista(original);
    lista2 = quickSortLista(lista2, 0);
    printLista(lista2, "[Quick Sort - Decrescente]");

    liberarLista(original);
    liberarLista(lista2);
    return 0;
}
