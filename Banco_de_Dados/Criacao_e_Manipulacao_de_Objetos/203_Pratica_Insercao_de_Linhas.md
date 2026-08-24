# Pratica de Insercao de Linhas em Tabela

Este documento apresenta o roteiro pratico para insercao de registros no SGBD PostgreSQL, demonstrando tecnicas de carga simples, multipla, importacao condicional de dados entre tabelas e a manipulacao avancada de duplicidades com a clausula ON CONFLICT. 

## 1. Estrutura do Banco de Dados para a Pratica

* Execute a criacao das tabelas base necessarias para simular o cenario de insercoes e rotinas de backup.
* Garanta a definicao das chaves primarias para que o mecanismo de restricao de unicidade atue nos testes.

```sql

-- Criacao da tabela principal de clientes
CREATE TABLE clientes (
    id_cliente INT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    idade INT NOT NULL,
    cidade VARCHAR(50)
);

-- Criacao da tabela destino para rotinas de backup
CREATE TABLE clientes_backup (
    id_cliente INT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    idade INT NOT NULL,
    cidade VARCHAR(50)
);

```

## 2. Matriz de Variacoes da Clausula INSERT

```text

Sintaxe Aplicada       Objetivo Operacional                        Cenario de Uso
INSERT INTO ... VALUES Carga manual de dados fixos na tabela       Cadastro unitario ou em lote reduzido
INSERT INTO ... SELECT Migracao automatica baseada em filtros      Rotinas de backup e carga em massa
ON CONFLICT DO NOTHING Ignora a insercao se a chave ja existir     Evitar interrupcao de scripts por erro
ON CONFLICT DO UPDATE  Atualiza o registro se a chave ja existir   Sincronizacao de dados (Upsert)

```

### 3. Insercoes Simples, Multiplas e Verificacao

```sql

-- Realize a insercao Simples de uma linha na tabela clientes
INSERT INTO clientes (id_cliente, nome, idade, cidade) 
VALUES (1, 'Marcos Souza', 34, 'Sao Paulo');

-- Realize a insercao multipla de duas linhas na tabela clientes
INSERT INTO clientes (id_cliente, nome, idade, cidade) VALUES 
(2, 'Julia Almeida', 28, 'Rio de Janeiro'),
(3, 'Ricardo Gomes', 42, 'Belo Horizonte');

-- Verifique as insercoes
SELECT * FROM clientes;

```

## 4. Carga Condicional entre Tabelas (Regras de Backup)

* Insira na tabela clientes_backup os dados dos clientes com mais de 30 anos.
* A sintaxe INSERT INTO ... SELECT extrai os dados filtrados em tempo de execucao e os injeta na tabela alvo.

```sql

-- Execucao da carga condicional com filtro de idade
INSERT INTO clientes_backup (id_cliente, nome, idade, cidade)
SELECT id_cliente, nome, idade, cidade 
FROM clientes 
WHERE idade > 30;

-- Verifique a tabela de backup para validar a regra aplicada
SELECT * FROM clientes_backup;

```

## 5. Manipulacao de Duplicidades com INSERT ... ON CONFLICT

* A instrucao ON CONFLICT intercepta o erro de chave primaria duplicada e define uma acao alternativa.
* O parametro DO NOTHING simplesmente ignora a linha conflitante, permitindo a continuidade do script.
* O parametro DO UPDATE realiza a atualizacao dos campos (Upsert) usando a tabela virtual EXCLUDED.

```sql

-- Exemplo 1: Evitando erro de chave duplicada (DO NOTHING)
-- Tentar inserir o id_cliente 1 novamente nao gerara erro no console
INSERT INTO clientes (id_cliente, nome, idade, cidade)
VALUES (1, 'Marcos Souza', 34, 'Sao Paulo')
ON CONFLICT (id_cliente) DO NOTHING;

-- Exemplo 2: Atualizando dados em caso de conflito (DO UPDATE)
-- Altera a cidade e a idade do cliente 3 caso ele ja exista no banco
INSERT INTO clientes (id_cliente, nome, idade, cidade)
VALUES (3, 'Ricardo Gomes', 43, 'Curitiba')
ON CONFLICT (id_cliente) DO UPDATE 
SET idade = EXCLUDED.idade,
    cidade = EXCLUDED.cidade;

-- Verifique o estado final da tabela apos as tratativas de conflito
SELECT * FROM clientes;

```
