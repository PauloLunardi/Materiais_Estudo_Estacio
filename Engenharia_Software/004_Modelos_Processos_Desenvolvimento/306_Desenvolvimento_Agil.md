# A Dinâmica de Execução e Eventos da Sprint no Scrum

No **Scrum**, a **Sprint** é o núcleo onde o desenvolvimento de software ganha ritmo, previsibilidade e cadência. O fluxo operacional da Sprint é estruturado por uma sequência lógica de eventos com *timeboxes* (caixas de tempo) rígidos, projetados para garantir os ciclos de inspeção e adaptação das práticas de engenharia de software.

---

## O Ciclo de Vida de uma Sprint

Abaixo está o detalhamento cronológico de como uma Sprint nasce, se desenvolve, é avaliada e serve de base para a evolução contínua da equipe:

### 1. Reunião de Planejamento da Sprint (*Sprint Planning*)
É o evento que marca o início oficial de uma nova Sprint. Todo o *Scrum Team* (Product Owner, Scrum Master e Desenvolvedores) trabalha de forma colaborativa para definir o trabalho técnico que será realizado.
* **O que acontece:** O Product Owner (PO) apresenta os itens priorizados do topo do *Product Backlog* e propõe a **Meta da Sprint** (o objetivo de negócio daquele ciclo). Os desenvolvedores analisam sua capacidade técnica, selecionam quais requisitos conseguem entregar e realizam a quebra técnica desses requisitos em tarefas operacionais de nível de código, gerando o **Sprint Backlog**.
* **Timebox:** Máximo de 8 horas para uma Sprint de um mês (proporcionalmente menor para ciclos mais curtos).

### 2. Desenvolvimento da Sprint (*Sprint Execution*)
É o período de construção propriamente dito, onde os desenvolvedores trabalham de forma auto-organizada para transformar as tarefas técnicas do *Sprint Backlog* em um incremento de software utilizável e em conformidade com a *Definição de Pronto* (*DoD*).
* **O que acontece:** É a fase de codificação intensa, modelagem arquitetural localizada, modelagem de banco de dados relacional e automação de testes (unidade e integração). 
* **A Reunião Diária (*Daily Scrum*):** A cada 24 horas, os desenvolvedores realizam uma reunião em pé de **15 minutos** para inspecionar o progresso técnico em relação à Meta da Sprint e sincronizar o plano de trabalho para o dia, identificando e removendo impedimentos precocemente com o suporte do Scrum Master.

### 3. Reunião de Revisão da Sprint (*Sprint Review*)
Ocorre ao final da Sprint e seu foco é estritamente na **inspeção e adaptação do produto** de software que foi construído. O Scrum Team se reúne com os clientes, usuários reais e stakeholders do negócio.
* **O que acontece:** Não é uma mera apresentação de slides. Os desenvolvedores **demonstram o incremento de software funcionando de verdade** (geralmente em ambiente de homologação). O Product Owner avalia as fatias de código entregues, o cliente fornece feedbacks sobre a usabilidade e eficácia das funções, e o grupo analisa o mercado para atualizar e reordenar o *Product Backlog* para as próximas Sprints.
* **Timebox:** Máximo de 4 horas para uma Sprint de um mês.

### 4. Reunião de Retrospectiva da Sprint (*Sprint Retrospective*)
É o evento final que encerra formalmente a Sprint, ocorrendo logo após a Revisão. O foco aqui muda completamente do produto para as **pessoas, relacionamentos, processos e ferramentas**.
* **O que acontece:** O Scrum Team realiza uma autoanálise honesta e transparente sobre como foi o ciclo de trabalho. Eles discutem o que funcionou bem e o que deu errado (ex: falhas no pipeline de CI/CD, estimativas de prazos erradas, conflitos internos de design). O objetivo é identificar as causas-raiz dos problemas e definir pelo menos uma melhoria técnica ou operacional para ser implementada imediatamente na próxima Sprint.
* **Timebox:** Máximo de 3 horas para uma Sprint de um mês.
