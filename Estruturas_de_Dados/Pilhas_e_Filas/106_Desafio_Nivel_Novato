# Desafio: Fila de Peças Futuras no Tetris Stack

Este documento apresenta a especificação técnica e as diretrizes de arquitetura para o desenvolvimento do sistema de gerenciamento de peças futuras para o jogo **Tetris Stack**, desenvolvido pela ByteBros. O objetivo do projeto é aplicar os conceitos de estruturas de dados lineares e circulares para simular o fluxo cronológico e ordenado de entrada e saída de peças através do modelo FIFO.

---

## 1. Visão Geral do Desafio

Na mecânica do jogo Tetris Stack, o jogador precisa visualizar quais serão as próximas peças a entrarem no tabuleiro para planejar a sua estratégia de posicionamento. Como desenvolvedor(a) técnico(a), você será responsável por construir o motor que gerencia essa fila de peças futuras. 

O sistema deve garantir o comportamento **FIFO (First In, First Out)**: a peça que está há mais tempo na fila de espera é obrigatoriamente a primeira a ser jogada (removida). O sistema operará com um vetor circular de tamanho fixo, permitindo o reaproveitamento inteligente do espaço de memória RAM à medida que o usuário interage com o terminal.

---

## 2. Requisitos do Sistema

### Requisitos Funcionais
As funcionalidades obrigatórias que determinam o comportamento do motor de peças são:

1. **Estrutura da Peça (Atributos):** Cada peça deve ser representada por um tipo de dado composto contendo:
   * `nome`: Caractere único que representa a forma geométrica da peça (`'I'`, `'O'`, `'T'`, `'L'`).
   * `id`: Um número inteiro exclusivo e sequencial que representa a ordem de nascimento da peça.
2. **Inicialização do Sistema:** O jogo deve inicializar a fila de peças futuras preenchendo-a de forma automática com um número fixo de **5 elementos** iniciais.
3. **Geração Automatizada:** As peças não são digitadas pelo jogador; elas devem ser geradas de forma automática pelo sistema por meio de uma função dedicada chamada `gerarPeca()`.
4. **Operações de Fluxo da Fila:**
   * **Jogar Peça (*Dequeue*):** Remove a peça localizada na frente da fila (a mais antiga) para ser posicionada no tabuleiro.
   * **Inserir Nova Peça (*Enqueue*):** Sorteia automaticamente uma nova peça e a adiciona no final da fila de espera, contanto que a capacidade do vetor circular não seja estourada.
5. **Atualização Visual:** O programa deve renderizar o painel com o estado atualizado da fila imediatamente após a execução de cada comando do menu, mostrando o nome e o ID de cada elemento em sequência.

### Requisitos Não Funcionais
Critérios de qualidade e boas práticas exigidos para a entrega do projeto:

* **Usabilidade Clara:** A saída de texto no terminal deve ser limpa e intuitiva, seguindo fielmente o modelo de exibição tabular.
* **Legibilidade e Organização:** O código-fonte deve ser bem estruturado, adotando nomes descritivos e autoexplicativos para funções, variáveis e contadores de controle.
* **Documentação por Comentários:** Inclusão obrigatória de comentários explicando a finalidade de cada bloco lógico, a atuação das equações matemáticas do vetor circular e o papel de cada parâmetro.

---

## 3. Instruções Detalhadas de Implementação

A arquitetura do programa deve respeitar os seguintes blocos e simplificações do nível básico:

### A. Dependências Básicas
O arquivo de código deve incluir os acessos às diretivas padrão do C:
```c
#include <stdio.h>   // Fluxos de leitura e escrita (printf, scanf)
#include <stdlib.h>  // Funções de utilidade e sorteio aleatório (rand, srand)
#include <string.h>  // Manipulação básica de caracteres
#include <time.h>    // Semente do relógio do sistema para aleatoriedade
```

### B. Definição das Estruturas e Vetor Circular
A fila operará sob um array de capacidade fixa com tratamento cíclico através do operador módulo (`%`):
```c
#define MAX 5

typedef struct {
    char nome; // Tipo da peça ('I', 'O', 'T', 'L')
    int id;    // Número de identificação único
} Peça;

typedef struct {
    Peça itens[MAX];
    int inicio;
    int fim;
    int total;
} FilaPecas;
```

### C. Menu de Comandos do Terminal
O loop principal do jogo deve rodar de forma contínua apresentando estritamente três opções fixas:

| Código do Comando | Ação Executada pelo Sistema |
| :---: | :--- |
| **1** | Jogar Peça (Executa o *Dequeue* na frente da fila) |
| **2** | Inserir Nova Peça (Executa o *Enqueue* automático no final) |
| **0** | Sair do Jogo (Encerra o loop e fecha o programa) |

---

## 4. Guia de Versionamento e Entrega (Tutorial Git)

O ciclo de publicação do desafio dentro da plataforma do GitHub Classroom deve seguir o roteiro operacional estruturado abaixo:

1. **Acesso ao Repositório:** Acesse o link de convite oficial enviado pela ByteBros/GitHub Classroom para vincular a tarefa à sua conta e gerar o seu repositório privado de desenvolvimento.
2. **Ativação do Ambiente:** Utilize o ambiente de nuvem do **GitHub CodeSpace** atrelado ao seu repositório para editar e compilar o código fonte diretamente através do navegador de internet.
3. **Desenvolvimento Localizado:** Modifique exclusivamente os arquivos modelo preexistentes na árvore do projeto. Não crie novos arquivos ou pastas fora do padrão estipulado.
4. **Inserção de Auditoria Teórica:** Comente exaustivamente todas as seções do arquivo de código. Seus comentários devem detalhar o funcionamento do algoritmo circular (`(fim + 1) % MAX`), o propósito das variáveis locais e a lógica das travas de segurança de fila cheia ou vazia.
5. **Sincronização Final:** Salve o arquivo e utilize o terminal integrado para realizar o envio definitivo para os servidores de correção automática do GitHub Classroom:
   ```bash
   git add .
   git commit -m "Implementacao da fila circular de pecas do Tetris Stack"
   git push origin main
   ```
