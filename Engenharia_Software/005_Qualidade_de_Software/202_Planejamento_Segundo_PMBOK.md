# Planejar o Gerenciamento da Qualidade segundo o Guia PMBOK

O processo de **Planejar o Gerenciamento da Qualidade** estabelece os padrões e critérios técnicos que o projeto de software deve atingir. Ele define formalmente como o time comprovará a aderência a esses padrões, priorizando a **prevenção de falhas** em detrimento de uma simples inspeção de código no encerramento da entrega.

```
+-------------------+       +------------------------+       +-------------------------+

|     ENTRADAS      |       |  TÉCNICAS E FERRAMENTAS|       |         SAÍDAS          |
|                   |       |                        |       |                         |
| O que é coletado  | ----> |  Como as informações   | ----> | Os planos e métricas    |
| de base para      |       |  são processadas e     |       | que guiarão o time de   |
| o planejamento    |       |  decisões são tomadas  |       | engenharia de software  |
+-------------------+       +------------------------+       +-------------------------+
```

---

## Detalhamento das Etapas do Processo

Abaixo estão explicados individualmente cada um dos itens listados na matriz oficial de planejamento da qualidade:

### 1. Entradas
Representam as informações históricas, diretrizes corporativas e restrições iniciais de escopo coletadas para embasar o planejamento:

* **Termo de abertura do projeto:** Documento de nível executivo que autoriza o início do projeto, contendo as metas de alto nível e requisitos de sucesso estipulados pelos patrocinadores.
* **Plano de gerenciamento do projeto:** O plano macro da iniciativa. Contém linhas de base fundamentais (como a linha de base do escopo, cronograma e custos) que ditam os limites financeiros e de tempo que impactam diretamente o esforço de qualidade.
* **Documentos do projeto:** Históricos funcionais que ajudam a detalhar o plano de QA, tais como o registro de partes interessadas (stakeholders), matriz de rastreabilidade e o registro de riscos do sistema.
* **Fatores ambientais da empresa:** Elementos externos ao projeto que limitam ou influenciam a operação (ex: normas regulamentadoras do setor financeiro ou de saúde, ferramentas de tecnologia disponíveis e cultura da organização).
* **Ativos de processos organizacionais:** O acervo de conhecimento interno da empresa (ex: templates e modelos de planos de qualidade anteriores, diretrizes de governança de código e repositório de lições aprendidas).

### 2. Técnicas e Ferramentas
São as metodologias e práticas analíticas utilizadas pelo gerente de projeto e equipe de SQA para formatar as estratégias de controle:

* **Opinião especializada:** Consultas a especialistas, arquitetos de software ou profissionais seniores de QA com conhecimento técnico focado em estratégias avançadas de testes.
* **Coleta de dados:** Técnicas para reunir informações relevantes, destacando-se o *benchmarking* (comparação de práticas com projetos do mercado) e o *brainstorming* (geração de ideias com o time).
* **Análise de dados:** Estudos analíticos como a Análise de Custo-Benefício (garantindo que investir em testes automatizados seja mais barato que consertar bugs em produção) e o Custo da Qualidade (COQ).
* **Tomada de decisões:** Metodologias estruturadas de escolha para definir quais ferramentas, frameworks e estratégias de automação serão de fato priorizadas no projeto.
* **Representação de dados:** Fluxogramas, diagramas lógicos ou matrizes que ajudam a mapear e expor visualmente onde os testes e checkpoints de qualidade ocorrerão no ciclo de vida do desenvolvimento.
* **Planejamento de testes e inspeções:** Definição estruturada de como o código será inspecionado, especificando as baterias de testes manuais e automatizados necessárias para homologar cada entrega.
* **Reuniões:** Encontros focados e rituais de alinhamento técnico com o time de engenharia e clientes para fechar as diretrizes do plano de qualidade.

### 3. Saídas
Os artefatos formais construídos e assinados que direcionarão a execução técnica dali em diante:

* **Plano de gerenciamento da qualidade:** Documento oficial que formaliza como os processos e o produto de software serão gerenciados e validados ao longo do ciclo de vida.
* **Métricas da qualidade:** Parâmetros operacionais explícitos que medem se o código está aceitável ou não (ex: cobertura de testes unitários mínima de 80%, tempo de resposta menor que 200ms por endpoint).
* **Atualizações do plano de gerenciamento do projeto:** Revisões nas linhas de base de custo ou cronograma necessárias após estimar o esforço técnico exigido pelas atividades de teste.
* **Atualizações de documentos do projeto:** Revisões nos arquivos de apoio criadas após a consolidação do plano (ex: novos riscos técnicos catalogados na planilha de riscos do projeto).
```
