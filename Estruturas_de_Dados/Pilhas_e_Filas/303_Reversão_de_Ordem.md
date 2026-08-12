# Reversão de Ordem de uma Fila Utilizando Pilha Auxiliar

Este documento apresenta o conceito técnico e o guia prático para realizar a reversão da ordem dos elementos de uma **Fila (FIFO)** utilizando uma **Pilha (LIFO)** como estrutura de suporte temporário. Essa técnica demonstra como o uso combinado de estruturas com políticas de acesso opostas pode resolver problemas complexos de reordenação com elegância e eficiência.

---

## 1. O Princípio da Reversão por Oposição Lógica

Uma fila, por sua natureza cronológica, não oferece mecanismos nativos para acessar ou inverter seus elementos a partir do final. No entanto, a pilha possui a propriedade intrínseca de inverter sequências devido ao seu comportamento **LIFO (Last In, First Out)**. 

Ao injetarmos o fluxo de uma fila para dentro de uma pilha e, posteriormente, consumirmos essa pilha de volta para uma nova fila, o comportamento reverso acontece de forma automática.

### O Processo de Transferência em Duas Etapas
1.  **Esvaziamento e Empilhamento (*Fila -> Pilha*):** Os elementos são removidos da frente da fila original (`dequeue`) e imediatamente inseridos no topo da pilha auxiliar (`push`). Dessa forma, o primeiro elemento a entrar na fila fica preso na base da pilha, enquanto o último elemento a entrar na fila torna-se o novo topo da pilha.
2.  **Desempilhamento e Carga (*Pilha -> Nova Fila*):** Os elementos são removidos do topo da pilha (`pop`) e inseridos sequencialmente no final de uma nova fila (`enqueue`). Como o topo da pilha continha o último elemento da fila original, ele passa a ser o primeiro elemento da nova fila, consolidando a inversão completa do fluxo.

---

## 2. Analogias e Aplicações Práticas

A combinação dessas duas estruturas para inverter fluxos simula rotinas reais do desenvolvimento de sistemas:

*   **Processamento Reverso de Comandos:** Em sistemas que capturam ações de usuários em tempo real para auditoria (salvos em fila por ordem de ocorrência), se o sistema precisar disparar um processo para "desfazer" ou analisar o impacto de trás para a frente, o uso da pilha reordena essas instruções instantaneamente.
*   **Abertura de Containers de Carga:** Imagine caixas de suprimentos que chegam a um centro de distribuição em um caminhão e são descarregadas em uma esteira (fila). Se essas caixas precisarem ser guardadas em um depósito vertical onde o acesso só é possível pela frente (pilha), ao retirá-las do depósito para colocá-las em um novo caminhão de entregas, a ordem de distribuição terá sido completamente invertida em relação à chegada original.

---

## 3. Exemplo Prático de Implementação em C

O código abaixo ilustra a integração física das duas estruturas dentro da função `main()`. O programa cria uma fila de cadastros, utiliza a pilha auxiliar para inverter a ordem dos dados e gera um novo fluxo invertido:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX 50
 
// Estrutura do Elemento
typedef struct {
    char nome[30];
    int idade;
} Pessoa;
 
// Estrutura da Fila (Controle FIFO)
typedef struct {
    Pessoa dados[MAX];
    int inicio, fim;
} Fila;
 
// Estrutura da Pilha (Controle LIFO)
typedef struct {
    Pessoa dados[MAX];
    int topo;
} Pilha;
 
// --- Funções de Controle ---

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}
 
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}
 
void inserir(Fila *f, Pessoa p) {
    if (f->fim < MAX) {
        f->dados[f->fim++] = p;
    }
}
 
Pessoa remover(Fila *f) {
    return f->dados[f->inicio++];
}
 
void push(Pilha *p, Pessoa pes) {
    if (p->topo < MAX - 1) {
        p->dados[++p->topo] = pes;
    }
}
 
Pessoa pop(Pilha *p) {
    return p->dados[p->topo--];
}
 
void exibirFila(Fila f) {
    for (int i = f.inicio; i < f.fim; i++) {
        printf("  -> Nome: %-10s | Idade: %d anos\n", f.dados[i].nome, f.dados[i].idade);
    }
}
 
// --- Função Principal e Orquestração ---
int main() {
    Fila filaOriginal, filaInvertida;
    Pilha auxiliar;
 
    inicializarFila(&filaOriginal);
    inicializarFila(&filaInvertida);
    inicializarPilha(&auxiliar);
 
    // População de dados em ordem cronológica original
    Pessoa pessoas[] = {
        {"Carlos", 45}, {"Joana", 62}, {"Lucas", 30}, {"Maria", 75}
    };
 
    for (int i = 0; i < 4; i++) {
        inserir(&filaOriginal, pessoas[i]);
    }
 
    printf("--- ESTADO INICIAL DA FILA ORIGINAL ---\n");
    exibirFila(filaOriginal);
 
    // ETAPA 1: Esvazia a fila original jogando tudo para o topo da pilha
    while (filaOriginal.inicio < filaOriginal.fim) {
        push(&auxiliar, remover(&filaOriginal));
    }
 
    // ETAPA 2: Consome o topo da pilha jogando de volta para a nova fila
    while (auxiliar.topo >= 0) {
        inserir(&filaInvertida, pop(&auxiliar));
    }
 
    printf("\n--- ESTADO FINAL DA FILA INVERTIDA ---\n");
    exibirFila(filaInvertida);
 
    return 0;
}
```

### 💻 Saída Esperada no Terminal:
```text
--- ESTADO INICIAL DA FILA ORIGINAL ---
  -> Nome: Carlos     | Idade: 45 anos
  -> Nome: Joana      | Idade: 62 anos
  -> Nome: Lucas      | Idade: 30 anos
  -> Nome: Maria      | Idade: 75 anos

--- ESTADO FINAL DA FILA INVERTIDA ---
  -> Nome: Maria      | Idade: 75 anos
  -> Nome: Lucas      | Idade: 30 anos
  -> Nome: Joana      | Idade: 62 anos
  -> Nome: Carlos     | Idade: 45 anos
```

---

## 4. Análise de Eficiência e Conclusões

*   **Segurança Estrutural:** O uso da pilha como ponte de dados temporária garante que os elementos sejam reorganizados sem que os ponteiros internos originais da fila de destino sejam violados por acessos manuais incorretos a índices do array.
*   **Complexidade de Tempo Linear:** O algoritmo opera com complexidade de tempo linear **$O(n)$**, pois processa cada elemento um número fixo de vezes (um ciclo para empilhar e um ciclo para desempilhar), garantindo alta velocidade mesmo para vetores grandes.
*   **Flexibilidade Arquitetural:** Este modelo de comunicação mútua prepara o desenvolvedor para implementar padrões de projeto complexos de gerenciamento de memória e histórico de contexto, muito requisitados no desenvolvimento de softwares profissionais.
