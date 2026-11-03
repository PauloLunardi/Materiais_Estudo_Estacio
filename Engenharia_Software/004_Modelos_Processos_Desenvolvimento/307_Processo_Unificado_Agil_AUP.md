# O Processo Unificado Ágil (AUP - Agile Unified Process)

O **Processo Unificado Ágil (AUP)** é uma variação simplificada e otimizada do RUP (*Rational Unified Process*). 
Ele foi desenvolvido por Scott Ambler com um objetivo muito claro: combinar o rigor conceitual e a governança estruturada por fases do Processo Unificado clássico com a agilidade, simplicidade e leveza das metodologias ágeis (como Scrum e XP).

O AUP adota a filosofia de ser **"gordo no início (macro) e magro nos detalhes (micro)"**. 
Ele mantém a divisão clássica do ciclo de vida em quatro fases consecutivas, mas executa o trabalho técnico do dia a dia por meio de ciclos altamente iterativos e ágeis.

---

## As 4 Fases do Ciclo de Vida do AUP

Assim como no RUP tradicional, o tempo e os marcos gerenciais do projeto no AUP são divididos em quatro fases lineares. Em cada uma delas, o time busca alcançar objetivos específicos de governança:

* **Concepção (*Inception*):** O foco inicial é validar a viabilidade de negócio do projeto, identificar o escopo macro, os principais *stakeholders* e obter a autorização formal (e orçamento inicial) para começar o software.
* **Elaboração (*Elaboration*):** O objetivo central é compreender os requisitos do sistema e consolidar a arquitetura técnica. No AUP, busca-se criar uma arquitetura executável simples que mitigue os riscos tecnológicos antes da produção em massa.
* **Construção (*Construction*):** É a fase de maior esforço de desenvolvimento. O time foca em construir o software de forma incremental, transformando a arquitetura em um sistema completo, testado e funcional, pronto para o usuário.
* **Transição (*Transition*):** É a fase de fechamento técnico e homologação. O software passa por validações finais, empacotamento, deploy nos servidores reais de produção, migração de dados e treinamentos operacionais com os usuários.

---

## A Natureza Iterativa das 7 Disciplinas do AUP

A grande revolução do AUP está em como as atividades técnicas são executadas. Enquanto o RUP tradicional possui dezenas de disciplinas burocráticas e centenas de artefatos documentais, o AUP simplifica o fluxo de trabalho em apenas **sete disciplinas**. 

Essas disciplinas ocorrem de forma **simultânea, iterativa e contínua** em todas as fases do projeto. O que muda ao longo do tempo é o foco e o nível de esforço técnico dedicado a cada uma delas em cada iteração:

### Disciplinas Técnicas de Engenharia
* **Modelagem (*Modeling*):** Consiste em compreender os negócios da organização, os requisitos do software e projetar uma solução viável. No AUP, a modelagem segue o princípio da *Modelagem Ágil (Agile Modeling)*: criam-se diagramas UML (Classes, Casos de Uso, Sequência) simples no quadro-negro ou em ferramentas CASE apenas para entender o problema técnico, sem a necessidade de gerar documentações gigantescas e estáticas.
* **Implementação (*Implementation*):** A tradução física dos modelos lógicos em código-fonte testável, limpo e integrado. Ela ocorre de forma pesada na fase de Construção, mas também se faz presente na fase de Elaboração para construir protótipos rápidos que provam o conceito da arquitetura e eliminam riscos tecnológicos antes que seja tarde.
* **Testes (*Testing*):** Avaliação contínua da qualidade do produto. O AUP herda as práticas destrutivas do desenvolvimento ágil, como a automação de testes de unidade e integração nas esteiras de desenvolvimento. O objetivo é testar o código a cada modificação para expor defeitos (*bugs*) de forma precoce, culminando nos testes de sistema e aceitação na fase de Transição.
* **Implantação (*Deployment*):** O planejamento e a execução logística da entrega do software aos usuários. Envolve o empacotamento (geração de imagens de containers ou instaladores), gerenciamento de releases, disponibilização física ou em nuvem e a prestação de ajuda e assistência pós-lançamento.

### Disciplinas Umbralares de Gestão e Suporte
* **Gerenciamento de Configuração (*Configuration Management*):** Garante a governança, a integridade e o histórico de todos os artefatos gerados pelo time. Lida diretamente com o controle de versões do código (Git), gerência de *baselines* (linhas de base estáveis) e o controle integrado de mudanças, impedindo que o escopo cresça de forma desorganizada.
* **Gestão de Projetos (*Project Management*):** Provê a liderança e o monitoramento do progresso das iterações curtas. É responsável por calcular o esforço (horas/homem), gerenciar os custos e gerenciar ativamente o registro de riscos para blindar o cronograma e o orçamento do software.
* **Ambiente (*Environment*):** A disciplina de suporte que provê a infraestrutura necessária para o time trabalhar. Lida com a seleção, instalação e parametrização das ferramentas CASE (IDEs, servidores de testes, pipelines de CI/CD) e com a definição das regras do processo de trabalho que a empresa vai seguir.
