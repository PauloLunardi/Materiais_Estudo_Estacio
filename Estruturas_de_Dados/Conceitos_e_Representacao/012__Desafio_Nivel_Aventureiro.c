// ============================================================================
//         PROJETO WAR ESTRUTURADO - NÍVEL AVENTUREIRO (BATALHA)
// ============================================================================
// OBJETIVOS:
// - Alocação dinâmica do mapa com tamanho definido pelo usuário.
// - Sistema de ataque por ponteiros utilizando dados aleatórios (rand).
// - Atualização de donos (cores) e tropas pós-vitória/derrota.
// - Modularização completa e liberação de memória obrigatória.
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Necessária para inicializar o gerador de números aleatórios

// --- Estrutura de Dados ---
// Requisito funcional: Campos exatos solicitados pelo desafio
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// --- Protótipos das Funções (Modularização) ---
void cadastrarTerritorios(Territorio *mapa, int total);
void exibirMapa(const Territorio *mapa, int total);
void atacar(Territorio *atacante, Territorio *defensor);
void liberarMemoria(Territorio *mapa);

// --- Função Principal ---
int main() {
    int total_territorios;
    int op_ataque, op_defesa;

    // Inicializa a semente de números aleatórios com base no relógio do computador
    srand((unsigned int)time(NULL));

    printf("=============================================\n");
    printf("     BEM-VINDO AO WAR ESTRUTURADO (AVENTUREIRO)     \n");
    printf("=============================================\n");

    // Requisito Técnico: Alocação com tamanho informado pelo usuário
    printf("Quantos territorios deseja ter no mapa do jogo? ");
    if (scanf("%d", &total_territorios) != 1 || total_territorios <= 0) {
        printf("Quantidade inválida!\n");
        return 1;
    }

    // Alocação dinâmica utilizando calloc (garante memória limpa e zerada)
    Territorio *mapa = (Territorio *) calloc(total_territorios, sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro Fatal: Memória insuficiente para carregar o mapa.\n");
        return 1;
    }

    // 1. Fase de Cadastro Dinâmico
    cadastrarTerritorios(mapa, total_territorios);

    // 2. Loop de Interatividade de Ataques
    int continuar = 1;
    while (continuar) {
        exibirMapa(mapa, total_territorios);

        printf("\n--- FASE DE ATAQUE ---\n");
        printf("Escolha o indice do territorio ATACANTE (1 a %d) ou 0 para sair: ", total_territorios);
        scanf("%d", &op_ataque);

        if (op_ataque == 0) {
            continuar = 0;
            break;
        }

        printf("Escolha o indice do territorio DEFENSOR (1 a %d): ", total_territorios);
        scanf("%d", &op_defesa);

        // Validações Críticas de Entrada
        if (op_ataque < 1 || op_ataque > total_territorios || op_defesa < 1 || op_defesa > total_territorios) {
            printf("\n❌ Erro: Índices fora do limite do mapa! Tente novamente.\n\n");
            continue;
        }

        if (op_ataque == op_defesa) {
            printf("\n❌ Erro: Um território não pode atacar a si mesmo!\n\n");
            continue;
        }

        // Ajusta os índices informados (1 a N) para o padrão do vetor em C (0 a N-1)
        Territorio *atacante = &mapa[op_ataque - 1];
        Territorio *defensor = &mapa[op_defesa - 1];

        // Requisito Técnico: Validar para não atacar território da própria cor
        if (strcmp(atacante->cor, defensor->cor) == 0) {
            printf("\n❌ Erro de Diplomacia: Você não pode atacar um território do seu próprio exército (%s)!\n\n", atacante->cor);
            continue;
        }

        // Regra de Negócio: Precisa de pelo menos 2 tropas para poder atacar (1 para ficar protegendo)
        if (atacante->tropas < 2) {
            printf("\n❌ Erro Militar: O território %s precisa de pelo menos 2 tropas para iniciar um ataque!\n\n", atacante->nome);
            continue;
        }

        // Executa a batalha passando os ponteiros dos territórios escolhidos
        atacar(atacante, defensor);
    }

    // Requisito Não Funcional: Liberação manual de toda a memória alocada
    liberarMemoria(mapa);

    printf("\nObrigado por jogar o War Estruturado!\n");
    return 0;
}

// --- Implementação das Funções (Modularização por Ponteiros) ---

// Preenche os dados do mapa dinâmico via ponteiro
void cadastrarTerritorios(Territorio *mapa, int total) {
    printf("\n--- INICIANDO CADASTRO DO MAPA ---\n");
    for (int i = 0; i < total; i++) {
        printf("Território %d:\n", i + 1);
        
        printf("  Nome: ");
        scanf("%29s", mapa[i].nome);
        
        printf("  Cor do exército dominante: ");
        scanf("%9s", mapa[i].cor);
        
        printf("  Quantidade inicial de tropas: ");
        scanf("%d", &mapa[i].tropas);
        printf("\n");
    }
}

// Exibe o status atual de todas as posições do vetor dinâmico
// Usa 'const' para proteção pois esta função deve apenas ler os dados
void exibirMapa(const Territorio *mapa, int total) {
    printf("\n=============================================\n");
    printf("          MAPA ATUAL DO MUNDO WAR            \n");
    printf("=============================================\n");
    for (int i = 0; i < total; i++) {
        printf("[%d] Território: %-12s | Exército: %-8s | Tropas: %d\n", 
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
    printf("=============================================\n");
}

// Função de Lógica Principal: Simula os dados e altera a memória à distância
void atacar(Territorio *atacante, Territorio *defensor) {
    printf("\n⚔️  %s (%s) ATACA %s (%s)! ⚔️\n", atacante->nome, atacante->cor, defensor->nome, defensor->cor);

    // Rola dados de 1 a 6 usando rand()
    int dado_ataque = (rand() % 6) + 1;
    int dado_defesa = (rand() % 6) + 1;

    printf("🎲 Dado do Atacante: %d\n", dado_ataque);
    printf("🎲 Dado do Defensor: %d\n", dado_defesa);

    // Se o atacante tirar um dado MAIOR que o defensor, ele VENCE a batalha
    if (dado_ataque > dado_defesa) {
        printf("🎉 VITÓRIA! O território %s conquistou %s!\n", atacante->nome, defensor->nome);
        
        // Transferência de propriedades exigida nas Instruções Detalhadas:
        // 1. Muda o dono do território defensor (copia a cor do atacante)
        strcpy(defensor->cor, atacante->cor);
        
        // 2. Calcula metade das tropas do atacante para mover
        int tropas_transferidas = atacante->tropas / 2;
        
        // 3. Atualiza os campos na memória através dos ponteiros
        defensor->tropas = tropas_transferidas;
        atacante->tropas = atacante->tropas - tropas_transferidas;
        
        printf("🚚 %d tropas foram deslocadas para ocupar o novo território.\n", tropas_transferidas);
    } 
    // Em caso de empate ou dado do defensor maior, o atacante PERDE
    else {
        printf("🛡️  DEFESA SUCEDIDA! O território %s resistiu ao ataque.\n", defensor->nome);
        
        // Reduz uma tropa do atacante
        atacante->tropas--;
        printf("💥 O atacante perdeu 1 tropa. Restam %d tropas em %s.\n", atacante->tropas, atacante->nome);
    }
    printf("\n");
}

// Desaloca a memória usada e limpa o ponteiro original
void liberarMemoria(Territorio *mapa) {
    if (mapa != NULL) {
        free(mapa);
        printf("\n[Sistema] Memória alocada dinamicamente liberada com sucesso.\n");
    }
}
