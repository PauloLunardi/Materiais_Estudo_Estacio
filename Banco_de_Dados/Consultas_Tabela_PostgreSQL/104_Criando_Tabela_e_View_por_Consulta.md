# Criando Tabela e View a Partir de Consulta

Este documento apresenta os conceitos e comandos práticos para a persistência de resultados de consultas no SGBD PostgreSQL, detalhando a criação de tabelas físicas por meio de estruturas DDL dinâmicas e a definição de tabelas virtuais por meio de Views. 

## 1. Persistência Lógica vs. Física de Consultas

* A criação de objetos a partir de consultas elimina a necessidade de redigitar estruturas DDL complexas.
* Uma tabela criada a partir de uma consulta armazena fisicamente os dados resultantes no momento da execução.
* Uma View funciona como uma tabela virtual que não guarda dados próprios, armazenando apenas a query de origem.
* Alterações nos dados da tabela original refletem-se instantaneamente na View, mas não na tabela gerada por consulta.

## 2. Matriz de Diferenças Operacionais

```text
|=========================================================================================================|
|  Critério Técnico       |  Tabela por Consulta (CTAS)    |  Tabela Virtual (View)                       |
|=========================================================================================================|
|  Armazenamento Físico   |  Consome espaço em disco       |  Consome apenas metadados no catálogo        |
|  Atualização dos Dados  |  Estática (Requer nova carga)  |  Dinâmica (Executa a query em tempo real)    |
|  Desempenho de Leitura  |  Rápido (Dados pré-calculados) |  Depende da complexidade da consulta base    |
|  Suporte a Índices      |  Permite criação de índices    |  Não permite índices diretos (Apenas em MVs) |
|=========================================================================================================|

```

## 3. Criando Tabela a Partir de Consulta (CTAS)

* A sintaxe utilizada é conhecida como CREATE TABLE AS SELECT (CTAS).
* O SGBD cria a tabela automaticamente e infere os tipos de dados baseando-se nas colunas projetadas.
* Os nomes das colunas da nova tabela serão idênticos aos nomes ou aliases definidos no SELECT.
* Esta técnica é amplamente empregada para criar cópias de segurança, tabelas de histórico ou backups temporários.

```sql

-- Criacao de uma tabela fisica de backup com base em um filtro de consulta
CREATE TABLE alunos_maiores_idade AS
SELECT 
    NOME,
    EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) AS idade
FROM ALUNO
WHERE EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) >= 18;

-- Validacao da tabela fisica criada com os dados copiados
SELECT * FROM alunos_maiores_idade;

```

## 4. Criando View a Partir de Consulta

* O comando CREATE VIEW registra uma consulta estruturada dentro do dicionário de dados do PostgreSQL.
* Sempre que a View é chamada em um SELECT, o motor do banco executa a query subjacente de forma transparente.
* É uma excelente ferramenta para simplificar queries complexas contendo múltiplos JOINs ou agregações para a aplicação.
* Funciona também como camada de segurança, permitindo expor apenas colunas específicas para determinados usuários.

```sql

-- Criacao de uma view para encapsular a regra complexa de faixas etarias
CREATE VIEW vw_faixa_etaria_alunos AS
SELECT 
    NOME,
    EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) AS "Idade do Aluno",
    CASE 
        WHEN EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) <= 20 THEN '1. até 20 anos'
        WHEN EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) BETWEEN 21 AND 30 THEN '2. 21 a 30 anos'
        WHEN EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) BETWEEN 31 AND 40 THEN '3. 31 a 40 anos'
        WHEN EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) BETWEEN 41 AND 50 THEN '4. 41 a 50 anos'
        WHEN EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) BETWEEN 51 AND 60 THEN '5. 51 a 60 anos'
        WHEN EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) > 60 THEN '6. mais de 60 anos'
    END AS "Faixa Etária"
FROM ALUNO;

-- Consulta a tabela virtual (A query interna sera executada neste momento)
SELECT * FROM vw_faixa_etaria_alunos WHERE "Idade do Aluno" < 40;

```
