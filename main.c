#include <stdio.h>
#include "alg.h"

int main(void) {
    int opt;
    printf("Digite o algoritmo que deseja testar:\n");
    printf("1 - Algoritmo vetor\n");
    printf("2 - Algoritmo ponteiro\n");
    scanf("%d", &opt);
    if (opt == 1) {
        ordenacao_normal();
    } else if (opt == 2) {
        ordenacao_ponteiros();
    } else {
        printf("Opção inválida\n");
    }
    return 0;
}