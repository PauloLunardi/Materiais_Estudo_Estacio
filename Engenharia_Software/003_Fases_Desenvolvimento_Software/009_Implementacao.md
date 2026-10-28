# A Etapa de Implementação na Engenharia de Software

A **Implementação** (ou codificação) é a fase do ciclo de vida do software onde os modelos lógicos, diagramas estruturais, especificações de requisitos e decisões arquiteturais são formalmente traduzidos em **código-fonte executável e testável**. 

Embora muitas pessoas leigas associem a Engenharia de Software apenas a este momento, a literatura clássica deixa claro que a implementação é um processo técnico que depende diretamente do sucesso de todas as etapas anteriores.

---

## Referências Teóricas e Visão dos Autores

Para entender a importância da implementação sem mitos, recorremos aos grandes nomes da engenharia de software:

* **Roger Pressman (2016):** Defende que a codificação é uma consequência natural do design. Se a equipe investiu tempo refinando os aspectos estáticos, dinâmicos e arquiteturais, a implementação torna-se um processo fluido, focado em traduzir algoritmos para a sintaxe da linguagem escolhida de forma limpa e padronizada.
* **Ian Sommerville (2007):** Destaca que a implementação e o design estão intimamente ligados. Ele ressalta que o código moderno não deve apenas compilar e funcionar, mas também ser escrito pensando na **manutenibilidade futura**, visto que a maior parte do custo de um software ocorre após a sua entrega, na fase de evolução e correção.
* **Robert C. Martin (Uncle Bob - 2009 / Código Limpo):** Traz uma visão prática e moderna sobre a implementação, afirmando que o código deve ser escrito para que seres humanos o leiam, e não apenas para que máquinas o executem. A implementação exige o cumprimento de padrões estritos de legibilidade, funções pequenas e responsabilidades únicas.

---

## Atividades e Princípios Fundamentais da Implementação

Durante a execução da etapa de implementação, a equipe de desenvolvimento deve guiar-se por práticas que garantam a saúde técnica do ecossistema:

* **Escolha e Aplicação de Paradigmas:** Definição prática de como a linguagem será utilizada (ex: Programação Orientada a Objetos, Funcional ou Imperativa). No contexto de **Bezerra (2014)**, a codificação deve espelhar fielmente o modelo de classes do domínio.
* **Padrões de Codificação (*Style Guides*):** Adoção de regras comuns de nomenclatura de variáveis, indentação e organização de pastas (como CamelCase ou PascalCase). Isso garante que o código pareça ter sido escrito por uma única pessoa, facilitando o trabalho em equipe.
* **Refatoração Contínua (*Refactoring*):** O ato de reestruturar o código interno para torná-lo mais limpo, rápido ou legível, sem alterar em nada o seu comportamento externo.
* **Reuso de Código:** Utilização de bibliotecas consolidadas, frameworks e padrões de projeto (*Design Patterns*) para evitar "reinventar a roda", acelerando a entrega e reduzindo o índice de bugs.

---

## Práticas Técnicas Integradas à Implementação

A engenharia moderna dita que a implementação não ocorre de forma isolada em uma máquina local. Ela precisa estar conectada a práticas automatizadas de apoio técnico:

* **Testes Unitários Intercalados:** O desenvolvedor escreve o código e, imediatamente, cria testes para validar as menores unidades daquele código (funções/métodos). Se adotada a prática do **TDD (Test-Driven Development)**, os testes são escritos inclusive *antes* do código funcional.
* **Controle de Versão Constante:** O código gerado é submetido a ramificações (*branches*) em repositórios Git, passando por processos de **Code Review** (onde outros engenheiros revisam a implementação em busca de falhas lógicas) antes de ser integrado ao tronco principal do projeto.
