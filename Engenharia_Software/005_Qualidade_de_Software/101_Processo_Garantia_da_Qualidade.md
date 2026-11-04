# O Processo de Garantia da Qualidade de Software (SQA)

O processo de **Garantia da Qualidade de Software (SQA - Software Quality Assurance)** não se resume a testar o código no final do projeto. Ele engloba um conjunto de atividades planejadas e sistemáticas, executadas ao longo de todo o ciclo de desenvolvimento, para garantir que o produto final atenda aos critérios de excelência exigidos.

```
            [ PROCESSO DE GARANTIA DA QUALIDADE (SQA) ]
                                 |
     +---------------------------+---------------------------+

     |                           |                           |
[PREPARAÇÃO E PADRÕES]     [AVALIAÇÃO E CONTROLE]      [SEGURANÇA E MITIGAÇÃO]
  - Padrões                  - Revisões e Auditorias     - Admin. da Segurança
  - Educação                 - Testes                    - Proteção
  - Gerência Fornecedores    - Coleta/Análise de Erros   - Admin. de Riscos
                             - Gerenciamento Mudanças
```

---

## 1. Padrões
Os padrões funcionam como a lei do projeto. Eles definem as diretrizes técnicas e os critérios que a equipe deve seguir obrigatoriamente.
* **Padrões de Processo:** Determinam como o trabalho deve ser conduzido (ex: guias do Scrum, metodologias ágeis ou regras de entrega/deploy).
* **Padrões de Produto:** Determinam os critérios do código e da arquitetura (ex: guias de estilo de código/linters, padrões de design e limites aceitáveis de complexidade ciclomática).

---

## 2. Revisões e Auditorias
Mecanismos de verificação e controle para avaliar a conformidade do projeto ao longo do tempo.
* **Revisões Técnicas:** Avaliações do código, arquitetura ou engenharia de requisitos feitas pelos próprios pares (*Code Review* e *Peer Review*) para encontrar defeitos logo no início.
* **Auditorias:** Verificações formais, muitas vezes conduzidas por equipes externas ou profissionais de QA, para atestar se o projeto está seguindo os processos e regulamentações obrigatórias da empresa ou da indústria.

---

## 3. Testes
A execução prática e controlada do sistema com o objetivo de encontrar falhas antes que o cliente as encontre. O SQA planeja a estratégia que divide os testes em diferentes níveis:
* **Testes Unitários:** Validam a menor unidade de código isolada (uma função ou classe).
* **Testes de Integração:** Verificam se diferentes módulos do sistema trabalham bem juntos.
* **Testes de Sistema / E2E:** Testam o fluxo do software de ponta a ponta na perspectiva do usuário final.

---

## 4. Coleta e Análise de Erros/Defeitos
Para melhorar um processo, é preciso medi-lo. Esta atividade consiste em registrar meticulosamente cada bug encontrado, identificando:
* **Onde e Quando:** Em qual fase do ciclo o erro foi introduzido e onde foi detectado.
* **Causa Raiz:** O motivo real da falha (falha de comunicação, erro de lógica, falta de cobertura de teste).
* **Métricas:** Uso de dados históricos para descobrir quais partes do sistema são mais instáveis, direcionando melhor os esforços de melhoria.

---

## 5. Gerenciamento de Mudanças
O software é um elemento vivo que sofre alterações constantes. Sem controle, modificações desordenadas destroem a qualidade do produto.
* Envolve ferramentas de **Gerenciamento de Configuração (como Git)** e processos de aprovação.
* Garante que toda alteração seja solicitada, avaliada quanto ao impacto, testada e homologada antes de entrar em produção.

---

## 6. Educação
A qualidade do software depende diretamente da capacidade técnica e da maturidade das pessoas que o constroem.
* Consiste em programas de treinamento contínuo para desenvolvedores, testadores e gestores.
* Foca na disseminação de novas ferramentas, metodologias de teste, práticas de código limpo (*Clean Code*) e atualizações de segurança.

---

## 7. Gerência dos Fornecedores
Sistemas modernos raramente são construídos do zero; eles utilizam bibliotecas de terceiros, APIs parceiras ou módulos terceirizados.
* Esta atividade estabelece os requisitos mínimos de qualidade que os softwares e componentes de fornecedores externos devem atingir.
* Avalia e homologa se o código integrado de fora não vai comprometer o desempenho ou a estabilidade da aplicação principal.

---

## 8. Administração da Segurança
Garante que o software seja robusto contra ataques maliciosos e vulnerabilidades de dados.
* Envolve a criação de políticas de controle de acesso rigorosas (quem pode acessar o quê).
* Aplica testes de intrusão (*PenTests*) e análises de código estáticas (SAST) e dinâmicas (DAST) para blindar o sistema contra invasões e vazamentos.

---

## 9. Proteção (Safety)
Enquanto a *Segurança (Security)* foca em defender o sistema contra ataques humanos externos, a *Proteção (Safety)* lida com o impacto das falhas do software no mundo real.
* É crucial em softwares de missão crítica (médicos, automotivos, de aviação ou financeiros).
* Avalia as consequências de um travamento do sistema, desenhando mecanismos de contingência para que, caso o software falhe, ele entre em um estado seguro, protegendo a vida de pessoas e ativos financeiros.

---

## 10. Administração de Riscos
Atividade proativa que tenta prever os problemas antes que eles aconteçam, traçando planos para contorná-los.
* **Identificação:** Mapear o que pode dar errado (ex: atraso na entrega de uma API, perda de um desenvolvedor chave, estouro do uso de memória do servidor).
* **Mitigação:** Criar estratégias preventivas para diminuir a chance do risco acontecer e planos de ação para remediar o problema imediatamente se ele se concretizar.
```

