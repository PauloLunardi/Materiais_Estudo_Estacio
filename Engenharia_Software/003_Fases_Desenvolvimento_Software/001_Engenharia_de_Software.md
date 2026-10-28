# A Engenharia de Software Segundo Pressman (2016) e as Camadas de Tecnologia

Como estabelecido na literatura clássica de **Roger Pressman (2016)**, uma das maiores referências mundiais na área, a Engenharia de Software não deve ser vista como um conjunto de tarefas isoladas de programação. Ela é formalmente definida e estruturada como uma **tecnologia em camadas**.

O princípio fundamental dessa abordagem é que, para criar um produto de software de forma bem-sucedida, previsível e com valor de mercado, a organização de tecnologia precisa se apoiar em uma engenharia estruturada, onde **cada camada serve de sustentação para a camada superior**.

---

## As Camadas da Engenharia de Software e suas Descrições

Abaixo estão detalhadas as quatro camadas que compõem a base tecnológica da disciplina, estruturadas exatamente conforme os conceitos de Pressman:

| Camada | Descrição |
| :--- | :--- |
| **Camada qualidade** | Garante que os requisitos atendam às expectativas dos usuários. |
| **Camada de processo** | Define as etapas de desenvolvimento do software. |
| **Camada de métodos** | Determina as técnicas e os artefatos de software. |
| **Camada ferramentas** | Estimula a utilização de ferramentas CASE. |

---

## Detalhamento Técnico das Camadas

### 1. Camada Qualidade (O Alicerce)
Para Pressman, qualquer abordagem de engenharia deve se apoiar em um compromisso organizacional com a **qualidade**. 
* **Função Prática:** Esta camada funciona como o alicerce de toda a estrutura. Ela estabelece a cultura de melhoria contínua dos processos (*Continuous Improvement*) e define os critérios que garantem que o software final seja robusto, confiável, de fácil manutenção e perfeitamente alinhado às reais necessidades e expectativas do usuário.

### 2. Camada de Processo (O Esqueleto)
A camada de processo é a liga que mantém todas as atividades de desenvolvimento unidas, organizadas e sob controle gerencial.
* **Função Prática:** É aqui que se define o fluxo de trabalho (*workflow*) do projeto. O processo determina quais atividades serão executadas, quem será o responsável por cada tarefa, quando elas acontecerão e quais serão os marcos de controle (*milestones*) que permitirão aos gerentes monitorar prazos, custos e escopo.

### 3. Camada de Métodos (O "Como Fazer")
Enquanto a camada de processo dita *o que* deve ser feito e *quando*, a camada de métodos fornece todo o conhecimento técnico e operacional sobre **como** realizar cada tarefa de engenharia.
* **Função Prática:** Abrange o conjunto de práticas e convenções que os engenheiros utilizam no dia a dia. Isso inclui técnicas de elicitação de requisitos, padrões de arquitetura e design (*Design Patterns*), paradigmas de programação (como a Orientação a Objetos) e estratégias rigorosas de testes de software. É nesta camada que os **artefatos de software** (como diagramas UML, especificações e planos de testes) são formalmente produzidos.

### 4. Camada Ferramentas (O Suporte Automatizado)
No topo da pirâmide tecnológica estão as ferramentas, responsáveis por fornecer suporte automatizado ou semiautomatizado para que os processos e métodos funcionem com máxima eficiência.
* **Função Prática:** Esta camada estimula intensamente o uso de **ferramentas CASE** (*Computer-Aided Software Engineering*). Quando essas ferramentas são integradas de forma inteligente (como repositórios Git vinculados a esteiras de CI/CD e gerenciadores de tarefas como Jira), o resultado gerado por uma etapa alimenta automaticamente a próxima. Isso reduz drasticamente os erros manuais, elimina a burocracia e acelera a produtividade da equipe.
