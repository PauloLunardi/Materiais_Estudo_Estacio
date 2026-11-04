# Medição e o Processo de Medição de Produto de Software

A **medição de software** consiste na coleta sistemática de dados quantitativos sobre as características do produto, do processo ou dos recursos de desenvolvimento. O objetivo principal da medição no controle de qualidade é fornecer dados objetivos que auxiliem os engenheiros a entender a estabilidade do sistema, prever atributos de qualidade e identificar pontos de falha antes que se tornem problemas críticos em produção.

```
[ ESCOPO/OBJETIVOS ] --> [ ESCOLHA DE MÉTRICAS ] --> [ COLETA DE DADOS ] --> [ ANÁLISE DE ANOMALIAS ]
```

---

## Detalhamento das Etapas do Processo (Módulos da Imagem)

O fluxo apresentado na imagem mapeia a sequência lógica do **Processo de Medição de Produto** utilizado para avaliar e monitorar a integridade técnica de componentes de software. Abaixo está o detalhamento de cada módulo:

### 1. Escolher as Medições a Serem Feitas
Esta etapa inicial define o propósito e o escopo da medição. Não se deve medir tudo indiscriminadamente, mas sim o que é estratégico.
* **Conceito:** Envolve a formulação das perguntas de negócio e de engenharia às quais a métrica precisa responder (ex: "Este código está complexo demais?", "Temos muitos caminhos lógicos sem testes?").
* **Abordagem Comum:** Utiliza-se frequentemente o modelo **GQM (Goal-Question-Metric)**, onde um Objetivo gera Questões e estas geram Métricas concretas (ex: Complexidade Ciclomática, Acoplamento entre Classes).

### 2. Selecionar os Componentes a Serem Avaliados
Em sistemas de larga escala ou legados, pode ser inviável ou ineficiente analisar absolutamente todos os arquivos e módulos em cada ciclo.
* **Conceito:** Escolha de um conjunto representativo ou crítico de componentes da arquitetura para passar pela auditoria métrica. 
* **Foco:** Priorizam-se os módulos mais alterados recentemente (*hotspots*), componentes que lidam com regras críticas de negócio ou áreas históricas que costumam concentrar a maioria dos bugs.

### 3. Mediar (Medir) as Características dos Componentes
*Nota: A palavra "Mediar" descrita na barra da imagem funciona na literatura técnica de Engenharia de Software como a ação direta de **Medir**.*
* **Conceito:** É a execução prática da coleta de dados. Os componentes selecionados são submetidos a ferramentas de análise que realizam a leitura estrutural da base de código e extraem os valores brutos das métricas definidas no passo 1.
* **Prática Técnica:** Recomenda-se fortemente o uso de **ferramentas de análise estática automática** (como SonarQube, linters ou analisadores de dependências) integradas à esteira de CI/CD para que a medição ocorra sem intervenção humana manual.

### 4. Identificar Medições Anômalas
Uma vez que os números brutos são gerados, o sistema ou o analista de QA precisa procurar desvios estatísticos.
* **Conceito:** Consiste em comparar as métricas recém-coletadas com o banco de dados histórico do próprio projeto ou com os limites-padrão aceitáveis pela empresa.
* **O que procurar:** Busca-se por *outliers* (valores atipicamente muito altos ou muito baixos). Por exemplo: se a média de complexidade das funções do projeto é 5, uma função recém-criada com complexidade 45 é imediatamente classificada como uma **medição anômala**.

### 5. Analisar Componentes Anômalos
Ter um valor anômalo não significa obrigatoriamente que o código está quebrado, mas indica um forte sinal de alerta técnico (*code smell*).
* **Conceito:** Avaliação minuciosa e humana sobre os componentes que apresentaram discrepâncias para identificar se houve perda real de qualidade.
* **Ação Corretiva:** O time analisa o componente anômalo para decidir se ele precisa passar por uma refatoração imediata para reduzir riscos, se necessita de uma cobertura de testes muito mais agressiva ou se a anomalia é justificada pela natureza altamente especializada daquela parte do sistema.
```
