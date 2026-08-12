// ============================================================================
//     DESAFIO MESTRE - GERENCIADOR AVANÇADO DO TETRIS STACK (FILA X PILHA)
// ============================================================================

// ============================================================================
// PARTE 1: DEFINIÇÃO DE ESTRUTURAS, VARIÁVEIS GLOBAIS E LAÇO DO MENU (MAIN)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Para a semente do rand() mudar a cada jogo

// Definimos as capacidades máximas exigidas pelo desafio mestre
#define FILA_MAX 5
#define PILHA_MAX 3

// --- Estrutura da Peça
// Aqui nós criamos a nossa struct para armazenar os atributos de cada peca
typedef struct {
    char nome; // Guarda o formato da peca: 'I', 'O', 'T', 'L'
    int id;    // Numero de identificacao unico e sequencial
} Peca;

// --- Estrutura da Fila Circular
typedef struct {
    Peca itens[FILA_MAX]; // Vetor fixo com capacidade para 5 pecas
    int inicio;           // Indica a peca da frente (FIFO)
    int fim;              // Indica a ultima peca que entrou
    int total;            // Contador de quantas pecas estao na fila atualmente
} FilaCircular;

// --- Estrutura da Pilha Linear
typedef struct {
    Peca itens[PILHA_MAX]; // Vetor fixo com capacidade para 3 pecas
    int topo;              // Indica o topo da reserva (LIFO)
} PilhaReserva;

// --- Variáveis Globais de Controle
FilaCircular fila;
PilhaReserva pilha;
int contador_id = 0; // Controla a geracao sequencial de IDs unicos

// --- Protótipos das Funções Modulares
void limparBuffer();
void inicializarEstruturas();
Peca gerarPeca();
void exibirPainel();

// Funções de Comando do Jogo
void jogarPecaFrente();
void enviarFilaParaPilha();
void usarPecaReserva();
void trocarPecaAtual();
void trocaMultiplaBloco();

// --- Função Principal (main)
int main() {
    int comando;

    // Inicializa o gerador de numeros aleatorios com base no tempo
    srand((unsigned int)time(NULL));

    // Passo obrigatorio: configura os indices iniciais da fila e da pilha
    inicializarEstruturas();

    // Requisito: O jogo comeca populando e enchendo a fila automaticamente com 5 pecas
    for (int i = 0; i < FILA_MAX; i++) {
        fila.itens[i] = gerarPeca();
        fila.total++;
    }
    fila.fim = FILA_MAX - 1; // Ajusta o ponteiro de fim na ultima posicao (indice 4)

    printf("=================================================\n");
    printf("         TETRIS STACK - INTERFACE MESTRE         \n");
    printf("=================================================\n");

    // Laço principal do jogo (Game Loop)
    do {
        // Toda vez que o turno vira, o painel redesenha a fila e a pilha na tela
        exibirPainel();

        printf("\nOpcoes disponiveis:\n");
        printf("1 - Jogar peca da frente da fila\n");
        printf("2 - Enviar peca da fila para a pilha de reserva\n");
        printf("3 - Usar peca da pilha de reserva\n");
        printf("4 - Trocar peca da frente da fila com o topo da pilha\n");
        printf("5 - Trocar os 3 primeiros da fila com as 3 pecas da pilha\n");
        printf("0 - Sair\n");
        printf("Escolha uma acao: ");
        scanf("%d", &comando);
        limparBuffer();

        // O switch chama o modulo correspondente ao clique do jogador
        switch(comando) {
            case 1: jogarPecaFrente(); break;
            case 2: enviarFilaParaPilha(); break;
            case 3: usarPecaReserva(); break;
            case 4: trocarPecaAtual(); break;
            case 5: trocaMultiplaBloco(); break;
            case 0: printf("\nEncerrando o Tetris Stack Mestre. Fim de jogo!\n"); break;
            default: printf("\nComando invalido! Tente novamente.\n");
        }

    } while (comando != 0);

    return 0;
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Aqui eu zero os indices de controle e coloco o topo em -1 para comecar limpo
void inicializarEstruturas() {
    fila.inicio = 0;
    fila.fim = 0;
    fila.total = 0;
    pilha.topo = -1; // -1 significa que a pilha de reserva nasceu vazia
}


// ============================================================================
// PARTE 2: GERAÇÃO DE PEÇAS, EXIBIÇÃO DUPLA E OPERAÇÕES BÁSICAS DE FLUXO


// Funcao automatica que escolhe uma letra aleatoria e gera um ID sequencial para a peca
Peca gerarPeca() {
    Peca nova;
    char formatos[] = {'I', 'O', 'T', 'L'};
    
    // Sorteia um indice de 0 a 3 do vetor de formatos
    int indice_sorteio = rand() % 4;
    
    nova.nome = formatos[indice_sorteio];
    nova.id = contador_id;
    
    contador_id++; // Aumenta o ID global para a proxima peca ganhar um numero novo
    return nova;
}

// Funcao que renderiza o estado da fila e da pilha separadas visualmente (Requisito UX)
void exibirPainel() {
    printf("\n=================================================\n");
    printf("Fila de pecas:    ");
    if (fila.total == 0) {
        printf("[ Vazia ]");
    } else {
        // Faz a varredura circular comecando no 'inicio' e andando pelo 'total' de pecas
        int idx = fila.inicio;
        for (int i = 0; i < fila.total; i++) {
            printf("[%c %d] ", fila.itens[idx].nome, fila.itens[idx].id);
            idx = (idx + 1) % FILA_MAX; // Giro circular do indice
        }
    }

    printf("\nPilha de reserva (Topo -> Base): ");
    if (pilha.topo == -1) {
        printf("[ Vazia ]");
    } else {
        // CORREÇÃO: Laço simplificado e direto do topo até a base (índice 0)
        for (int j = pilha.topo; j >= 0; j--) {
            printf("[%c %d] ", pilha.itens[j].nome, pilha.itens[j].id);
        }
    }
    printf("\n=================================================\n");
}


// Operacao 1: Faz o dequeue (remove a peca da frente da fila e joga uma nova no fim)
void jogarPecaFrente() {
    if (fila.total == 0) {
        printf("\nErro: Nao ha pecas na fila para jogar!\n");
        return;
    }

    // Captura os dados da peca que esta saindo da frente
    Peca peca_jogada = fila.itens[fila.inicio];
    printf("\n️ Voce jogou a peca da frente: [%c %d]\n", peca_jogada.nome, peca_jogada.id);

    // Avanca o inicio da fila circular
    fila.inicio = (fila.inicio + 1) % FILA_MAX;
    fila.total--;

    // Requisito: Reposicao automatica para manter a fila sempre cheia
    fila.fim = (fila.fim + 1) % FILA_MAX;
    fila.itens[fila.fim] = gerarPeca();
    fila.total++;
    printf("Nova peca [%c %d] entrou no fim da fila para recompor o estoque.\n", fila.itens[fila.fim].nome, fila.itens[fila.fim].id);
}

// Operacao 2: Move o elemento da frente da fila para o topo da pilha de reserva
void enviarFilaParaPilha() {
    // Primeiro conferimos as duas travas de segurança obrigatórias
    if (fila.total == 0) {
        printf("\nErro: Nao ha pecas na fila para reservar.\n");
        return;
    }
    if (pilha.topo >= PILHA_MAX - 1) {
        printf("\nErro: Pilha de reserva cheia (Maximo 3)! Use uma peca antes.\n");
        return;
    }

    // Remove a peca da frente da fila (sem apagar, apenas guardamos ela)
    Peca peca_reservada = fila.itens[fila.inicio];
    fila.inicio = (fila.inicio + 1) % FILA_MAX;
    fila.total--;

    // Coloca essa peca no topo da pilha de reserva (Push)
    pilha.topo++;
    pilha.itens[pilha.topo] = peca_reservada;
    printf("\n Peca [%c %d] foi enviada para o topo da pilha de reserva.\n", peca_reservada.nome, peca_reservada.id);

    // Requisito: Reposicao automatica na fila para ela nao esvaziar
    fila.fim = (fila.fim + 1) % FILA_MAX;
    fila.itens[fila.fim] = gerarPeca();
    fila.total++;
    printf("Nova peca [%c %d] entrou no fim da fila para manter as 5 pecas ativas.\n", fila.itens[fila.fim].nome, fila.itens[fila.fim].id);
}

// Operacao 3: Faz o pop (consome e destroi a peca que esta no topo da reserva)
void usarPecaReserva() {
    if (pilha.topo == -1) {
        printf("\n Erro: Pilha de reserva vazia! Nao ha o que usar.\n");
        return;
    }

    // Retira o elemento do topo da pilha (Pop)
    Peca peca_usada = pilha.itens[pilha.topo];
    pilha.topo--; // Recua o topo, deixando o item antigo inacessivel

    printf("\nVoce usou a peca reservada do topo: [%c %d]! Ela foi removida do jogo.\n", peca_usada.nome, peca_usada.id);
}


// ============================================================================
// PARTE 3: MANOBRAS AVANÇADAS DE TROCA E FECHAMENTO DO ARQUIVO


// Operacao 4: Substitui de lugar a peca da frente da fila com o topo da pilha
void trocarPecaAtual() {
    // Trava de seguranca: precisamos ter pecas nas duas estruturas para trocar
    if (fila.total == 0 || pilha.topo == -1) {
        printf("\nErro: Operacao invalida! A fila ou a pilha de reserva esta vazia.\n");
        return;
    }

    // Usamos uma variavel temporaria para fazer a permuta sem apagar os dados
    Peca temp = fila.itens[fila.inicio];
    
    // O inicio da fila ganha os dados do topo da pilha
    fila.itens[fila.inicio] = pilha.itens[pilha.topo];
    
    // O topo da pilha ganha o antigo inicio da fila que guardamos em temp
    pilha.itens[pilha.topo] = temp;

    printf("\n Troca Unitária realizada com sucesso!\n");
    printf("   -> Nova peca na frente da fila: [%c %d]\n", fila.itens[fila.inicio].nome, fila.itens[fila.inicio].id);
    printf("   -> Nova peca no topo da reserva: [%c %d]\n", pilha.itens[pilha.topo].nome, pilha.itens[pilha.topo].id);
}

// Operacao 5: Alterna os 3 primeiros da fila com os 3 da pilha (Troca em Bloco)
void trocaMultiplaBloco() {
    // Requisito: Ambas as estruturas precisam ter pelo menos 3 pecas cadastradas
    if (fila.total < 3) {
        printf("\nErro: A fila precisa de pelo menos 3 pecas para a troca em bloco.\n");
        return;
    }
    if (pilha.topo < 2) { // Como o topo comeca em -1, o indice 2 significa que temos 3 itens (0, 1, 2)
        printf("\nErro: A pilha precisa estar totalmente cheia (3 pecas) para esta acao.\n");
        return;
    }

    // Criamos um vetor auxiliar temporario para guardar as 3 pecas da fila
    Peca pecasFila[3];
    int idx_fila = fila.inicio;

    // 1º Passo: Retiramos e guardamos as 3 primeiras pecas da fila de forma circular
    for (int i = 0; i < 3; i++) {
        pecasFila[i] = fila.itens[idx_fila];
        idx_fila = (idx_fila + 1) % FILA_MAX;
    }

    // 2º Passo: Como a pilha funciona em LIFO, nós colocamos as 3 pecas da fila 
    // dentro do vetor circular, respeitando a ordem reversa das pecas que saem da pilha.
    idx_fila = fila.inicio;
    int idx_pilha = pilha.topo; // Comeca do topo (indice 2) e vai descendo ate a base (0)
    
    for (int i = 0; i < 3; i++) {
        fila.itens[idx_fila] = pilha.itens[idx_pilha];
        idx_fila = (idx_fila + 1) % FILA_MAX;
        idx_pilha--;
    }

    // 3º Passo: Agora colocamos as pecas da fila que guardamos no comeco dentro da pilha.
    // Para manter a inversao correta de estados exigida pelo desafio mestre, 
    // nós jogamos a primeira peca da fila na base e a terceira no topo da pilha.
    pilha.itens[0] = pecasFila[0];
    pilha.itens[1] = pecasFila[1];
    pilha.itens[2] = pecasFila[2];

    printf("\n TROCA MÚLTIPLA REALIZADA! Os 3 primeiros blocos mudaram de estrutura!\n");
}
