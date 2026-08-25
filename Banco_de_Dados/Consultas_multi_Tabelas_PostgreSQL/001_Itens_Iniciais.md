# FUNDAMENTOS DE CONSULTAS COM MULTIPLAS TABELAS NO POSTGRESQL

1. PREPARACAO E OBJETIVOS DE APRENDIZADO
-------------------------------------------------------------------------------
* Certifique-se de ter baixado e instalado o SGBD PostgreSQL em seu computador.
* Aplique consultas estruturadas envolvendo operacoes de juncao interior.
  - Exemplo: INNER JOIN.
* Aplique consultas estruturadas envolvendo operacoes de juncao exterior.
  - Exemplo: LEFT, RIGHT e FULL OUTER JOIN.
* Aplique subconsultas avancadas nas modalidades aninhadas e correlatas.
* Aplique consultas combinadas com o uso de operadores de conjunto.
  - Exemplos: UNION, INTERSECT e EXCEPT.


## 2. MATRIZ DE COMPONENTES DE CONSULTAS MULTI-TABELAS

* RECURSO: INNER JOIN
  - Operacao: Juncao interna por chaves correspondentes.
  - Objetivo: Cruzar linhas que possuem equivalencia nas duas tabelas.

* RECURSO: OUTER JOIN
  - Operacao: Juncao externa esquerda, direita ou total.
  - Objetivo: Preservar registros orfaos de um dos lados da juncao.

* RECURSO: SUBCONSULTA
  - Operacao: Query aninhada dentro de outra instrucao principal.
  - Objetivo: Gerar filtros ou massas de dados dinamicos em tempo de execucao.

* RECURSO: OPERADORES DE CONJUNTO
  - Operacao: Combinacao vertical de tabelas.
  - Objetivo: Unificar, interceptar ou subtrair conjuntos de resultados.


## 3. IMPORTANCIA PRATICA DA INTEGRACAO DE TABELAS

* A normalizacao de dados divide as informacoes em entidades isoladas.
* O processo evita redundancias e anomalias de atualizacao no sistema.
* A recuperacao de relatorios exige a reconstrucao dessas tabelas.
* O motor do SGBD utiliza algoritmos internos de alta performance.
  - Exemplos: Hash Join e Merge Join para conectar milhoes de registros.
* Dominar juncoes permite extrair inteligencia direta da camada de dados.

## 4. EXEMPLO PRATICO DE APLICACAO DE JUNCAO BASICA

```sql

-- Criacao da tabela mae de categorias
CREATE TABLE categoria (
    id_categoria SERIAL PRIMARY KEY,
    nome_categoria VARCHAR(50) NOT NULL
);

-- Criacao da tabela filha com vinculo relacional
CREATE TABLE produto_item (
    id_item SERIAL PRIMARY KEY,
    nome_item VARCHAR(50) NOT NULL,
    fk_categoria INT REFERENCES categoria(id_categoria)
);

-- Carga inicial de dados para os testes
INSERT INTO categoria (nome_categoria) VALUES ('Eletronicos'), ('Moveis');
INSERT INTO produto_item (nome_item, fk_categoria) VALUES ('Smartphone A', 1), ('Cadeira B', 2);

-- CONSULTA INTEGRADA: Cruzamento de dados por correspondencia de chaves
SELECT p.nome_item, c.nome_categoria
FROM produto_item p
INNER JOIN categoria c ON p.fk_categoria = c.id_categoria;

```
