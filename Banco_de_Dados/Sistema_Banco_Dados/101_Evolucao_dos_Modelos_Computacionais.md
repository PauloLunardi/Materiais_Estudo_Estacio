### Características dos Sistemas de Banco de Dados, Arquitetura ANSI/SPARC e Modelos de Dados

## 1. Arquitetura de Três Esquemas (ANSI/SPARC)

O conceito estrutural de independência de dados fundamenta-se na separação estrita entre as interfaces de uso final e a estrutura de armazenamento físico. A arquitetura de três esquemas divide a organização do banco de dados em três camadas abstratas independentes: 

* **Nível Externo (Esquema Conceitual Externo):** Camada de abstração mais alta. Consolida as diferentes visões personalizadas (*views*) dos usuários finais e dos programas de aplicação. Cada usuário acessa apenas uma fração específica dos dados totais que seja de seu interesse.
* **Nível Conceitual (Esquema Conceitual Lógico):** Camada intermediária de implementação. Descreve formalmente a estrutura lógica completa do banco de dados como um todo (entidades, atributos, relacionamentos e regras de restrição). Oculta totalmente os detalhes físicos e de hardware.
* **Nível Interno (Esquema Interno ou Físico):** Camada mais baixa. Define os mecanismos de armazenamento físico do banco de dados em disco rígido. Detalha aspectos técnicos como tipos de arquivos, estruturas de blocos, indexações, compressões e caminhos de acesso direto.

## 2. Conceito Ampliado de Independência de Dados

A arquitetura ANSI/SPARC estabelece o mapeamento entre os níveis, garantindo duas frentes principais de independência lógica e física: 

### Independência Lógica de Dados

* **Definição:** Capacidade de aplicar modificações estruturais ao esquema conceitual lógico sem que seja necessário reestruturar ou reescrever as visões externas do nível externo ou os programas de aplicação.
* **Exemplo:** Adicionar um novo campo de dados à tabela ou incluir uma nova entidade no banco. As aplicações legadas que ignoram esse campo continuam funcionando sem necessidade de adaptação ou recompilação de código.

### Independência Física de Dados

* **Definição:** Capacidade de modificar a estrutura de dados interna do nível interno (armazenamento físico) sem causar impactos ou necessidade de alterações no esquema conceitual lógico e, por extensão, no nível externo.
* **Exemplo:** Alterar a organização física dos arquivos em disco, trocar a tecnologia de indexação (de Árvore B para Hash), fragmentar tabelas ou migrar os arquivos para um novo hardware ou sistema de arquivos do S.O.

## 3. Atributos Diferenciais: SBD vs. Sistemas de Arquivos

Para além do isolamento entre códigos e conjuntos de dados, o paradigma dos Sistemas de Banco de Dados apresenta propriedades operacionais exclusivas: 

* **Natureza Autocontida (Self-Describing):** Um SBD armazena nativamente a descrição completa de todas as suas próprias estruturas, formatos de campos, relacionamentos e restrições de integridade. Essa coleção interna de descritores constitui os **metadados** (dados que descrevem os próprios dados) e reside no catálogo interno do sistema. Nos sistemas de arquivos convencionais, essa definição estrutural dependia de documentações externas ou de declarações codificadas de forma redundante dentro de cada programa.
* **Abstração de Dados:** Processo pelo qual o SGBD esconde as complexidades do hardware e do armazenamento de baixo nível de seus usuários. Realizada por meio da aplicação de modelos de dados, ela provê a base para o funcionamento de múltiplas visões e garante a integridade da independência de dados.
* **Compartilhamento de Dados e Concorrência:** O software SGBD possui subsistemas dedicados à coordenação de acessos simultâneos. Permite que centenas de usuários ou aplicações interajam cooperativamente e modifiquem o banco de dados de maneira concorrente sem causar inconsistências lógicas, violações de integridade ou colisões de arquivos (*deadlocks*).

## 4. Classificação dos Modelos de Dados

Os modelos de dados fornecem os esquemas conceituais necessários para a validação técnica das camadas de abstração. São classificados em três grandes vertentes hierárquicas: 

[Mundo Real / Usuário] Modelos Conceituais (Ex: Modelo ER / Classes UML)
          │
          ▼
[Implementação Abstrata] Modelos Lógicos (Ex: Relacional, NoSQL, Redes)
          │
          ▼
[Armazenamento Físico] Modelos Físicos (Ex: Arquivos, Índices, Blocos de Disco)

### Modelos Conceituais

* **Foco:** Visão de dados do ponto de vista do usuário final e das regras de negócio. Situam-se no nível de abstração mais alto, sem qualquer relação com tecnologias de implementação de software ou especificações técnicas de disco.
* **Modelo Entidade-Relacionamento (ER):** Criado por Peter Chen em 1976 para abstrair os cenários lógicos antes da implementação.
* **Modelo de Classes UML:** Desenvolvido no final da década de 1990 para uniformizar o desenvolvimento de Orientação a Objetos. Substitui na prática o modelo ER clássico nas fases primordiais do desenvolvimento de sistemas modernos, mapeando entidades e relacionamentos sob a ótica de classes e associações.

### Modelos Lógicos (ou de Implementação)

* **Foco:** Representação abstrata e técnica da base de dados, estabelecendo tabelas ou coleções de registros estruturadas, porém mantendo omitidos os detalhes de hardware.
* **Exemplos:** O clássico modelo relacional de tabelas, linhas e colunas (Edgar Codd), os modelos navegacionais primitivos (hierárquico e em rede) e as modernas variações de armazenamento estruturado não relacional do ecossistema NoSQL.

### Modelos Físicos

* **Foco:** Detalhamento exato de como as estruturas lógicas se traduzem em dados eletrônicos organizados no computador.
* **Elementos:** Envolvem a ordenação física dos registros de dados em partições, caminhos específicos de busca, ponteiros de baixo nível, alocação de setores em disco e configurações finas que dependem estritamente do motor interno do SGBD e do kernel do Sistema Operacional.
