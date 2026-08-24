# Projeto de Banco de Dados: Modelagem Lógica e Física

## 1. Propósito e Ferramental de Estudo

O domínio dos componentes do modelo relacional, a aplicação das formas normais e o mapeamento conceitual-lógico (abrangendo entidades, relacionamentos, atributos e especializações) são pilares essenciais para converter conceitos abstratos em bancos de dados reais. 

* **Diretrizes Técnicas:** A implementação eficiente e otimizada de um banco de dados em um SGBD exige familiaridade com diretrizes físicas, constituindo uma atividade estratégica e rotineira para profissionais de engenharia de dados.
* **Ferramenta Recomendada:** Para a execução e reprodução dos exercícios práticos desta unidade, recomenda-se a instalação e utilização da ferramenta de distribuição livre **brModelo** em seu computador.
* **Objetivos Centrais de Aprendizado:** 

  * Identificar e dominar os elementos estruturais que compõem o modelo relacional.
  * Diferenciar os critérios e regras que regem as formas normais na modelagem.
  * Aplicar de maneira prática e precisa as regras de mapeamento conceitual-lógico.
  * Identificar e configurar os aspectos físicos necessários para a implementação do modelo final no SGBD.

## 2. O Modelo Relacional e o Processo de Normalização

A introdução a esta nova fase aborda a engenharia lógica do banco de dados, estabelecendo as bases para avaliar a qualidade e a viabilidade técnica do armazenamento. 

* **Representação por Tabelas:** O modelo relacional — introduzido historicamente na década de 1970 — organiza as informações do minimundo sob o formato exclusivo de tabelas estruturadas. Esse modelo é o padrão nativo dos SGBDs líderes de mercado, como MySQL, Oracle, PostgreSQL e SQL Server.
* **A Técnica de Normalização:** Caracteriza-se como um processo formal e matemático utilizado para avaliar, auditar e garantir a qualidade técnica de um projeto de banco de dados relacional. Seu objetivo principal é eliminar redundâncias desnecessárias, mitigar anomalias de atualização e certificar a integridade das dependências lógicas dos dados.

## 3. Regras de Transição e Diretrizes Físicas

O ciclo de desenvolvimento avança da abstração em direção à infraestrutura concreta, exigindo mapeamentos sistemáticos antes da escrita dos scripts finais. 

* **Mapeamento Conceitual-Lógico:** Consiste na aplicação de um conjunto de regras determinísticas bem definidas para transformar os blocos e losangos do Diagrama Entidade-Relacionamento (DER) em tabelas, colunas e chaves lógicas relacionais.
* **Aspectos Físicos de Implementação:** Envolvem a tomada de decisões de baixo nível técnico que impactam diretamente a performance do SGBD. Nesta fase final, são analisados fatores como a tipagem exata dos dados, o tamanho dos campos, a criação de índices para otimização de buscas e a distribuição física dos arquivos em disco.
