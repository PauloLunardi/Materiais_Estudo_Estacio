# Diagrama Entidade-Relacionamento (DER): Atributo

## 1. Conceito e Classificação de Unicidade

Os atributos correspondem às propriedades e características que descrevem as entidades e os relacionamentos dentro de um minimundo. Segundo a definição de Heuser (2009), um atributo é um dado associado a cada ocorrência de uma entidade ou de um relacionamento. 

* **Atributo Identificador:** 

  * É um tipo especial de atributo cujos valores são estritamente exclusivos para cada ocorrência da entidade, garantindo que não existam registros duplicados.
  * *Exemplo Prático:* O atributo CODIGOCURSO possui um valor único para cada curso cadastrado, assim como CODIGODISCIPLINA diferencia cada uma das disciplinas.
  * *Representação Gráfica:* É expresso visualmente por um **traço com uma das extremidades contendo um círculo totalmente preenchido**.

## 2. Restrições e Cardinalidade de Atributos

A participação e a multiplicidade de valores que um atributo pode aceitar no sistema são determinadas pelo seu par ordenado de cardinalidade, expresso sob a forma **(mínima, máxima)**. 

* **Cardinalidade Mínima (Obrigatoriedade):** 

  * **0:** Indica que o atributo é opcional (não obrigatório). Sua representação gráfica apresenta um **círculo pontilhado** na extremidade.
  * **1:** Indica que o atributo é de preenchimento estritamente obrigatório.
* **Cardinalidade Máxima (Multiplicidade):** 

  * **1:** Indica um atributo monovalorado (armazena apenas um valor por registro).
  * **N:** Indica um atributo multivalorado (pode armazenar múltiplos valores para o mesmo registro, como vários telefones).
* **Mapeamento de Propriedades por Cardinalidade:** 

  * *(0,1):* Opcional e Monovalorado.
  * *(0,N):* Opcional e Multivalorado.
  * *(1,1):* Obrigatório e Monovalorado.
  * *(1,N):* Obrigatório e Multivalorado.
* **Convenção de Legibilidade:** Na construção de um DER, a grande maioria dos atributos é obrigatória e monovalorada. Para evitar a poluição visual do diagrama, adota-se a convenção de **omitir a exibição da cardinalidade (1,1)**. Portanto, se um atributo não apresentar nenhuma cardinalidade explícita no modelo, ele deve ser considerado obrigatoriamente como monovalorado e obrigatório.

## 3. Estruturas de Atributos Complexos e Modelo Estendido

À medida que as regras de negócio de uma organização se tornam mais detalhadas, a modelagem exige estruturas de atributos ramificadas ou o uso de conceitos semânticos avançados. 

* **Atributo Composto:** 

  * Caracteriza-se por propriedades complexas que podem ser logicamente subdivididas em partes menores e independentes para facilitar a indexação ou a busca no sistema.
  * *Exemplo Prático:* O atributo composto endereço pode ser decomposto e estruturado em subelementos como logradouro, complemento, CEP e cidade.
* **Modelo de Entidade e Relacionamento Estendido (EER):** 

  * Introduz novos componentes conceituais e semânticos para mapear relacionamentos altamente complexos que o modelo conceitual clássico não cobre nativamente.
  * Engloba o estudo de estruturas avançadas de **especialização / generalização** (conceito semelhante à herança da programação) e a modelagem de **entidades associativas**.
