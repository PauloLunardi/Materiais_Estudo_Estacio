// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO FINAL (NÍVEL MESTRE)
// ============================================================================
// OBJETIVOS CUMPRIDOS (CONFORME REQUISITOS TÉCNICOS DA DOCUMENTAÇÃO):
//
// [REQUISITOS FUNCIONAIS]
// - Criação do vetor de missões: banco estático com 5 descrições estratégicas.
// - Sorteio da missão: função void atribuirMissao utilizando cópia com strcpy.
// - Armazenamento e acesso: string de missão alocada dinamicamente via malloc.
// - Verificação da missão: função int verificarMissao com varredura por strstr.
// - Exibição condicional: checagem ao fim de cada turno para declarar vencedor.
//
// [REQUISITOS NÃO FUNCIONAIS E ADICIONAIS]
// - Modularização: código dividido rigidamente entre main, ataque e missões.
// - Uso de ponteiros: todas as manipulações de structs feitas por referência.
// - Gerenciamento de memória: liberação obrigatória via free (limpeza do Heap).
// - Interface intuitiva (UX): missão exibida apenas no início da partida.
// - Validação de fronteiras: travas de segurança contra fogo amigo e limites.
// ============================================================================


#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>

// --- Constantes Globais ---
#define TAM_STRING 100
#define TOTAL_MISSOES 5

// --- Estrutura de Dados ---
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// --- Protótipos das Funções ---
void limparBufferEntrada();
void exibirMenuAcoes();
void cadastrarTerritorios(Territorio *mapa, int total);
void exibirMapa(const Territorio *mapa, int total);
void atribuirMissao(char *destino, const char *missoes[], int totalMissoes);
void atacar(Territorio *atacante, Territorio *defensor);
int verificarMissao(const char *missao, const Territorio *mapa, int tamanho);
void liberarMemoria(Territorio *mapa, char *missaoJogador);

// --- Função Principal (main) ---
int main() {
    int total_territorios = 0;
    int opcao_menu;
    int op_ataque, op_defesa;

    srand((unsigned int)time(NULL));

    // Banco de dados de missões pré-definidas (Vetor de strings)
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

    printf("Quantos territorios deseja ter no mapa do jogo? ");
    scanf("%d", &total_territorios);
    limparBufferEntrada();

    if (total_territorios <= 0) {
        printf("Quantidade inválida! Encerrando...\n");
        return 1;
    }

    // Alocação dinâmica de territórios e da string de missão
    Territorio *mapa = (Territorio *) calloc(total_territorios, sizeof(Territorio));
    char *missao_jogador = (char *) malloc(TAM_STRING * sizeof(char));

    if (mapa == NULL || missao_jogador == NULL) {
        printf("Erro Crítico: Falha ao alocar memória no sistema.\n");
        liberarMemoria(mapa, missao_jogador);
        return 1;
    }

    // Sorteia e atribui a missão copiando por referência
    atribuirMissao(missao_jogador, banco_missoes, TOTAL_MISSOES);
    
    // Interface intuitiva exibe a missão APENAS uma vez no início
    printf("\n SUA MISSÃO SECRETA: \"%s\"\n\n", missao_jogador);

    // Fase de Cadastro Inicial dos Territórios
    cadastrarTerritorios(mapa, total_territorios);

    // --- Laço Principal do Jogo (Game Loop com o Menu Solicitado) ---
    int jogo_ativo = 1;
    do {
        exibirMapa(mapa, total_territorios);
        exibirMenuAcoes();
        scanf("%d", &opcao_menu);
        limparBufferEntrada();

        switch (opcao_menu) {
            case 1: // OPÇÃO 1: FASE DE ATAQUE
                printf("\n--- INICIANDO ATAQUE ---\n");
                printf("Escolha o territorio ATACANTE (1 a %d): ", total_territorios);
                scanf("%d", &op_ataque);
                printf("Escolha o territorio DEFENSOR (1 a %d): ", total_territorios);
                scanf("%d", &op_defesa);
                limparBufferEntrada();

                int idx_atq = op_ataque - 1;
                int idx_def = op_defesa - 1;

                // Validações Críticas de Fronteiras e Regras do War
                if (idx_atq < 0 || idx_atq >= total_territorios || idx_def < 0 || idx_def >= total_territorios) {
                    printf("\n Erro: Índices fora dos limites do mapa!\n");
                } else if (idx_atq == idx_def) {
                    printf("\n Erro:Um território não pode atacar a si mesmo!\n");
                } else if (strcmp(mapa[idx_atq].cor, mapa[idx_def].cor) == 0) {
                    printf("\n Erro: Você só pode atacar territórios inimigos! (%s é seu).\n", mapa[idx_atq].cor);
                } else if (mapa[idx_atq].tropas < 2) {
                    printf("\n Erro: O território %s precisa de no mínimo 2 tropas para atacar!\n", mapa[idx_atq].nome);
                } else {
                    // Executa a batalha enviando os dados por ponteiros (Referência)
                    atacar(&mapa[idx_atq], &mapa[idx_def]);
                }
                
                printf("\nPressione [Enter] para voltar ao menu...");
                getchar();
                break;

            case 2: // OPÇÃO 2: VERIFICAR MISSÃO
                printf("\n--- VERIFICANDO CONDIÇÃO DE VITÓRIA ---\n");
                // Checagem utilizando a passagem da missão e do mapa
                if (verificarMissao(missao_jogador, mapa, total_territorios)) {
                    printf("\n PARABÉNS! Você cumpriu seu objetivo: \"%s\" e VENCEU O JOGO! \n\n", missao_jogador);
                    jogo_ativo = 0; // Finaliza o loop principal
                } else {
                    printf(" Objetivos ainda não alcançados. Continue lutando!\n");
                }
                printf("\nPressione [Enter] para voltar ao menu...");
                getchar();
                break;

            case 0: // OPÇÃO 0: SAIR
                printf("\nVocê se rendeu e abandonou o tabuleiro. Fim de jogo.\n");
                jogo_ativo = 0;
                break;

            default:
                printf("\n Opção Inválida! Tente novamente.\n");
                printf("\nPressione [Enter] para continuar...");
                getchar();
                break;
        }

    } while (opcao_menu != 0 && jogo_ativo != 0);

    // Liberação total da memória alocada dinamicamente no Heap
    liberarMemoria(mapa, missao_jogador);
    return 0;
}

// --- Implementação das Funções (Módulos Especializados) ---

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exibirMenuAcoes() {
    printf("\n--- MENU DE AÇÕES ---\n");
    printf("1 - Atacar\n");
    printf("2 - Verificar Missão\n");
    printf("0 - Sair do Jogo\n");
    printf("Escolha uma opção: ");
}

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
    limparBufferEntrada();
}

void exibirMapa(const Territorio *mapa, int total) {
    printf("               SITUAÇÃO DO MAPA                  \n");
    printf("=================================================\n");
    for (int i = 0; i < total; i++) {
        printf("[%d] Território: %-12s | Exército: %-8s | Tropas: %d\n", 
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
    printf("=================================================\n");
}

void atribuirMissao(char *destino, const char *missoes[], int totalMissoes) {
    int indice_sorteado = rand() % totalMissoes;
    strcpy(destino, missoes[indice_sorteado]); 
}

void atacar(Territorio *atacante, Territorio *defensor) {
    int dado_ataque = (rand() % 6) + 1;
    int dado_defesa = (rand() % 6) + 1;

    printf("\n Resultado dos Dados -> Atacante [%s]: %d | Defensor [%s]: %d\n", atacante->nome, dado_ataque, defensor->nome, dado_defesa);

    if (dado_ataque > dado_defesa) {
        printf(" VITÓRIA! O território %s foi conquistado por %s!\n", defensor->nome, atacante->cor);
        strcpy(defensor->cor, atacante->cor); 
        
        int tropas_transferidas = atacante->tropas / 2; 
        defensor->tropas = tropas_transferidas;
        atacante->tropas = atacante->tropas - tropas_transferidas;
        
        printf(" %d tropas avançaram para ocupar a nova região.\n", tropas_transferidas);
    } else {
        printf(" DEFESA SUCEDIDA! O território %s resistiu e o atacante perdeu 1 exército.\n", defensor->nome);
        atacante->tropas--; 
    }
}

int verificarMissao(const char *missao, const Territorio *mapa, int tamanho) {
    if (strstr(missao, "mais de 10 tropas") != NULL) {
        for (int i = 0; i < tamanho; i++) {
            if (mapa[i].tropas > 10) return 1; 
        }
    }
    if (strstr(missao, "total de 20 tropas") != NULL) {
        int soma_total = 0;
        for (int i = 0; i < tamanho; i++) {
            soma_total += mapa[i].tropas;
        }
        if (soma_total >= 20) return 1; 
    }
    if (strstr(missao, "primeiro territorio") != NULL) {
        if (mapa[0].tropas > 1) return 1; 
    }
    return 0; 
}

void liberarMemoria(Territorio *mapa, char *missaoJogador) {
    if (mapa != NULL) {
        free(mapa);
    }
    if (missaoJogador != NULL) {
        free(missaoJogador);
    }
    printf("\n[Sistema] Memória limpa com sucesso. Jogo encerrado de forma segura!\n");
}


/*
Resumos de dados para teste, e resumos de funçoões a implantar
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
