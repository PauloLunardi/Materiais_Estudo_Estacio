# Caso Pratico de Manipulacao de Dados, Integridade e Recuperacao

Este documento apresenta o roteiro pratico expandido para execucao de comandos SQL de atualizacao, remocao e estruturacao no SGBD PostgreSQL, simulando cenarios reais de manutencao, o comportamento de restricoes e a recuperacao de dados via transacoes. 

## 1. Conexao e Preparacao da Estrutura Inicial

* Acesse o PostgreSQL utilizando o pgAdmin4, conecte-se ao servidor local e abra a ferramenta Query Tool no banco da empresa.
* Antes de iniciar as manipulacoes, monte o cenario estrutural executando o script de criacao de tabelas e carga inicial abaixo.

```sql

-- Criacao das tabelas estruturais do cenario
CREATE TABLE regiao (
    id_regiao INT PRIMARY KEY,
    nome VARCHAR(50) NOT NULL
);

CREATE TABLE departamentos (
    id_dep INT PRIMARY KEY,
    nome_dep VARCHAR(50) NOT NULL,
    fk_regiao INT,
    CONSTRAINT fk_dep_regiao FOREIGN KEY (fk_regiao) REFERENCES regiao (id_regiao)
);

CREATE TABLE empregados (
    id_empregado INT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    salario NUMERIC(10,2) NOT NULL,
    fk_dep INT,
    CONSTRAINT fk_emp_dep FOREIGN KEY (fk_dep) REFERENCES departamentos (id_dep)
);

-- Carga inicial de dados para os testes
INSERT INTO regiao (id_regiao, nome) VALUES (1, 'Norte'), (2, 'Sul');
INSERT INTO departamentos (id_dep, nome_dep, fk_regiao) VALUES (10, 'TI', 1), (20, 'RH', 2);
INSERT INTO empregados (id_empregado, nome, salario, fk_dep) VALUES (100, 'Alice Silva', 5000.00, 10), (101, 'Bruno Costa', 6000.00, 20);

```

## 2. Matriz de Sequencia das Operacoes Praticas

```text

Etapa Operacional      Comando SQL Aplicado        Alvo da Modificacao           Resultado Esperado
1. Atualizacao Local   UPDATE ... WHERE ID         Linha unica da tabela Regiao  Nome da regiao modificado
2. Atualizacao Global  UPDATE (Sem WHERE)          Todas as linhas de Empregados Salario unificado para 10000
3. Exclusao com Trava  BEGIN ... ROLLBACK          Todas as linhas de Empregados Remocao desfeita com sucesso
4. Exclusao Global     DELETE (Sem WHERE)          Todas as linhas de Empregados Tabela esvaziada por completo
5. Exclusao Restrita   DELETE ... WHERE ID         Linha especifica da Regiao    Bloqueio por erro de FK ativa
6. Resolucao de FK     DELETE ... WHERE ID         Linhas de Departamentos       Remocao das dependencias
7. Exclusao Concluida  DELETE ... WHERE ID         Linha especifica da Regiao    Sucesso apos limpeza de vinculos

```

## 3. Atualizacao de Dados e Validacao

```sql

-- 1. Altere o nome da regiao de ID 1 para Exemplo1
UPDATE regiao SET nome = 'Exemplo1' WHERE id_regiao = 1;

-- Valide a alteracao
SELECT * FROM regiao WHERE id_regiao = 1;

-- 2. Altere o salario de todos os empregados para 10000
UPDATE empregados SET salario = 10000;

-- Valide a alteracao
SELECT id_empregado, nome, salario FROM empregados;

```

### 4. Controle Transacional e Simulacao de ROLLBACK

* Para garantir a segurança das remoções globais, utilizamos blocos transacionais nativos que permitem desfazer erros antes da gravação definitiva.

```sql

-- Inicia a unidade logica de trabalho
BEGIN;

-- Elimine todos os empregados temporariamente
DELETE FROM empregados;

-- Valide a eliminacao dentro da transacao ativa (retornara zero)
SELECT COUNT(*) FROM empregados;

-- Cancela a operacao e desfaz todas as alteracoes do bloco
ROLLBACK;

-- Valide a recuperacao total dos dados apos o desfazimento
SELECT COUNT(*) FROM empregados;

```

## 5. Tratativa de Erro de Integridade Referencial

```sql

-- Elimine definitivamente todos os empregados para seguir o roteiro
DELETE FROM empregados;

-- Valide a eliminacao definitiva
SELECT COUNT(*) FROM empregados;

-- Tente eliminar a regiao de ID 1 de forma direta
DELETE FROM regiao WHERE id_regiao = 1;

```

* Você não conseguiu ainda porque tem departamento apontando para a região 1. Vamos lá! O PostgreSQL intercepta a query e exibe a mensagem de erro de restricao:

```text

ERROR: update or delete on table "regiao" violates foreign key constraint on table "departamentos"
DETAIL: Key (id_regiao)=(1) is still referenced from table "departamentos".

```

## 6. Resolucao do Vinculo e Conclusao da Pratica

```sql

-- Elimine os departamentos da regiao 1 para liberar o vinculo relacional
DELETE FROM departamentos WHERE fk_regiao = 1;

-- Comande novamente delete na regiao de ID 1
DELETE FROM regiao WHERE id_regiao = 1;

-- Agora sim! Valide a eliminacao final do objeto
SELECT * FROM regiao WHERE id_regiao = 1;

```

## 7. Automatizacao do Cenario Alternativo com ON DELETE CASCADE

* Se o objetivo arquitetural do banco fosse deletar automaticamente os registros dependentes sem a necessidade de comandos manuais sequenciais, a restrição de chave estrangeira deveria ser redefinida com o comportamento em cascata.

```sql

-- Exemplo de configuracao estrutural automatica
ALTER TABLE departamentos 
    DROP CONSTRAINT fk_dep_regiao,
    ADD CONSTRAINT fk_dep_regiao 
    FOREIGN KEY (fk_regiao) REFERENCES regiao (id_regiao) 
    ON DELETE CASCADE;

-- Com essa regra, deletar a regiao de ID 2 apagaria o departamento 20 em cascata
-- DELETE FROM regiao WHERE id_regiao = 2;

```
