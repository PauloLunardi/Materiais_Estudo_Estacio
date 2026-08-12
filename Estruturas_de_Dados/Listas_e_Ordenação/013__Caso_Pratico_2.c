#include <stdio.h>
#include <string.h> // essencial para comparar strings(strcmp)
#include <stdlib.h> // para a função exit(), caso a lista não esteja ordenada para a busca binária.

// --- Declaração das Funções (Protótipos) ---
// Isso Informa ao compilador que essas funções existem e como elas são,
// Mesmo que suas implementações estejam mais abaixo no código.

// 1. Busca Sequencial
int buscaSequencialIterativa(const char* lista[], int tamanho, const char* item);
int buscaSequencialRecursiva(const char* lista[], int tamanho, const char* item);
int buscaSequencialRecursiva_aux(const char* lista[], int tamanho, const char* item, int indice);

// 2. Busca Binaria
int buscaBinariaIterativa(const char* lista[], int tamanho, const char* item);
int buscaBinariaRecursiva(const char* lista[], int tamanho, const char* item);
int buscaBinariaRecursiva_aux(const char* lista[], const char* item, int inicio, int fim);

// Função auxiliar par imprimir os resultados de forma organizada
void imprimirResultado(const char* nomeDaBusca, const char* item, int resultado);

// --- Função Principal (Main) ---
int main() {
  // Importante: para a busca binaria funcionar, a lista DEVE estar ordenada alfabeticamente.
  // Nossa lista de compras já esta ordenada para o exemplo.
  const char* listaDeCompras[] = {
    "arroz",
    "batata",
    "cebola",
    "detergente",
    "feijao",
    "leite",
    "macarrao",
    "oleo",
    "sal",
    "tomate"
  };
  
  // Calcula o numero de itens na lista.
  // sizeof(listaDeCompras) -> tamanho total do array em bytes.
  // sizeof(listaDeCompras[0] -> tamanho de um elemento (um ponteiro char*) em bytes.
  // A divisao nos dá o numero de elementos.
  int tamanhoDaLista = sizeof(listaDeCompras) / sizeof(listaDeCompras[0]);
  
  // Itens que vamos procurar para demonstrar os algoritimos.
  const char* itemExistente = "leite";
  const char* itemInexistente = "queijo";

  printf("--- Demonstração de algoritimos de busca em lista de texto ---\n");
  printf("--- Lista Utilizadas: [arroz, batata, cabola, detergente, feijao, leite, macarrao, oleo, sal, limao]");
  printf("-------------------------------------------------------------\n\n");

  // --- Testando a busca Sequencial ---
  printf("--- 1. Busca Sequencial ---");
  // a) Versao Iterativa
  int res1 = buscaSequencialIterativa(listaDeCompras, tamanhoDaLista, itemExistente);
  imprimirResultado("Sequencial Iterativa", itemExistente, res1);

  int res2 = buscaSequencialIterativa(listaDeCompras, tamanhoDaLista, itemInexistente);
  imprimirResultado("Sequencial Iterativa", itemInexistente, res2);
  printf("\n");

  // a) Versao Recursiva
  int res3 = buscaSequencialRecursiva(listaDeCompras, tamanhoDaLista, itemExistente);
  imprimirResultado("Sequencial Recursiva", itemExistente, res3);

  int res4 = buscaSequencialRecursiva(listaDeCompras, tamanhoDaLista, itemInexistente);
  imprimirResultado("Sequencial Recursiva", itemInexistente, res4);
  printf("-------------------------------------------------------------\n\n");

  // --- Testando a busca Binaria ---
  printf("--- 1. Busca Binaria (Requer lista ordenada) ---");
  // a) Versao Iterativa
  int res5 = buscaBinariaIterativa(listaDeCompras, tamanhoDaLista, itemExistente);
  imprimirResultado("Binaria Iterativa", itemExistente, res5);

  int res6 = buscaBinariaIterativa(listaDeCompras, tamanhoDaLista, itemInexistente);
  imprimirResultado("Binaria Iterativa", itemInexistente, res6);
  printf("\n");

  // a) Versao Recursiva
  int res7 = buscaBinariaRecursiva(listaDeCompras, tamanhoDaLista, itemExistente);
  imprimirResultado("Binaria Recursiva", itemExistente, res7);

  int res8 = buscaBinariaRecursiva(listaDeCompras, tamanhoDaLista, itemInexistente);
  imprimirResultado("Binaria Recursiva", itemInexistente, res8);
  printf("-------------------------------------------------------------\n\n");

  return 0; // Indica que oi programa terminou com sucesso.
}

// --- Implementação das funções ---

// 1. Busca Sequencial
// =======================================================================
// Percorre a lista elemento por elemento, do inicio ao fim,
// até encontrar o item ou chegar ao final da lista.
// Não requer que a lista esteja ordenada.
// =======================================================================

/*
* @brief Busca sequencial usando laço(iteração).
* @param lista O array de strings onde a busca sera feita.
* @param tamanho O numero de elementos na lista.
* @param item A string que esta sendo procurada.
* @return O indice do item se encontrando, ou -1 caso contrario.
*/
int buscaSequencialIterativa(const char* lista[], int tamanho, const char* item) {
  // Um laço 'for' percorre cada indice da lista, de 0 até 'tamanho - 1'.
  for (int i = 0; i < tamanho; i++) {
    // strcmp(str1, str2) compara duas strings.
    // Retorna 0 se elas forem identicas.
    if (strcmp(lista[i], item) == 0) {
      // se as strings forem iguais, encontramos o item!
      return i; // retorna o indice atual
    }
  }
  // Se o laço terminar e nao tivermos retornando nada, significa que o item não esta na lista.
  return -1;
}

/*
 * @brief Função "involucro" (wrapper) para a busca sequencial recursiva.
 *         Ela esconde a complexidade do parametro 'indice' do usuario.
 */
int buscaSequencialRecursiva(const char* lista[], int tamanho, const char* item) {
  // A logica recursiva real esta na funcao auxiliar.
  // Começamos a busca a partir do indice 0.
  return buscaSequencialRecursiva_aux(lista, tamanho, item, 0);
}

/*
 * @brief Funçao auxiliar que implementa a logica recursiva da busca sequencial.
 * @param indice O indice do elemento atual a ser verificado.
 * @return o indice do item se encontrado, ou -1 caso contrario.
 */
int buscaSequencialRecursiva_aux(const char* lista[], int tamanho, const char* item, int indice) {
  // Caso Base 1: Falha(Fim da Lista)
  // Se o indice atual for igual ou maior que o tamanho da lista,
  // Significa que ja percorremos todos os elementos sem sucesso.
  if (indice >= tamanho) {
    return -1; // Item nao encontrado.
  }

  // Caso Base 2: Sucesso
  // Compara o item na posiçao ' indice' atual com o item procurado.
  if (strcmp(lista[indice], item) == 0) {
    return indice; // Item encontrado! Retorna o indice.
  }

  // Passo Recursivo
  // Se nao for nenhum dos casos base, o item ainda pode estar no resto da lista.
  // Chamamos a função novamente, mas agora para o proximo indice (indice + 1).
  // O retorno desta chamada sera propagado para a chamada anterior.
  return buscaSequencialRecursiva_aux(lista, tamanho, item, indice + 1);
}

// =======================================================================
// 2 Busca Binaria
// =======================================================================
// Algoritimo de "dividir para conquistar".
// A cada passo, ele olha o elemento do meio da lista (ou sub-lista).
// Se o item do meio for o procurado, a busca termina.
// Se o item procurado for menor, ele descarta a metade direita e busca na esquerda.
// Se for maior, descart a metade esquerda e busca na direita.
// Requer que a lista esteja ORDENADA.
// =======================================================================

/**
  * @brief Busca binaria usando um laço (iteracao).
  * @return O indice do item se encontrando, ou -1 caso contrario.
  */
int buscaBinariaIterativa(const char* lista[], int tamanho, const char* item) {
  int inicio = 0;
  int fim = tamanho - 1;
  int meio;

  // O laço continua a sub-lista for valida (inicio não ultrapassou o fim).
  while (inicio <= fim) {
    // Calcula o indice do meio.
    // Usar inicio + (fim - inicio) / 2 evita overflow para listas muito grandes.
    meio = inicio + (fim - inicio) / 2;

    // Compara a string do meio com o item procurado.
    int comparacao = strcmp(lista[meio], item);

    if (comparacao == 0) { // Encontrou!
      return meio;
    }
    else if (comparacao > 0) {
      // O item do meio vem DEPOIS do item procurado (ex: "leite" > "feijao").
      // Portanto, o item só pode estar na metade esquerda.
      // Descartamos a metade direita, ajustando o 'fim'.
      fim = meio - 1;
    }
    else { // comparacao < 0
      // O item do meio vem ANTES do item procurado (ex: "leite" < "sal").
      // Portanto, o item só pode estar na metade direita.
      // Descartamos a metade esquerda, ajustando o 'inicio'.
      fim = meio + 1;
    }
  }

  // Se o laço 'while' terminar, significa que 'inicio' ultrapassou 'fim',
  // O espeço de busca se esgotou e o item não foi encontrado.
  return -1;
}

/**
  * @brief Funcção "involucro" (wrapper) para a busca binaria recursiva.
*/
int buscaBinariaRecursiva(const char* lista[], int tamanho, const char* item) {
  // inicia a busca recursiva em toda lista, do indice 0 até 'tamanho - 1'.
  return buscaBinariaRecursiva_aux(lista, item, 0, tamanho - 1);
}

/**
  * @brief Função auxiliar que implementa a logica recursiva da busca binaria.
  * @param inicio O indice inicial da sub-lista atual.
  * @param fim O indice final da sub-lista atual.
  * @return O indice do item se encontrado, ou -1 caso contrario.
  */
int buscaBinariaRecursiva_aux(const char* lista[], const char* item, int inicio, int fim) {
  // Caso Base 1: Falha (espaço de busca invalido)
  // Se o 'inicio' ultrapassar o 'fim', a sub-lista é vazia, o item não esta aqui.
  if (inicio > fim) {
    return -1;
  }

  // Passo Recursivo e Caso Base de Sucesso
  int meio = inicio + (fim - inicio) / 2;
  int comparacao = strcmp(lista[meio], item);

  if (comparacao == 0) {
    // Caso Base 2: Sucesso
    return meio; // Encontramos o item!
  }
  else if (comparacao > 0) {
    // O item esta na metade esquerda.
    // Chamamos a função novamente, mas com um novo 'fim'.
    return buscaBinariaRecursiva_aux(lista, item, inicio, meio - 1);
  }
  else { //comparacao < 0
    // O item esta na metade direita.
    // Chamamos a função novamente, mas como um novo 'inicio'.
    return buscaBinariaRecursiva_aux(lista, item, meio + 1, fim);
  }
}

// =======================================================================
// Funcao Auxiliar de Impressao
// =======================================================================
/**
  * @brief formata e imprime o resultado de uma busca.
  * @param nomeDaBusca O nome do algoritimo utilizada..
  * @param item O item que foi procurado.
  * @return resultado O resultado da busca (indice ou -1)..
  */
void imprimirResultado(const char* nomeDaBusca, const char* item, int resultado) {
  printf("[%s] Buscado por \"%s\"... \n", nomeDaBusca, item);
  if (resultado != -1) {
    printf("  -> Resultado: Item encontrado no indice %d.\n", resultado);
  } else {
    printf("  -> Resultado: Item nao encontrado na lista.\n");
  }
}
