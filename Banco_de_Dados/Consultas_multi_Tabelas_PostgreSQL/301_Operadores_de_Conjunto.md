# Operadores de Conjunto

Este documento apresenta os conceitos e aplicações práticas dos operadores de conjunto na linguagem SQL, detalhando o funcionamento de UNION, INTERSECT e EXCEPT para a combinação vertical de resultados no SGBD PostgreSQL. 

## 1. Regras de Compatibilidade para Operações de Conjunto

* Os operadores de conjunto combinam verticalmente o resultado de duas ou mais consultas SELECT em uma única saída.
* **Quantidade de Colunas:** Todas as consultas envolvidas devem projetar exatamente o mesmo número de colunas.
* **Compatibilidade de Tipos:** As colunas nas posições correspondentes devem possuir tipos de dados compatíveis (ex: Texto com Texto).
* **Nomes dos Cabeçalhos:** Os nomes das colunas do resultado final são herdados exclusivamente da primeira instrução SELECT.
* **Remoção de Duplicidades:** Por padrão, as operações removem linhas duplicadas (comportamento DISTINCT). Para mantê-las, adiciona-se o modificador ALL.

## 2. Matriz de Comportamento dos Operadores

```text

Operador               Equivalência Matemática     Efeito Prático no Conjunto de Dados
UNION                  União (A ∪ B)               Agrupa os resultados de ambas as queries em uma única lista
INTERSECT              Intersecção (A ∩ B)         Retorna apenas os registros que existem simultaneamente nas duas listas
EXCEPT                 Diferença (A - B)           Retorna as linhas da primeira query que não existem na segunda

```

## 3. Preparação do Cenário de Dados para os Exemplos

```sql

-- Criação de duas tabelas de amostragem isoladas
CREATE TABLE clientes_ativos (
    email VARCHAR(100) PRIMARY KEY,
    nome VARCHAR(50) NOT NULL
);

CREATE TABLE leads_evento (
    email VARCHAR(100) PRIMARY KEY,
    nome VARCHAR(50) NOT NULL
);

-- Carga inicial de dados com registros sobrepostos
INSERT INTO clientes_ativos VALUES ('ana@email.com', 'Ana'), ('carlos@email.com', 'Carlos');
INSERT INTO leads_evento VALUES ('carlos@email.com', 'Carlos'), ('julia@email.com', 'Julia');

```

## 4. O Operador UNION (União de Listas)

* O operador UNION consolida os registros de ambas as tabelas em uma única listagem, eliminando as linhas repetidas automaticamente.
* O uso de UNION ALL unifica os dados sem realizar a checagem de duplicidade, oferecendo maior velocidade de processamento.

```sql

-- Retorna uma lista consolidada com todos os e-mails únicos (Ana, Carlos, Julia)
SELECT email, nome FROM clientes_ativos
UNION
SELECT email, nome FROM leads_evento;

-- Exemplo mantendo duplicidades (Carlos aparecerá duas vezes)
SELECT email, nome FROM clientes_ativos
UNION ALL
SELECT email, nome FROM leads_evento;

```

## 5. O Operador INTERSECT (Elementos Comuns)

* O operador INTERSECT atua como um filtro estrito de intersecção, isolando apenas os registros que constam em todas as tabelas consultadas.

```sql

-- Retorna apenas os registros presentes em ambas as tabelas (Carlos)
SELECT email, nome FROM clientes_ativos
INTERSECT
SELECT email, nome FROM leads_evento;

```

## 6. O Operador EXCEPT (Subtração de Conjuntos)

* O operador EXCEPT realiza a exclusão lógica, retornando os dados exclusivos da primeira consulta e subtraindo tudo o que for encontrado na segunda.

```sql

-- Retorna os clientes ativos que NÃO se cadastraram no evento (Ana)
SELECT email, nome FROM clientes_ativos
EXCEPT
SELECT email, nome FROM leads_evento;

```
