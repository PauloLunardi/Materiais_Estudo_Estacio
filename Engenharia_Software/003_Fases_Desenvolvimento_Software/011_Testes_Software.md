# Testes de Software: Estratégias e Níveis de Validação

Os **Testes de Software** representam uma atividade umbral crucial no ciclo de vida do desenvolvimento. O objetivo principal dos testes não é apenas provar que o sistema funciona, mas atuar de forma destrutiva para **encontrar defeitos (*bugs*)** antes que o produto chegue ao usuário final, garantindo o cumprimento dos atributos de qualidade da norma ISO 9126.

---

## Níveis e Tipos de Teste de Software

A Engenharia de Software organiza os testes em uma sequência lógica e progressiva, partindo da menor unidade de código até a validação do sistema completo frente ao negócio do cliente.

* **Teste de Unidade (ou Unitário)**
  * **Foco:** Valida o menor componente testável do software de forma isolada (geralmente uma única função, método ou classe).
  * **Abordagem:** Executado predominantemente pelos próprios desenvolvedores durante a etapa de implementação. Utiliza técnicas de *Caixa Branca* (onde o testador conhece a estrutura interna do código).
  * **Objetivo:** Garantir que os algoritmos, cálculos internos e lógicas condicionais de um método específico funcionem exatamente como planejado.

* **Teste de Integração**
  * **Foco:** Valida a comunicação, a troca de mensagens e a transferência de dados entre diferentes módulos ou classes que já foram testados individualmente.
  * **Abordagem:** Pode seguir estratégias como *Top-down* (da camada mais alta para a mais baixa), *Bottom-up* (das sub-rotinas de infraestrutura para cima) ou integração contínua automática.
  * **Objetivo:** Descobrir falhas em interfaces de comunicação, problemas de acoplamento arquitetural e inconsistências em contratos de APIs ou persistência de dados.

* **Teste de Validação**
  * **Foco:** Avalia se o software como um todo atende a todos os requisitos funcionais, não funcionais e de negócio estipulados no Documento de Especificação (SRS).
  * **Abordagem:** Utiliza técnicas de *Caixa Preta* (onde o testador avalia apenas as entradas e saídas do sistema, sem olhar o código).
  * **Objetivo:** Confirmar se o software entrega o valor real pretendido e se comporta de forma estável no cenário de simulação de uso do cliente.

---

## Os Testes de Aceite (Homologação)

Após passar pelos testes de validação da equipe de controle de qualidade (QA), o software entra na fase de **Aceite**. Esta etapa transfere o foco para o cliente ou usuário final, determinando se o sistema está comercial e operacionalmente pronto para o deploy definitivo.

Divide-se em três etapas fundamentais:

* **1. Teste Alpha (Alfa)**
  * **Ambiente:** Ocorre em um ambiente controlado de desenvolvimento, mas é **executado por usuários finais reais** (ou por uma equipe interna que simula o perfil do usuário).
  * **Dinâmica:** Os desenvolvedores costumam acompanhar os testes de perto ("olhando por cima do ombro") para registrar erros de usabilidade, comportamentos inesperados e bugs instantaneamente em uma atmosfera de laboratório.

* **2. Teste Beta (Beta)**
  * **Ambiente:** Ocorre em um ambiente real de produção controlado, **fora da empresa desenvolvedora**.
  * **Dinâmica:** O software é disponibilizado para um grupo selecionado e limitado de usuários reais externos (público beta). Esses usuários utilizam o sistema no seu cotidiano de trabalho e reportam de forma assíncrona as falhas e dificuldades encontradas. Os desenvolvedores não estão presentes para intervir.

* **3. Aceite Formal**
  * **Ambiente:** Fase burocrática e contratual de fechamento do projeto ou da iteração.
  * **Dinâmica:** O cliente corporativo ou o comitê de governança do projeto avalia todos os relatórios de testes (Alpha, Beta e de Validação). Caso o software cumpra os critérios de sucesso e os níveis de serviço acordados, o cliente assina formalmente o **Termo de Aceite**, autorizando o pagamento e a virada oficial do sistema para o uso em larga escala.

## A Espiral de Testes de Software (Mapeamento com a Engenharia)

Como ilustrado na imagem clássica da literatura de engenharia de software (proposta originalmente por **Roger Pressman**), o processo de testes não ocorre de forma aleatória. Existe uma **relação de espiral** direta entre as fases em que o sistema foi projetado e as fases em que ele é testado. 

A espiral funciona em duas direções de leitura complementares:

### 1. O Fluxo de Dentro para Fora (A Execução dos Testes)
Durante a fase prática de testes, a equipe começa no centro da espiral e caminha para as bordas externas:
* **Código ➔ Teste de Unidade:** O ponto de partida é o código-fonte bruto recém-escrito. O foco é testar as menores frações de lógica de forma isolada.
* **Projeto ➔ Teste de Integração:** À medida que a espiral se expande, os componentes do design de arquitetura e projeto de classes começam a ser montados e testados em conjunto.
* **Requisitos ➔ Teste de Validação:** Expandindo um pouco mais, o foco passa a ser validar se o produto final atende diretamente aos requisitos lógicos levantados com o cliente.
* **Engenharia de Sistemas ➔ Teste de Sistema:** Na borda mais externa, o software deixa de ser avaliado isoladamente e passa a ser testado de forma integrada a todo o ecossistema (hardware, banco de dados, redes e outros sistemas da organização).

### 2. O Fluxo de Correspondência (O Alinhamento Teórico)
A grande sacada desse organograma em espiral é que **cada nível de teste usa como base de comparação os artefatos gerados na sua fase correspondente de engenharia**:

* O **Teste de Unidade** toma como base a implementação do **Código**.
* O **Teste de Integração** toma como base o desenho do **Projeto/Design** arquitetural.
* O **Teste de Validação** toma como base os critérios mapeados na fase de **Requisitos**.
* O **Teste de Sistema** toma como base o escopo macro desenhado na **Engenharia de Sistemas**.

Em termos simples: você não consegue validar se um requisito foi cumprido na fase de teste unitário, assim como não olha o código-fonte de um método durante o teste de sistema. Cada nível tem seu papel e sua documentação de apoio correspondente.

