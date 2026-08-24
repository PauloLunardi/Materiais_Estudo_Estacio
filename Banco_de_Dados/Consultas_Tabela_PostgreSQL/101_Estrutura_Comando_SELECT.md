# Estrutura Basica de um Comando SELECT

Este documento apresenta os fundamentos da projecao de dados na linguagem SQL, detalhando a sintaxe essencial do comando SELECT, o encadeamento de suas principais clausulas operacionais e as diferentes formas de extrair informacoes de uma mesma tabela no SGBD PostgreSQL. 

## 1. Sintaxe Geral e Ordem de Processamento

* O comando SELECT e o instrumento de DQL responsavel por extrair conjuntos de resultados de tabelas sem modificar o banco.
* A sintaxe basica exige os termos SELECT para especificar as colunas e FROM para declarar a tabela de origem.
* O modificador opcional DISTINCT elimina linhas duplicadas do resultado, enquanto o termo ALL mantem a totalidade dos registros.
* Internamente, o motor do SGBD nao processa as clausulas na ordem de digitacao, iniciando a leitura pelo bloco FROM.

## 2. Encadeamento de Clausulas na Sintaxe Complexa

* A montagem de consultas avancadas envolve uma serie de clausulas e recursos bastante uteis para tratamento de dados:
* **WHERE:** Aplica um filtro booleano horizontal nas linhas da tabela antes que qualquer agregacao ocorra em memoria.
* **GROUP BY:** Agrupa os registros restantes que compartilham valores identicos nas colunas especificadas.
* **HAVING:** Funciona como um filtro condicional exclusivo para os grupos formados, atuando apos as funcoes de agregacao.
* **ORDER BY:** Determina a ordenacao final das linhas, podendo adotar o parametro ASC (crescente) ou DESC (decrescente).
* **LIMIT:** Restringe a quantidade maxima de linhas retornadas ao cliente, poupando processamento de rede.

## 3. Matriz de Sequencia Arquitetural do Processamento

```text

Ordem Lógica           |  Clausula Relacional    |  Papel no Motor do PostgreSQL
==================================================================================================================
1. Origem              |  FROM                   |  Identifica as tabelas base e processa juncoes JOIN
2. Filtragem Inicial   |  WHERE                  |  Descarta linhas que nao atendem aos criterios logicos
3. Agrupamento         |  GROUP BY               |  Divide o restante dos dados em grupos de afinidade
4. Filtragem de Grupo  |  HAVING                 |  Elimina grupos baseado no resultado de agregacoes (Ex: SUM, AVG)
5. Projecao            |  SELECT                 |  Determina as colunas finais e computa aliases ou expressoes
6. Ordenacao e Janela  |  ORDER BY / LIMIT       |  Ordena o resultado final e limita o tamanho do lote de entrega

```

## 4. Estruturas Distintas de SELECT para uma Mesma Tabela

* O SGBD permite formular diferentes combinacoes de projecoes dependendo do objetivo do relatorio ou da aplicacao:

```sql

-- Preparacao de cenario com tabela unica para demonstracao
CREATE TABLE empregado (
    id_emp INT PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    departamento VARCHAR(30) NOT NULL,
    salario NUMERIC(10,2) NOT NULL
);

INSERT INTO empregado (id_emp, nome, departamento, salario) VALUES
(1, 'Arthur Silva', 'TI', 5000.00),
(2, 'Beatriz Souza', 'TI', 6200.00),
(3, 'Carlos Mendes', 'RH', 4100.00),
(4, 'Daniela Rocha', 'RH', 3900.00);

-- ABORDAGEM A: Projecao total de colunas da tabela
SELECT * FROM empregado;

-- ABORDAGEM B: Projecao seletiva de campos e uso de Alias (Apelido)
SELECT nome AS funcionario, salario FROM empregado;

-- ABORDAGEM C: Projecao calculada com expressao matematica
SELECT nome, (salario * 13) AS rendimento_anual FROM empregado;

-- ABORDAGEM D: Extracao de dominios unicos com desduplicacao
SELECT DISTINCT departamento FROM empregado;

-- ABORDAGEM E: Consulta complexa com agregacao, filtro e agrupamento
SELECT departamento, AVG(salario) AS media_salarial
FROM empregado
WHERE salario > 3000.00
GROUP BY departamento
HAVING AVG(salario) > 4000.00
ORDER BY media_salarial DESC
LIMIT 5;

```

## 5. Concatenacao de Colunas e Strings em SQL

* A concatenacao unifica dois ou mais campos de texto ou literais em uma unica string de saida no relatorio.
* O operador nativo padrao do PostgreSQL para concatenar valores e composto por duas barras verticais ||.
* A funcao embutida CONCAT() realiza o mesmo papel, tratando automaticamente valores nulos sem invalidar a expressao.
* Este recurso e comumente aplicado para formatar dados de exibicao, unindo nomes, sobrenomes ou codigos estruturados.

```sql

-- Exemplo de concatenacao utilizando o operador nativo ||
SELECT nome || ' trabalha no departamento de ' || departamento AS alocacao_funcionario 
FROM empregado;

-- Exemplo alternativo utilizando a funcao nativa CONCAT
SELECT CONCAT(nome, ' - Salario: R$ ', salario) AS informativo_remuneracao 
FROM empregado;

--Exemplo Concatenação de Colunas e Strings (ou Concatenação de Literais com Campos).
-- O comando SELECT extrai dados da tabela ALUNO.
-- O operador || (duas barras verticais) realiza a concatenação de strings.
-- Ele junta o texto estático 'NOME ALUNO: ' com o conteúdo da coluna NOME,
-- adiciona um espaço em branco ' ', concatena o texto 'EMAIL: ' 
-- e finaliza juntando o conteúdo da coluna EMAIL de cada linha.
SELECT 'NOME ALUNO: ' || NOME || ' ' || 'EMAIL: ' || EMAIL FROM ALUNO;


```

## 6. Uso do Comando SELECT Sem a Clausula FROM

* O PostgreSQL permite a execucao do comando SELECT omitindo por completo a clausula de origem FROM.
* Esta abordagem serve para avaliar funcoes do sistema, testar expressoes matematicas ou obter constantes de data.
* O comportamento difere de outros SGBDs que exigem uma tabela virtual de sistema (como a tabela DUAL no Oracle).
* A query e resolvida de forma imediata pelo interpretador de comandos (Traffic Cop) sem acessar tabelas fisicas em disco.

```sql

-- Consulta para obter a data e hora atual do servidor do banco
SELECT CURRENT_TIMESTAMP AS horario_servidor;

-- Uso do SELECT para resolucao de operacoes matematicas estaticas
SELECT (450 * 1.15) / 2 AS resultado_calculo_teste;

-- Retorno de funcoes de formatacao ou manipulacao de strings
SELECT UPPER('banco de dados objeto-relacional') AS texto_caixa_alta;

```
