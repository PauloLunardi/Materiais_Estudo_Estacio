# Listas Encadeadas em C

Este documento apresenta os conceitos fundamentais sobre **Listas Encadeadas**, explorando suas variações (simples, duplamente encadeadas e circulares) na linguagem C. Compreender o uso de ponteiros para conectar elementos de forma não contígua na memória é essencial para criar estruturas de dados dinâmicas, flexíveis e altamente eficientes.

---

## 1. O Conceito de Lista Encadeada

Uma **lista encadeada** é uma estrutura de dados dinâmica em que cada elemento (chamado de **nó**) contém uma informação e um ponteiro que indica onde está localizado o próximo elemento da sequência.

###  Diferença Crucial para os Vetores
*   **Nos Vetores (Listas Estáticas):** Todos os elementos estão enfileirados em ordem física na memória, como em uma estante de livros com espaços fixos. Se você quiser adicionar um novo item no meio, terá que deslocar todos os outros para o lado.
*   **Nas Listas Encadeadas:** Os elementos **não precisam** estar armazenados em posições vizinhas ou contíguas da memória. Eles podem estar espalhados em qualquer lugar do sistema operacional, contanto que o elemento anterior saiba o endereço do próximo. Isso oferece grande agilidade em cenários onde inserções e remoções de dados acontecem com frequência.

>  **Analogia da Fila Humana:** Imagine uma fila de pessoas em que cada uma segura apenas a mão da próxima. A posição geográfica de cada pessoa na sala não importa — elas só precisam estar conectadas por suas mãos. Se alguém no meio da fila decidir sair, basta que os vizinhos soltem a mão dessa pessoa e deem as mãos novamente entre si. A corrente se refaz sem que ninguém precise mudar de lugar físico.

---

## 2. Tipos de Listas Encadeadas e suas Estruturas

Acompanhe as quatro variações de listas encadeadas e como representá-las através de `structs` na linguagem C:

###  A. Lista Encadeada Simples
É composta por nós que apontam exclusivamente para o próximo elemento da sequência. O último nó aponta para `NULL`, indicando o fim da lista. Cada nó possui:
1.  Um campo de dados (Ex: um número inteiro).
2.  Um ponteiro para o próximo nó.

```c
typedef struct No {
    int dado;          // Informação armazenada
    struct No *proximo; // Ponteiro para a próxima caixinha (nó)
} No;
```

####  Exemplo Prático: Criação Manual de 3 Nós
Abaixo está o exemplo prático de como alocar, preencher e encadear manualmente três nós distintos com os valores `10`, `20` e `30`:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

int main() {
    // 1. Criação e alocação dinâmica dos três nós na memória RAM
    No *primeiro = (No *) malloc(sizeof(No));
    No *segundo  = (No *) malloc(sizeof(No));
    No *terceiro = (No *) malloc(sizeof(No));

    // ⚠️ Validação de Segurança Obrigatória
    if (primeiro == NULL || segundo == NULL || terceiro == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // 2. Atribuição de valores utilizando o operador seta (->)
    primeiro->dado = 10;
    segundo->dado  = 20;
    terceiro->dado = 30;

    // 3. Amarração/Encadeamento dos nós através de seus endereços
    primeiro->proximo = segundo;  // O primeiro aponta para a localização do segundo
    segundo->proximo  = terceiro; // O segundo aponta para a localização do terceiro
    terceiro->proximo = NULL;     // O último aponta para NULL (fim da lista)

    // 4. Navegação e Exibição da lista usando um ponteiro auxiliar
    No *atual = primeiro;
    while (atual != NULL) {
        printf("Valor do No: %d\n", atual->dado);
        atual = atual->proximo; // Avança para o próximo endereço
    }

    // 5. Liberação obrigatória da memória para evitar Memory Leaks
    free(primeiro);
    free(segundo);
    free(terceiro);

    return 0;
}
```

---

###  B. Lista Duplamente Encadeada
Diferente da lista simples que só permite avançar, a lista duplamente encadeada oferece maior flexibilidade de navegação (do início para o fim e do fim para o início), facilitando inserções e remoções rápidas em qualquer posição. Cada nó possui 3 partes:
1.  Um campo de dados.
2.  Um ponteiro para o próximo nó.
3.  Um ponteiro para o nó anterior.

```c
typedef struct NoDuplo {
    int dado;
    struct NoDuplo *proximo;  // Endereço do vizinho da frente
    struct NoDuplo *anterior; // Endereço do vizinho de trás
} NoDuplo;
```

---

###  C. Lista Circular Simples
É uma variação da lista encadeada simples em que o último nó da estrutura **não aponta para `NULL`**, mas sim de volta para o primeiro nó da lista. 
*   **Vantagem:** Forma um ciclo fechado ininterrupto, permitindo que a navegação continue indefinidamente a partir de qualquer ponto, sem um fim definido.

```c
typedef struct NoCircular {
    int dado;
    struct NoCircular *proximo; // Se for o último nó, apontará para o primeiro
} NoCircular;
```

---

###  D. Lista Circular Duplamente Encadeada
Esta estrutura combina o poder dos dois conceitos anteriores. Ela é duplamente encadeada (possui ponteiros para frente e para trás) e é circular, o que significa que o último nó aponta para o primeiro e o primeiro nó aponta para o último, criando um ciclo bidirecional fechado.

```c
typedef struct NoCircularDuplo {
    int dado;
    struct NoCircularDuplo *proximo;  // Se for o último, aponta para o primeiro
    struct NoCircularDuplo *anterior; // Se for o primeiro, aponta para o último
} NoCircularDuplo;
```

---

## ⚠️ Cuidados Críticos com a Memória (Boas Práticas)

Lidar com estruturas encadeadas dinamicamente exige atenção redobrada com os ponteiros para manter o software seguro e previsível:
1.  **Validação Oblíqua:** Sempre teste se a função `malloc()` retornou `NULL` antes de tentar ler ou escrever propriedades em um nó.
2.  **Par Perfeito:** Lembre-se de desalocar cada nó individualmente com o comando `free()` quando a estrutura não for mais necessária, eliminando vazamentos de memória (*memory leaks*).
3.  **Segurança de Ponteiro:** Certifique-se de que os ponteiros de fim de linha apontem de fato para `NULL` ou para os nós circulares corretos. Tentar ler dados em uma área inválida da memória resultará no encerramento abrupto do sistema por `Segmentation Fault`.
