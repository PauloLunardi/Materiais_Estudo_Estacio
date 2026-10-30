# O Processo Unificado e o RUP (Rational Unified Process)

O **Processo Unificado** é um framework de desenvolvimento de software iterativo e incremental que surgiu da fusão de práticas consolidadas da indústria de tecnologia, sendo intimamente ligado à criação da UML (Unified Modeling Language). O **RUP (Rational Unified Process)** é a versão comercializada e refinada originalmente pela Rational Software (hoje IBM), que detalha as tarefas, papéis e artefatos de engenharia.

---

## Os 3 Princípios Fundamentais do Processo Unificado

Para orientar a execução técnica e gerencial dos projetos, o Processo Unificado se apoia em três pilares conceituais esmagadoramente cobrados na literatura de **Roger Pressman (2016)** e **Bezerra (2014)**:

* **Dirigido por Casos de Uso (*Use-Case Driven*)**
  * **Conceito:** Os casos de uso, capturados na etapa de Engenharia de Requisitos, servem como o fio condutor de todo o projeto. Eles guiam a análise de escopo, a modelagem de arquitetura, a escrita do código e a elaboração dos planos de testes. Todo o sistema existe para entregar as funcionalidades solicitadas por esses casos de uso.

* **Centrado na Arquitetura (*Architecture-Centric*)**
  * **Conceito:** A arquitetura do sistema é desenhada e consolidada logo no início do ciclo de vida do projeto. O Processo Unificado defende que ter um mapa arquitetural claro (as camadas, componentes e interfaces de serviços) mitiga riscos técnicos catastróficos e fornece a base estável necessária para que o software cresça de forma organizada.

* **Iterativo e Incremental (*Iterative and Incremental*)**
  * **Conceito:** O projeto é quebrado em pequenos ciclos de tempo chamados iterações. Cada iteração funciona como um "mini-projeto" (contendo comunicação, modelagem, construção e testes). O resultado de cada ciclo é um **incremento**, ou seja, uma versão executável e testável do software que adiciona novas fatias de valor técnico à entrega anterior.

---

## As 4 Fases do Ciclo de Vida do Processo Unificado

Diferente dos modelos tradicionais que dividem o projeto por atividades puras (como "fase de design" ou "fase de codificação"), o Processo Unificado organiza o tempo e a governança em **quatro fases sucessivas**. 

Em cada uma dessas fases, a equipe realiza diferentes níveis de esforço nas atividades técnicas e gerenciais:

```text
Fases do RUP:  [ Concepção ] ➔ [ Elaboração ] ➔ [ Construção ] ➔ [ Transição ]
```

### 1. Fase de Concepção (ou Inicialização / *Inception*)
O objetivo principal é definir o escopo de negócio do projeto e obter a autorização formal para o seu início.
* **Foco de Esforço:** Alta concentração em Comunicação e Planejamento.
* **Atividades Técnicas:** Identificação dos principais stakeholders, elicitação macro de requisitos (mapeamento de cerca de 20% dos casos de uso críticos), avaliação de viabilidade financeira e criação do caso de negócio (*Business Case*).
* **Marco de Entrega:** O estabelecimento dos objetivos do ciclo de vida do projeto.

### 2. Fase de Elaboração (*Elaboration*)
O objetivo central é analisar o domínio do problema de forma profunda e **solidificar a linha de base da arquitetura** (*architectural baseline*).
* **Foco de Esforço:** Alta concentração em Modelagem e Gerenciamento de Riscos.
* **Atividades Técnicas:** Engenharia de requisitos detalhada (detalhar a grande maioria dos casos de uso), refinamento dos aspectos estáticos e dinâmicos, e a criação de um "esqueleto executável" da arquitetura para provar que a tecnologia escolhida funciona na prática.
* **Marco de Entrega:** A validação e estabilização da arquitetura do sistema.

### 3. Fase de Construção (*Construction*)
O objetivo é o desenvolvimento do produto propriamente dito, transformando a arquitetura em um sistema completo.
* **Foco de Esforço:** Concentração massiva em Construção (Codificação e Testes).
* **Atividades Técnicas:** Escrita de código limpo de forma iterativa, execução rigorosa de testes de unidade e integração, e a fabricação sequencial dos incrementos de software funcionais. As regras de negócio são totalmente implementadas aqui.
* **Marco de Entrega:** A capacidade operacional inicial do produto (o software está completo e pronto para testes de homologação de sistema).

### 4. Fase de Transição (*Transition*)
O objetivo é transferir o software com sucesso do ambiente de engenharia para o ambiente real de produção do usuário final.
* **Foco de Esforço:** Foco total em Implantação e Suporte.
* **Atividades Técnicas:** Execução de testes de aceitação (Alpha e Beta), correção de bugs de última hora, migração física de bancos de dados relacionais, empacotamento em releases oficiais, treinamentos operacionais com os usuários e prestação de assistência e suporte.
* **Marco de Entrega:** A liberação oficial e o encerramento do produto no mercado.
