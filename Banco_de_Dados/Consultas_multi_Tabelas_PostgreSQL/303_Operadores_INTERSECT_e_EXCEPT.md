# Consultas com os Operadores INTERSECT e EXCEPT

Este documento apresenta a sintaxe formal e a aplicação prática dos operadores de conjunto INTERSECT e EXCEPT no SGBD PostgreSQL, detalhando o comportamento das cláusulas adicionais DISTINCT e ALL para o controle de linhas duplicadas. 

## 1. O Operador INTERSECT (Interseccao de Resultados)

* O operador INTERSECT retorna apenas as linhas que estão presentes simultaneamente em ambas as consultas SELECT.
* **INTERSECT / INTERSECT DISTINCT:** É o comportamento padrão do SGBD. Ele compara os dois conjuntos de dados, isola os registros comuns e elimina todas as duplicadas da saída final.
* **INTERSECT ALL:** Mantém as duplicadas de forma controlada por frequência. Se uma linha aparece 𝑋 vezes na primeira tabela e 𝑌 vezes na segunda, ela retornará exatamente 𝑚𝑖𝑛(𝑋,𝑌) vezes no resultado final.

## 2. Exemplos Praticos com o Operador INTERSECT

```sql

-- Estruturacao de tabelas para simulacao de registros repetidos
CREATE TABLE inscritos_palestra (nome VARCHAR(50));
CREATE TABLE inscritos_workshop (nome VARCHAR(50));

-- Carlos aparece duplicado na palestra e uma vez no workshop. Ana aparece uma vez em ambos.
INSERT INTO inscritos_palestra VALUES ('Carlos'), ('Carlos'), ('Ana'), ('Beatriz');
INSERT INTO inscritos_workshop VALUES ('Carlos'), ('Ana'), ('Ana'), ('Daniel');

-- 1. Exemplo com INTERSECT / INTERSECT DISTINCT
-- Retorna apenas uma linha para Carlos e uma para Ana (Elimina duplicadas)
SELECT nome FROM inscritos_palestra
INTERSECT DISTINCT
SELECT nome FROM inscritos_workshop;

-- 2. Exemplo com INTERSECT ALL
-- Aplica a regra de frequencia minima: Carlos aparece 1 vez, Ana aparece 1 vez
SELECT nome FROM inscritos_palestra
INTERSECT ALL
SELECT nome FROM inscritos_workshop;

```

## 3. O Operador EXCEPT (Subtracao de Resultados)

* O operador EXCEPT realiza a exclusão lógica, retornando os registros da primeira consulta que não existem na segunda.
* **EXCEPT / EXCEPT DISTINCT:** É o comportamento padrão. Ele remove todas as ocorrências de linhas da primeira tabela que correspondam a qualquer registro da segunda tabela, desduplicando o resultado final.
* **EXCEPT ALL:** Remove as duplicadas por subtração de frequência. Se uma linha aparece 𝑋 vezes na primeira tabela e 𝑌 vezes na segunda, ela retornará no resultado exatamente 𝑚𝑎𝑥(0,𝑋−𝑌) vezes.

## 4. Exemplos Praticos com o Operador EXCEPT

```sql

-- Utilizando o mesmo cenario de dados carregado no item 2

-- 3. Exemplo com EXCEPT / EXCEPT DISTINCT
-- Retorna apenas 'Beatriz' (Carlos e Ana sao totalmente removidos porque constam na segunda tabela)
SELECT nome FROM inscritos_palestra
EXCEPT DISTINCT
SELECT nome FROM inscritos_workshop;

-- 4. Exemplo com EXCEPT ALL
-- Aplica a subtracao de frequencia: 
-- Carlos (2 na palestra - 1 no workshop = 1) -> Retorna 1 vez
-- Ana (1 na palestra - 2 no workshop = 0) -> Nao retorna
-- Beatriz (1 na palestra - 0 no workshop = 1) -> Retorna 1 vez
SELECT nome FROM inscritos_palestra
EXCEPT ALL
SELECT nome FROM inscritos_workshop;

```

## 5. Matriz de Comportamento dos Modificadores de Conjunto

```text

Operador Base            Modificador Adicional       Impacto nas Linhas Duplicadas do Resultado
INTERSECT                DISTINCT (Padrao)           Garante apenas registros comuns exclusivos (Sem repeticao)
INTERSECT                ALL                         Mantem a menor frequencia comum entre os conjuntos
EXCEPT                   DISTINCT (Padrao)           Garante apenas registros exclusivos da primeira query (Sem repeticao)
EXCEPT                   ALL                         Reduz a frequencia da primeira query com base na segunda

```
