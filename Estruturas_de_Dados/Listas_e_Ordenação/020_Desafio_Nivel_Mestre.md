# Desafio Final: Sistema de Priorização e Montagem da Torre de Fuga

Este documento apresenta a especificação técnica oficial e as diretrizes de arquitetura para a conclusão do módulo avançado de organização de dados do jogo. O desafio do nível mestre consiste em projetar e implementar um ambiente de teste e execução de múltiplos algoritmos de ordenação e busca linear/binária aplicados a uma estrutura composta de dados, mensurando empiricamente o consumo de tempo e o número de operações lógicas em tempo de execução.

---

## 1. Visão Geral do Desafio

O cenário simula o fechamento da última safe zone da ilha. Para escapar, o jogador deve organizar e priorizar os componentes necessários para construir uma torre de resgate. Esta etapa consolida os conceitos de algoritmos de ordenação (Bubble Sort, Insertion Sort e Selection Sort) e busca logarítmica (Busca Binária), exigindo que o jogador analise os impactos de desempenho (comparações feitas e tempo gasto) de cada escolha estratégica.

O sistema opera permitindo que o utilizador ordene até 20 componentes sob três critérios distintos (nome, tipo ou prioridade). Após organizar o inventário por nome, habilita-se a execução de uma busca binária para localizar um componente-chave indispensável para a ativação da torre de fuga.

---

## 2. Requisitos do Sistema

### Requisitos Funcionais
1. **Criação da Estrutura Base:** Definição da `struct Componente` contendo as propriedades `char nome[30]`, `char tipo[20]` e `int prioridade`.
2. **Entrada e Cadastro de Dados:** O sistema deve permitir o cadastro dinâmico de até 20 componentes essenciais da torre. Cada entrada deve coletar o nome (ex: "chip central"), o tipo (ex: "controle", "suporte", "propulsao") e o nível de prioridade mapeado de 1 a 10.
3. **Opções de Ordenação por Critério:**
   * **Bubble Sort:** Ordenação alfabética crescente baseada no campo `nome` (comparação de strings).
   * **Insertion Sort:** Ordenação alfabética crescente baseada no campo `tipo` (comparação de strings).
   * **Selection Sort:** Ordenação numérica crescente baseada no campo `prioridade` (comparação de inteiros).
4. **Busca Binária de Alta Performance:** Aplicável unicamente após o inventário ser ordenado pelo critério de nome. Serve para rastrear o componente-chave que dispara a ativação do plano de fuga.
5. **Medição de Desempenho e Benchmarking:**
   * Rastreamento e exibição do número exato de comparações textuais ou numéricas feitas por cada rotina.
   * Rastreamento do tempo de execução de cada algoritmo medido de forma empírica através da função `clock()` da biblioteca `<time.h>`.
6. **Montagem e Confirmação Visual:** Renderização do painel de componentes atualizado após cada operação e confirmação visual de que o item-chave foi detectado e ativado.

### Requisitos Não Funcionais
* **Interface Amigável e Interativa:** Implementação de um menu interativo de linha de comando estável que permita a navegação fluida entre cadastros, escolhas de algoritmos e consultas.
* **Feedback Educacional:** Exibição clara e explícita dos contadores de operações e milissegundos para fins de análise comparativa de algoritmos.
* **Modularização Rígida:** Cada rotina de ordenação, busca e utilitário de medição deve residir em uma função isolada com responsabilidade única para facilitar manutenções.
* **Documentação Interna:** Comentários explicativos detalhados sobre as assinaturas de funções e lógica interna dos laços aninhados e ponteiros de função.

---

## 3. Instruções Detalhadas de Implementação

A arquitetura do código-fonte e o arranjo de componentes devem seguir estritamente o roteiro técnico abaixo:

### A. Dependências Obrigatórias
O topo do arquivo-fonte deve carregar as seguintes diretivas:
```c
#include <stdio.h>   // Fluxos de entrada e saída padrão
#include <stdlib.h>  // Funções utilitárias do sistema
#include <string.h>  // Manipulação segura de strings (strcmp, strcpy, strcspn)
#include <time.h>    // Captura de ciclos de clock para medição de desempenho
```

### B. Assinaturas Funcionais Obrigatórias
O contrato de desenvolvimento do programa exige a presença dos seguintes módulos especializados:
```c
void bubbleSortNome(Componente lista[], int n);
void insertionSortTipo(Componente lista[], int n);
void selectionSortPrioridade(Componente lista[], int n);
int buscaBinariaPorNome(Componente lista[], int n, char alvo[]);
void mostrarComponentes(Componente lista[], int n);
void medirTempo(void (*algoritmo)(Componente[], int), Componente vetor[], int tamanho);
```

### C. Captura Segura de Dados e Strings
Para blindar o buffer de entrada e capturar os textos sem quebras na interface, deve-se adotar o uso de `fgets()` combinado com o tratamento do caractere de quebra de linha (`\n`):
```c
fgets(lista[i].nome, 30, stdin);
lista[i].nome[strcspn(lista[i].nome, "\n")] = '\0'; // Remove o \n do buffer de forma limpa
```

---

## 4. Guia de Versionamento e Entrega (Tutorial Git)

A publicação e entrega do desafio de nível mestre no ambiente do GitHub Classroom deve ser realizada seguindo o protocolo de versionamento abaixo:

1. **Acesso ao Repositório:** Clique no link oficial disponibilizado pela sua coordenação para aceitar a atribuição e criar o repositório privado do nível mestre associado à sua conta.
2. **Uso do CodeSpaces:** Ative a extensão do GitHub CodeSpaces diretamente no seu repositório para editar os arquivos de código-fonte direto pelo navegador de internet, eliminando a necessidade de configurações locais.
3. **Desenvolvimento e Modularização:** Desenvolva as estruturas de dados e os algoritmos nos arquivos modelo preexistentes. Certifique-se de preencher as lógicas internas respeitando as regras de negócio de ordenação por strings e inteiros.
4. **Comentários de Auditoria:** Comente todas as seções cruciais do código, justificando o papel das variáveis de controle, o cálculo do índice médio na busca binária e a lógica de incremento dos contadores de comparação.
5. **Sincronização e Push Final:** No terminal do CodeSpaces, execute a sequência de comandos Git para registrar o progresso e realizar o upload definitivo:
   ```bash
   git add .
   git commit -m "Implementacao completa do desafio nivel mestre - Torre de Fuga"
   git push origin main
   ```
