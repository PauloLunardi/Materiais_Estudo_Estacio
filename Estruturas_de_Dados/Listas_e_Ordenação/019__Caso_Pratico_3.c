// ============================================================================
//         SISTEMA DE TESTES DE ORDENAÇÃO (AMBIENTE DE BENCHMARK)
// ============================================================================

#include <stdio.h>
#include <stdlib.h> // Para as funções rand(), srand()
#include <time.h>   // Para a função time(), usada para semear o gerador de número

// Define o tamanho das listas que serão ordenadas.
// Facilita a alteração para testes com mais ou menos elementos.
#define TAMANHO 10

// --- DECLARAÇÃO DAS FUNÇÕES (PROTÓTIPO) ---
// Informa ao compilador sobre a existência e a "assinatura" das funções
// que serão implementadas mais abaixo.

// Funções para gerar os diferentes tipos de listas
void gerarListaOrdenada(int lista[], int n);
void gerarListaInversa(int lista[], int n);
void gerarListaAleatoria(int lista[], int n);

// Funções de ordenação
void bubbleSort(int lista[], int n);
void insertionSort(int lista[], int n);
void selectionSort(int lista[], int n);

// Funções auxiliares
void imprimirLista(const char* titulo, const int lista[], int n);
void copiarLista(int destino[], const int origem[], int n);

// --- FUNÇÃO PRINCIPAL (main) ---
// O programa inicia sua execução aqui.
int main() {
    // Semeia o gerador de números aleatórios com a hora atual.
    // Isso garante que a lista aleatória seja diferente a cada execução do programa.
    // Deve ser chamado apenas UMA VEZ.
    srand(time(NULL));

    // Declara os três tipos de listas que servirão como nossos casos de teste.
    int listaOrdenada[TAMANHO];
    int listaInversa[TAMANHO];
    int listaAleatoria[TAMANHO];

    // Preenche as listas com os padrões desejados.
    printf("--- GERANDO LISTAS DE ENTRADA ---\n");
    
    // Aqui eu chamo as funções para preencher os nossos vetores de teste
    gerarListaOrdenada(listaOrdenada, TAMANHO);
    gerarListaInversa(listaInversa, TAMANHO);
    gerarListaAleatoria(listaAleatoria, TAMANHO);

    // Aqui eu uso a função auxiliar para mostrar como os vetores nasceram
    imprimirLista("Lista Original Ordenada", listaOrdenada, TAMANHO);
    imprimirLista("Lista Original Inversa (Decrescente)", listaInversa, TAMANHO);
    imprimirLista("Lista Original Aleatoria (Baguncada)", listaAleatoria, TAMANHO);

    printf("\n--- FIM DA GERACAO DAS LISTAS ---\n");
    return 0;
}

// ============================================================================
//             IMPLEMENTAÇÃO DAS FUNÇÕES (O QUE ELAS FAZEM)
// ============================================================================

// --- Funções para Preencher os Vetores ---

// Aqui eu crio uma lista que já nasce na ordem certa (1, 2, 3...)
void gerarListaOrdenada(int lista[], int n) {
    for (int i = 0; i < n; i++) {
        lista[i] = i + 1; // O primeiro ganha 1, o segundo 2, etc.
    }
}

// Aqui eu crio uma lista na pior ordem possível, que é a decrescente (10, 9, 8...)
void gerarListaInversa(int lista[], int n) {
    for (int i = 0; i < n; i++) {
        lista[i] = n - i; // Vai diminuindo conforme o 'i' aumenta
    }
}

// Aqui eu uso o rand() para gerar números totalmente misturados e aleatórios
void gerarListaAleatoria(int lista[], int n) {
    for (int i = 0; i < n; i++) {
        lista[i] = rand() % 100; // Sorteia números de 0 até 99
    }
}

// --- Funções Auxiliares Comuns ---

// Aqui eu crio a função para tirar uma cópia do vetor original.
// Fazemos isso para poder ordenar a cópia e não estragar o vetor principal.
void copiarLista(int destino[], const int origem[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i]; // Copia posição por posição
    }
}

// Aqui eu faço um laço for simples para imprimir o vetor na tela bem bonito
void imprimirLista(const char* titulo, const int lista[], int n) {
    printf("%s: [ ", titulo);
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("]\n");
}

// --- Funções de Ordenação (Cascas vazias para você preencher) ---

void bubbleSort(int lista[], int n) {
    // Aqui você vai colocar a sua lógica do Bubble Sort depois
}

void insertionSort(int lista[], int n) {
    // Aqui você vai colocar a sua lógica do Insertion Sort depois
}

void selectionSort(int lista[], int n) {
    // Aqui você vai colocar a sua lógica do Selection Sort depois
}
