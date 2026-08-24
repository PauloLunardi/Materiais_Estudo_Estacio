# Fundamentos de Consultas em Uma Tabela no PostgreSQL

Este documento apresenta os itens iniciais de preparacao, objetivos de aprendizado, e a introducao tecnica sobre a construcao de consultas estruturadas utilizando o comando SELECT, evidenciando sua importancia nas operacoes de manutencao do SGBD. 

## 1. Preparacao e Objetivos de Aprendizado

* Certifique-se de ter baixado e instalado o SGBD PostgreSQL em seu computador antes de comecar.
* Baixe o arquivo complementar contendo todos os codigos que serao utilizados nas consultas dos modulos.
* Aplique consultas basicas e avancadas utilizando o comando de projecao SELECT.
* Aplique consultas com filtros especificos e ordenacao usando as clausulas WHERE e ORDER BY.
* Aplique consultas complexas envolvendo a agregacao e o agrupamento de dados em tabelas.

## 2. Matriz de Componentes Básicos da Consulta (DQL)

```text

Clausula SQL           Funcao Arquitetural no SGBD                 Obrigatoriedade
SELECT                 Projecao de colunas e calculo de expressoes Obrigatorio
FROM                   Definicao da tabela de origem dos dados     Obrigatorio
WHERE                  Filtro logico de linhas para o processamento Opcional
GROUP BY               Agrupamento de registros por criterios      Opcional
ORDER BY               Ordenacao final do conjunto de resultados    Opcional

```

## 3. Importancia Pratica e Integracao das Consultas

* A exploracao do material engloba a recuperacao de colunas fisicas e o uso de expressoes matematicas no SELECT.
* O design de bancos de dados relacionais envolve a criacao de multiplas tabelas manipuladas por aplicacoes.
* Diversas operacoes de manipulacao (DML) estao obrigatoriamente associadas a uma operacao de consulta previa.
* O SGBD exige a execucao interna de filtros de consulta para delimitar o alvo de instrucoes de remocao e atualizacao.
* A proficiencia na programacao de consultas aperfeicoa a geracao de relatorios e otimiza operacoes corporativas.

## 4. Exemplo Pratico de Aplicacao Integrada

* Conforme apresentado na introducao, se resolvermos aumentar em 10% o salario de todos os funcionarios que ganham ate R$ 4.000, o SGBD processara um filtro de selecao interno equivalente ao comando abaixo.

```sql

-- Cenario prático exemplificado na introducao
CREATE TABLE funcionario (
    id_func SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    salario NUMERIC(10,2) NOT NULL
);

INSERT INTO funcionario (nome, salario) VALUES 
('Renato Cruz', 3500.00),
('Camila Lima', 4200.00);

-- 1. CONSULTA DE VERIFICACAO (DQL): Identifica quem ganha ate R$ 4.000
SELECT id_func, nome, salario FROM funcionario WHERE salario <= 4000.00;

-- 2. OPERACAO DE ATUALIZACAO (DML): Executa a alteracao baseada na mesma regra da consulta
UPDATE funcionario SET salario = salario * 1.10 WHERE salario <= 4000.00;

-- 3. PROJECAO COM EXPRESSAO (DQL): Consulta os valores reajustados
SELECT nome, salario AS salario_atualizado FROM funcionario;

```
