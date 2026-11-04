# Padrões de Software: Padrões de Produto vs. Padrões de Processo

Os **padrões de software** são as regras, guias e critérios estabelecidos para garantir que o desenvolvimento ocorra de forma uniforme, previsível e com alto nível de qualidade. Eles evitam o amadorismo e impedem que cada membro da equipe trabalhe de um jeito totalmente diferente.

Eles se dividem em duas grandes frentes:

```
                      [ PADRÕES DE SOFTWARE ]
                                 |
        +------------------------+------------------------+

        |                                                 |
        v                                                 v
[ PADRÕES DE PRODUTO ]                         [ PADRÕES DE PROCESSO ]
(Foco em "O QUE" é entregue)                   (Foco em "COMO" é feito)
  - Estilo de código (Linters)                   - Ciclo de vida (Ex: Scrum)
  - Arquitetura e Design Patterns                 - Fluxo de Deploy (CI/CD)
  - Documentação Técnica                         - Padrões de Comunicação
  - Métricas de Código                           - Regras de Code Review
```

---

## 1. Padrões de Produto
Os padrões de produto aplicam-se diretamente ao **artefato final entregue**. Eles definem as características, propriedades e restrições que o software (ou seus documentos) deve possuir para ser considerado aceitável.

Os principais exemplos incluem:

* **Padrões de Codificação e Estilo:** Definição de regras de escrita de código (como nomenclatura de variáveis, indentação e tamanho máximo de funções). São comumente validados por ferramentas de análise estática (*Linters* como ESLint, SonarQube).
* **Padrões de Arquitetura e Design:** Uso de estruturas arquiteturais consagradas (ex: Clean Architecture, Microserviços, MVC) e *Design Patterns* (ex: Singleton, Factory, Strategy) para manter o código limpo e extensível.
* **Padrões de Documentação:** Estruturas obrigatórias para arquivos como `README.md`, dicionários de dados, especificações de APIs (ex: OpenAPI/Swagger) e manuais de instalação.
* **Métricas de Qualidade de Código:** Limites técnicos aceitáveis para aceitar um código, tais como:
  * Cobertura de testes automatizados mínima (ex: no mínimo 80% do código testado).
  * Limite máximo de complexidade ciclomática (o nível de ramificações e caminhos lógicos do código).

---

## 2. Padrões de Processo
Os padrões de processo definem **os métodos, as sequências de passos e os comportamentos** que a equipe deve seguir durante o ciclo de desenvolvimento do software. O foco aqui não é o código em si, mas a engrenagem que o produz.

Os principais exemplos incluem:

* **Metodologias de Desenvolvimento:** Definição do modelo de trabalho da equipe (ex: duração das Sprints do Scrum, regras de transição de colunas no Kanban, rituais como reuniões diárias e retrospectivas).
* **Padrões de Versionamento e Ramificação (Branching):** Regras de como os desenvolvedores usam o Git (ex: adoção do *GitFlow* ou *Trunk-Based Development*), definindo como as funcionalidades novas são mescladas no código principal.
* **Fluxo de Integração e Entrega Contínua (CI/CD):** Critérios automatizados para compilar, testar e publicar o software. Por exemplo: "Nenhum código vai para produção sem passar por todos os testes automáticos e receber aprovação de dois desenvolvedores".
* **Práticas de Revisão de Código (Code Review):** Regras sobre o que deve ser avaliado quando um desenvolvedor revisa o trabalho do outro (ex: checar legibilidade, segurança e cobertura de testes antes de aprovar um *Pull Request*).

---

## Tabela Comparativa: Produto vs. Processo

A forma mais simples de diferenciar as duas frentes é compreender o objeto central da avaliação de cada uma:

| Critério | Padrões de Produto | Padrões de Processo |
| :--- | :--- | :--- |
| **Foco Central** | O produto de software em si (o artefato). | O método e fluxo de trabalho (as ações). |
| **Pergunta-Chave** | "O software foi construído corretamente?" | "O software foi construído do jeito certo?" |
| **Exemplo Prático** | O código fonte segue o padrão *Clean Code*. | A equipe faz reuniões diárias de alinhamento. |
| **Ferramentas Comuns** | SonarQube, ESLint, JUnit, Swagger. | Jira, Trello, GitHub Actions, Jenkins. |
| **Benefício Direto** | Facilidade de manutenção e menos bugs no sistema. | Previsibilidade de prazos e fluxo de equipe estável. |
```
