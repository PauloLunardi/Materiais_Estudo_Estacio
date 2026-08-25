# Consulta Correlacionada com Uso de [NOT] EXISTS

Este documento apresenta as tecnicas de validacao de existencia de registros em subconsultas correlacionadas utilizando os operadores EXISTS e NOT EXISTS no SGBD PostgreSQL, demonstrando seu comportamento logico e aplicacoes praticas. 

## 1. Funcionamento dos Operadores EXISTS e NOT EXISTS

* O operador EXISTS e um operador booleano que avalia a existencia de linhas retornadas por uma subconsulta.
* O motor do SGBD interrompe o processamento interno assim que a primeira linha correspondente e encontrada (Short-circuit evaluation).
* A projecao do SELECT dentro do EXISTS (como SELECT 1 ou SELECT *) nao causa impacto de performance, pois o SGBD valida apenas a presenca do registro.
* O operador NOT EXISTS inverte a condicao, retornando verdadeiro somente se a subconsulta nao encontrar nenhuma linha correspondente.

## 2. Matriz de Comportamento dos Operadores de Existencia

```text

Sintaxe Aplicada       Retorno da Subconsulta      Resultado Booleano Final
EXISTS (...)           Pelo menos 1 linha achada   TRUE (A linha externa e incluida no resultado)
EXISTS (...)           Nenhuma linha encontrada    FALSE (A linha externa e descartada)
NOT EXISTS (...)       Pelo menos 1 linha achada   FALSE (A linha externa e descartada)
NOT EXISTS (...)       Nenhuma linha encontrada    TRUE (A linha externa e incluida no resultado)

```

## 3. Consulta 07: Filtragem de Departamentos Ativos (EXISTS)

* **Objetivo:** Exibir o código e o nome do departamento em que há pelo menos um funcionário alocado.

```sql

-- Execucao utilizando subconsulta correlata com EXISTS
-- O SGBD avalia cada departamento e verifica se ha correspondencia em funcionarios
SELECT d.id_depto, d.nome_depto
FROM departamento d
WHERE EXISTS (
    SELECT 1 
    FROM funcionarios f 
    WHERE f.id_depto = d.id_depto
)
ORDER BY d.id_depto ASC;

```

## Explicação do Mecanismo de Busca

* Para cada linha da tabela externa departamento (d), o PostgreSQL abre a tabela interna funcionarios (f).
* O vinculo logico e resolvido pela igualdade das chaves estrangeiras f.id_depto = d.id_depto.
* Se o departamento avaliado possuir um ou mais colaboradores vinculados, a condicao torna-se verdadeira e o departamento entra no relatorio.

## 4. Filtragem de Departamentos Inativos (NOT EXISTS)

* Finalmente, se estivéssemos interessados em saber se há departamento sem ocorrência de colaborador alocado, bastaria usar a negação (NOT), conforme a seguir.
* Esta abordagem localiza rapidamente setores vazios, funcionando como uma alternativa eficiente ao uso de juncoes do tipo LEFT JOIN ... WHERE key IS NULL.

```sql

-- Execucao utilizando a negacao NOT EXISTS para isolar departamentos sem vinculos
SELECT d.id_depto, d.nome_depto
FROM departamento d
WHERE NOT EXISTS (
    SELECT 1 
    FROM funcionarios f 
    WHERE f.id_depto = d.id_depto
)
ORDER BY d.id_depto ASC;

```
