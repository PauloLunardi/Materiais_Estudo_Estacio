# Declaração, Implementação e Uso de Filas

Este documento apresenta o guia técnico completo para a construção e manipulação de uma fila circular estática na linguagem C. O exemplo utiliza uma estrutura composta para gerenciar o fluxo cronológico de cadastros de pessoas, aplicando travas de segurança contra estouro de capacidade e garantindo o reaproveitamento cíclico de memória.

---

## 1. Definição das Estruturas de Dados

Para construir uma fila organizada, o primeiro passo é segmentar as responsabilidades. Criamos uma estrutura para representar o elemento útil (o dado que será armazenado) e outra estrutura para gerenciar a fila em si (vetor de dados e variáveis de controle).

### A. Struct do Elemento (Dado Útil)
Representa a entidade que navegará pela estrutura. Neste cenário, cada item corresponde a uma pessoa contendo propriedades de texto e número inteiro.
```c
typedef struct {
    char nome[30];
    int idade;
} Pessoa;
```

### B. Struct da Fila (Engine de Controle)
Agrupa o vetor fixo que servirá de armazenamento físico e os ponteiros numéricos encarregados de monitorar o estado e o ciclo da fila.
```c
#define MAX 5

typedef struct {
    Pessoa itens[MAX]; // Vetor fixo para armazenar os elementos
    int inicio;        // Índice que rastreia a cabeça (frente) da fila
    int fim;           // Índice que rastreia a cauda (final) da fila
    int total;         // Contador do número absoluto de elementos ativos
} Fila;
```

---

## 2. Funções de Inicialização e Validação de Estado

Antes de submeter a fila a qualquer operação de leitura ou escrita, os seletores de controle precisam ser aterrados na memória para evitar o consumo de lixo lógico residuo de outras execuções.

### A. Inicializar Fila
Zera o contador e posiciona os dois seletores de fronteira no índice inicial do vetor.
```c
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}
```

### B. Checagem de Limites (Fila Cheia e Vazia)
As validações bloqueiam operações inválidas de escrita (*overflow*) e leitura (*underflow*), protegendo a integridade do sistema.
```c
// Retorna 1 se o vetor atingiu a capacidade máxima e 0 caso contrário
int filaCheia(Fila *f) {
    return f->total == MAX;
}

// Retorna 1 se a estrutura não possui nenhum elemento ativo e 0 caso contrário
int filaVazia(Fila *f) {
    return f->total == 0;
}
```

---

## 3. Lógica das Operações de Fluxo (FIFO)

As funções de inserção e remoção implementam o comportamento cronológico da fila através do uso do operador módulo (`%`), que força os índices a rotacionarem de volta ao início assim que extrapolam o limite máximo do vetor.

### A. Inserir (Enqueue)
Insere o dado no índice apontado por `fim` e calcula de forma circular a próxima coordenada livre.
```c
void inserir(Fila *f, Pessoa p) {
    // Trava de segurança contra estouro de capacidade
    if (filaCheia(f)) {
        printf("Erro: Fila cheia. Nao e possivel inserir.\n");
        return;
    }
 
    f->itens[f->fim] = p;          // Grava o elemento no final da fila
    f->fim = (f->fim + 1) % MAX;   // Avanço circular do ponteiro de fim
    f->total++;                    // Incrementa o número de itens ativos
}
```

### B. Remover (Dequeue)
Extrai o elemento mais antigo copiando-o por referência para uma variável externa e avança o indicador de início.
```c
void remover(Fila *f, Pessoa *p) {
    // Trava de segurança contra leitura de posições inválidas
    if (filaVazia(f)) {
        printf("Erro: Fila vazia. Nao e possivel remover.\n");
        return;
    }

    *p = f->itens[f->inicio];             // Entrega o dado da frente por referência
    f->inicio = (f->inicio + 1) % MAX;     // Avanço circular do ponteiro de início
    f->total--;                            // Decrementa o número de itens ativos
}
```

---

## 4. Exibição e Depuração Visual

A listagem de uma fila circular não pode ser feita por um laço `for` linear comum de `0` a `MAX`, pois o início da fila se desloca conforme os elementos saem. O percorrimento correto deve partir do índice `inicio` e saltar de forma cíclica baseando-se estritamente na quantidade de elementos ativos (`total`).

```c
void mostrarFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Fila Atual: ");
    // O laço acompanha a contagem de elementos (i) enquanto calcula o índice real (idx) via módulo
    for (int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx + 1) % MAX) {
        printf("[%s, %d] ", f->itens[idx].nome, f->itens[idx].idade);
    }
    printf("\n");
}
```

---

## 5. Integração e Fluxo de Execução no `main()`

O bloco principal orquestra a declaração local, inicializa os ponteiros e executa as transações sequenciais simulando o fluxo de atendimento FIFO:

```c
int main() {
    Fila f;
    inicializarFila(&f);  // Configuração obrigatória inicial

    // 1. Entrada de dados na estrutura
    Pessoa p1 = {"Joao", 25};
    Pessoa p2 = {"Maria", 30};
    inserir(&f, p1);
    inserir(&f, p2);
 
    mostrarFila(&f);  // Exibição do estado inicial [Joao, Maria]
 
    // 2. Processamento e remoção do primeiro da vez
    Pessoa removida;
    remover(&f, &removida);  
 
    printf("Pessoa atendida e removida: %s, %d anos\n", removida.nome, removida.idade);
 
    mostrarFila(&f);  // Exibição do estado pós-atendimento [Maria]
 
    return 0;
}
```
