# 🏆 Nível Mestre: Desafio Final – Missões Estratégicas no WAR Estruturado

Este documento apresenta a especificação técnica oficial e as diretrizes de arquitetura para a conclusão do desenvolvimento do jogo **War Estruturado**. O desafio do nível mestre consiste em integrar as mecânicas de combate anteriores a um sistema dinâmico de objetivos secretos individuais, consolidando o uso de ponteiros, alocação dinâmica de memória no *Heap*, modularização rígida e herança de conceitos como *Const Correctness*.

---

## 1. Visão Geral do Desafio

A etapa final adiciona uma camada profunda de imprevisibilidade e estratégia ao jogo: a **funcionalidade de missões estratégicas**. 

No início da partida, cada jogador receberá uma missão sorteada de forma automática a partir de um banco de descrições pré-definidas (armazenadas em um vetor de strings). Essa missão guiará as ações do usuário e será checada silenciosamente pelo motor do jogo a cada fim de turno para validar se a condição de vitória global foi atingida.

---

## 2. Requisitos do Sistema

### 📌 Requisitos Funcionais
Rotinas obrigatórias que determinam as regras do jogo e do sorteio:

1. **Criação do Vetor de Missões:** Declaração de um banco de dados estático contendo ao menos **cinco descrições diferentes** de objetivos militares (Ex: *"Conquistar 3 territórios"*, *"Eliminar o exército Vermelho"*, etc.).
2. **Sorteio e Atribuição da Missão:** Implementação da função `void atribuirMissao(char* destino, char* missoes[], int totalMissoes)` encarregada de sortear um índice aleatório e copiar o texto para a variável do jogador via `strcpy`.
3. **Armazenamento Dinâmico:** A string da missão ativa do jogador deve ter seu espaço reservado dinamicamente utilizando a função `malloc()`.
4. **Verificação Automatizada:** Implementação da função `int verificarMissao(char* missao, Territorio* mapa, int tamanho)`. Ela avalia o mapa e retorna `1` (verdadeiro) se as condições do objetivo foram cumpridas, ou `0` (falso) caso contrário.
5. **Exibição Condicional:** Monitoramento ao final de cada rodada. Assim que a função de verificação confirmar o cumprimento, o jogo deve congelar, declarar o vencedor e encerrar o loop principal.

### ⚡ Requisitos Não Funcionais
Critérios de qualidade arquitetural e engenharia de software:

* **Modularização Avançada:** Divisão cirúrgica do arquivo-fonte. A função `main()` deve atuar estritamente como uma orquestradora (cérebro), delegando as tarefas para as funções: `atribuirMissao`, `verificarMissao`, `exibirMissao`, `atacar`, `exibirMapa` e `liberarMemoria`.
* **Manipulação por Ponteiros:** Todos os textos de missões e vetores de dados de territórios devem ser transferidos e processados entre os escopos por meio de ponteiros.
* **Passagem de Parâmetros Mista:** A string da missão deve ser passada **por valor** (ou ponteiro constante) para rotinas de exibição e **por referência** para rotinas de atribuição e validação de vitória.
* **Interface Fluida (UX):** A missão deve ser revelada ao jogador de forma clara apenas no início da partida. Ao longo dos turnos, o sistema realiza a checagem de integridade em segundo plano (silenciosamente), sem poluir o terminal.

---

## 3. Instruções Detalhadas de Implementação

A árvore lógica e a distribuição de componentes devem seguir a formatação técnica descrita abaixo:

### A. Bibliotecas Requeridas
O cabeçalho do código deve conter os acessos às ferramentas padrão de gerenciamento e strings do C:
```c
#include <stdio.h>   // Entrada e saída padrão (printf, scanf)
#include <stdlib.h>  // Alocação dinâmica e sorteios (malloc, calloc, free, rand)
#include <string.h>  // Manipulação de strings (strcpy, strcmp, strcspn)
#include <time.h>    // Captura do relógio do sistema (srand)
```

### B. Estrutura e Escopos de Memória
O mapa deve utilizar um vetor dinâmico baseado na seguinte `struct`:
```c
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;
```
* **Alocação de Recursos:** A `main()` inicializa um ponteiro `Territorio *mapa` (via `calloc`) e um ponteiro `char *missao_jogador` (via `malloc`) com tamanho suficiente para armazenar a maior string de descrição.

### C. Dinâmica de Combate e Atualização de Campos
A função `atacar(Territorio* atacante, Territorio* defensor)` avalia rolagens pseudoaleatórias de dados (intervalo clássico de **1 a 6**):
* **Vitória do Atacante:** O defensor capitula. A string `cor` do atacante é copiada para o defensor. O defensor recebe metade (divisão inteira `/ 2`) das tropas do atacante, e o atacante perde a quantidade deslocada.
* **Derrota do Atacante:** A defesa resiste firmemente. O território atacante sofre uma baixa, perdendo exatamente **1 tropa** de sua guarnição.

### D. Encerramento Seguro (Gerenciamento do Heap)
A rotina `void liberarMemoria(...)` deve aceitar múltiplos ponteiros ou ser executada sequencialmente ao fim da `main` para limpar **tanto o vetor de territórios quanto a string da missão alocada**, blindando o sistema contra vazamentos (*memory leaks*).

---

## 4. Requisitos Técnicos Adicionais e Trava de Segurança

* **Semente (`srand`):** O comando `srand((unsigned int)time(NULL));` deve ser acionado uma única vez na primeira linha da `main()` para garantir que o sorteio de missões e dados de combate mude a cada reinicialização do executável.
* **Fronteiras Inimigas:** O sistema deve validar as coordenadas de entrada do usuário impedindo ações de fogo amigo (um jogador escolher atacar um território dominado pela sua própria cor de exército).
* **Documentação Interna:** Cada assinatura de função e bloco condicional de recálculo matemático deve conter comentários curtos e expressivos detalhando sua responsabilidade.

---
