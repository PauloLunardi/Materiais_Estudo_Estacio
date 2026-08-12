# Comunicação e Integração entre Fila e Pilha

Este documento aborda os conceitos e mecanismos técnicos necessários para realizar a comunicação e transferência condicional de dados entre uma **Fila (FIFO)** e uma **Pilha (LIFO)** na linguagem C. Essa integração é fundamental para solucionar problemas de triagem, filtragem de fluxos e redirecionamento de prioridades em tempo real.

---

## 1. O Mecanismo de Comunicação Condicional

A integração real entre estruturas de dados ocorre quando elas deixam de funcionar de forma isolada e passam a compartilhar ou transferir elementos entre si com base em regras de negócio predefinidas. 

Quando conectamos uma fila a uma pilha, estamos unindo a ordem cronológica natural de chegada com um depósito de processamento imediato ou prioritário. Para realizar essa comunicação de forma segura, o algoritmo executa um ciclo de três etapas básicas:
1.  **Consumo de Entrada (*Dequeue*):** Remove o elemento que está na frente da fila de espera, respeitando a ordem de chegada.
2.  **Análise e Filtragem (Critério):** Examina as propriedades internas do elemento coletado através de uma estrutura condicional (`if`).
3.  **Redirecionamento de Fluxo (*Push*):** Se o elemento cumprir o critério, ele é injetado diretamente no topo da pilha de prioridade. Caso contrário, ele segue o fluxo normal do sistema.

---

## 2. Analogia e Aplicação no Mundo Real

A combinação síncrona de filtros entre filas e pilhas replica perfeitamente sistemas de triagem complexos do cotidiano:

*   **Triagem Hospitalar (Atendimento Médico):** Imagine que os pacientes chegam a um pronto-socorro e entram em uma fila comum por ordem de chegada. O profissional da triagem avalia cada paciente: se a pessoa tiver mais de 60 anos (ou uma classificação de risco grave), ela é retirada da fila comum e transferida imediatamente para um bloco de atendimento prioritário (pilha de emergência), onde o último a entrar é o próximo a ser chamado.
*   **Separação de Pacotes de Rede:** Pacotes de dados chegam a um roteador em uma fila sequencial. O sistema inspeciona o cabeçalho de cada pacote; se for um pacote de voz ou vídeo em tempo real (streaming), ele é empilhado em um buffer de alta prioridade para ser transmitido antes dos dados de navegação comuns.

---

## 3. Exemplo Prático de Implementação em C

O código abaixo demonstra a integração física de estruturas em C. O programa alimenta uma fila de pessoas e, em seguida, varre essa fila filtrando e transferindo as pessoas com mais de 60 anos para uma pilha de prioridade.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

// Estrutura do Dado Útil
typedef struct {
    char nome[30];
    int idade;
} Pessoa;

// Estrutura da Fila (Controle FIFO)
typedef struct {
    Pessoa itens[MAX];
    int inicio, fim, total;
} Fila;

// Estrutura da Pilha (Controle LIFO)
typedef struct {
    Pessoa itens[MAX];
    int topo;
} Pilha;

// --- Funções de Controle da Fila ---
void inicializarFila(Fila *f) { f->inicio = 0; f->fim = 0; f->total = 0; }
int filaVazia(Fila *f) { return f->total == 0; }
int filaCheia(Fila *f) { return f->total == MAX; }

void enqueue(Fila *f, Pessoa p) {
    if (filaCheia(f)) return;
    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
}

Pessoa dequeue(Fila *f) {
    Pessoa p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
    return p;
}

// --- Funções de Controle da Pilha ---
void inicializarPilha(Pilha *p) { p->topo = -1; }
int pilhaCheia(Pilha *p) { return p->topo == MAX - 1; }

void push(Pilha *p, Pessoa val) {
    if (pb_full_checked_or_direct) {
        if (p->topo >= MAX - 1) return;
    }
    p->topo++;
    p->itens[p->topo] = val;
}

// --- Função Principal e Lógica de Integração ---
int main() {
    Fila fila_espera;
    Pilha pilha_prioridade;

    inicializarFila(&fila_espera);
    inicializarPilha(&pilha_prioridade);

    // 1. Inserção de dados mistos na fila de entrada
    Pessoa a = {"Carlos", 20};
    Pessoa b = {"Ana (Idosa)", 65};
    Pessoa c = {"Bruno", 34};
    Pessoa d = {"Julia (Idosa)", 72};

    enqueue(&fila_espera, a);
    enqueue(&fila_espera, b);
    enqueue(&fila_espera, c);
    enqueue(&fila_espera, d);

    printf("--- INICIANDO PROCESSO DE TRIAGEM E FILTRAGEM ---\n");

    // 2. Loop de Integração: esvazia a fila e alimenta a pilha condicionalmente
    while (!filaVazia(&fila_espera)) {
        Pessoa atual = dequeue(&fila_espera); // Retira da frente da fila (FIFO)

        // Aplicação do Filtro: Critério de idade maior que 60 anos
        if (atual.idade > 60) {
            push(&pilha_prioridade, atual); // Transfere para o topo da pilha (LIFO)
            printf("[Triagem] %s (%d anos) direcionado para a Pilha de Prioridade.\n", atual.nome, atual.idade);
        } else {
            printf("[Triagem] %s (%d anos) mantido no fluxo de atendimento comum.\n", atual.nome, atual.idade);
        }
    }

    // 3. Exibição dos resultados filtrados na Pilha (Comportamento LIFO)
    printf("\n--- PACIENTES NA PILHA DE PRIORIDADE (Topo -> Base) ---\n");
    for (int i = pilha_prioridade.topo; i >= 0; i--) {
        printf("Prioridade [%d] -> Nome: %s | Idade: %d\n", i + 1, pilha_prioridade.itens[i].nome, pilha_prioridade.itens[i].idade);
    }

    return 0;
}
```

---

## 4. Benefícios Arquiteturais da Estratégia

O isolamento e a transferência controlada de dados entre modelos de acesso diferentes oferecem vantagens significativas para o design de sistemas profissionais:
*   **Garantia de Integridade:** Permite aplicar filtros e regras de classificação complexas sem corromper ou misturar os dados originais durante a execução.
*   **Alternância de Perspetivas:** O sistema consegue lidar perfeitamente com o fluxo contínuo e ordenado de requisições gerais (fila) e, ao mesmo tempo, dar respostas e tratamentos imediatos a exceções ou urgências (pilha).
*   **Modularização Limpa:** A lógica de triagem fica concentrada em um ponto específico do código, facilitando a alteração de critérios (mudar o filtro de idade ou adicionar novas condições) sem a necessidade de reescrever as funções de manipulação das estruturas.
