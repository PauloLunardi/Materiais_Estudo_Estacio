# Consultas com o Operador UNION

Este documento apresenta a sintaxe formal e a aplicação prática do operador UNION no SGBD PostgreSQL, detalhando o comportamento das cláusulas adicionais ALL e DISTINCT para o controle de linhas duplicadas em consultas de união. 

## 1. Estrutura Sintática Geral do UNION

* O operador UNION consolida verticalmente os resultados de duas ou mais instruções SELECT independentes.
* A sintaxe aceita modificadores específicos para determinar como o motor do banco de dados gerenciará os registros idênticos.

```text

Sintaxe Padrão Aceita Pelo SGBD:
CONSULTASQL UNION [ALL | DISTINCT] CONSULTASQL

```

## 2. Diferenças Técnicas: UNION DISTINCT vs. UNION ALL

* **UNION DISTINCT (Padrão):** É o comportamento executado automaticamente quando declaramos apenas a palavra-chave UNION. O SGBD realiza uma varredura interna (geralmente uma operação de *Unique Sort* ou *Hash Aggregate*) para remover todas as linhas duplicadas do resultado final.
* **UNION ALL:** Unifica as projeções diretamente e mantém todas as linhas, inclusive as duplicadas. Como pula a etapa de checagem e desduplicação em memória, apresenta um desempenho drasticamente superior e consome menos recursos de CPU e RAM.

## 3. Matriz de Impacto Operacional

```text

Modificador            Processamento de Duplicadas Desempenho no SGBD          Uso de Recursos (RAM)
UNION / DISTINCT       Elimina linhas idênticas    Menor (Exige ordenação/hash) Alto (Consolida e filtra)
UNION ALL              Preserva todas as linhas    Máximo (Apenas anexa os dados) Baixo (Entrega imediata)

```

## 4. Exemplos Práticos de UNION DISTINCT e UNION ALL

```sql

-- Estruturação de tabelas para simulação de registros coincidentes
CREATE TABLE alunos_graduacao (
    id INT PRIMARY KEY,
    nome VARCHAR(50) NOT NULL
);

CREATE TABLE monitores_laboratorio (
    id INT PRIMARY KEY,
    nome VARCHAR(50) NOT NULL
);

-- Carga inicial de teste (O aluno Carlos pertence a ambos os grupos)
INSERT INTO alunos_graduacao VALUES (1, 'Carlos Silva'), (2, 'Ana Costa');
INSERT INTO monitores_laboratorio VALUES (1, 'Carlos Silva'), (3, 'Bruno Lima');

-- 1. EXEMPLO COM UNION / DISTINCT
-- Filtra o registro repetido do 'Carlos Silva' e retorna 3 linhas exclusivas
SELECT nome FROM alunos_graduacao
UNION DISTINCT
SELECT nome FROM monitores_laboratorio;

-- 2. EXEMPLO COM UNION ALL
-- Une as massas de dados sem filtrar nada e retorna 4 linhas (Carlos Silva aparece duas vezes)
SELECT nome FROM alunos_graduacao
UNION ALL
SELECT nome FROM monitores_laboratorio;

```
