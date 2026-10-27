# Ciclo de Vida do Projeto vs. Grupos de Processos

É muito comum confundir o Ciclo de Vida do Projeto com os Grupos de Processos de Gerenciamento. No entanto, embora andem juntos e operem de forma integrada na Engenharia de Software, eles possuem conceitos, escopos e finalidades completamente distintos.

---

## Diferença Conceitual

* **Ciclo de Vida do Projeto:** Refere-se às **fases técnicas** que o projeto atravessa desde o seu início até a sua conclusão (ex: Levantamento de Requisitos, Análise, Projeto, Implementação, Testes e Implantação). Ele dita *o que deve ser feito* técnica e operacionalmente para construir o produto de software.
* **Grupos de Processos de Gerenciamento:** Referem-se às **atividades de gestão** que organizam, gerenciam e controlam o trabalho técnico dessas fases. Eles ditam *como o projeto será governado*, independentemente da metodologia de engenharia adotada (seja ela ágil, híbrida ou preditiva).

---

## Os Grupos de Processos de Gerenciamento de Projetos

Conforme estabelecido pelos padrões globais de gerenciamento de projetos do PMI, as práticas de gestão são organizadas em **cinco grupos de processos de gerenciamento**. Eles interagem de maneira contínua e sobreposta ao longo de todo o ciclo de vida do projeto:

* **Grupo de Processos de Iniciação**
  * Finalidade: Define o projeto ou uma nova fase do ciclo de vida, obtendo formalmente a autorização para começar.
  * Atividades principais: Identificação dos stakeholders primários, alinhamento das expectativas iniciais e emissão do Termo de Abertura do Projeto (TAP).

* **Grupo de Processos de Planejamento**
  * Finalidade: Estabelece o escopo total do esforço, define os objetivos e desenvolve a linha de ação necessária para alcançá-los.
  * Atividades principais: Criação do cronograma, estimativa de custos, definição da Estrutura Analítica do Projeto (EAP), plano de gerenciamento de riscos e planejamento de recursos humanos.

* **Grupo de Processos de Execução**
  * Finalidade: Realiza o trabalho técnico definido no plano de gerenciamento de projetos para satisfazer os requisitos e especificações.
  * Atividades principais: Liderar e gerenciar o trabalho da equipe de desenvolvimento, coordenar pessoas e recursos, e gerenciar o conhecimento do projeto.

* **Grupo de Processos de Monitoramento e Controle**
  * Finalidade: Acompanha, analisa e regula o progresso e o desempenho do projeto. Identifica áreas nas quais alterações no plano são necessárias e inicia as mudanças correspondentes.
  * Atividades principais: Controle integrado de mudanças de escopo, medição do progresso de entregas técnicas (como sprints ou pacotes de trabalho) e monitoramento de riscos em tempo real.

* **Grupo de Processos de Encerramento**
  * Finalidade: Conclui formalmente todas as atividades de todos os grupos de processos de gerenciamento para fechar oficialmente o projeto ou uma fase específica.
  * Atividades principais: Formalização do aceite do software pelo cliente, encerramento de contratos com fornecedores, arquivamento de lições aprendidas e liberação da equipe técnica para novos projetos.

---

## Dinâmica de Interação e Sobreposição

Diferente do ciclo de vida linear da engenharia, os Grupos de Processos de Gerenciamento **não acontecem em uma sequência rígida de uma única vez**. Eles se sobrepõem e se repetem a cada etapa ou fase técnica do ciclo de vida do projeto:

* **Ciclos de Feedback:** Durante o grupo de *Execução* (por exemplo, escrevendo código), o grupo de *Monitoramento e Controle* pode detectar um atraso. Isso força o projeto a retornar temporariamente ao grupo de *Planejamento* para ajustar o cronograma antes de retomar a execução.
* **Abordagem por Fases:** Em projetos complexos, cada fase técnica (como a transição da etapa de Projeto para a etapa de Implementação) pode passar por seus próprios processos de *Iniciação* (para aprovar o início da codificação) e *Encerramento* (para validar a entrega dos diagramas arquiteturais antes de liberar a equipe).
