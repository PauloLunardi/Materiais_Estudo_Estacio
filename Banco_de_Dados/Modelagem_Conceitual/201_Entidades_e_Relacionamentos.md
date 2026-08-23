# Entidades e Relacionamentos

## 1. Conceitos de Entidade, Relacionamento e Autorrelacionamento

A modelagem visual por meio do Diagrama Entidade-Relacionamento (DER) funciona como uma ferramenta essencial na concepção e comunicação de estruturas de dados, proporcionando uma visão intuitiva dos componentes do sistema. 

* **Entidade:** 

  * Segundo a definição clássica da literatura técnica (HEUSER, 2009), corresponde à representação de um conjunto de objetos da realidade modelada sobre os quais se deseja manter informações no banco de dados.
  * *Representação Gráfica:* É expressa por um **retângulo** contendo o nome do conjunto em seu interior (ex: o retângulo ALUNO representa o conjunto de todos os alunos cadastrados).
* **Relacionamento:** 

  * Caracteriza-se como a propriedade da entidade que especifica as associações entre os objetos, correspondendo a um conjunto de conexões entre ocorrências de entidades (HEUSER, 2009).
  * *Representação Gráfica:* É expresso por um **losango** conectado por linhas diretas às entidades participantes. Todo relacionamento pressupõe a existência prévia dos objetos das entidades envolvidas.
* **Autorrelacionamento:** 

  * Ocorre quando um relacionamento envolve ocorrências pertencentes a uma mesma e única entidade. Nesses cenários, torna-se obrigatório diferenciar o papel que cada ocorrência cumpre na associação.
  * *Exemplo Prático (Pré-requisito de Disciplinas):* Na estrutura da entidade DISCIPLINA, o relacionamento PREREQUISITO divide-se em dois conjuntos conceituais: 

    * *Conjunto de Objetos:* As disciplinas mapeadas na base de dados.
    * *Conjunto de Associações:* Cada registro vincula uma disciplina **liberadora** (aquela que o aluno precisa ter cumprido previamente) a uma disciplina **liberada** (aquela que o aluno ganha o direito de cursar). No caso real, Cálculo I atua como a liberadora e Cálculo II como a liberada.

## 2. Restrições de Cardinalidade em Relacionamentos

A especificação de como as entidades se associam no mundo real exige a definição de limites de participação, mapeados no DER por meio do conceito de cardinalidade. 

* **Definição de Cardinalidade:** É representada graficamente por um par ordenado sob a forma **(mínima, máxima)** posicionado ao lado das linhas de conexão. 

  * *Cardinalidade Mínima:* Assume os valores lógicos **0** (participação opcional) ou **1** (participação obrigatória).
  * *Cardinalidade Máxima:* Assume os valores lógicos **1** (associação unitária) ou **N** (associação múltipla, representando valores maiores que a unidade).
* **Regra de Interpretação por Convenção:** Cada par ordenado de cardinalidade posicionado no diagrama diz respeito à participação da entidade localizada no **lado oposto** do relacionamento em questão.
* **Análise de Estudo de Caso (Relacionamento POSSUI entre CURSO e DISCIPLINA):** 

  * *Pergunta 1:* Toda disciplina, para existir no banco de dados, tem de estar associada a algum curso? **Não** (cardinalidade mínima 0 expressa ao lado da entidade CURSO, mapeando o comportamento da disciplina).
  * *Pergunta 2:* Uma disciplina pode estar associada a, no máximo, quantos cursos? **Vários** (cardinalidade máxima N expressa ao lado da entidade CURSO).
  * *Pergunta 3:* Todo curso, para existir no banco de dados, deve estar associada a alguma disciplina? **Não** (cardinalidade mínima 0 expressa ao lado da entidade DISCIPLINA, mapeando o comportamento do curso).
  * *Pergunta 4:* Um curso pode estar associado a, no máximo, quantas disciplinas? **Várias** (cardinalidade máxima N expressa ao lado da entidade DISCIPLINA).

## 3. Estruturas Complexas: Relacionamento Ternário

Quando uma regra de negócio exige a associação simultânea de três entidades distintas para fazer sentido lógico, utiliza-se a modelagem de um relacionamento ternário. 

* **Cenário Prático (Orientação de Projetos):** A modelagem de orientações acadêmicas envolve três informações que precisam coexistir na mesma ocorrência de vínculo: a entidade PROJETO, a entidade ALUNO e a entidade DOCENTE.
* **Interpretação de Cardinalidades em Modelos Ternários:** Em um relacionamento de três vias, a especificação e a leitura de cada par de cardinalidade máxima são determinadas com base na relação combinada existente entre as **duas entidades restantes**: 

  * *Cardinalidade Máxima 1 (ao lado de DOCENTE):* Diz respeito ao par combinado (ALUNO, PROJETO). Determina que um aluno específico participante de um projeto determinado pode ser orientado por, no máximo, **um** docente orientador.
  * *Cardinalidade Máxima N (ao lado de ALUNO):* Diz respeito ao par combinado (DOCENTE, PROJETO). Determina que um docente participante de um projeto específico pode orientar **diversos** alunos dentro daquele mesmo contexto.
  * *Cardinalidade Máxima N (ao lado de PROJETO):* Diz respeito ao par combinado (ALUNO, DOCENTE). Determina que uma combinação fixa de um aluno e seu docente orientador pode participar e desenvolver **vários** projetos simultaneamente.
