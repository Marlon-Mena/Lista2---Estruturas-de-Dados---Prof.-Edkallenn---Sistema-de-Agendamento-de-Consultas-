/*
** Função : Teste do sistema de agendamento de consultas
** Autor : Marlon Mena Monteiro Alves - Ciência da Computação - Estruturas de Dados I - Terceiro Periodo
** Data : 19/06/2025
** Observações: Testa a fila estática (médico) e a fila dinâmica (enfermagem)
*/

#include <stdio.h>

// Protótipos
void inicializarFilaEstatica();
void inicializarFilaDinamica();
int enfileirarEstatica();
int desenfileirarEstatica();
void imprimirFilaEstatica();
void enfileirarDinamica();
int desenfileirarDinamica();
void imprimirFilaDinamica();

// Inclui os arquivos diretamente
#include "ED-lista2-questao02-fila_estatica.c"
#include "ED-lista2-questao02-fila_dinamica.c"

int main() {
    FilaEstatica filaMedico;
    FilaDinamica filaEnfermagem;
    
    inicializarFilaEstatica(&filaMedico);
    inicializarFilaDinamica(&filaEnfermagem);

    // Agendamentos com médico (máximo 5)
    enfileirarEstatica(&filaMedico, "Alice");
    enfileirarEstatica(&filaMedico, "Bob");
    enfileirarEstatica(&filaMedico, "Carlos");
    enfileirarEstatica(&filaMedico, "Diana");
    enfileirarEstatica(&filaMedico, "Eva");
    if (!enfileirarEstatica(&filaMedico, "Felipe"))
        printf("Fila de médico cheia!\n");
    
    imprimirFilaEstatica(&filaMedico);

    // Agendamentos com enfermagem (ilimitado)
    enfileirarDinamica(&filaEnfermagem, "Gabi");
    enfileirarDinamica(&filaEnfermagem, "Hugo");
    enfileirarDinamica(&filaEnfermagem, "Iara");
    
    imprimirFilaDinamica(&filaEnfermagem);

    return 0;
}
