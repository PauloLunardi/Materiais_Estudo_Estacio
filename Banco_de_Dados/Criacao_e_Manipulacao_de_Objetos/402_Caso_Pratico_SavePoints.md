# Caso Pratico de Controle Transacional com Savepoints

Este documento apresenta o roteiro pratico e sequencial para execucao e analise de transacoes manuais no SGBD PostgreSQL, demonstrando o comportamento de pontos de salvamento intermediarios e a visibilidade dos dados. 

## 1. Conexao e Preparacao do Ambiente

* Abra o aplicativo pgAdmin em seu computador e conecte-se ao servidor local ativo.
* Acesse o banco de dados denominado tabelas_lab utilizando o menu lateral esquerdo.
* Abra a ferramenta Query Tool para iniciar a digitacao e execucao sequencial do roteiro.

```sql

-- Passo 3: Crie uma tabela chamada tabtrans com duas colunas
CREATE TABLE tabtrans (
    id INT,
    texto VARCHAR(10)
);

```

## 2. Matriz de Estados e Operacoes do Laboratorio

```text

Etapa / Comando SQL      |  Acao Operacional no Banco   |  Visibilidade Interna          |  Ponto de Restauracao
===========================================================================================================================
4. BEGIN                 |  Abre o bloco da transacao   |  Estado isolado inicial        |  Nenhum ativo
5. INSERT (Duas linhas)  |  Insere IDs 1 e 2            |  Duas linhas visiveis          |  Nenhum ativo
7. SAVEPOINT A           |  Marca ponto de salvamento   |  Duas linhas visiveis          |  Ponto A fixado
8. INSERT (Mais duas)    |  Insere IDs 3 e 4            |  Quatro linhas visiveis        |  Ponto A ativo
10. SAVEPOINT B          |  Marca ponto de salvamento   |  Quatro linhas visiveis        |  Pontos A e B ativos
11. UPDATE (Duas linhas) |  Modifica textos dos IDs 1/2 |  Alteracoes visiveis           |  Pontos A e B ativos
13. SAVEPOINT C          |  Marca ponto de salvamento   |  Alteracoes visiveis           |  Pontos A, B e C ativos
14. DELETE (Uma linha)   |  Remove o ID 4               |  Tres linhas visiveis          |  Pontos A, B e C ativos
16. ROLLBACK TO B        |  Retorna ao marco B          |  Quatro linhas originais       |  Ponto A ativo (B e C destruidos)
19. ROLLBACK TO A        |  Retorna ao marco A          |  Duas linhas originais         |  Nenhum ativo
21. COMMIT               |  Consolida a transacao       |  Duas linhas gravadas em disco |  Transacao encerrada

```

## 3. Execucao Sequencial do Bloco Transacional

```sql

-- 4. Abra uma transacao
BEGIN;

-- 5. Insira duas linhas na tabela
INSERT INTO tabtrans (id, texto) VALUES (1, 'Linha 1'), (2, 'Linha 2');

-- 6. Consulte a tabela (Retornara as 2 linhas inseridas)
SELECT * FROM tabtrans;

-- 7. Crie um ponto de salvamento A
SAVEPOINT A;

-- 8. Insira mais 2 linhas
INSERT INTO tabtrans (id, texto) VALUES (3, 'Linha 3'), (4, 'Linha 4');

-- 9. Consulte a tabela (Retornara 4 linhas no total)
SELECT * FROM tabtrans;

-- 10. Crie um ponto de salvamento B
SAVEPOINT B;

-- 11. Altere duas linhas da tabela
UPDATE tabtrans SET texto = 'Alterado' WHERE id IN (1, 2);

-- 12. Consulte a tabela (Retornara as alteracoes aplicadas nos IDs 1 e 2)
SELECT * FROM tabtrans;

-- 13. Crie novo ponto de salvamento C
SAVEPOINT C;

-- 14. Elimine uma linha
DELETE FROM tabtrans WHERE id = 4;

-- 15. Consulte a tabela (Retornara 3 linhas, o ID 4 foi removido)
SELECT * FROM tabtrans;

```

## 4. Analise de Retorno dos Pontos de Salvamento

```sql

-- 16. Retorne ao ponto de salvamento B
ROLLBACK TO B;

-- 17. Consulte a tabela
SELECT * FROM tabtrans;

```

* **Resultado da consulta 17:** A tabela retorna ao estado exato do Passo 10. As alteracoes do UPDATE (Passo 11) e a exclusao do DELETE (Passo 14) foram desfeitas. O ID 4 reaparece e os IDs 1 e 2 voltam aos textos originais.

```sql

-- 18. Retorne ao ponto de salvamento C
ROLLBACK TO C;

```

* **Conseguiu? Não?** O PostgreSQL retornara um erro no console. Isso ocorre porque ao disparar o ROLLBACK TO B, todos os savepoints criados *apos* o ponto B (neste caso, o ponto C) sao automaticamente destruidos pelo SGBD.

```text

ERROR: savepoint "c" does not exist

```

## 5. Conclusao e Confirmacao dos Dados

```sql

-- 19. Retorne ao ponto de salvamento A
ROLLBACK TO A;

-- 20. Consulte a tabela (Retornara apenas as 2 linhas iniciais dos IDs 1 e 2)
SELECT * FROM tabtrans;

-- 21. Confirme a transacao
COMMIT;

-- 22. Consulte a tabela (Valida a persistencia definitiva das 2 linhas no disco)
SELECT * FROM tabtrans;

```
