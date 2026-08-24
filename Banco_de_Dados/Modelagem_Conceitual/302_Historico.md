# Modelo Entidade-Relacionamento: Quando Manter Histórico

## 1. Mapeamento Inicial da Relação Docente-Departamento

A decisão de preservar o histórico de alterações no banco de dados é estratégica, envolvendo requisitos de auditoria, análises temporais e conformidade regulatória. O cenário inicial mapeia uma associação estática comum em Instituições de Ensino Superior (IES). 

* **Requisitos de Dados Originais:** 

  * Todo departamento é identificado obrigatoriamente por um código exclusivo e possui um nome.
  * Um docente pode estar associado a, no máximo, um departamento da instituição.
* **Comportamento Lógico no DER:** A regra de que o professor pertence a apenas um setor é expressa pela cardinalidade máxima unitária 1 posicionada na linha de conexão oposta, junto à entidade de departamentos.

```mermaid

graph TD
    subgraph Exemplo_1 [1. Cenário Estático - Sem Manutenção de Histórico]
        DOCENTE["👥 DOCENTE<br/>(Matrícula, Nome)"]
        DEPARTAMENTO["🏢 DEPARTAMENTO<br/>(Código, Nome)"]
        
        PERTENCE((PERTENCE))
        
        DOCENTE -- "0,n" --- PERTENCE
        PERTENCE -- "0,1" ---> DEPARTAMENTO
    end

    style DOCENTE fill:#f9f,stroke:#333,stroke-width:2px
    style DEPARTAMENTO fill:#f9f,stroke:#333,stroke-width:2px
    style PERTENCE fill:#fff,stroke:#333,stroke-width:1px
````

## 2. Evolução dos Requisitos e Implementação do Histórico Temporizado

As necessidades institucionais podem evoluir ao longo do tempo, exigindo que o Diagrama Entidade-Relacionamento seja adaptado incrementalmente para suportar a rastreabilidade das informações passadas. 

* **Novos Requisitos de Dados (Evolução do Minimundo):** 

  * O banco de dados deve registrar compulsoriamente toda a movimentação de docentes entre os diferentes departamentos da IES.
  * A atuação e a permanência do docente em um determinado departamento passa a possuir uma data de início e uma data de fim bem definidas.
* **Impacto na Modelagem Conceitual:** Para refletir essa dinâmica de série temporal, o modelo precisa quebrar a restrição de unicidade anterior. A diferença crucial entre o DER original e o modificado resume-se a dois fatores técnicos: 

  1. *Alteração de Cardinalidade:* A cardinalidade máxima ao lado da entidade DEPARTAMENTO muda de **1** para **N**. Isso indica que, ao longo de seu ciclo profissional, o docente acumulou vínculos com diversos departamentos.
  2. *Inclusão de Atributos no Vínculo:* O relacionamento passa a carregar propriedades temporais próprias: os atributos Data_Início e Data_Fim.

```mermaid

graph TD
    subgraph Exemplo_2 [2. Cenário Dinâmico - Com Manutenção de Histórico]
        DOCENTE_H["👥 DOCENTE<br/>(Matrícula, Nome)"]
        DEPARTAMENTO_H["🏢 DEPARTAMENTO<br/>(Código, Nome)"]
        
        MOVIMENTACAO((MOVIMENTAÇÃO))
        ATRIBUTOS["Atributos do Vínculo:<br/>- (•) Data_Início<br/>- (○) Data_Fim"]
        
        DOCENTE_H -- "0,n" --- MOVIMENTACAO
        MOVIMENTACAO -- "0,n" --- DEPARTAMENTO_H
        MOVIMENTACAO -.-> ATRIBUTOS
    end

    style DOCENTE_H fill:#f9f,stroke:#333,stroke-width:2px
    style DEPARTAMENTO_H fill:#f9f,stroke:#333,stroke-width:2px
    style MOVIMENTACAO fill:#fff,stroke:#333,stroke-width:1px
    style ATRIBUTOS fill:#fffde7,stroke:#ffd54f,stroke-width:1px,stroke-dasharray: 5 5

```
