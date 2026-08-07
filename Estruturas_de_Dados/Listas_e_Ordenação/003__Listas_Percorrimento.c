// ============================================================================
// ARQUIVO: percorrimento.c
// OBJETIVO: Demonstrar a navegacao/iteraçao completa pelos nos de uma lista.
// ============================================================================

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

// Funcao encarregada de caminhar do inicio ao fim da lista imprimindo os valores.
// Usa ponteiro simples (No *lista) por passagem de valor, pois esta rotina 
// realiza apenas operacoes de leitura e nao deve alterar a estrutura real na main.
void listarElementos(No *lista) {
    // Cria um ponteiro auxiliar para navegar sem perder o endereco do inicio da lista original
    No *ponteiro_atual = lista;
    
    // Verifica se a estrutura nao possui nenhum no cadastrado
    if (ponteiro_atual == NULL) {
        printf("A lista esta completamente vazia.\n");
        return;
    }
    
    printf("--- IMPRIMINDO ELEMENTOS DA LISTA ENCADEADA ---\n");
    
    // O laco continua executando enquanto o ponteiro apontar para um endereco valido
    while (ponteiro_atual != NULL) {
        // Exibe o dado armazenado no no corrente
        printf("No localizado no endereco %p -> Valor: %d\n", (void*)ponteiro_atual, ponteiro_atual->dado);
        
        // Caminha para o proximo elemento atualizando o ponteiro com o endereco salvo no campo proximo
        ponteiro_atual = ponteiro_atual->proximo;
    }
    
    printf("---------------- FIM DA LISTAGEM ----------------\n");
}

int main() {
    // Aloca e monta manualmente uma lista de teste com 3 elementos conectados
    No *n1 = (No *) malloc(sizeof(No));
    No *n2 = (No *) malloc(sizeof(No));
    No *n3 = (No *) malloc(sizeof(No));

    if (n1 == NULL || n2 == NULL || n3 == NULL) {
        return 1;
    }

    n1->dado = 5;
    n1->proximo = n2;
    
    n2->dado = 15;
    n2->proximo = n3;
    
    n3->dado = 25;
    n3->proximo = NULL; // Fim da linha da estrutura encadeada

    // Chama a funcao de percorrimento passando a cabeça da lista
    listarElementos(n1);

    // Libera a memoria alocada
    free(n1);
    free(n2);
    free(n3);

    return 0;
}
