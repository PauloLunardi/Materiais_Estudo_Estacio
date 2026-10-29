# O Processo de Desenvolvimento de Software: As 5 Atividades Genéricas

Independentemente do modelo de processo adotado por uma equipe de engenharia — seja ele um modelo tradicional prescritivo (como o Cascata) ou um framework ágil incremental (como o Scrum) —, o fluxo de engenharia é sustentado por **cinco atividades metodológicas genéricas**. 

Como aponta a literatura clássica de **Roger Pressman (2016)**, essas atividades representam o ciclo de ações essenciais que transformam uma necessidade de negócio abstrata em um sistema de software funcional e homologado em ambiente de produção.

---

## Detalhando as 5 Atividades Fundamentais

* **1. Comunicação**
  * **O que é:** O ponto de partida de qualquer projeto. Consiste na colaboração intensa e contínua entre a equipe técnica de engenharia e as partes interessadas (*stakeholders*).
  * **Foco Técnico:** Execução das etapas de engenharia de requisitos (concepção, levantamento e elicitação), reuniões de entendimento de dores do negócio e alinhamento do escopo macro do sistema. O objetivo principal é compreender perfeitamente os objetivos do cliente antes de desenhar soluções.

* **2. Planejamento**
  * **O que é:** A criação do mapa de navegação técnico e gerencial do projeto. Define como a jornada de desenvolvimento será executada ao longo do tempo.
  * **Foco Técnico:** Estimativa de esforço de desenvolvimento (horas/homem), cálculo de orçamento, definição de cronogramas, sequenciamento lógico de tarefas por meio de dependências, montagem da Estrutura Analítica do Projeto (EAP/WBS) e mapeamento rigoroso do registro de riscos para blindar as metas do software.

* **3. Modelagem**
  * **O que é:** A criação de representações, esboços e maquetes de engenharia que permitem entender a visão geral do sistema antes que o código-fonte seja escrito.
  * **Foco Técnico:** Divide-se no refinamento dos aspectos estáticos/estruturais (modelagem de classes, diagramas de arquitetura lógicos baseados em Bezerra, 2014) e nos aspectos dinâmicos/comportamentais (diagramas de sequência, fluxos de dados). Inclui também a criação de protótipos de tela (UI/UX) para validação visual imediata com o usuário.

* **4. Construção**
  * **O que é:** A combinação direta entre a geração física de valor (programação) e o controle de qualidade inicial do produto gerado.
  * **Foco Técnico:** Tradução dos modelos lógicos criados na etapa anterior em linhas de código executáveis e limpas seguindo padrões de codificação (*Clean Code*). Inclui a execução imediata de **Testes de Unidade** e **Testes de Integração** pelos desenvolvedores nas esteiras de automação técnico para expor erros de forma precoce.

* **5. Entrega (ou Implantação)**
  * **O que é:** A disponibilização operacional do software para o cliente ou para os usuários finais, seguida pela avaliação prática do produto entregue.
  * **Foco Técnico:** Empacotamento do software (imagens Docker, instaladores), distribuição física ou em nuvem através de pipelines de CD (Entrega Contínua) e execução de **Testes de Sistema** (Segurança, Carga, Recuperação). Envolve também o processo de homologação por **Testes de Aceite (Alpha e Beta)**, coleta de feedbacks reais, treinamento operacional de usuários e fornecimento de assistência técnica (*Help Desk*).
