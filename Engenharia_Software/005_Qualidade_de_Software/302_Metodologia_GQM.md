# Metodologia GQM (Goal/Question/Metric) na Engenharia de Software

O **GQM (Goal/Question/Metric)** é um modelo estruturado e hierárquico voltado para a medição direcionada a metas. O princípio fundamental do GQM é que **toda medição de software deve ter um propósito claro e explícito**, evitando o erro comum de equipes de tecnologia que coletam volumes massivos de dados e métricas sem saber como utilizá-los de forma prática para tomar decisões.

```
       NÍVEL CONCEITUAL  -->   [ META / OBJETIVO (Goal) ]
                                          |
                                          v
       NÍVEL OPERACIONAL -->   [ PERGUNTAS (Question) ]
                                          |
                                          v
       NÍVEL QUANTITATIVO -->  [ MÉTRICAS (Metric) ]
```

---

## 1. Origem e Criação
A abordagem GQM foi criada pelo **Dr. Victor Basili** na Universidade de Maryland, em conjunto com o Laboratório de Engenharia de Software (SEL) do *Goddard Space Flight Center* da **NASA** durante a década de 1980. 

A metodologia surgiu a partir de pesquisas práticas e teses acadêmicas coordenadas por Basili (com colaboradores como David M. Weiss) para avaliar e melhorar a produtividade e a qualidade dos projetos de engenharia de software aeroespaciais da agência. Posteriormente, o modelo foi refinado e amplamente documentado na década de 1990 para adoção comercial global.

---

## 2. Proposta e Estrutura Hierárquica
A proposta do GQM é realizar um desdobramento de cima para baixo (*top-down*), partindo de objetivos abstratos de negócio e engenharia até alcançar indicadores matemáticos concretos. A análise do resultado ocorre de baixo para cima (*bottom-up*), onde os dados das métricas respondem às perguntas que validam se as metas foram cumpridas.

A estrutura é dividida em três níveis:

* **Nível Conceitual - Meta (Goal):** Define o objetivo que a organização deseja alcançar. Uma meta bem-definida no GQM deve especificar o **objeto** a ser analisado (produto, processo ou recurso), o **propósito** (avaliar, controlar, prever, melhorar), o **foco de qualidade** (custo, defeitos, usabilidade, performance), o **ponto de vista** (gerente, desenvolvedor, cliente) e o **contexto/ambiente** do projeto.
* **Nível Operacional - Pergunta (Question):** Conjunto de questionamentos utilizados para caracterizar ou avaliar o objeto sob a perspectiva da meta estabelecida. As perguntas trazem a meta para a realidade do dia a dia do desenvolvimento.
* **Nível Quantitativo - Métrica (Metric):** Dados numéricos e mensuráveis associados a cada pergunta para respondê-la de forma objetiva. Podem ser métricas diretas (ex: número de bugs) ou indiretas/compostas (ex: densidade de defeitos por linha de código).

---

## 3. Como o GQM é Utilizado (Fases do Processo)
A implementação do framework GQM em uma equipe de engenharia segue quatro fases cíclicas:

1. **Planejamento:** Alocação do time de medição, seleção do projeto piloto e identificação das necessidades iniciais de melhoria.
2. **Definição:** Criação formal das metas, especificação das perguntas e o desenho/refinamento das métricas exatas que serão capturadas.
3. **Coleta de Dados:** Execução prática da medição através de ferramentas automatizadas (plugins de IDE, linters, relatórios de testes) para armazenar os dados reais.
4. **Interpretação e Análise:** Avaliação dos dados brutos processados. O time analisa os indicadores para responder às perguntas da fase 2, validando se a meta conceitual foi atingida e traçando planos de ação corretiva ou de melhoria.

---

## 4. Métricas de Controle vs. Métricas de Previsão
Dentro do framework GQM, as métricas coletadas no nível quantitativo servem a dois grandes propósitos operacionais distintos: controlar o andamento atual do projeto ou prever cenários futuros.

### Métricas de Controle (Métricas de Processo e Estado Atual)
São utilizadas para monitorar a saúde e a conformidade do sistema e dos processos no presente, garantindo estabilidade e permitindo intervenções rápidas se algo sair dos limites aceitáveis.
* **Mapeamento Prático de Exemplo (GQM):**
  * **Meta:** Melhorar a estabilidade das entregas contínuas em produção do ponto de vista da equipe de SQA.
  * **Pergunta:** Qual é o nível de integridade da nossa build atual?
  * **Métricas de Controle:**
    * Taxa de sucesso de compilação da esteira de CI/CD (Builds Verificadas).
    * Percentual de cobertura de testes unitários ativos por módulo.
    * Quantidade de defeitos críticos abertos aguardando correção (*Issue Log*).

### Métricas de Previsão (Métricas Preditivas e de Estimativa)
São métricas coletadas para alimentar modelos matemáticos ou históricos que tentam prever o comportamento futuro do produto, os custos de manutenção ou a probabilidade de falhas futuras em produção.
* **Mapeamento Prático de Exemplo (GQM):**
  * **Meta:** Prever o esforço necessário para a fase de suporte do produto de software.
  * **Pergunta:** Quão propenso a novos defeitos está o sistema modificado?
  * **Métricas de Previsão:**
    * **Complexidade Ciclomática / Complexidade de McCabe:** Indica funções excessivamente ramificadas, permitindo prever quais módulos concentrarão os próximos bugs estruturais.
    * **Acoplamento entre Componentes:** Mede o grau de dependência entre módulos; classes altamente acopladas permitem prever um alto custo de manutenção (*MTTR*) futuro.
    * **Densidade de Defeitos Histórica (Bugs por KLOC):** Ajuda a prever estatisticamente o volume provável de incidentes que surgirão no próximo lançamento em larga escala com base nas linhas de código adicionadas.
```
