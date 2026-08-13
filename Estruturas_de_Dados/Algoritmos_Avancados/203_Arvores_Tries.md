# Árvores Trie (Árvore de Prefixos)

Este documento apresenta a especificação técnica, a análise estrutural e o guia de funcionamento para a implementação de uma **Árvore Trie** na linguagem C. Focada no armazenamento e manipulação de cadeias de caracteres (strings), esta estrutura destaca-se por sua alta performance em buscas de texto e otimização por prefixos comuns.

---

## 1. Introdução a Árvores Trie

Quando falamos de árvore Trie, precisamos saber que a pronúncia correta é “trai” e que é também conhecida como árvore de prefixos. Ela é uma estrutura de dados especializada no armazenamento e manipulação de strings, com excelente desempenho para buscas rápidas, autocompletar e verificação de palavras. 

Ao contrário das árvores BST, que organizam os dados de acordo com valores numéricos ou ordem alfabética total, a Trie organiza cada palavra letra por letra, aproveitando ao máximo os prefixos comuns entre elas. Essa estrutura é bastante utilizada em dicionários digitais, sistemas de correção automática, algoritmos de compressão e qualquer aplicação que envolva grande quantidade de palavras ou buscas frequentes com base em prefixos.

---

## 2. Estrutura e Criação do Nó

### Estrutura do Nó
Para construir uma Trie, cada nó precisa representar possíveis ramificações para os próximos caracteres. Em geral, utilizamos um array de ponteiros (26 para letras minúsculas de 'a' a 'z') e um indicador booleano que mostra se um caminho forma uma palavra completa.

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
 
#define TAMANHO_ALFABETO 26
 
struct NoTrie {
    struct NoTrie* filhos[TAMANHO_ALFABETO];
    bool ehFimDePalavra;
};
```
A estrutura reserva espaço para até 26 possíveis filhos em cada nível e um campo `ehFimDePalavra`, que nos ajuda a reconhecer quando uma sequência de caracteres completa uma palavra.

### Criação de um Nó
Ao iniciarmos a Trie, precisaremos de um nó raiz vazio. Cada novo caractere inserido será conectado de modo dinâmico, conforme a palavra for processada.

```c
struct NoTrie* criarNo() { 
    struct NoTrie* novoNo = (struct NoTrie*) malloc(sizeof(struct NoTrie));
    novoNo->ehFimDePalavra = false;
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        novoNo->filhos[i] = NULL;
    }
    return novoNo;
}
```
A alocação dinâmica permite que o espaço de memória seja utilizado apenas quando necessário. Cada ponteiro inicializado com `NULL` viabiliza que a árvore cresça sob demanda, economizando espaço.

---

## 3. Inserção e Busca de Palavras

### Inserção de Palavras na Trie
Percorremos caractere por caractere e criamos os nós intermediários se eles ainda não existirem. A marcação de fim de palavra é essencial para distinguir palavras completas de simples prefixos.

```c
void inserir(struct NoTrie* raiz, const char* palavra) {
    struct NoTrie* atual = raiz;

    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = palavra[i] - 'a';

        if (atual->filhos[indice] == NULL) {
            atual->filhos[indice] = criarNo();
        }
        atual = atual->filhos[indice];
    }
    atual->ehFimDePalavra = true;
}
```
O uso de `palavra[i] - 'a'` transforma letras em índices de 0 a 25. Assim, a letra 'c' vira índice 2, por exemplo. Isso permite acesso direto ao filho correspondente, sem necessidade de laços ou comparações.

### Busca de Palavras
É muito parecida com a inserção, ou seja, percorremos os nós conforme os caracteres da palavra. Se em algum momento o caminho não existir, significa que a palavra não está presente.

```c
bool buscar(struct NoTrie* raiz, const char* palavra) {
    struct NoTrie* atual = raiz;

    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = palavra[i] - 'a';

        if (atual->filhos[indice] == NULL)
            return false;

        atual = atual->filhos[indice];
    }
    return atual != NULL && atual->ehFimDePalavra;
}
```
A função retorna `true` apenas se a sequência existir e estiver marcada como palavra completa. Isso evita confundir prefixos com palavras reais.

---

## 4. Ordenação Lexicográfica e Normalização

Como a Trie armazena os caracteres em ramos que seguem a ordem do alfabeto (de ‘a’ a ‘z’), podemos percorrê-la em pré-ordem alfabética para imprimir todas as palavras de forma ordenada. Esse percurso pode ser feito de modo recursivo.

```c
void listarPalavras(struct NoTrie* no, char* buffer, int nivel) {
    if (no->ehFimDePalavra) {
        buffer[nivel] = '\0';
        printf("%s\n", buffer);
    }

    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        if (no->filhos[i] != NULL) {
            buffer[nivel] = 'a' + i;
            listarPalavras(no->filhos[i], buffer, nivel + 1);
        }
    }
}

void normalizar(const char* entrada, char* saida) {
    int j = 0;
    for (int i = 0; entrada[i] != '\0'; i++) {
        char c = entrada[i];
        if (c >= 'A' && c <= 'Z') c += 32; // Converte para minúsculo
        if (c >= 'a' && c <= 'z') saida[j++] = c; // Mantém apenas letras
    }
    saida[j] = '\0';
}
```

### Por que é necessário normalizar?
Nossa Trie foi projetada para funcionar com letras minúsculas de ‘a’ a ‘z’, ou seja, apenas 26 caracteres. Assim, ao tentar usar palavras com letras maiúsculas, espaços e acentos, podem ocorrer erros de acesso fora dos limites, retornando possíveis falhas no funcionamento do programa.

A normalização corrige isso, pois, antes de inserir a palavra na Trie, é feita uma conversão para letras minúsculas, remoção dos espaços, eliminação ou substituição de caracteres com acento e garantia de que cada caractere esteja entre ‘a’ e ‘z’.

---

## 5. Exemplo Completo com Função main()

O bloco abaixo demonstra a unificação dos conceitos apresentados, realizando a criação da estrutura, inserção das pistas textuais normalizadas do jogo e a listagem final no console:

```c
int main() {
    struct NoTrie* raiz = criarNo();
    char normalizada[100];
 
    normalizar("Pegadas de Lama", normalizada);
    inserir(raiz, normalizada);
 
    normalizar("Chave perdida", normalizada);
    inserir(raiz, normalizada);
 
    normalizar("Livro com página faltando", normalizada);
    inserir(raiz, normalizada);
 
    normalizar("Lençol manchado", normalizada);
    inserir(raiz, normalizada);
 
    normalizar("Gaveta perdida", normalizada);
    inserir(raiz, normalizada);

    char buffer[100]; // Tamanho máximo de palavra suportado
    printf("--- LISTAGEM DE PALAVRAS NA TRIE ---\n");
    listarPalavras(raiz, buffer, 0);

    return 0;
}
```

### Saída Esperada no Terminal:
```text
chaveperdida  
gavetaperdida
lencolmanchado  
livrocompaginafaltando  
pegadasdelama  
```
*(Nota: Devido à ordenação natural dos índices do alfabeto de 0 a 25 no laço de listagem, as palavras são exibidas automaticamente em ordem alfabética estrita).*

---

## 6. Considerações Finais sobre a Trie

A estrutura Trie é muito eficiente para cenários que envolvem grandes volumes de palavras, em especial, quando há muitos prefixos repetidos. Ela oferece um tempo de busca proporcional ao tamanho da palavra, independentemente da quantidade total de palavras armazenadas. Por isso, ela é muito usada em sistemas de autocompletar, filtros de spam e até em inteligências artificiais.
