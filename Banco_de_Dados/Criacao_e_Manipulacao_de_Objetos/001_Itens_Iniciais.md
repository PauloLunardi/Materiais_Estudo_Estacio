### Introducao ao SGBD PostgreSQL, Comandos SQL e Controle de Transacoes

Este documento apresenta as etapas de preparacao, objetivos de aprendizado, caracteristicas do SGBD PostgreSQL e os conceitos essenciais para manipulacao de dados e gerenciamento de transacoes. 

### 1. Preparacao e Objetivos de Aprendizado

* Garanta o download previo do instalador do SGBD PostgreSQL em seu computador.
* Compreenda detalhadamente todo o processo de instalacao e configuracao do sistema.
* Empregue comandos estruturais para a criacao e a alteracao de tabelas físicas.
* Domine a aplicacao de comandos para a manipulacao direta de linhas nas tabelas.
* Aplique comandos especificos voltados ao controle estrito de transacoes no banco.

### 2. Fluxo de Operacoes e Recursos do SGBD

mermaid

graph LR
    A[Instalacao do SGBD] --> B[Comandos DDL: Estrutura]
    B --> C[Comandos CRUD: Manipulacao]
    C --> D[Controle Transacional: Atomicidade]

    style A fill:#e3f2fd,stroke:#1e88e5,stroke-width:2px,color:#000
    style B fill:#e3f2fd,stroke:#1e88e5,stroke-width:2px,color:#000
    style C fill:#e3f2fd,stroke:#1e88e5,stroke-width:2px,color:#000
    style D fill:#e3f2fd,stroke:#1e88e5,stroke-width:2px,color:#000

Use o código com cuidado.

### 3. Matriz de Classificacao de Recursos SQL

text

Categoria SQL          Sigla / Conceito            Operacoes Principais
Definicao de Dados     DDL                         CREATE TABLE, ALTER TABLE, DROP TABLE
Manipulacao (CRUD)     DML / DQL                   INSERT (Create), SELECT (Read), UPDATE, DELETE
Controle Transacional  TCL                         BEGIN, COMMIT, ROLLBACK

Use o código com cuidado.

### 4. Caracteristicas Estruturais do PostgreSQL

* O PostgreSQL e um SGBD objeto-relacional de codigo aberto codificado em linguagem C.
* O sistema possui portabilidade nativa para Linux, Unix, Windows, OS X e Solaris.
* Os recursos de DDL sao usados para definir esquemas, tabelas e restricoes de integridade.
* O acronimo CRUD mapeia o ciclo de vida dos dados: criacao, consulta, atualizacao e remocao.
* O motor do SGBD trata conjuntos de operacoes de forma atomica como uma unidade logica.
* O controle transacional garante que todos os comandos confirmem ou nenhum seja realizado.

## 5. Exemplos Praticos de Comandos SQL (DDL e CRUD)
```sql
-- Criacao de uma tabela exemplo (DDL)
CREATE TABLE documento (
    id_documento SERIAL PRIMARY KEY,
    titulo VARCHAR(100) NOT NULL,
    data_criacao DATE DEFAULT CURRENT_DATE
);

-- Insercao de dados (CRUD - Create)
INSERT INTO documento (titulo) VALUES ('Relatorio Financeiro de Despachos');

-- Consulta de dados (CRUD - Read)
SELECT * FROM documento WHERE id_documento = 1;

-- Atualizacao de dados (CRUD - Update)
UPDATE documento SET titulo = 'Relatorio Anual de Despachos' WHERE id_documento = 1;

-- Remocao de dados (CRUD - Delete)
DELETE FROM documento WHERE id_documento = 1;

```

## 6. Exemplos de Controle de Transacoes (TCL)
```sql
-- Exemplo de transacao confirmada com sucesso
BEGIN;

INSERT INTO documento (titulo) VALUES ('Documento de Auditoria A');
INSERT INTO documento (titulo) VALUES ('Documento de Auditoria B');

COMMIT;

-- Exemplo de transacao revertida em caso de falha ou desistencia
BEGIN;

UPDATE documento SET titulo = 'Alteracao Incorreta' WHERE id_documento = 2;
-- Se a operacao nao for desejada, desfaz todas as alteracoes do bloco
ROLLBACK;
```
