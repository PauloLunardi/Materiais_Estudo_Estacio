# Gerenciamento de Versões na Engenharia de Software

O **Gerenciamento de Versões** é o processo de manter o controle sobre diferentes versões de componentes de software e sistemas completos, garantindo que alterações feitas por diferentes desenvolvedores não interfiram umas nas outras e que qualquer versão anterior possa ser recuperada.

---

## 1. Codelines e Baselines (Segundo Sommerville)

De acordo com **Ian Sommerville**, um sistema de software raramente é um arquivo único. Ele é composto por vários módulos que evoluem em ritmos diferentes, organizados através de três conceitos essenciais:

* **Codeline (Linha de Código):** É uma sequência de versões de código-fonte onde cada nova versão é derivada da anterior. Uma *codeline* geralmente representa a evolução de um componente específico do sistema ao longo do tempo.
* **Baseline (Linha de Base):** É uma definição formal de um sistema completo. Ela especifica exatamente quais versões de quais componentes (*codelines*), bibliotecas e arquivos de configuração foram combinados para gerar aquela versão específica do software. Uma *baseline* permite recriar o sistema exatamente como ele era em um determinado momento.
* **Mainline (Linha Principal):** É a sequência de *baselines* que representa as versões oficiais e principais do sistema que evoluem ao longo do tempo (por exemplo, a versão 1.0, seguida da versão 2.0).

### Representação Estrutural: Codelines, Componentes e Baselines

```
EVOLUÇÃO DOS COMPONENTES (Codelines)

Codeline (A) :  [ A ] ---> [ A1.1 ] ---> [ A1.2 ] ---> [ A1.3 ]

Codeline (B) :  [ B ] ---> [ B1.1 ] ---> [ B1.2 ] ---> [ B1.3 ]

Codeline (C) :  [ C ] ---> [ C1.1 ] ---> [ C1.2 ] ---> [ C1.3 ]

Bibliotecas e Componentes Externos:  [ L1 ]   [ L2 ]   [ Ex1 ]   [ Ex2 ]


DEFINIÇÃO DAS VERSÕES DO SISTEMA (Baselines na Mainline)

[ Baseline - V1 ]
  +-- Componentes internos:  [ A ]   +  [ B1.2 ] +  [ C1.1 ]
  +-- Externos/Bibliotecas:  [ L1 ]  +  [ L2 ]   +  [ Ex1 ]

        |
        | (Evolução na Mainline)
        v

[ Baseline - V2 ]
  +-- Componentes internos:  [ A1.3 ] + [ B1.2 ] +  [ C1.2 ]
  +-- Externos/Bibliotecas:  [ L1 ]   + [ L2 ]   +  [ Ex2 ]
```

---

## 2. Os Dois Tipos de Sistemas de Controle de Versão Modernos

Os sistemas modernos de controle de versão (VCS) dividem-se em duas arquiteturas principais:

1. **Sistemas Centralizados (CVCS - Centralized Version Control Systems):**
   * Existe um único servidor central que armazena todas as versões dos arquivos.
   * Os desenvolvedores conectam-se a esse servidor para baixar os arquivos mais recentes e enviar suas alterações (ex: **Subversion - SVN**, Perforce).
2. **Sistemas Distribuídos (DVCS - Distributed Version Control Systems):**
   * Não dependem exclusivamente de um servidor central para operações diárias.
   * Cada desenvolvedor clona o repositório inteiro localmente, possuindo uma cópia completa de todo o histórico e de todas as versões em sua própria máquina (ex: **Git**, Mercurial).

---

## 3. Funcionalidades Principais dos Sistemas de Controle de Versão

Independentemente da arquitetura, ferramentas modernas de controle de versão oferecem cinco recursos fundamentais:

* **Identificação de Versão e Lançamento:** Atribui identificadores únicos a cada versão de um arquivo ou *baseline* (como números sequenciais, hashes ou tags semânticas ex: `v2.1.0`), facilitando a distinção entre código em desenvolvimento e versões oficiais de lançamento (*releases*).
* **Registro de Histórico de Mudanças:** Mantém um log detalhado de auditoria informando o que foi alterado em cada arquivo, quem realizou a modificação, a data exata e uma mensagem descritiva explicando o motivo da alteração.
* **Desenvolvimento Independente:** Permite que vários desenvolvedores trabalhem simultaneamente nos mesmos arquivos sem sobrescrever o trabalho alheio, utilizando espaços de trabalho isolados e ramificações (*branches*) que depois são mescladas (*merge*).
* **Apoio de Projeto:** Permite agrupar vários arquivos diferentes sob um único projeto ou módulo lógico, facilitando o gerenciamento de sistemas inteiros em vez de tratar apenas arquivos isolados.
* **Gerenciamento de Armazenamento:** Otimiza o espaço em disco ao salvar múltiplas versões. Em vez de guardar cópias completas e repetidas de um arquivo gigante a cada pequena edição, o sistema armazena apenas as **diferenças (deltas)** entre uma versão e outra.

---

## 4. Como Funcionam os Sistemas com Repositório Centralizado (Exemplo: SVN)

Em um sistema centralizado como o **Apache Subversion (SVN)**, toda a verdade do projeto reside em um servidor único, e o fluxo de trabalho ocorre através de requisições em rede:

```
                   [ REPOSITÓRIO CENTRAL (SVN) ]
                   (Armazena todo o histórico e deltas)
                        |                     ^

                        | 1. Check-out        | 3. Commit
                        | (Baixa cópia)       | (Envia alterações)
                        v                     |
             [ ESPAÇO DE TRABALHO LOCAL (Workspace) ]
               +-- 2. Edição de arquivos locais
               +-- 4. Update (Sincroniza mudanças de outros devs)
```

1. **Repositório Central:** Fica hospedado em um servidor da rede ou nuvem. Ele guarda todas as *baselines*, histórico de revisões e arquivos oficiais.
2. **Check-out (Extração):** Para começar a trabalhar, o desenvolvedor faz um *check-out*, baixando uma cópia de trabalho (*working copy*) de uma versão específica do repositório central para o seu computador.
3. **Edição Local:** O desenvolvedor modifica o código no seu computador. Enquanto trabalha localmente, ele não tem acesso ao histórico completo do projeto sem consultar o servidor.
4. **Commit (Submissão):** Quando termina a tarefa, o desenvolvedor envia as modificações de volta para o servidor central através de um *commit*. Nesse momento, o repositório cria uma nova revisão numerada (ex: Revisão 104 -> Revisão 105).
5. **Update e Resolução de Conflitos:** Antes de enviar suas mudanças, o desenvolvedor executa um *update* para baixar alterações que outros colegas possam ter enviado enquanto ele trabalhava. Se duas pessoas editaram a mesma linha do mesmo arquivo, o sistema sinaliza um conflito que precisa ser resolvido manualmente antes de concluir o *commit*.
```
