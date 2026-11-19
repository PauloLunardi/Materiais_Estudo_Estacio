# Planejamento de Gerenciamento de Configuração de Software (GCS)

O **Planejamento de Gerenciamento de Configuração (GCS)** é a etapa inicial que estrutura formalmente como as mudanças e versões de um projeto de software serão organizadas, controladas e auditadas. 

O resultado dessa atividade é o **Plano de GCS**, um documento que estabelece as regras do jogo antes que o código comece a ser modificado em larga escala, garantindo que toda a equipe siga padrões unificados.

```
[ 1. IDENTIFICAÇÃO ] --> [ 2. RESPONSABILIDADES ] --> [ 3. POLÍTICAS ] --> [ 4. FERRAMENTAS ] --> [ 5. BANCO DE DADOS ]
   (O que controlar)       (Quem responde)            (Regras de uso)      (Onde executar)        (Onde registrar)
```

---

## As 5 Etapas do Planejamento de GCS (Detalhamento da Imagem)

De acordo com o fluxo apresentado na imagem, o planejamento da configuração é estruturado em cinco pilares sequenciais:

### 1. Definição e Identificação dos Itens de Configuração (ICS)
* **O que diz a etapa:** Definição dos itens de configuração de software (ICS) que serão gerenciados e o esquema que se deve usar para identificar essas entidades.
* **Na prática:** Nem todo arquivo temporário precisa de controle rigoroso. Aqui a equipe decide exatamente quais artefatos entram sob controle formal (ex: código-fonte, scripts de banco de dados, documentos de requisitos, casos de teste) e cria uma **nomenclatura padrão** única para cada arquivo e versão (ex: `API_Pagamentos_v1.2.0`).

### 2. Estabelecimento de Responsabilidades e Papéis
* **O que diz a etapa:** Estabelecimento do responsável pelos procedimentos de gerenciamento de configuração e pela submissão de itens controlados para a equipe de gerenciamento de configurações.
* **Na prática:** Define claramente **quem faz o quê**. Estabelece quem atua como Gerente de Configuração, quem tem permissão apenas para propor alterações em ramificações locais e quem possui autoridade para aprovar e submeter os itens validados para o repositório oficial da equipe.

### 3. Definição das Políticas de Controle e Versionamento
* **O que diz a etapa:** Definição das políticas de gerenciamento de configurações que todos os membros da equipe devem adotar para o controle de mudanças e gerenciamento de versões.
* **Na prática:** Cria o regimento interno de manipulação de código e documentos. Define como funciona o fluxo de aprovação de mudanças (ex: obrigatoriedade de *Code Review* antes do *merge*), regras de versionamento semântico (`MAJOR.MINOR.PATCH`) e critérios para criação de linhas de base (*baselines*).

### 4. Especificação de Ferramentas e Processos de Uso
* **O que diz a etapa:** Especificação das ferramentas aplicadas no gerenciamento de configurações e os processos para uso dessas ferramentas.
* **Na prática:** Escolhe a pilha tecnológica que sustentará o GCS e documenta o passo a passo de operação. Por exemplo: adotar o **Git/GitHub** para controle de versão, **Jira** para rastreamento de solicitações de mudança e **Jenkins/GitHub Actions** para compilação automática, acompanhados de um guia prático de uso (como o *GitFlow*).

### 5. Estruturação do Banco de Dados de Configuração
* **O que diz a etapa:** Descrição da estrutura do banco de dados de configuração usada para registrar as informações de configuração e as informações que devem ser mantidas neste banco de dados, ou seja, os registros de configurações.
* **Na prática:** Define onde e como todo o histórico do projeto será armazenado e consultado. Esse repositório central guarda os metadados essenciais para auditoria: qual versão está em produção, quem aprovou cada alteração, quais bugs foram corrigidos em cada entrega e qual documento de requisito deu origem a cada modificação no código.
```
