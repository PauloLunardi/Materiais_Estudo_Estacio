// ============================================================================
// ARQUIVO: remocao.c
// OBJETIVO: Demonstrar a operacao de remocao de elementos de uma lista encadeada.
// ============================================================================

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

// Funcao que remove o primeiro elemento da lista e reorganiza a estrutura.
// Usa ponteiro para ponteiro (No **lista) para alterar o inicio real da lista na main.
void removerDoInicio(No **lista) {
    // 1. Verificacao de seguranca: Se a lista estiver vazia, nao ha o que remover
    if (*lista == NULL) {
        printf("Aviso: A lista ja esta vazia. Operacao cancelada.\n");
        return;
    }
    
    // 2. Cria um ponteiro auxiliar temporario para segurar o endereco do no que sera deletado
    No *noParaDeletar = *lista;
    
    // 3. Faz o ponteiro principal da lista avancar para o segundo elemento da sequencia
    *lista = (*lista)->proximo;
    
    // Armazena o valor apenas para exibir na mensagem de confirmacao
    int valorRemovido = noParaDeletar->dado;
    
    // 4. Libera fisicamente a memoria do no isolado para evitar Memory Leaks
    free(noParaDeletar);
    
    printf("Elemento %d removido do inicio da lista com sucesso.\n", valorRemovido);
}

int main() {
    // Cria de forma manual uma lista com 2 nos para testar a remocao
    No *primeiro = (No *) malloc(sizeof(No));
    No *segundo  = (No *) malloc(sizeof(No));

    if (primeiro == NULL || segundo == NULL) {
        return 1;
    }

    primeiro->dado = 100;
    primeiro->proximo = segundo;
    
    segundo->dado = 200;
    segundo->proximo = NULL;

    No *minha_lista = primeiro;

    // Executa as remocoes sucessivas
    removerDoInicio(&minha_lista); // Remove o 100, lista passa a comecar no 200
    removerDoInicio(&minha_lista); // Remove o 200, lista passa a ser NULL
    removerDoInicio(&minha_lista); // Tenta remover de lista vazia (Dispara o aviso)

    return 0;
}
