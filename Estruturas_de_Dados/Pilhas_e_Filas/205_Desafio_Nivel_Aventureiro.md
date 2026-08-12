# Desafio: Integração de Fila Circular e Pilha de Reserva no Tetris Stack

Este documento apresenta a especificação técnica e as diretrizes de arquitetura para o desenvolvimento do módulo intermediário do jogo **Tetris Stack**. O objetivo do projeto é aplicar de forma simultânea e coordenada duas estruturas de dados lineares fundamentais: uma **Fila Circular** para as peças futuras e uma **Pilha Linear** para o sistema de reserva, demonstrando na prática as diferenças operacionais entre os fluxos FIFO e LIFO.

---

## 1. Visão Geral do Desafio

Na mecânica avançada do Tetris Stack, o jogador ganha uma nova camada de estratégia: a capacidade de gerir uma mochila de reserva de componentes. O jogo exige o monitoramento síncrono de duas estruturas:

*   **Fila de Peças Futuras (Ordem FIFO):** Uma esteira rolante de tamanho fixo (5 posições) que mostra as próximas peças que entrarão no tabuleiro. A peça localizada na frente da fila é sempre a bola da vez.
*   **Pilha de Reserva (Ordem LIFO):** Um espaço guardado de capacidade restrita (3 posições) onde o jogador pode armazenar temporariamente uma peça estratégica para usar mais tarde. Respeitando a lógica de pilhas, a última peça guardada é obrigatoriamente a primeira a ser recuperada.

A cada ação realizada pelo usuário (seja jogar ou reservar), a engrenagem do jogo deve disparar um gatilho de reposição automática no final da fila circular, mantendo o painel de peças futuras sempre completo.

---

## 2. Requisitos do Sistema

### Requisitos Funcionais
As rotinas obrigatórias para o funcionamento do motor de jogo combinado são:

1. **Atributos das Peças:** Cada peça gerada de forma automatizada pelo sistema possui um caractere indicador de forma (`'I'`, `'O'`, `'T'`, `'L'`) e um número inteiro identificador único (`id`) sequencial.
2. **Inicialização Síncrona:** O programa deve preparar a memória RAM configurando a fila com **5 peças iniciais** e inicializando a pilha de reserva como vazia.
3. **Mecânica de Movimentação e Fluxo:**
   *   **Jogar Peça (*Dequeue*):** Remove a peça localizada na frente da fila circular e a elimina do jogo.
   *   **Reservar Peça (*Push* via *Dequeue*):** Retira a peça da frente da fila futura e a empilha no topo da reserva, contanto que a pilha não exceda o limite de 3 slots.
   *   **Usar Peça Reservada (*Pop*):** Retira e consome a peça que está posicionada no topo da pilha de reserva.
4. **Alimentação Contínua:** Toda vez que a peça da frente da fila for consumida (por um comando de jogo ou de reserva), o algoritmo deve gerar imediatamente uma nova peça via `gerarPeca()` e inseri-la no final da fila para mantê-la sempre cheia.
5. **Atualização do Painel Visual:** O console deve renderizar de forma clara e separada a composição da fila circular e o empilhamento da reserva (do topo para a base) logo após o término de cada turno.

### Requisitos Não Funcionais
Critérios de qualidade, design e boas práticas para o código:

*   **Usabilidade Clara:** Criação de divisórias visuais explícitas no console para separar o painel da fila do painel da pilha de reserva.
*   **Legibilidade Estruturada:** Uso de nomes autoexplicativos e claros para variáveis, contadores de controle de índices e ponteiros.
*   **Documentação Interna:** Comentários detalhados descrevendo o papel de cada bloco lógico, as validações de limites (*overflow* e *underflow*) e as manipulações matemáticas do vetor circular.

---

## 3. Instruções Detalhadas de Implementação

A arquitetura do software deve respeitar as seguintes estruturas e simplificações do nível intermediário:

### A. Dependências Básicas
O cabeçalho do código deve carregar as seguintes inclusoes:
```c
#include <stdio.h>   // Fluxos de leitura e escrita no console
#include <stdlib.h>  // Funções utilitárias e gerador de aleatoriedade (rand, malloc)
#include <string.h>  // Manipulação de strings e caracteres
#include <time.h>    // Semente do relógio para aleatoriedade estável
```

### B. Estruturas Complexas de Dados
A modelagem dos componentes utiliza structs aninhadas com capacidade estática e circular:
```c
#define MAX_FILA 5
#define MAX_PILHA 3

typedef struct {
    char nome;
    int id;
} Peca;

typedef struct {
    Peca itens[MAX_FILA];
    int inicio;
    int fim;
    int total;
} FilaCircular;

typedef struct {
    Peca itens[MAX_PILHA];
    int topo;
} PilhaLinear;
```

### C. Menu de Interação de Comandos
O console do jogo deve rodar dentro de um laço `do-while` expondo as seguintes quatro opções fixas:

| Código | Ação Executada pelo Sistema | Impacto nas Estruturas |
| :---: | :--- | :--- |
| **1** | Jogar Peça | *Dequeue* na fila + Gerar nova peça para o final da fila. |
| **2** | Reservar Peça | *Dequeue* na fila + *Push* na pilha + Gerar nova peça para o final da fila. |
| **3** | Usar Peça Reservada | *Pop* no topo da pilha de reserva. |
| **0** | Sair do Jogo | Encerra o loop e encerra a execução. |

---

## 4. Guia de Entrega e Versionamento (Tutorial Git)

O ciclo de publicação do projeto dentro da plataforma do GitHub Classroom deve ser executado conforme as seguintes etapas:

1. **Acesso ao Repositório:** Clique no link fornecido pela ByteBros/GitHub Classroom para aceitar o desafio e clonar automaticamente o repositório modelo em sua conta do GitHub.
2. **Desenvolvimento via CodeSpaces:** Ative a ferramenta **GitHub CodeSpace** integrada ao seu repositório para editar e testar o arquivo de código-fonte diretamente pelo navegador.
3. **Escrita e Modularização:** Codifique os blocos lógicos nos arquivos modelo existentes na árvore do projeto. Respeite as validações de barramento (não deixar reservar se a pilha estiver cheia e não deixar usar da reserva se ela estiver vazia).
4. **Comentários de Auditoria:** Documente por completo o arquivo de código. Explique a lógica de transição onde o dado sai do início da fila circular e é injetado diretamente no topo da pilha.
5. **Sincronização Final:** Execute a sequência de comandos Git no terminal para homologar a entrega final da sua tarefa:
   ```bash
   git add .
   git commit -m "Implementacao da fila combinada com pilha de reserva do Tetris Stack"
   git push origin main
   ```
