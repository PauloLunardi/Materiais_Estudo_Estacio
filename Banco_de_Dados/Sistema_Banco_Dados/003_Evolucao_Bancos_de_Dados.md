### Evolução dos SGBDs
- Modelos Navegacionais (Rede e Hierárquico) e o Surgimento do Modelo Relacional
---
### 1. Primeiros Modelos de Dados (Década de 1960)

Com a integração efetiva dos computadores nas empresas e o aumento na capacidade de armazenamento, surgiram os primeiros modelos formais de dados para substituir os registros impressos e os arquivos primitivos. 

### Características Comuns (SGBDs Navegacionais)

* **Acesso aos Dados:** Os programas de aplicação precisavam "navegar" de forma explícita e sequencial de registro em registro pela estrutura física armazenada em disco.
* **Complexidade:** Exigiam que o programador conhecesse profundamente a estrutura física dos dados e dos ponteiros para conseguir recuperar qualquer informação.

### O Modelo em Rede

* **Produto Pioneiro:** *Integrated Data Systems* (IDS), criado por Charles Bachman (1924-2017) no âmbito do comitê *CODASYL* (responsável também pela padronização do COBOL).
* **Estrutura de Dados:** Utilizava a estrutura de **grafos ou redes** (*network databases*).
* **Flexibilidade:** Permitia que um registro filho tivesse múltiplos registros pais (relacionamentos N:M complexos via ponteiros).

### O Modelo Hierárquico

* **Produto Pioneiro:** *Information Management System* (IMS), desenvolvido pela IBM impulsionado pelo sucesso do disco magnético.
* **Estrutura de Dados:** Utilizava a estrutura de **árvores** (*hierarchical databases*), que é um tipo de grafo restrito baseado em hierarquias rígidas.
* **Restrição:** Cada registro filho podia possuir apenas um único registro pai (relacionamentos estritamente 1:N).

### Persistência de Mercado

* Variantes desses modelos foram amplamente implementadas, como o *DMS* e o *IDMS*.
* **Sistemas Legados:** Assim como o ecossistema de arquivos de dados, muitos sistemas legados corporativos de grande porte ainda operam sobre esses SGBDs navegacionais.
---
### 2. A Revolução do Modelo Relacional (Virada de 1960 para 1970)

O surgimento do modelo relacional quebrou o paradigma dos bancos de dados navegacionais, separando a lógica do usuário da implementação física no disco. 

### O Artigo Seminal de Edgar Codd

* **Autor:** Edgar Frank Codd, matemático e pesquisador da IBM.
* **Marco Histórico:** Publicação do artigo *"A Relational Model of Data for Large Shared Data Banks"*, uma das obras científicas mais citadas na história da computação.

### Fundamentação Teórica e Simplicidade Prática

* **Base Matemática:** O modelo foi construído sobre uma sólida fundamentação matemática chamada **relação** (uma função matemática), operada por meio da **álgebra relacional** e do **cálculo relacional**.
* **Abstração de Tabela:** Apesar do rigor matemático subjacente, a visualização dos dados para o usuário foi simplificada em uma **tabela formada por linhas (tuplas) e colunas (atributos)**.
* **Legibilidade:** Tornou a estrutura de dados compreensível tanto para especialistas quanto para leigos, abandonando os complexos emaranhados de ponteiros dos modelos de grafos e árvores.
---
### 3. Primeiras Iniciativas de Implementação Relacional

O sucesso teórico do artigo de Codd motivou o desenvolvimento dos primeiros protótipos de SGBDs relacionais no ambiente empresarial e acadêmico da Califórnia. 

### Iniciativa Empresarial: System R

* **Desenvolvedor:** IBM (financiadora e patrocinadora do projeto).
* **Objetivo:** Demonstrar a viabilidade prática e comercial da teoria do modelo relacional formulada por Codd.

### Iniciativa Acadêmica: Ingres

* **Desenvolvedor:** Universidade da Califórnia em Berkeley (UCB).
* **Nome Técnico:** *Interactive Graphics Retrieval System* (Ingres).
* **Impacto:** Serviu como base de código aberto para o nascimento de diversos SGBDs relacionais modernos de mercado importantes nas décadas seguintes.
