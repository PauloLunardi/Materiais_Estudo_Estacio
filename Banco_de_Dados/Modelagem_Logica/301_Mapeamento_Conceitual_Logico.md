# Mapeamento Conceitual-Lógico de Entidades

## 1. Diretrizes Técnicas e Regras de Mapeamento

O mapeamento conceitual-lógico constitui a etapa de engenharia reversa e transição onde as definições abstratas contidas no Diagrama Entidade-Relacionamento (DER) são convertidas em estruturas de dados tangíveis de baixo nível, preparando o banco de dados para a implementação física em um SGBD Relacional. 

* **O Princípio da Correspondência:** Cada componente gráfico contido no modelo conceitual possui uma regra determinística de conversão: 

  * **Entidades Fortes:** São mapeadas e transformadas diretamente em tabelas independentes (relações).
  * **Atributos Simples:** Tornam-se as colunas (campos) da tabela correspondente.
  * **Atributos Identificadores:** São promovidos e configurados estritamente como a Chave Primária (PK) da relação gerada.
* **Obrigatoriedade e Domínio:** Durante a transição, a cardinalidade mínima de cada atributo conceitual dita se a respectiva coluna lógica receberá a restrição de preenchimento mandatório (NOT NULL) ou opcional (NULL).

# 2. Processo Prático de Mapeamento de Entidades

A conversão de entidades fortes baseia-se no isolamento estrutural dos objetos do minimundo. Cada elemento da caixa do DER deve ser declarado e associado a um tipo de dado e restrição de integridade referencial estável. 

### Exemplo Prático de Mapeamento de Entidades

Considere o cenário conceitual de uma instituição de ensino que gerencia o acervo acadêmico por meio das entidades fortes ALUNO e CURSO. Abaixo está a declaração do esquema lógico textual gerado a partir do mapeamento: 

```text

ALUNO (CODIGOALUNO, NOME, CPF, DTNASCIMENTO)

CURSO (CODIGOCURSO, NOMECURSO, CARGAHORARIA)

```

### Estrutura das Tabelas Lógicas Geradas (Texto Puro)

**Relação / Tabela: ALUNO** 

```text

CODIGOALUNO (PK) | NOME                   | CPF         | DTNASCIMENTO
-----------------|------------------------|-------------|-------------
1                | Aline Goncalves Campos | 09320900022 | 13/02/1980
2                | Pablo Goncalves Campos | 08760900022 | 13/12/1984

```

**Relação / Tabela: CURSO** 

```text

CODIGOCURSO (PK) | NOMECURSO        | CARGAHORARIA
-----------------|------------------|-------------
ENG-01           | Engenharia de TI | 3600
COMP-02          | Ciencia da Comp. | 3200

```

## 3. Explicação Técnica do Mapeamento de Entidades

A mecânica aplicada para a consolidação das tabelas do exemplo anterior obedece a critérios sistemáticos de engenharia de dados que estruturam os objetos independentes do sistema: 

* **Mapeamento da Entidade ALUNO:** 

  * A caixa retangular ALUNO do DER foi convertida na tabela física ALUNO.
  * O atributo identificador conceitual CODIGOALUNO (representado no DER pelo círculo totalmente preenchido) foi definido como a **Chave Primária (PK)** simples da relação.
  * As propriedades NOME, CPF e DTNASCIMENTO migraram de forma atômica como colunas obrigatórias convencionais da tabela.
* **Mapeamento da Entidade CURSO:** 

  * O bloco abstrato CURSO transformou-se na tabela de banco de dados CURSO.
  * O campo CODIGOCURSO assumiu a responsabilidade de ser a **Chave Primária (PK)** para impedir registros duplicados de matrizes curriculares.
  * As propriedades NOMECURSO e CARGAHORARIA foram anexadas como campos verticais da relação, com o domínio numérico associado ao tempo em horas de cada treinamento.

