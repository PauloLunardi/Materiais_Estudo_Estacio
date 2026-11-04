# As Normas ISO 9000 / ISO 9001 na Engenharia de Software

A família **ISO 9000** descreve os fundamentos de um Sistema de Gestão da Qualidade (SGQ) e define a terminologia para organizações de todos os setores. A **ISO 9001** estabelece os requisitos e critérios específicos que a empresa deve cumprir para obter a certificação formal de qualidade. 

No contexto do desenvolvimento de software, a ISO 9001 garante que a organização possui processos estruturados, monitorados e focados na melhoria contínua para entregar produtos de valor previsível aos clientes.

```
       [ FAMÍLIA ISO 9000 ] --(Fornece)--> Fundamentos e Vocabulário
               |
               v
       [ NORMA ISO 9001 ]   --(Exige)---> Requisitos para Certificação (SGQ)
               |
               +---> Aplicada ao ciclo de vida do software
```

---

## 1. As Necessidades Delineadas pela ISO 9001

A estrutura essencial da ISO 9001 mapeia o ciclo de vida do desenvolvimento de software através de requisitos organizacionais e de engenharia fundamentais:

* **Responsabilidade administrativa:** A liderança e a alta gerência da empresa de tecnologia devem demonstrar compromisso claro com a qualidade. Isso significa definir a política de qualidade da organização, alocar recursos financeiros e de pessoal para equipes de QA, e revisar periodicamente o desempenho do SGQ.
* **Um sistema de qualidade:** A organização precisa ter um ecossistema documentado que unifique os processos, papéis, responsabilidades e fluxos de trabalho que assegurem a qualidade dos softwares produzidos.
* **Revisão contratada:** Antes de assinar o contrato de desenvolvimento ou de iniciar um projeto para um cliente, a empresa precisa revisar os requisitos contratuais e comerciais. O objetivo é garantir que as necessidades do cliente estão claras e que a equipe técnica realmente possui a capacidade interna para cumpri-las.
* **Controle de projeto:** Consiste em gerenciar cada fase do ciclo de desenvolvimento do software. Envolve o planejamento do projeto, a definição de entregáveis intermediários, a validação de arquitetura e a verificação técnica para que o código reflita fielmente o escopo inicial.
* **Controle de dados e documentos:** Todo documento crítico (especificações de requisitos, diagramas arquiteturais, manuais e decisões de design) deve ser controlado. O sistema deve garantir que as versões estejam atualizadas, aprovadas pelas pessoas certas e acessíveis para quem precisa.
* **Identificação e rastreabilidade de produtos:** A capacidade de rastrear a evolução do software. Em sistemas digitais, isso significa associar cada linha de código (ou commit) a um requisito de negócio específico e saber exatamente quais versões do código-fonte compõem um pacote liberado em produção (*build/release*).
* **Controle de processos:** O desenvolvimento deve ocorrer sob condições controladas. Isso inclui o monitoramento dos ambientes de homologação e produção, o uso de ferramentas adequadas (como IDEs padronizadas, servidores de CI/CD) e a execução padronizada das metodologias de desenvolvimento da casa.
* **Inspeções e testes:** Atividades sistemáticas para validar se o software atende aos critérios funcionais e não funcionais. Isso engloba desde a fase de testes unitários pelos desenvolvedores até os testes integrados, testes de fumaça (*smoke tests*) e homologações finais efetuadas pelos analistas de QA.
* **Ações preventivas e corretivas:** Estratégias focadas em eliminar as causas de falhas. Uma **ação corretiva** atua para corrigir um bug encontrado e impedir que ele reincida no código. Uma **ação preventiva** analisa o processo para evitar que um tipo de erro aconteça futuramente (ex: identificar uma falha no fluxo de comunicação e corrigi-la).
* **Registros de controle de qualidade:** Manutenção de históricos claros que atestem as verificações realizadas no produto. Exemplos práticos incluem relatórios de execução de testes automatizados, taxas de bugs abertos/fechados e logs de compilação de sistemas.
* **Auditorias de qualidade internas:** Avaliações periódicas feitas de forma independente pela própria empresa para verificar se os times de engenharia estão realmente seguindo os processos exigidos pela ISO 9001 e identificar gargalos no fluxo de trabalho.
* **Treinamento:** Identificação das lacunas de conhecimento e capacitação formal dos colaboradores. Garante que desenvolvedores conheçam as tecnologias utilizadas, arquitetos compreendam os padrões adotados e o time de qualidade domine as ferramentas de automação de testes.
* **Manutenção:** Atividades executadas após a entrega do produto ao usuário. Envolve suporte a incidentes, correção de vulnerabilidades de segurança e aplicação de patches corretivos em ambientes de produção.
* **Técnicas estatísticas:** O uso de dados reais para entender o comportamento dos processos e do produto. Mede métricas cruciais como densidade de defeitos por blocos de código, tempo médio de resolução de problemas (*MTTR*) e percentual de cobertura de testes.

---

## 2. Modelos de Plano

Para operacionalizar as exigências da ISO 9001 no mundo real da tecnologia, as organizações utilizam planos documentados padrão. Veja as duas principais estruturas aplicadas a projetos de software:

### Modelo de Plano de Garantia da Qualidade de Software (SQAP)
Este documento descreve as práticas, ferramentas e cenários de controle aplicados ao longo de um projeto específico:

```
ESTRUTURA DE UM SQAP (Software Quality Assurance Plan)
  |
  +--> 1. Finalidade e Escopo (Objetivos do projeto e sistema avaliado)
  |
  +--> 2. Gerência e Organização (Papéis, lideranças e responsabilidades)
  |
  +--> 3. Documentação Exigida (Quais artefatos o projeto deve gerar)
  |
  +--> 4. Padrões, Práticas e Métricas (Convenções de código, limites de bugs)
  |
  +--> 5. Revisões e Auditorias (Calendário e regras de Code Reviews)
  |
  +--> 6. Gerenciamento de Configuração (Fluxo de branches no Git e Deploys)
  |
  +--> 7. Ferramentas e Ambientes (Softwares de automação de testes utilizados)
```

### Modelo de Plano de Gerenciamento de Riscos de Software
Este documento mapeia proativamente o que pode dar errado no projeto e define salvaguardas preventivas e de contingência:

```
ESTRUTURA DE UM PLANO DE RISCOS
  |
  +--> 1. Identificação de Riscos (Mapeamento de vulnerabilidades técnicas/operacionais)
  |
  +--> 2. Análise e Matriz de Impacto (Avaliação de Probabilidade x Gravidade)
  |
  +--> 3. Estratégias de Mitigação (Ações preventivas para diminuir chances do risco)
  |
  +--> 4. Planos de Contingência (O que fazer imediatamente se o risco virar um problema)
  |
  +--> 5. Monitoramento Contínuo (Mecanismos de revisão de riscos nas Sprints)
```



