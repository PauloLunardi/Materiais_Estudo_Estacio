# O Framework Scrum: Os 3 Pilares Empíricos

O **Scrum** é o framework ágil mais utilizado no mundo para o gerenciamento e desenvolvimento de produtos complexos. Diferente dos modelos tradicionais baseados em previsibilidade de longo prazo, o Scrum fundamenta-se no **controle de processos empírico** (ou empirismo). Isso significa que as decisões de projeto são tomadas com base em experiências reais e dados observados no dia a dia, e não em suposições.

Como destaca a literatura clássica e o próprio Guia oficial do Scrum, o empirismo é sustentado por **três pilares fundamentais**: **Transparência, Inspeção e Adaptação**.

---

## Os 3 Pilares do Scrum

* **1. Transparência**
  * **O que é:** Exige que todos os aspectos do processo e do produto sejam visíveis e compreendidos de forma idêntica tanto por quem realiza o trabalho quanto por quem o recebe.
  * **Na prática da Engenharia:** Não pode haver "trabalho oculto". O time utiliza ferramentas como quadros visuais (**Kanban** no Jira/Azure DevOps) e artefatos claros como o *Product Backlog* e o *Sprint Backlog*. Além disso, a equipe estabelece uma **Definição de Pronto (*Definition of Done - DoD*)** comum: todos precisam concordar sobre quais testes de qualidade e revisões de código o software deve passar para ser considerado realmente "concluído".

* **2. Inspeção**
  * **O que é:** O ato de avaliar e checar os artefatos do Scrum e o progresso em direção aos objetivos de forma frequente e diligente, visando detectar variações indesejadas ou problemas lógicos precocemente.
  * **Na prática da Engenharia:** O Scrum cria pontos específicos na linha do tempo para que a inspeção ocorra de forma natural, sem atrapalhar a produtividade. Os desenvolvedores inspecionam o código diariamente nas reuniões diárias (*Daily Scrum*), o cliente inspeciona o incremento de software funcionando ao final do ciclo na Revisão da Sprint (*Sprint Review*), e o time inspeciona o próprio processo de trabalho na Retrospectiva (*Sprint Retrospective*).

* **3. Adaptação**
  * **O que é:** Se durante a fase de inspeção for detectado que um desvio de prazo ocorreu, que a arquitetura apresentou falhas ou que a regra de negócio do cliente mudou, o processo ou o produto deve ser ajustado o mais rápido possível para minimizar novos problemas.
  * **Na prática da Engenharia:** É a resposta direta à mudança do mercado. Se uma funcionalidade entregue na Sprint não atende mais às necessidades do negócio, o Product Owner altera a prioridade do *Product Backlog*. Se a esteira de testes automatizados unitários quebrar, o time de desenvolvimento adapta sua rotina na hora para corrigir a falha técnica antes de escrever novos códigos.

---

## A Interdependência dos Pilares

Os três pilares formam um ciclo contínuo e dependem de forma absoluta uns dos outros. Na Engenharia de Software:
* A **Inspeção** é impossível sem a **Transparência** (se o time esconde os bugs ou finge que o cronograma está em dia, não há o que inspecionar de forma real).
* A **Adaptação** torna-se inútil e sem rumo se não houver uma **Inspeção** precisa e honesta das falhas do sistema.
