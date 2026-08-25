# Juncao Interna

Este documento apresenta os conceitos, sintaxes e aplicacoes praticas da operacao de juncao interna (INNER JOIN) no SGBD PostgreSQL, demonstrando o uso das clausulas ON e USING para estabelecer a correspondencia de chaves. 

## 1. Conceito e Funcionamento do INNER JOIN

* O INNER JOIN e o mecanismo padrao para cruzar dados de duas tabelas com base em uma condicao de igualdade.
* O motor do SGBD compara os registros e retorna apenas as linhas que possuem correspondencia exata em ambas as tabelas.
* Caso uma linha da primeira tabela nao encontre um par correspondente na segunda tabela, ela e omitida do resultado.
* A palavra-chave INNER e opcional na sintaxe ANSI SQL, sendo interpretada automaticamente ao declarar apenas JOIN.

## 2. Analise da Sintaxe Estruturada do Comando

* A estrutura basica aceita duas formas de declaracao para a condicao de ligacao:
* **Clausula ON:** Utilizada para especificar explicitamente a condicao logica de juncao entre as colunas, mesmo que possuam nomes diferentes.
* **Clausula USING:** Funciona como uma alternativa simplificada quando as colunas de juncao possuem exatamente o mesmo nome em ambas as tabelas.

```text

Sintaxe Geral Aceita Pelo Interpretador do SGBD:
SELECT * FROM TABELA1 [INNER] JOIN TABELA2 ON (CONDIÇÃOJUNÇÃO) [USING (COLUNA_DE_JUNÇÃO)]

```

## 3. Diferencas e Regras de Uso: ON vs. USING

```text

Criterio Tecnico       Uso da Clausula ON          Uso da Clausula USING
Nomes das Colunas      Podem ser diferentes ou iguais Devem ser estritamente identicos
Sintaxe de Operadores  Exige operador explicito (Ex: =) Omiti o operador e os nomes das tabelas
Colunas Duplicadas     Mantem as duas colunas na saida Agrupa automaticamente em uma unica coluna
Flexibilidade          Alta (Permite comparacoes complexas) Restrita a igualdade direta de chaves

```

## 4. Exemplos Praticos de Juncao Interna

```sql

-- Cenario estrutural para teste das variacoes de sintaxe
CREATE TABLE departamento (
    id_depto INT PRIMARY KEY,
    nome_depto VARCHAR(50) NOT NULL
);

CREATE TABLE colaborador (
    id_colab INT PRIMARY KEY,
    nome_colab VARCHAR(50) NOT NULL,
    id_depto INT REFERENCES departamento(id_depto) -- Nome identico para teste do USING
);

INSERT INTO departamento (id_depto, nome_depto) VALUES (1, 'Tecnologia'), (2, 'Financeiro');
INSERT INTO colaborador (id_colab, nome_colab, id_depto) VALUES (10, 'Rodrigo', 1), (20, 'Beatriz', 2);

-- ABORDAGEM A: Uso tradicional com a clausula ON
SELECT c.nome_colab, d.nome_depto
FROM colaborador c
INNER JOIN departamento d ON c.id_depto = d.id_depto;

-- ABORDAGEM B: Uso simplificado com a clausula USING
-- Nota: Nao se deve usar prefixos/aliases de tabela na coluna declarada dentro do USING
SELECT nome_colab, nome_depto
FROM colaborador
INNER JOIN departamento USING (id_depto);

```
