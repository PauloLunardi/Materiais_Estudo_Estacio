# Subconsultas Aninhadas e Correlatas

Este documento apresenta os conceitos arquiteturais e a aplicação prática de subconsultas (Subqueries) no SGBD PostgreSQL, demonstrando como resolver problemas de negócios complexos por meio de consultas internas aninhadas e correlacionadas, além de analisar equivalências com junções relacionais. 

## 1. Conceito e Classificação de Subconsultas

* Uma subconsulta é uma instrução SELECT aninhada dentro de outra consulta principal (Outer Query), delimitada obrigatoriamente por parênteses.
* O motor do SGBD PostgreSQL processa a subconsulta para gerar um resultado temporário em memória que alimenta os filtros ou projeções da consulta externa.
* **Subconsultas Aninhadas (Independentes):** Não possuem nenhuma dependência das colunas da consulta externa. Elas são executadas uma única vez pelo otimizador, e seu resultado final (seja um valor escalar ou uma lista) é repassado diretamente para a query principal.
* **Subconsultas Correlatas:** Possuem dependência direta de uma ou mais colunas da consulta externa. O interpretador do banco de dados precisa avaliar a subconsulta repetidamente, linha por linha, para cada registro processado pela consulta principal, o que exige maior custo computacional.

## 2. Matriz de Tipos de Subconsultas e Operadores

```text

Tipo de Subconsulta    Retorno Esperado            Operadores Comuns de Comparação
Escalar                Uma única linha e coluna    =, <, >, <=, >=, <>
Lista (Multi-Linhas)   Múltiplas linhas e 1 coluna IN, NOT IN, ANY, ALL
Tabela (Multi-Colunas) Linhas e colunas completas  EXISTS, NOT EXISTS (Geralmente correlata)

```

## 3. Consultas Práticas: Subconsultas Aninhadas

* **Cenário de Dados:** Considere uma tabela funcionarios contendo os campos codigo, nome, salario, sexo e id_depto.

```sql

-- Consulta 01: Retornar o código e o nome do(s) funcionário(s) que ganha(m) o maior salário
SELECT codigo, nome 
FROM funcionarios 
WHERE salario = (SELECT MAX(salario) FROM funcionarios);

-- Consulta 02: Retornar o código, o nome e o salário do(s) funcionário(s) que ganha(m) mais que a média salarial dos colaboradores
SELECT codigo, nome, salario 
FROM funcionarios 
WHERE salario > (SELECT AVG(salario) FROM funcionarios)
ORDER BY salario DESC;

```

## 4. Consulta 03: Filtros Multitabelas e Equivalência com JOIN

* **Objetivo:** Retornar o código, o nome e o salário do(s) funcionário(s) que ganha(m) menos que a média salarial dos colaboradores do departamento de tecnologia da informação (TI).

```sql

-- Abordagem A: Resolvendo estritamente com Subconsulta Aninhada
SELECT f.codigo, f.nome, f.salario 
FROM funcionarios f
WHERE f.salario < (
    SELECT AVG(sal.salario) 
    FROM funcionarios sal 
    INNER JOIN departamento d ON sal.id_depto = d.id_depto 
    WHERE d.nome_depto = 'Tecnologia da Informação'
);

-- Abordagem B: Substituindo a subconsulta por uma junção explícita (Gera o mesmo resultado)
SELECT f.codigo, f.nome, f.salario 
FROM funcionarios f
CROSS JOIN (
    SELECT AVG(sal.salario) AS media_ti
    FROM funcionarios sal
    INNER JOIN departamento d ON sal.id_depto = d.id_depto
    WHERE d.nome_depto = 'Tecnologia da Informação'
) AS depto_media
WHERE f.salario < depto_media.media_ti;

```

## 5. Consulta 04: Aninhamento em Múltiplos Níveis

* **Objetivo:** Quantos funcionários recebem menos que a funcionária que possui o maior salário entre as colaboradoras de sexo feminino?

```sql

-- Execução da contagem baseada na subconsulta de teto salarial feminino
SELECT COUNT(*) AS "Quantidade de Funcionários"
FROM funcionarios
WHERE salario < (
    SELECT MAX(salario) 
    FROM funcionarios 
    WHERE sexo = 'F'
);

```
