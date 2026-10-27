# Processo de Software: Framework Genérico e Atividades de Apoio

Um **Processo de Software** pode ser definido como uma estrutura de trabalho (*framework*) voltada para o desenvolvimento de um produto de alta qualidade. Conforme estabelecido pelas principais normas internacionais de engenharia de software (como a **ISO/IEC/IEEE 12207**), um processo eficaz organiza o trabalho de engenharia de forma previsível, repetível e controlável.

---

## O Framework Genérico de Processo (Atividades Fundamentais)

Independentemente do tamanho do projeto ou da abordagem adotada (seja ela ágil como o Scrum ou tradicional como o Processo Unificado), Roger Pressman aponta que todo processo de software é sustentado por **cinco atividades metodológicas genéricas**:

* **Comunicação:** Esta fase inicial envolve uma colaboração intensa com as partes interessadas (*stakeholders*). O objetivo principal é entender os requisitos do negócio, definir o escopo inicial e coletar os requisitos do sistema.
* **Planejamento:** Cria-se o mapa de navegação do projeto. Esta atividade define os riscos potenciais, os recursos necessários (humanos e computacionais), os custos estimados, o cronograma de entregas e os marcos de acompanhamento (*milestones*).
* **Modelagem:** Envolve a criação de representações de engenharia para que se possa entender a visão geral do sistema antes da codificação. Inclui a análise dos requisitos detalhados e o design da arquitetura do software (diagramas UML, esquemas de bancos de dados, etc.).
* **Construção:** É a combinação direta entre a **geração de código** (programação) e a execução de **testes** de software (testes unitários e de integração) para descobrir e corrigir erros antes da entrega.
* **Implantação:** O software é entregue ao cliente ou disponibilizado em ambiente de produção. Esta etapa inclui o recebimento de feedback dos usuários com base na avaliação do produto entregue.

---

## Atividades Umbralares ou de Apoio (*Umbrella Activities*)

As atividades metodológicas genéricas descrevem o fluxo sequencial ou incremental de desenvolvimento. No entanto, para garantir que o projeto não saia dos trilhos, existem as **Atividades de Apoio** (também conhecidas como *Umbrella Activities* ou Atividades Umbralares).

Como manda a norma de engenharia, estas atividades **ocorrem de forma contínua durante todo o ciclo de vida do projeto**, fornecendo governança e controle de qualidade:

* **Gerenciamento de Projeto de Software:** Monitoramento contínuo do progresso em relação ao plano estabelecido, aplicando ações corretivas sempre que o projeto desviar do escopo, prazo ou orçamento.
* **Gerenciamento de Configuração de Software (GCS):** Mecanismos para controlar as mudanças nos artefatos do projeto. Garante o versionamento correto do código, da documentação e dos releases.
* **Garantia de Qualidade de Software (SQA):** Execução de auditorias, revisões técnicas formais e inspeções de processos para assegurar que a equipe está seguindo os padrões organizacionais estabelecidos.
* **Gerenciamento de Riscos:** Identificação contínua, análise de impacto e definição de planos de mitigação para eventos que possam ameaçar o sucesso do projeto.
* **Medição e Métricas de Software:** Coleta e análise de dados sobre o produto e o processo (ex: linhas de código, densidade de defeitos, esforço gasto) para orientar a tomada de decisões baseada em evidências.
* **Gerenciamento de Reuso:** Definição de critérios para a criação e utilização de componentes reutilizáveis de software, aumentando a eficiência e a padronização.
* **Preparação e Acompanhamento de Produtos de Trabalho:** Atividades voltadas à criação, revisão técnica e aprovação de artefatos (como manuais de usuário, especificações de requisitos e planos de teste).

---

## O que mandam as Normas Internacionais (ISO/IEC/IEEE 12207)

A norma de referência mundial para os processos de ciclo de vida do software é a **ISO/IEC/IEEE 12207**. Ela estabelece uma arquitetura comum para os processos com uma terminologia bem definida, dividindo o ciclo em três grandes grupos de processos interdependentes:

* **Processos Técnicos:** Equivalem às atividades genéricas (Elicitação de Requisitos, Análise de Arquitetura, Implementação, Integração, Verificação, Validação e Transição).
* **Processos de Apoio (Suporte):** Correspondem diretamente às atividades umbralares. A norma dita que o gerenciamento de configuração, a garantia de qualidade, a verificação externa e as revisões conjuntas devem ser tratadas de forma independente das tarefas de escrita de código para assegurar conformidade mútua.
* **Processos de Gerenciamento e Organizacionais:** Fornecem a infraestrutura, recursos e controle de portfólio necessários para que os projetos existam e operem sob um padrão de melhoria contínua.
