# Projeto de Banco de Dados: Projeto Lógico

## 1. Conceito e Modelos de Baixo Nível

O projeto lógico, também conhecido na literatura técnica como modelo de dados de baixo nível, tem como objetivo principal transformar o modelo conceitual abstrato (como o DER) em uma estrutura de dados tangível e lógica. 

* **Dependência Tecnológica:** Ao contrário do projeto conceitual, o projeto lógico depende diretamente do tipo de SGBD escolhido para a implementação do sistema (por exemplo, se o banco será relacional ou não relacional).
* **Paradigmas Lógicos Existentes:** A engenharia de dados classifica os modelos lógicos em diversas categorias estruturais: 

  * Rede
  * Hierárquico
  * Relacional
  * Orientado a objeto
  * Grafos
  * Chave-valor
  * XML
* **Predomínio de Mercado:** Atualmente, o modelo **relacional** é o mais popular e amplamente utilizado em sistemas de informação organizacionais. Os principais SGBDs líderes que adotam esse modelo são o Oracle, MySQL, PostgreSQL, SQLite e Microsoft SQL Server.

## 2. O Modelo Relacional e as Regras de Conversão

Nascido na década de 1970, o modelo relacional organiza e representa as informações do minimundo de forma estruturada, utilizando tabelas como elemento base de construção. 

* **Estrutura Tabular:** Cada tabela possui um nome identificador exclusivo e é composta por colunas específicas que definem a sua estrutura de dados.
* **Mapeamento Prático (DER para Relacional):** A transformação do modelo conceitual para o lógico relacional ocorre por meio da aplicação de regras bem definidas que convertem os elementos do DER em tabelas físicas: 

  * *Entidades:* São convertidas diretamente em tabelas com o mesmo nome (ex: as entidades CLIENTE e CURSO tornam-se as tabelas CLIENTE e CURSO).
  * *Relacionamentos:* Dependendo das regras de cardinalidade, relacionamentos também podem se transformar em tabelas isoladas para associar os dados (ex: o relacionamento INSCRICAO tornou-se a tabela INSCRICAO).
* **Abstração de Tipagem nesta Fase:** No projeto lógico, a preocupação principal reside em vincular os atributos corretamente às suas respectivas tabelas. Detalhes físicos específicos de implementação — como o tamanho dos campos em caracteres ou a definição exata dos tipos de dados (Inteiro, Varchar, Date) — **não são definidos nesta etapa**, sendo postergados para o projeto físico.

## 3. Representação Textual das Tabelas

Além do mapeamento visual em diagramas de bancos de dados, o projeto lógico pode ser documentado por meio de uma sintaxe de representação textual padronizada. Seguindo o estudo de caso da Escola de TI, a estrutura consolida-se da seguinte forma: 

* **CLIENTE** 

  * *Campos:* idcliente, nome, datanascimento, CPF, email, telefone
  * *Significado:* Um cliente é caracterizado obrigatoriamente por um código identificador, além de conter as propriedades lógicas de nome, data de nascimento, CPF, e-mail e telefone de contato.
* **CURSO** 

  * *Campos:* idcurso, nome, cargahoraria, descricao
  * *Significado:* Um curso possui um código identificador exclusivo, além das propriedades de nome do treinamento, carga horária total e descrição ementária.
* **INSCRICAO** 

  * *Campos:* idcurso, idcliente, datainscricao, datacancelamento
  * *Significado:* Uma inscrição funciona como o elo de ligação e associação entre as tabelas cliente e curso, possuindo propriedades temporais próprias como a data em que a inscrição foi efetuada e a data de um eventual cancelamento do serviço.
