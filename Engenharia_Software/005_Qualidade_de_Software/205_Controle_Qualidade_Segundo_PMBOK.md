# Controlar a Qualidade segundo o Guia PMBOK

O processo de **Controlar a Qualidade** pertence ao grupo de processos de *Monitoramento e Controle*. Enquanto o processo anterior (*Gerenciar a Qualidade*) foca na execução e conformidade dos processos com as pessoas, o **Controle da Qualidade foca diretamente no produto entregável (os artefatos e o código-fonte)**. 

O grande objetivo aqui é monitorar e registrar os resultados da execução das atividades de qualidade para avaliar o desempenho do software, certificar que as entregas atendem aos requisitos do cliente e validar a correta implementação de alterações aprovadas antes da homologação final.

```
[ DADOS E PRODUTOS BRUTOS ] --(Passam por)--> [ PROCESSAMENTO E TESTES ] --(Geram)--> [ ENTREGAS VERIFICADAS ]
   - Entregas brutas                             - Inspeções / Testes                     - Software sem bugs
   - Dados de desempenho                         - Gráficos e Estatísticas                - Métricas reais de QA
```

---

## Detalhamento das Etapas do Processo

Abaixo está a explicação conceitual e prática de cada item contido na matriz oficial do PMBOK para o Controle de Qualidade:

### 1. Entradas (Inputs)
Os recursos, dados de campo e documentos necessários para iniciar a inspeção do produto de software:

* **Plano de gerenciamento do projeto:**
  * **Plano de gerenciamento da qualidade:** Define de forma explícita *como* o controle de qualidade deve ser executado, quais ferramentas serão utilizadas e quais são os limites estatísticos aceitáveis para as falhas.
* **Documentos do projeto:**
  * **Registro das lições aprendidas:** Histórico de erros cometidos no início do projeto que ajuda a guiar o foco dos testes atuais para evitar reincidências.
  * **Métricas da qualidade:** Os alvos numéricos e os atributos exatos a serem medidos (ex: cobertura mínima de testes de 80%, taxa aceitável de falhas de 1%).
  * **Documentos de teste e avaliação:** Roteiros, matrizes de rastreabilidade, cenários de teste criados anteriormente e checklists de validação.
* **Solicitações de mudança aprovadas:** Modificações de código, correções de bugs anteriores ou novas regras que foram aprovadas e precisam ser testadas para garantir que foram implementadas perfeitamente.
* **Entregas:** O software bruto compilado (o incremento do sistema, artefatos, APIs prontas) que precisa passar pela bateria de testes funcionais e não funcionais.
* **Dados de desempenho do trabalho:** Métricas reais e brutas capturadas diretamente da equipe (ex: quantidade de bugs abertos, tempo de carregamento real medido na máquina, número de testes que falharam).
* **Fatores ambientais da empresa:** Sistemas operacionais homologados na empresa, sistemas de rastreamento de bugs da organização (Jira, Redmine) e restrições regulatórias do setor.
* **Ativos de processos organizacionais:** Políticas de qualidade globais da empresa, diretrizes formais para relatórios de defeitos e repositórios de métricas corporativas.

### 2. Técnicas e Ferramentas (Tools & Techniques)
As metodologias analíticas e práticas utilizadas para inspecionar, avaliar e descobrir defeitos no sistema de software:

* **Coleta de dados:**
  * **Listas de verificação (Checklists):** Guias estruturados com o critério de pronto (*Definition of Done*) para checar se todas as funções exigidas na história de usuário foram programadas.
  * **Folhas de verificação (Check Sheets):** Planilhas simples para anotar dados e contar a frequência de defeitos na hora em que eles aparecem durante o teste.
  * **Amostragem estatística:** Escolha aleatória de uma parte do código ou de um conjunto de requisições de API para testar quando o volume total de dados é grande demais.
  * **Questionário e pesquisas:** Coleta de dados com os usuários participantes dos testes Alpha e Beta para avaliar a satisfação com o sistema.
* **Análises de dados:**
  * **Análises de desempenho:** Comparação dos tempos de resposta reais medidos no software contra a linha de base planejada de performance.
  * **Análise de causa-raiz:** Estudo focado em descobrir *por que* um bug complexo aconteceu para consertar a engrenagem do sistema e não apenas remediar o sintoma.
* **Inspeção:** Exame físico direto do produto (como a revisão formal de código e as verificações visuais de interface gráfica).
* **Testes/avaliação de produtos:** A execução prática do software (testes automáticos, testes de stress, testes integrados) para avaliar o funcionamento em tempo real.
* **Representação de dados:**
  * **Diagramas de causa e efeito (Ishikawa/Espinha de peixe):** Mapeamento visual das causas de um bug.
  * **Gráficos de controle:** Gráficos que mostram a variação do processo ao longo do tempo com limites superior e inferior (ex: monitorar o tempo de resposta da API nas builds).
  * **Histograma:** Gráfico de barras que exibe a distribuição de frequências de defeitos classificados por categorias (ex: interface, banco de dados, lógica).
  * **Diagramas de dispersão:** Gráficos de pontos que cruzam duas variáveis para achar correlações (ex: quantidade de linhas de código em uma classe vs. quantidade de bugs dela).
* **Reuniões:** Encontros formais com o time de testes, analistas de negócios e desenvolvedores para triagem de bugs (*Bug Triage*) e alinhamento do status da qualidade do sistema.

### 3. Saídas (Outputs)
Os resultados diretos produzidos após a filtragem e a inspeção das entregas:

* **Medições de controle da qualidade:** Os resultados documentados, numéricos e objetivos de todas as avaliações feitas (ex: relatório contendo o percentual exato de testes aprovados).
* **Entregas verificadas:** O software testado e aprovado pelo controle de qualidade técnico. Esta saída é pré-requisito indispensável para que o cliente realize o processo de validação de escopo e assine o aceite formal.
* **Informações sobre o desempenho do trabalho:** Análise consolidada combinando os dados brutos (ex: descobriu-se que o índice de rejeição de código no projeto aumentou devido à pressa nas entregas).
* **Solicitações de mudança:** Se os testes detectarem falhas, o time de SQA emite solicitações de mudança de correção de defeito (*Bug Fix*) para que os desenvolvedores corrijam o problema.
* **Atualizações do plano de gerenciamento do projeto:**
  * **Plano de gerenciamento da qualidade:** Ajustes nas rotinas ou abordagens de teste caso a estratégia inicial não esteja funcionando.
* **Atualizações de documentos do projeto:**
  * **Registro das questões (Issue Log):** Cadastro formal de problemas operacionais ocorridos.
  * **Registro das lições aprendidas:** Documentação do que deu certo e errado na rodada de testes atual.
  * **Registro dos riscos:** Modificações nos níveis de risco técnico do projeto de acordo com a estabilidade apresentada pelo software.
  * **Documentos de teste e avaliação:** Otimizações e correções nos cenários e roteiros de teste após a rodada de execução.
```
