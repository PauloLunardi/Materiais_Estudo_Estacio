# Desafio: Coleta e Organização de Pistas no Detective Quest

Este documento apresenta a especificação técnica oficial e os requisitos de engenharia para o desenvolvimento do sistema integrado de navegação e coleta de vestígios criminais do jogo **Detective Quest**, produzido pela Enigma Studios. O objetivo do projeto é aplicar os conceitos de estruturas hierárquicas não lineares através da operação simultânea de duas arquiteturas distintas: uma **Árvore Binária Convencional** para o mapa e uma **Árvore Binária de Busca (BST)** para o inventário de evidências.

---

## 1. Visão Geral do Desafio

O enredo expandido do jogo exige que o detetive não apenas caminhe pelos cenários da mansão, mas também recolha indícios cruciais deixados pelo culpado em cada ambiente visitado. Sua missão é estender a engine anterior criando um fluxo de dados contínuo onde a exploração física dispara uma operação automatizada de catalogação em memória.

O programa gerencia duas estruturas em paralelo: o mapa fixo da Mansão Enigma (onde cada nó carrega o nome do cômodo e uma string contendo uma pista embutida) e uma árvore de busca secundária (BST). No momento em que o detetive pisa em um cômodo, a pista local é "recolhida" pelo motor do jogo e inserida na BST. Ao encerrar a partida, o inventário de evidências deve ser processado recursivamente para exibir todas as pistas coletadas organizadas em ordem alfabética estrita.

---

## 2. Requisitos do Sistema

### Requisitos Funcionais
As propriedades e rotinas obrigatórias para a validação do software compreendem:

1. **Modelagem de Tipos Personalizados Duplos:**
   * Struct `Sala`: Representa o mapa hierárquico, contendo `char nome[50]`, `char pista[100]` (conteúdo opcional da evidência) e ponteiros `esquerda/direita`.
   * Struct `PistaNode`: Unidade base da árvore de inventário BST, contendo `char conteudo[100]` e ponteiros `esquerda/direita`.
2. **Construção Fixa de Cenários:** O mapa da mansão com suas respectivas pistas deve ser instanciado de forma estática e automática na função `main()` através do encadeamento do módulo `criarSala()`. Não há alteração do mapa em tempo de execução.
3. **Navegação Interativa e Entrada de Comandos:** Leitura contínua das diretrizes do jogador no console através das opções de comando: **esquerda (e)**, **direita (d)** ou **sair (s)**.
4. **Coleta e Injeção Automatizada:** Toda vez que o usuário migrar para uma nova sala válida, o sistema deve checar se há uma pista associada. Caso positivo, o conteúdo textual deve ser repassado automaticamente para a função `inserirPista()`, alimentando a árvore BST.
5. **Encerramento Controlado:** A jornada não possui fim automático por nós folhas neste nível; ela continua ativa até que o jogador digite o comando de parada voluntária (`'s'`).
6. **Exibição Alfabética das Evidências:** No momento da saída, o sistema deve acionar o caminhamento recursivo em ordem (*In-Order Traversal*) sobre a árvore BST, renderizando uma listagem alfabética de todas as pistas acumuladas na investigação.

### Requisitos Não Funcionais
* **Usabilidade e Clareza de Painel:** O terminal deve exibir mensagens informativas limpas sobre o nome do cômodo corrente, se uma pista foi coletada e os caminhos disponíveis em cada bifurcação.
* **Nomenclatura Descritiva:** Uso rigoroso de identificadores explícitos para ponteiros, strings e travas de segurança de fluxo.
* **Documentação por Código Fonte:** Inclusão de comentários explicando a finalidade das seguintes funções essenciais:
  * `criarSala()`: Instancia dinamicamente um cômodo configurando o nome e o texto da pista correspondente.
  * `inserirPista()`: Insere uma nova string de evidência na árvore BST respeitando os critérios de ordenação alfabética (`strcmp`).
  * `explorarSalasComPistas()`: Orquestra o laço de navegação pelos cenários e dispara o gatilho automático de coleta.
  * `exibirPistas()`: Executa o percurso em ordem na BST para imprimir as evidências organizadas de A a Z.

---

## 3. Simplificações e Escopo de Arquitetura

Para manter o foco no uso combinado e na transferência de dados entre árvores, o escopo respeita os seguintes critérios do nível aventureiro:
* **Árvores Estáticas e Desbalanceadas:** O mapa físico não sofre remoções ou expansões em tempo de execução. A árvore de busca (BST) crescerá de forma puramente recursiva descendente, sem a obrigatoriedade de algoritmos de balanceamento automático (como AVL ou Red-Black).
* **Navegação Linear Segura:** Caso o usuário escolha um caminho nulo (`NULL`), o sistema emite um alerta de parede ou bloqueio e mantém o detetive na sala atual para impedir falhas de acesso de ponteiros (*Segmentation Fault*).

---

## 4. Topologia Estrutural do Ecossistema (Arte ASCII)

O diagrama abaixo ilustra como as duas estruturas de dados se comunicam e operam de forma isolada e simultânea na memória RAM do computador durante a jogabilidade:

```text
    ESTRUTURA 1: MAPA DA MANSÃO                    ESTRUTURA 2: BST DE PISTAS
 (Árvore Binária Convencional)                     (Árvore Binária de Busca)
 
         [ Hall de Entrada ]                             [ Pista B ]
            (Pista: Nenhuma)                               /     \
             /             \                         [ Pista A ] [ Pista C ]
            /               \
     [Sala de Estar]     [Biblioteca]
     (Pista: Pista B)    (Pista: Pista C)               (Inventário de Evidências
           /                                             Recuperado em Ordem)
          /
      [Quarto]
  (Pista: Pista A)
```
