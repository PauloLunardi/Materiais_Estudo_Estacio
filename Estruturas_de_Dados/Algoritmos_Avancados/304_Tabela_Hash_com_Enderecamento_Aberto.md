# Tabela Hash com Endereçamento Aberto (Sondagem Linear)

Este documento apresenta a especificação técnica e o guia de implementação para uma **Tabela Hash com Endereçamento Aberto** utilizando a técnica de **Sondagem Linear (*Linear Probing*)** na linguagem C. Essa abordagem mantém todos os dados armazenados diretamente dentro do próprio vetor principal da tabela, eliminando o uso de ponteiros ou listas ligadas auxiliares.

---

## 1. O Conceito de Endereçamento Aberto e Sondagem Linear

Diferente do encadeamento separado (que cria listas externas para resolver colisões), o **Endereçamento Aberto** mantém todos os elementos residentes dentro do próprio array da tabela. 

Quando ocorre uma colisão (duas chaves mapeando para a mesma coordenada), o algoritmo inicia um processo de varredura sequencial chamado **Sondagem Linear**: se a posição calculada `i` estiver ocupada por outro registro, o sistema tenta a posição `i+1`, depois `i+2`, e assim por diante de forma circular, até localizar uma vaga livre para gravação.

---

## 2. Modelagem das Estruturas e Controle de Estados

Para aplicar a sondagem linear sem quebrar a lógica de buscas futuras, cada slot do vetor deve gerenciar explicitamente três estados possíveis através de uma variável indicadora:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 10

// Estrutura que representa cada célula de armazenamento do vetor
typedef struct {
    char nome[50]; // Espaço físico para guardar a string
    int ocupado;   // Máquina de Estados: 0 = Vazio, 1 = Ocupado, -1 = Removido
} Entrada;

// Vetor contíguo interno da tabela hash
Entrada tabela_hash[TAMANHO_TABELA];
```

### Significado Técnico dos Estados:
*   **`0` (Vazio / Livre):** A posição nunca foi utilizada. Funciona como um sinalizador de parada para os algoritmos de busca.
*   **`1` (Ocupado):** Contém um dado ativo e válido inserido pelo usuário.
*   **`-1` (Removido / Lápide):** Sinaliza que ali já existiu um dado, mas ele foi excluído. Esse estado impede que a busca pare antes da hora, garantindo que o programa continue varrendo as colisões jogadas para os slots seguintes.

---

## 3. Função de Mapeamento (Hash Simples)

A string de entrada é convertida em um índice válido de `0` a `9` acumulando os seus valores ASCII inteiros e aplicando o operador de resto da divisão:

```c
int funcao_hash(const char* chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }
    return soma % TAMANHO_TABELA;
}
```

---

## 4. Operações Essenciais do Sistema

### A. Inserção com Sondagem Linear
Inicia a busca a partir do índice calculado pela função hash. Caso a vaga esteja ocupada por outra palavra ativa, pula de uma em uma posição utilizando o operador módulo para dar a volta no vetor de forma circular.

```c
void inserir(const char* nome) { 
    int indice = funcao_hash(nome);
    
    // O laço tenta dar no máximo uma volta completa no vetor
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        // Calcula a próxima posição circular usando o incremento linear 'i'
        int pos = (indice + i) % TAMANHO_TABELA;
        
        // Se a gaveta estiver virgem (0) ou marcada como lápide (-1), grava o dado
        if (tabela_hash[pos].ocupado == 0 || tabela_hash[pos].ocupado == -1) {
            strcpy(tabela_hash[pos].nome, nome);
            tabela_hash[pos].ocupado = 1; // Ativa o estado ocupado
            return; // Encerra a escrita imediatamente
        }
    }
    printf("Erro: Overflow! Tabela cheia. Nao foi possivel inserir '%s'.\n", nome);
}
```

### B. Busca por Chave
A busca segue o mesmo padrão de saltos lineares da inserção para localizar chaves colididas. Ela utiliza as regras de estados para tomar decisões de parada ou avanço:

```c
int buscar(const char* nome) { 
    int indice = funcao_hash(nome);
    
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        int pos = (indice + i) % TAMANHO_TABELA;
        
        // REGRA DE OURO: Se achar 0, a busca para. O item nunca foi inserido.
        if (tabela_hash[pos].ocupado == 0) {
            return -1; 
        }
    
        // Se a posição estiver ativa e o texto bater com a chave, retorna o ID
        if (tabela_hash[pos].ocupado == 1 && strcmp(tabela_hash[pos].nome, nome) == 0) {
            return pos; // Retorna o índice numérico onde o dado está
        }
        
        // Nota: Se o estado for -1 (Removido), o laço ignora e continua procurando!
    }
    return -1; // Varreu o vetor inteiro e não achou nada
}
```

### C. Remoção Lógica
A exclusão não apaga fisicamente os bytes do texto ou zera o slot para `0`. Ela simplesmente altera o estado do marcador para `-1`.

```c
void remover(const char* nome) {
    int pos = buscar(nome); // Invoca o motor de busca para achar o índice
    
    if (pos == -1) {
        printf("'%s' nao foi localizado na tabela.\n", nome);
        return;
    }
 
    // Marcamos como Lápide (-1) para manter a integridade dos caminhos de busca
    tabela_hash[pos].ocupado = -1;
    printf("'%s' removido logicamente da tabela.\n", nome);
}
```

---

## 5. Orquestração e Validação no `main()`

O bloco principal do programa executa a carga de dados simulando colisões implícitas, checa chaves e roda exclusões controladas:

```c
int main() {
    // Inicialização Obrigatória: Configura todos os slots como vazios (0)
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela_hash[i].ocupado = 0;
    }
 
    // Escrita de dados
    inserir("Ana");
    inserir("Bruno");
    inserir("Carlos");
    inserir("Amanda"); // Chave com alto potencial de colidir com "Ana"
 
    // Testes de Consulta (Retorno diferente de -1 significa sucesso)
    printf("Buscando 'Bruno': %s\n", buscar("Bruno") != -1 ? "Encontrado" : "Não encontrado");
    printf("Buscando 'João': %s\n\n", buscar("João") != -1 ? "Encontrado" : "Não encontrado");
 
    // Testes de Remoção
    remover("Carlos"); // Passa o status da posição para -1
    remover("João");   // Dispara o feedback de ausência
 
    return 0;
}
```

---

## 6. Considerações de Arquitetura de Hardware

*   **Vantagem de Cache:** Ao manter todas as informações guardadas de forma sequencial e contígua dentro do mesmo vetor (sem saltos de ponteiros por alocações dispersas na memória *Heap*), o endereçamento aberto aproveita muito melhor o **Cache L1/L2 do Processador**, acelerando as checagens em microarquiteturas de CPU.
*   **Limitação por Agrupamento:** À medida que a tabela vai ficando cheia (fator de carga alto), blocos contínuos de posições ocupadas começam a se formar na memória. Esse fenômeno (*Primary Clustering*) faz com que as novas colisões demorem cada vez mais para achar uma vaga livre, degradando a velocidade do sistema.
