# Gerenciamento da Qualidade de Software(PMBOK)

O Guia PMBOK (Project Management Body of Knowledge) organiza o gerenciamento da qualidade do projeto em três processos fundamentais. 
Cada um deles pertence a um **Grupo de Processos** específico do ciclo de vida do projeto. 

*Nota importante:* Para garantir o alinhamento com a literatura oficial do PMBOK, os processos são mapeados da seguinte forma nas três grandes fases:

```
[ PLANEJAMENTO ]            --> Planejar o Gerenciamento da Qualidade
       |
       v
[ EXECUÇÃO ]                --> Gerenciar a Qualidade (Garantia da Qualidade)
       |
       v
[ MONITORAMENTO E CONTROLE ] --> Controlar a Qualidade (Controle de Qualidade)
```

---

## 1. Planejar o Gerenciamento da Qualidade (Fase de Planejamento)
Este é o ponto de partida. O objetivo desta etapa é identificar os requisitos e padrões de qualidade do software para o projeto e documentar como a equipe demonstrará a conformidade com eles.

* **Foco Principal:** Prevenção de defeitos em vez de inspeção tardia. É aqui que se decide como a qualidade será medida.
* **Principais Entradas:** Termo de Abertura do Projeto, Plano de Gerenciamento do Escopo e Requisitos do Cliente.
* **Ferramentas e Técnicas:**
  * Coleta de dados (Benchmarking, Custo da Qualidade - COQ).
  * Análise de decisões e representação de dados (Matrizes de fluxo).
  * Planejamento de testes e inspeções.
* **Principal Entrega:** **Plano de Gerenciamento da Qualidade**, contendo as métricas de qualidade específicas do software (ex: limite aceitável de tempo de resposta da API ou cobertura mínima de testes de 85%).

---

## 2. Gerenciar a Qualidade (Fase de Execução)
Historicamente conhecido como *Garantia da Qualidade (QA)*, este processo traduz o plano de gerenciamento da qualidade em atividades executáveis. Ele garante que os processos definidos no planejamento estejam sendo efetivamente seguidos pela equipe de desenvolvimento.

* **Foco Principal:** Aprimoramento e auditoria dos processos de trabalho. Se o processo for bom, o produto final naturalmente terá mais qualidade.
* **Principais Entradas:** Plano de Gerenciamento da Qualidade e Métricas de Qualidade.
* **Ferramentas e Técnicas:**
  * **Auditorias de Qualidade:** Verificações estruturadas e independentes para determinar se as atividades do projeto estão em conformidade com as políticas da empresa.
  * **Análise de Processos:** Identificação de melhorias necessárias no fluxo de trabalho e eliminação de atividades que não agregam valor.
  * Solução de problemas e técnicas de representação de dados (como Diagramas de Causa e Efeito/Ishikawa).
* **Principal Entrega:** Relatórios de qualidade, documentos de teste atualizados e solicitações de mudança nos processos internos da equipe.

---

## 3. Controlar a Qualidade (Fase de Monitoramento e Controle)
Este processo foca no **produto entregável**. É a atividade de monitorar e registrar os resultados da execução das atividades de qualidade para avaliar o desempenho e garantir que as entregas do software estejam completas, corretas e atendam às expectativas do cliente.

* **Foco Principal:** Identificar e corrigir defeitos nos artefatos gerados (código, telas, APIs, documentação) antes da homologação final.
* **Principais Entradas:** Entregas do projeto (o incremento do software rodando) e dados de desempenho do trabalho.
* **Ferramentas e Técnicas:**
  * Inspeções físicas e revisões de código.
  * Execução prática de Testes Automatizados e Manuais.
  * Listas de verificação (*Checklists*) de conformidade das histórias de usuário.
* **Principal Entrega:** **Entregas Verificadas** (software testado e pronto para homologação), medições de controle de qualidade e atualizações no plano de testes.

---

## Resumo das Diferenças (Gerenciar vs. Controlar)

Uma distinção clássica cobrada em gerenciamento de projetos é a diferença entre a Execução e o Monitoramento da qualidade:

* **Gerenciar a Qualidade (Execução):** Foco nas **pessoas e processos**. Avalia se o time está seguindo os padrões definidos (Ex: "A equipe realizou as revisões de código obrigatórias?").
* **Controlar a Qualidade (Monitoramento):** Foco no **produto final**. Avalia se o código em si cumpre os requisitos (Ex: "O software passou nos testes automatizados e está livre de bugs críticos?").
```
