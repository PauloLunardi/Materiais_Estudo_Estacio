# Engenharia, Processos e Atributos da Qualidade de Software

## 1. Engenharia de Software vs. Qualidade
A relação entre Engenharia de Software e Qualidade não é de oposição, mas de **interdependência**. 

* **Engenharia de Software:** É a aplicação prática de conhecimento científico e tecnológico na criação de sistemas de software. Foca no *como* construir (arquitetura, prazos, custos, gerenciamento).
* **Qualidade de Software:** É o balizador da Engenharia. Ela define os critérios e padrões que determinam se o que foi construído possui valor real, segurança e confiabilidade. 

```
[ENGENHARIA DE SOFTWARE] (Métodos, Ferramentas e Processos)
       |
       | (Devem caminhar juntas)
       v
[QUALIDADE DE SOFTWARE] (Critérios, Padrões e Confiabilidade)
```

---

## 2. Qualidade, Processo, Método e Ferramentas
A Engenharia de Software é uma tecnologia em camadas. A qualidade é a base que sustenta todas as outras três camadas fundamentais:

```
( Camada 4 ) FERRAMENTAS --> Suporte automatizado (Ex: Git, CI/CD)
( Camada 3 ) MÉTODOS     --> Como fazer tecnicamente (Ex: UML, TDD)
( Camada 2 ) PROCESSO    --> Estrutura de trabalho (Ex: Scrum, XP)
( Camada 1 ) QUALIDADE   --> O alicerce e compromisso com a excelência
```

* **Foco na Qualidade:** A base de tudo. O compromisso organizacional com a melhoria contínua e a redução de falhas.
* **Processo:** A estrutura de suporte que conecta todas as etapas. Ele define quem faz o quê, quando faz e como gerenciar o fluxo de trabalho.
* **Métodos:** Fornecem as orientações técnicas para construir o software. Envolvem a análise de requisitos, modelagem, codificação, testes e suporte.
* **Ferramentas:** Fornecem suporte automatizado ou semiautomatizado para os processos e métodos.

---

## 3. Metodologia de Processo Genérica (Pressman, 2016)
De acordo com Roger Pressman, independentemente do tamanho ou complexidade do projeto, o desenvolvimento de software adota uma estrutura de processo genérica composta por **cinco atividades metodológicas fundamentais**:

```
COMUNICAÇÃO --> PLANEJAMENTO --> MODELAGEM --> CONSTRUÇÃO --> IMPLANTAÇÃO
```

1. **Comunicação:** Reunião inicial e colaboração intensa com o cliente para entender os objetivos do projeto e levantar os requisitos.
2. **Planejamento:** Criação do mapa de desenvolvimento. Define riscos, recursos, cronograma e produtos a serem entregues.
3. **Modelagem:** Criação de designs e diagramas de arquitetura para que a equipe e o cliente compreendam a estrutura do sistema antes de codificar.
4. **Construção:** Combinação da geração de código (programação) com os testes necessários para descobrir e corrigir erros.
5. **Implantação:** Entrega do software (ou incremento) ao cliente, seguida pela avaliação do feedback recebido.

---

## 4. Qualidade do Produto (Fatores de Qualidade)
A qualidade de um produto de software é mensurada através de características específicas divididas em três grandes frentes:

```
QUALIDADE DO PRODUTO
  |
  +--> OPERAÇÃO (Correção, Confiabilidade, Eficiência, Integridade, Usabilidade)
  |
  +--> REVISÃO  (Facilidade de Manutenção, Flexibilidade, Testabilidade)
  |
  +--> TRANSIÇÃO (Portabilidade, Reusabilidade, Interoperabilidade)
```

### Operação do Produto (No dia a dia)
* **Correção:** O grau em que o software atende às especificações e objetivos pretendidos pelo cliente.
* **Confiabilidade:** A precisão exigida com que o software executa suas funções, operando livre de falhas.
* **Eficiência:** A quantidade de recursos de computação e código necessários para realizar as funções.
* **Integridade:** O controle de segurança do software contra acessos não autorizados a dados ou funções.
* **Usabilidade:** O esforço e facilidade necessários para aprender, operar e interpretar o sistema.

### Revisão do Produto (Capacidade de Mudança)
* **Facilidade de Manutenção:** O esforço necessário para localizar e corrigir erros no software.
* **Flexibilidade:** O esforço necessário para modificar um software que já está operacional para novas regras.
* **Testabilidade:** O esforço exigido para testar o software e garantir que execute suas funções corretamente.

### Transição do Produto (Adaptabilidade)
* **Portabilidade:** O esforço necessário para transferir o software de um ambiente de hardware ou sistema operacional para outro.
* **Reusabilidade:** A extensão com que partes do software podem ser reaproveitadas em outras aplicações.
* **Interoperabilidade:** O esforço necessário para acoplar ou fazer o software interagir com outros sistemas.
```
