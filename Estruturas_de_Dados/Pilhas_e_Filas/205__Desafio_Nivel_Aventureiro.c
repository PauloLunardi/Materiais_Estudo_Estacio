// ============================================================================
//     DESAFIO AVENTUREIRO - FILA CIRCULAR COM PILHA DE RESERVA (TETRIS STACK)
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILA 5
#define MAX_PILHA 3

// --- Estrutura da Peça ---
// Aqui eu criei a struct basica para guardar os dados de cada peca do jogo
typedef struct {
    char nome; // Guarda a letra ('I', 'O', 'T', 'L')
    int id;    // Guarda o numero sequencial unico da peca
} Peca;

// --- Estrutura da Fila Circular ---
// Aqui eu fiz a struct para controlar a nossa fila de pecas futuras
typedef struct {
    Peca itens[MAX_FILA];
    int inicio;
    int fim;
    int total;
} FilaCircular;

// --- Estrutura da Pilha Linear ---
// Aqui eu montei a struct para controlar as pecas que o jogador deixar guardadas
typedef struct {
    Peca itens[MAX_PILHA];
    int topo; // Indica qual e a posicao da peca mais alta na pilha
} PilhaLinear;

// --- Variaveis Globais ---
FilaCircular fila;
PilhaLinear pilha;
int contador_id = 0; // Controla o gerador de IDs sequenciais

// --- Protótipos das Funções ---
void limparBuffer();
void inicializarEstruturas();
Peca gerarPeca();
void jogarPeca();
void reservarPeca();
void usarPecaReservada();
void exibirPainel();

// --- Funcao Principal (main) ---
int main() {
    int opcao;

    // Aqui eu coloco a semente do rand() baseada no relogio do PC
    srand((unsigned int)time(NULL));

    // Aqui eu chamo a funcao para zerar todos os indices e deixar tudo limpo
    inicializarEstruturas();

    // Requisito: Aqui eu preencho automaticamente as 5 pecas iniciais da fila futura
    for (int i = 0; i < MAX_FILA; i++) {
        fila.itens[i] = gerarPeca();
        fila.total++;
    }
    fila.fim = MAX_FILA - 1; // Deixo o ponteiro do fim travado na ultima peca

    printf("=================================================\n");
    printf("         TETRIS STACK - MÓDULO INTERMEDIÁRIO     \n");
    printf("=================================================\n");

    do {
        exibirPainel(); // Aqui eu desenho a fila e a pilha na tela

        printf("\nOpcoes de Acao:\n");
        printf("1 - Jogar peca\n");
        printf("2 - Reservar peca\n");
        printf("3 - Usar peca reservada\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) {
            case 1:
                jogarPeca();
                break;
            case 2:
                reservarPeca();
                break;
            case 3:
                usarPecaReservada();
                break;
            case 0:
                printf("\nFechando o inventario do jogo. Ate logo!\n");
                break;
            default:
                printf("\n❌ Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Implementacao das Funcoes ---

void inicializarEstruturas() {
    // Aqui eu zero os controles da fila circular
    fila.inicio = 0;
    fila.fim = 0;
    fila.total = 0;

    // Aqui eu zero a pilha linear definindo o topo como -1 (indica pilha vazia)
    pilha.topo = -1;
}

Peca gerarPeca() {
    Peca nova;
    char formatos[] = {'I', 'O', 'T', 'L'};
    int sorteio = rand() % 4;
    
    nova.nome = formatos[sorteio];
    nova.id = contador_id;
    
    contador_id++; // Aqui eu somo 1 no ID global para a proxima peca ganhar um numero novo
    return nova;
}

// Oopcao 1: Faz o dequeue na fila para jogar no tabuleiro
void jogarPeca() {
    if (fila.total == 0) {
        printf("\n❌ Erro: Nao ha pecas na fila para jogar!\n");
        return;
    }

    // Aqui eu pego o elemento da frente da fila
    Peca peca_saida = fila.itens[fila.inicio];
    printf("\n🕹️ Voce jogou a peca [%c %d] no tabuleiro!\n", peca_saida.nome, peca_saida.id);

    // Aqui eu aplico o operador modulo para girar o inicio da fila de forma circular
    fila.inicio = (fila.inicio + 1) % MAX_FILA;
    fila.total--;

    // Requisito: Aqui eu coloco uma peca nova automaticamente no final da fila para repor
    fila.fim = (fila.fim + 1) % MAX_FILA;
    fila.itens[fila.fim] = gerarPeca();
    fila.total++;
}

// Opcao 2: Move a peca da frente da fila para o topo da pilha
void reservarPeca() {
    // Aqui eu testo se a pilha ja estourou a capacidade de 3 slots
    if (pilha.topo >= MAX_PILHA - 1) {
        printf("\n❌ Erro: Pilha de reserva cheia! Use uma peca antes de guardar outra.\n");
        return;
    }
    if (fila.total == 0) {
        printf("\n❌ Erro: Nao ha pecas na fila para reservar!\n");
        return;
    }

    // Aqui eu capturo a peca que esta na frente da fila circular (dequeue)
    Peca peca_para_reservar = fila.itens[fila.inicio];
    fila.inicio = (fila.inicio + 1) % MAX_FILA;
    fila.total--;

    // Aqui eu subo o topo da pilha e coloco a peca la dentro (push)
    pilha.topo++;
    pilha.itens[pilha.topo] = peca_para_reservar;
    printf("\n📦 Peca [%c %d] movida da fila e guardada na reserva!\n", peca_para_reservar.nome, peca_para_reservar.id);

    // Requisito: Aqui eu gero uma peca nova para o fim da fila nao ficar desfalcado
    fila.fim = (fila.fim + 1) % MAX_FILA;
    fila.itens[fila.fim] = gerarPeca();
    fila.total++;
}

// Opcao 3: Faz o pop no topo da pilha para consumir a peca guardada
void usarPecaReservada() {
    // Aqui eu testo se a pilha esta vazia antes de tentar tirar
    if (pilha.topo == -1) {
        printf("\n❌ Erro: Nao ha nenhuma peca na reserva para usar!\n");
        return;
    }

    // Aqui eu retiro a peca que estava mais alta na pilha (estilo LIFO)
    Peca peca_usada = pilha.itens[pilha.topo];
    pilha.topo--; // Desco o indicador do topo para a posicao de baixo

    printf("\n⚡ Voce ativou e usou a peca reservada [%c %d]!\n", peca_usada.nome, peca_usada.id);
}

void exibirPainel() {
    printf("\n=================================================\n");
    
    // Varredura circular da fila
    printf("Fila de pecas:       ");
    if (fila.total == 0) {
        printf("[Vazia]");
    } else {
        int idx = fila.inicio;
        for (int i = 0; i < fila.total; i++) {
            printf("[%c %d] ", fila.itens[idx].nome, fila.itens[idx].id);
            idx = (idx + 1) % MAX_FILA;
        }
    }
    
    // Varredura linear da pilha (do topo ate a base)
    printf("\nPilha de reserva (Topo -> Base): ");
    if (pilha.topo == -1) {
        printf("[Vazia]");
    } else {
        for (int i = pilha.topo; i >= 0; i--) {
            printf("[%c %d] ", pilha.itens[i].nome, pilha.itens[i].id);
        }
    }
    printf("\n=================================================\n");
}
