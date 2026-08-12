# O Algoritmo de Ordenação Bubble Sort (Ordenação por Bolha)

Este documento apresenta uma análise técnica e aprofundada sobre o algoritmo **Bubble Sort**. Embora seja classificado como um método de ordenação básico e de baixa eficiência para grandes volumes de dados, o seu estudo é indispensável na engenharia de software para consolidar os conceitos de laços aninhados, varreduras sequenciais, manipulação de ponteiros por referência e análise empírica de algoritmos.

---

## 1. Mecanismo de Funcionamento e Lógica de Borbulhamento

O funcionamento do Bubble Sort baseia-se no princípio de **comparações e trocas sucessivas entre elementos adjacentes** (vizinhos diretos). O algoritmo realiza múltiplas passagens (varreduras) pelo vetor, analisando os elementos aos pares, da esquerda para a direita.

### O Fluxo Passo a Passo:
1. O algoritmo posiciona-se no início do vetor e compara o elemento do índice `j` com o seu vizinho da direita no índice `j + 1`.
2. Se o elemento da esquerda for maior que o da direita (`vetor[j] > vetor[j + 1]`), uma operação de troca (*swap*) é disparada, invertendo a posição física de ambos na memória RAM.
3. Se não for maior, nenhuma ação é tomada e o algoritmo avança uma posição para avaliar o próximo par (`j + 1` e `j + 2`).
4. **O Efeito Bolha:** Ao término da primeira varredura completa, o maior elemento de toda a estrutura terá, obrigatoriamente, flutuado ("borbulhado") até a última posição do vetor.
5. Na segunda varredura, o processo repete-se, fazendo com que o segundo maior elemento se posicione na penúltima vaga, e assim sucessivamente. O algoritmo encerra-se quando uma varredura inteira acontece sem disparar nenhuma troca, sinalizando que a lista está estável e ordenada.

> **Analogia das Bolas Numeradas:** Imagine um conjunto de bolas numeradas e fora de ordem alinhadas no chão. Começando pelo lado esquerdo, compara o peso da primeira bola com o da segunda; se a primeira for mais pesada, troca-as de lugar. De seguida, compara a segunda com a terceira. Repete este ciclo até ao fim da linha. Ao terminar a primeira rodada, a bola mais pesada de todas estará garantidamente na última posição da direita.

---

## 2. Exemplo Prático de Implementação em C

Para garantir a máxima modularidade e reutilização de código, a implementação correta do Bubble Sort divide-se em duas rotinas: uma função auxiliar que manipula os endereços de memória por referência para inverter as variáveis (`trocar`) e a função principal de ordenação (`bubbleSort`).

```c
#include <stdio.h>

// Função Auxiliar: Inverte o valor de duas variáveis diretamente na memória RAM
// Recebe ponteiros (int* a e int* b) para modificar os dados originais do vetor
void trocar(int *a, int *b) {
    int temp; // Variável temporária para segurar o valor durante a manobra
    temp = *a;
    *a = *b;
    *b = temp;
}

// Função Principal do Bubble Sort: Organiza o vetor em ordem crescente
void bubbleSort(int vetor[], int tamanho) {
    // O laço externo 'i' controla o número total de passagens pelo vetor.
    // A cada turno concluído, o limite do laço interno recua, pois os maiores
    // elementos já estão fixados corretamente no final do array.
    for (int i = 0; i < tamanho - 1; i++) {
        
        // O laço interno 'j' realiza as comparações entre os vizinhos adjacentes.
        // Usar 'tamanho - i - 1' evita comparações redundantes com as posições
        // finais que já foram devidamente ordenadas nos turnos anteriores.
        for (int j = 0; j < tamanho - i - 1; j++) {
            
            // Critério de Ordenação Crescente: verifica se o elemento da esquerda
            // é maior que o elemento da direita.
            if (vetor[j] > vetor[j + 1]) {
                // Se estiverem fora de ordem, envia os endereços para a função de troca
                trocar(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

// Função Utilitária para renderizar o vetor no console
void imprimirVetor(int vetor[], int tamanho) {
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

int main() {
    int meu_vetor = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;

    printf("Vetor original: ");
    imprimirVetor(meu_vetor, n);

    // Executa a ordenação por borbulhamento
    bubbleSort(meu_vetor, n);

    printf("Vetor ordenado de forma crescente: ");
    imprimirVetor(meu_vetor, n);

    return 0;
}
```

---

## 3. Análise de Desempenho e Eficiência Computacional

O Bubble Sort possui uma complexidade de tempo de ordem **$O(n^2)$** no pior caso e no caso médio, o que significa que o tempo de processamento cresce de forma quadrática em relação ao número de elementos (`n`).

*   **Pior Caso ($O(n^2)$):** Ocorre quando o vetor está em ordem decrescente exata. O algoritmo precisará realizar o número máximo de comparações e o número máximo de trocas físicas na memória.
*   **Melhor Caso ($O(n)$):** Ocorre se o vetor já estiver totalmente ordenado. Uma versão otimizada do algoritmo (utilizando uma variável booleana de controle para checar se houve trocas) consegue encerrar a execução logo na primeira varredura, realizando apenas $n-1$ comparações e nenhuma troca.

---

## 4. Comparativo entre Algoritmos Básicos de Ordenação

Quando avaliamos o cenário de algoritmos simples e didáticos (indicados para listas pequenas onde o desempenho bruto não é um fator crítico), três métodos destacam-se por apresentar estratégias de troca e inserção distintas:

| Algoritmo de Ordenação | Estratégia Principal | Ponto Forte / Vantagem | Limitação / Ponto Fraco |
| :--- | :--- | :--- | :--- |
| **Bubble Sort** | Compara vizinhos diretos aos pares e faz trocas sucessivas. | Facilidade de escrita, leitura e implementação lógica. | Baixa eficiência. Executa uma quantidade massiva de trocas na memória RAM. |
| **Insertion Sort**| Insere o elemento atual na posição correta de um subvetor já ordenado. | Desempenho excelente ($O(n)$) e altamente estável para listas quase ordenadas. | Custo computacional elevado se os dados estiverem muito dispersos. |
| **Selection Sort**| Localiza o menor elemento do vetor e o joga para o início da linha. | Realiza o menor número possível de trocas de variáveis na memória. | Ineficiente em checagens. Obriga-se a realizar muitas comparações independentemente do estado do vetor. |
