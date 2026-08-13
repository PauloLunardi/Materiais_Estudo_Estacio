# Estrutura de uma Árvore Binária na Prática

Este documento apresenta a implementação prática dos componentes estruturais de uma árvore binária na linguagem C. Compreender a definição de nós, as funções da raiz e das folhas, bem como o funcionamento dos algoritmos recursivos de **Altura** e **Profundidade** é fundamental para manipular relações hierárquicas na memória do computador.

---

## 1. Estrutura do Nó (O Bloco de Construção)

Para criar uma árvore binária, precisamos de uma estrutura composta (`struct`) capaz de representar um nó isolado na memória. Cada nó carrega a informação útil (o dado) e dois ponteiros de conexão para os seus respectivos descendentes.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aqui nós criamos a nossa struct para representar cada nó da árvore
struct No {
    char valor[50];       // Aqui o nó guarda um texto/string de até 49 letras
    struct No* esquerda;  // Ponteiro para ligar o filho do lado esquerdo
    struct No* direita;   // Ponteiro para ligar o filho do lado direito
};
```

> **Por que isso importa?** Essa estrutura correta permite que a árvore se ramifique livremente. Como cada nó conhece os seus filhos, nós podemos usar funções recursivas para caminhar por todos os galhos até alcançar as pontas finais da árvore.

---

## 2. Algoritmo de Altura (Métrica Global)

A altura é o maior número de arestas entre a raiz e uma folha. Ela define a distância máxima vertical da estrutura e serve para monitorar se a árvore está ficando muito esticada e lenta para buscas.

### Como a Lógica Recursiva Funciona:
1. Se chegarmos em um nó vazio (`NULL`), a função devolve `0` (indica fim de linha ou árvore vazia).
2. O programa chama a si mesmo para calcular a altura da subárvore esquerda e depois da subárvore direita.
3. Usamos o operador ternário `(condicao ? se_verdade : se_falso)` para descobrir qual dos dois lados é o mais alto.
4. Somamos `1` ao maior lado encontrado para incluir o nível do nó atual no cálculo e devolvemos o total.

```c
// Função recursiva para calcular a altura da árvore inteira
int altura(struct No* raiz) {
    // Se o nó estiver vazio, a altura é 0 (Caso Base)
    if (raiz == NULL) {
        return 0;
    }
    
    // Aqui eu chamo a função para calcular o tamanho do lado esquerdo e direito
    int alt_esq = altura(raiz->esquerda);
    int alt_dir = altura(raiz->direita);
    
    // Aqui nós descobrimos qual lado é o maior, somamos 1 e retornamos o resultado
    return 1 + (alt_esq > alt_dir ? alt_esq : alt_dir);
}
```

---

## 3. Algoritmo de Profundidade (Métrica Local)

A profundidade é a distância exata entre o nó raiz e um determinado nó alvo que queremos localizar. Ela mede o custo de acesso para chegar a um elemento específico.

### Como a Lógica Recursiva Funciona:
1. A função recebe o nó corrente, o nó alvo que estamos procurando e o nível atual da descida (que começa em `0` na raiz).
2. Se bater em um nó `NULL`, devolve `-1` (sinaliza que não achou o alvo por aquele caminho).
3. Se o nó atual for exatamente o alvo, devolve o número do `nivel` atual.
4. Caso contrário, a função tenta descer recursivamente pelo lado esquerdo incrementando `nivel + 1`. Se achar, propaga o resultado para cima. Se não achar (retornar `-1`), ela desce e tenta a mesma lógica pelo lado direito.

```c
// Função recursiva para achar a profundidade de um nó específico
int profundidade(struct No* raiz, struct No* alvo, int nivel) {
    // Caso Base 1: Chegou ao fim de um galho vazio e não encontrou nada
    if (raiz == NULL) {
        return -1;
    }
    
    // Caso Base 2: Encontrou o nó alvo! Retorna o nível em que ele está
    if (raiz == alvo) {
        return nivel;
    }

    // Aqui eu tento procurar o nó alvo descendo pelo lado esquerdo
    int esq = profundidade(raiz->esquerda, alvo, nivel + 1);
    
    // Se o resultado da esquerda for diferente de -1, significa que achamos!
    if (esq != -1) {
        return esq; // Devolve a profundidade encontrada
    }

    // Se não encontrou na esquerda, o programa tenta buscar no galho da direita
    return profundidade(raiz->direita, alvo, nivel + 1);
}
```

---

## 4. Diagrama de Identificação de Nós e Níveis

O desenho abaixo mimetiza o comportamento dos ponteiros, mostrando onde ficam os nós internos e as folhas, mapeando como o contador de `nivel` calcula a profundidade de cima para baixo:

```text
 PROFUNDIDADE                 DIAGRAMA DOS COMPONENTES
 (Pelo Nível)

   Nível 0    ───────────────►        [ Raiz ]     <── (O topo da hierarquia)
                                      /      \
                                     /        \
   Nível 1    ───────────────►   [ Folha ]   [ Nó ]    <── (Nó Interno: Tem filhos)
                                             /    \
                                            /      \
   Nível 2    ───────────────►          [ Nó ]   [ Folha ]
                                        /    \
                                       /      \
   Nível 3    ───────────────►    [ Folha ]  [ Folha ] <── (Nós Folhas: Fim de linha)
```
