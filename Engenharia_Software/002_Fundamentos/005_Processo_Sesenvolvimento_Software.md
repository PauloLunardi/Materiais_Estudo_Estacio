# Atividades Comuns nos Processos de Desenvolvimento de Software

Independentemente do tamanho do projeto, da área de atuação ou da metodologia escolhida (seja ela tradicional ou ágil), existem etapas técnicas essenciais que todo processo de desenvolvimento de software deve possuir. O objetivo desta seção é detalhar essas atividades fundamentais que transformam uma necessidade de negócio em um produto de software funcional.

---

## 1. Etapa de Engenharia e Levantamento de Requisitos

Esta é a fase em que se descobre o que deve ser construído. Envolve uma colaboração estreita com os clientes e usuários para extrair as necessidades reais do sistema. Os requisitos mapeados nesta atividade dividem-se em três categorias principais:

* **Requisitos Funcionais:** Descrevem o comportamento do sistema, isto é, as funções, facilidades, entradas e saídas que o software deve fornecer (ex: "O sistema deve emitir um relatório de vendas mensal", "O usuário deve conseguir redefinir sua senha por e-mail").
* **Requisitos Não Funcionais:** Definem restrições sobre os serviços ou funções oferecidos pelo sistema. Estão ligados a características de qualidade e propriedades emergentes (ex: "A página deve carregar em menos de 2 segundos", "O banco de dados deve criptografar os dados dos cartões de crédito utilizando AES-256").
* **Requisitos de Domínio:** São restrições que derivam diretamente do domínio de aplicação do sistema, e não das necessidades específicas do usuário. Eles refletem as características, regras e regulamentos do setor (ex: "O cálculo do imposto deve seguir a tabela de alíquotas vigente da Receita Federal", "O sistema de controle de voo deve respeitar os limites de aproximação estabelecidos pelas regras de aviação civil").

---

## 2. Etapa de Análise

A etapa de análise foca em *compreender o problema* profundamente e estruturar as necessidades levantadas de forma lógica e conceitual, garantindo que o escopo esteja correto antes de pensar em infraestrutura técnica ou linhas de código. Ela se divide em:

* **Análise de Procedimento:** Mapeamento do fluxo de trabalho atual e das regras de negócio do cliente. Entende-se como os processos operam hoje (mesmo que manualmente) para desenhar como operarão com o novo software.
* **Análise de Problemas:** Identificação de gargalos, falhas de comunicação, redundâncias de dados e ineficiências no cenário atual que o novo sistema precisará mitigar ou eliminar.
* **Modelos de Análise:** Criação de representações conceituais do sistema (como diagramas de casos de uso, diagramas de classes conceituais ou diagramas de fluxo de dados) que servem de ponte de comunicação entre a equipe de desenvolvimento e as partes interessadas.

---

## 3. Etapa de Projeto (Design)

Se a análise foca em entender *o que* o sistema deve fazer, o projeto foca em planejar *como* ele será construído internamente. É a transição do mundo lógico para o mundo físico e tecnológico. Durante esta atividade, a equipe define:

* **Arquitetura do Software:** Estrutura do sistema (ex: arquitetura em camadas, microsserviços, *clean architecture*).
* **Design de Interface (UI/UX):** Layout das telas, usabilidade e navegação para o usuário final.
* **Projeto de Banco de Dados:** Modelagem física e lógica das tabelas, chaves e relacionamentos de dados.
* **Definição de Tecnologias:** Escolha de linguagens de programação, frameworks, bibliotecas e infraestrutura de servidores ou nuvem.

---

## 4. Etapa de Implementação (Codificação)

Esta é a fase de construção propriamente dita, onde os modelos, arquiteturas e designs criados nas etapas anteriores são traduzidos em linhas de código executáveis.

* **Escrita do Código:** Desenvolvimento do back-end, front-end e integrações de APIs seguindo os padrões de codificação da equipe.
* **Refatoração:** Melhoria contínua da estrutura interna do código sem alterar seu comportamento externo, garantindo um sistema limpo e de fácil manutenção.
* **Testes Unitários Iniciais:** Testes realizados pelos próprios desenvolvedores para garantir que as menores unidades de código (funções ou métodos) funcionem isoladamente de maneira correta.

---

## 5. Etapa de Testes (Garantia de Qualidade)

Após a codificação, o sistema passa por rigorosas validações para identificar discrepâncias entre o que foi desenvolvido e os requisitos que foram solicitados. Esta etapa visa descobrir e corrigir falhas (*bugs*) antes do lançamento. Inclui:

* **Testes de Integração:** Verificação de que as diferentes partes do software funcionam bem quando combinadas.
* **Testes de Sistema:** Validação do software como um todo em um ambiente que simula o uso real.
* **Testes de Aceitação (UAT):** Testes realizados ou validados pelo cliente final para confirmar se o produto atende às expectativas e regras de negócio estipuladas.

---

## 6. Etapa de Implantação (Deployment)

Com o software testado e homologado, ele entra na fase de entrega. O objetivo desta etapa é disponibilizar o produto para uso real.

* **Publicação em Produção:** Instalação e configuração do software nos servidores ou lojas de aplicativos onde os usuários finais terão acesso.
* **Migração de Dados:** Transferência segura de informações de sistemas antigos para a nova base de dados, caso necessário.
* **Treinamento e Suporte:** Capacitação dos usuários para utilizarem a nova ferramenta de maneira eficiente e estruturação dos canais de suporte para a resolução de incidentes.
