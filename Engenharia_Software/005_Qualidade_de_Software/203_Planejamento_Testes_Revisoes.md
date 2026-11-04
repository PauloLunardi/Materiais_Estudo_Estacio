# Planejamento de Testes e Revisões: Verificação, Validação e Ciclo de Aceite

O planejamento de testes e revisões estabelece a estratégia para garantir que o software seja construído corretamente (atendendo às especificações técnicas) e que o produto certo seja entregue (resolvendo o problema real do cliente).

```
         [ ENGENHARIA DE TESTES E REVISÕES ]
                         |
       +-----------------+-----------------+

       |                                   |
       v                                   v
 [ VERIFICAÇÃO ]                     [ VALIDAÇÃO ]
"O software está sendo             "O software atende às
construído corretamente?"           expectativas do usuário?"
  - Revisões e Auditorias             - Integração Alterada
  - Documentação Técnica              - Validação de Sistema
  - Atividades de Inspeção            - Testes Alpha / Beta
                                      - Aceite Formal
```

---

## 1. Testes de Verificação vs. Testes de Validação

A engenharia de software separa rigidamente as ações de checagem técnica das ações de homologação prática do negócio:

* **Testes de Verificação:** Avaliam se os artefatos de software cumprem rigorosamente as especificações estipuladas na fase anterior. Focam na parte técnica (arquitetura, lógica, conformidade do código).
* **Testes de Validação:** Avaliam se o software atende ao propósito de negócio projetado e às expectativas reais do usuário final quando opera em ambiente real.

---

## 2. O Universo da Verificação: Revisões, Auditorias e Atividades

A verificação baseia-se fortemente em técnicas estáticas e de conformidade que não exigem necessariamente a execução do código:

* **Revisões e Auditorias:**
  * **Revisões Técnicas (*Code/Peer Review*):** Análises detalhadas do código ou de diagramas feitas por outros desenvolvedores da equipe para identificar falhas lógicas, falhas de segurança e problemas de legibilidade antes do merge.
  * **Auditorias:** Inspeções formais lideradas pela equipe de SQA para garantir que o projeto está seguindo os processos definidos (ex: se todos os artefatos obrigatórios foram preenchidos e as diretrizes da ISO 9001 foram respeitadas).
* **Documentação:** Manutenção e revisão de artefatos essenciais de verificação, incluindo a especificação de requisitos, dicionário de dados, planos de arquitetura, guias de estilo e especificações de endpoints (Swagger/OpenAPI).
* **Atividades:** Processos contínuos de verificação como execução de ferramentas de análise estática de código (*Linters*), checagens automáticas de vulnerabilidade em dependências (SAST) e testes unitários.

---

## 3. Integração Especificada ou Alterada

Mapeia o momento em que diferentes módulos ou submódulos do sistema são conectados e precisam ser reavaliados.

* Quando um novo código é adicionado ou um módulo existente é **alterado**, executa-se o fluxo de **Testes de Integração** e **Testes de Regressão**.
* O objetivo é certificar que a comunicação e a troca de dados entre os componentes (ex: o aplicativo enviando dados para o banco através de uma API) ocorra sem perdas e que a alteração de um pedaço não destrua funcionalidades que já estavam funcionando perfeitamente.

---

## 4. Sistema Especificado ou Alterado (Validação do Sistema, Solução ou Aceite)

Esta etapa marca a transição da perspectiva técnica para a perspectiva do usuário final. O sistema completo e integrado passa pelos checkpoints finais de validação:

* **Validação do Sistema:** Testes de caixa-preta aplicados ao software completo para checar o comportamento de ponta a ponta dos fluxos operacionais contra os cenários de uso acordados.
* **Validação da Solução:** Avaliação de métricas não funcionais (como testes de carga, stress e alta disponibilidade) para assegurar que a solução tecnológica suporta o ecossistema e as demandas volumétricas do negócio.
* **Validação de Aceite:** O processo pelo qual o cliente final ou o Dono do Produto (*Product Owner*) avalia o incremento do software para atestar se a dor do negócio foi de fato sanada.

---

## 5. Testes Alpha, Beta e Aceite Formal

As etapas que determinam a homologação final do software e autorizam seu lançamento oficial para o mercado seguem uma progressão controlada:

```
[ AMBIENTE INTERNO ]         [ AMBIENTE REAL CONTROLADO ]         [ HOMOLOGAÇÃO ]
   Teste Alpha       ------>          Teste Beta          ------>  Aceite Formal
```

* **Teste Alpha:** É realizado em ambiente interno de desenvolvimento (laboratório), simulando o uso real do sistema de ponta a ponta. É executado tipicamente por membros da própria empresa (equipe de QA, desenvolvedores e gerentes de produto), buscando capturar bugs crassos, travamentos estruturais ou inconsistências visuais óbvias antes de expor o software ao público externo.
* **Teste Beta:** O software é disponibilizado para um grupo selecionado de usuários reais externos em um ambiente de produção controlado (ambiente de *Staging* ou lançamento restrito). O objetivo é coletar feedback sobre usabilidade, identificar bugs raros causados por hardwares variados e analisar a performance do software sob interações humanas autênticas e imprevisíveis.
* **Aceite Formal:** A assinatura e chancela contratual definitiva do cliente ou da governança corporativa da empresa atestando que o software cumpre com todos os critérios de aceitação estabelecidos. O aceite formal é o gatilho burocrático e operacional que encerra o ciclo de desenvolvimento e autoriza o deploy definitivo da aplicação para toda a base de clientes do ambiente produtivo.
```
