# Comandos SQL para Alteracao e Remocao de Tabela

Este documento apresenta os conceitos e comandos práticos para modificação da estrutura de tabelas existentes e para a exclusão definitiva de objetos dentro do SGBD PostgreSQL. 

## 1. Alteracao de Tabela - ALTER TABLE, ADD e DROP

* A instrução ALTER TABLE permite modificar a estrutura de uma tabela existente sem a necessidade de recriá-la.
* A cláusula ADD insere novas colunas na tabela, exigindo a definição do nome do campo e do seu respectivo tipo de dado.
* A cláusula DROP COLUMN elimina colunas existentes no modelo físico, removendo permanentemente os dados contidos nelas.
* O comando de alteração bloqueia temporariamente a tabela para garantir a consistência estrutural dos dados em disco.

## 2. Matriz de Operacoes Estruturais (DDL)

```text

Comando Base           Clausula Adicional          Efeito Pratico no Banco de Dados
ALTER TABLE            ADD COLUMN                  Insere um novo campo com tipo de dado especificado
ALTER TABLE            DROP COLUMN                 Exclui uma coluna existente e apaga seus dados
DROP TABLE             [Nenhuma]                   Elimina a tabela por completo do dicionario de dados
DROP TABLE             CASCADE                     Remove a tabela e desfaz vinculos de chaves estrangeiras

```

## 3. Remocao de Tabela - DROP TABLE

* O comando DROP TABLE apaga permanentemente a tabela e todos os seus registros do dicionário de dados do SGBD.
* A remoção direta de uma tabela pai falhará se houver restrições de chave estrangeira (FOREIGN KEY) apontando para ela.
* A inclusão do parâmetro CASCADE força a exclusão da tabela e remove automaticamente as restrições ou objetos dependentes.
* Esta operação não pode ser desfeita por comandos DML comuns, exigindo cautela na sua execução em ambientes de produção.

## 4. Exemplos Praticos de Alteracao e Remocao

```sql

-- Criacao de uma tabela base para a pratica estrutural
CREATE TABLE funcionario (
    id_funcionario SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL
);

-- Insercao de duas linhas de dados para teste inicial
INSERT INTO funcionario (nome) VALUES ('Rodrigo Santos');
INSERT INTO funcionario (nome) VALUES ('Mariana Costa');

-- 1. ALTERACAO: Adicionando uma nova coluna (ADD)
ALTER TABLE funcionario ADD COLUMN salario NUMERIC(10,2) DEFAULT 1500.00;

-- 2. ALTERACAO: Adicionando uma coluna que sera removida depois
ALTER TABLE funcionario ADD COLUMN tag_temporaria VARCHAR(10);

-- Consulta para verificar a tabela com as novas colunas e dados padrao
SELECT * FROM funcionario;

-- 3. ALTERACAO: Removendo a coluna temporaria (DROP COLUMN)
ALTER TABLE funcionario DROP COLUMN tag_temporaria;

-- Consulta para validar a estrutura apos a exclusao da coluna
SELECT * FROM funcionario;

-- 4. REMOCAO: Eliminando a tabela por completo do banco de dados (DROP TABLE)
DROP TABLE funcionario;

```
