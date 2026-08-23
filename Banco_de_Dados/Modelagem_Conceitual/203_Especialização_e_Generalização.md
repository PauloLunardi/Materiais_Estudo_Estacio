# Diagrama Entidade-Relacionamento (DER): Especialização/Generalização

## 1. Conceito e Herança de Propriedades

O mecanismo de especialização/generalização é um recurso do Modelo Entidade-Relacionamento Estendido (EER) utilizado para representar hierarquias, categorias e subtipos de dados dentro de um sistema de informação. 

* **Generalização:** Consiste no processo de abstração que identifica e captura as semelhanças entre diferentes entidades, agrupando suas propriedades comuns em uma entidade de nível superior mais genérica (supertipo).
* **Especialização:** Consiste no processo inverso, focando no detalhamento de características e atributos únicos pertencentes a subgrupos específicos de dados (subtipos).
* **Representação Gráfica:** O mecanismo é representado visualmente no diagrama por um **triângulo**. A entidade mais genérica (supertipo) localiza-se conectada à parte superior do triângulo, enquanto as entidades especializadas (subtipos) conectam-se à parte inferior.
* **Princípio da Herança:** Cada entidade especializada herda automaticamente todas as propriedades, atributos (inclusive o atributo identificador) e relacionamentos pertencentes à entidade mais genérica. 

  * *Exemplo Prático:* Na hierarquia de uma instituição de ensino, FUNCIONARIO é a entidade genérica, enquanto DOCENTE e ANALISTA são as entidades especializadas. O atributo id_funcionario e o nome residem em FUNCIONARIO, mas são herdados por DOCENTE e ANALISTA. O atributo específico graduação pertence exclusivamente à entidade DOCENTE.

## 2. Restrições e Classificações Técnicas

A modelagem de hierarquias exige a definição de restrições de restrição de integridade para ditar como as ocorrências das entidades especializadas se comportam em relação à entidade genérica. Essas restrições dividem-se em dois eixos de classificação combinatórios: 

* **Eixo de Completude (Total ou Parcial):** Responde se toda ocorrência da entidade genérica deve obrigatoriamente pertencer a pelo menos um dos subtipos. 

  * *Total (t):* Um registro na entidade genérica deve necessariamente ser classificado em um dos subtipos especializados. Não pode existir um supertipo puro.
  * *Parcial (p):* Permite a existência de ocorrências na entidade genérica que não se enquadram em nenhum dos subtipos especializados.
* **Eixo de Disjunção (Exclusiva ou Compartilhada):** Responde se uma ocorrência da entidade genérica pode pertencer simultaneamente a mais de um subtipo especializado. 

  * *Exclusiva (x):* Uma ocorrência do supertipo pode pertencer a, no máximo, um único subtipo. Os conjuntos são disjuntos.
  * *Compartilhada (c):* Uma ocorrência do supertipo pode se classificar e coexistir em múltiplos subtipos simultaneamente. Os conjuntos se sobrepõem.

## 3. Combinações e Aplicação no Estudo de Caso

As siglas representativas dessas regras (como tx, px, tc, pc) são grafadas diretamente no interior ou ao lado do triângulo de especialização no DER para formalizar o comportamento do negócio. 

* **Matriz de Combinações Possíveis:** 

  * **tx:** Total e Exclusiva.
  * **px:** Parcial e Exclusiva.
  * **tc:** Total e Compartilhada.
  * **pc:** Parcial e Compartilhada.
* **Análise das Regras de Negócio da Instituição de Ensino:** 

  * *Pergunta 1:* Pode existir um funcionário que não seja nem docente nem analista? **Sim**. (Indica que a especialização é **Parcial - p**). Significa que a instituição possui outros cargos cadastrados na base que não demandam tabelas especializadas próprias.
  * *Pergunta 2:* Pode existir um funcionário que exerça simultaneamente o papel de docente e a função de analista? **Sim**. (Indica que a especialização é **Compartilhada - c**). Significa que o mesmo ID de funcionário pode possuir registros ativos concomitantes em ambas as tabelas filhas.
* **Resultado do Modelo:** O triângulo de ligação recebe a marcação **(pc)**, consolidando uma hierarquia parcial e compartilhada conforme as necessidades validadas junto ao minimundo da organização.
