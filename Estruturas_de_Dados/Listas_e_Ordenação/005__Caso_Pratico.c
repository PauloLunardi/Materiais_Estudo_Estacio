//MOD1 - Hora de Codar

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define uma constante para o comprimento maximo que cada texto pode ter.
#define MAX_STR_LEN 50 // Tamanho máximo de cada string/texto.

//------------------------------------------------------------------------
// PARTE 1: LISTA ESTÀTICA (Vetor de Strings)
// Uma lista estática é uma estrutura de dados de tamanho fixo,
// implementada usando um vetor (ou array)a.
// Toda a memória é alocada de uma só vez, quando a variável é declarada.
//------------------------------------------------------------------------

// Define uma constante para o número máximo de itens que nossa lista pode conter.
#define TAM_MAX 10 // Define o número máximo de intes na lista estática

// Estrutura que representa a lista estática
typedef struct {
  char dados[TAM_MAX][MAX_STR_LEN]; // MATRIZ: 10 LINHAS(Itens), 50 colunas(caracteres por item)
  int quantidade; // Este é o nosso contador de controle. Ele informa quantos itens estão realmente armazenados na lista.
} ListaEstática;

// Funções da Lista Estática

// Esta função prepara a lista para ser usada.
// Ela simplesmente define o contador quantidade como 0, indicando que a lista está vazia.
// Recebemos um ponteiro (*lista) para modificar a variavel original passada para a função.
void inicializarListaEstatica(ListaEstatica *lista);

void inserirListaEstatica(ListaEstatica *lista, const char* texto);
void removerListaEstatica(ListaEstatica *lista, const char* texto);
void listarListaEstatica(const ListaEstatica *lista);

//------------------------------------------------------------------------
// PARTE 2: LISTA ENCADEADA(de Strings)
// Uma Lista encadeada é uma estrutura de dados de tamanho dinânico.
// Ela é composta por "nós" separados na memória,
// onde cada nó contém um dado e um ponteiro que "aponta" para o próximo nó da sequência.
//------------------------------------------------------------------------

// Estrutura do nó (cada elemento da lista)
// - char* dado: Este é um ponteiro. Ele não armazena o texto em si, mas sim o endereço de memoria onde o texto está guardado.
// Isso é muito flexivel, pois cada texto pode ter um tamanho diferente, e alocamos apenas a memória necessária para cada um.
// - struct No *proximo: Este é o ponteiro que cria a "ligação". Ele armazena o endereço do proximo nó na lista.
// O ultimo nó da lista terá este pointeiro apontando para NULL.
typedef struct No {
  char* dado;
  struct No *proximo;
} No;

// "Atalho", em vez de escrever No* sempre-que quisermos nos referir á nossa lista, podemos simplesmenteusadr...
// A "lista" em si é apenas um ponteiro para o primeiro nó (a "cabeça" da lista)
typedef No* ListaEncadeada

// Funções da Lista Encadeada

// Uma lista encadeada vazia é representada por um ponteiro de cabeça que aponta para NULL.
// Esta função simplesmente atribui NULL ao ponteiro que representa nossa lista.
void inicializarListaEncadeada(ListaEncadeada *lista);

void inserirListaEncadeada(ListaEncadeada *lista, const char* texto);
void removerListaEncadeada(ListaEncadeada *lista, const chat* texto);
void listarListaEncadeada(const ListaEncadeada lista);
void liberarListaEncadeada(ListaEncadeada *lista); // Função para limpar a memória.


//------------------------------------------------------------------------
// Função Principal (main) E Menus

void menuListaEstatica();
void menuListaEncadeada();

int main() {
  int opcao;
  do {
    printf("\n-- Manipulação de Listas (Texto) --\n");
    printf("1. Lista Estatica --\n");
    printf("2. Lista Encadeada --\n");
    printf("0. Sair do Programa --\n");
    printf("Escolha uma opção: --\n");
    scanf("%d", &opcao);

    switch(opcao) {
      case 1:
        menuListaEstatica();
        break;
      case 2:
        menuListaEncadeada();
        break;
      case 0:
        printf("Saindo...\n");
        break;
      default:
        printf("Opção Invalida...\n");
    }
  } while (opcao != 0);
return 0;
}

//------------------------------------------------------------------------
// Implementação das Funções - Lista Estatica

void inicializarListaEstatica(ListaEstatica *lista) {
  lista->quantidade = 0;
}

void inserirListaEstatica(ListaEstatica *lista, const char* texto) {
  // Primeiro, verifica se lista->quantidade ja atingiu TAM_MAX.
  // Se sim, a lista está cheia e a função retorna.
  if (lista->quantidade == TAM_MAX) {
    printf("Erro: Lista cheia! Não é possivel inserir.\n");
    return;
  }

  // A inserção ocorre na primeira "linha" livre da matriz.
  // Para strings, não podemos fazer "lista->dados[i] = texto;" porque em C não se pode atribuir vetores/strings...
  // Precisamos copiar o conteudo da string para a posição correta na nossa matriz dados.
  strcpy(lista->dados[lista->quantidade], texto);
  // Após a cópia, lista->quantidade é incremento, pois agora temos mais um item na lista.
  lista->quantidade++;
  printf("Texto \"%s\" Inserido com Sucesso.\n" texto);
}

void removerListaEstatica(ListaEstatica *lista, const char* texto) {
  int i, pos = -1;
  // Para comparar strings, usamos strcmp(). Retorna 0 se forem iguais.
  // A função percorre os itens em usao na lista (de 0 até quantidade).
  // Para comparar strings, usamos strcmp(string1, string2).
  for (i = 0; i < lista->quantidade; i++) {
    if (strcmp(lista->dados[i], texto) == o) {
      pos = i;
      break;
    }
  }

  // Tratamento de Erro: Se o loop terminar e pos continuar -1, o item não foi encontrado.
  if (pos == -1) {
    print("Erro: Texto \"%s\" Não encontrado na lista.\n", texto);
    return;
  }

  // Fechar Lacuna: Se removermos um item do meio da lista, criamos um "buraco".
  // Para preench~e-lo, movemos todos os itens subsequentes para posição para a esquerda.
  // O loop for começa na posição do item removido e copia cada item i+1 para a posição i.
  // Deslocar os elementos posteriores para a esquerda usando strcpy.
  for (i = pos; i < lista->quantidade -1; i++) {
    strcpy(lista->dados[i], lista->dados[i + 1]);
  }

  // A atualização do Contador: Quantidade é decrementado para refletir que a lista tem 1 item a menos.
  lista->quantidade--;
  printf("Texto \"%s\" removido com sucesso.\n", texto);
}

void listarListaEstatica(const ListaEstatica *lista) {
  if (lista->quantidade == 0) {
    printf("A lista estatica esta vazia.\n");
    return;
  }
  printf("Itens da Lista Estatica: [ ");
  for (int i = 0; i < lista->quantidade; i++) {
    printf("\"%s\" ", lista->dados[i]); 
  }
  printf("]\n");
}


//------------------------------------------------------------------------
// Implementação das Funções - Lista Encadeada
      
// Uma lista encadeada vazia é representada por um ponteiro de cabeça que aponta para NULL.
// Esta função simplesmente atribui NULL ao ponteiro que representa nossa lista.
void inicializarListaEncadeada(ListaEncadeada *lista) {
  *lista = NULL;
}

void inserirListaEncadeada(ListaEncadeada *lista, const char* texto) {
  // 1. alocar memória para o novo nó.
  // Alocação do Nó: malloc(sizeof(No)) pede aos sistema operacional memória suficiente para um nó.
  // novoNo agora aponta para essa memória.
  No* novoNo = (No*) malloc(sizeof(No));

  if (novoNo == NULL) {
    printf("Erro: Falha na alocação de memória para o Nó. \n");
    return;
  }

  // 2. Alocar memória para a string dentro do Nó.
  // strlen(texto) + 1 para incluir o caractere nulo '\0' no final
  // Alocação da String: malloc(strlen(texto) + 1) aloca memória para o texto.
  // strlen conta os caracteres, e o +1 é viotal para o caractere nulo (\0) que finaliza toda string em C.
  // novoNo->dado agora aponta para este espaço.
  novoNo->dado = (chgar*) malloc(strclen(texto) + 1);

  if (novoNo->dado == NULL) {
    printf("Erro: Falha na alocação de memória para o texto.\n");
    free(novoNo); // Libera o nó que já foi alocado
    return;
  }

  // 3. Copiar o texto para a memória recém-alocada
  // Cópia do texto: strcpy copia o texto de entrada para a área de memória recém-alocada apontada  por novoNo->dado, texto
  strcpy(novoNo->dado, texto);

  // 4. Ligar o novo nó à lista
  // O ponteiro proximo do novo nó passa a pontar para o que era o antigo primeiro nó da lista.
  novoNo->proximo = *lista;
  // A cabeça da lista (*lista) é atualizada para apontar para o novoNo. o novoNo é agora o primeiro item.
  *lista = novoNo;

  printf("Texto \"%s\" Inserido com sucesso.\n", texto);
}

void removerListaEncadeada(ListaEncadeada *lista, const char* texto) {
  // Usamos dois ponteiros, atual e anterior, para percorrer a lista. atual avança e anterior segue.
  // Paramos quandoi atual aponta para o nó a ser removido.
  No *atual = *lista;
  No *anterior = NULL;

  while (atual != NULL && strcmp(atual->dado, texto) != 0) {
    anterior = atual;
    atual = atual->proximo;
  }

  if (atual == NULL) {
    printf("Erro: Texto \"%s\" não encontrado na lista.\n", texto);
    return;
  }

  // Se o nó a ser removido for o primeiro (anterior == NULL), a cabeça da lista (*lista) passa a ser o segundo (atual)
  // Se estiver no meio/fim, o ponteiro proximo do nó anterior "pula" o atual e aponta para atual->proximo.
  if (anterior == NULL) {
    *lista = atual->proximo;
  } else {
    anterior->proximo = atual->proximo;
  }

  // Liberação de memória (muito Importante): Para evitar vazamento de memória (memory leak), precisamos devolver ao ....
  // Primeiro, free(atual->dado): Libera a memória que foi usada para guardar o texto.
  // Depois, free(atual): Libera memória do proprio nó. Se fisermos o contrario, perderiamos a referencia para...

  // ANTES de liberar o nó, precisamos liberar a string DENTRO dele.
  free(atual->dado);
  // AGORA podemos liberar o nó.
  free(atual);
  printf("Texto \"%s\" removido com sucesso.\n", texto);
}

void listarListaEncadeada(const ListaEncadeada lista) {
  No *temp = lista;
  if (temp == NULL) {
    printf("A lista encadeada esta vazia.\n");
  }
  printf("Itens da Lista Encadeada: [ ");
  while (temp != NULL)
    printf("\"%s\" ", temp->dado); // Usando o S para impressao de strings
    temp = temp->proximo;
  }
  printf("]\n");
}

// Função para liberar toda a meória da lista encadeada no final
// ela percorre todos os nós da lista, um po um, e aplica a mesma lógica de liberação dupla (free(dado)
// E depois free(no) para cada um deles, garantindo que nenhuma memória alocada seja deixada para trás quando o programa.
void liberarListaEncadeada(ListaEncadeada *lista) {
  No *atual = *lista;
  No *proximo;
  while (atual != NULL) {
    proximo = atual->proximo;
    free(atual->dado); // Libera a string
    free(atual; // Libera o nó
    
