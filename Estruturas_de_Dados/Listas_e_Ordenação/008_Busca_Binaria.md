# Busca Binária

Este documento apresenta o conceito, a lógica de funcionamento e a implementação prática do algoritmo de **Busca Binária**. Trata-se de uma técnica de alta performance baseada no paradigma de "divisão e conquista", projetada especificamente para localizar elementos em estruturas de dados que já se encontram previamente ordenadas.

---

## 1. O Conceito de Busca Binária

A busca binária funciona dividindo a área de busca ao meio a cada passo executado. Em vez de verificar os itens um por um (como na busca sequencial), o algoritmo realiza uma comparação com o elemento central da estrutura e descarta metade dos elementos restantes na iteração seguinte.

Essa estratégia reduz drasticamente o número de comparações necessárias para encontrar um valor, tornando-a ideal para coleções com grandes volumes de dados.

### A Regra de Ouro e Funcionamento
Dado um vetor ordenado em ordem crescente, o algoritmo executa o seguinte roteiro:
1. Compara o valor buscado com o elemento localizado exatamente no **meio** do vetor.
2. Se o valor for igual ao do meio, a busca termina com sucesso.
3. Se o valor buscado for **menor** que o do meio, o algoritmo descarta toda a metade superior (à direita) e restringe a busca à metade inferior.
4. Se o valor buscado for **maior** que o do meio, o algoritmo descarta toda a metade inferior (à esquerda) e restringe a busca à metade superior.
5. O processo se repete afunilando os limites até o item ser encontrado ou o espaço de busca se esgotar.

> **Analogia do Dicionário:** Imagine procurar uma palavra em um dicionário impresso. Ninguém folheia a partir da primeira página (busca linear). A tendência humana é abrir o livro direto no meio, avaliar a letra da página e decidir se o termo procurado está mais para frente ou mais para trás. Cada vez que o livro é reaberto no meio do bloco restante, elimina-se uma quantidade massiva de páginas redundantes.

---

## 2. Exemplo Prático de Implementação em C

Abaixo está a implementação clássica da busca binária em sua forma iterativa. O algoritmo utiliza três variáveis de controle de escopo: `inicio`, `fim` e `meio`.

```c
#include <stdio.h>

// Função que executa a busca binária e retorna o índice ou -1
int buscaBinaria(int vetor[], int tamanho, int valorBuscado) {
    int inicio = 0;
    int fim = tamanho - 1;

    // O laço continua enquanto a área de busca possuir ao menos 1 elemento
    while (inicio <= fim) {
        // Calcula o índice do elemento central da área atual
        int meio = inicio + (fim - inicio) / 2;

        // Cenário 1: O valor desejado está exatamente no meio
        if (vetor[meio] == valorBuscado) {
            return meio; // Retorna a posição do elemento
        }

        // Cenário 2: O valor desejado é menor, descarta a metade direita
        if (vetor[meio] > valorBuscado) {
            fim = meio - 1; // O limite final recua para antes do meio
        }
        // Cenário 3: O valor desejado é maior, descarta a metade esquerda
        else {
            inicio = meio + 1; // O limite inicial avança para depois do meio
        }
    }

    return -1; // Espaço de busca esgotado, elemento não existe no vetor
}

int main() {
    // REQUISITO: O vetor DEVE estar ordenado para o algoritmo funcionar
    int dados_ordenados = {11, 21, 34, 45, 56, 67, 78, 89, 90};
    int total = 9;
    int alvo = 21;

    int resultado = buscaBinaria(dados_ordenados, total, alvo);

    if (resultado != -1) {
        printf("Elemento %d localizado com sucesso no indice: %d\n", alvo, resultado);
    } else {
        printf("Elemento %d nao encontrado no vetor.\n", alvo);
    }

    return 0;
}
```

---

## 3. Análise de Desempenho e Eficiência

O desempenho da busca binária segue a complexidade de tempo de ordem **O(log n)**, o que significa que o número de passos necessários cresce de forma logarítmica em relação ao número de elementos (`n`).

### Comparação Prática: Linear x Binária
A eficiência da divisão por dois fica evidente quando comparamos o pior caso de ambos os algoritmos em estruturas de tamanhos variados:

*   **Em uma lista com 1.000 elementos:**
    *   *Busca Sequencial:* Pode exigir até **1.000 comparações** se o item for o último ou não existir.
    *   *Busca Binária:* Exige no máximo **10 comparações**, pois $2^{10} = 1024$, espaço suficiente para isolar qualquer item.
*   **Em uma lista com 1.000.000 de elementos:**
    *   *Busca Sequencial:* Pode exigir até **1.000.000 de comparações**.
    *   *Busca Binária:* Exige no máximo **20 comparações** ($2^{20} = 1.048.576$).

---

## 4. Requisitos e Restrições Técnicas

Embora seja um dos algoritmos mais elegantes e eficientes da ciência da computação, a busca binária impõe uma restrição severa:

*   **Obrigadoriedade de Ordenação:** O algoritmo depende totalmente da ordenação prévia dos dados (seja crescente ou decrescente). Se for executado em um vetor desorganizado, as condições lógicas de corte falharão e o algoritmo produzirá resultados incorretos, deixando de encontrar elementos que estão presentes na lista.
*   **Acesso Direto:** Funciona de forma ideal em estruturas que suportam acesso direto por posição (como vetores). Em listas encadeadas simples, o custo para encontrar o elemento do "meio" quebrando a corrente consome o desempenho da busca, tornando-a menos vantajosa nessas estruturas.
