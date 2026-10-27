# Fluxo de Processo e Modelos de Ciclo de Vida

O fluxo de processo descreve como as atividades metodológicas, ações e tarefas de engenharia de software são organizadas em relação à sequência e ao tempo. Mesmo que um processo possua as mesmas atividades fundamentais (comunicação, planejamento, modelagem, construção e implantação), a forma como a equipe navega por elas define a dinâmica do projeto.

---

## Estrutura do Fluxo de Processo

Abaixo está o organograma das quatro estruturas principais de fluxo que moldam a execução de um projeto:

* **Fluxo de Processo Linear**
  * Avança em linha reta e sequência direta
  * Sequência fixa: Comunicação ➔ Planejamento ➔ Modelagem ➔ Construção ➔ Implantação
  * Características: Uma etapa só começa quando a anterior estiver 100% concluída. Não há retorno para fases passadas.
  * Cenário Ideal: Projetos com requisitos muito claros, estáveis e que dificilmente sofrerão alterações.

* **Fluxo de Processo Iterativo**
  * Executa as atividades de forma cíclica e repetitiva
  * Sequência cíclica: Executa as cinco etapas básicas ➔ Retorna ao início para refinar o produto ➔ Repete o ciclo
  * Características: Permite revisitar fases anteriores para refinar e polir os artefatos com base no aprendizado obtido.
  * Cenário Ideal: Projetos onde a equipe técnica precisa de tempo para amadurecer a arquitetura ou compreender melhor os requisitos ao longo do caminho.

* **Fluxo de Processo Evolucionário**
  * Desenvolve-se em um padrão circular e em espiral
  * Sequência em espiral: Cada volta completa pelas atividades gera uma versão mais robusta e evoluída do software
  * Características: Focado no gerenciamento rigoroso de riscos. Cada ciclo gera protótipos operacionais intermediários.
  * Cenário Ideal: Sistemas de grande porte, altamente complexos ou inovadores, onde os requisitos mudam constantemente no mercado.

* **Fluxo de Processo Paralelo**
  * Permite a execução de uma ou mais atividades de forma simultânea
  * Sequência sobreposta: Atividades diferentes ocorrem ao mesmo tempo para componentes distintos
  * Características: Reduz o tempo ocioso da equipe. Enquanto uma funcionalidade está na etapa de modelagem, outra já pode estar em construção.
  * Cenário Ideal: Equipes multidisciplinares e maduras que trabalham com sistemas modulares, onde as partes possuem pouca interdependência imediata.

---

## O Modelo de Ciclo de Vida Iterativo e Incremental

O modelo **Iterativo e Incremental** é a base das metodologias ágeis modernas e de processos robustos como o RUP (Rational Unified Process). Ele combina o conceito de refinamento (iteração) com o de entrega em pedaços (incremento).

### Estrutura do Ciclo
* **Fase de Definição:** Alinhamento dos Requisitos Globais do sistema.
* **Ciclo da Iteração 1:** Executa as atividades genéricas ➔ Entrega do **Incremento 1** (ex: Módulo de Login e Cadastro).
* **Ciclo da Iteração 2:** Executa as atividades genéricas ➔ Entrega do **Incremento 2** (ex: Módulo de Dashboard integrado ao Incremento 1).
* **Ciclo da Iteração 3:** Executa as atividades genéricas ➔ Entrega do **Incremento 3** (ex: Módulo de Relatórios integrado aos anteriores).

### Conceitos Fundamentais

* **Abordagem Iterativa:** O desenvolvimento é repetitivo. O sistema é planejado, projetado e testado várias vezes em ciclos curtos. Cada iteração gera um aprendizado que ajuda a corrigir o rumo do projeto e a melhorar a qualidade técnica.
* **Abordagem Incremental:** O produto final não é entregue de uma só vez no término do contrato. Em vez disso, ele é quebrado em partes menores e funcionais chamadas incrementos. Cada incremento adiciona uma nova fatia de valor utilizável ao software que já foi entregue anteriormente.

### Principais Benefícios desta Abordagem
* **Retorno de Investimento Rápido:** O cliente recebe partes do sistema prontas para uso real muito mais cedo.
* **Flexibilidade a Mudanças:** Como os ciclos são curtos, novos requisitos podem ser incorporados no início da próxima iteração sem destruir o trabalho anterior.
* **Mitigação de Riscos Técnicos:** Problemas de integração ou arquitetura inadequada são descobertos logo no primeiro incremento, evitando surpresas negativas no final do projeto.
