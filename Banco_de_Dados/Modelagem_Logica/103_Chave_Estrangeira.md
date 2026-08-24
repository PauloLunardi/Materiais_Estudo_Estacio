# Banco de Dados: Chave Estrangeira e Integridade Referencial

### 1. O Conceito de Chave Estrangeira e Vínculo entre Tabelas

Em um banco de dados relacional, as informações não ficam isoladas. A conexão lógica e coesa entre diferentes tabelas é estabelecida por meio de uma restrição chamada **Chave Estrangeira (FK - Foreign Key)**. 

* **Definição Técnica:** Segundo Heuser (2009), uma chave estrangeira é uma coluna (ou uma combinação de colunas) cujos valores obrigatoriamente aparecem cadastrados na chave primária de uma tabela referenciada.
* **Garantia de Conexão:** A FK atua como um elo inteligente que estabelece e valida os relacionamentos de negócios, transcendendo as fronteiras físicas de tabelas distintas.
* **Convenção de Nomenclatura:** Embora seja permitido dar nomes diferentes para a chave primária e a chave estrangeira que se conectam, manter exatamente o mesmo nome nas duas tabelas é uma boa prática de projeto que facilita a identificação rápida das colunas relacionadas pelas equipes de TI.

## 2. Análise Prática de Integridade Referencial (Funcionário vs. Dependente)

Para compreender a mecânica de uma chave estrangeira, analisa-se o comportamento de duas estruturas correlatas de uma empresa: a tabela de titulares e a tabela de seus respectivos familiares. 

### Tabela: FUNCIONARIO (Tabela Pai / Referenciada)
Contém a lista de funcionários ativos, onde CODIGOFUNCIONARIO atua como a Chave Primária (PK) simples. 

CODIGOFUNCIONARIO (PK) | NOME DA TABELA: FUNCIONARIO
-----------------------|----------------------------
1                      | Jose Maciel
2                      | Pedro Antonio
3                      | Maria Conceicao
4                      | Carlos Alberto


### Tabela: DEPENDENTE (Tabela Filho / Dependente)
Contém os familiares vinculados. O campo CODIGOFUNCIONARIO nesta estrutura atua como a **Chave Estrangeira (FK)** que aponta para a tabela pai. 

CODIGOFUNCIONARIO (FK) | NRDEPENDENTE | NOME DO DEPENDENTE
-----------------------|--------------|-------------------
1                      | 1            | Andrey Campos
1                      | 2            | Manoel Oliveira
2                      | 1            | Joao Silva
2                      | 2            | Jose Maciel


### Interpretações Lógicas do Modelo:

* **Vinculação Obrigatória:** Todo dependente está associado a um funcionário existente. O valor 1 em CODIGOFUNCIONARIO na tabela de dependentes identifica que José Maciel é o responsável por Andrey e Manoel.
* **Multiplicidade (1:N):** Um funcionário pode possuir múltiplos dependentes. O código 2 repete-se nas duas últimas linhas de DEPENDENTE, indicando que Pedro Antônio possui dois familiares associados.
* **Participação Opcional:** Um funcionário pode não possuir nenhum dependente cadastrado. O código 3 (Maria Conceição) existe na tabela pai, mas não possui nenhuma ocorrência correspondente na tabela filho.

### 3. Restrições Operacionais Impostas pelo SGBD

Para assegurar o princípio da **Integridade Referencial** — garantindo que nenhuma chave estrangeira aponte para um registro inexistente —, o motor do SGBD monitora e intercepta quatro operações críticas no ciclo de vida dos dados: 

* **Inclusão de Linhas na Tabela Filho:** Ao cadastrar um novo dependente, o SGBD barra a operação caso o usuário tente inserir um código de funcionário inválido. O campo FK só pode assumir valores que já existam na PK da tabela pai (neste exemplo, valores de 1 a 4).
* **Alteração de Valor da Chave Estrangeira:** Se houver a transferência de responsabilidade de um dependente para outro funcionário, o novo código inserido na FK deve constar obrigatoriamente na tabela de origem.
* **Exclusão de Linhas na Tabela Pai:** O sistema impede a remoção de um funcionário que possua dependentes vinculados a ele. No exemplo, os funcionários de código 1 e 2 não podem ser excluídos da tabela FUNCIONARIO enquanto suas respectivas linhas existirem em DEPENDENTE, evitando que os dependentes fiquem órfãos no sistema.
* **Alteração de Valor da Chave Primária:** Se o código identificador de um funcionário for modificado na tabela pai (ex: mudar o código de 2 para 5 em FUNCIONARIO), o SGBD exige regras de propagação (como o *Cascade Update*) para replicar e atualizar essa alteração automaticamente nas linhas correspondentes da tabela DEPENDENTE.
