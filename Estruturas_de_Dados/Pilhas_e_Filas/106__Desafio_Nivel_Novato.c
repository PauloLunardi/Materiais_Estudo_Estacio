// ============================================================================
//         DESAFIO NOVATO - FILA DE PEÇAS FUTURAS (TETRIS STACK)
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Para a semente do rand() mudar a cada jogo

#define MAX 5

// --- Estrutura da Peça
// Aqui criamos a nossa struct para guardar os dados de cada peca do Tetris
typedef struct {
    char nome; // Vai guardar a letra da forma: 'I', 'O', 'T', 'L'
    int id;    // Numero unico sequencial da peca
} Peca;

// --- Estrutura da Fila Circular
// Aqui eu crio a struct para controlar a nossa fila circular de pecas
typedef struct {
    Peca itens[MAX]; // Vetor fixo de 5 posicoes para as pecas futuras
    int inicio;      // Indica onde esta a peca da frente (proxima a ser jogada)
    int fim;         // Indica onde esta a ultima peca que entrou
    int total;       // Contador absoluto de quantas pecas estao na fila agora
} FilaPecas;

// --- Variaveis Globais de Controle
FilaPecas fila;
int contador_id = 0; // Guarda o proximo ID unico a ser gerado

// --- Protótipos das Funções
void limparBuffer();
void inicializarFila();
Peca gerarPeca();
void jogarPeca();
void inserirNovaPeca();
void exibirFila();

// --- Funcao Principal (main)
int main() {
    int opcao;

    // Inicializa o gerador de numeros aleatorios com base no tempo atual
    srand((unsigned int)time(NULL));

    // Passo obrigatorio: zera os indices e contadores da fila
    inicializarFila();

    printf("=================================================\n");
    printf("           TETRIS STACK - FILA DE PEÇAS          \n");
    printf("=================================================\n");

    // Requisito: O jogo comeca preenchendo automaticamente as 5 vagas da fila
    for (int i = 0; i < MAX; i++) {
        fila.itens[i] = gerarPeca();
        fila.total++;
    }
    // Ajustamos o ponteiro do fim para a ultima peca inserida (indice 4)
    fila.fim = MAX - 1;

    // Laco principal do jogo
    do {
        exibirFila(); // Mostra o painel com as pecas atuais

        printf("\nOpcoes de acao:\n");
        printf("1 - Jogar peca (dequeue)\n");
        printf("2 - Inserir nova peca (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha um comando: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) {
            case 1:
                jogarPeca();
                break;
            case 2:
                inserirNovaPeca();
                break;
            case 0:
                printf("\nFechando o Tetris Stack. Ate logo!\n");
                break;
            default:
                printf("\n❌ Comando invalido! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Implementacao das Funcoes

// Aqui eu zero os indices e o total de controle para limpar a memoria da fila
void inicializarFila() {
    fila.inicio = 0;
    fila.fim = 0;
    fila.total = 0;
}

// Funcao automatica que escolhe uma letra aleatoria e coloca um ID sequencial na peca
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

// Funcao que faz o dequeue (remove a peca da frente da fila para jogar no tabuleiro)
void jogarPeca() {
    // Validação obrigatória: Se a fila estiver vazia, nao ha o que jogar
    if (fila.total == 0) {
        printf("\n❌ Erro: Nao ha pecas na fila para jogar!\n");
        return;
    }

    // Captura os dados da peca que esta saindo da frente
    Peca peca_jogada = fila.itens[fila.inicio];
    printf("\n🕹️ Voce jogou a peca [%c %d] no tabuleiro!\n", peca_jogada.nome, peca_jogada.id);

    // Aqui aplicamos a logica circular para avancar o inicio da fila
    fila.inicio = (fila.inicio + 1) % MAX;
    
    // Tiramos 1 do total porque agora a fila tem uma peca a menos
    fila.total--;
}

// Funcao que faz o enqueue (adiciona uma peca gerada de forma automatica no fim da fila)
void inserirNovaPeca() {
    // Validação obrigatória: Se a fila estiver cheia, nao podemos inserir mais
    if (fila.total == MAX) {
        printf("\n❌ Erro: Fila cheia! Jogue uma peca antes de adicionar outra.\n");
        return;
    }

    // Aqui eu aplico o operador modulo (%) para calcular a proxima posicao de fim de forma circular
    fila.fim = (fila.fim + 1) % MAX;
    
    // O sistema gera a peca automaticamente e joga na posicao de fim calculada
    fila.itens[fila.fim] = gerarPeca();
    
    // Aumentamos o total de pecas ativas
    fila.total++;
    printf("\n➕ Nova peca [%c %d] entrou no fim da fila de espera.\n", fila.itens[fila.fim].nome, fila.itens[fila.fim].id);
}

// Funcao que percorre o vetor de forma circular respeitando a ordem FIFO real
void exibirFila() {
    printf("\n--- FILA DE PEÇAS FUTURAS ---\n");
    if (fila.total == 0) {
        printf("[ Fila Vazia ]\n");
        return;
    }

    // Aqui fazemos a varredura circular: comeca no 'inicio' e roda ate completar o 'total' de itens salvos
    int idx = fila.inicio;
    for (int i = 0; i < fila.total; i++) {
        printf("[%c %d] ", fila.itens[idx].nome, fila.itens[idx].id);
        
        // Faz o indice rodar de forma circular para nao estourar o tamanho do vetor
        idx = (idx + 1) % MAX;
    }
    printf("\n-----------------------------\n");
}
