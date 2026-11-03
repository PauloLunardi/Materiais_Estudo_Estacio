# Os Eventos e Cerimônias no Scrum

Dentro do framework **Scrum**, os **Eventos** (ou cerimônias) são caixas de tempo rígidas (*timeboxes*) projetadas especificamente para criar regularidade, otimizar a produtividade e eliminar a necessidade de reuniões não planejadas na Engenharia de Software. Eles servem como os pontos formais de **Inspeção e Adaptação** do processo empírico.

Todo o fluxo de desenvolvimento ágil do Scrum é estruturado através de cinco eventos essenciais descritos a seguir:

---

## Detalhamento dos 5 Eventos do Scrum

* **1. A Sprint (O Coração do Scrum)**
  * **O que é:** É o contêiner para todos os outros eventos. Um ciclo de tempo fechado, com duração fixa de **uma a quatro semanas**, onde um incremento de software utilizável e potencialmente liberável é construído.
  * **Regras de Engenharia:** Assim que uma Sprint termina, a próxima começa imediatamente. Durante a sua execução, não são feitas alterações que possam colocar a Meta da Sprint em risco, os objetivos de qualidade não são reduzidos e o escopo pode ser renegociado entre o PO e os desenvolvedores à medida que mais é aprendido sobre o código.

* **2. Reunião de Planejamento da Sprint (*Sprint Planning*)**
  * **O que é:** O evento que inicia a Sprint, onde todo o Scrum Team colabora para definir o trabalho que será realizado naquele ciclo.
  * **Dinâmica Técnica:** O PO apresenta os itens prioritários do *Product Backlog* e propõe a **Meta da Sprint**. Os desenvolvedores avaliam sua capacidade técnica e selecionam quais itens conseguem entregar, quebrando esses requisitos em tarefas de nível de código para gerar o **Sprint Backlog**.
  * **Timebox:** Máximo de 8 horas para uma Sprint de um mês (proporcionalmente menor para Sprints mais curtas).

* **3. Reunião Diária (*Daily Scrum*)**
  * **O que é:** Uma reunião rápida de alinhamento diário exclusiva para os **Developers** inspecionarem o progresso em direção à Meta da Sprint e adaptarem o plano de trabalho para as próximas 24 horas.
  * **Dinâmica Técnica:** Tradicionalmente focada em responder a três perguntas para garantir a transparência do fluxo: *O que eu fiz ontem que ajudou o time a atingir a meta? O que farei hoje? Existe algum impedimento técnico bloqueando o meu trabalho?* O foco é identificar gargalos e travar o *Scope Creep* imediatamente.
  * **Timebox:** Rígido de **15 minutos**, realizada no mesmo horário e local todos os dias para reduzir a complexidade.

* **4. Revisão da Sprint (*Sprint Review*)**
  * **O que é:** Evento realizado ao término da Sprint focado na **inspeção do produto**. O Scrum Team e os stakeholders/clientes reúnem-se para avaliar o que foi alcançado e determinar os próximos passos.
  * **Dinâmica Técnica:** Não é uma apresentação de slides. Os desenvolvedores **demonstram o incremento de software funcionando real** (em ambiente de homologação ou produção). O PO coleta o feedback dos clientes sobre as novas funcionalidades e atualiza o *Product Backlog* para refletir as novas demandas ou mudanças do mercado.
  * **Timebox:** Máximo de 4 horas para uma Sprint de um mês.

* **5. Retrospectiva da Sprint (*Sprint Retrospective*)**
  * **O que é:** O evento final da Sprint, focado na **inspeção e adaptação do processo de trabalho e das pessoas**. É o momento em que o Scrum Team olha para dentro de si para planejar melhorias contínuas.
  * **Dinâmica Técnica:** O time discute o que funcionou bem e o que deu errado na iteração em relação às ferramentas, relacionamentos, processos e qualidade do código. Identificam-se as causas raiz das falhas (ex: quebras constantes no pipeline de CI/CD ou estimativas erradas) e define-se um plano de ação imediato para melhorar a eficiência na Sprint seguinte.
  * **Timebox:** Máximo de 3 horas para uma Sprint de um mês.
