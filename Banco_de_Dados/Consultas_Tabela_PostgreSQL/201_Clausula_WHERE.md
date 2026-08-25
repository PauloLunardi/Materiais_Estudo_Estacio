# Consultas Usando a Clausula WHERE

Este documento apresenta as regras de filtragem horizontal de registros utilizando a clausula WHERE, o mapeamento dos operadores relacionais nativos do SGBD PostgreSQL e exemplos práticos de consultas com exibição de resultados. 

## 1. Recuperando Dados com SELECT / FROM / WHERE / ORDER BY

* A cláusula WHERE intercepta as linhas retornadas pela cláusula FROM e aplica um filtro lógico booleano.
* O motor do SGBD avalia cada registro individualmente e descarta os dados que retornarem o valor FALSE ou UNKNOWN.
* A filtragem precede o processamento de ordenação executado no bloco final da instrução ORDER BY.
* O uso correto de índices nas colunas filtradas evita que o PostgreSQL realize uma leitura sequencial pesada no disco.

## 2. Matriz de Operadores Relacionais

```text

Operador               Significado                 Comportamento Lógico no PostgreSQL
<                      menor                       Verifica se o valor da esquerda é estritamente menor
<=                     menor ou igual a            Verifica se o valor da esquerda é menor ou idêntico
>                      maior                       Verifica se o valor da esquerda é estritamente maior
>=                     maior ou igual a            Verifica se o valor da esquerda é maior ou idêntico
=                      igual                       Executa comparação exata de igualdade entre os termos
<> ou !=               diferente                   Retorna verdadeiro se os valores comparados forem distintos

```

## 3. Consulta 01: Filtragem por Faixa Salarial e Ordenacao

* **Objetivo:** Listar o nome, a função e o salário de todos os funcionários que ganham mais de R$ 4.500,00, ordenando o resultado pelo nome de forma crescente.

```sql

-- Execução da query com operador de maioridade
SELECT nome, funcao, salario 
FROM funcionarios 
WHERE salario > 4500.00
ORDER BY nome ASC;

```

### Resultado da Consulta 01

```text

      nome       |   funcao    |  salario  
-----------------+-------------+-----------
 Alice Silva     | Analista    |   5000.00
 Bruno Costa     | Supervisor  |   6000.00
(2 rows)

```

## 4. Consulta 02: Filtragem por Chave Estrangeira e Exclusao

* **Objetivo:** Consultar o código, o título e o ano das obras que pertencem ao salão de número 10, descartando registros que não atendam à condição.

```sql

-- Execução da query com operador de igualdade numérica
SELECT codigo, titulo, ano 
FROM obras 
WHERE salao = 10
ORDER BY ano DESC;

```

### Resultado da Consulta 02

```text

 codigo |            titulo            |  ano  
--------+------------------------------+-------
    501 | Monalisa Revisitada          |  2015
    502 | Noite Estrelada Moderna      |  2011
(2 rows)

```
