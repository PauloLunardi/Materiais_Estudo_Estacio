# Desafio Final: Sistema Integrado de Investigação no Detective Quest

Este documento apresenta a especificação técnica oficial e os requisitos de arquitetura para a conclusão do módulo avançado do jogo **Detective Quest**, desenvolvido pela Enigma Studios. O desafio do nível mestre consiste em projetar e implementar um ecossistema integrado onde três estruturas de dados avançadas cooperam em tempo real: uma **Árvore Binária Convencional** para o mapa, uma **Árvore Binária de Busca (BST)** para o inventário de evidências e uma **Tabela Hash** para a associação de suspeitos.

---

## 1. Visão Geral do Desafio

No capítulo mais desafiador da saga, o detetive deve explorar os cômodos da mansão para coletar pistas, mapear qual indício aponta para qual suspeito e, ao final, fazer uma acusação formal. Como desenvolvedor(a) técnico(a), você criará o motor que valida se a acusação possui embasamento lógico e provas suficientes para encerrar o caso.

O fluxo de dados funcionará de forma síncrona: a exploração física dos cômodos ativa o gatilho de coleta de pistas textuais. Essas pistas alimentam o inventário ordenado (BST). Em paralelo, uma Tabela Hash atua como o banco de dados de inteligência criminal do detetive, mapeando as pistas (chaves) diretamente aos seus respectivos suspeitos (valores). No julgamento final, o sistema varre o inventário, consulta a tabela hash e avalia automaticamente se há um veredito de culpabilidade (mínimo de duas provas contra o acusado).

---

## 2. Requisitos do Sistema

### Requisitos Funcionais
As funcionalidades obrigatórias que determinam o comportamento do motor do jogo compreendem:

1. **Modelagem de Estruturas Triplas Simultâneas:**
   * Struct `Sala`: Unidade do mapa hierárquico, contendo `char nome`, `char pista` e ponteiros `esquerda/direita`.
   * Struct `PistaNode`: Unidade do inventário ordenado (BST), contendo `char conteudo` e ponteiros `esquerda/direita`.
   * Struct `HashEntry` / `Tabela`: Células da Tabela Hash que amarram as propriedades chave-valor (`Pista` \(\rightarrow\) `Suspeito`).
2. **Carga e População Automática:** O mapa da mansão com suas pistas estáticas e a tabela hash conectando indícios aos suspeitos devem ser montados automaticamente na função `main()`. Não há digitação manual de salas ou suspeitos.
3. **Navegação Interativa por Comandos:** Controle do detetive no console através das opções de comando de movimentação: **esquerda (e)**, **direita (d)** ou **sair (s)**.
4. **Coleta Automatizada em Profundidade:** Ao pisar em um cômodo válido, a pista associada à sala é exibida e injetada na árvore BST de forma alfabética estrita via `inserirPista()`.
5. **Julgamento Automático por Provas:** Ao escolher sair (`'s'`), o sistema inicia a fase de julgamento: lista as evidências coletadas, solicita que o jogador digite o nome do suspeito acusado e invoca a função `verificarSuspeitoFinal()`.
6. **Regra de Culpabilidade:** O programa deve consultar a Tabela Hash para cada pista coletada. O réu só será considerado culpado se o detetive tiver conseguido arrecadar, no mínimo, **duas pistas independentes** que apontem diretamente para ele.

### Requisitos Não Funcionais
* **Usabilidade e Feedback de Investigação:** O console deve fornecer atualizações limpas dividindo visualmente as etapas de exploração de salas da fase de tribunal e veredito final.
* **Modularização Rígida:** Separação obrigatória de responsabilidades por funções isoladas com assinaturas explícitas.
* **Documentação Obrigatória:** Inclusão de comentários explicando a finalidade e a mecânica interna das seguintes funções-chave:
  * `criarSala()`: Aloca e cria de forma dinâmica um cômodo configurando seus ponteiros.
  * `explorarSalas()`: Controla o loop de movimentação e ativa o gatilho de coleta automática.
  * `inserirPista()`: Insere a pista textual coletada na árvore BST por ordem alfabética.
  * `inserirNaHash()`: Realiza a associação chave-valor inserindo a pista e o suspeito na tabela hash.
  * `encontrarSuspeito()`: Consulta a tabela hash para descobrir qual suspeito está amarrado a uma determinada pista.
  * `verificarSuspeitoFinal()`: Contabiliza as provas do inventário contra o acusado e dita o desfecho do jogo.

---

## 3. Simplificações e Restrições do Nível Mestre

Para mitigar a sobrecarga de gerenciamento e focar na comunicação mútua das estruturas de dados, o escopo adota os seguintes critérios:
* **Estruturas Estáticas em Tempo de Execução:** O mapa da mansão e o catálogo de suspeitos são fixos. O jogador não adiciona novas salas ou novos vilões durante a partida.
* **Encerramento Voluntário:** O loop do jogo não fecha por caminhos nulos; a exploração dura o tempo que o detetive desejar, encerrando-se especificamente quando ele decide ir para o julgamento digitando o comando `'s'`.

---

## 4. Topologia e Fluxo do Ecossistema Integrado (Arte ASCII)

O diagrama abaixo ilustra como as três ferramentas de dados conversam e compartilham informações de forma integrada dentro do fluxo do jogo:

```text
 ETAPA 1: MAPA DA MANSÃO                    ETAPA 2: INVENTÁRIO BST
 (Árvore Binária de Cômodos)               (Árvore Binária de Busca)
 
    [ Hall de Entrada ]                       [ Chave perdida ]
      (Pista: Nenhuma)                             /       \
       /            \                        [ G. P. ]   [ L. M. ]
   [Sala Estar]   [Biblioteca]
   (Pista: L.M.)  (Pista: C.P.)                   (Pistas Coletadas
                                                 Ordenadas de A a Z)
        │                │
        └───────┬────────┘
                ▼
 ETAPA 3: TABELA HASH DE INTELIGÊNCIA CRIMINAL
 (Associação Chave -> Valor)
 
   [ CHAVE: Pista ]          [ FUNÇÃO HASH ]          [ VALOR: Suspeito ]
  "Chave perdida"     ───►  [ Soma ASCII % M ]  ───►    "Mordomo Charles"
  "Lençol manchado"   ───►  [ Soma ASCII % M ]  ───►    "Mordomo Charles"
  "Gaveta perdida"    ───►  [ Soma ASCII % M ]  ───►    "Cozinheira Ana"
  
                │
                ▼
 ETAPA 4: TRIBUNAL E JULGAMENTO FINAL
  • Se Acusado == "Mordomo Charles" e Contagem(Provas) >= 2 ───► 🎉 CASO RESOLVIDO!
  • Caso contrário ───► ❌ CULPADO INOCENTADO / ERRO DE ACUSAÇÃO!
```
