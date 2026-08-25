# Recuperando Dados com o Uso do Operador NULL e Usando Ordenacao

Este documento apresenta as tecnicas de identificacao de valores ausentes (NULL) e a estruturacao de criterios de ordenacao simples e multipla no SGBD PostgreSQL, demonstrando a aplicacao pratica atraves de consultas e seus respectivos resultados. 

## 1. Recuperando Dados com o Uso do Operador NULL

* O valor NULL representa a ausencia de informacao ou um dado desconhecido no banco de dados.
* Devido a sua natureza desconhecida, operacoes matematicas ou relacionais comuns (como = NULL ou <> NULL) retornam UNKNOWN.
* Para testar a existencia ou ausencia de valores nulos, a sintaxe SQL exige o uso dos operadores exclusivos IS NULL e IS NOT NULL.
* O motor do SGBD avalia a presenca do marcador e filtra as linhas horizontais conforme a expressao booleana.

## 2. Consulta 09 e 10: Tratativa de Dados Nativos (IS [NOT] NULL)

* **Consulta 09:** Para listar o nome, a data de nascimento e o e-mail dos alunos que têm endereço eletrônico cadastrado.

```sql

-- Execucao da query com o filtro IS NOT NULL
SELECT nome, dtnascimento, email 
FROM aluno 
WHERE email IS NOT NULL
ORDER BY nome ASC;

```

### Resultado da Consulta 09

```text

       nome        | dtnascimento |         email          
-------------------+--------------+------------------------
 Ana Maria Souza   | 2000-01-10   | anamaria@gmail.com
 Marcos Souza      | 1991-10-25   | marcos.souza@yahoo.com
 Mariana Fontes    | 2012-07-20   | mariana@gmail.com
(3 rows)

```

* **Consulta 10:** Para retornar o nome dos alunos sem e-mail cadastrado no banco de dados.

```sql

-- Execucao da query com o filtro IS NULL
SELECT nome 
FROM aluno 
WHERE email IS NULL
ORDER BY nome ASC;

```

### Resultado da Consulta 10

```text

       nome        
-------------------
 Carlos Augusto
 Pedro Alcantar
(2 rows)

```

## 3. Recuperando Dados Usando Ordenacao dos Resultados

* Para organizar os resultados de uma consulta, podemos especificar criterios de ordenacao por meio da clausula ORDER BY.
* O modificador ASC realiza a ordenacao de forma ascendente (padrao), enquanto o DESC ordena de forma descendente.
* E permitido ordenar os registros utilizando colunas fisicas, funcoes calculadas ou expressoes de data e hora.
* Quando multiplas colunas sao declaradas, o SGBD desempatara a ordenacao seguindo estritamente a precedencia da esquerda para a direita.

## 4. Consulta 11: Ordenacao Unica e Ascendente

* **Objetivo:** Para retornar o nome e a data de nascimento dos alunos, ordenando os resultados por nome, de maneira ascendente.

```sql

-- Execucao da query com ordenacao simples por string
SELECT nome, dtnascimento 
FROM aluno 
ORDER BY nome ASC;

```

### Resultado da Consulta 11

```text

       nome        | dtnascimento 
-------------------+--------------
 Ana Maria Souza   | 2000-01-10
 Carlos Augusto    | 1998-05-12
 Marcos Souza      | 1991-10-25
 Mariana Fontes    | 2012-07-20
 Pedro Alcantar    | 1995-03-15
(5 rows)

```

## 5. Consulta 12: Ordenacao Multipla com Funcoes Cronologicas

* **Objetivo:** Para retornar o nome e a data de nascimento dos alunos, ordenando os resultados de modo ascendente pelo mês de nascimento e, em seguida, pelo nome, também de modo ascendente.

```sql

-- Execucao de ordenacao composta utilizando a funcao EXTRACT
SELECT nome, dtnascimento 
FROM aluno 
ORDER BY EXTRACT(MONTH FROM dtnascimento) ASC, nome ASC;

```

### Resultado da Consulta 12

```text

       nome        | dtnascimento 
-------------------+--------------
 Ana Maria Souza   | 2000-01-10 -- Mes 01 (Janeiro)
 Carlos Augusto    | 1998-05-12 -- Mes 05 (Maio)
 Mariana Fontes    | 2012-07-20 -- Mes 07 (Julho)
 Pedro Alcantar    | 1995-03-15 -- Mes 03 (Março)
 Marcos Souza      | 1991-10-25 -- Mes 10 (Outubro)
(5 rows)

```
