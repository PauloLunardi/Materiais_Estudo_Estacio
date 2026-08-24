# Comandos SQL para Criacao de Banco de Dados e Tabelas

Este documento apresenta o historico da linguagem SQL, as formas de acesso ao SGBD PostgreSQL, as regras de definicao estrutural para criacao de bases de dados e tabelas, o mapeamento dos tipos de dados suportados e o comportamento interno do motor nos bastidores. 

## 1. Breve Historico da SQL e Acesso ao PostgreSQL

* A linguagem SQL nasceu nos laboratorios da IBM na decada de 1970 baseada no modelo relacional de Edgar F. Codd.
* A padronizacao internacional ocorreu via institutos ANSI e ISO para unificar a sintaxe estrutural.
* O acesso ao ambiente do PostgreSQL exige autenticacao por meio de IP, porta, usuario e senha criptografada.
* A interacao nativa ocorre de forma grafica pelo pgAdmin 4 ou via terminal de comandos pelo utilitario PSQL.

## 2. Criando um Banco de Dados e Estrutura de Tabelas

* O comando CREATE DATABASE aloca uma nova estrutura isolada no cluster logico do SGBD.
* A criacao de tabelas requer o comando CREATE TABLE seguido pelo identificador mandatorio NOMETABELA.
* A declaracao define os campos da entidade organizados sequencialmente entre COLUNA1 e COLUNAN.
* Cada campo exige a definicao explicita de um TIPODEDADOS valido e a aplicacao opcional de uma RESTRICAO.
* A clausula PRIMARY KEY especifica a chave primaria para garantir a unicidade de identificacao da linha.
* A clausula FOREIGN KEY estabelece o vinculo de integridade referencial com tabelas externas do banco.
* A sintaxe CONSTRAINT RESTRICAO permite nomear explicitamente as regras de validacao e chaves do sistema.

## 3. Matriz de Mapeamento de Tipos de Dados Nativos

```text

Tipo de Dado           Espaco em Disco             Descricao e Comportamento Tecnico
bigint                 8 bytes                     Inteiro com sinal de alta precisao numerica
char (comprimento)     Fixo conforme o parametro   Texto complementado com espacos em branco a direita
date                   4 bytes                     Armazenamento exclusivo de data calendario (ano, mes, dia)
decimal / numeric      Variavel                    Numero de ponto fixo com precisao exata configuravel
double                 8 bytes                     Numero de ponto flutuante de dupla precisao de processamento
int ou integer         4 bytes                     Inteiro com sinal para faixas numericas convencionais
money                  8 bytes                     Quantidade monetaria com formato de exibicao regionalizado
real                   4 bytes                     Numero de ponto flutuante de precisao simples de processamento
serial                 4 bytes                     Inteiro autoincremental gerenciado por um objeto de sequencia
smallint               2 bytes                     Inteiro com sinal para faixas numericas restritas e pequenas
time                   8 bytes                     Armazenamento exclusivo de horario do dia (hora, minuto, segundo)
varchar (comprimento)  Variavel ate o limite max   Texto de tamanho variavel sem preenchimento de espacos vazios

```

## 4. Exemplo Pratico Envolvendo Criacao de Tabelas

```sql

-- Criacao do banco de dados operacional
CREATE DATABASE bd_sistema_documentos;

-- Conexao manual ao banco criado para iniciar a execucao estrutural
\c bd_sistema_documentos;

-- Criacao da tabela mae (Entidade de Dominio)
CREATE TABLE tipo_documento (
    id_tipo SERIAL,
    descricao VARCHAR(50) NOT NULL,
    CONSTRAINT pk_tipo_documento PRIMARY KEY (id_tipo)
);

-- Criacao da tabela filha (Entidade Relacional com integridade referencial)
CREATE TABLE documento (
    id_documento SERIAL,
    titulo VARCHAR(100) NOT NULL,
    valor_taxa NUMERIC(12,2) DEFAULT 0.00,
    data_registro DATE DEFAULT CURRENT_DATE,
    fk_tipo INT NOT NULL,
    CONSTRAINT pk_documento PRIMARY KEY (id_documento),
    CONSTRAINT fk_documento_tipo FOREIGN KEY (fk_tipo) REFERENCES tipo_documento (id_tipo)
);

-- Insercao de registros de teste para validacao de carga inicial
INSERT INTO tipo_documento (descricao) VALUES ('Contrato Comercial');
INSERT INTO tipo_documento (descricao) VALUES ('Certidao Publica');

INSERT INTO documento (titulo, valor_taxa, fk_tipo) VALUES ('Contrato Locacao Galpao A', 150.50, 1);
INSERT INTO documento (titulo, valor_taxa, fk_tipo) VALUES ('Certidao Negativa de Debitos', 0.00, 2);

-- Execucao de consulta de juncao estrutural para analise de integridade
SELECT d.id_documento, d.titulo, t.descricao AS categoria, d.valor_taxa
FROM documento d
INNER JOIN tipo_documento t ON d.fk_tipo = t.id_tipo;

```

## 5. Gerenciamento de Scripts e Bastidores do SGBD

* O gerenciamento de scripts na pratica deve adotar arquivos com extensao .sql codificados em UTF-8 padrao.
* Os blocos de comandos devem conter comentarios estruturados iniciados por hifens duplos para documentacao.
* Nos bastidores, o PostgreSQL intercepta o comando por meio de um processo backend dedicado gerado por fork.
* O componente Parser valida a sintaxe gramatical da query recebida contra o dicionario de dados.
* O Traffic Cop direciona instrucoes DDL para utilitarios de catalogo e comandos DML para o otimizador logico.
* O otimizador gera planos de custo computacional baseados em estatisticas de armazenamento atuais das tabelas.
* A gravacao fisica ocorre gravando primeiro as alteracoes no WAL (Write-Ahead Logging) para garantir durabilidade.
* Os dados modificados permanecem na Shared Buffers ate o processo Checkpointer consolida-los nos arquivos de dados.
