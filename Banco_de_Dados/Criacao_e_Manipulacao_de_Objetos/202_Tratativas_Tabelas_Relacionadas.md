# Tratativas para Tabelas Relacionadas

Este documento aborda as regras de integridade referencial aplicadas na criacao, alteracao e remocao de tabelas vinculadas por chaves estrangeiras, destacando os cuidados operacionais necessarios para evitar violacoes de integridade no SGBD PostgreSQL. 

## 1. Criacao, Alteracao e Cuidados com Tabelas Relacionadas

* A vinculacao entre tabelas ocorre por meio de restricoes de chave estrangeira (FOREIGN KEY), que associam uma tabela filha a uma tabela pai.
* A ordem de criacao e estrita: a tabela pai (que contem a chave primaria referenciada) deve ser erguida antes da tabela filha.
* Alteracoes estruturais em colunas indexadas por relacionamentos exigem a validacao previa de compatibilidade de tipos de dados.
* A manipulacao de tabelas relacionadas exige cautela, pois o SGBD impede operacoes que gerem registros orfaos no banco de dados.
* Tentativas de exclusao de tabelas ou registros pai que possuem vinculos ativos na tabela filha resultarao em erro de restricao.

## 2. Matriz de Comportamento de Integridade Referencial

```text

Operacao Pretendida    Cenario Relacional              Comportamento Padrao do SGBD
DROP TABLE (Pai)       Existem tabelas filhas ativas   Operacao rejeitada (Erro de restricao de FK)
DROP TABLE (Filha)     Nao possui tabelas dependentes  Operacao aceita e executada imediatamente
DROP TABLE ... CASCADE Existem tabelas filhas ativas   Operacao aceita (Remove tabela pai e vinculos da filha)

```

#;# 3. Exemplo Pratico de Restricao e Uso do DROP CASCADE

```sql

-- Criacao da tabela pai (NIVEL)
CREATE TABLE nivel (
    id_nivel SERIAL PRIMARY KEY,
    descricao VARCHAR(50) NOT NULL
);

-- Criacao da tabela filha relacionada (COLABORADOR)
CREATE TABLE colaborador (
    id_colaborador SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    fk_nivel INT NOT NULL,
    CONSTRAINT fk_colaborador_nivel FOREIGN KEY (fk_nivel) REFERENCES nivel (id_nivel)
);

-- Insercao de dados para teste de integridade
INSERT INTO nivel (descricao) VALUES ('Junior');
INSERT INTO nivel (descricao) VALUES ('Pleno');

INSERT INTO colaborador (nome, fk_nivel) VALUES ('Carlos Augusto', 1);
INSERT INTO colaborador (nome, fk_nivel) VALUES ('Luana Mendes', 2);

-- Consulta para demonstrar o vinculo relacional ativo
SELECT c.nome, n.descricao AS nivel_profissional
FROM colaborador c
INNER JOIN nivel n ON c.fk_nivel = n.id_nivel;

```

## 4. Analise de Tentativa de Remocao Restrita

* Suponha que temos interesse em remover a tabela NIVEL. Para isso, executaremos o comando SQL a seguir.

```sql

DROP TABLE nivel;

```

* Ao executar o comando acima, o PostgreSQL interceptara a instrucao e retornara um erro na tela do PSQL ou pgAdmin:

```text

ERROR: cannot drop table nivel because other objects depend on it
DETAIL: constraint fk_colaborador_nivel on table colaborador depends on table nivel
HINT: Use DROP ... CASCADE to drop the dependent objects too.

```

## 5. Aplicacao Pratica do DROP TABLE ... CASCADE

* E se, ainda assim, quisessemos remover a tabela NIVEL?
* Para forcar a exclusao, utilizamos a clausula CASCADE. Ela instrui o SGBD a eliminar a tabela pai e apagar automaticamente todas as restricoes de chave estrangeira que dependem dela nas tabelas filhas.

```sql

-- Execucao da remocao em cascata
DROP TABLE nivel CASCADE;

-- Consulta para demonstrar que a tabela filha permanece, mas perdeu o vinculo
SELECT * FROM colaborador;

```
