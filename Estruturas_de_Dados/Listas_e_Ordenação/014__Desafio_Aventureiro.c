// ============================================================================
//      DESAFIO AVENTUREIRO - COMPARAÇÃO DE VETOR X LISTA ENCADEADA
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 10

// --- Variáveis Globais para os Contadores ---
// Aqui eu crio duas variáveis globais para contar as comparações de cada busca
int conta_sequencial = 0;
int conta_binaria = 0;

// --- Estruturas de Dados ---
// Aqui nós criamos a nossa struct padrão para guardar os dados de cada item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Aqui nós criamos a struct do Nó para podermos montar a nossa lista encadeada
typedef struct No {
    Item dados;         // Aqui dentro do nó fica a struct com os dados do item
    struct No* proximo; // E aqui fica o ponteiro que liga este nó ao próximo da fila
} No;

// --- Variáveis Globais de Inventário ---
// Aqui eu crio o vetor da mochila que aguenta até 10 itens
Item mochila_vetor[TAM_MAX];
int total_vetor = 0; // Este contador controla quantas vagas o vetor já ocupou

// Aqui eu crio o ponteiro da cabeça para começar a nossa lista encadeada vazia
No* mochila_lista = NULL;

// --- Protótipos das Funções ---
void limparBuffer();
void menuVetor();
void menuLista();

// Funções do Vetor
void inserirItemVetor();
void removerItemVetor();
void listarVetor();
void ordenarVetor();
void buscarSequencialVetor();
void buscarBinariaVetor();

// Funções da Lista Encadeada
void inserirItemLista();
void removerItemLista();
void listarLista();
void buscarSequencialLista();
void liberarLista();

// --- Função Principal (main) ---
int main() {
    int opcao;

    do {
        printf("\n=== ENGINE DE INVENTÁRIO WAR ===\n");
        printf("1. Gerenciar Mochila por VETOR\n");
        printf("2. Gerenciar Mochila por LISTA ENCADEADA\n");
        printf("0. Fechar Jogo\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) {
            case 1:
                menuVetor();
                break;
            case 2:
                menuLista();
                break;
            case 0:
                printf("Encerrando o jogo e limpando tudo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    // No final do programa, eu limpo a memória da lista encadeada para não dar memory leak
    liberarLista();
    return 0;
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- MENUS DE INTERAÇÃO ---

void menuVetor() {
    int op;
    do {
        printf("\n--- MOCHILA VIA VETOR ---\n");
        printf("1. Inserir Item\n");
        printf("2. Remover Item por Nome\n");
        printf("3. Listar Itens\n");
        printf("4. Ordenar Inventário (Bubble Sort)\n");
        printf("5. Buscar Item (Busca Sequencial)\n");
        printf("6. Buscar Item (Busca Binária - Requer Ordenação)\n");
        printf("0. Voltar ao Menu Anterior\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
        limparBuffer();

        switch(op) {
            case 1: inserirItemVetor(); break;
            case 2: removerItemVetor(); break;
            case 3: listarVetor(); break;
            case 4: ordenarVetor(); break;
            case 5: buscarSequencialVetor(); break;
            case 6: buscarBinariaVetor(); break;
            case 0: break;
            default: printf("Opção inválida.\n");
        }
    } while (op != 0);
}

void menuLista() {
    int op;
    do {
        printf("\n--- MOCHILA VIA LISTA ENCADEADA ---\n");
        printf("1. Inserir Item (No Início)\n");
        printf("2. Remover Item por Nome\n");
        printf("3. Listar Itens\n");
        printf("4. Buscar Item (Busca Sequencial)\n");
        printf("0. Voltar ao Menu Anterior\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
        limparBuffer();

        switch(op) {
            case 1: inserirItemLista(); break;
            case 2: removerItemLista(); break;
            case 3: listarLista(); break;
            case 4: buscarSequencialLista(); break;
            case 0: break;
            default: printf("Opção inválida.\n");
        }
    } while (op != 0);
}

// ============================================================================
//                       IMPLEMENTAÇÃO - COMPONENTE VETOR
// ============================================================================

void inserirItemVetor() {
    if (total_vetor >= TAM_MAX) {
        printf("Erro: A mochila por vetor já está cheia!\n");
        return;
    }

    printf("\n[Vetor] Digite o nome do item: ");
    scanf("%29s", mochila_vetor[total_vetor].nome);
    printf("[Vetor] Digite o tipo: ");
    scanf("%19s", mochila_vetor[total_vetor].tipo);
    printf("[Vetor] Digite a quantidade: ");
    scanf("%d", &mochila_vetor[total_vetor].quantidade);
    limparBuffer();

    printf("Item \"%s\" cadastrado com sucesso no vetor!\n", mochila_vetor[total_vetor].nome);
    total_vetor++; // Aqui eu avanço o contador para a próxima vaga livre

    listarVetor(); // Requisito: Mostrar a listagem logo após a operação
}

void removerItemVetor() {
    char alvo[30];
    int achei = -1;

    if (total_vetor == 0) {
        printf("A mochila está vazia!\n");
        return;
    }

    printf("\n[Vetor] Digite o nome do item para remover: ");
    scanf("%29s", alvo);
    limparBuffer();

    // Aqui eu rodo um laço para procurar onde está o item que o usuário digitou
    for (int i = 0; i < total_vetor; i++) {
        if (strcmp(mochila_vetor[i].nome, alvo) == 0) {
            achei = i;
            break;
        }
    }

    if (achei == -1) {
        printf("Item não localizado no vetor!\n");
        return;
    }

    // Aqui eu aplico o fechamento de lacuna, arrastando os itens da frente para trás
    for (int i = achei; i < total_vetor - 1; i++) {
        mochila_vetor[i] = mochila_vetor[i + 1];
    }

    printf("Item \"%s\" removido com sucesso do vetor!\n", alvo);
    total_vetor--; // Diminuo o tamanho total do vetor

    listarVetor();
}

void listarVetor() {
    printf("\n--- CONTEÚDO DA MOCHILA (VETOR) ---\n");
    if (total_vetor == 0) {
        printf("Nenhum item guardado no vetor ainda.\n");
        return;
    }
    for (int i = 0; i < total_vetor; i++) {
        printf("Slot [%d] -> Nome: %-12s | Tipo: %-8s | Qtd: %d\n", 
               i + 1, mochila_vetor[i].nome, mochila_vetor[i].tipo, mochila_vetor[i].quantidade);
    }
}

void ordenarVetor() {
    if (total_vetor < 2) {
        printf("Não há itens suficientes para ordenar.\n");
        return;
    }

    // Aqui eu aplico o Bubble Sort simples para ordenar os nomes em ordem alfabética
    for (int i = 0; i < total_vetor - 1; i++) {
        for (int j = 0; j < total_vetor - i - 1; j++) {
            // Se o de trás vir depois alfabeticamente que o da frente, nós trocamos eles de lugar
            if (strcmp(mochila_vetor[j].nome, mochila_vetor[j + 1].nome) > 0) {
                Item temp = mochila_vetor[j];
                mochila_vetor[j] = mochila_vetor[j + 1];
                mochila_vetor[j + 1] = temp;
            }
        }
    }
    printf("Inventário por vetor ordenado com sucesso de forma alfabética!\n");
    listarVetor();
}

void buscarSequencialVetor() {
    char alvo[30];
    int encontrado = 0;
    conta_sequencial = 0; // Reseto o contador antes de começar a busca

    if (total_vetor == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    printf("\n[Vetor] Digite o nome do item para BUSCA SEQUENCIAL: ");
    scanf("%29s", alvo);
    limparBuffer();

    // Lógica Sequencial: Aqui eu passo de posição em posição olhando todos os itens
    for (int i = 0; i < total_vetor; i++) {
        conta_sequencial++; // Aqui eu conto cada comparação de string que eu faço
        
        if (strcmp(mochila_vetor[i].nome, alvo) == 0) {
            printf("\nItem Encontrado! Posição no vetor: Índice %d\n", i);
            printf("-> Nome: %s | Tipo: %s | Qtd: %d\n", mochila_vetor[i].nome, mochila_vetor[i].tipo, mochila_vetor[i].quantidade);
            encontrado = 1;
            break; // Paro o laço porque já achei
        }
    }

    if (!encontrado) {
        printf("O item \"%s\" não está na mochila.\n", alvo);
    }
    // Requisito: Exibir o número de comparações realizadas
    printf(">> Total de comparações feitas na Busca Sequencial: %d\n", conta_sequencial);
}

void buscarBinariaVetor() {
    char alvo[30];
    int inicio = 0;
    int fim = total_vetor - 1;
    int encontrado = 0;
    conta_binaria = 0; // Reseto o contador antes de começar

    if (total_vetor == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    printf("\n⚠️ ATENÇÃO: Certifique-se de que ordenou a mochila antes de usar esta busca!\n");
    printf("[Vetor] Digite o nome do item para BUSCA BINÁRIA: ");
    scanf("%29s", alvo);
    limparBuffer();

    // Lógica da Busca Binária: Aqui eu divido o espaço de busca na metade a cada passo
    while (inicio <= fim) {
        conta_binaria++; // Aqui eu conto a comparação do passo atual
        
        int meio = inicio + (fim - inicio) / 2;
        int comp = strcmp(mochila_vetor[meio].nome, alvo);

        if (comp == 0) {
            printf("\nItem Encontrado de forma rápida! Posição no vetor: Índice %d\n", meio);
            printf("-> Nome: %s | Tipo: %s | Qtd: %d\n", mochila_vetor[meio].nome, mochila_vetor[meio].tipo, mochila_vetor[meio].quantidade);
            encontrado = 1;
            break;
        }
        else if (comp > 0) {
            fim = meio - 1; // O item está na metade esquerda, então eu puxo o fim para trás
        }
        else {
            inicio = meio + 1; // O item está na metade direita, então eu empurro o início para a frente
        }
}if (!encontrado) {printf("O item "%s" não foi localizado pela Busca Binária.\n", alvo);}
// Requisito: Exibir o número de comparações realizadasprintf(">> Total de comparações feitas na Busca Binária: %d\n", conta_binaria);}
// ============================================================================
//                   IMPLEMENTAÇÃO - COMPONENTE LISTA ENCADEADA
// ============================================================================
void inserirItemLista() {// Aqui eu aloco memória dinâmica para criar a caixinha do novo nó
  No* novoNo = (No*) malloc(sizeof(No));
  if (novoNo == NULL) {
    printf("Erro de memória do sistema.\n");
    return;
  }
  printf("\n[Lista] Digite o nome do item: ");
  scanf("%29s", novoNo->dados.nome);
  printf("[Lista] Digite o tipo: ");
  scanf("%19s", novoNo->dados.tipo);
  printf("[Lista] Digite a quantidade: ");
  scanf("%d", &novoNo->dados.quantidade);
  limparBuffer();// Aqui eu aplico o encadeamento no início: liga o nó novo no antigo topo da listanovoNo->proximo = mochila_lista;
  // E o ponteiro principal vira o novo nó, atualizando a cabeça
  mochila_lista = novoNo;
  printf("Item "%s" alocado e inserido com sucesso na lista encadeada!\n", novoNo->dados.nome);
  listarLista();
}

void removerItemLista() {
  char alvo[30];
  No* atual = mochila_lista;
  No* anterior = NULL;
  
  if (mochila_lista == NULL) {
    printf("A lista encadeada já está vazia.\n");
    return;
  }
  printf("\n[Lista] Digite o nome do item para remover: ");
  scanf("%29s", alvo);
  limparBuffer();

  // Aqui nós caminhamos pelos nós procurando quem tem o nome desejado
  while (atual != NULL && strcmp(atual->dados.nome, alvo) != 0) {
    anterior = atual;
    atual = atual->proximo;
  }
  if (atual == NULL) {
    printf("Item "%s" não foi localizado na lista encadeada.\n", alvo);
    return;
  }
  // Se o item for o primeiro da fila (cabeça), faz a lista apontar para o segundo nó
  if (anterior == NULL) {
    mochila_lista = atual->proximo;
  }
  // Se estiver no meio, o anterior pula o nó atual e liga direto no próximo
  else {
    anterior->proximo = atual->proximo;
  }
  // Aqui eu desfaço o nó liberando a memória do Heap com free() para não dar vazamento
  free(atual);
  printf("Item "%s" deletado e memória liberada da lista!\n", alvo);
  listarLista();
}

void listarLista() {
  printf("\n--- CONTEÚDO DA MOCHILA (LISTA ENCADEADA) ---\n");
  No* temp = mochila_lista;
  if (temp == NULL) {
    printf("A sua lista encadeada está vazia.\n");
    return;
  }
  int c = 1;

  // Aqui eu navego de nó em nó seguindo a pista dos ponteiros até encontrar NULL
  while (temp != NULL) {
    printf("Nó [%d] -> Nome: %-12s | Tipo: %-8s | Qtd: %d\n",c++, temp->dados.nome, temp->dados.tipo, temp->dados.quantidade);
    temp = temp->proximo; // Avança para o endereço salvo no campo próximo
  }
}

void buscarSequencialLista() {
  char alvo[30];
  No* temp = mochila_lista;
  int c = 0;
  int encontrado = 0;
  conta_sequencial = 0; 
  
  // Reseto o contador da lista
  if (mochila_lista == NULL) {
    printf("A lista encadeada está vazia.\n");
    return;
  }
  printf("\n[Lista] Digite o nome do item para BUSCA SEQUENCIAL: ");
  scanf("%29s", alvo);
  limparBuffer();

  // Aqui eu faço a varredura linear caminhando pela corrente da lista
  while (temp != NULL) {
    conta_sequencial++; 
    // Aqui eu conto mais uma comparação de string realizada
    if (strcmp(temp->dados.nome, alvo) == 0) {
      printf("\nItem Encontrado na Lista Encadeada! Posição na corrente: Nó %d\n", c + 1);
      printf("-> Nome: %s | Tipo: %s | Qtd: %d\n", temp->dados.nome, temp->dados.tipo, temp->dados.quantidade);
      encontrado = 1;break;
    }
    temp = temp->proximo;c++;
  }
  if (!encontrado) {
    printf("O item "%s" não está na lista encadeada.\n", alvo);
  }
  // Requisito: Exibir o número de comparações realizadas
  printf(">> Total de comparações feitas na Lista Encadeada: %d\n", conta_sequencial);
}

void liberarLista() {
  No* atual = mochila_lista;
  No* proximo_no;

  // Aqui eu passo limpando todos os nós um por um antes do programa fechar
  while (atual != NULL) {
    proximo_no = atual->proximo; // Salvo onde está o próximo antes de apagar o atual
    free(atual); // Dou free na memória do nó atual
    atual = proximo_no; // Avanço o atual para o próximo da fila
  }
  mochila_lista = NULL; // Aterro o ponteiro inicial}
