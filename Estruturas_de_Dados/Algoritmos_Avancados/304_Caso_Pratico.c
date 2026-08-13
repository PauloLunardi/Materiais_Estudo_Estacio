// ============================================================================
//         HORA DE CODAR - IMPLEMENTAÇÃO DE TABELAS HASH EM C
// ============================================================================
// OBJETIVOS CUMPRIDOS:
// - Função Hash uniforme comum baseada no resto da divisão (% TAMANHO).
// - Abordagem 1: Encadeamento Separado (Chaining via Lista Ligada).
// - Abordagem 2: Endereçamento Aberto (Sondagem Linear via Máquina de Estados).
// - Menu e Testes no terminal tratando inserção, busca e remoção de strings.
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 10

// ============================================================================
//      ESTRUTURAS E VARIÁVEIS DA ABORDAGEM 1: ENCADEAMENTO (CHAINING)
// ============================================================================

// Aqui nós criamos a estrutura do no da lista ligada para o encadeamento
typedef struct Nodo {
    char nome[50];        // Campo que armazena a string do item
    struct Nodo* proximo; // Ponteiro que conecta o próximo elo da lista
} Nodo;

// Vetor de ponteiros global para a tabela por encadeamento
Nodo* tabela_encadeamento[TAMANHO];

// ============================================================================
//      ESTRUTURAS E VARIÁVEIS DA ABORDAGEM 2: SONDAGEM LINEAR
// ============================================================================

// Aqui nós criamos a estrutura do slot contíguo para a sondagem linear
typedef struct {
    char nome[50];
    int estado; // Máquina de Estados: 0 = Vazio, 1 = Ocupado, -1 = Removido
} SlotSondagem;

// Vetor de dados contíguo global para a tabela por sondagem
SlotSondagem tabela_sondagem[TAMANHO];

// --- Protótipos das Funções ---
void limparBuffer();
int calcular_hash(const char* chave);
void inicializarTabelas();

// Funções da Tabela 1: Encadeamento
void inserir_encadeamento(const char* nome);
int buscar_encadeamento(const char* nome);
void remover_encadeamento(const char* nome);
void exibir_encadeamento();

// Funções da Tabela 2: Sondagem
void inserir_sondagem(const char* nome);
int buscar_sondagem(const char* nome);
void remover_sondagem(const char* nome);
void exibir_sondagem();

// --- Função Principal (main) ---
int main() {
    // Semente padrão e inicialização zerando a memória dos seletores
    inicializarTabelas();

    printf("=================================================\n");
    printf("         HORA DE CODAR - TABELAS HASH v1         \n");
    printf("=================================================\n");

    // --- CARGA DE TESTES: INSERINDO ELEMENTOS ---
    printf("\n[Sistema] Realizando insercoes de teste...\n");
    
    // Nomes com alto potencial de colisão para testar o comportamento das tabelas
    inserir_encadeamento("Ana");
    inserir_encadeamento("Bruno");
    inserir_encadeamento("Carlos");
    inserir_encadeamento("Amanda"); // Colide com Ana na soma ASCII

    inserir_sondagem("Ana");
    inserir_sondagem("Bruno");
    inserir_sondagem("Carlos");
    inserir_sondagem("Amanda");

    // --- EXIBIÇÃO DO ESTADO INTERNO ---
    exibir_encadeamento();
    exibir_sondagem();

    // --- TESTES DE CONSULTA / BUSCA ---
    printf("\n=== ROTEIRO DE BUSCAS NO TERMINAL ===\n");
    printf("Busca 'Bruno' (Encadeamento): %s\n", buscar_encadeamento("Bruno") ? "Achou!" : "Nao cadastrado");
    printf("Busca 'Joao' (Encadeamento): %s\n", buscar_encadeamento("Joao") ? "Achou!" : "Nao cadastrado");
    
    printf("Busca 'Bruno' (Sondagem): %s\n", buscar_sondagem("Bruno") != -1 ? "Achou!" : "Nao cadastrado");
    printf("Busca 'Joao' (Sondagem): %s\n", buscar_sondagem("Joao") != -1 ? "Achou!" : "Nao cadastrado");

    // --- TESTES DE EXCLUSÃO / REMOÇÃO ---
    printf("\n=== ROTEIRO DE REMOÇÕES NO TERMINAL ===\n");
    remover_encadeamento("Carlos");
    remover_encadeamento("Joao"); // Deve avisar que não achou

    remover_sondagem("Carlos");
    remover_sondagem("Joao");

    // --- EXIBIÇÃO FINAL PÓS MANOBRAS ---
    printf("\n[Sistema] Estado final dos vetores apos remocoes:\n");
    exibir_encadeamento();
    exibir_sondagem();

    return 0;
}

// ============================================================================
//                     IMPLEMENTAÇÃO DAS ROTINAS COMUNS
// ============================================================================

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função Hash Uniforme: soma o valor numérico dos caracteres e aplica o resto
int calcular_hash(const char* chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i]; // Acumula o valor numérico inteiro do caractere ASCII
    }
    return soma % TAMANHO; // Restringe o índice para caber no vetor (0 a 9)
}

// Configura os estados iniciais limpando lixos lógicos da memória RAM
void inicializarTabelas() {
    for (int i = 0; i < TAMANHO; i++) {
        tabela_encadeamento[i] = NULL; // Aterra as cabeças das listas ligadas
        tabela_sondagem[i].estado = 0;   // Máquina de estados: 0 significa Vazio/Virgem
        strcpy(tabela_sondagem[i].nome, "");
    }
}

// ============================================================================
//             IMPLEMENTAÇÃO OPERACIONAL - TABELA 1: ENCADEAMENTO
// ============================================================================

void inserir_encadeamento(const char* nome) {
    int indice = calcular_hash(nome); // Calcula a caixinha de destino

    // Aloca a memória dinâmica para a caixinha do novo nó
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) {
        printf("Erro de alocacao no Heap.\n");
        exit(1);
    }
    strcpy(novo->nome, nome);

    // Manobra clássica de inserção na cabeça (head): o novo aponta para quem já estava lá
    novo->proximo = tabela_encadeamento[indice];
    // O array assume o novo nó como o primeiro da fila daquela posição
    tabela_encadeamento[indice] = novo;
}

int buscar_encadeamento(const char* nome) {
    int indice = calcular_hash(nome);
    Nodo* atual = tabela_encadeamento[indice]; // Posiciona na cabeça da lista desse índice

    // Varre a corrente de colisões de nó em nó
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return 1; // Sucesso: Localizou o elemento cadastrado
        }
        atual = atual->proximo; // Salta para o próximo elo da corrente
    }
    return 0; // Varreu toda a listinha da gaveta e não achou
}

void remover_encadeamento(const char* nome) {
    int indice = calcular_hash(nome);
    Nodo* atual = tabela_encadeamento[indice];
    Nodo* anterior = NULL; // Ponteiro de suporte para não quebrar a corrente

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            // Caso 1: O nó alvo era a própria cabeça da lista
            if (anterior == NULL) {
                tabela_encadeamento[indice] = atual->proximo;
            } 
            // Caso 2: O nó estava no meio ou no final da fila
            else {
                anterior->proximo = atual->proximo; // O de trás pula o atual e liga no da frente
            }
            free(atual); // Apaga a caixinha desempilhando a memória
            printf("[Encadeamento] Nome '%s' removido fisicamente da lista.\n", nome);
            return;
        }
        anterior = atual; // O anterior anda para onde o atual estava
        atual = atual->proximo; // O atual avança uma vaga
    }
    printf("[Encadeamento] Erro: Nome '%s' nao localizado na lista encadeada.\n", nome);
}

void exibir_encadeamento() {
    printf("\n>>> TABELA HASH 1: ENCADEAMENTO SEPARADO <<<\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("Slot [%d]: ", i);
        Nodo* temp = tabela_encadeamento[i];
        if (temp == NULL) {
            printf("[NULL]");
        } else {
            while (temp != NULL) {
                printf(" -> %s ", temp->nome);
                temp = temp->proximo;
            }
        }
        printf("\n");
    }
}

// ============================================================================
//             IMPLEMENTAÇÃO OPERACIONAL - TABELA 2: SONDAGEM LINEAR
// ============================================================================

// Função que insere nomes buscando vagas de um em um índice de forma circular
void inserir_sondagem(const char* nome) {
    int indice = calcular_hash(nome);

    // O laço de varredura tenta achar uma vaga dando no máximo uma volta na tabela
    for (int i = 0; i < TAMANHO; i++) {
        // Equação da Sondagem Linear: calcula a posição pulando de 1 em 1 de forma circular
        int pos = (indice + i) % TAMANHO;

        // Se a vaga for virgem (0) ou for uma lápide (-1), nós podemos gravar o dado ali
        if (tabela_sondagem[pos].estado == 0 || tabela_sondagem[pos].estado == -1) {
            strcpy(tabela_sondagem[pos].nome, nome);
            tabela_sondagem[pos].estado = 1; // Transiciona o status para Ocupado
            return; // Escrita concluída, encerra a função
        }
    }
    printf("[Sondagem] Erro: Tabela cheia! Nao foi possivel inserir '%s'.\n", nome);
}

// Função de busca que salta de um em um elemento usando a máquina de estados
int buscar_sondagem(const char* nome) {
    int indice = calcular_hash(nome);

    for (int i = 0; i < TAMANHO; i++) {
        int pos = (indice + i) % TAMANHO;

        // TRAVA DE PARADA: Se achar um slot vazio (0), a busca para na hora. O item não existe.
        if (tabela_sondagem[pos].estado == 0) {
            return -1;
        }

        // Se a vaga estiver ativa e o texto bater perfeitamente, devolve o ID/índice
        if (tabela_sondagem[pos].estado == 1 && strcmp(tabela_sondagem[pos].nome, nome) == 0) {
            return pos;
        }

        // Observação importante: Se o estado for -1 (Removido), o laço ignora e continua procurando!
    }
    return -1; // Procurou em todos os slots e não achou
}

// Função que remove marcando o status como Lápide (-1) para não quebrar buscas futuras
void remover_sondagem(const char* nome) {
    int pos = buscar_sondagem(nome); // Invoca a busca para rastrear a coordenada

    if (pos == -1) {
        printf("[Sondagem] Erro: Nome '%s' nao localizado na tabela hash.\n", nome);
        return;
    }

    // Marca o slot como Lápide (-1) para manter os caminhos de buscas futuras íntegros
    tabela_sondagem[pos].estado = -1;
    printf("[Sondagem] Nome '%s' removido logicamente da tabela (Status = -1).\n", nome);
}

// Mostra o vetor contíguo da sondagem linear no terminal
void exibir_sondagem() {
    printf("\n>>> TABELA HASH 2: SONDAGEM LINEAR <<<\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("Slot [%d]: ", i);
        if (tabela_sondagem[i].estado == 1) {
            printf("[ Ocupado: %-8s ]", tabela_sondagem[i].nome);
        } else if (tabela_sondagem[i].estado == -1) {
            printf("[ REMOVIDO / LÁPIDE  ]");
        } else {
            printf("[ Vazio / Disponivel ]");
        }
        printf("\n");
    }
}
