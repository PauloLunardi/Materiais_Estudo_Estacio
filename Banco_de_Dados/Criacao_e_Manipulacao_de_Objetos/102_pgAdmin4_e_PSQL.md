# pgAdmin 4 e PSQL

Este documento apresenta as principais interfaces utilizadas para interacao com o SGBD PostgreSQL, demonstrando de forma tecnica e pratica como realizar a criacao de bancos de dados utilizando tanto o ambiente grafico pgAdmin 4 quanto o utilitario de linha de comando PSQL. 

## 1. Interfaces para Interagir com o PostgreSQL

* O pgAdmin 4 e a interface grafica (GUI) oficial baseada em web para gerenciamento e administracao do cluster.
* O PSQL e o utilitario interativo de linha de comando (CLI) nativo para execucao direta de queries e scripts SQL.
* A interface grafica e recomendada para analises visuais, navegacao estrutural e geracao de diagramas.
* A ferramenta de linha de comando e ideal para automacoes, execucao em servidores remotos e scripts de deploy.
* Ambas as ferramentas se comunicam com o processo principal utilizando o protocolo de rede nativo do SGBD.

## 2. Matriz de Comparacao entre Interfaces

```text

Caracteristica         Interface Grafica (pgAdmin 4)  Linha de Comando (PSQL)
Ambiente de Execucao   Navegador Web / Desktop App    Terminal / Prompt de Comando
Consumo de Memoria     Moderado a Alto                Baixo / Leve
Ideal para             Administracao e Analise Visual Automacao de Tarefas e Scripts
Conexao Remota         Exige configuracao de tuning   Nativa e imediata via SSH/Terminal

```

## 3. Criando Database com o pgAdmin 4 e o PSQL

* No pgAdmin 4, a criacao ocorre clicando com o botao direito em Databases e selecionando Create Database.
* O script DDL executado internamente pela interface grafica segue o padrao ANSI SQL de definicao.
* No PSQL, a criacao exige conexao previa ao servidor por meio de credenciais validas de superusuario.
* A sintaxe de criacao em ambas as ferramentas exige que o nome do banco de dados seja exclusivo no cluster.

## 4. Exemplos de Comandos SQL de Criacao

```sql

-- Execucao via Query Tool no ambiente grafico pgAdmin 4
CREATE DATABASE BDTESTEPGADMIN;

-- Execucao via terminal interativo utilitario PSQL
CREATE DATABASE BDTESTEPSQL;

```

## 5. Retorno e Comportamento da Tela do PSQL

* Apos o SGBD executar o comando com sucesso, o terminal exibira uma mensagem de confirmacao literal.
* O prompt do PSQL aguardara a proxima instrucao indicando que a transacao foi consolidada em disco.

```text

postgres=# CREATE DATABASE BDTESTEPSQL;
CREATE DATABASE
postgres=# 

```
