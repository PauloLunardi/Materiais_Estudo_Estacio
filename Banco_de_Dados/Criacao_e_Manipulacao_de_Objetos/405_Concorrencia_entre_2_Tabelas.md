# Controle de Concorrencia Entre 2 Tabelas

Este documento apresenta o roteiro pratico para analise de concorrencia, isolamento e bloqueios simultaneos entre duas sessoes ativas no SGBD PostgreSQL, utilizando a interface grafica pgAdmin e o terminal interativo PSQL. 

## 1. Conexao e Preparacao das Sessoes

* Para realizar a atividade, siga os passos apresentados a seguir.
* Abra o pgAdmin, expanda a arvore de servidores e acesse o banco tabelas_lab com o Query Tool.
* Abra o PSQL no prompt de comando ou terminal do seu sistema operacional.
* Faca conexao ao banco tabelas_lab informando as credenciais de autenticacao exigidas pelo SGBD.

## 2. Matriz de Linha do Tempo e Interacao Concorrente

```text

Passo Cronologico       | Sessao Ativa (pgAdmin)      | Sessao Ativa (PSQL)         | Efeito no Motor do Banco
*************************************************************************************************************************
1. Inicializacao DML    | BEGIN e INSERT (2 linhas)   | [Inativa neste passo]       | Dados visiveis apenas no pgAdmin
2. Inicializacao DML    | [Inativa neste passo]       | BEGIN e INSERT (2 linhas)   | Dados visiveis apenas no PSQL
3. Resolucao Sessao 1   | COMMIT e SELECT             | [Inativa neste passo]       | Dados do pgAdmin gravados em disco
4. Resolucao Sessao 2   | [Inativa neste passo]       | ROLLBACK e SELECT           | Dados do PSQL sao descartados
5. Bloqueio de Escrita  | BEGIN e UPDATE Global       | [Inativa neste passo]       | Linhas recebem travamento exclusivo
6. Conflito Concorrente | [Inativa neste passo]       | BEGIN e UPDATE Global       | Sessao PSQL entra em estado de WAIT

```

## 3. Pratica de Visibilidade e Isolamento de Dados

```sql

-- Execucao simultanea nas duas interfaces para teste de insercao concorrente

-- [No pgAdmin]:
BEGIN;
SELECT * FROM tabtrans;
INSERT INTO tabtrans (id, texto) VALUES (10, 'pgAdmin 1'), (11, 'pgAdmin 2');
SELECT * FROM tabtrans; -- Exibe as linhas originais mais as duas novas

-- [No PSQL]:
BEGIN;
SELECT * FROM tabtrans; -- Nao enxerga as linhas inseridas pelo pgAdmin (Isolamento)
INSERT INTO tabtrans (id, texto) VALUES (20, 'PSQL 1'), (21, 'PSQL 2');
SELECT * FROM tabtrans; -- Exibe as linhas originais mais as duas do PSQL

-- [No pgAdmin]:
COMMIT;
SELECT * FROM tabtrans; -- Mostra as insercoes consolidadas do pgAdmin

-- [No PSQL]:
SELECT * FROM tabtrans; -- Enxerga as linhas do pgAdmin? Nao, devido ao snapshot do bloco
ROLLBACK;
SELECT * FROM tabtrans; -- Agora enxerga as linhas do pgAdmin, pois a transacao local foi desfeita

```

## 4. Simulacao de Bloqueio Concorrente (Lock Wait)

* Nesta etapa, as duas sessoes tentarao modificar os mesmos registros simultaneamente, forcando o motor do SGBD a gerenciar uma fila de espera por recursos.

```sql

-- [No pgAdmin]:
BEGIN;
SELECT * FROM tabtrans;
-- Comande update em todas as linhas da tabela tabtrans
UPDATE tabtrans SET texto = 'Mod_pgAdmin';
SELECT * FROM tabtrans; -- Exibe todas as linhas modificadas com sucesso

-- [No PSQL]:
BEGIN;
SELECT * FROM tabtrans; -- Exibe os dados anteriores ao UPDATE do pgAdmin
-- Comande update em todas as linhas da tabela tabtrans
UPDATE tabtrans SET texto = 'Mod_PSQL';

```

## 5. Comportamento do SGBD Nos Bastidores do Bloqueio

* Ao executar o comando UPDATE na janela do PSQL, a tela do console **ficara travada e congelada**, sem retornar mensagem de sucesso.
* O PostgreSQL intercepta a segunda instrucao de modificacao e coloca o processo backend do PSQL em estado de espera (Lock Wait).
* Este comportamento ocorre porque o pgAdmin detem o bloqueio exclusivo de escrita (Exclusive Lock) sobre as linhas da tabela.
* O terminal do PSQL permanecera aguardando indefinidamente ate que a sessao do pgAdmin execute um comando COMMIT ou ROLLBACK para liberar os registros.
