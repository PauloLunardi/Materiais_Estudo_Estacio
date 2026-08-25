# Recuperando Dados com o Uso dos Operadores IN e BETWEEN

Este documento apresenta as tecnicas de filtragem por conjuntos e intervalos no SGBD PostgreSQL, detalhando o funcionamento dos operadores IN e BETWEEN, suas variacoes com a clausula NOT e exemplos praticos de consultas baseadas no minimundo Empresa. 

## 1. Recuperando Dados com o Uso do Operador IN

* O operador IN permite verificar se o valor de uma coluna corresponde a qualquer valor contido em uma lista especificada.
* Funciona como uma alternativa sintatica simplificada para multiplas condicoes de igualdade unidas pelo operador logico OR.
* A lista de valores pode ser definida manualmente por literais ou gerada dinamicamente atraves de uma subconsulta (Subquery).
* O modificador NOT IN inverte a logica, descartando os registros cujos valores estejam presentes na listagem.

## 2. Consulta 03: Filtragem por Lista de Valores (IN)

* **Objetivo:** Listar o codigo, o titulo e o autor das obras que estao alocadas nos saloes de numero 1, 3 ou 5.

```sql

-- Execucao da query utilizando o operador IN
SELECT codigo, titulo, autor 
FROM obras 
WHERE salao IN (1, 3, 5)
ORDER BY codigo ASC;

```

### Resultado da Consulta 03

```text

 codigo |            titulo            | autor 
--------+------------------------------+-------
    101 | O Despertar da Natureza      |    20
    104 | Reflexos do Amanha           |    25
    107 | Escultura de Outono          |    30
(3 rows)

```

## 3. Recuperando Dados com o Uso do Operador BETWEEN

* O operador BETWEEN filtra registros com base em um intervalo fechado, delimitado por um valor minimo e um valor maximo.
* A sintaxe BETWEEN valor_min AND valor_max e inclusiva, incluindo os proprios limites estabelecidos na comparacao.
* O motor do SGBD processa essa instrucao transformando-a logicamente na expressao coluna >= valor_min AND coluna <= valor_max.
* O operador pode ser aplicado em colunas de tipos numericos, textuais e de data/hora (Time-series).

## 4. O Modificador [NOT] BETWEEN

* A clausula NOT BETWEEN inverte o criterio de busca para selecionar registros que estao fora do intervalo especificado.
* A expressao NOT BETWEEN valor_min AND valor_max exclui os valores limites e todo o intervalo interno.
* E equivalente a instrucao logica baseada em operadores relacionais coluna < valor_min OR coluna > valor_max.

```text

Sintaxe Aplicada             Comportamento no PostgreSQL
BETWEEN 10 AND 20            Seleciona valores de 10 ate 20 (Inclui 10 e 20)
NOT BETWEEN 10 AND 20        Seleciona valores menores que 10 ou maiores que 20

```

## 5. Consulta 04: Filtragem por Intervalo Inclusivo (BETWEEN)

* **Objetivo:** Listar o codigo, o titulo e o ano das obras cujo ano de criacao esteja entre os anos de 2010 e 2020.

```sql

-- Execucao da query utilizando o operador BETWEEN
SELECT codigo, titulo, ano 
FROM obras 
WHERE ano BETWEEN 2010 AND 2020
ORDER BY ano DESC;

```

### Resultado da Consulta 04

```text

 codigo |            titulo            |  ano  
--------+------------------------------+-------
    501 | Monalisa Revisitada          |  2015
    502 | Noite Estrelada Moderna      |  2011
    101 | O Despertar da Natureza      |  2010
(3 rows)

```
