# Comandos SQL para Remocao de Linhas em Tabela

Este documento apresenta as regras, sintaxes e cuidados operacionais necessarios para a exclusao de registros utilizando o comando DELETE, abordando desde remocoes condicionais ate os impactos estruturais causados por restricoes de integridade referencial no SGBD PostgreSQL. 

## 1. Remocao de Linhas em Tabela (DELETE)

* O comando DELETE elimina permanentemente uma ou mais linhas de dados ja armazenadas em uma tabela.
* A utilizacao da clausula WHERE e obrigatoria para filtrar os registros exatos que serao deletados do banco.
* A omissao acidental ou intencional da clausula WHERE faz com que todas as linhas da tabela sejam apagadas.
* O comando DELETE remove apenas os dados internos, preservando intacta a estrutura da tabela no dicionario.

## 2. Matriz de Variacoes do Comando DELETE

```text

Cenário de Uso         Sintaxe Aplicada            Alvo da Exclusao              Risco Operacional
Filtro por ID (PK)     DELETE FROM ... WHERE ID=v  Registro unico e isolado      Minimo (Totalmente controlado)
Filtro por Condicao    DELETE FROM ... WHERE Val<x Grupo especifico de linhas    Moderado (Requer validacao)
Exclusao Geral         DELETE FROM NOMETABELA      Apaga todas as linhas da tabela Maximo (Limpa o banco inteiro)

```

## 3. Exemplos Praticos de Remocao de Registros

```sql

-- Estruturacao basica da tabela para execucao dos exemplos
CREATE TABLE aluno (
    id_aluno INT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    status_matricula VARCHAR(20) NOT NULL
);

INSERT INTO aluno (id_aluno, nome, status_matricula) VALUES
(1, 'Roberto Antunes', 'Ativo'),
(2, 'Gabriela Rocha', 'Cancelado'),
(3, 'Fernando Lima', 'Cancelado');

-- Exemplo 1: Remover o registro especifico do aluno com ID igual a 1
DELETE FROM aluno WHERE id_aluno = 1;

-- Exemplo 2: Remover todos os alunos que estao com a matricula cancelada
DELETE FROM aluno WHERE status_matricula = 'Cancelado';

-- Verificacao do estado final da tabela
SELECT * FROM aluno;

```

## 4. Gerenciamento Completo de Cascata (ON UPDATE e ON DELETE)

* Tentar remover ou alterar uma linha de uma tabela pai cuja chave primaria esteja vinculada a uma tabela filha causara erro de restricao.
* Para permitir que o SGBD propague tanto as atualizacoes de codigo quanto as exclusoes de registros de forma automatica, declaramos as clausulas ON UPDATE CASCADE e ON DELETE CASCADE conjuntamente.

```sql

-- Remocao da restricao antiga e adicao da nova chave com comportamento duplo em cascata
ALTER TABLE CURSODISCIPLINA
    DROP CONSTRAINT CURSODISCIPLINA_CURSO,
    ADD CONSTRAINT CURSODISCIPLINA_CURSO
    FOREIGN KEY (CODIGOCURSO) REFERENCES CURSO (CODIGOCURSO)
    ON UPDATE CASCADE
    ON DELETE CASCADE;

```

## 5. Analise Pratica dos Mecanismos Combinados em Acao

* O que fizemos? Usamos o comando ALTER TABLE para redefinir a chave estrangeira da tabela filha, garantindo que qualquer mudanca de codigo (UPDATE) ou exclusao de registro (DELETE) efetuada na tabela pai seja replicada de forma transparente.

```sql

-- CENARIO 1: Atualizacao em Cascata (ON UPDATE CASCADE)
-- O curso com codigo 1 passa a ser o codigo 10. O vinculo na tabela filha muda automaticamente.
UPDATE curso SET codigocurso = 10 WHERE codigocurso = 1;

-- CENARIO 2: Exclusao em Cascata (ON DELETE CASCADE)
-- O curso com codigo 3 e apagado. Todas as linhas dependentes dele em CURSODISCIPLINA sao removidas.
DELETE FROM curso WHERE codigocurso = 3;

-- Verificacao do resultado final na tabela filha relacionada
SELECT * FROM cursodisciplina;

```
