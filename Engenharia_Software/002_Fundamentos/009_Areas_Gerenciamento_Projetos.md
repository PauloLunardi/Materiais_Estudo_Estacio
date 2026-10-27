# Áreas de Conhecimento em Gerenciamento de Projetos Aplicadas ao Software

As **Áreas de Conhecimento** organizam os conceitos, práticas e processos de gestão que um gerente de projetos deve dominar. No desenvolvimento de software, essas áreas ganham contornos específicos devido à natureza intangível, volátil e complexa dos produtos digitais. 

Abaixo estão detalhadas as 10 áreas de conhecimento consolidadas pelo PMI, adaptadas à realidade da Engenharia de Software.

---

## 1. Gerenciamento da Integração do Projeto
É a cola que une todas as partes do projeto. Garante que os prazos, custos, qualidade e equipe técnica caminhem em sintonia.
* **No Software:** Consiste em balancear a arquitetura técnica com os prazos de entrega, além de gerenciar o *Controle Integrado de Mudanças* para avaliar o impacto de novos requisitos no sistema sem desestruturar o código existente.

## 2. Gerenciamento do Escopo do Projeto
Define exatamente o que será e o que não será construído no sistema, mapeando todas as funcionalidades e entregas técnicas.
* **No Software:** Evita o *Scope Creep* (crescimento descontrolado do escopo). Sua principal ferramenta de controle técnico é a **Estrutura Analítica do Projeto (EAP)** ou **Work Breakdown Structure (WBS)**.

### Estrutura Analítica do Projeto (EAP)
A EAP é uma decomposição hierárquica orientada às entregas do projeto. Ela quebra o software complexo em partes menores e gerenciáveis (pacotes de trabalho):

* **1. Sistema de Gestão Escolar (Produto Completo)**
  * **1.1. Módulo de Autenticação**
    * 1.1.1. Tela de Login e Cadastro de Usuários
    * 1.1.2. Integração com Recuperação de Senha por E-mail
  * **1.2. Módulo Acadêmico**
    * 1.2.1. Lançamento de Notas e Frequência
    * 1.2.2. Geração de Boletim Escolar (PDF)
  * **1.3. Banco de Dados e Infraestrutura**
    * 1.3.1. Modelagem do Esquema de Dados (SGBD)
    * 1.3.2. Configuração do Pipeline de CI/CD em Nuvem

---

## 3. Gerenciamento do Cronograma do Projeto
Estabelece os prazos, sequenciamento de atividades e marcos temporais para a entrega das fatias de código ou módulos.

```text
Atividade             | Sem 1 | Sem 2 | Sem 3 | Sem 4 | Sem 5 | Sem 6 |
-----------------------------------------------------------------------
A. Elicitação/Requisitos [======]
B. Modelagem BD e API            [======]
C. Desenvolvimento UI                    [==========]
D. Testes Integrados                                 [======]
E. Implantação/Deploy                                        [==] (Marco)
```

* **Exemplo de Dependência Lógica:** A atividade **C (Desenvolvimento UI)** depende diretamente da conclusão da atividade **A (Elicitação/Requisitos)** para que as telas façam sentido técnico para o usuário.

---

## 4. Gerenciamento dos Custos do Projeto
Envolve o planejamento, estimativa, orçamento e controle dos custos para que o projeto termine dentro do orçamento aprovado.
* **No Software:** O custo principal costuma ser a **hora/homem** da equipe de desenvolvimento (desenvolvedores, arquitetos, designers, QAs), além de despesas com licenças de softwares, ferramentas CASE, APIs pagas e infraestrutura de servidores em nuvem (AWS, Azure, Google Cloud).

## 5. Gerenciamento da Qualidade do Projeto
Garante que o software atenda aos requisitos solicitados e opere sem falhas críticas, cobrindo o planejamento, a garantia e o controle de qualidade.
* **No Software:** Traduz-se na definição de padrões de codificação, revisões de código (*Code Reviews*), automação de testes (unitários, integração e e2e) e auditorias de processos antes do release em produção.

## 6. Gerenciamento dos Recursos do Projeto
Identifica, adquire e gerencia as pessoas (recursos humanos) e os materiais/infraestrutura necessários para a execução do trabalho técnico.
* **No Software:** Foca na alocação correta de papéis técnicos (ex: separar tarefas de back-end e front-end) e em garantir que a equipe possua as máquinas, IDEs e ambientes de testes necessários para trabalhar sem impedimentos.

## 7. Gerenciamento das Comunicações do Projeto
Garante que as informações do projeto sejam coletadas, distribuídas, armazenadas e gerenciadas no tempo certo e para as pessoas certas.
* **No Software:** Crucial para alinhar as expectativas da equipe técnica com o cliente de negócios. Utiliza ferramentas como Jira, Slack, relatórios de status de sprints e documentações técnicas claras para evitar retrabalho.

## 8. Gerenciamento dos Riscos do Projeto
Identifica, analisa e responde a eventos incertos que podem impactar positiva ou negativamente o projeto.
* **No Software:** Mapeia riscos tecnológicos clássicos, como: "A API do cliente atrasar a homologação", "A equipe não dominar o novo framework escolhido" ou "Perda de um desenvolvedor sênior no meio do projeto". Requer a criação de planos de contingência.

## 9. Gerenciamento das Aquisições do Projeto
Processos necessários para comprar ou adquirir produtos, serviços ou resultados externos à equipe do projeto.
* **No Software:** Envolve a contratação de consultorias especializadas (ex: para testes de invasão e segurança), compra de bibliotecas proprietárias, contratação de servidores terceirizados ou terceirização da criação de layouts específicos de UX/UI.

## 10. Gerenciamento das Partes Interessadas (Stakeholders)
Identifica todas as pessoas ou organizações impactadas pelo projeto e desenvolve estratégias para engajá-las efetivamente nas decisões e execução.
* **No Software:** Gerencia o envolvimento de usuários finais, diretores, investidores e a própria equipe de tecnologia, garantindo que o produto final resolva as dores reais do cliente e seja aceito pelo mercado.


## 11. Matriz de Relacionamento: Áreas de Conhecimento vs. Grupos de Processos

Para compreender como as áreas de conhecimento interagem com a governança do projeto, a tabela abaixo mapeia os principais processos de gerenciamento distribuídos ao longo das fases de ciclo de vida (baseado no mapeamento do Guia PMBOK):

| Áreas de Conhecimento | Iniciação | Planejamento | Execução | Monitoramento e Controle | Encerramento |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Integração** | 1. Desenvolver o termo de abertura do projeto | 2. Desenvolver o plano de gerenciamento do projeto | 3. Orientar e gerenciar a execução do projeto | 4. Monitorar e controlar o trabalho do projeto <br> 5. Realizar o controle integrado de mudanças | 6. Encerrar o projeto ou fase |
| **Escopo** | | 1. Coletar os requisitos <br> 2. Definir o escopo <br> 3. Criar a EAP | | 4. Verificar o escopo <br> 5. Controlar o escopo | |
| **Tempo** | | 1. Definir as atividades <br> 2. Sequenciar as atividades <br> 3. Estimar os recursos das atividades <br> 4. Estimar as durações das atividades <br> 5. Desenvolver o cronograma | | 6. Controlar o cronograma | |
| **Custos** | | 1. Estimar os custos <br> 2. Determinar o orçamento | | 3. Controlar os custos | |
| **Qualidade** | | 1. Planejar a qualidade | 2. Realizar a garantia de qualidade | 3. Realizar o controle da qualidade | |
| **Recursos Humanos** | | 1. Desenvolver o plano de recursos humanos | 2. Mobilizar a equipe do projeto <br> 3. Desenvolver a equipe do projeto <br> 4. Gerenciar a equipe do projeto | | |
| **Comunicação** | 1. Identificar as partes interessadas | 2. Planejar as comunicações | 3. Distribuir as informações <br> 4. Gerenciar as expectativas das partes interessadas | 5. Reportar o desempenho | |
| **Riscos** | | 1. Planejar o gerenciamento dos riscos <br> 2. Identificar os riscos <br> 3. Realizar a análise qualitativa dos riscos <br> 4. Realizar a análise quantitativa dos riscos <br> 5. Planejar as respostas aos riscos | | 6. Monitorar e controlar os riscos | |
| **Aquisição** | | 1. Planejar as aquisições | 2. Conduzir as aquisições | 3. Administrar as aquisições | 4. Encerrar as aquisições |

