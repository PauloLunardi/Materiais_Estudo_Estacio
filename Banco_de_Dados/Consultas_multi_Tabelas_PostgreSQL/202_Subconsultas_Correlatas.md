# Subconsultas Correlatas

Este documento apresenta os conceitos arquiteturais e a aplicação prática das subconsultas correlacionadas no SGBD PostgreSQL, demonstrando o mecanismo de avaliação linha a linha e a reescrita otimizada por meio de junções relacionais. 

## 1. Funcionamento das Subconsultas Correlatas

* Diferente das subconsultas aninhadas simples, a subconsulta correlata depende de valores da consulta externa.
* O motor do SGBD executa a consulta interna repetidamente, uma vez para cada linha avaliada pela consulta principal.
* Essa dependência direta estabelece um vínculo lógico através de um alias (apelido) compartilhado entre as tabelas.
* Embora ofereçam alta legibilidade para regras complexas, podem apresentar menor desempenho em grandes volumes de dados.

## 2. Matriz de Abordagens: Correlata vs. Junção

```text

Critério Técnico       Abordagem Correlata         Abordagem por Junção (JOIN)
Algoritmo do SGBD      Loop aninhado linha a linha Processamento em lote (Hash/Merge)
Desempenho Geral       Menor em tabelas robustas   Maior (Otimizado pelas estatísticas)
Complexidade da Query  Alta legibilidade lógica    Requer criação de subquery no FROM
Uso de Memória RAM     Baixo e fracionado          Moderado (Gera tabelas temporárias)

```

## 3. Consulta 05: Filtragem por Média Setorial Dinâmica

* **Objetivo:** Retornar o código, o nome e o salário do(s) funcionário(s) que ganha(m) mais que a média salarial dos colaboradores do departamento ao qual pertencem.

```sql

-- Abordagem A: Resolução utilizando Subconsulta Correlata
-- A tabela interna (sub) se correlaciona com a externa (func) via id_depto
SELECT func.codigo, func.nome, func.salario, func.id_depto
FROM funcionarios func
WHERE func.salario > (
    SELECT AVG(sub.salario)
    FROM funcionarios sub
    WHERE sub.id_depto = func.id_depto
)
ORDER BY func.id_depto ASC, func.salario DESC;

```

## 4. Reescrita Otimizada da Consulta 05 com JOIN

* Há outra maneira de resolver a consulta 05, pois você pode trocar uma subconsulta por uma junção. O código a seguir produz os mesmos resultados.
* Esta técnica pré-calcula as médias de todos os departamentos de uma só vez, unindo o resultado consolidado à tabela de funcionários.

```sql

-- Abordagem B: Resolução utilizando Junção com Subconsulta no FROM
SELECT func.codigo, func.nome, func.salario, func.id_depto
FROM funcionarios func
INNER JOIN (
    -- Subconsulta que gera a tabela temporária de médias setoriais
    SELECT id_depto, AVG(salario) AS media_salarial
    FROM funcionarios
    GROUP BY id_depto
) depto_media ON func.id_depto = depto_media.id_depto
WHERE func.salario > depto_media.media_salarial
ORDER BY func.id_depto ASC, func.salario DESC;

```
