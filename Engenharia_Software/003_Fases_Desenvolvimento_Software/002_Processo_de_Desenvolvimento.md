# Processo de Desenvolvimento de Software

Um **Processo de Desenvolvimento de Software** (também conhecido como ciclo de vida ou SDLC — *Software Development Life Cycle*) é um conjunto estruturado de atividades, ações e tarefas necessárias para construir, implantar e manter um sistema de software de alta qualidade. 

Como estabelecido na ementa da nossa disciplina, qualquer processo de engenharia maduro — seja ele baseado em metodologias tradicionais ou ágeis — precisa incorporar um núcleo de etapas essenciais para garantir o controle, a previsibilidade e a qualidade do produto final.

---

## As Atividades Comuns e Essenciais do Processo

Independentemente da abordagem metodológica adotada pela organização, as seguintes etapas devem fazer parte do fluxo de trabalho técnico:

### 1. Levantamento e Engenharia de Requisitos
Esta fase inicial foca em descobrir e documentar o que o sistema deve fazer, alinhando as expectativas dos clientes e usuários com o time de engenharia. Os requisitos levantados dividem-se em três pilares fundamentais:
* **Requisitos Funcionais:** Descrevem diretamente o comportamento, as funções e os recursos que o software deve fornecer (ex: o sistema deve emitir um relatório de faturamento; o usuário deve conseguir redefinir sua senha).
* **Requisitos Não Funcionais:** Definem os critérios de qualidade, restrições e propriedades emergentes do sistema (ex: a página deve carregar em menos de 2 segundos; os dados devem ser criptografados usando AES-256).
* **Requisitos de Domínio:** São restrições que derivam diretamente do setor de aplicação do software e não do desejo imediato do usuário, refletindo leis, regulamentos ou regras de negócio obrigatórias (ex: o cálculo do imposto deve seguir as diretrizes vigentes da Receita Federal).

### 2. Etapa de Análise
A análise foca na compreensão profunda e lógica do problema antes da codificação técnica. Ela se divide em três atividades centrais:
* **Procedimento:** Mapeamento minucioso do fluxo de trabalho e das regras de negócio do cliente para entender como os processos operam na realidade atual.
* **Problemas:** Identificação de gargalos, falhas de comunicação, redundâncias e ineficiências operacionais que o novo software terá a missão de eliminar ou mitigar.
* **Modelos:** Criação de representações abstratas e conceituais do sistema (como diagramas de casos de uso e modelos de fluxo de dados) que servem como ponte de validação entre os stakeholders e os desenvolvedores.

### 3. Etapa de Projeto (Design Architecture)
Se a análise foca em entender *o que* o sistema deve fazer, a etapa de projeto foca em planejar **como** ele será construído fisicamente. Durante essa atividade, a equipe define a arquitetura do software (camadas, microsserviços), a modelagem lógica e física do banco de dados (SGBD), o design de interface de usuário (UI/UX) e a pilha de tecnologias (linguagens, frameworks e servidores).

### 4. Etapa de Implementação (Codificação)
É a fase de construção propriamente dita. Os modelos conceituais e os projetos arquiteturais são traduzidos pelos desenvolvedores em linhas de código-fonte limpas, executáveis e sustentáveis. Inclui também as revisões de código (*Code Reviews*) e a escrita de testes unitários iniciais pelo próprio time de programação.

### 5. Etapa de Testes (Garantia de Qualidade)
Após a codificação, o sistema passa por rigorosas baterias de validação técnica para identificar discrepâncias entre o comportamento do software e os requisitos originais. Essa fase visa descobrir e corrigir falhas (*bugs*) por meio de testes de integração, testes de sistema de ponta a ponta e testes de aceitação do usuário (UAT).

### 6. Etapa de Implantação (Deployment)
Com o software testado, validado e homologado, ele entra na fase de entrega. O objetivo é disponibilizar o produto para uso em ambiente de produção real, envolvendo a publicação em servidores ou lojas de aplicativos, migração segura de dados antigos e treinamento de usuários.

---

## A Organização do Fluxo de Processo

A dinâmica de execução dessas etapas varia conforme a estrutura do fluxo de processo escolhido para o projeto. As principais abordagens de mercado incluem:

* **Fluxo Linear (Cascata):** Executa as etapas em uma sequência rígida de linha de montagem, onde uma fase só inicia quando a anterior estiver 100% concluída.
* **Fluxo Iterativo:** Executa as atividades de forma cíclica, permitindo que a equipe revisite fases anteriores para refinar e polir os artefatos com base no aprendizado contínuo.
* **Fluxo Evolucionário (Espiral):** O software desenvolve-se em um padrão circular que cresce em escopo a cada ciclo completo, gerando protótipos funcionais intermediários e focando intensamente na mitigação de riscos.
* **Fluxo Paralelo:** Permite que diferentes atividades ocorram de forma simultânea para componentes modulares e independentes do sistema, acelerando o cronograma de entrega.

### O Modelo Iterativo e Incremental
Consolida-se como a base das metodologias modernas de engenharia de software (como o Scrum, XP e o Processo Unificado). Ele combina o conceito de refinamento contínuo (**Iteração**) com a entrega do produto quebrado em partes menores e utilizáveis (**Incrementos**). Em vez de esperar meses pelo software completo, o cliente recebe fatias funcionais de valor a cada ciclo curto de desenvolvimento, otimizando recursos e reduzindo drasticamente os riscos do projeto.
