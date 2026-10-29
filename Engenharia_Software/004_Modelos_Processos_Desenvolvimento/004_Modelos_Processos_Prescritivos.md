# Modelos de Processos Prescritivos de Desenvolvimento de Software

Os **Modelos Prescritivos de Processo** foram originalmente criados para trazer ordem, estrutura e previsibilidade ao desenvolvimento de sistemas complexos. Eles são chamados de "prescritivos" porque determinam antecipadamente um conjunto de atividades metodológicas, ações, tarefas, marcos e produtos de trabalho que a equipe de engenharia deve seguir rigorosamente.

Abaixo estão detalhados os principais modelos clássicos descritos pela literatura de **Roger Pressman (2016)** e **Ian Sommerville (2007)**.

---

## 1. O Modelo em Cascata (*Waterfall*)

O Modelo em Cascata é o mais antigo e clássico dos modelos de ciclo de vida. Ele propõe uma abordagem sistemática e sequencial para o desenvolvimento de software.

* **Dinâmica do Fluxo:** O fluxo é estritamente **Linear**. Uma atividade metodológica genérica só pode ser iniciada quando a atividade anterior estiver 100% concluída e seus artefatos validados. O processo avança em linha reta de cima para baixo (como uma cachoeira): *Comunicação ➔ Planejamento ➔ Modelagem ➔ Construção ➔ Implantação*.
* **Cenário Ideal:** Projetos cujos requisitos sejam extremamente estáveis, muito bem compreendidos logo no início e que dificilmente sofrerão alterações ao longo do tempo (ex: sistemas regulatórios governamentais ou softwares baseados em normas rígidas).
* **Desvantagem Principal:** Baixa flexibilidade. Se um erro de requisito for descoberto apenas na fase de construção ou testes, o custo para retornar à fase de comunicação e corrigir o problema é proibitivo. Além disso, o cliente só vê o software funcionando no final do cronograma.

---

## 2. O Modelo de Processo Incremental

Quando o mercado exige que partes do sistema sejam entregues rapidamente, a engenharia adota a filosofia incremental.

* **Dinâmica do Fluxo:** O software não é entregue de uma única vez. O escopo total é quebrado em fatias funcionais chamadas **incrementos**. Cada incremento passa pelas cinco atividades genéricas e adiciona uma nova funcionalidade utilizável ao software que já foi entregue anteriormente.
* **O Core do Modelo:** O primeiro incremento costuma ser o **Produto Núcleo (*Core Product*)**, que resolve a necessidade mais crítica do negócio (ex: o módulo de vendas de um e-commerce). Os incrementos subsequentes adicionam características secundárias (ex: módulo de relatórios, sistema de cupons).
* **Cenário Ideal:** Situações onde a equipe técnica é reduzida e não consegue construir o sistema inteiro de uma vez, ou quando a empresa precisa colocar o produto básico no mercado rapidamente para bater a concorrência (*time-to-market*).

---

## 3. Modelos de Processo Evolucionário

Diferente do Cascata, os modelos evolucionários reconhecem que o software evolui e se transforma ao longo do tempo. Eles são projetados para crescer e se adaptar à medida que o entendimento do problema amadurece. As duas principais abordagens evolucionárias são:

### A. Prototipação (*Prototyping*)
* **Dinâmica do Fluxo:** É uma abordagem cíclica de experimentação rápida. Diante de requisitos confusos, a equipe projeta e constrói rapidamente uma maquete ou tela interativa (o protótipo).
* **O Objetivo:** O protótipo é entregue ao cliente para que ele possa mexer e avaliar. O feedback gerado serve para clarear as ideias e refinar os requisitos reais. Uma vez descobertos os requisitos verdadeiros, o protótipo pode ser descartado e o software real é construído sob bases sólidas.

### B. O Modelo Espiral (*Spiral Model*)
Proposto originalmente por Barry Boehm, o Modelo Espiral é uma abordagem evolucionária altamente focada no **gerenciamento rigoroso de riscos**. O software é desenvolvido em uma série de versões evolucionárias que vão crescendo em tamanho e escopo a cada volta completa na espiral.

A cada loop (iteração) em torno da espiral, a equipe passa obrigatoriamente por **quatro etapas fundamentais**:

```text
    [ Etapa 1: Definir Objetivos ]   |   [ Etapa 2: Avaliar Riscos ]
-------------------------------------+-------------------------------------
    [ Etapa 4: Planejar Próxima ]    |   [ Etapa 3: Desenvolver e Testar ]
```

* **Primeira Etapa (Definição de Objetivos, Alternativas e Restrições):** No início de cada ciclo, determinam-se os objetivos específicos daquela iteração (quais funcionalidades serão abordadas), as alternativas tecnológicas viáveis para alcançá-los e as restrições existentes (prazo, custo).
* **Segunda Etapa (Avaliação de Alternativas e Identificação/Resolução de Riscos):** É a etapa mais importante e exclusiva do modelo. A equipe analisa tecnicamente todas as alternativas e realiza uma avaliação profunda dos riscos envolvidos. Provas de conceito (PoCs) e protótipos são construídos aqui especificamente para eliminar incertezas técnicas antes de prosseguir.
* **Terceira Etapa (Desenvolvimento e Validação do Produto do Nível):** Após mitigar os riscos, o time executa a engenharia tradicional daquele ciclo. Escreve-se o código, realizam-se os testes correspondentes (unidade, integração) e valida-se a versão gerada naquela fatia da espiral.
* **Quarta Etapa (Planejamento do Próximo Ciclo):** O projeto é avaliado junto ao cliente. Com base no feedback obtido, planeja-se a próxima volta da espiral, definindo o escopo, cronograma e orçamento da iteração subsequente.
