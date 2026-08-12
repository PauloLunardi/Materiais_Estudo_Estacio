# Declaração, Implementação e Uso de Pilhas

Este documento apresenta o guia técnico completo para a construção, gerenciamento e manipulação de uma pilha estática utilizando vetores e estruturas compostas (`structs`) na linguagem C. O exemplo prático gerencia dados do tipo `Pessoa`, demonstrando de forma granular a aplicação do comportamento LIFO (Last In, First Out) e as validações necessárias para assegurar a estabilidade do sistema.

---

## 1. Declaração da Estrutura de Dados

A arquitetura de uma pilha estática fundamenta-se em um vetor de tamanho fixo com capacidade delimitada e uma variável inteira que rastreia dinamicamente o índice do último elemento inserido.

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define a capacidade limite de armazenamento da pilha
 
// Struct do Elemento: Armazena o registro de dados úteis de cada item
typedef struct {
    char nome[30];
    int idade;
} Pessoa;
 
// Struct da Pilha: Engine de controle sequencial contíguo
typedef struct {
    Pessoa itens[MAX]; // Vetor contendo os elementos empilhados
    int topo;          // Variável indicadora do índice do elemento mais recente
} Pilha;
```

---

## 2. Rotinas de Inicialização e Verificação de Estado

Antes de executar operações de leitura e escrita, a pilha precisa ser preparada na memória. Atribui-se o valor `-1` ao seletor de topo para sinalizar que a estrutura está inicialmente limpa.

### A. Inicializar Pilha
Aterra o índice de controle, definindo o ponto de partida padrão para inserções futuras.
```c
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}
```

### B. Verificar Pilha Vazia
Valida se a estrutura possui dados disponíveis para remoção ou consulta. Evita erros de subfluxo (*underflow*).
```c
int pilhaVazia(Pilha *p) {
    return p->topo == -1; // Retorna 1 (verdadeiro) se o topo for -1
}
```

### C. Verificar Pilha Cheia
Valida se a estrutura atingiu o limite de sua capacidade física. Evita erros de transbordo (*overflow*).
```c
int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1; // Retorna 1 (verdadeiro) se o topo atingiu o último índice (MAX - 1)
}
```

---

## 3. Lógica das Operações de Manipulação LIFO

As funções abaixo realizam a movimentação e consulta de elementos obedecendo estritamente à política de acesso exclusivo pelo topo, apresentando complexidade de tempo constante $O(1)$.

### A. Inserir (Push)
Incrementa o ponteiro numérico do topo e realiza a cópia física do novo elemento para a nova posição do vetor.
```c
void push(Pilha *p, Pessoa nova) {
    // Trava de segurança contra violação de limite
    if (pilhaCheia(p)) {
        printf("Erro: Pilha cheia. Nao e possivel inserir.\n");
        return;
    }
 
    p->topo++;                  // Avança o índice do topo para a próxima posição vaga
    p->itens[p->topo] = nova;   // Grava o novo registro na posição correspondente
}
```

### B. Remover (Pop)
Extrai e entrega os dados do elemento mais recente por referência e recua o seletor do topo, tornando o dado antigo inacessível para a lógica da pilha.
```c
void pop(Pilha *p, Pessoa *removida) {
    // Trava de segurança contra leitura de endereços inválidos
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia. Nao e possivel remover.\n");
        return;
    }

    *removida = p->itens[p->topo]; // Transfere os dados do topo para a variável externa
    p->topo--;                     // Recua o índice para desempilhar o elemento
}
```

### C. Consulta (Peek / Espiar)
Duplica os dados contidos no topo para um ponteiro externo, operando em modo de leitura estrita para inspecionar a informação sem gerar modificações estruturais.
```c
void peek(Pilha *p, Pessoa *visualizada) {
    // Trava de segurança: impede a varredura em estruturas sem dados
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia. Nada para espiar.\n");
        return;
    }

    *visualizada = p->itens[p->topo]; // Copia o conteúdo atual sem alterar p->topo
}
```

---

## 4. Varredura e Exibição do Console

A renderização visual de uma pilha deve respeitar o fluxo real de desempilhamento, iniciando o laço a partir do índice `topo` corrente e descendo progressivamente até alcançar o primeiro elemento inserido na base (índice `0`).

```c
void mostrarPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Pilha (topo -> base):\n");
    // O laço decrementa o contador para mimetizar o comportamento LIFO
    for (int i = p->topo; i >= 0; i--) {
        printf("  [%d] Nome: %-15s | Idade: %d\n", i, p->itens[i].nome, p->itens[i].idade);
    }
    printf("\n");
}
```

---

## 5. Integração de Fluxo e Execução no `main()`

O bloco principal instancia a pilha, executa comandos sucessivos de escrita, remove dados controladamente e faz auditorias com o método `peek`:

```c
int main() {
    Pilha p;
    inicializarPilha(&p); // Configuração obrigatória do topo para -1
 
    // Instanciação dos registros de teste
    Pessoa a = {"Ana", 20};
    Pessoa b = {"Bruno", 35};
    Pessoa c = {"Carlos", 28};
 
    // Execução sequencial de empilhamento (Push)
    push(&p, a);
    push(&p, b);
    push(&p, c);
 
    mostrarPilha(&p); // Apresenta a pilha completa: Carlos (topo), Bruno, Ana (base)
 
    // Remoção do elemento mais recente (Pop)
    Pessoa removida;
    pop(&p, &removida);
    printf("Pessoa removida do topo: %s, %d anos\n\n", removida.nome, removida.idade);
 
    mostrarFilaExemplo(&p); // Mostra a pilha atualizada: Bruno (novo topo), Ana (base)
 
    // Consulta ao topo sem remoção (Peek)
    Pessoa topoAtual;
    peek(&p, &topoAtual);
    printf("Espiando o topo atual: %s, %d anos\n", topoAtual.nome, topoAtual.idade);
 
    return 0;
}
```
