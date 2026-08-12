# Desafio Final: Gerenciador Avançado do Tetris Stack (Fila x Pilha)

Este documento apresenta a especificação técnica oficial e os requisitos de arquitetura para o desenvolvimento do sistema avançado de movimentação de peças no jogo **Tetris Stack**. O desafio do nível mestre consiste em projetar um ecossistema integrado onde uma **Fila Circular (FIFO)** e uma **Pilha Linear (LIFO)** interagem em tempo real, permitindo manobras estratégicas de reserva, substituição pontual e troca múltipla de blocos na memória RAM.

---

## 1. Visão Geral do Desafio

No nível mestre do Tetris Stack, o jogador ganha acesso a uma mecânica avançada de controle de inventário de blocos. Além de visualizar as próximas peças que entrarão no tabuleiro através de uma fila circular, ele poderá gerenciar uma área de armazenamento temporário (uma pilha de reserva).

O coração do desafio reside na capacidade de fazer as duas estruturas de dados se comunicarem de forma síncrona. O sistema deve permitir que o jogador alterne ordens de processamento, realize trocas diretas entre a cabeça da fila e o topo da pilha, ou até mesmo dispare uma manobra complexa de rotação em bloco de três elementos simultâneos. Tudo isso deve acontecer sem corromper os índices ou violar os limites de capacidade das coleções.

---

## 2. Requisitos do Sistema

### Requisitos Funcionais
As funcionalidades obrigatórias para a homologação do motor do jogo são:

1. **Estruturas de Dados Coesas:**
   * Struct `Peca`: Contendo as propriedades `char nome` (tipo da forma geométrica `'I'`, `'O'`, `'T'`, `'L'`) e `int id` (identificador numérico único sequencial).
   * Struct `FilaPecas`: Vetor de capacidade fixa igual a **5 elementos**, gerenciado de forma circular via operador módulo (`%`).
   * Struct `PilhaReserva`: Vetor linear de capacidade fixa limitada a **3 elementos**, controlado por um seletor de topo.
2. **Inicialização Automatizada:** O jogo deve ser inicializado gerando e inserindo automaticamente **5 peças** na fila de espera. A pilha de reserva deve nascer vazia (topo em `-1`).
3. **Gerenciamento Inteligente de Reposição:** Toda vez que a peça da frente for consumida ou enviada para a reserva, o sistema deve acionar a função `gerarPeca()` para criar um novo elemento invisível e manter a fila futura sempre cheia com 5 componentes ativos.
4. **Mecânicas de Movimentação e Fluxo:**
   * **Jogar Peça (*Dequeue*):** Consome a peça da frente da fila circular, retirando-a definitivamente do jogo.
   * **Reservar Peça (*Push* da Fila para Pilha):** Desloca o elemento da frente da fila para o topo da pilha de reserva, validando se há espaço livre na pilha (máximo 3).
   * **Usar Peça Reservada (*Pop*):** Consome e destrói o elemento localizado no topo da pilha de reserva.
   * **Trocar Peça Atual (Substituição Unitária):** Realiza uma permuta simples de valores invertendo os atributos da peça que está na frente da fila com os da peça que está no topo da pilha.
   * **Troca Múltipla (Permuta em Bloco):** Troca de lugar, de forma síncrona, os 3 primeiros elementos da fila com os 3 elementos empilhados na reserva. Esta manobra só é permitida se a pilha estiver totalmente cheia (3 itens) e a fila possuir ao menos 3 itens.
5. **Atualização do Dashboard:** O terminal deve renderizar o estado visual exato da fila e da pilha imediatamente após a conclusão de cada comando do menu de ações.

### Requisitos Não Funcionais
* **Usabilidade e Feedback Visual:** A saída no console deve apresentar uma divisão visual explícita e clara entre o painel da fila e o painel da pilha (exibida do topo para a base).
* **Robustez e Controle de Escopo:** O código deve conter travas lógicas contra estouro de capacidade (*overflow*) e leitura de posições vazias (*underflow*) em ambas as estruturas.
* **Legibilidade e Documentação:** O código-fonte precisa conter comentários detalhados descrevendo o propósito das variáveis, a movimentação de variáveis temporárias nas trocas e o fluxo das funções modulares.

---

## 3. Instruções Detalhadas de Implementação

A árvore do programa deve respeitar a separação rígida de responsabilidades e as seguintes diretrizes:

### A. Dependências e Bibliotecas
O cabeçalho do código deve importar os seguintes utilitários padrão:
```c
#include <stdio.h>   // Fluxos de leitura e escrita no console (printf, scanf)
#include <stdlib.h>  // Controle de memória e sorteio pseudoaleatório (rand, srand)
#include <string.h>  // Manipulação de strings e caracteres
#include <time.h>    // Semente temporal para o gerador de números aleatórios
```

### B. Mapeamento Lógico do Menu de Comandos
O loop de turnos principal (`do-while` ou `while`) deve ser controlado pelo jogador através da captura dos seguintes códigos fixos de operação:

| Código | Ação Executada pelo Mecanismo do Jogo |
| :---: | :--- |
| **1** | Jogar peça da frente da fila (Consome o início da Fila) |
| **2** | Enviar peça da fila para a pilha de reserva (Fila $\rightarrow$ Pilha) |
| **3** | Usar peça da pilha de reserva (Consome o topo da Pilha) |
| **4** | Trocar peça da frente da fila com o topo da pilha (Permuta $1 \times 1$) |
| **5** | Trocar os 3 primeiros da fila com as 3 peças da pilha (Permuta em Bloco $3 \times 3$) |
| **0** | Encerrar o programa e fechar o Tetris Stack |

---

## 4. Guia de Versionamento e Entrega (Tutorial Git)

A publicação da sua solução profissional no ecossistema do GitHub Classroom deve ser realizada seguindo o roteiro operacional:

1. **Acesso ao Repositório Modelo:** Clique no link do convite oficial enviado pela ByteBros para aceitar o desafio de nível mestre e gerar o seu repositório privado na nuvem.
2. **Inicialização do CodeSpace:** Ative uma instância do GitHub CodeSpaces integrada ao repositório para editar e compilar o código fonte diretamente na IDE baseada no navegador.
3. **Desenvolvimento Modular:** Escreva as estruturas e implemente as funções de troca nos arquivos de modelo preexistentes. Não altere o nome das pastas ou arquivos originais do projeto.
4. **Comentários de Auditoria:** Comente obrigatoriamente todas as seções principais do código. Seus comentários devem detalhar o funcionamento do algoritmo circular da fila, o comportamento LIFO da pilha e a forma como as variáveis auxiliares temporárias evitam a perda de dados durante as operações de troca (`case 4` e `case 5`).
5. **Sincronização e Push:** Salve o arquivo e utilize o terminal integrado para realizar o envio definitivo para os servidores de correção automática do GitHub:
   ```bash
   git add .
   git commit -m "Implementacao completa do gerenciador mestre de pecas - Fila x Pilha"
   git push origin main
   ```
