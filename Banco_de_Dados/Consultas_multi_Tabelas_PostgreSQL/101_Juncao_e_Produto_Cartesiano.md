# Juncao e Produto Cartesiano

Este documento apresenta os fundamentos teoricos e praticos da integracao de dados em bancos de dados relacionais, detalhando o funcionamento das operacoes de juncao interna, externa e o comportamento do produto cartesiano no SGBD PostgreSQL. 

## 1. Operacao de Juncao de Tabelas

* A operacao de juncao permite reconstruir as relacoes logicas entre tabelas separadas pelo processo de normalizacao.
* A associacao dos dados ocorre por meio do cruzamento entre colunas comuns, geralmente chaves primarias e estrangeiras.
* O motor do SGBD utiliza a clausula ON para avaliar as condicoes de correspondencia estipuladas na query.
* A utilizacao correta de juncoes evita o retorno de dados inconsistentes ou duplicidades nos relatorios.

## 2. Tipos de Juncao: INNER JOIN e OUTER JOIN

* **INNER JOIN (Juncao Interna):** Retorna os registros apenas se houver correspondencia exata entre as duas tabelas envolvidas. Se uma linha nao encontrar equivalencia na tabela associada, ela sera completamente descartada do resultado final.
* **OUTER JOIN (Juncao Externa):** Preserva os registros de uma ou de ambas as tabelas, mesmo que nao existam dados correspondentes do outro lado. As colunas que ficarem sem correspondencia sao preenchidas automaticamente com valores nulos (NULL).

## 3. Matriz de Categorias de Juncao Externa

```text

Sintaxe do Comando     Comportamento Tecnico no Motor do PostgreSQL
LEFT OUTER JOIN        Preserva todas as linhas da tabela da esquerda e traz apenas os pares da direita
RIGHT OUTER JOIN       Preserva todas as linhas da tabela da direita e traz apenas os pares da esquerda
FULL OUTER JOIN        Preserva a totalidade dos registros de ambas as tabelas (Uniao das duas abordagens)

```

## 4. Operacao de Produto Cartesiano

* O produto cartesiano ocorre quando combinamos todas as linhas da primeira tabela com todas as linhas da segunda tabela.
* Esta operacao e gerada nativamente quando omitimos a clausula de ligacao ON ou usamos o comando CROSS JOIN.
* O volume total de linhas gerado no resultado final equivale a multiplicacao da quantidade de linhas das duas tabelas.
* Em bancos de dados de producao, o produto cartesiano acidental causa alto consumo de memoria RAM e travamento do SGBD.

## 5. Exemplos Praticos de Juncao e Produto Cartesiano

```sql

-- Cenario basico para execucao dos testes relacionais
CREATE TABLE filial (
    id_filial INT PRIMARY KEY,
    nome_filial VARCHAR(30) NOT NULL
);

CREATE TABLE gestor (
    id_gestor INT PRIMARY KEY,
    nome_gestor VARCHAR(30) NOT NULL,
    fk_filial INT
);

INSERT INTO filial (id_filial, nome_filial) VALUES (1, 'Sao Paulo'), (2, 'Rio de Janeiro');
INSERT INTO gestor (id_gestor, nome_gestor, fk_filial) VALUES (10, 'Carlos', 1), (20, 'Ana', NULL);

-- 1. EXEMPLO DE INNER JOIN (Traz apenas o gestor Carlos e a filial Sao Paulo)
SELECT g.nome_gestor, f.nome_filial
FROM gestor g
INNER JOIN filial f ON g.fk_filial = f.id_filial;

-- 2. EXEMPLO DE LEFT OUTER JOIN (Preserva a gestora Ana, trazendo a filial como NULL)
SELECT g.nome_gestor, f.nome_filial
FROM gestor g
LEFT OUTER JOIN filial f ON g.fk_filial = f.id_filial;

-- 3. EXEMPLO DE PRODUTO CARTESIANO (Gera 4 linhas no total: 2 filiais x 2 gestores)
SELECT g.nome_gestor, f.nome_filial
FROM gestor g
CROSS JOIN filial f;

```
