# Conceito de Gerenciamento de Configuração de Software (GCS)

O **Gerenciamento de Configuração de Software (GCS)** — ou *Software Configuration Management (SCM)* — é uma atividade de guarda-chuva aplicada ao longo de todo o ciclo de vida do desenvolvimento. Seu objetivo principal é **identificar, organizar e controlar sistematicamente as modificações feitas no software** (código-fonte, documentos, dados e modelos), mantendo a integridade e a rastreabilidade do produto desde a concepção até a desativação.

```
[ ARTEFATOS DE SOFTWARE ] ---> [ CONTROLE DE MUDANÇAS (GCS) ] ---> [ INTEGRIDADE E RASTREABILIDADE ]
 (Código, Docs, Dados)          (Versionamento, Auditoria)           (Sem conflitos ou perda)
```

---

## 1. Os 2 Cenários Possíveis (Com GCS vs. Sem GCS)

Na engenharia de software, a ausência de controle sobre as alterações gera o caos operacional. Podemos contrastar claramente os dois cenários possíveis em um projeto:

### Cenário 1: Sem Gerenciamento de Configuração (O Caos)
Ocorre quando múltiplos desenvolvedores alteram o mesmo sistema sem regras ou rastreamento centralizado.
* **Sobrescrita de Código:** O desenvolvedor A sobe uma correção, e minutos depois o desenvolvedor B sobe uma nova funcionalidade que apaga acidentalmente o trabalho de A.
* **Perda de Histórico:** Ninguém sabe quem alterou um arquivo crítico, quando foi alterado ou o motivo técnico da mudança.
* **Impossibilidade de Reversão:** Se uma nova versão quebrar o ambiente de produção, a equipe não consegue voltar rapidamente para a versão anterior estável.
* **Desalinhamento Documental:** O código-fonte evolui, mas os manuais e diagramas continuam refletindo uma versão antiga e obsoleta.

### Cenário 2: Com Gerenciamento de Configuração (O Controle)
Ocorre quando a equipe aplica ferramentas e processos estruturados de GCS (como Git aliado a fluxos de aprovação e esteiras de build).
* **Trabalho Paralelo Seguro:** Vários programadores atuam simultaneamente em ramificações (*branches*) isoladas sem interferir no código principal estável (*baseline*).
* **Rastreabilidade Total:** Cada linha de código alterada está vinculada a um autor, uma data e uma solicitação de mudança aprovada.
* **Construção Reprodutível:** É possível recriar exatamente qualquer versão (*release*) entregue ao cliente no passado para investigar bugs específicos.

---

## 2. Os 4 Elementos de um Sistema de GCS (Pressman)

De acordo com a literatura clássica de Engenharia de Software (Pressman), um sistema eficaz de Gerenciamento de Configuração é sustentado pela integração de quatro elementos fundamentais:

```
               [ SISTEMA DE GERENCIAMENTO DE CONFIGURAÇÃO ]
                                    |
     +------------------------------+------------------------------+

     |                      |                      |               |
     v                      v                      v               v
[ COMPONENTE ]         [ PROCESSO ]          [ CONSTRUÇÃO ]    [ HUMANOS ]
Armazenamento e        Ações e tarefas       Automação de      Equipe e papéis
acesso aos itens       de gestão             build e entrega   de aprovação
```

### Elementos de Componente
* **Definição:** Conjunto de ferramentas acopladas a um sistema de gerenciamento de arquivos (repositório ou banco de dados de configuração).
* **Função:** Possibilita o armazenamento seguro, o rastreamento e o controle de acesso a cada **Item de Configuração de Software (ICS)** — que inclui arquivos de código-fonte, especificações de requisitos, casos de teste e modelos de dados.
* **Exemplos Práticos:** Repositórios Git (GitHub, GitLab, Bitbucket) e gerenciadores de artefatos (Nexus, JFrog Artifactory).

### Elementos de Processo
* **Definição:** Coleção de ações, procedimentos e tarefas formais que definem uma abordagem eficaz para a gestão de alterações.
* **Função:** Estabelece as regras do jogo para todas as partes envolvidas, determinando como uma mudança é solicitada, avaliada quanto ao impacto técnico, aprovada e auditada.
* **Exemplos Práticos:** Fluxos de trabalho como *GitFlow*, políticas obrigatórias de *Pull Request* e *Code Review*, e reuniões do Comitê de Controle de Mudanças (CCB).

### Elementos de Construção
* **Definição:** Conjunto de ferramentas e scripts que automatizam a compilação e a montagem do software.
* **Função:** Assegura que o conjunto apropriado de versões de cada componente validado seja reunido, compilado, testado e empacotado corretamente para gerar um executável ou versão de entrega (*release*) sem erros humanos.
* **Exemplos Práticos:** Ferramentas de automação de build e integração contínua (CI/CD) como Maven, Gradle, Docker, Jenkins e GitHub Actions.

### Elementos Humanos
* **Definição:** A equipe de engenharia de software e os gestores que utilizam o sistema de GCS e aplicam suas regras no dia a dia.
* **Função:** Garantir que as ferramentas e processos sejam seguidos com disciplina. Envolve a definição clara de papéis e responsabilidades (quem pode propor alterações, quem tem permissão para aprovar o *merge* na linha de base e quem audita as entregas).
* **Exemplos Práticos:** Desenvolvedores, Engenheiros de Release/DevOps, Analistas de QA e membros do Comitê de Controle de Mudanças.
