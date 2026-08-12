// ============================================================================
//         CASO PRÁTICO - REVERSÃO DE FILA UTILIZANDO PILHA AUXILIAR
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

// --- Estrutura do Dado ---
// Aqui nós criamos a nossa struct para guardar os dados de cada pessoa
typedef struct {
    char nome[30];
    int idade;
} Pessoa;

// --- Estrutura da Fila (FIFO) ---
// Aqui eu crio a struct para controlar a nossa fila tradicional
typedef struct {
    Pessoa dados[MAX]; // Vetor fixo para armazenar as pessoas na fila
    int inicio;        // Indica onde está a pessoa da frente (próxima a sair)
    int fim;           // Indica onde está a última vaga que foi ocupada
} Fila;

// --- Estrutura da Pilha (LIFO) ---
// Aqui eu crio a struct para controlar a nossa pilha de suporte
typedef struct {
    Pessoa dados[MAX]; // Vetor fixo para armazenar as pessoas empilhadas
    int topo;          // Indica onde está o elemento do topo (último que entrou)
} Pilha;

// --- Protótipos das Funções ---
void inicializarFila(Fila *f);
void inicializarPilha(Pilha *p);
void inserirFila(Fila *f, Pessoa p);
Pessoa removerFila(Fila *f);
void pushPilha(Pilha *p, Pessoa pes);
Pessoa popPilha(Pilha *p);
void exibirFila(Fila f);

// --- Função Principal (main) ---
int main() {
    // Aqui eu crio as nossas estruturas locais para o teste
    Fila filaOriginal;
    Fila filaInvertida;
    Pilha auxiliar;

    // Passo obrigatório: inicializar os índices de todas as estruturas
    inicializarFila(&filaOriginal);
    inicializarFila(&filaInvertida);
    inicializarPilha(&auxiliar);

    // Criamos um banco de dados fixo com 4 pessoas para testar a inversão
    Pessoa pessoas[] = {
        {"Carlos", 45}, 
        {"Joana", 62}, 
        {"Lucas", 30}, 
        {"Maria", 75}
    };

    // Aqui nós colocamos as 4 pessoas dentro da nossa fila original
    for (int i = 0; i < 4; i++) {
        inserirFila(&filaOriginal, pessoas[i]);
    }

    printf("--- ESTADO INICIAL DA FILA ORIGINAL (Ordem de Chegada) ---\n");
    exibirFila(filaOriginal);

    // ========================================================================
    // ETAPA 1: Esvaziar a fila jogando tudo para o topo da pilha
    // ========================================================================
    // O laço continua rodando enquanto o início da fila não alcançar o fim
    while (filaOriginal.inicio < filaOriginal.fim) {
        // Eu removo a pessoa da frente da fila e dou um push direto no topo da pilha
        Pessoa temporaria = removerFila(&filaOriginal);
        pushPilha(&auxiliar, temporaria);
    }

    // ========================================================================
    // ETAPA 2: Consumir o topo da pilha jogando para a nova fila invertida
    // ========================================================================
    // O laço continua rodando enquanto o topo da pilha for maior ou igual a 0 (não estiver vazia)
    while (auxiliar.topo >= 0) {
        // Eu retiro a pessoa do topo da pilha com o pop e insiro no fim da nova fila
        Pessoa temporaria = popPilha(&auxiliar);
        inserirFila(&filaInvertida, temporaria);
    }
    // ========================================================================

    printf("\n--- ESTADO FINAL DA FILA INVERTIDA (Ordem Inversa) ---\n");
    exibirFila(filaInvertida);

    return 0;
}

// --- Implementação das Funções Auxiliares ---

// Aqui nós zeramos os índices de início e fim da fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Aqui eu defino o topo da pilha como -1 para indicar que ela está vazia
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

// Função para colocar uma pessoa no final da fila (Enqueue)
void inserirFila(Fila *f, Pessoa p) {
    if (f->fim < MAX) {
        f->dados[f->fim] = p; // Grava o dado na vaga atual do fim
        f->fim++;             // Avança o indicador do fim para a próxima casa
    }
}

// Função para retirar a pessoa da frente da fila (Dequeue)
Pessoa removerFila(Fila *f) {
    Pessoa p = f->dados[f->inicio]; // Captura a pessoa que está no início
    f->inicio++;                    // Avança o início para a próxima pessoa da fila
    return p;                       // Devolve a pessoa capturada para quem chamou
}

// Função para colocar uma pessoa no topo da pilha (Push)
void pushPilha(Pilha *p, Pessoa pes) {
    if (p->topo < MAX - 1) {
        p->topo++;             // Avança o índice do topo primeiro
        p->dados[p->topo] = pes; // Salva a pessoa na nova posição do topo
    }
}

// Função para retirar a pessoa do topo da pilha (Pop)
Pessoa popPilha(Pilha *p) {
    Pessoa pes = p->dados[p->topo]; // Captura quem está no topo atual
    p->topo--;                      // Recua o índice do topo para desempilhar
    return pes;                     // Devolve a pessoa capturada
}

// Função para percorrer o vetor da fila do início ao fim e mostrar na tela
void exibirFila(Fila f) {
    for (int i = f.inicio; i < f.fim; i++) {
        printf("  Nome: %-8s | Idade: %d anos\n", f.dados[i].nome, f.dados[i].idade);
    }
}
