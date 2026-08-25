# Juncao Externa

Este documento apresenta os conceitos, sintaxes e aplicacoes praticas das operacoes de juncao externa (OUTER JOIN) no SGBD PostgreSQL, demonstrando como preservar registros sem correspondencia por meio de Left, Right e Full Join. 

## 1. O Desafio dos Dados Sem Correspondência

* A juncao interna tradicional (INNER JOIN) descarta automaticamente qualquer linha que nao encontre um par correspondente.
* E se quisessemos incluir na listagem todos os registros da tabela CURSO? Mesmo aqueles que nao possuem nenhuma disciplina vinculada?
* A solucao arquitetural consiste em utilizar as juncoes externas, que forcam a exibicao de registros orfaos de uma ou de ambas as tabelas.
* As colunas da tabela associada que ficarem sem dados correspondentes sao preenchidas de forma automatica com valores nulos (NULL).

## 2. Matriz de Variacoes de Juncao Externa

```text

Comando SQL            Direcao da Preservacao      Comportamento no Motor do PostgreSQL
LEFT [OUTER] JOIN      Juncao a Esquerda           Mantem todas as linhas da tabela da esquerda (declarada primeiro)
RIGHT [OUTER] JOIN     Juncao a Direita            Mantem todas as linhas da tabela da direita (declarada por ultimo)
FULL [OUTER] JOIN      Juncao Total                Mantem todos os registros de ambas as tabelas (Uniao dos dois lados)

```

## 3. Exemplos Praticos de Left, Right e Full Join

```sql

-- Cenario basico para execucao dos testes relacionais
CREATE TABLE curso (
    id_curso INT PRIMARY KEY,
    nome_curso VARCHAR(50) NOT NULL
);

CREATE TABLE disciplina (
    id_disc INT PRIMARY KEY,
    nome_disc VARCHAR(50) NOT NULL,
    fk_curso INT REFERENCES curso(id_curso)
);

INSERT INTO curso (id_curso, nome_curso) VALUES (1, 'Sistemas de Informacao'), (2, 'Direito');
INSERT INTO disciplina (id_disc, nome_disc, fk_curso) VALUES (10, 'Banco de Dados', 1), (20, 'Direito Penal', NULL);

-- 1. Usando Juncao LEFT JOIN (Inclui todos os cursos, mesmo Direito que nao tem disciplina)
SELECT c.nome_curso, d.nome_disc
FROM curso c
LEFT JOIN disciplina d ON c.id_curso = d.fk_curso;

-- 2. Usando Juncao RIGHT JOIN (Inclui todas as disciplinas, mesmo Direito Penal que esta sem curso)
SELECT c.nome_curso, d.nome_disc
FROM curso c
RIGHT JOIN disciplina d ON c.id_curso = d.fk_curso;

-- 3. Juncao FULL OUTER JOIN (Inclui tudo: todos os cursos e todas as disciplinas de forma unificada)
SELECT c.nome_curso, d.nome_disc
FROM curso c
FULL OUTER JOIN disciplina d ON c.id_curso = d.fk_curso;

```

## 4. Equivalencia Logica entre Left e Right Join

* Qualquer consulta estruturada com LEFT JOIN pode ser reescrita utilizando RIGHT JOIN apenas invertendo a ordem das tabelas.
* A declaracao A LEFT JOIN B produz matematicamente e fisicamente o mesmo resultado que B RIGHT JOIN A.
* Na pratica do mercado de desenvolvimento, prioriza-se o uso do LEFT JOIN para manter a leitura do fluxo de dados da esquerda para a direita.

Para prosseguir com os estudos de junções externas no PostgreSQL, informe se deseja: 

* O exemplo de como filtrar apenas as linhas órfãs utilizando a cláusula **WHERE ... IS NULL** (Anti-Join).
* Como realizar a junção externa envolvendo **três ou mais tabelas** simultaneamente.
* Como o otimizador trata os custos de execução de um **FULL OUTER JOIN**.
