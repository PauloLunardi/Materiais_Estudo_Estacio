# Transacoes no PostgreSQL

Este documento apresenta a aplicacao dos comandos de controle transacional (TCL) no SGBD PostgreSQL, demonstrando a capacidade de reversao de operacoes DML e DDL por meio de comandos de Rollback e Savepoints. 

## 1. Comandos Basicos: BEGIN, COMMIT e ROLLBACK

* O comando BEGIN inicia formalmente um bloco transacional manual, desativando o modo de confirmação automática.
* O comando COMMIT grava permanentemente todas as alterações realizadas dentro da transação ativa nos arquivos de disco.
* O comando ROLLBACK aborta a transação e reverte o banco ao estado idêntico ao momento anterior à abertura do bloco.
* Todas as instruções executadas entre o início e o fim do bloco permanecem invisíveis para conexões concorrentes.

## 2. Matriz de Comportamento de Reversao (Rollback)

```text

Comando Executado      Categoria SQL  Status Apos ROLLBACK          Descricao do Efeito Pratico
INSERT INTO            DML            Registro removido               A linha inserida e totalmente descartada
UPDATE ... SET         DML            Valores originais restaurados   Os dados modificados voltam ao estado anterior
DELETE FROM            DML            Linhas deletadas restauradas    Os registros apagados reaparecem na tabela
ALTER TABLE ... ADD    DDL            Coluna adicionada e removida    A nova coluna e eliminada da estrutura
ALTER TABLE ... DROP   DDL            Coluna removida e restaurada    A coluna e seus dados sao recuperados
DROP TABLE             DDL            Tabela excluida e restaurada    A tabela e recriada com todos os dados

```

## 3. Comportamento do ROLLBACK com Filtros e Sintaxe

* O comando ROLLBACK atua estritamente sobre a totalidade do bloco de transação ativo na sessão atual.
* Não existe a sintaxe de filtro condicional na instrução de reversão (ex: ROLLBACK WHERE id = 10 é inválido).
* O escopo do desfazimento é atômico, aplicando-se de forma global a todas as tabelas modificadas desde o BEGIN.

### 4. Exemplos Praticos de Reversao DML e DDL

```sql

-- Criacao da tabela base para os testes transacionais
CREATE TABLE item (
    id_item INT PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    quantidade INT NOT NULL
);

INSERT INTO item (id_item, nome, quantidade) VALUES (1, 'Cadeira', 10);

-- 1. Teste de Operacao DML: INSERT, UPDATE, DELETE + ROLLBACK
BEGIN;

INSERT INTO item (id_item, nome, quantidade) VALUES (2, 'Mesa', 5);
UPDATE item SET quantidade = 20 WHERE id_item = 1;
DELETE FROM item WHERE id_item = 1;

-- Desfaz todas as operacoes de manipulacao de dados acima
ROLLBACK;

-- Validacao: O registro 1 permanece intacto e o registro 2 nao existe
SELECT * FROM item;

-- 2. Teste de Operacao DDL: ALTER TABLE, DROP COLUMN, DROP TABLE + ROLLBACK
BEGIN;

ALTER TABLE item ADD COLUMN descricao TEXT;
ALTER TABLE item DROP COLUMN quantidade;
DROP TABLE item;

-- O PostgreSQL suporta ROLLBACK para comandos DDL estruturais
ROLLBACK;

-- Validacao: A tabela e sua estrutura original foram totalmente preservadas
SELECT * FROM item;

```

## 5. Gerenciamento Parcial com Savepoints

* Os Savepoints permitem estabelecer pontos de restauração intermediários dentro de uma mesma transação ativa.
* A instrução SAVEPOINT nome_ponto marca a posição atual na pilha de execução do bloco do banco.
* O comando ROLLBACK TO nome_ponto desfaz apenas os comandos executados após a criação daquele marco específico.
* O uso dessa estratégia evita a necessidade de abortar e reiniciar toda a transação em caso de falhas pontuais.

```sql

-- 3. Teste pratico utilizando controle parcial de Savepoints
BEGIN;

INSERT INTO item (id_item, nome, quantidade) VALUES (10, 'Armario', 2);

-- Define o primeiro ponto de restauracao na transacao
SAVEPOINT ponto_inicial;

UPDATE item SET quantidade = 99 WHERE id_item = 10;
INSERT INTO item (id_item, nome, quantidade) VALUES (20, 'Balcao', 1);

-- Desfaz apenas as operacoes executadas apos a marcacao do ponto
ROLLBACK TO ponto_inicial;

-- Finaliza e consolida o bloco no banco de dados
COMMIT;

-- Validacao: O item 10 foi inserido com a quantidade original 2. O item 20 nao existe.
SELECT * FROM item;

```
