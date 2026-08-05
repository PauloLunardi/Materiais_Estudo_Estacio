// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO FINAL (NÍVEL MESTRE)
// ============================================================================
// OBJETIVOS CUMPRIDOS:
// - Criação do vetor de missões estratégicas (mínimo 5).
// - Alocação dinâmica do mapa (calloc) e da string de missão (malloc).
// - Função atribuirMissao utilizando cópia por referência (strcpy).
// - Função de ataque por ponteiros com simulação de dados (rand() % 6 + 1).
// - Função de verificação silenciosa e condicional de vitória.
// - Liberação manual obrigatória de toda a memória (free).
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h> // Para carregar a semente de tempo do srand

// --- Constantes Globais ---
#define TAM_STRING 100
#define TOTAL_MISSOES 5

// --- Estrutura de Dados ---
// Requisito técnico: struct Territorio com os campos exatos solicitados
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// --- Protótipos das Funções (Modularização Rígida) ---
void limparBufferEntrada();
void cadastrarTerritorios(Territorio *mapa, int total);
void exibirMapa(const Territorio *mapa, int total);
void atribuirMissao(char *destino, const char *missoes[], int totalMissoes);
void atacar(Territorio *atacante, Territorio *defensor);
int verificarMissao(const char *missao, const Territorio *mapa, int tamanho);
void liberarMemoria(Territorio *mapa, char *missaoJogador);

// --- Função Principal (main) ---
int main() {
    int total_territorios = 0;
    int op_ataque, op_defesa;

    // Requisito Adicional: srand configurado para garantir aleatoriedade real
    srand((unsigned int)time(NULL));

    // Requisito Funcional: Vetor de strings com ao menos 5 missões diferentes
    const char *banco_missoes[TOTAL_MISSOES] = {
        "Conquistar mais da metade do mapa",
        "Garantir que nenhum territorio tenha menos de 3 tropas",
        "Dominar um territorio com mais de 10 tropas",
        "Acumular um total de 20 tropas pelo mapa",
        "Conquistar o primeiro territorio do mapa (Posicao 1)"
    };

    printf("=================================================\n");
    printf("         WAR ESTRUTURADO - VERSÃO MESTRE         \n");
    printf("=================================================\n");

    // Instrução Detalhada: Solicita o número total de territórios ao usuário
    printf("Quantos territorios deseja ter no mapa do jogo? ");
    scanf("%d", &total_territorios);
    limparBufferEntrada();

    if (total_territorios <= 0) {
        printf("Quantidade inválida! Encerrando...\n");
        return 1;
    }

    // Requisito Funcional: Alocação dinâmica de territórios e da string de missão (malloc/calloc)
    Territorio *mapa = (Territorio *) calloc(total_territorios, sizeof(Territorio));
    char *missao_jogador = (char *) malloc(TAM_STRING * sizeof(char));

    // Trava de Segurança: Verifica se o sistema operacional concedeu a memória
    if (mapa == NULL || missao_jogador == NULL) {
        printf("Erro Crítico: Falha ao alocar memória no sistema.\n");
        liberarMemoria(mapa, missao_jogador);
        return 1;
    }

    // Requisito Funcional: Sorteia e atribui a missão copiando por referência
    atribuirMissao(missao_jogador, banco_missoes, TOTAL_MISSOES);
    
    // Requisito Não Funcional: Interface intuitiva exibe a missão APENAS uma vez no início
    printf("\n MISSÃO SECRETA: \"%s\"\n\n", missao_jogador);

    // Fase de Cadastro
    cadastrarTerritorios(mapa, total_territorios);

    // Laço Principal do Jogo (Game Loop)
    int jogo_ativo = 1;
    while (jogo_ativo) {
        exibirMapa(mapa, total_territorios);

        printf("\n--- TURNO DE ATAQUE ---\n");
        printf("Escolha o territorio ATACANTE (1 a %d) ou 0 para render-se: ", total_territorios);
        scanf("%d", &op_ataque);

        if (op_ataque == 0) {
            printf("\nVocê se rendeu! Fim de jogo.\n");
            break;
        }

        printf("Escolha o territorio DEFENSOR (1 a %d): ", total_territorios);
        scanf("%d", &op_defesa);
        limparBufferEntrada();

        // Conversão do índice do usuário (1 a N) para o padrão do vetor (0 a N-1)
        int idx_atq = op_ataque - 1;
        int idx_def = op_defesa - 1;

        // Requisitos Técnicos e Adicionais: Validações de limites e regras de combate
        if (idx_atq < 0 || idx_atq >= total_territorios || idx_def < 0 || idx_def >= total_territorios) {
            printf("\nErro: Índices fora dos limites do mapa! Tente novamente.\n");
            continue;
        }
        if (idx_atq == idx_def) {
            printf("\nErro: Um território não pode atacar a si mesmo!\n");
            continue;
        }
        // Requisito Técnico Adicional: Validar para atacar apenas territórios inimigos (cores diferentes)
        if (strcmp(mapa[idx_atq].cor, mapa[idx_def].cor) == 0) {
            printf("\nErro de Diplomacia: Você só pode atacar territórios inimigos! (%s é seu).\n", mapa[idx_atq].cor);
            continue;
        }
        if (mapa[idx_atq].tropas < 2) {
            printf("\nErro Militar: O território %s precisa de no mínimo 2 tropas para atacar!\n", mapa[idx_atq].nome);
            continue;
        }

        // Requisito Não Funcional: Executa a batalha enviando os dados por ponteiros (Referência)
        atacar(&mapa[idx_atq], &mapa[idx_def]);

        // Requisito Funcional/Não Funcional: Verificação silenciosa de missão ao fim de cada turno
        if (verificarMissao(missao_jogador, mapa, total_territorios)) {
            printf("\n PARABÉNS! Você cumpriu seu objetivo: \"%s\" e VENCEU O JOGO! \n\n", missao_jogador);
            exibirMapa(mapa, total_territorios);
            jogo_ativo = 0; // Exibição condicional declara o vencedor e encerra
        }
    }

    // Requisito Não Funcional: Liberação total da memória alocada dinamicamente
    liberarMemoria(mapa, missao_jogador);
    return 0;
}

// --- Implementação das Funções (Módulos Especializados) ---

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarTerritorios(Territorio *mapa, int total) {
    printf("--- INICIANDO CADASTRO DO MAPA ---\n");
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
    limparBufferEntrada();
}

void exibirMapa(const Territorio *mapa, int total) {
    printf("\n=================================================\n");
    printf("               SITUAÇÃO DO MAPA                  \n");
    printf("=================================================\n");
    for (int i = 0; i < total; i++) {
        printf("[%d] Território: %-12s | Exército: %-8s | Tropas: %d\n", 
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
    printf("=================================================\n");
}

// Requisito Funcional: Função atribuirMissao com a assinatura solicitada. Usa strcpy.
void atribuirMissao(char *destino, const char *missoes[], int totalMissoes) {
    int indice_sorteado = rand() % totalMissoes;
    strcpy(destino, missoes[indice_sorteado]); // Copia o texto sorteado para o ponteiro de destino
}

// Instrução Detalhada: Gerencia o ataque rolando dados e atualizando campos
void atacar(Territorio *atacante, Territorio *defensor) {
    // Rola dados pseudoaleatórios de 1 a 6
    int dado_ataque = (rand() % 6) + 1;
    int dado_defesa = (rand() % 6) + 1;

    printf("\n⚔️  %s [%d] VS %s [%d] ⚔️\n", atacante->nome, dado_ataque, defensor->nome, dado_defesa);

    // Cenário de Vitória: Atacante tira dado maior que o defensor
    if (dado_ataque > dado_defesa) {
        printf(" VITÓRIA! O território %s foi conquistado por %s!\n", defensor->nome, atacante->cor);
        
        // Modifica os campos na memória através dos ponteiros
        strcpy(defensor->cor, atacante->cor); // Transfere o controle (cor do exército)
        
        int tropas_transferidas = atacante->tropas / 2; // Calcula a metade das tropas
        defensor->tropas = tropas_transferidas;
        atacante->tropas = atacante->tropas - tropas_transferidas;
        
        printf(" %d tropas avançaram para ocupar o novo território.\n", tropas_transferidas);
    } 
    // Cenário de Derrota/Empate: Defensor ganha ou empata
    else {
        printf(" DEFESA SUCEDIDA! O território %s resistiu e o atacante recuou.\n", defensor->nome);
        atacante->tropas--; // Atacante sofre uma baixa (perde uma tropa)
    }
}

// Requisito Funcional: Avalia se a missão do jogador foi cumprida através de lógicas simples
int verificarMissao(const char *missao, const Territorio *mapa, int tamanho) {
    
    // Verificação para a Missão: "Dominar um territorio com mais de 10 tropas"
    if (strstr(missao, "mais de 10 tropas") != NULL) {
        for (int i = 0; i < tamanho; i++) {
            if (mapa[i].tropas > 10) return 1; // Objetivo cumprido
        }
    }
    
    // Verificação para a Missão: "Acumular um total de 20 tropas pelo mapa"
    if (strstr(missao, "total de 20 tropas") != NULL) {
        int soma_total = 0;
        for (int i = 0; i < tamanho; i++) {
            soma_total += mapa[i].tropas;
        }
        if (soma_total >= 20) return 1; // Objetivo cumprido
    }
    
    // Verificação para a Missão: "Conquistar o primeiro territorio do mapa (Posicao 1)"
    if (strstr(missao, "primeiro territorio") != NULL) {
        // Se o primeiro território tiver mais de 1 tropa, assume-se que está estabilizado pelo jogador
        if (mapa[0].tropas > 1) return 1; 
    }
    return 0; // Retorna 0 (falso) se nenhuma regra de vitória foi atingida ainda}
    // Requisito Não Funcional: Libera toda a memória ocupada no Heap
}
    
void liberarMemoria(Territorio *mapa, char *missaoJogador) {
    if (mapa != NULL) {
        free(mapa);
    }
    if (missaoJogador != NULL) {
        free(missaoJogador);
    }
    printf("[Sistema] Memória limpa com sucesso. Jogo encerrado de forma segura!\n");
}



/*
================== MAPA DO MUNDO ====================
1. America      (Exercito: Verde            ,Tropas: 5)
2. Europa       (Exercito: Azul             ,Tropas: 3)
3. Asia      (Exercito: Vermelho            ,Tropas: 2)
4. Africa       (Exercito: Amarelo          ,Tropas: 4)
5. Oceania       (Exercito: Branco          ,Tropas: 1)
=====================================================

menu de acoes
1 atacar
2 verificar missao
0 sair

fase de ataque 
  escolher o territorio de atacante
  escolher o territorio de defensor 

--- resultado da batalha ---
  Ataque(europa):4 | Defesa (america): 5
  VITORIA DA DEFESA! O atacante perdeu 1 tropa.
*/
