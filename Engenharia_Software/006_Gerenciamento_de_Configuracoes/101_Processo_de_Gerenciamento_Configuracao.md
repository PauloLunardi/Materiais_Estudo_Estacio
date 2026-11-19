# Processo de Gerenciamento de Configuração de Software (GCS)

O **Processo de Gerenciamento de Configuração de Software (GCS)** estabelece o conjunto de atividades sistemáticas que garantem o controle sobre a evolução do sistema. Conforme ilustrado na imagem, o processo atua em camadas concêntricas ao redor dos **Itens de Configuração de Software (ICSs)** para assegurar a integridade técnica do projeto.

```
( Camada Externa )  RELATOS
( Camada 4 )        AUDITORIA DE CONFIGURAÇÃO
( Camada 3 )        CONTROLE DE VERSÃO
( Camada 2 )        CONTROLE DE ALTERAÇÕES
( Camada 1 )        IDENTIFICAÇÃO
( Núcleo )          [ ICSs ] (Itens de Configuração de Software)
```

---

## 1. Os 4 Objetivos Fundamentais do Processo (Topo da Imagem)

Antes de executar as tarefas técnicas, o processo de GCS busca cumprir quatro metas essenciais no ciclo de vida do desenvolvimento:

* **Identificar todos os itens:** Mapear e catalogar todos os artefatos (código, documentos, dados, testes) que coletivamente definem a configuração completa do software.
* **Gerenciar alterações:** Controlar de forma disciplinada qualquer modificação solicitada em um ou mais desses itens, evitando mudanças desordenadas.
* **Facilitar a construção de versões:** Permitir que a equipe compile e gere diferentes versões ou variantes de uma mesma aplicação (ex: versão Web, Mobile, ou edições para clientes específicos) sem conflitos.
* **Assegurar a qualidade contínua:** Garantir que a estabilidade e a qualidade do software sejam preservadas à medida que a configuração evolui e cresce ao longo do tempo.

---

## 2. As 5 Tarefas do Processo de GCS (Camadas da Figura 3)

Partindo do núcleo (**ICSs**) em direção às camadas mais externas de governança e visibilidade, o processo define cinco tarefas interdependentes:

### 1. Identificação
É a camada mais próxima aos artefatos. Consiste em catalogar e nomear de forma única cada Item de Configuração de Software (ICS) dentro do banco de dados do projeto.
* **Como funciona:** Atribui etiquetas exclusivas a cada arquivo, documento ou modelo, além de mapear os relacionamentos entre eles (ex: saber exatamente qual arquivo de código implementa qual documento de requisito).

### 2. Controle de Alterações (Mudanças)
Envolve a combinação de procedimentos humanos e ferramentas automatizadas para governar as modificações nos ICSs após eles se tornarem uma linha de base (*baseline*).
* **Como funciona:** Nenhuma alteração ocorre por impulso. Toda mudança exige uma **Solicitação de Mudança**, passa por uma avaliação de impacto técnico/financeiro e precisa ser aprovada por uma autoridade (como o **CCB - Comitê de Controle de Mudanças**) antes de ser aplicada.

### 3. Controle de Versão
Combina procedimentos e ferramentas para gerenciar as diferentes versões dos objetos de configuração criados ao longo do processo de engenharia de software.
* **Como funciona:** Permite que a equipe acompanhe a evolução histórica de cada arquivo (quem alterou, o que mudou e quando), possibilita o trabalho paralelo em ramificações (*branches* no Git) e garante que versões anteriores possam ser recuperadas a qualquer momento.

### 4. Auditoria de Configuração
Garante que a alteração aprovada foi realmente implementada da maneira correta e que a integridade do sistema não foi comprometida.
* **Como funciona:** Consiste em revisões técnicas formais (*FTR*) e auditorias realizadas pela equipe de SQA para responder a perguntas críticas: *"A mudança especificada foi feita corretamente?"*, *"Foram introduzidos efeitos colaterais indesejados?"* e *"Os padrões de documentação e codificação foram respeitados?"*.

### 5. Relatos (Relatórios de Status de Configuração - CSA)
É a camada mais externa, responsável por dar visibilidade e transparência de todo o processo para a equipe técnica, gerentes e clientes.
* **Como funciona:** Responde continuamente às perguntas: **"O que aconteceu?"**, **"Quem fez?"**, **"Quando aconteceu?"** e **"O que mais será afetado?"**. Sempre que um ICS recebe uma nova identificação, passa por uma alteração aprovada ou sofre uma auditoria, um registro é atualizado e distribuído para manter todos alinhados sobre o estado real do software.
```
