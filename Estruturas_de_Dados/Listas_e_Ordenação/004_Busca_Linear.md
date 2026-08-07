# Busca Linear

Este documento apresenta o conceito, o funcionamento e os exemplos práticos da **Busca Linear** (também conhecida como busca sequencial). Esta é uma das técnicas mais simples e diretas para localizar a posição de um determinado elemento dentro de uma estrutura de dados, sendo indispensável para a manipulação de coleções não ordenadas.

---

## 1. O Conceito de Busca Linear

A busca linear consiste em examinar, de maneira sequencial e um por um, todos os elementos de uma estrutura de dados até que o valor desejado seja localizado ou que o fim da lista seja atingido. 

A grande vantagem e aplicabilidade da busca linear estão na sua capacidade de operar em **listas não ordenadas**, onde os dados não seguem nenhum critério de arranjo prévio (como ordem alfabética ou numérica). Por conta disso, ela possui uma lógica intuitiva e de fácil implementação.

### Analogias do Mundo Real
*   **Procurando chaves na bolsa:** Imagine procurar uma chave perdida no fundo de uma bolsa cheia de objetos desorganizados. Como não há ordem ali dentro, a única estratégia viável é retirar e analisar item por item até encontrar a chave.
*   **Lista de chamada fora de ordem:** Pense em um professor procurando o nome de um aluno em uma lista de presença que não segue a ordem alfabética. O professor precisa ler cada linha, de cima para baixo. Se o aluno não tiver comparecido, o professor só descobrirá isso depois de ler a lista inteira até a última linha.
*   **Caixa com 50 chaves misturadas:** Para encontrar a chave correta do carro dentro de uma caixa bagunçada, você precisa realizar um processo sequencial e manual de verificação individual. Quanto mais chaves houver na caixa, mais demorado será o processo.

---

## 2. Exemplos Práticos de Implementação em C

A busca sequencial automatiza o comportamento humano de verificar item por item. Abaixo estão as implementações práticas dessa lógica tanto para vetores quanto para listas encadeadas.

### A. Busca Linear em Vetores (Arrays)
Em vetores, a busca caminha através dos índices numéricos. Se o valor for encontrado, o algoritmo retorna o índice da posição. Caso o loop termine sem localizar o elemento, retorna-se `-1` para sinalizar a ausência.

```c
#include <stdio.h>

// Função que percorre o vetor e retorna o índice do elemento ou -1
int buscaLinearVetor(int lista[], int tamanho, int valorBuscado) {
    // Percorre o vetor elemento por elemento através do índice
    for (int i = 0; i < tamanho; i++) {
        // Compara o elemento atual com o valor alvo
        if (lista[i] == valorBuscado) {
            return i; // Elemento encontrado, retorna a posição (índice)
        }
    }
    return -1; // Fim do vetor atingido sem encontrar o valor
}

int main() {
    int meu_vetor[5] = {40, 10, 50, 20, 30};
    int alvo = 20;
    
    int resultado = buscaLinearVetor(meu_vetor, 5, alvo);
    
    if (resultado != -1) {
        printf("O valor %d foi encontrado no indice: %d\n", alvo, resultado);
    } else {
        printf("O valor %d nao esta presente no vetor.\n", alvo);
    }
    
    return 0;
}
```

### B. Busca Linear em Listas Encadeadas
Em listas encadeadas, a busca navega de nó em nó utilizando os ponteiros de encadeamento. Uma variável contadora auxilia no rastreamento do número da posição atual do elemento.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

// Função que percorre a lista encadeada e retorna a posição do nó ou -1
int buscaLinearLista(No *lista, int valorBuscado) {
    No *atual = lista;
    int posicao = 0;
    
    // Caminha pela lista até atingir o ponteiro NULL do fim
    while (atual != NULL) {
        // Verifica se o campo de dados do nó atual corresponde ao alvo
        if (atual->dado == valorBuscado) {
            return posicao; // Retorna a posição sequencial onde foi achado
        }
        atual = atual->proximo; // Avança para o endereço do próximo nó
        posicao++;
    }
    return -1; // Percorreu toda a estrutura e não encontrou
}

int main() {
    // Alocação manual de nós para teste
    No *n1 = (No *) malloc(sizeof(No));
    No *n2 = (No *) malloc(sizeof(No));
    No *n3 = (No *) malloc(sizeof(No));

    if (n1 == NULL || n2 == NULL || n3 == NULL) return 1;

    n1->dado = 45; n1->proximo = n2;
    n2->dado = 88; n2->proximo = n3;
    n3->dado = 12; n3->proximo = NULL;

    int alvo = 88;
    int resultado = buscaLinearLista(n1, alvo);

    if (resultado != -1) {
        printf("O valor %d foi encontrado na posicao: %d\n", alvo, resultado);
    } else {
        printf("O valor %d nao foi encontrado na lista.\n", alvo);
    }

    free(n1); free(n2); free(n3);
    return 0;
}
```

---

## 3. Análise de Desempenho

O desempenho da busca linear é diretamente proporcional ao número total de elementos (`n`) contidos na estrutura de dados. O computador realiza essas comparações em frações de milissegundos, mas a eficiência varia de acordo com a localização do item:

| Situação do Elemento na Estrutura | Número Médio de Comparações | Eficiência |
| :--- | :---: | :--- |
| O valor está logo no **início** | 1 | Melhor Caso |
| O valor está localizado no **meio** | $n / 2$ | Caso Médio |
| O valor está localizado no **final** | $n$ | Pior Caso |
| O valor **não está presente** na lista | $n$ | Pior Caso |

---

## 4. Considerações Finais

A busca linear é um algoritmo elementar e robusto. Embora não seja recomendada para gerenciar volumes massivos de dados (onde técnicas como a busca binária apresentam maior eficiência), ela continua sendo a melhor escolha em cenários específicos:
1. Quando lidamos com estruturas de dados pequenas.
2. Quando a coleção de dados não está ordenada e o custo computacional para ordená-la não compensa o benefício da busca.
3. Quando as estruturas de dados utilizadas são ligadas por ponteiros (como listas encadeadas simples), onde o acesso direto a índices não é nativo.
