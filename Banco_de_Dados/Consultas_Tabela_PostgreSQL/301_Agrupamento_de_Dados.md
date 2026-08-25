# Agrupamento de Dados

Este documento apresenta as regras de agregacao e segmentacao de registros por afinidade utilizando as clausulas GROUP BY e HAVING no SGBD PostgreSQL, demonstrando a aplicacao pratica por meio de consultas multidimensionais, estatisticas e de controle de resultados. 

## 1. Conceito de Agrupamento e Filtragem de Grupos

* A clausula GROUP BY divide os registros retornados pela query em grupos menores que compartilham valores identicos nas colunas declaradas.
* Sempre que o agrupamento e ativado, toda coluna projetada no SELECT deve obrigatoriamente participar do GROUP BY ou estar encapsulada em uma funcao de agregacao (Ex: COUNT, SUM, AVG).
* A clausula HAVING funciona como um filtro booleano exclusivo para os grupos formados, atuando obrigatoriamente apos o processamento das funcoes de resumo.
* O bloco WHERE descarta linhas antes do agrupamento, enquanto o bloco HAVING descarta os grupos prontos em memoria.

## 2. Matriz de Diferencas Operacionais de Filtros

```text

Criterio Tecnico       Clausula WHERE              Clausula HAVING
Momento de Execucao    Antes do GROUP BY (Pre-filtro) Apos o GROUP BY (Pos-filtro)
Alvo da Condicao       Linhas atomicas individuais Grupos consolidados e resumos
Suporte a Agregacoes   Nao permite (Erro de sintaxe) Permite o uso nativo (Ex: SUM > x)
Impacto em Performance Alto (Reduz dados processados) Moderado (Filtra dados prontos)

```

## 3. Consulta 01 e 02: Resumos Estatisticos Simples

* **Consulta 01:** Para retornar o número de funcionários por sexo.

```sql

-- Contagem de colaboradores segmentada por genero
SELECT sexo, COUNT(*) AS "Número de funcionários" 
FROM colaboradores 
GROUP BY sexo
ORDER BY sexo ASC;

```

### Resultado da Consulta 01

```text

 sexo | Número de funcionários 
------+------------------------
 F    |                      3
 M    |                      2
(2 rows)

```

* **Consulta 02:** Para retornar a média salarial por sexo.

```sql

-- Calculo da media aritmetica de remuneracao por genero
SELECT sexo, ROUND(AVG(salario), 2) AS "Salário Médio" 
FROM colaboradores 
GROUP BY sexo
ORDER BY "Salário Médio" DESC;

```

### Resultado da Consulta 02

```text

 sexo | Salário Médio 
------+---------------
 M    |       5200.00
 F    |       4850.00
(2 rows)

```

## 4. Consulta 03: Agregacao Complexa com Funcoes de Data

* **Objetivo:** Para retornar, por mês de aniversário, a quantidade de colaboradores, o menor salário, o maior salário e o salário médio, ordene os resultados por mês de aniversário.

```sql

-- Agrupamento baseado no subcampo extract de data de nascimento
SELECT 
    EXTRACT(MONTH FROM dtnascimento) AS "Mês Aniversário",
    COUNT(*) AS "Qtd Colaboradores",
    MIN(salario) AS "Menor Salário",
    MAX(salario) AS "Maior Salário",
    ROUND(AVG(salario), 2) AS "Salário Médio"
FROM colaboradores
GROUP BY EXTRACT(MONTH FROM dtnascimento)
ORDER BY "Mês Aniversário" ASC;

```

### Resultado da Consulta 03

```text

 Mês Aniversário | Qtd Colaboradores | Menor Salário | Maior Salário | Salário Médio 
-----------------+-------------------+---------------+---------------+---------------
               1 |                 1 |       4500.00 |       4500.00 |       4500.00
               3 |                 2 |       3800.00 |       5200.00 |       4500.00
               7 |                 1 |       6000.00 |       6000.00 |       6000.00
              10 |                 1 |       5500.00 |       5500.00 |       5500.00
(4 rows)

```

## 5. Consulta 04: Agrupamento Multi-Coluna (Multidimensional)

* **Objetivo:** Para retornar, por mês de aniversário, o mês, o sexo e a quantidade de colaboradores, veja o código a seguir. Os resultados ordenados são apresentados pelo mês.

```sql

-- Agrupamento composto combinando expressao temporal e coluna atomica
SELECT 
    EXTRACT(MONTH FROM dtnascimento) AS "Mês",
    sexo,
    COUNT(*) AS "Quantidade"
FROM colaboradores
GROUP BY EXTRACT(MONTH FROM dtnascimento), sexo
ORDER BY "Mês" ASC, sexo ASC;

```

### Resultado da Consulta 04

```text

 Mês | sexo | Quantidade 
-----+------+------------
   1 | F    |          1
   3 | F    |          1
   3 | M    |          1
   7 | M    |          1
  10 | F    |          1
(5 rows)

```
