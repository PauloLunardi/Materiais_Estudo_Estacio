# Modelagem de Atributos: Atributo vs. Entidade

## 1. O Problema dos Atributos Multivalorados Textuais

A decisão estratégica entre modelar uma informação como atributo ou como uma entidade independente molda a estrutura do sistema, impactando diretamente a consistência e a eficiência de armazenamento do banco de dados. 

* **Cenário Inicial (Mapeamento por Atributo):** No modelo acadêmico base, a exigência de que todo professor registre suas formações foi inicialmente mapeada por meio de um atributo multivalorado GRADUACAO com cardinalidade (1,n) conectado à entidade DOCENTE.
* **Riscos de Redundância e Inconsistência:** 

  * Manter a formação como um campo de texto livre e multivalorado faz com que o nome de um mesmo curso (ex: "Ciência da Computação") seja digitado e repetido centenas de vezes no banco de dados.
  * Essa abordagem abre margem para erros de digitação e variações textuais (ex: "Ciência da Comp.", "Computação", "Ciência da Computacao"), o que inviabiliza buscas precisas, relatórios confiáveis e filtros estatísticos no sistema.

```mermaid
graph LR
    subgraph Exemplo_1 [1. Cenário Primitivo - Graduação como Atributo Multivalorado]
        DOCENTE["👥 DOCENTE<br/>(Matrícula, Nome)"]
        GRAD["(○) GRADUACAO (1,n)<br/>[Atributo Multivalorado]"]
        
        DOCENTE --- GRAD
    end

    style DOCENTE fill:#e3f2fd,stroke:#1e88e5,stroke-width:2px
    style GRAD fill:#fff,stroke:#333,stroke-width:1px
````

## 2. Critérios para Conversão de Atributo em Entidade

A evolução de um atributo para uma entidade própria torna-se obrigatória e tecnicamente vantajosa quando o objeto analisado passa a demandar propriedades adicionais ou quando se deseja padronizar o catálogo de informações. 

* **Gatilho de Mudança:** Se além do nome da formação, o negócio exigir o rastreamento de novas propriedades correlatas — como o ano de conclusão ou a instituição de ensino —, o atributo deixa de ser simples e **deve ser promovido a uma Entidade**.
* **Comportamento Lógico do Novo Modelo:** No diagrama modificado, o objeto transforma-se na entidade GRADUACAO, interagindo com o professor através do relacionamento DOCENTEGRAD: 

  * *Independência do Cadastro:* O par (0,n) ao lado de DOCENTE indica que os cursos de graduação podem ser previamente cadastrados no sistema de forma independente, antes mesmo de haver qualquer professor formado neles.
  * *Obrigatoriedade:* O par (1,n) ao lado de GRADUACAO assegura a regra de negócio de que todo docente possua, no mínimo, uma formação vinculada.
  * *Atributos de Relacionamento:* Propriedades que dependem estritamente da união entre as duas partes — como o ano de término daquele professor específico (ANOFIM) — são anexadas diretamente ao losango do relacionamento DOCENTEGRAD.

```mermaid

graph LR
    subgraph Exemplo_2 [2. Cenário Evoluído - Graduação Promovida a Entidade]
        DOCENTE_E["👥 DOCENTE<br/>(Matrícula, Nome)"]
        GRADUACAO["🎓 GRADUACAO<br/>(Código_ID, Nome_Curso)"]
        
        DOCENTEGRAD{DOCENTEGRAD}
        ANOFIM["(○) ANOFIM<br/>[Atributo do Vínculo]"]
        
        DOCENTE_E -- "1,n" --- DOCENTEGRAD
        DOCENTEGRAD -- "0,n" ---> GRADUACAO
        DOCENTEGRAD -.-> ANOFIM
    end

    style DOCENTE_E fill:#e3f2fd,stroke:#1e88e5,stroke-width:2px
    style GRADUACAO fill:#e3f2fd,stroke:#1e88e5,stroke-width:2px
    style DOCENTEGRAD fill:#fff,stroke:#333,stroke-width:1px
    style ANOFIM fill:#fffde7,stroke:#ffd54f,stroke-width:1px,stroke-dasharray: 5 5
````

## 3. Critério de Decisão: Atributo vs. Especialização

Outro dilema comum na modelagem conceitual reside em decidir se um determinado subgrupo de informações deve ser tratado apenas como um atributo comum ou se exige a criação de uma estrutura de especialização/generalização. 

* **A Regra de Ouro da Modelagem:** O critério técnico para tomar essa decisão é direto e baseia-se na presença de dependências estruturais: 

  * Se o objeto em questão possuir **atributos próprios** específicos ou **relacionamentos exclusivos** com outras tabelas do sistema, ele deve ser modelado obrigatoriamente como uma **Especialização**.
  * Se o objeto contiver apenas uma informação simples de classificação que não se conecta a mais nada, ele deve ser mantido puramente como um **Atributo**.
* **Validação do Caso Real:** No modelo consolidado, a entidade genérica FUNCIONARIO foi especializada gerando o subtipo DOCENTE exatamente porque os professores demandavam uma conexão exclusiva com a tabela GRADUACAO, comprovando a aplicação correta do critério de engenharia.
