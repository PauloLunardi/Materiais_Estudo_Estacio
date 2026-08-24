# Funcoes de Data e Hora

Este documento apresenta o mapeamento das funcoes nativas de data e hora do SGBD PostgreSQL, demonstrando a sintaxe de extracao de subcampos, a identificacao nominal de dias da semana e rotinas de calculo de idade e faixa etaria, comparando diferentes abordagens de codificacao. 

## 1. Funcoes de Tempo do Sistema

* As funcoes temporais nativas capturam as metricas diretamente do relogio operacional do servidor.
* O comando SELECT sem a clausula FROM e amplamente utilizado para testar o retorno destas funcoes.
* A precisao dos timestamps inclui milissegundos e informacoes de fuso horario configurados no cluster.
* O uso de apelidos (AS) delimitados por aspas duplas permite criar nomes de cabecalhos com espacos e caracteres especiais.

## 2. Matriz de Funcoes e Retornos Nativos

```text

Funcao                      O que retorna?              Exemplo de Saida Tecnica
current_date                data de hoje                2026-08-24
current_time                hora do dia                 15:55:01.123456-03
current_timestamp           data e a hora               2026-08-24 15:55:01.123456-03
extract (campo from fonte)  subcampos de data e hora    2026 (se campo for 'year')

```

## 3. Exemplos Praticos das Funcoes do Sistema

```sql

-- Abordagem padrao com metadados adicionais de calendario
SELECT 
    CURRENT_DATE AS "Data Atual",
    CURRENT_TIME AS "Hora Atual",
    CURRENT_TIMESTAMP AS "Data e Hora atuais",
    EXTRACT(DOY FROM CURRENT_DATE) AS "Dia do ano", -- Retorna o dia cardinal do ano (1 a 366)
    EXTRACT(DOW FROM CURRENT_DATE) AS "Dia da semana", -- DOW 0 - domingo, 1 - segunda, ..., 6 - sábado
    EXTRACT(DAY FROM CURRENT_DATE) AS "Dia Atual",
    EXTRACT(MONTH FROM CURRENT_DATE) AS "Mês Atual",
    EXTRACT(YEAR FROM CURRENT_DATE) AS "Ano Atual",
    EXTRACT(CENTURY FROM CURRENT_DATE) AS "Século Atual";

```

## 4. Exibindo o Nome do Dia da Semana

* **Abordagem A (Conversao via TO_CHAR):** Utiliza uma funcao embutida de formatacao de strings. E mais concisa, porem retorna o nome baseado na configuracao regional (LC_TIME) ativa no cluster ou em ingles por padrao.
* **Abordagem B (Mapeamento Logico com CASE WHEN):** Avalia o indice do EXTRACT(DOW...). Garante o retorno textual personalizado em portugues exato independente do idioma do servidor do banco.

```sql

-- Abordagem A: Exibicao via formatacao nativa de string
SELECT TO_CHAR(current_date, 'Day') AS nome_dia_semana;

-- Abordagem B: Controle condicional explicito em portugues
SELECT CASE 
    WHEN EXTRACT(DOW FROM CURRENT_DATE) = 0 THEN 'domingo'
    WHEN EXTRACT(DOW FROM CURRENT_DATE) = 1 THEN 'segunda-feira'
    WHEN EXTRACT(DOW FROM CURRENT_DATE) = 2 THEN 'terça-feira'
    WHEN EXTRACT(DOW FROM CURRENT_DATE) = 3 THEN 'quarta-feira'
    WHEN EXTRACT(DOW FROM CURRENT_DATE) = 4 THEN 'quinta-feira'
    WHEN EXTRACT(DOW FROM CURRENT_DATE) = 5 THEN 'sexta-feira'
    WHEN EXTRACT(DOW FROM CURRENT_DATE) = 6 THEN 'sábado'
END AS "Nome do dia da semana";

```

## 5. Calculando Idade e Classificacao de Faixa Etaria

* **Caso Simplificado (Filtro Booleano):** Realiza uma divisao binaria (Maior/Menor) baseada em uma condicao de corte direta.
* **Caso Avancado (Agrupamento por Faixas):** Utiliza operadores de intervalo fechado BETWEEN ... AND para criar segmentacoes estatisticas granulares ideais para relatorios e dashboards.

```sql

-- Cenario de dados compartilhado pelas consultas
-- CREATE TABLE ALUNO (NOME VARCHAR(50), DTNASCIMENTO DATE);

-- Caso 1: Filtro simples binario
SELECT 
    NOME,
    EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) AS anos_de_idade,
    CASE 
        WHEN EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) < 18 THEN 'Menor de Idade'
        ELSE 'Maior de Idade'
    END AS faixa_etaria
FROM ALUNO;

-- Caso 2: Segmentacao avançada e categorizada por multiplas faixas etarias
SELECT 
    NOME,
    EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) AS "Idade do Aluno",
    CASE 
        WHEN EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) <= 20 THEN '1. até 20 anos'
        WHEN EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) BETWEEN 21 AND 30 THEN '2. 21 a 30 anos'
        WHEN EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) BETWEEN 31 AND 40 THEN '3. 31 a 40 anos'
        WHEN EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) BETWEEN 41 AND 50 THEN '4. 41 a 50 anos'
        WHEN EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) BETWEEN 51 AND 60 THEN '5. 51 a 60 anos'
        WHEN EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) > 60 THEN '6. mais de 60 anos'
    END AS "Faixa Etária"
FROM ALUNO;

```
