# Gerenciamento de Mudanças: Fluxo em 5 Processos, Governança e Ferramentas

O **Gerenciamento de Mudanças** controla o ciclo de vida das alterações solicitadas em um software após a definição de sua linha de base (*baseline*). Ele garante que evoluções, correções de defeitos e adaptações ocorram de forma organizada, avaliando os impactos técnicos e financeiros antes que qualquer linha de código seja alterada.

```
[ 1. SOLICITAÇÃO ] --> [ 2. TRIAGEM ] --> [ 3. ANÁLISE TÉCNICA ] --> [ 4. DECISÃO (CCM) ] --> [ 5. EXECUÇÃO/TESTE ]
  (Cliente abre)        (Suporte valida)   (Custo e Impacto)        (Aprova ou Rejeita)     (Modifica e Homologa)
```

```
[ CLIENTE ]
  |
  +--> Apresenta solicitação de mudança
         |
         v
[ REPOSITÓRIO CENTRAL: SOLICITAÇÕES DE MUDANÇAS ]
  |
  +---> [ SUPORTE AO CLIENTE ]

  |       |
  |       +--> Verificar solicitação de mudança

  |              |
  |              +--> (Inválida) --> Fechar solicitação de mudança

  |              |
  |              +--> (Válida)   --> Registrar solicitação de mudança
  |
  +---> [ DESENVOLVIMENTO (Análise) ]

  |       |
  |       +--> Análise de implementação

  |       |
  |       +--> Análise de custo/impacto
  |
  +---> [ DESENVOLVIMENTO PRODUTO (CCM) ]

  |       |
  |       +--> Avaliar solicitações de mudança

  |       |
  |       +--> Selecionar solicitações de mudança

  |              |
  |              +--> (Rejeitada) --> Fechar solicitação de mudança

  |              |
  |              +--> (Aprovada)  --> Segue para execução abaixo
  |
  +---> [ DESENVOLVIMENTO (Execução e Teste) ]
          |
          +--> Modificar software <---+

          |       |                   | (Reprovado)
          |       v                   |
          +--> Testar software -------+
                  |
                  +--> (Aprovado) --> Fechar solicitação de mudança
```
---

## 1. Os 5 Processos do Fluxo de Mudanças (Detalhamento da fluxograma)

Analisando o fluxograma apresentado, o ciclo completo de uma mudança divide-se em **cinco processos operacionais** interligados ao repositório central de **Solicitações de Mudanças**:

### Processo 1: Origem e Abertura (Cliente)
* **Ação na Imagem:** *Apresenta solicitação de mudança*.
* **Como funciona:** O processo inicia quando o cliente, usuário final ou área de negócio identifica a necessidade de uma nova funcionalidade, melhoria ou correção de erro e submete formalmente um pedido ao repositório central de solicitações.

### Processo 2: Triagem e Registro (Suporte ao Cliente)
* **Ações na Imagem:** *Verificar solicitação de mudança* -> Decisão (*Inválida* -> *Fechar solicitação* / *Válida* -> *Registrar solicitação*).
* **Como funciona:** A equipe de suporte faz o primeiro filtro. Verifica se o pedido faz sentido, se não é um erro de operação do próprio usuário ou uma solicitação duplicada. Se for inválido, o chamado é encerrado; se for válido, é registrado oficialmente na fila de análise.

### Processo 3: Análise Técnica e de Impacto (Desenvolvimento - Parte 1)
* **Ações na Imagem:** *Análise de implementação* -> *Análise de custo/impacto*.
* **Como funciona:** Antes de aprovar a mudança, os engenheiros de software avaliam a viabilidade técnica. Eles mapeiam quais módulos do sistema serão afetados, calculam o esforço em horas, estimam os custos financeiros e identificam os riscos envolvidos na alteração.

### Processo 4: Avaliação e Decisão (Desenvolvimento Produto / CCM)
* **Ações na Imagem:** *Avaliar solicitações de mudança* -> *Selecionar solicitações de mudança* -> Decisão (Rejeitada -> *Fechar solicitação* / Aprovada -> Segue para implementação).
* **Como funciona:** O **CCM (Comitê de Controle de Mudanças)** analisa os relatórios de custo e impacto gerados no processo anterior. Com base nas prioridades do negócio e no orçamento, o comitê decide quais mudanças serão rejeitadas (fechadas) e quais são prioritárias e aprovadas para entrar na fila de construção.

### Processo 5: Implementação, Teste e Encerramento (Desenvolvimento - Parte 2)
* **Ações na Imagem:** *Modificar software* -> *Testar software* -> Decisão (*Reprovado* -> Retorna para modificar / *Aprovado* -> *Fechar solicitação de mudança*).
* **Como funciona:** Os desenvolvedores alteram o código-fonte conforme especificado. Em seguida, o sistema passa pelos testes de qualidade e regressão. Se os testes reprovarem a alteração, o item volta para correção; se for aprovado, a entrega é validada e a solicitação de mudança é finalmente encerrada.

---

## 2. Governança Multi-equipes e Construções Sistemáticas

Em sistemas corporativos de grande porte, o gerenciamento de mudanças exige práticas estruturadas de coordenação:

* **Avaliação e Priorização entre Times:** Quando múltiplos times de desenvolvimento produzem módulos diferentes de um mesmo sistema, uma mudança em um módulo central pode quebrar integrações de outras equipes. O processo de gerenciamento avalia essas dependências cruzadas e prioriza as entregas para evitar conflitos de código e gargalos de integração.
* **Construções Sistemáticas (Builds):** Consiste no processo automatizado e repetível de compilar, vincular e empacotar as versões corretas de cada módulo produzido pelos diferentes times. Garante que o executável final do sistema seja montado sempre a partir de itens validados e compatíveis entre si.

---

## 3. Conceitos e Ferramentas Relacionadas

Para suportar o rastreamento rigoroso de mudanças e versões, a engenharia de software apoia-se em modelos e ferramentas especializadas:

* **CAD (Controle de Acesso e Distribuição / Controle de Alterações e Defeitos):** Mecanismos e políticas que governam quem tem permissão para extrair (*check-out*) e submeter (*check-in*) itens de configuração, garantindo o rastreamento formal tanto de solicitações de evolução quanto de correções de defeitos.
* **FSM (Finite State Machine / Máquina de Estados Finitos):** Modelo lógico utilizado dentro das ferramentas de gerenciamento de mudanças para controlar o ciclo de vida de um chamado ou requisito. Uma solicitação transita por estados rígidos e predefinidos (ex: *Aberta* -> *Em Triagem* -> *Em Análise* -> *Aprovada* -> *Em Teste* -> *Fechada*), impedindo que um desenvolvedor altere o código sem passar pela aprovação prévia do comitê.
* **IBM Rational ClearCase:** Uma das ferramentas clássicas e mais robustas de Gerenciamento de Configuração de Software (GCS) do mercado corporativo. O ClearCase oferece controle de versão avançado, gerenciamento de espaços de trabalho isolados (*views*), rastreamento paralelo de alterações multi-equipes e automação de construções sistemáticas (*builds*), integrando-se nativamente com ferramentas de controle de fluxo de mudanças (como o *ClearQuest*).
```
