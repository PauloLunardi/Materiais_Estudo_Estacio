# Árvores Binárias de Busca (BST) - Sistema de Pistas

Este documento apresenta a especificação técnica, a análise estrutural e o guia de funcionamento para a implementação de uma **Árvore Binária de Busca (BST - Binary Search Tree)** na linguagem C, utilizando cadeias de caracteres (strings) como chaves para organizar pistas criminais.

---

## 1. Fundamentos da BST (Binary Search Tree)

A árvore binária de busca é uma estrutura projetada para organizar dados de forma hierárquica. Seu principal objetivo é acelerar a busca de informações, respeitando uma regra simples: em cada nó, todos os elementos à esquerda são menores que o valor atual, enquanto os à direita são maiores. 

Essa ordenação natural permite que, a cada comparação, metade da árvore seja descartada, o que torna as operações muito mais eficientes do que em estruturas lineares (por exemplo, listas).

---

## 2. Estrutura e Criação do Nó

### Estrutura do Nó
Cada nó possui dois ponteiros para seus filhos e um campo para o valor armazenado, utilizando strings para salvar os nomes das pistas.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct No {
    char valor[50];       // O dado armazenado (uma string de até 49 caracteres)
    struct No* esquerda;  // Ponteiro para o filho à esquerda
    struct No* direita;   // Ponteiro para o filho à direita
};
```

### Criando um Nó
Sempre que quisermos adicionar um novo valor à árvore, precisaremos criar um nó com esse valor. Essa função aloca memória dinâmica e inicializa os ponteiros como `NULL`, já que novos nós começam sem filhos.

```c
struct No* criarNo(const char* valor) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    strcpy(novo->valor, valor);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}
```
> ⚠️ **Atenção:** Esse passo certifica que cada valor inserido é um novo bloco na árvore, isolado e pronto para ser conectado a outros nós.

---

## 3. Inserção, Percurso e Busca

### Inserindo Elementos na Árvore
O passo agora é inserir os nós seguindo a regra da BST: valores menores vão à esquerda, maiores à direita. A comparação de strings é realizada através da função `strcmp()`.

```c
struct No* inserir(struct No* raiz, const char* valor) {
    if (raiz == NULL) 
        return criarNo(valor);
    
    // Se o valor for menor que o nó atual, desce para a esquerda
    if (strcmp(valor, raiz->valor) < 0)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    // Se o valor for maior que o nó atual, desce para a direita
    else if (strcmp(valor, raiz->valor) > 0)
        raiz->direita = inserir(raiz->direita, valor);
    
    return raiz;
}
```
O processo estudado é recursivo, ou seja, ele percorre a árvore até encontrar uma posição livre para inserir o novo valor. Como cada chamada vai descendo um nível, a árvore cresce de cima para baixo.

### Percorrendo a Árvore Em Ordem (In-Order)
A principal vantagem da BST é poder ser percorrida em ordem crescente com um algoritmo simples. Esse percurso visita primeiro a esquerda, depois o nó atual, e, por fim, a direita.

```c
void emOrdem(struct No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%s | ", raiz->valor);
        emOrdem(raiz->direita);
    }
}
```
> 🔄 **Relembrando:** O tipo de travessia visto é ideal para exibir os valores organizados de forma alfabética ou numérica.

### Buscando um Valor na Árvore
Procurar em uma BST é muito mais eficiente do que em uma lista, pelo simples fato de que podemos eliminar metade dos elementos a cada comparação.

```c
int buscar(struct No* raiz, const char* chave) {
    if (raiz == NULL) 
        return 0; // Não encontrado
    
    if (strcmp(chave, raiz->valor) == 0)
        return 1; // Encontrado
    else if (strcmp(chave, raiz->valor) < 0)
        return buscar(raiz->esquerda, chave);
    else
        return buscar(raiz->direita, chave);
}
```

---

## 4. Teoria e Casos de Remoção de um Nó

A exclusão é um processo complexo, pois não se pode remover o nó de uma árvore binária sem considerar os casos distintos para a manutenção da hierarquia.

### Caso 1: Remoção na Folha
A exclusão de um nó folha ocorre quando o nó a ser excluído não possui filhos. Nesse caso, o procedimento é simples: o ponteiro do pai é ajustado para `NULL` e o nó é liberado da memória.

### Caso 2: Remoção de um Nó com um Filho
Se for um único filho, a exclusão exige que o ponteiro do pai do nó removido passe a apontar para o filho existente, que pode estar à esquerda ou à direita. Isso preserva a ordenação da árvore binária de busca.

### Caso 3: Remoção de Nó com Dois Filhos
Encontra a menor string da subárvore direita (ordem alfabética), copia para o nó atual de forma segura e remove o nó duplicado do sucessor de maneira recursiva.

```c
// Versão final da função de remover unificada:
struct No* remover(struct No* raiz, const char* valor) {
    if (raiz == NULL) 
        return NULL;

    if (strcmp(valor, raiz->valor) < 0) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (strcmp(valor, raiz->valor) > 0) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        // Caso 1: sem filhos (Nó folha)
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        }
        // Caso 2: um único filho
        else if (raiz->esquerda == NULL) {
            struct No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            struct No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        // Caso 3: dois filhos
        else {
            // Procura o menor nó do lado direito (sucessor)
            struct No* temp = raiz->direita;
            while (temp->esquerda != NULL) {
                temp = temp->esquerda;
            }
            strcpy(raiz->valor, temp->valor); // Copia a string do sucessor
            raiz->direita = remover(raiz->direita, temp->valor);
        }
    }
    return raiz;
}
```
> 💡 **Dica:** O código visto cobre todos os casos de maneira certa e permite que a memória alocada para as strings também seja liberada quando um nó é removido.

---

## 5. Orquestração e Validação no `main()`

O bloco principal do programa monta a árvore de pistas automaticamente e usa o operador ternário `(condicao ? valor_se_verdadeiro : valor_se_falso)` dentro do `printf` para simplificar decisões lógicas e exibir se os itens procurados existem ou não no cenário.

---

## 6. Painel de Resultados do Console (Outputs)

O mapa textual abaixo reproduz fielmente a hierarquia física gerada na memória RAM após as inserções automáticas da função `main()`, combinando exatamente com o diagrama de pistas do professor:

```text
                     [ Pegadas de lama ]
                       /             \
             [ Chave perdida ]      [ Null ]
               /           \
     [ Gaveta perdida ]   [ Livro com página faltando ]
                                   /             \
                           [ Lençol manchado ]  [ Null ]
```

### Saída Exibida no Terminal:
```text
Elementos em ordem: Chave perdida Gaveta perdida Lençol manchado Livro com página faltando Pegadas de lama 

Busca por ‘Lençol manchado’: Encontrado
Busca por ‘Óculos’: Não encontrado
```
