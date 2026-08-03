// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <string.h> // para strcspn

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define TOTAL_TERRITORIOS 5
#define TAM_STRING 50

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
typedef struct {
    char nome[30];      // Ex: "Argentina", "Egito"
    char cor[20]; // Cor do jogador que domina o território
    int tropas;     // Quantidade atual de exércitos no local
} Territorio;

// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
// Funções de setup e gerenciamento de memória:
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
// Função utilitária:

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {
    // --- Requisito: Declaração de vetor de structs ---
    // Cria um vetor (array) com capacidade para armazenar exatamente 5 territórios
    Territorio lista_territorios[TOTAL_TERRITORIOS];

     // --- Requisito: Entrada dos dados ---
    // Laço 'for' para guiar o usuário no preenchimento de cada uma das 5 fichas
    for (int i = 0; i < TOTAL_TERRITORIOS; i++) {
        // Usabilidade: Mensagens claras orientando o usuário
        printf("=== CADASTRO DO %dº TERRITÓRIO ===\n", i + 1);
        
        printf("Digite o nome do territorio: ");
        // Requisito técnico: scanf para ler strings de palavra única sem bugar o buffer
        scanf("%29s", lista_territorios[i].nome);
        
        printf("Digite a cor do exercito: ");
        scanf("%9s", lista_territorios[i].cor);
        
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &lista_territorios[i].tropas);
        
        printf("\n"); // Salta uma linha para organizar visualmente a entrada
    }

        printf("        TERRITÓRIOS REGISTRADOS NO JOGO      \n");
    // Percorre o vetor exibindo as informações de forma limpa e tabular
    for (int i = 0; i < TOTAL_TERRITORIOS; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("  -> Nome:   %s\n", lista_territorios[i].nome);
        printf("  -> Cor:    %s\n", lista_territorios[i].cor);
        printf("  -> Tropas: %d\n", lista_territorios[i].tropas);
        printf("---------------------------------------------\n");
    }
    
    return 0;

}

