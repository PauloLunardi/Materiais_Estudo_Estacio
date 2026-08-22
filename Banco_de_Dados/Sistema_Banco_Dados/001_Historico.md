### ASSUNTO: Histórico e Tecnologias de Banco de Dados - Evolução dos Sistemas de Informação

### 1. Introdução ao Conceito de Banco de Dados

### Definição Técnica

O termo origina-se do inglês "database". Na literatura técnica, a definição clássica estabelece que um banco de dados é uma coleção de dados relacionados. 

* **Dados:** Fatos conhecidos que podem ser registrados e possuem um significado implícito.
* **Informação:** Dados processados, estruturados e contextualizados que geram conhecimento útil para a tomada de decisões.

### 2. Evolução da Arquitetura Computacional e Infraestrutura de Hardware

A evolução dos sistemas de armazenamento e organização de dados está diretamente atrelada ao desenvolvimento do hardware computacional. 

### Década de 1940: Computação Numérica Pura

* **Contexto:** Ao fim da Segunda Guerra Mundial, o computador operava estritamente como uma máquina voltada para cálculos matemáticos complexos.
* **Pioneirismo:** Esse modelo mecânico baseava-se em conceitos do século XIX, como a Máquina Diferencial N.1 de Charles Babbage (1791-1871), projetada para calcular tabelas matemáticas com alta precisão.

### Consolidação da Arquitetura Unificada

* **John von Neumann (1903-1957):** Propôs a arquitetura computacional moderna.
* **Mudança de Paradigma:** Introduziu uma Unidade Central de Processamento (CPU) que armazena, simultaneamente na mesma memória, tanto os programas (instruções) quanto os dados.
* **Impacto:** Transformou o computador de uma máquina de calcular em uma máquina de processamento de dados genérica.

### Revolução do Armazenamento de Acesso Direto (1957)

* **Invenção:** A IBM introduziu o disco magnético rígido (HD - Hard Disk).
* **Classificação Técnica:** Denominado DASD (Direct Access Storage Device - Dispositivo de Armazenamento de Acesso Direto).
* **Ruptura Tecnológica:** Permitiu a leitura e gravação de dados em posições específicas de forma imediata, quebrando a dependência da leitura estritamente sequencial das antigas fitas magnéticas e cartões perfurados.

### 3. Era do Processamento de Dados por Computador (CPD)

A introdução do armazenamento em disco rígido externo deu origem aos Centros de Processamento de Dados (CPDs). 

### O Modelo de Servidor e Sistemas de Arquivos

* **Estrutura:** Os programas de aplicação manipulavam arquivos de dados hospedados diretamente nos discos magnéticos, gerenciados pelo Sistema Operacional.
* **Avanço Inicial:** Representou uma evolução histórica ao separar os dados do código do programa (anteriormente, os dados eram inseridos de forma fixa dentro do código).
* **Modo de Operação:** Execução majoritariamente em lotes (Batch Processing), processando grandes volumes de registros de uma só vez, sem interatividade em tempo real.

### Linguagens de Programação Dominantes

* **COBOL (Common Business-Oriented Language):** Linguagem voltada para aplicações comerciais e administrativas empresariais.
* **Fortran (Formula Translation):** Linguagem otimizada para cálculos científicos e engenharia.

### 4. Comparativo: Sistemas de Arquivos vs. Bancos de Dados

O modelo pioneiro baseado em sistemas de arquivos apresentava limitações críticas que forçaram o desenvolvimento dos Sistemas de Gerenciamento de Bancos de Dados (SGBDs). 

### Limitações Técnicas dos Sistemas de Arquivos (Complemento)

* **Redundância de Dados:** O mesmo dado (como o endereço de um cliente) era replicado em vários arquivos de departamentos diferentes, gerando desperdício de espaço.
* **Inconsistência de Dados:** Devido à redundância, a atualização de um registro em um arquivo frequentemente não se propagava para os outros, gerando dados conflitantes.
* **Dependência entre Dados e Programas:** Se o formato físico de um arquivo mudasse, todos os programas de aplicação que o utilizavam precisavam ser reescritos e modificados.
* **Acesso Concorrente Limitado:** Dificuldade para permitir que múltiplos usuários ou programas atualizassem o mesmo arquivo simultaneamente sem corromper os dados.

### A Persistência dos Sistemas Legados

* O processamento de dados baseado em sistemas de arquivos tradicionais persiste até os dias atuais em sistemas legados.
* **Exemplo Histórico:** Durante a pandemia de COVID-19 (2020), a Administração Pública dos EUA enfrentou crises em sistemas governamentais devido à escassez de programadores COBOL, necessários para dar manutenção emergencial em estruturas baseadas em arquivos criadas há décadas.

### 5. Abstração e Conceito de Banco de Dados

Bancos de dados são componentes centrais dos Sistemas de Informação (SI) e existem desde que a humanidade começou a se organizar socialmente. 

### Transição dos Meios de Armazenamento

* **Era Pré-Computacional:** Bancos de dados existiam sob a forma de registros físicos em papel, organizados em fichários e pastas dentro de armários. O processo de busca e atualização era estritamente manual.
* **Transição Tecnológica:** A necessidade humana de organizar, relacionar e recuperar informações permanece constante; o que evolui rapidamente é a tecnologia física e lógica utilizada para sua implementação (Melo, Silva e Tanaka, 1998).
