# Engenharia de Requisitos

A **Engenharia de Requisitos** é uma das fases mais críticas e fundamentais do processo de engenharia de software. Como destaca **Sommerville (2007)**, os requisitos de um sistema de computador descrevem o que o sistema deve fazer e as restrições sobre sua operação e implementação. Falhas cometidas nesta etapa propagam-se por todo o ciclo de desenvolvimento, gerando retrabalho custoso e estouros de orçamento.

---

##  Fluxo Conceitual e Estrutura das Atividades

Para representar o relacionamento e a dependência lógica entre as primeiras etapas da engenharia de requisitos sem causar erros de renderização no Markdown, utilizamos um organograma baseado em listas estruturadas aninhadas:

* **Concepção (Definição Inicial do Negócio)**
  * Serve de base de entrada e contexto para ➔ **Levantamento (Elicitação Prática)**
    * Fornece os dados brutos e necessidades descobertas para ➔ **Elaboração (Modelagem e Detalhamento)**
      * Alimenta as etapas subsequentes de Negociação, Especificação, Validação e Gestão.

---

##  As 7 Atividades da Engenharia de Requisitos

Conforme os padrões da engenharia de software e a literatura de referência, o processo engloba sete atividades principais e interdependentes:

### 1. Concepção
É a fase de nascimento da ideia do software no contexto do negócio.
* **O que faz:** Estabelece uma compreensão inicial do problema a ser resolvido, identifica as partes interessadas primárias (*stakeholders*) e avalia a viabilidade básica da solução proposta. Busca responder se o software faz sentido estratégico e econômico para a organização.

### 2. Levantamento (ou Elicitação)
Trata-se do trabalho prático de descoberta e extração das necessidades dos usuários.
* **O que faz:** O time técnico interage diretamente com clientes e usuários utilizando técnicas como entrevistas, questionários, observação de campo, workshops e *brainstorming*. O foco aqui é descobrir o que os usuários realizam em seu dia a dia e o que eles esperam que o software faça (gerando os requisitos funcionais, não funcionais e de domínio).

### 3. Elaboração
É o momento em que as informações brutas coletadas no levantamento são estruturadas de forma técnica.
* **O que faz:** Foca na modelagem e no refinamento técnico dos requisitos. Nesta atividade, os requisitos são detalhados e representados por meio de modelos formais, como diagramas de casos de uso da UML, diagramas de classes e protótipos de tela. A elaboração ajuda a dar clareza técnica ao escopo do software antes do desenvolvimento.

### 4. Negociação
É comum que diferentes usuários peçam recursos conflitantes ou que o orçamento não seja suficiente para construir tudo o que foi solicitado.
* **O que faz:** É um processo de discussão e conciliação onde os requisitos são priorizados de forma realista. Engenheiros de software e clientes negociam para definir o que entrará no escopo da primeira entrega, resolvendo conflitos de interesses e ajustando as expectativas técnicas aos prazos e custos disponíveis.

### 5. Especificação
Consiste na formalização escrita de tudo o que foi acordado nas etapas anteriores.
* **O que faz:** Transforma as notas de levantamento e os modelos de elaboração em um documento oficial legível. Esse artefato pode ser um Documento de Especificação de Requisitos de Software (SRS) formal ou uma coleção bem estruturada de Histórias de Usuário (*User Stories*). Serve de guia tanto para o cliente (saber o que vai receber) quanto para os desenvolvedores e QAs (saber o que construir e testar).

### 6. Validação
É a etapa de checagem e controle de qualidade dos requisitos coletados.
* **O que faz:** Examina o documento de especificação para garantir que todos os requisitos estejam claros, consistentes (sem contradições internas), completos e realistas. O objetivo principal da validação é assegurar que o engenheiro de software compreendeu exatamente o que o cliente quis dizer, evitando o desenvolvimento de funcionalidades erradas.

### 7. Gestão (ou Gerenciamento de Requisitos)
Os requisitos de um software dificilmente permanecem estáticos; eles mudam à medida que o negócio evolui.
* **O que faz:** Trata-se de um conjunto de atividades umbralares de apoio que ocorrem durante todo o ciclo de vida do software para controlar as mudanças nos requisitos. Envolve estabelecer o rastreamento de quais códigos e testes dependem de cada requisito, analisar o impacto de novos pedidos de alteração e garantir a governança sobre as versões do escopo do software.


##  Técnicas mais Utilizadas para o Levantamento de Requisitos

A etapa de **Levantamento (ou Elicitação)** exige habilidades de comunicação e investigação. Como os usuários nem sempre conseguem expressar claramente suas necessidades técnicas, o engenheiro de software utiliza um conjunto de técnicas consolidadas pela literatura (como **Sommerville, 2007** e **Pressman, 2016**) para extrair essas informações de forma estruturada:

* **Entrevistas**
  * Consiste em reuniões diretas (estruturadas ou informais) entre o engenheiro de requisitos e as partes interessadas.
  * *Aplicação:* Excelente para obter uma compreensão profunda do ponto de vista de um usuário específico, entender suas dores diárias e coletar insights detalhados sobre as regras de negócio.

* **Questionários**
  * Aplicação de formulários com perguntas fechadas ou abertas enviados para um grande número de pessoas.
  * *Aplicação:* Ideal quando o sistema possui centenas de usuários espalhados geograficamente (como um sistema de RH corporativo) e a equipe precisa coletar dados estatísticos ou preferências gerais rapidamente antes de detalhar o escopo.

* **Workshops e JAD (Joint Application Design)**
  * Sessões de trabalho intensivas e colaborativas que reúnem, na mesma sala, os desenvolvedores, designers, gerentes de projeto e os principais clientes/usuários.
  * *Aplicação:* Altamente eficiente para acelerar o levantamento e resolver conflitos de requisitos em tempo real. O grupo discute, desenha fluxos e entra em consenso sobre o escopo do software de forma conjunta.

* **Observação de Campo (ou Etnografia)**
  * O engenheiro de software acompanha e observa os usuários realizando suas tarefas diárias no ambiente real de trabalho, sem interferir na rotina deles.
  * *Aplicação:* Fundamental para descobrir requisitos implícitos ou processos ocultos que os usuários esquecem de mencionar nas entrevistas porque já os realizam de forma automática no dia a dia.

* **Brainstorming (Tempestade de Ideias)**
  * Reuniões dinâmicas e sem julgamentos iniciais focadas em gerar o maior volume possível de ideias criativas para o software.
  * *Aplicação:* Muito utilizada no início de projetos inovadores ou startups, servindo para desenhar o leque de funcionalidades disruptivas que o sistema pode oferecer ao mercado.

* **Análise de Documentos e Sistemas Legados**
  * Investigação técnica de manuais de procedimentos atuais, formulários impressos, planilhas eletrônicas e relatórios gerados por sistemas antigos que o novo software irá substituir.
  * *Aplicação:* Garante que o novo sistema herde as regras de negócio essenciais, termos técnicos corretos e fluxos operacionais que já funcionam na organização.

* **Prototipação Rápida**
  * Construção de maquetes visuais, wireframes ou telas interativas simples (usando ferramentas como Figma ou Adobe XD) para mostrar ao cliente como o software poderá funcionar.
  * *Aplicação:* Funciona como uma técnica de levantamento reversa: ao interagir com o protótipo, o usuário instantaneamente identifica o que falta ou o que precisa ser alterado, ajudando a elicitar novos requisitos antes de escrever qualquer linha de código.
