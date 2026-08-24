### Modelo Entidade-Relacionamento: Modelagem na Prática (Estudo de Caso TV a Cabo)

### 1. Abordagem Metodológica para Casos de Uso

A resolução prática de um problema de modelagem de dados a partir de um minimundo descritivo exige a quebra do texto em componentes atômicos. O processo deve seguir rigorosamente um roteiro estruturado de quatro passos fundamentais. 

* **Passo 1:** Identificar no texto descritivo todas as entidades tipo (objetos com existência independente) e representá-las graficamente no modelo utilizando retângulos.
* **Passo 2:** Identificar no texto descritivo os relacionamentos tipo (as interações e associações de negócios) e desenhá-los no diagrama por meio de losangos.
* **Passo 3:** Estabelecer e validar os pares ordenados de cardinalidade mínima e máxima para cada ponta dos relacionamentos mapeados.
* **Passo 4:** Modelar e anexar detalhadamente os atributos (identificadores, obrigatórios ou opcionais) aos seus respectivos elementos.

### 2. Organograma Lógico do DER (Solução TV a Cabo)

Abaixo está o diagrama estrutural que mapeia o ecossistema de faturamento, assinaturas e serviços da empresa de TV a Cabo, garantindo a integridade referencial do sistema de cobrança automatizado. 

```mermaid
graph LR
    %% Entidades Principais (Em tons de azul moderno)
    CANAL["📺 CANAL<br/>• (•) NUMERO<br/>• (○) NOME"]
    PACOTE["📦 PACOTE<br/>• (•) NOME<br/>• (○) PRECO"]
    CLIENTE["👤 CLIENTE<br/>• (•) CPF<br/>• (○) NOME<br/>• (○) EMAIL (0,n)<br/>• (○) Atributo_1<br/>• [Logradouro, Numero, Complemento, CEP]"]
    ASSINATURA["📝 ASSINATURA<br/>• (•) CODIGO<br/>• (○) DT ATIVACAO<br/>• (○) DATA DESATIVACAO<br/>• (○) ENDEREÇO DE INSTALACAO"]

    %% Relacionamentos e Cardinalidades Reversas
    CANAL -- "1,n" --- POSSUI_1{POSSUI}
    POSSUI_1 -- "1,1" ---> PACOTE

    PACOTE -- "1,1" --- POSSUI_2{POSSUI}
    POSSUI_2 -- "1,n : 0,n" ---> ASSINATURA

    CLIENTE -- "1,1" --- FAZ{FAZ}
    FAZ -- "1,n" ---> ASSINATURA

    %% Estilização Visual Customizada
    style CANAL fill:#e3f2fd,stroke:#1e88e5,stroke-width:2px
    style PACOTE fill:#e3f2fd,stroke:#1e88e5,stroke-width:2px
    style CLIENTE fill:#e3f2fd,stroke:#1e88e5,stroke-width:2px
    style ASSINATURA fill:#e3f2fd,stroke:#1e88e5,stroke-width:2px
    style POSSUI_1 fill:#fff,stroke:#333,stroke-width:1px
    style POSSUI_2 fill:#fff,stroke:#333,stroke-width:1px
    style FAZ fill:#fff,stroke:#333,stroke-width:1px
```

### 3. Dicionário e Regras de Negócio do Diagrama

O fluxo operacional do sistema de cobrança automatizado distribui-se em três eixos de associação lógicas fundamentais expressas pelas caixas do organograma: 

* **Eixo de Assinatura (ASSINANTE e CONTRATO):** 

  * Um assinante pode possuir um ou vários contratos ativos ou históricos com a empresa (1,n).
  * Cada contrato deve estar vinculado obrigatoriamente a um único assinante responsável pelo faturamento (1,1).
* **Eixo de Pacotes (CONTRATO e PLANO_SERVIÇO):** 

  * Um plano de serviço pode estar presente em zero ou múltiplos contratos da base de clientes (0,n).
  * Cada contrato adere obrigatoriamente a pelo menos um plano de serviço específico oferecido pela operadora (1,1).
* **Eixo de Faturamento (CONTRATO e FATURA_COBRANÇA):** 

  * Um contrato gera, ao longo do tempo, uma série histórica de faturas mensais de cobrança (1,n).
  * Cada fatura de cobrança é gerada e emitida de forma exclusiva contra um único contrato correspondente no sistema (1,1).
