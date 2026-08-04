# ⚔️ Nível Aventureiro: Interatividade no WAR Estruturado

Este documento detalha a especificação técnica e os requisitos para a implementação da funcionalidade de ataque entre territórios no projeto **War Estruturado**. Esta etapa consolida os conceitos de alocação dinâmica de memória, manipulação de estruturas por referência através de ponteiros e geração de números aleatórios em tempo de execução.

---

## 1. Visão Geral do Desafio

O objetivo principal desta etapa é adicionar interatividade ao sistema de jogo. Com base em um mapa de territórios cadastrado dinamicamente pelo usuário, o sistema deve permitir a seleção de um território atacante e um território defensor. 

A resolução da batalha ocorrerá por meio de uma simulação de rolagem de dados aleatórios. O resultado dessa disputa alterará diretamente o controle geopolítico (cor do exército) e o número de tropas dos territórios envolvidos na memória do computador.

---

## 2. Requisitos do Sistema

### 📌 Requisitos Funcionais
As funcionalidades essenciais que determinam o comportamento da simulação de batalha são:

1. **Alocação Dinâmica de Territórios:** O programa deve solicitar ao usuário o número total de territórios e utilizar as funções `malloc()` ou `calloc()` para reservar o espaço exato na memória para o vetor da estrutura `Territorio`.
2. **Simulação de Ataques:** Criação de uma função especializada com a assinatura `void atacar(Territorio* atacante, Territorio* defensor)` para processar as batalhas utilizando números pseudoaleatórios como dados.
3. **Atualização de Dados:** Caso o atacante vença, o território defensor deve mudar de dono (receber a cor do exército atacante) e ter sua quantidade de tropas recalculada.
4. **Exibição Pós-Ataque:** O sistema deve renderizar na tela o estado atualizado de todos os territórios imediatamente após a resolução de cada rodada de ataque.

### ⚡ Requisitos Não Funcionais
Critérios de qualidade, usabilidade e boas práticas de arquitetura de software:

* **Modularização:** O código-fonte deve ser separado rigidamente em funções distintas para cada responsabilidade: cadastro, exibição, processamento de ataque e liberação de memória.
* **Uso de Ponteiros:** Todos os acessos, leituras e modificações nas propriedades dos territórios dentro das funções especializadas devem ser realizados obrigatoriamente através de ponteiros.
* **Gerenciamento de Memória:** Toda a memória solicitada ao sistema operacional na inicialização deve ser explicitamente devolvida utilizando a função `free()` antes do encerramento do programa para evitar *Memory Leaks*.
* **Interface Amigável:** O terminal de comando deve ser intuitivo, orientando o jogador com clareza sobre quais índices de territórios estão disponíveis e válidos para ações militares.

---

## 3. Instruções Detalhadas de Implementação

Para garantir a conformidade com as regras de avaliação, a arquitetura do programa deve seguir este roteiro:

### A. Dependências e Bibliotecas
O arquivo de código deve incluir as seguintes diretivas de compilação:
* `<stdio.h>` e `<stdlib.h>` (Entrada/saída padrão e funções de alocação).
* `<string.h>` (Manipulação e cópia de cadeias de caracteres).
* `<time.h>` (Alimentação da semente do gerador aleatório).

### B. Definição da Estrutura Base
A `struct` deve respeitar rigorosamente os seguintes tipos e limites de dados:
```c
typedef struct {
    char nome[30];  // Nome do território (Ex: "Egito")
    char cor[10];   // Identificação do exército (Ex: "Azul")
    int tropas;     // Quantidade de exércitos alocados
} Territorio;
```

### C. Regras de Negócio e Mecânicas da Função `atacar()`
* A função deve simular uma rolagem de dados gerando valores inteiros de **1 a 6** para ambos os lados através do uso de `rand()`.
* **Cenário de Vitória (Dado do Atacante > Dado do Defensor):** O território defensor passa a pertencer ao exército do atacante (copia-se a string `cor`). O território defensor recebe metade das tropas atuais do atacante. O atacante perde essa mesma quantidade transferida para ocupação.
* **Cenário de Derrota (Dado do Atacante <= Dado do Defensor):** O defensor resiste. O território atacante perde exatamente **1 tropa** como penalidade pelo fracasso.

---

## 4. Requisitos Técnicos Adicionais (Validações Críticas)

Para mitigar falhas de segmentação e garantir a robustez do software, as seguintes travas técnicas devem ser implementadas no código:

* **Semente Aleatória:** O gerador deve ser inicializado no início da função `main` através do comando `srand(time(NULL))` para assegurar que os resultados dos dados variem a cada execução do jogo.
* **Validação de Fronteiras Diplomáticas:** O sistema não deve permitir que o usuário selecione territórios que possuam a mesma cor para guerrearem entre si.
* **Desalocação Segura:** A memória deve ser liberada por uma rotina específica (`void liberarMemoria(Territorio* mapa)`) garantindo o encerramento correto do ciclo de vida dos dados dinâmicos.

---
