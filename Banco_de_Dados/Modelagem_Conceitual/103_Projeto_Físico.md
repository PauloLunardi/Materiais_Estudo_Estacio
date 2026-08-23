# Projeto de Banco de Dados: Projeto Físico

## 1. Conceito e Detalhes de Implementação

O projeto físico representa a última etapa do desenvolvimento de um projeto de banco de dados, onde as estruturas abstratas definidas no projeto lógico são convertidas em objetos concretos e otimizados para um SGBD específico. 

* **Definição de Atributos Físicos:** Nesta fase, são estabelecidos os detalhes técnicos de cada coluna das tabelas, tais como: 

  * A escolha exata dos tipos de dados (ex: INTEGER, VARCHAR, DATE).
  * O tamanho máximo de armazenamento de cada campo.
  * A obrigatoriedade ou opcionalidade do preenchimento da coluna (campos nulos ou não nulos).
* **Implementação de Relacionamentos:** As conexões lógicas entre as tabelas são consolidadas fisicamente por meio de restrições especiais aplicadas às colunas, denominadas **Chaves Estrangeiras (FK - Foreign Keys)**.
* **Uso de Ferramentas CASE:** O design físico é comumente realizado com o auxílio de ferramentas gráficas de modelagem. O estudo de caso utiliza a plataforma online **Vertabelo**, selecionada por suas funcionalidades educacionais gratuitas.
* **Vinculação com o SGBD Alvo:** Ao contrário das etapas anteriores, o modelo físico é totalmente dependente do produto escolhido. Neste cenário, o modelo foi enriquecido com as especificações técnicas e tipos de dados nativos do **PostgreSQL**.

## 2. Elementos e Restrições do Modelo Físico

A transformação das tabelas lógicas para o ambiente físico exige a marcação clara de restrições de integridade diretamente no diagrama e no dicionário de dados. 

* **PK (Primary Key / Chave Primária):** Identificador exclusivo de uma linha dentro da tabela. Garante que não existam registros duplicados (ex: idcliente na tabela CLIENTE e idcurso na tabela CURSO).
* **FK (Foreign Key / Chave Estrangeira):** Coluna ou conjunto de colunas que estabelece um vínculo com a Chave Primária de outra tabela, garantindo a integridade referencial.
* **N (Nullable / Nulo):** Indicador que define se uma coluna aceita valores vazios ou se a sua inserção é estritamente obrigatória (NOT NULL).

## 3. Scripts DDL (Linguagem de Definição de Dados)

A criação real do esquema do banco de dados no SGBD é executada por meio de um script escrito em **SQL (Structured Query Language)**, utilizando especificamente os comandos da **DDL (Data Definition Language)**. 

* **Propósito do Script:** Funciona como um conjunto de comandos textuais declarativos que, quando executados no SGBD, criam fisicamente as tabelas e restrições no armazenamento do computador.
* **Análise Estrutural do Código SQL (Estudo de Caso Escola):** 

  * *Criação de Tabelas:* Cada estrutura é iniciada com a sintaxe padrão CREATE TABLE nometabela.
  * *Chaves Primárias Simples:* A tabela CLIENTE possui o identificador único idcliente, enquanto a tabela CURSO possui o identificador idcurso.
  * *Chave Primária Composta:* A tabela de associação INSCRICAO possui uma chave primária composta, formada simultaneamente pelo par de colunas (idcurso, idcliente).
  * *Garantia de Integridade Referencial:* O script físico configura restrições que asseguram que uma inscrição só possa ser processada e salva se envolver, obrigatoriamente, um cliente e um curso que já tenham sido previamente cadastrados e existam no banco de dados.

## 4. Resumo Dinâmico das Fases do Projeto

O desenvolvimento de um projeto de banco de dados é um ciclo contínuo e integrado, cujas tarefas não são estáticas e respondem à evolução constante do negócio ou da legislação vigente. 

* **Fluxo Sequencial de Tarefas:** 

  1. *Levantamento de Requisitos:* Entrevistas com usuários para documentar as necessidades de dados do minimundo.
  2. *Projeto Conceitual:* Construção do modelo abstrato de alto nível por meio do Diagrama de Entidade e Relacionamento (DER).
  3. *Projeto Lógico:* Conversão do DER para estruturas tabulares genéricas (modelo relacional de baixo nível), sem definição de tipos físicos.
  4. *Projeto Físico:* Detalhamento técnico de tipos, tamanhos, restrições (PK, FK) e geração do script DDL para implementação no SGBD alvo.
