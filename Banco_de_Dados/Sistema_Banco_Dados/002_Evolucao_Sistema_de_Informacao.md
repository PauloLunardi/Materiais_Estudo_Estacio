### Evolução dos Sistemas de Informação - SGBDs, Arquitetura Web e Big Data

### 1. Transição dos Sistemas de Arquivos para os Sistemas de Banco de Dados

A transição para os sistemas de banco de dados representou uma evolução arquitetural necessária para eliminar a duplicação de código de infraestrutura. 

### O Problema do Modelo de Arquivos Tradicional

* **Acoplamento de Código:** Nos sistemas de arquivos primitivos, os programas de aplicação precisavam implementar, além da própria regra de negócio, um módulo interno dedicado exclusivamente à gerência física dos arquivos (abertura, leitura, gravação e fechamento).
* **Redundância de Código:** Esse módulo de gerência de arquivos precisava ser replicado e reescrito em todos os programas de aplicação que precisassem acessar ou manipular os mesmos dados.

### O Surgimento do SGBD (A partir de 1960)

* **Solução:** Isolamento da responsabilidade de gerenciamento físico dos dados. Criou-se uma camada de software intermediária especializada.
* **SGBD (Sistema de Gerência de Banco de Dados):** Software encarregado de intermediar toda a comunicação entre as aplicações e os arquivos físicos gravados em disco.
* **Modularização:** O sistema de informação foi dividido. As aplicações focam estritamente nas regras de negócio e funcionalidades do usuário, enquanto o SGBD cuida do acesso físico aos dados em segundo plano (*back end*).
---
### 2. Propriedades e Conceitos Estruturais dos Sistemas de Dados

### Independência entre Dados e Programas

* É a capacidade de alterar a estrutura de armazenamento dos dados (física ou lógica) sem que seja necessário modificar ou reescrever os programas de aplicação que consomem esses dados.
* Representa a principal diferença técnica e vantagem competitiva dos SGBDs em relação aos sistemas de arquivos tradicionais.

### Diferenciação de Nomenclaturas Específicas

* **SGBD (Sistema de Gerência de Banco de Dados):** É o software motor, o gerenciador proprietário ou de código aberto (ex: Oracle, MySQL, PostgreSQL) que provê os serviços de manipulação, segurança e transações.
* **SBD (Sistema de Banco de Dados):** É um ecossistema muito mais amplo e abrangente. Ele engloba o SGBD, os bancos de dados armazenados, os programas de aplicação clientes e os usuários finais que interagem com o sistema.
---
### 3. O Estágio Atual dos Sistemas de Informação na Web

A arquitetura dos sistemas de informação sofreu profundas transformações a partir do final do século XX com o advento da *World Wide Web*. 

### O SGBD como Middleware

* Com a interface web e a arquitetura em camadas, o SGBD passou a operar como um *middleware*.
* **Middleware:** Software básico de papel intermediário que atua em conjunto com servidores de aplicação, APIs e ambientes de desenvolvimento web para conectar a interface do usuário às fontes de dados.

### Ecossistema Moderno de TI (Nuvem, Big Data e Multiplataforma)

* **Heterogeneidade de Formatos:** Os dados atuais superaram o limite dos bancos de dados relacionais estritos (tabelas e colunas). Os sistemas modernos gerenciam dados não estruturados e semiestruturados (textos, vídeos, logs, JSON).
* **Big Data:** Caracteriza-se pelo gerenciamento de volumes gigantescos de dados, produzidos em alta velocidade e provenientes de diversas fontes ou localizações.
* **Computação em Nuvem (Cloud Computing):** Os bancos de dados e aplicações migraram de servidores locais (*on-premises*) para infraestruturas globais distribuídas e escaláveis na nuvem.
* **Multiplataforma:** As aplicações web modernas consomem esses dados centralizados a partir de qualquer dispositivo conectado à internet, cobrindo o espectro desde computadores e smartphones até supercomputadores.
