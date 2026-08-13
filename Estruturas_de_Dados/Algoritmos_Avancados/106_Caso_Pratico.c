// ============================================================================
//         DETECTIVE QUEST - MAPA DA MANSÃO (ÁRVORE BINÁRIA EM C)
// ============================================================================
// OBJETIVOS CUMPRIDOS:
// - Definição da struct do nó da árvore com strings.
// - Criação manual do mapa da mansão usando alocação dinâmica.
// - Implementação dos percursos: Pré-ordem, Em ordem e Pós-ordem.
// - Liberação total e segura da memória RAM (Pós-ordem).
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Definição da Estrutura ---
// Aqui nós criamos a nossa struct para representar cada cômodo (nó) do mapa
struct No {
    char valor[50];       // Guarda o nome do cômodo (até 49 caracteres)
    struct No* esquerda;  // Ponteiro para o cômodo do lado esquerdo
    struct No* direita;   // Ponteiro para o cômodo do lado direito
};

// --- Protótipos das Funções ---
struct No* criarNo(char* valor);
void preOrdem(struct No* raiz);
void emOrdem(struct No* raiz);
void posOrdem(struct No* raiz);
void liberarArvore(struct No* raiz);

// --- Função Principal (main) ---
int main() {
    printf("=================================================\n");
    printf("         DETECTIVE QUEST - MAPA DA MANSÃO        \n");
    printf("=================================================\n");

    // Aqui nós usamos a alocação dinâmica para ligar os cômodos manualmente
    // Criamos a raiz principal: O Hall de Entrada
    struct No* raiz = criarNo("Hall de Entrada");
    
    // Conectamos os cômodos do primeiro nível abaixo da raiz
    raiz->esquerda = criarNo("Sala de Estar");
    raiz->direita = criarNo("Biblioteca");
    
    // Descemos mais um nível e colocamos o Quarto debaixo da Sala de Estar
    raiz->esquerda->esquerda = criarNo("Quarto");

    // --- Executando os Caminhamentos (Percursos) ---
    printf("\n🔍 [Exploracao] Caminho em Pre-ordem:\n -> ");
    preOrdem(raiz);
    printf("\n");

    printf("\n🔍 [Exploracao] Caminho Em ordem:\n -> ");
    emOrdem(raiz);
    printf("\n");

    printf("\n🔍 [Exploracao] Caminho em Pos-ordem:\n -> ");
    posOrdem(raiz);
    printf("\n");

    // Passo obrigatório: limpamos a memória do Heap antes de fechar o jogo
    liberarArvore(raiz);
    raiz = NULL;

    printf("\n[Sistema] Memória do mapa limpa. Investigação encerrada de forma segura!\n");
    return 0;
}

// --- Implementação das Funções ---

// Função que cria o nó, aloca a memória e zera os ponteiros dos filhos
struct No* criarNo(char* valor) {
    // Alocação Dinâmica: malloc pede espaço na memória para o tamanho exato do nosso nó
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    
    // Verificação de Segurança: garante que o computador conseguiu liberar a memória
    if (novo == NULL) {
        printf("Erro Crítico: Falha ao alocar memória para o cômodo.\n");
        exit(1);
    }
    
    // Aqui eu copio o texto do cômodo para dentro da struct e aterro os filhos com NULL
    strcpy(novo->valor, valor);
    novo->esquerda = NULL;
    novo->direita = NULL;
    
    return novo; // Devolve o nó prontinho
}

// 1. Pré-Ordem (Nó Atual -> Esquerda -> Direita)
// Aqui nós olhamos o cômodo atual primeiro e depois descemos para investigar os arredores
void preOrdem(struct No* raiz) {
    if (raiz != NULL) {
        printf("[%s] ", raiz->valor); // Visita o nó corrente
        preOrdem(raiz->esquerda);     // Desce recursivamente para a esquerda
        preOrdem(raiz->direita);      // Desce recursivamente para a direita
    }
}

// 2. Em Ordem (Esquerda -> Nó Atual -> Direita)
// Aqui o programa desce até o extremo esquerdo primeiro, processa e depois vai para a direita
void emOrdem(struct No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);     // Desce tudo para a esquerda primeiro
        printf("[%s] ", raiz->valor); // Só agora visita o nó corrente (Pai)
        emOrdem(raiz->direita);      // Desce para a direita
    }
}

// 3. Pós-Ordem (Esquerda -> Direita -> Nó Atual)
// Aqui nós deixamos o cômodo pai por último, investigando todas as extremidades antes
void posOrdem(struct No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);     // Desce para a esquerda
        posOrdem(raiz->direita);      // Desce para a direita
    }
}

// Função de Limpeza (Segurança contra Memory Leak)
// Aqui eu aplico a lógica de Pós-ordem para apagar primeiro os filhos e depois o pai
void liberarArvore(struct No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda); // Limpa as subárvores da esquerda
        liberarArvore(raiz->direita);  // Limpa as subárvores da direita
        free(raiz);                    // Dá free fisicamente na caixinha do pai
    }
}
