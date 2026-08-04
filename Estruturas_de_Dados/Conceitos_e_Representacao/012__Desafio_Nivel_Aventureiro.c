// ============================================================================
//         PROJETO WAR ESTRUTURADO - NÍVEL AVENTUREIRO (BATALHA)
// ============================================================================
// OBJETIVOS:
// - Alocação dinâmica do mapa com tamanho definido pelo usuário.
// - Sistema de ataque por ponteiros utilizando dados aleatórios (rand).
// - Atualização de donos (cores) e tropas pós-vitória/derrota.
// - Modularização completa e liberação de memória obrigatória.
// ============================================================================


// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // para strcspn
#include <time.h>

// --- Constantes Globais ---
#define TAM_STRING 50

// --- Estrutura de Dados ---
typedef struct {
    char nome[30];      // Ex: "Argentina", "Egito"
    char cor[20]; // Cor do jogador que domina o território
    int tropas;     // Quantidade atual de exércitos no local
} Territorio;

// --- Protótipos das Funções ---
// Avisa ao compilador que essas funções existem lá embaixo
void cadastrarTerritorios(Territorio *mapa, int total);
void exibirMapa(Territorio *mapa, int total);
void atacar(Territorio *atacante, Territorio *defensor);
void liberarMemoria(Territorio *mapa);

// --- Função Principal (main) ---
int main() {
    int total_territorios = 0;

    // Inicializa o gerador de números aleatórios para a função atacar
    srand((unsigned int)time(NULL));
    
    // Pergunta o tamanho do mapa
    printf("Quantos territorios deseja terno mapa? ");
    scanf("%d", &total_territorios);

    // Solicita a memória dinamicamente
    Territorio *mapa = (Territorio *) calloc(total_territorios, sizeof(Territorio));

    // validaçao de segurança: se não houver memoria o ponteiro vira NULL
    if (mapa == NULL){
        printf("Erro: Memória Cheia!\n");
        return 1;
    }

    // Executa as funções do war
    cadastrarTerritorios(mapa, total_territorios);
    exibirMapa(mapa, total_territorios);

    // --- EXEMPLO DE ATAQUE SIMULADO ---
    // Se houver pelo menos 2 territórios, simula o território 1 atacando o território 2
    if (total_territorios >= 2) {
        printf("\n--- SIMULAÇÃO DE ATAQUE TESTE (Território 1 vs Território 2) ---\n");
        atacar(&mapa[0], &mapa[1]);
        
        printf("\n--- MAPA ATUALIZADO PÓS-ATAQUE ---\n");
        exibirMapa(mapa, total_territorios);
    }

    // Limpa a memória antes de fechar o programa
    liberarMemoria(mapa);

    return 0;
}


// --- Requisito: Entrada dos dados ---
// --- Cadastro com Laço ---
void cadastrarTerritorios(Territorio *mapa, int total) {
    // Laço 'for' para preencher dinamicamente o vetor
    for (int i = 0; i < total; i++) {
        // Usabilidade: Mensagens claras orientando o usuário
        printf("=== CADASTRO DO %dº TERRITÓRIO ===\n", i + 1);
        
        printf("Digite o nome do Territorio: ");
        // Requisito técnico: scanf para ler strings de palavra única sem bugar o buffer
        scanf("%29s", mapa[i].nome); // Sem '&' porque 'nome' já é um array de char
        
        printf("Digite a cor do Exercito: ");
        scanf("%9s", mapa[i].cor);
        
        printf("Digite a quantidade de Tropas: ");
        scanf("%d", &mapa[i].tropas); // Com '&' porque 'tropas' é um int comum
        
        printf("\n"); // Salta uma linha para organizar visualmente a entrada
    }

        printf("        TERRITÓRIOS REGISTRADOS NO JOGO      \n");
    // Percorre o vetor exibindo as informações de forma limpa e tabular
    for (int i = 0; i < total; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("  -> Nome:   %s\n", mapa[i].nome);
        printf("  -> Cor:    %s\n", mapa[i].cor);
        printf("  -> Tropas: %d\n", mapa[i].tropas);
        printf("---------------------------------------------\n");
    }  

}

void atacar (Territorio *atacante, Territorio *defensor) {
    // joga dados (numeros de 1 a 6)
    int dado_ataque = (rand() % 6) + 1;
    int dado_defesa = (rand() % 6) + 1;

    if (dado_ataque > dado_defesa) {
        printf("Vitória do Atacante!\n");

        // O defensor passa a ser da cor do atacante
        strcpy(defensor->cor, atacante->cor);
    
        // Calcula a metade da tropa para mover
        int tropas_movidas = atacante->tropas / 2;
    
        defensor->tropas = tropas_movidas;
        atacante->tropas = atacante->tropas - tropas_movidas;

    } else {
        printf("Defesa Resistiu!\n");
        atacante->tropas--; // atacante perde 1 da tropa por falhar
    }
}

void exibirMapa(Territorio *mapa, int total) {
    printf("        Territórios Registrados no Jogo           \n");
    printf("--------------------------------------------------\n");
    // Percorre o vetor dinâmico exibindo as infomações corrigidas
    for (int i = 0; i < total; i++) {
        printf("Territorio %d:\n", i + 1);
        printf(" -> Nome: %s\n", mapa[i].nome);
        printf(" -> Cor: %s\n", mapa[i].cor);
        printf(" -> Tropas: %d\n", mapa[i].tropas);
        printf("---------------------------------------------\n");
    }
}

void liberarMemoria(Territorio *mapa) {
    // só aplica o free se o ponteiro realmente existir
    if(mapa != NULL) {
        free(mapa);
        printf("Memória Limpa com sucesso!");
    }
}    

