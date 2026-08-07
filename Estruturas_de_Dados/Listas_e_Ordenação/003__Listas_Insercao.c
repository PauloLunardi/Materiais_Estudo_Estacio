// ============================================================================
// ARQUIVO: insercao.c
// OBJETIVO: Demonstrar a operacao de insercao no inicio de uma lista encadeada.
// ============================================================================

#include <stdio.h>
#include <stdlib.h>

// Definicao da estrutura do no da lista
typedef struct No {
    int dado;
    struct No *proximo;
} No;

// Função especializada em inserir um novo elemento no inicio da lista.
// Usa ponteiro para ponteiro (No **lista) porque precisa modificar o endereco
// do ponteiro original que reside dentro da funcao main.
void inserirNoInicio(No **lista, int valor) {
    // 1. Alocacao de memoria dinamica no Heap para o novo elemento
    No *novoNo = (No *) malloc(sizeof(No));
    
    // Validacao de seguranca para garantir que o sistema operacional cedeu a memoria
    if (novoNo == NULL) {
        printf("Erro Crítico: Falha ao alocar memoria para o novo no.\n");
        return;
    }
    
    // 2. Preenchimento do campo de dados do no com o valor recebido
    novoNo->dado = valor;
    
    // 3. O ponteiro proximo do novo no recebe o endereco do antigo primeiro no da lista
    novoNo->proximo = *lista;
    
    // 4. O ponteiro da cabeça da lista e atualizado para apontar para o novo no
    *lista = novoNo;
    
    printf("Elemento %d inserido com sucesso no inicio da lista.\n", valor);
}

int main() {
    // Inicializa uma lista encadeada vazia apontando para NULL
    No *minha_lista = NULL;

    // Realiza tres insercoes consecutivas no topo da estrutura
    inserirNoInicio(&minha_lista, 10);
    inserirNoInicio(&minha_lista, 20);
    inserirNoInicio(&minha_lista, 30);

    // Limpeza da memoria antes de encerrar o programa (Boa pratica)
    No *atual = minha_lista;
    while (atual != NULL) {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    return 0;
}
