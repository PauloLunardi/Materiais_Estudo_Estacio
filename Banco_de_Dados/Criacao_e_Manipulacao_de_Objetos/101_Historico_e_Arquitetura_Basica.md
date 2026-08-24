# Historico e Arquitetura Basica do PostgreSQL

Este documento apresenta a evolucao cronologica do SGBD PostgreSQL, desde a sua concepcao academica na Universidade da California ate a consolidacao como um dos principais sistemas gerenciadores de banco de dados relacionais de codigo aberto do mercado, detalhando tambem o seu modelo de arquitetura de processos. 

## 1. Breve Historico e Implementacao

* O projeto iniciou em 1986 na Universidade da California em Berkeley sob a lideranca de Michael Stonebraker.
* O desenvolvimento surgiu como um sucessor do projeto Ingres para resolver problemas de tipos complexos de dados.
* A primeira versao operacional do sistema, denominada Postgres, teve sua implementacao consolidada em 1989.
* O foco inicial do motor estava na extensibilidade e no suporte nativo a programacao orientada a objetos.

## 2. Evolucao, Postgres95 e Mudanca para PostgreSQL

* O lancamento ao publico externo ocorreu formalmente no inicio da decada de 1990 com a versao 4.2 do Postgres.
* Dois estudantes de pos-graduacao, Andrew Yu e Jolly Chen, substituiram o interpretador de consultas PostQUEL por SQL.
* O sistema reformulado foi lancado em 1995 sob o nome comercial e tecnico de Postgres95.
* Em 1996, o projeto foi rebatizado definitivamente como PostgreSQL para refletir o suporte nativo a linguagem SQL.
* A comunidade global PostgreSQL Global Development Group assumiu o codigo para lancar a versao historica 6.0.

## 3. Consolidacao como SGBD de Codigo Aberto

* O PostgreSQL consolidou-se como um dos principais SGBDs de codigo aberto devido a sua licenca liberal permissiva.
* O software destaca-se pela conformidade estrita com os padroes ANSI/ISO SQL internacionais.
* O motor oferece recursos avancados como integridade referencial, transacoes ACID completas e concorrencia via MVCC.
* O ecossistema expandiu-se com suporte massivo a dados nao estruturados, extensoes espaciais e alta disponibilidade.

## 4. Matriz Comparativa de Marcos Cronologicos

```text

Ano Marco Tecnico         Nome do Projeto   Principal Caracteristica Desenvolvida
1986 Concepcao Academica    Postgres          Inicio das pesquisas pos-Ingres em Berkeley
1989 Primeira Versao        Postgres          Implementacao do modelo objeto-relacional basico
1995 Substituicao de Engine Postgres95        Troca do PostQUEL pelo interpretador SQL standard
1996 Criacao da Comunidade  PostgreSQL        Lancamento da versao 6.0 e governanca global livre

```

## 5. Arquitetura Interna do PostgreSQL

* O PostgreSQL adota uma arquitetura baseada em processos com modelo de atendimento Cliente/Servidor.
* O processo central de segundo plano do servidor e denominado postgres (antigamente chamado de postmaster).
* O processo principal escuta conexoes em uma porta TCP configurada e gerencia a alocacao de recursos do cluster.
* Para cada nova conexao de cliente, o processo pai realiza um fork e cria um processo dedicado chamado backend worker.
* A comunicacao entre o cliente e o backend atribuido ocorre por meio de mensagens via protocolo de rede nativo.
* Os processos do backend compartilham uma area comum de memoria RAM para cache de blocos de disco e controle de locks.
