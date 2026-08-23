# Arquitetura dos Sistemas de Gerência de Banco de Dados

## 1. O Ambiente e as Fronteiras do SBD

Um sistema de banco de dados (SBD) representa a interação consolidada entre dados, humanos, hardware e software. Essa integração é o que permite dar sentido prático às informações, tornando-as acessíveis e utilizáveis. 

* **Diferenciação Estrutural:** O SBD e o SGBD não se confundem. O SGBD é apenas um componente de software contido dentro do ecossistema maior que é o SBD.
* **Componentes do SGBD:** O motor do SGBD é composto, de forma simplificada, por duas grandes frentes de software: 

  * Um módulo para processar consultas e programas executados pelos usuários.
  * Um módulo para controlar o acesso direto aos dados e metadados armazenados fisicamente.
* **Fronteiras do SBD:** O limite de um SBD engloba: 

  * Os programas que implementam as aplicações finais.
  * As consultas diretas enviadas por usuários através de linguagens ou interfaces de comunicação.
  * O software intermediário (SGBD).
  * O catálogo do sistema contendo os metadados.
  * O conteúdo bruto armazenado no banco de dados.

## 2. Esquema (Metadados) vs. Instância (Estado)

Dentro do ambiente de banco de dados, existe uma separação clara entre a definição estrutural do sistema e os dados reais contidos nele em um determinado momento. 

* **Esquema do Banco de Dados (Metadados):** 

  * *Definição:* É a descrição estrutural completa do banco de dados, organizada de acordo com o modelo lógico adotado. Também é conhecido como catálogo ou dicionário de dados.
  * *Exemplo no Modelo Relacional:* O esquema é composto pelas definições das tabelas e suas respectivas colunas.
  * *Modificação:* O esquema só muda quando um comando de definição de dados (DDL) é executado, como a criação, alteração ou remoção de uma tabela ou coluna.
* **Estado ou Instância do Banco de Dados:** 

  * *Definição:* É o conteúdo real e os dados que estão efetivamente gravados no banco de dados em um momento específico do tempo.
  * *Modificação:* O estado é extremamente dinâmico. Cada operação de manipulação de dados (DML), como inserção, atualização ou exclusão de registros, altera o estado atual e gera uma nova instância do banco de dados.

## 3. Terminologia e Contexto Internacional

O termo "banco de dados" possui variações de significado e traduções específicas dependendo da região e do idioma técnico utilizado. 

* **Origem Histórica:** A palavra origina-se do inglês *database*. Seu primeiro registro oficial documentado remonta a 1962, em um relatório de uma empresa na Califórnia. O termo alternativo *data bank* caiu em desuso, embora tenha sido utilizado por Edgar Codd em seu artigo seminal de 1970.
* **Traduções Internacionais:** 

  * *Espanhol:* Base de datos
  * *Francês:* Base de données
  * *Alemão:* Datenbank
  * *Italiano:* Banca dati
* **Nuance da Língua Portuguesa:** No Brasil, a comunidade técnica costuma adotar uma distinção prática entre dois termos: 

  * *Banco de dados:* Sentido amplo. Refere-se a todo o ambiente computacional, incluindo o sistema, softwares e infraestrutura.
  * *Base de dados:* Sentido restrito. Refere-se exclusivamente ao conteúdo armazenado, ou seja, ao estado/instância atual dos dados. Um exemplo prático é a "Base de Dados da Receita Federal", que designa o conjunto de registros dos contribuintes, e não o software que os gerencia.
