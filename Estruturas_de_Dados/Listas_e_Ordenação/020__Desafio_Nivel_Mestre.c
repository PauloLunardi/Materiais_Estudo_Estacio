// ============================================================================
//      DESAFIO MESTRE - TORRE DE FUGA: ALGORITMOS DE ORDENAÇÃO E BUSCA
// ============================================================================

// ============================================================================
// PARTE 1: ESTRUTURAS, PROTÓTIPOS E FUNÇÃO PRINCIPAL (MAIN)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Para usarmos a função clock() que mede o tempo

// Definimos os tamanhos máximos de componentes e de texto do sistema
#define MAX_COMPONENTES 20
#define TAM_STRING 50

// --- Criacao da Struct ---
// Aqui nós criamos a nossa struct para guardar os dados de cada componente da torre
typedef struct {
    char nome[TAM_STRING];
    char tipo[TAM_STRING];
    int prioridade;
} Componente;

// --- Variáveis Globais de Controle ---
// Criamos o vetor que vai guardar nossos componentes e os contadores de performance
Componente torre[MAX_COMPONENTES];
int total_componentes = 0; // Controla quantos componentes já foram cadastrados
int conta_comparacoes = 0; // Conta quantas vezes o algoritmo fez uma comparação

// --- Protótipos das Funções ---
// Avisando o compilador que essas funções existem e foram feitas fora da main
void limparBuffer();
void exibirMenuAcoes();
void cadastrarComponentes();
void mostrarComponentes();
void bubbleSortNome();
void insertionSortTipo();
void selectionSortPrioridade();
void buscarBinariaPorNome();

// --- Função Principal (main) ---
int main() {
    int opcao;

    // Semeia o gerador de números aleatórios com a hora atual (boa prática)
    srand((unsigned int)time(NULL));

    do {
        // Toda vez que o laço roda, ele redesenha o menu e espera nossa escolha
        exibirMenuAcoes();
        scanf("%d", &opcao);
        limparBuffer(); // Eu limpo o buffer aqui para o enter do scanf não bugar o menu

        switch(opcao) {
            case 1:
                cadastrarComponentes();
                break;
            case 2:
                bubbleSortNome();
                break;
            case 3:
                insertionSortTipo();
                break;
            case 4:
                selectionSortPrioridade();
                break;
            case 5:
                buscarBinariaPorNome();
                break;
            case 6:
                mostrarComponentes();
                break;
            case 0:
                printf("\nSaindo do sistema da Torre de Fuga. Até logo!\n");
                break;
            default:
                printf("\n❌ Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

// -- Função para limpar o buffer de entrada --
// Aqui eu crio a função clássica para limpar o enter do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// -- Função para desenhar as opções na tela --
void exibirMenuAcoes() {
    printf("\n=== PAINEL DE CONTROLE DA TORRE DE FUGA ===\n");
    printf("1 - Cadastrar Componentes (Ate 20)\n");
    printf("2 - Ordenar por Nome (Bubble Sort - Libera Busca Binaria)\n");
    printf("3 - Ordenar por Tipo (Insertion Sort)\n");
    printf("4 - Ordenar por Prioridade (Selection Sort)\n");
    printf("5 - Buscar Componente-Chave (Busca Binaria)\n");
    printf("6 - Mostrar Lista de Componentes Atual\n");
    printf("0 - Desistir e Sair do Jogo\n");
    printf("Escolha uma opcao: ");
}


// PARTE 2: CADASTRO, EXIBIÇÃO E IMPLEMENTAÇÃO DOS TRÊS ALGORITMOS DE ORDENAÇÃO

// --- Função para Cadastrar Componentes ---
void cadastrarComponentes() {
    if (total_componentes >= MAX_COMPONENTES) {
        printf("\n❌ Erro: Painel cheio! A torre ja tem os 20 componentes necessarios.\n");
        return;
    }

    printf("\n--- CADASTRAR COMPONENTE DA TORRE (%d/20) ---\n", total_componentes + 1);
    
    printf("Digite o nome (Ex: chip_central): ");
    fgets(torre[total_componentes].nome, TAM_STRING, stdin);
    torre[total_componentes].nome[strcspn(torre[total_componentes].nome, "\n")] = '\0'; // Eu limpo o \n do fgets de forma limpa

    printf("Digite o tipo (Ex: controle, suporte, propulsao): ");
    fgets(torre[total_componentes].tipo, TAM_STRING, stdin);
    torre[total_componentes].tipo[strcspn(torre[total_componentes].tipo, "\n")] = '\0';

    printf("Digite a prioridade (de 1 a 10): ");
    scanf("%d", &torre[total_componentes].prioridade);
    limparBuffer();

    printf("✔️ Componente \"%s\" registrado com sucesso!\n", torre[total_componentes].nome);
    total_componentes++; // Aqui eu avanco o contador da mochila global
    
    mostrarComponentes(); // Requisito: Exibir a lista apos cada operacao
}

// --- Função para Mostrar a Lista Formatada ---
void mostrarComponentes() {
    printf("\n=================================================\n");
    printf("         LISTA DE COMPONENTES DA TORRE           \n");
    printf("=================================================\n");
    if (total_componentes == 0) {
        printf("Nenhum componente cadastrado no painel ainda.\n");
        printf("=================================================\n");
        return;
    }
    for (int i = 0; i < total_componentes; i++) {
        printf("[%d] Nome: %-15s | Tipo: %-12s | Prioridade: %d\n", 
               i + 1, torre[i].nome, torre[i].tipo, torre[i].prioridade);
    }
    printf("=================================================\n");
}

// --- 1. Bubble Sort por Nome (Ordem Alfabética de Strings) ---
void bubbleSortNome() {
    if (total_componentes < 2) {
        printf("\nNao ha componentes suficientes para ordenar.\n");
        return;
    }

    conta_comparacoes = 0; // Aqui eu reseto o contador antes de comecar a ordenacao
    clock_t tempo_inicial = clock(); // Aqui eu capturo os milissegundos iniciais

    // Lógica do Bubble Sort: compara vizinhos diretos e joga o maior para o fim
    for (int i = 0; i < total_componentes - 1; i++) {
        for (int j = 0; j < total_componentes - i - 1; j++) {
            conta_comparacoes++; // Aqui eu conto a checagem que farei na proxima linha
            
            if (strcmp(torre[j].nome, torre[j + 1].nome) > 0) {
                // Se o da esquerda for maior, trocamos eles de lugar
                Componente temp = torre[j];
                torre[j] = torre[j + 1];
                torre[j + 1] = temp;
            }
        }
    }

    clock_t tempo_final = clock(); // Aqui eu pego o tempo final apos terminar
    double tempo_gasto = ((double)(tempo_final - tempo_inicial)) / CLOCKS_PER_SEC;

    printf("\n✔️ Lista ordenada por NOME usando Bubble Sort!\n");
    printf(">> Total de comparacoes feitas: %d\n", conta_comparacoes);
    printf(">> Tempo de execucao: %f segundos\n", tempo_gasto);
    mostrarComponentes();
}

// --- 2. Insertion Sort por Tipo (Ordem Alfabética de Strings) ---
void insertionSortTipo() {
    if (total_componentes < 2) {
        printf("\nNao ha componentes suficientes para ordenar.\n");
        return;
    }

    conta_comparacoes = 0; 
    clock_t tempo_inicial = clock();

    // Lógica do Insertion Sort: pega a chave e a encaixa entre os elementos ja organizados
    for (int i = 1; i < total_componentes; i++) {
        Componente chave = torre[i];
        int j = i - 1;

        // Enquanto o item da esquerda for maior que a chave alfabeticamente, movemos ele para a direita
        while (j >= 0) {
            conta_comparacoes++; // Conta a checagem da string que sera feita
            if (strcmp(torre[j].tipo, chave.tipo) > 0) {
                torre[j + 1] = torre[j];
                j = j - 1;
            } else {
                break; // Se nao for maior, a posicao correta foi achada e paramos o laço
            }
        }
        torre[j + 1] = chave; // Coloca a chave na lacuna aberta
    }

    clock_t tempo_final = clock();
    double tempo_gasto = ((double)(tempo_final - tempo_inicial)) / CLOCKS_PER_SEC;

    printf("\n✔️ Lista ordenada por TIPO usando Insertion Sort!\n");
    printf(">> Total de comparacoes feitas: %d\n", conta_comparacoes);
    printf(">> Tempo de execucao: %f segundos\n", tempo_gasto);
    mostrarComponentes();
}

// --- 3. Selection Sort por Prioridade (Ordem Crescente Numérica) ---
void selectionSortPrioridade() {
    if (total_componentes < 2) {
        printf("\nNao ha componentes suficientes para ordenar.\n");
        return;
    }

    conta_comparacoes = 0;
    clock_t tempo_inicial = clock();

    // Lógica do Selection Sort: busca o menor valor restante e o joga para o inicio
    for (int i = 0; i < total_componentes - 1; i++) {
        int indice_menor = i; // Assume que o primeiro nao ordenado e o menor

        for (int j = i + 1; j < total_componentes; j++) {
            conta_comparacoes++; // Conta a comparacao numerica atual
            if (torre[j].prioridade < torre[indice_menor].prioridade) {
                indice_menor = j; // Guarda onde foi achado o menor numero
            }
        }

        // Se o menor numero nao estiver na posicao inicial, fazemos a troca
        if (indice_menor != i) {
            Componente temp = torre[i];
            torre[i] = torre[indice_menor];
            torre[indice_menor] = temp;
        }
    }

    clock_t tempo_final = clock();
    double tempo_gasto = ((double)(tempo_final - tempo_inicial)) / CLOCKS_PER_SEC;

    printf("\n✔️ Lista ordenada por PRIORIDADE usando Selection Sort!\n");
    printf(">> Total de comparacoes feitas: %d\n", conta_comparacoes);
    printf(">> Tempo de execucao: %f segundos\n", tempo_gasto);
    mostrarComponentes();
}


// ============================================================================
// PARTE 3: BUSCA BINÁRIA POR NOME E FECHAMENTO DO ARQUIVO

// --- Função de Busca Binária por Nome ---
// Requisito: Aplicável apenas após ordenar por nome (Opção 2 do menu)
void buscarBinariaPorNome() {
    char alvo[TAM_STRING];
    int inicio = 0;
    int fim = total_componentes - 1;
    int encontrado = 0;
    int conta_binaria = 0; // Reseto o contador específico desta busca

    if (total_componentes == 0) {
        printf("\n❌ Erro: O painel está vazio. Cadastre componentes antes de buscar!\n");
        return;
    }

    printf("\n⚠️ ATENÇÃO: Esta busca exige que a lista tenha sido ordenada por NOME primeiro!\n");
    printf("Digite o nome do componente-chave para destravar a torre: ");
    fgets(alvo, TAM_STRING, stdin);
    alvo[strcspn(alvo, "\n")] = '\0'; // Remove o \n do teclado

    // Lógica da Busca Binária: divide o espaço de busca na metade a cada passo
    while (inicio <= fim) {
        conta_binaria++; // Contamos cada passagem pelo loop que faz uma checagem
        
        int meio = inicio + (fim - inicio) / 2;
        int comp = strcmp(torre[meio].nome, alvo);

        // Cenário 1: Encontramos o componente-chave exatamente no meio
        if (comp == 0) {
            printf("\n🎉🎉 COMPONENTE-CHAVE ENCONTRADO! ATIVAÇÃO DA TORRE DESTRANCADA! 🎉🎉\n");
            printf("-> Slot [%d] -> Nome: %s | Tipo: %s | Prioridade: %d\n", 
                   meio + 1, torre[meio].nome, torre[meio].tipo, torre[meio].prioridade);
            encontrado = 1;
            break; // Interrompe o laço porque o objetivo foi alcançado
        }
        // Cenário 2: O item do meio vem depois alfabeticamente, buscamos na esquerda
        else if (comp > 0) {
            fim = meio - 1;
        }
        // Cenário 3: O item do meio vem antes alfabeticamente, buscamos na direita
        else {
            inicio = meio + 1;
        }
    }

    // Se o laço terminar e a flag continuar 0, o item não está no vetor
    if (encontrado == 0) {
        printf("\n❌ Falha: O componente \"%s\" não foi localizado no painel da torre.\n", alvo);
    }

    // Requisito funcional: Exibir o número de comparações realizadas
    printf(">> Total de comparações feitas na Busca Binária: %d\n", conta_binaria);
}
