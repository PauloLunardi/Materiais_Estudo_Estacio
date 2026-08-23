# Sistema de Gerência de Banco de Dados

## 1. Módulos do SGBD e Perfis de Usuários

Um sistema de gerenciamento de banco de dados (SGBD) é responsável pelo gerenciamento de um ou mais bancos de dados. Seu principal objetivo é retirar da aplicação cliente a responsabilidade de gerenciar o acesso, a persistência, a manipulação e a organização dos dados. Os módulos que compõem o SGBD interagem com diferentes perfis de usuários e linguagens. 

* **Administradores de Banco de Dados (ABD / DBA):** 

  * Utilizam a Linguagem de Definição de Dados (LDD / DDL) para criar, alterar ou remover objetos da estrutura do banco (comandos CREATE, ALTER, DROP no padrão SQL). Essas definições alteram metadados que ficam salvos no catálogo do sistema.
  * Possuem privilégios para executar comandos da Linguagem de Controle de Dados (LCD / DCL), concedendo ou revogando permissões de acesso (GRANT e REVOKE no padrão SQL). O destino dessas instruções é o processador de runtime.
* **Usuários Casuais:** 

  * Realizam consultas interativas diretamente por meio de interfaces voltadas para pesquisas *ad hoc* (consultas não programadas previamente).
  * Utilizam tipicamente o comando SELECT do padrão SQL, que é enviado a um compilador de linguagem de consulta e passa por um otimizador antes de atingir o nó central do SGBD.
* **Programadores de Aplicações:** 

  * Desenvolvem softwares em linguagens hospedeiras (como Java, PHP ou Python) embutindo instruções de consulta, inserção, atualização e exclusão de dados.
  * Utilizam a Linguagem de Manipulação de Dados (LMD / DML) por meio dos comandos INSERT, UPDATE e DELETE no padrão SQL, atuando diretamente sobre os dados armazenados (e não sobre os metadados).

## 2. Processamento de Aplicações e Usuários Paramétricos

Os programas de aplicação executam fluxos híbridos que misturam a sintaxe da linguagem de programação hospedeira com as instruções de manipulação de banco de dados, exigindo etapas específicas de compilação. 

* **Fluxo de Compilação Híbrida:** 

  * *Pré-compilador:* É o módulo encarregado de analisar o código-fonte da aplicação, isolar os comandos de banco de dados das instruções nativas da linguagem de programação e repassá-los aos seus respectivos compiladores.
  * *Compiladores:* Processam os códigos separados e geram as transações executáveis que serão disponibilizadas para uso nas interfaces finais.
* **Usuários Paramétricos:** 

  * Perfil de usuário final que interage com o sistema exclusivamente por meio de parâmetros preenchidos em formulários e interfaces visuais prontas.
  * *Exemplo Prático:* Um agente de viagens que realiza a reserva de uma passagem aérea fornecendo campos fixos ao sistema, como nome do passageiro, data, horário, número do voo e assento escolhido.
* **Validação via Catálogo:** 

  * Durante o processo de compilação da LMD e otimização de consultas, o SGBD realiza fluxos de controle constantes (representados por linhas tracejadas em diagramas arquiteturais) consultando o catálogo.
  * Essa validação é obrigatória para certificar que os objetos (tabelas e colunas) referenciados pelo código da aplicação de fato existem e estão consistentes com as estruturas criadas previamente pelo DBA através da DDL.

## 3. Processamento de Runtime e Acesso Armazenado

A metade inferior da arquitetura de um SGBD gerencia a execução dos comandos validados e faz a interface direta com as mídias de armazenamento físico. 

* **Processador de Runtime (Runtime Engine):** 

  * Considerado o coração ou nó central do SGBD. É o componente encarregado de processar e executar as transações compiladas e os comandos enviados por todas as categorias de usuários em tempo de execução.
  * A eficiência desse mecanismo constitui o principal diferencial comercial e segredo industrial dos grandes fornecedores de SGBD proprietários do mercado.
* **Interação com o Catálogo e a Base:** 

  * O processador de runtime consulta e, dependendo da operação executada, modifica os registros contidos no catálogo do sistema.
  * O acesso direto aos arquivos da base de dados ocorre sob a supervisão estrita de subsistemas de segurança, tratamento de falhas, rotinas de backup e controle de concorrência.
* **Gerenciador de Dados Armazenados:** 

  * É o módulo de baixo nível acionado diretamente pelo processador de runtime sempre que há necessidade de efetuar operações físicas de entrada e saída (leitura e gravação) nas trilhas do disco rígido.
