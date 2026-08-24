# Pratica de Criacao de Banco de Dados com PSQL e pgAdmin

Este documento apresenta o roteiro pratico completo para criacao de bases de dados, definicao estrutural de tabelas, insercao de registros e consultas de dados utilizando o terminal interativo PSQL e a ferramenta grafica pgAdmin4. 

## 1. Criando Banco de Dados e Objetos Utilizando o PSQL

* Abra o terminal ou prompt de comando do seu sistema operacional.
* Conecte-se ao servidor executando o comando de inicializacao do utilitario nativo.
* Insira a senha do superusuario padrao para liberar o acesso ao prompt interativo.
* Execute a instrucao de criacao e alterne para o novo contexto de banco de dados.
* Construa a estrutura da tabela definindo tipos de dados apropriados para cada coluna.
* Insira duas linhas de registros de teste para popular a estrutura criada.
* Rode a query de selecao para certificar a gravacao correta dos dados no disco.

```sql

-- Conexao inicial via terminal de comando
psql -U postgres

-- Criacao da database no prompt do PSQL
CREATE DATABASE bd_pratica_psql;

-- Conexao e mudanca de contexto para o banco criado
\c bd_pratica_psql

-- Criacao de tabela (DDL)
CREATE TABLE produto (
    id_produto SERIAL PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    preco NUMERIC(10,2) NOT NULL
);

-- Insercao de duas linhas de dados (CRUD - Create)
INSERT INTO produto (nome, preco) VALUES ('Notebook', 3500.00);
INSERT INTO produto (nome, preco) VALUES ('Mouse Sem Fio', 120.00);

-- Consulta de dados (CRUD - Read)
SELECT * FROM produto;

```

## 2. Interface de Resposta no Terminal PSQL

```text

postgres=# CREATE DATABASE bd_pratica_psql;
CREATE DATABASE
postgres=# \c bd_pratica_psql
You are now connected to database "bd_pratica_psql" as user "postgres".
bd_pratica_psql=# CREATE TABLE produto (id_produto SERIAL PRIMARY KEY, nome VARCHAR(50)...);
CREATE TABLE
bd_pratica_psql=# INSERT INTO produto (nome, preco) VALUES ('Notebook', 3500.00);
INSERT 0 1
bd_pratica_psql=# INSERT INTO produto (nome, preco) VALUES ('Mouse Sem Fio', 120.00);
INSERT 0 1
bd_pratica_psql=# SELECT * FROM produto;
 id_produto |     nome      |  preco  
------------+---------------+---------
          1 | Notebook      | 3500.00
          2 | Mouse Sem Fio |  120.00
(2 rows)

```

## 3. Matriz de Passos de Execucao por Interface

```text

Etapa do Processo      Acao via Terminal (PSQL)       Acao via Grafico (pgAdmin)
Troca de Contexto      Comando interno \c [banco]     Selecao do banco na Server Tree
Definicao de Tabela    Instrucao CREATE TABLE direta  Digitacao de DDL na Query Tool
Carga Inicial (DML)    Execucao sequencial de INSERT  Execucao de bloco de codigos script
Validacao dos Dados    Query SELECT exibida em texto  Grade de dados em formato de grade

```

## 4. Criando Banco de Dados e Objetos Utilizando o pgAdmin

* Inicie o aplicativo pgAdmin4 em seu navegador ou em modo desktop.
* Expanda o menu de servidores na arvore lateral esquerda e informe a credencial de acesso.
* Clique com o botao direito do mouse sobre o nó denominado Databases, selecione Create e Database.
* Atribua o nome bd_pratica_pgadmin e salve as alteracoes do objeto.
* Clique com o botao direito em cima do banco criado e abra a ferramenta Query Tool.
* Digite e execute o bloco de comandos para estruturar, popular e consultar a nova tabela.

```sql

-- Instrucoes executadas dentro da janela Query Tool no pgAdmin4

-- Criacao de tabela (DDL)
CREATE TABLE cliente (
    id_cliente SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL
);

-- Insercao de duas linhas de dados (CRUD - Create)
INSERT INTO cliente (nome, email) VALUES ('Ana Silva', 'ana@email.com');
INSERT INTO cliente (nome, email) VALUES ('Carlos Souza', 'carlos@email.com');

-- Consulta de dados (CRUD - Read)
SELECT * FROM cliente;

```
