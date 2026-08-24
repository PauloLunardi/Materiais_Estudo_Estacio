# Funcoes de Resumo ou de Agregacao

Este documento apresenta as funcoes estatisticas e de agrupamento nativas do SGBD PostgreSQL, demonstrando a aplicacao de agregacoes numericas, mensuracao de dispersao e a consolidacao de dados calculados em uma unica linha de retorno. 

## 1. Conceito de Agregacao de Dados

* As funcoes de resumo processam um conjunto de valores de uma coluna e retornam um unico valor consolidado.
* O motor do SGBD ignora valores nulos (NULL) no calculo da maioria das funcoes, com excecao do COUNT(*).
* A aplicacao destas funcoes sem a clausula GROUP BY resulta obrigatoriamente em uma unica linha de resposta.
* As operacoes podem receber expressoes matematicas complexas internas como argumento de processamento.

## 2. Matriz de Funcoes e Retornos Estatisticos

```text

Funcao                      O que retorna?                              Aplicabilidade Tecnica
COUNT(*)                    numero de linhas da consulta                Contagem total incluindo nulos e duplicados
MIN(COLUNA/EXPRESSAO)       menor valor de uma coluna ou expressao      Identificacao de extremos minimos
AVG(COLUNA/EXPRESSAO)       valor medio da coluna ou expressao          Calculo de media aritmetica simples
MAX(COLUNA/EXPRESSAO)       maior valor de uma coluna ou expressao      Identificacao de extremos maximos
SUM(COLUNA/EXPRESSAO)       soma dos valores de uma coluna ou expressao Acumulacao totalizadora de valores
STDDEV(COLUNA/EXPRESSAO)    desvio-padrao dos valores de uma coluna     Mensuracao de dispersao em relacao a media
VARIANCE(COLUNA/EXPRESSAO)  variancia dos valores de uma coluna         Quadrado do desvio-padrao para analise estatistica

```

## 3. Exemplo Pratico de Consolidacao e Calculos

* O script abaixo demonstra a criacao do cenario e a aplicacao simultanea das funcoes de resumo combinadas com expressoes de data e hora.

```sql

-- Cenario de dados compartilhado pelas consultas
-- CREATE TABLE ALUNO (NOME VARCHAR(50), DTNASCIMENTO DATE);

-- Execucao de multiplas agregacoes estruturadas
SELECT
    COUNT(*) AS "Número de alunos",
    MIN(EXTRACT(YEAR FROM AGE(DTNASCIMENTO))) AS "Menor Idade",
    AVG(EXTRACT(YEAR FROM AGE(DTNASCIMENTO))) AS "Idade Média",
    MAX(EXTRACT(YEAR FROM AGE(DTNASCIMENTO))) AS "Maior Idade",
    SUM(EXTRACT(YEAR FROM AGE(DTNASCIMENTO)))/COUNT(*) AS "Idade Média Alternativa"
FROM ALUNO;

```

## 4. Listando Resumos em Uma Linha

* A centralizacao de metricas em uma unica linha reduz o overhead de rede ao transferir dados para a aplicacao.
* O PostgreSQL computa todas as funcoes declaradas em um unico escaneamento sequencial ou de indice da tabela.
* A expressao combinada SUM(Expressao)/COUNT(*) resulta matematicamente no mesmo valor da funcao nativa AVG().
* Nao e permitido projetar colunas atomicas convencionais junto com funcoes de resumo sem a presenca do GROUP BY.

```sql

-- Consulta focada em metricas de dispersao avancadas condensadas em uma unica linha
SELECT 
    COUNT(DISTINCT NOME) AS "Qtd Alunos Unicos",
    ROUND(STDDEV(EXTRACT(YEAR FROM AGE(DTNASCIMENTO))), 2) AS "Desvio-Padrão Idade",
    ROUND(VARIANCE(EXTRACT(YEAR FROM AGE(DTNASCIMENTO))), 2) AS "Variância Idade"
FROM ALUNO;

```
