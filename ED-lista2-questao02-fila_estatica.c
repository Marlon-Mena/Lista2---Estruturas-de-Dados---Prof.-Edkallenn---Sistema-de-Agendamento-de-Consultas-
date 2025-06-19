/*
** Função : Fila Estática para agendamento com Médico (máximo 5 pacientes)
** Autor : Marlon Mena Monteiro Alves - Ciência da Computação - Estruturas de Dados I - Terceiro Periodo
** Data : 19/06/2025
** Observações: Implementa uma fila circular estática simples
*/

#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    char nome[50];
} Paciente;

typedef struct {
    Paciente fila[MAX];
    int inicio;
    int fim;
    int tamanho;
} FilaEstatica;

void inicializarFilaEstatica(FilaEstatica *f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

int enfileirarEstatica(FilaEstatica *f, char nome[]) {
    if (f->tamanho == MAX) return 0; 
    strcpy(f->fila[f->fim].nome, nome);
    f->fim = (f->fim + 1) % MAX;
    f->tamanho++;
    return 1;
}

int desenfileirarEstatica(FilaEstatica *f, char nome[]) {
    if (f->tamanho == 0) return 0; 
    strcpy(nome, f->fila[f->inicio].nome);
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return 1;
}

void imprimirFilaEstatica(FilaEstatica *f) {
    printf("Fila de médicos (%d pacientes):\n", f->tamanho);
    for (int i = 0; i < f->tamanho; i++) {
        int idx = (f->inicio + i) % MAX;
        printf(" - %s\n", f->fila[idx].nome);
    }
}
