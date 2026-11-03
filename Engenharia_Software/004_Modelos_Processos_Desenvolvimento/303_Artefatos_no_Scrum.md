# Os Artefatos no Scrum

Dentro do framework **Scrum**, os **Artefatos** são projetados especificamente para garantir a **transparência** e pontos de **inspeção** contínuos, fornecendo informações essenciais que a equipe de engenharia e gerenciamento precisa para tomar decisões com base no empirismo. 

Os dois principais artefatos focados no gerenciamento de escopo, requisitos e tarefas do software são o **Product Backlog** e o **Sprint Backlog**.

---

## 1. Product Backlog (O Backlog do Produto)

O **Product Backlog** é uma lista ordenada, dinâmica e viva de tudo o que pode ser necessário no produto de software. Ele substitui de forma ágil o tradicional Documento de Especificação de Requisitos (SRS) exaustivo.

* **Responsável Único:** O **Product Owner (PO)**. Ele é o único com autonomia para adicionar itens, remover ou alterar a ordem de prioridade.
* **Características Técnicas:** 
  * **Evolutivo:** Nunca está completo. Ele cresce e se transforma à medida que o mercado muda, o software evolui (fase de manutenção) e novos feedbacks de usuários reais são coletados.
  * **Granularidade Variável (DEEP):** Os itens localizados no topo (próximos de serem desenvolvidos) são pequenos, detalhados na forma de *Histórias de Usuário*, possuem critérios de aceitação claros e estimativas precisas. Os itens do fundo são macro, genéricos e conhecidos como *Épicos*.
* **Compromisso Associado:** **Meta do Produto (*Product Goal*)**. Cada item inserido ou priorizado no Product Backlog deve servir como um tijolo para alcançar o objetivo de longo prazo do sistema.

---

## 2. Sprint Backlog (O Backlog da Sprint)

O **Sprint Backlog** é o plano de ação detalhado criado para a Sprint atual. Ele representa uma fotografia ou subconjunto de itens extraídos do Product Backlog combinados com o plano técnico para entregá-los.

* **Responsável Único:** Os **Developers (Time de Desenvolvimento)**. O Product Owner ou o Scrum Master não interferem na gerência deste artefato.
* **Características Técnicas:**
  * **Imutabilidade de Meta:** Uma vez definido no início da Sprint (durante a reunião de Planejamento), o escopo de trabalho contido no Sprint Backlog não deve sofrer alterações que ameacem o objetivo final da Sprint.
  * **Altamente Visual:** É mapeado no dia a dia por meio de quadros de tarefas (como quadros **Kanban** ou Scrum Boards) divididos em colunas de progresso técnico (ex: *A Fazer, Em Desenvolvimento, Em Code Review, Em Testes, Pronto*).
  * **Composição Interna:** Ele une os itens de valor de negócio selecionados do Product Backlog com a quebra técnica das tarefas em nível de código (ex: "Criar tabela de alocação no SQL Server", "Implementar método POST da API", "Escrever testes de unidade").
* **Compromisso Associado:** **Meta da Sprint (*Sprint Goal*)**. O objetivo único e claro que une o esforço técnico de todo o time durante aquele ciclo curto de tempo.

---

## Tabela Comparativa: Product Backlog vs. Sprint Backlog

Para consolidar o entendimento conceitual para exames acadêmicos e repositórios de documentação técnica:

| Característica | Product Backlog | Sprint Backlog |
| :--- | :--- | :--- |
| **Escopo** | Visão macro e de longo prazo de todo o ecossistema do software. | Visão micro e focada no ciclo atual (1 a 4 semanas). |
| **Dono/Responsável** | Product Owner (PO). | Developers (Time Técnico). |
| **Volatilidade** | Altamente volátil e adaptável a qualquer momento do mercado. | Rígido. Não sofre alterações que corrompam a Meta da Sprint. |
| **Nível de Detalhe** | Variável (detalhado no topo, genérico no fundo). | Altamente detalhado em formato de tarefas operacionais de código. |
| **Compromisso** | Meta do Produto (*Product Goal*). | Meta da Sprint (*Sprint Goal*). |
