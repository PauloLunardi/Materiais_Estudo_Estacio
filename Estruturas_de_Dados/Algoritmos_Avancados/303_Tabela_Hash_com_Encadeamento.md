# Tabela Hash com Encadeamento (Chaining)

Este documento apresenta a especificação técnica e o guia de implementação para uma **Tabela Hash com Encadeamento Separado** na linguagem C. Essa arquitetura resolve o problema inevitável das colisões acoplando uma lista encadeada dinâmica em cada índice do vetor principal, garantindo flexibilidade, estabilidade e mantendo o tempo médio de acesso constante.

---

## 1. O Problema das Colisões e a Solução por Encadeamento

Uma tabela hash converte chaves abstratas em índices de um array para proporcionar buscas rápidas. No entanto, quando duas ou mais chaves diferentes produzem exatamente o mesmo índice através do cálculo da função hash, ocorre o fenômeno da **Colisão**. Como o vetor físico só consegue armazenar um elemento direto por posição, o sistema precisa de uma estratégia para reter múltiplos dados sob a mesma coordenada.

O **Encadeamento Separado (*Chaining*)** resolve esse gargalo transformando cada posição do vetor em uma **lista ligada dinâmica**. Quando uma nova chave colide em um índice já ocupado, ela não sobrescreve o dado anterior; em vez disso, ela é encapsulada em um novo nó e conectada como um elo na corrente daquela posição específica.

> **Analogia das Caixas de Correio:** Imagine um armário de caixas de correio numeradas. Cada número de caixa representa um índice do vetor. Quando várias cartas (nós) são direcionadas para a mesma caixinha de correio (colisão), elas são simplesmente empilhadas umas atrás das outras dentro daquela mesma caixa.

---

## 2. Modelagem das Estruturas e Alocação

Para implementar esta arquitetura, criamos um tipo estruturado para agir como o nó da lista e um array de ponteiros que servirá como a nossa tabela base de espalhamento.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 10

// Estrutura de um nó da lista ligada (Nodo)
typedef struct Nodo {
    char nome[50];              // Campo que armazena a string de dados
    struct Nodo* proximo;       // Ponteiro que conecta o elo seguinte da lista
} Nodo;

// A tabela hash é instanciada como um vetor de ponteiros para estruturas do tipo Nodo
Nodo* tabela_hash[TAMANHO_TABELA];
```
*   **Vetor de Ponteiros:** O array `tabela_hash` possui 10 posições de memória.
*   **Cabeça de Lista:** Cada índice do array atua como o ponteiro `head` (início) de uma lista encadeada independente, nascendo configurado com `NULL`.

---

## 3. Função de Espalhamento (Hash Simples)

A engrenagem encarregada de transformar a cadeia de caracteres em um índice válido de `0` a `9` opera acumulando os valores ASCII das letras e aplicando a redução pelo operador módulo (`%`).

```c
int funcao_hash(const char* chave) {
    int soma = 0;
    // Varre o texto acumulando a assinatura numérica de cada caractere
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }
    // Restringe o resultado estritamente ao tamanho limite da tabela (0 a 9)
    return soma % TAMANHO_TABELA;
}
```

> **Simulação Aritmética:** Se passarmos a chave `"Ana"`, o processador soma os caracteres $(65 + 110 + 97 = 272)$. Aplicando a fórmula $272 \pmod{10}$, extraímos o resto **`2`**. Portanto, `"Ana"` será catalogada estritamente no índice `2` da tabela.

---

## 4. Operações Fundamentais de Gerenciamento

### A. Inserir um Nome (Enqueue no Início)
Para maximizar a velocidade de escrita, o novo nó é alocado dinamicamente e inserido diretamente na **cabeça (*head*)** da lista do índice correspondente. Isso elimina a necessidade de percorrer a fila inteira, garantindo tempo de execução imediato.

```c
void inserir(const char* nome) {
    int indice = funcao_hash(nome); // Executa o mapeamento da chave

    // Aloca a caixinha do nó dinamicamente no Heap
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(novo->nome, nome);

    // Manobra de Encadeamento: o novo nó aponta para quem estava na frente antes
    novo->proximo = tabela_hash[indice];
    // A tabela assume o novo nó como o primeiro da fila daquela posição
    tabela_hash[indice] = novo;
}
```

### B. Buscar um Nome
O algoritmo calcula o índice, acessa o ponteiro inicial daquela célula e caminha de nó em nó realizando testes de igualdade de texto via `strcmp()` até localizar o alvo ou bater em `NULL`.

```c
Nodo* buscar(const char* nome) {
    int indice = funcao_hash(nome); // Descobre em qual gaveta olhar
    Nodo* atual = tabela_hash[indice]; // Posiciona o ponteiro no início da lista
    
    // Caminha pela corrente de colisões
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual; // Sucesso: Encontrou o registro na memória
        }
        atual = atual->proximo; // Avança para o próximo elo
    }
    return NULL; // Falha: O elemento não está cadastrado no sistema
}
```

### C. Remover um Nome
A exclusão exige uma varredura cuidadosa para rastrear o elemento **anterior**. Precisamos do ponteiro anterior para reencadear a lista (ligar o elemento de trás direto no da frente) antes de dar o `free`, evitando que a corrente se quebre na memória.

```c
void remover(const char* nome) {
    int indice = funcao_hash(nome);
    Nodo* atual = tabela_hash[indice];
    Nodo* anterior = NULL; // Ponteiro de suporte para não quebrar a corrente
    
    while (atual != NULL) {
        // Localizou o nó alvo que deve ser excluído
        if (strcmp(atual->nome, nome) == 0) {
            // Cenário 1: O elemento era o primeiro da fila (cabeça)
            if (anterior == NULL) {
                tabela_hash[indice] = atual->proximo; 
            } 
            // Cenário 2: O elemento estava no meio ou no final da fila
            else {
                anterior->proximo = atual->proximo; // O de trás pula o atual e liga no da frente
            }
            free(atual); // Devolve a memória RAM para o sistema operacional
            printf("'%s' removido com sucesso.\n", nome);
            return;
        }
        anterior = atual; // O anterior avança para onde o atual estava
        atual = atual->proximo; // O atual avança uma casa
    }
    printf("'%s' nao foi localizado para remocao.\n", nome);
}
```

---

## 5. Orquestração e Simulação no `main()`

O bloco principal do software simula o fluxo completo de transações, demonstrando visualmente como o sistema gerencia colisões latentes na mesma célula da tabela:

```c
int main() {
    // Inicialização (Boa prática: garantir que a tabela comece limpa)
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela_hash[i] = NULL;
    }

    // Inserção de dados
    inserir("Ana");
    inserir("Bruno");
    inserir("Carlos");
    inserir("Amanda"); // Elemento que pode colidir no mesmo índice de "Ana"
 
    // Testes de Consulta
    printf("Buscando 'Bruno': %s\n", buscar("Bruno") ? "Encontrado" : "Não encontrado");
    printf("Buscando 'João': %s\n\n", buscar("João") ? "Encontrado" : "Não encontrado");
 
    // Testes de Exclusão Controlada
    remover("Carlos"); // Deve remover ajustando ponteiros
    remover("João");   // Deve disparar a mensagem de aviso de ausência
 
    return 0;
}
```

### Comportamento Interno dos Dados:
*   As chaves `"Ana"` e `"Amanda"` produzem colisões devido a assinaturas semelhantes na função de espalhamento. O encadeamento por lista ligada organiza ambas na célula `2` do array de ponteiros automaticamente sem perda de informações.
*   Ao acionar o comando de remoção para uma chave ausente (`"João"`), as travas lógicas interceptam a leitura ao atingirem o fim da linha (`NULL`), emitindo o feedback correto de falha e blindando o sistema contra travamentos.
