# Percursos em Árvores Binárias: Pré-Ordem, Em Ordem e Pós-Ordem

Este documento apresenta os três métodos clássicos de **percorrimento (travessia)** em árvores binárias na linguagem C. Como as árvores não são estruturas lineares, caminhar por seus nós exige uma estratégia sistemática. A mudança na ordem de visitação altera completamente a sequência dos dados, atendendo a diferentes necessidades de engenharia de software.

---

## 1. O que é um Percurso?

Percorrer uma árvore significa visitar todos os seus nós exatamente uma vez. Devido à natureza ramificada da estrutura, existem três formas clássicas de realizar essa travessia baseando-se no momento em que o **nó atual (pai)** é processado em relação aos seus filhos da **esquerda** e da **direita**.

---

## 2. Tipos de Percurso e Suas Aplicações

### 📁 A. Pré-Ordem (Pre-Order)
*   **Ordem de Visita:** Nó Atual \(\rightarrow\) Subárvore Esquerda \(\rightarrow\) Subárvore Direita.
*   **Características:** Realiza um reconhecimento inicial, identificando o ponto principal antes de descer para as ramificações.
*   **Caso de Uso Ideal:** Excelente para **clonar/copiar uma árvore** ou salvar sua estrutura original em um arquivo, já que os elementos são gravados na ordem exata de sua hierarquia.

### 📁 B. Em Ordem (In-Order)
*   **Ordem de Visita:** Subárvore Esquerda \(\rightarrow\) Nó Atual \(\rightarrow\) Subárvore Direita.
*   **Características:** A travessia caminha até o extremo esquerdo antes de começar a exibir os dados.
*   **Caso de Uso Ideal:** Crucial para **Árvores Binárias de Busca (BST)**. Quando aplicado a uma BST, este percurso recupera e exibe todos os elementos em **ordem crescente** perfeita (numérica ou alfabética).

### 📁 C. Pós-Ordem (Post-Order)
*   **Ordem de Visita:** Subárvore Esquerda \(\rightarrow\) Subárvore Direita \(\rightarrow\) Nó Atual.
*   **Características:** O nó pai é deixado por último, processando os filhos primeiro.
*   **Caso de Uso Ideal:** Perfeito para **deletar a árvore e liberar memória** com segurança (garante que os filhos sejam apagados antes do pai, evitando ponteiros perdidos) e para **resolver expressões matemáticas** complexas.

---

## 3. Diagrama Visual de Sequenciamento (Arte ASCII)

Para compreender o impacto de cada estratégia, observe a árvore de teste abaixo:

```text
       [ A ]          ● PRÉ-ORDEM:  A -> B -> D -> E -> C
      /     \
   [ B ]   [ C ]      ● EM ORDEM:   D -> B -> E -> A -> C
   /   \
 [ D ] [ E ]          ● PÓS-ORDEM:  D -> E -> B -> C -> A
```

---

## 4. Implementação Prática em C (Lógica Recursiva)

Graças à natureza recursiva das árvores, as três funções utilizam a mesma estrutura de código. A única diferença reside na linha onde o comando `printf` (a visita real) é posicionado:

```c
#include <stdio.h>

// Definição base da estrutura do nó
struct No {
    char valor[50];
    struct No* esquerda;
    struct No* direita;
};

// 1. Caminhamento em Pré-Ordem (Imprime primeiro, depois desce)
void preOrdem(struct No* raiz) {
    if (raiz != NULL) {
        printf("%s ", raiz->valor); // Visita o nó atual (Pai)
        preOrdem(raiz->esquerda);   // Delega para o galho esquerdo
        preOrdem(raiz->direita);    // Delega para o galho direito
    }
}
 
// 2. Caminhamento Em Ordem (Desce tudo para a esquerda, imprime, depois vai para a direita)
void emOrdem(struct No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);   // Delega para o galho esquerdo
        printf("%s ", raiz->valor); // Visita o nó atual (Pai)
        emOrdem(raiz->direita);    // Delega para o galho direito
    }
}
 
// 3. Caminhamento em Pós-Ordem (Desce os dois lados e só imprime o pai no final)
void posOrdem(struct No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);   // Delega para o galho esquerdo
        posOrdem(raiz->direita);    // Delega para o galho direito
        printf("%s ", raiz->valor); // Visita o nó atual (Pai)
    }
}
```
