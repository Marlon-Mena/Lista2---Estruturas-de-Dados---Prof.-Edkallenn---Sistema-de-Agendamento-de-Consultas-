/*
** Função : Fila Dinâmica para agendamento com Enfermagem (sem limite)
** Autor : Marlon Mena Monteiro Alves - Ciência da Computação - Estruturas de Dados I - Terceiro Periodo
** Data : 19/06/2025
** Observações: Implementação de fila dinâmica com ponteiros
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[50];
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} FilaDinamica;

void inicializarFilaDinamica(FilaDinamica *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void enfileirarDinamica(FilaDinamica *f, char nome[]) {
    No *novo = (No*) malloc(sizeof(No));
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    if (f->fim == NULL) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
}

int desenfileirarDinamica(FilaDinamica *f, char nome[]) {
    if (f->inicio == NULL) return 0;
    No *remover = f->inicio;
    strcpy(nome, remover->nome);
    f->inicio = remover->prox;
    if (f->inicio == NULL) f->fim = NULL;
    free(remover);
    return 1;
}

void imprimirFilaDinamica(FilaDinamica *f) {
    printf("Fila de enfermagem:\n");
    No *atual = f->inicio;
    while (atual != NULL) {
        printf(" - %s\n", atual->nome);
        atual = atual->prox;
    }
}
