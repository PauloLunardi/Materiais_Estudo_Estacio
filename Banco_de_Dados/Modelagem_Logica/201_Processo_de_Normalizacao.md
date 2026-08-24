# Banco de Dados: Processo de Normalização

## 1. Fundamentos da Normalização e Formas Normais

Projetar um banco de dados relacional exige a aplicação de critérios científicos para avaliar a qualidade técnica das tabelas. O processo que guia essa avaliação é denominado **Normalização**, cujo foco principal é mitigar a redundância de dados, eliminar anomalias de atualização (inserção, deleção e modificação) e assegurar a consistência e a integridade da base. 

* **Conceito de Forma Normal (FN):** Funciona como uma regra ou diretriz semântica estrita que dita como os dados de uma tabela devem se relacionar. Se a tabela atende aos requisitos da regra, ela é classificada como bem projetada naquele nível.
* **Escopo Prático:** Embora a literatura de banco de dados liste diversas formas normais — como a 1FN, 2FN, 3FN, FNBC (Forma Normal de Boyce-Codd), 4FN e 5FN —, a engenharia de software adota como padrão prático a execução do processo de normalização **até a Terceira Forma Normal (3FN)** para a grande maioria dos sistemas corporativos.
* **Origem Interoperável:** O processo de normalização não precisa começar a partir de um diagrama pronto; ele pode ser iniciado a partir de qualquer representação física de dados do mundo real, incluindo telas de sistemas legados, planilhas ou relatórios impressos.

## 2. Roteiro Metodológico e Análise do Relatório Bruto

Para transformar dados brutos em uma estrutura relacional normalizada e otimizada até a 3FN, utiliza-se um roteiro sistemático composto por cinco etapas sequenciais: 

1. Identificar a origem e a semântica dos dados brutos.
2. Construir uma tabela não normalizada a partir dos dados coletados.
3. Aplicar as regras de eliminação de grupos repetitivos da Primeira Forma Normal (1FN).
4. Aplicar as regras de dependência funcional total da Segunda Forma Normal (2FN).
5. Aplicar as regras de dependência transitiva da Terceira Forma Normal (3FN).

## Estudo de Caso: Relatório de Alocação de Docentes a Projetos de Pesquisa

O minimundo analisado parte de um relatório institucional de uma Instituição de Ensino Superior (IES) que consolida o corpo docente vinculado a projetos científicos: 

```text

========================================================================================
                 RELATÓRIOS DE ALOCAÇÃO DOCENTE A PROJETOS DE PESQUISA
========================================================================================
CÓDIGO DO PROJETO: PRODATA   | TIPO: ANÁLISE DE DADOS
DESCRIÇÃO: DESENVOLVIMENTO DE AMBIENTE PARA ANÁLISE DE DADOS
----------------------------------------------------------------------------------------
CÓDIGO DOCENTE | NOME     | CATEGORIA | SALÁRIO      | DATA INÍCIO | TEMPO ALOCADO (MÊS)
----------------------------------------------------------------------------------------
DOC001         | JOSÉ     | ADJUNTO   | R$ 6.000,00  | 01/02/2019  | 16
DOC002         | LUCIANO  | TITULAR   | R$ 16.000,00 | 01/02/2020  | 4
DOC003         | GILSON   | ADJUNTO   | R$ 6.000,00  | 01/02/2019  | 16
DOC004         | MARTA    | TITULAR   | R$ 16.000,00 | 01/02/2020  | 4
========================================================================================
CÓDIGO DO PROJETO: PROMED    | TIPO: ANÁLISE CLÍNICA
DESCRIÇÃO: ATENDIMENTO COMUNITÁRIO E VACINAÇÃO
----------------------------------------------------------------------------------------
CÓDIGO DOCENTE | NOME     | CATEGORIA | SALÁRIO      | DATA INÍCIO | TEMPO ALOCADO (MÊS)
----------------------------------------------------------------------------------------
DOC001         | JOSÉ     | ADJUNTO   | R$ 6.000,00  | 01/02/2019  | 16
DOC010         | MARIA    | ADJUNTO   | R$ 6.000,00  | 01/06/2020  | 0
DOC004         | MARTA    | TITULAR   | R$ 16.000,00 | 01/05/2020  | 1
========================================================================================

```

* **Semântica dos Dados:** A leitura do relatório demonstra duas estruturas acopladas: os projetos (compostos por código, descrição e tipo) e os docentes (caracterizados por código, nome, categoria profissional, salário base, data de início da atividade e tempo total de alocação em meses).

## 3. Construção da Tabela Não Normalizada (TNN)

A segunda etapa do roteiro consiste em unificar visual e textualmente todas as informações contidas no relatório de origem em uma única estrutura de tabela bruta, evidenciando o acoplamento dos dados. 

### Tabela Prática: PROJETO (Não Normalizada)

A estrutura abaixo consolida as linhas do relatório, evidenciando as repetições de blocos onde múltiplos docentes residem dentro de um único código de projeto: 

```text

CODPROJETO | TIPO             | DESCRICAO               | CODDOC | NOME    | CAT     | SALARIO   | DTINICIO   | TEMPO
-----------|------------------|-------------------------|--------|---------|---------|-----------|------------|------
PRODATA    | ANÁLISE DE DADOS | DESENVOLVIMENTO DE AMB. | DOC001 | JOSÉ    | ADJUNTO | R$ 6000,00| 01/02/2019 | 16

           |                  |                         | DOC002 | LUCIANO | TITULAR | R$16000,00| 01/02/2020 | 4
           |                  |                         | DOC003 | GILSON  | ADJUNTO | R$ 6000,00| 01/02/2019 | 16
           |                  |                         | DOC004 | MARTA   | TITULAR | R$16000,00| 01/02/2020 | 4
-----------|------------------|-------------------------|--------|---------|---------|-----------|------------|------
PROMED     | ANÁLISE CLÍNICA  | ATENDIMENTO COMUNITÁRIO | DOC001 | JOSÉ    | ADJUNTO | R$ 6000,00| 01/02/2019 | 16

           |                  |                         | DOC010 | MARIA   | ADJUNTO | R$ 6000,00| 01/06/2020 | 0
           |                  |                         | DOC004 | MARTA   | TITULAR | R$16000,00| 01/05/2020 | 1

```

* **Representação Textual de TNN:** A estrutura acima é formalizada na engenharia de dados por meio da seguinte sintaxe, utilizando parênteses aninhados para explicitar o grupo repetitivo:

text

PROJETO (CODIGOPROJETO, TIPO, DESCRICAO, (CODIGODOCENTE, NOME, CATEGORIA, SALARIO, DATAINICIO, TEMPOMESES))

Use o código com cuidado.

* **Análise de Restrições Aninhadas:** 

  * Cada linha desta tabela bruta representa o fato complexo de alocação de um docente a um determinado projeto.
  * A coluna CODIGOPROJETO é a chave responsável por diferenciar um projeto dos demais.
  * A coluna CODIGODOCENTE atua individualizando os docentes apenas no contexto interno de cada projeto.
  * *O Impasse Estrutural:* A coluna complexa DOCENTE funciona como um atributo composto multivalorado que agrupa uma lista interna de subcampos (CODIGODOCENTE, NOME, CATEGORIA, SALARIO, DATAINICIO e TEMPOMESES). Essa configuração de aninhamento caracteriza o modelo como uma **Tabela Não Normalizada**, violando as propriedades fundamentais do modelo relacional e servindo de ponto de partida para a aplicação da 1FN.
