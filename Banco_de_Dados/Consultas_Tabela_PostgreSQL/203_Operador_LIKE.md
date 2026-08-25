# Recuperando Dados com o Uso do Operador LIKE

Este documento apresenta as tecnicas de busca e correspondencia de padroes de texto (Pattern Matching) no SGBD PostgreSQL, detalhando o funcionamento do operador LIKE, os caracteres curinga de busca e exemplos praticos de consultas baseadas em uma tabela de alunos. 

## 1. Padroes de Busca com o Operador [NOT] LIKE

* O operador LIKE permite realizar buscas em uma cadeia de caracteres comparando uma coluna de texto com um padrao especifico.
* A busca e sensivel a maiusculas e minusculas (Case Sensitive) no padrao ANSI SQL tradicional do PostgreSQL.
* O modificador NOT LIKE inverte o criterio, retornando apenas as linhas que nao casam com o padrao definido.
* Para realizar a correspondencia de padroes flexiveis, utilizam-se obrigatoriamente dois caracteres curinga nativos:
* **_ (Sublinhado):** Utilizado para ignorar qualquer caractere especifico em uma posicao exata da string (Mapeia exatamente um caractere).
* **% (Percentual):** Utilizado para ignorar qualquer padrao ou sequencia de caracteres (Mapeia zero, um ou multiplos caracteres).

## 2. Matriz de Comportamento dos Caracteres Curinga

```text

Sintaxe do Padrao      Significado Tecnico da Busca                Exemplo de Casamento Valido
'A%'                   Inicia obrigatoriamente com a letra A       'ANA', 'ARTHUR', 'ALBERTO'
'%A'                   Termina obrigatoriamente com a letra A      'AMANDA', 'MARIA', 'LUCAS' (FALSO)
'%MARIA%'              Contem a palavra MARIA em qualquer posicao  'ANA MARIA SOUZA', 'MARIANA'
'_A%'                  Possui a letra A estritamente na 2ª posicao 'CARLOS', 'MARCOS', 'ANTONIO' (FALSO)

```

## 3. Consulta 05: Uso Geral do LIKE (Busca Inicial)

* **Objetivo:** Listar o nome e o e-mail de todos os alunos cujo nome comece com a letra "M".

```sql

-- Execucao da query utilizando o curinga de sufixo %
SELECT nome, email 
FROM aluno 
WHERE nome LIKE 'M%'
ORDER BY nome ASC;

```

### Resultado da Consulta 05

```text

       nome        |         email          
-------------------+------------------------
 Mariana Fontes    | mariana@gmail.com
 Marcos Souza      | marcos.souza@yahoo.com
(2 rows)

```

## 4. Consulta 06: Filtragem por Posicao Especifica (_)

* **Objetivo:** Listar o nome dos alunos que possuem a letra “A” na segunda posicao do nome.

```sql

-- Execucao da query utilizando o curinga de caractere unico na primeira posicao
SELECT nome 
FROM aluno 
WHERE nome LIKE '_A%'
ORDER BY nome ASC;

```

### Resultado da Consulta 06

```text

       nome        
-------------------
 Carlos Augusto
 Mariana Fontes
(2 rows)

```

## 5. Consulta 07: Exclusao de Cadeia de Texto (NOT LIKE)

* **Objetivo:** Listar o nome e a data de nascimento dos alunos que nao possuem a string “MARIA” fazendo parte do nome.

```sql

-- Execucao da query com inversao de lógica de padrao
SELECT nome, dtnascimento 
FROM aluno 
WHERE nome NOT LIKE '%MARIA%'
ORDER BY nome ASC;

```

### Resultado da Consulta 07

```text

       nome        | dtnascimento 
-------------------+--------------
 Carlos Augusto    | 1998-05-12
 Marcos Souza      | 1991-10-25
 Pedro Alcantar    | 1995-03-15
(3 rows)

```

## 6. Consulta 08: Contagem de Ocorrencias e Sufixos

* **Objetivo:** Quantos alunos possuem conta de e-mail no Gmail?

```sql

-- Execucao de agregacao baseada na busca pelo dominio do e-mail
SELECT COUNT(*) AS "Quantidade de Alunos Gmail" 
FROM aluno 
WHERE email LIKE '%@gmail.com';

```

### Resultado da Consulta 08

```text

 Quantidade de Alunos Gmail 
----------------------------
                          3
(1 row)

```
