# Modelo Entidade-Relacionamento: Mais sobre Modelagem de Entidades e Relacionamentos

## 1. Processo Incremental e a Estratégia Descendente

Em projetos reais de engenharia de dados, um Diagrama Entidade-Relacionamento (DER) nunca é construído em uma única etapa definitiva. Trata-se de um processo incremental, onde o modelo é modificado, refinado e enriquecido de forma gradativa à medida que novos requisitos de negócios são levantados. 

* **Conceito da Estratégia Descendente (Top-Down):** Consiste em uma metodologia de modelagem que parte dos conceitos mais amplos e abstratos do sistema para, em seguida, detalhar suas propriedades específicas de baixo nível.
* **Dinâmica do Fluxo:** O projetista primeiro identifica as grandes entidades macro do negócio e, nas fases subsequentes, anexa seus respectivos atributos, chaves identificadoras e regras de relacionamentos.

## 2. Etapas de Construção do Diagrama

A adoção da estratégia descendente organiza o desenvolvimento do modelo conceitual em três fases cíclicas consecutivas. Devido à natureza mutável dos requisitos, o fluxo permite retornar a qualquer etapa anterior a fim de realizar ajustes e revisões evolutivas. 

* **Etapa 1: Modelo Inicial** 

  * Concentra os esforços na identificação primária das entidades centrais do minimundo.
  * Realiza o mapeamento dos relacionamentos de negócios, estruturas de especialização e herança.
  * Determina as cardinalidades máximas brutas das associações e elenca os atributos identificadores (chaves primárias).
* **Etapa 2: Modelo Detalhado** 

  * Refina o diagrama através da definição exata das cardinalidades mínimas e máximas de todas as pontas de conexão.
  * Identifica, isola e documenta regras de restrições semânticas adicionais que devem ser forçadas no banco de dados.
* **Etapa 3: Validação** 

  * Submete o desenho do DER a sessões de revisão técnica e homologação junto aos usuários finais e donos do negócio.
  * Garante que a estrutura gráfica atenda fielmente à realidade operacional antes de avançar para a fase de projeto lógico.
