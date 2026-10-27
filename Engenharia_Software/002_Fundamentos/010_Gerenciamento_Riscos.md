# Gerenciamento de Riscos em Engenharia de Software

O gerenciamento de riscos é uma atividade umbral fundamental para antecipar problemas, mitigar impactos negativos e aproveitar oportunidades antes que elas afetem o sucesso do projeto.

---

## Cenários de Risco: Negativo vs. Positivo

Embora a palavra "risco" costume ser associada a eventos ruins, a engenharia de software e a gestão moderna (PMBOK) dividem os riscos em duas perspectivas:

* **Cenário Negativo (Ameaças):** Eventos incertos que, se ocorrerem, causam impactos prejudiciais ao projeto, como atrasos, estouro de orçamento ou falhas críticas na arquitetura.
  * *Exemplo:* Um desenvolvedor sênior se desliga da equipe no meio de uma iteração crítica.
* **Cenário Positivo (Oportunidades):** Eventos incertos que, se acontecerem, trazem benefícios diretos e otimização ao projeto.
  * *Exemplo:* A liberação antecipada de uma biblioteca de código aberto estável que reduz pela metade o tempo de construção de um módulo complexo.

---

## Processo de Identificação de Riscos

A identificação de riscos é um esforço contínuo e colaborativo. Para mapear o que pode dar certo ou errado, a equipe utiliza técnicas como:
* **Brainstorming:** Reuniões com o time técnico e stakeholders para levantar hipóteses de problemas.
* **Checklists:** Listas baseadas em projetos anteriores ou lições aprendidas da organização.
* **Análise de Premissas:** Verificação de tudo o que foi assumido como "verdade absoluta" no planejamento (ex: assumir que o servidor do cliente suportará a carga de testes).

---

## Categorias Genéricas de Risco (Segundo Pressman, 2016)

Conforme a literatura clássica de Roger Pressman, os riscos de software podem ser sistematicamente agrupados em sete categorias genéricas essenciais para a análise do projeto. Abaixo está o detalhamento de cada uma delas com complementos práticos do ecossistema de engenharia:

* **Tamanho do Produto**
  * Riscos associados ao escopo geral do software a ser construído ou modificado.
  * *Fatores técnicos:* Volume de linhas de código estimadas, número de telas, volume de dados gerados e complexidade das integrações. Quanto maior o produto, maior o risco de desvio.

* **Impacto no Negócio**
  * Riscos associados a restrições impostas pelo mercado, pela gerência ou pelo modelo de negócios da empresa.
  * *Fatores técnicos:* Data de lançamento crítica para o mercado (*time-to-market*), viabilidade financeira do projeto, alinhamento com a estratégia da empresa e o custo de penalidades contratuais por atrasos.

* **Características do Envolvido (Cliente/Stakeholder)**
  * Riscos relacionados à maturidade, disposição e capacidade de comunicação do cliente ou dos usuários finais.
  * *Fatores técnicos:* Clientes que não sabem expressar o que precisam, falta de disponibilidade para validar incrementos, ou conflitos internos entre os tomadores de decisão sobre as regras de negócio.

* **Definição do Processo**
  * Riscos ligados ao nível de maturidade e adesão do time ao processo de software escolhido.
  * *Fatores técnicos:* Falta de clareza nas etapas de desenvolvimento, ausência de padrões de design, processos de garantia de qualidade (QA) ineficientes ou equipes que ignoram as regras de controle de configuração (versionamento).

* **Ambiente de Desenvolvimento**
  * Riscos associados às ferramentas CASE, softwares e infraestrutura de hardware disponíveis para construir o sistema.
  * *Fatores técnicos:* Lentidão ou instabilidade em pipelines de CI/CD, falta de ambientes estáveis de homologação/testes, ou ferramentas de desenvolvimento desatualizadas que geram gargalos de produtividade.

* **Tecnologia a ser Criada**
  * Riscos que derivam da complexidade técnica do sistema ou do uso de tecnologias inovadoras/desconhecidas.
  * *Fatores técnicos:* Utilizar um framework ou linguagem que a equipe nunca usou, criar sistemas com altíssima exigência de desempenho em tempo real, ou lidar com arquiteturas de hardware complexas ou inéditas.

* **Quantidade de Pessoas e Experiência**
  * Riscos associados à quantidade total de profissionais disponíveis na equipe e ao nível de conhecimento técnico e de negócio deles.
  * *Fatores técnicos:* Falta de desenvolvedores qualificados, alta rotatividade de pessoal (*turnover*), falta de experiência prévia com o domínio do problema (ex: programadores excelentes construindo um sistema contábil sem entender regras fiscais).
