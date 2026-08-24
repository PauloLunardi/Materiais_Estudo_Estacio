# Saiba Mais Sobre Atualizacao Temporaria e Transacao de Leitura

Este documento detalha o comportamento e o impacto de anomalias de concorrencia e o papel das transacoes de leitura dentro do SGBD PostgreSQL, evidenciando como os niveis de isolamento controlam esses cenarios. 

## 1. O Fenomeno da Atualizacao Temporaria (Leitura Suja)

* A atualizacao temporaria ocorre quando uma transacao modifica um dado, e uma segunda transacao le esse dado modificado antes do commit da primeira.
* Se a primeira transacao falhar e executar um rollback, a informacao lida pela segunda transacao torna-se invalida e inexistente.
* Essa inconsistencia tambem e conhecida no padrao ANSI SQL pelo termo tecnico Leitura Suja (Dirty Read).
* No PostgreSQL, a atualizacao temporaria e nativamente impossivel de acontecer em qualquer nivel de isolamento.
* O motor do PostgreSQL utiliza o controle de concorrencia multiversao (MVCC), garantindo que uma leitura nunca veja dados nao confirmados.

## 2. Caracteristicas da Transacao de Leitura

* Uma transacao de leitura executa estritamente buscas de informacoes usando a instrucao basica SELECT.
* Este tipo de transacao nao altera o estado dos arquivos em disco e nao gera locks de escrita concorrente.
* Pode ser declarada explicitamente no SGBD como apenas de leitura para otimizacao de performance do otimizador.
* A declaracao avisa ao gerenciador que nao haverá comandos DML de alteracao, otimizando o uso de buffers de memoria.

## 3. Matriz de Comportamento Transacional por Nivel

```text

Nivel de Isolamento    Garante Leitura Suja?       Garante Leitura Repetitiva?  Uso de Recursos
Read Committed         Sim (Bloqueia nativamente)  Nao (Dados mudam pos-commit) Baixo / Padrao
Repeatable Read        Sim (Bloqueia nativamente)  Sim (Dados congelam no bloco) Moderado
Serializable           Sim (Bloqueia nativamente)  Sim (Isolamento total)        Alto (Verifica conflitos)

```

## 4. Exemplos Praticos de Configuracao e Isolamento

```sql

-- Estrutura para os testes de visibilidade de leitura
CREATE TABLE saldo_usuario (
    id_usuario INT PRIMARY KEY,
    valor NUMERIC(12,2) NOT NULL
);

INSERT INTO saldo_usuario (id_usuario, valor) VALUES (1, 500.00);

-- 1. Transacao de Leitura Explicita (Read Only)
-- Informa ao PostgreSQL que o bloco fara apenas buscas para otimizar memoria
BEGIN TRANSACTION READ ONLY;

SELECT * FROM saldo_usuario WHERE id_usuario = 1;

-- Tentativas de INSERT/UPDATE aqui gerariam um erro imediato do SGBD
COMMIT;

-- 2. Demonstracao do comportamento do Read Committed (Padrao do SGBD)
BEGIN TRANSACTION ISOLATION LEVEL READ COMMITTED;

SELECT valor FROM saldo_usuario WHERE id_usuario = 1; -- Retorna 500.00

-- Se outra sessao rodar um UPDATE para 600.00 e der COMMIT agora:
SELECT valor FROM saldo_usuario WHERE id_usuario = 1; -- Retornara 600.00 (Leitura nao repetitiva)

COMMIT;

```
