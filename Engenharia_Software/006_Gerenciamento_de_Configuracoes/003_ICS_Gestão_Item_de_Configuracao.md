# Gestão de Item de Configuração de Software (ICS)

Um **Item de Configuração de Software (ICS)** é qualquer informação ou artefato gerado como parte do processo de engenharia de software que precisa ser controlado formalmente. Isso inclui desde documentos de requisitos e modelos de projeto até o código-fonte, casos de teste e scripts de banco de dados.

A **Gestão de ICS** garante que cada artefato seja identificado de forma única (conforme previsto no Plano de GCS) e que suas alterações passem por um ciclo rigoroso de revisão antes de se tornarem oficiais.

```
[ TAREFAS DE ENGENHARIA ] ---> [ REVISÕES TÉCNICAS ] ---> [ BANCO DE DADOS DO PROJETO ]
  (Criação / Modificação)       (Validação e Aprovação)    (Armazenado como Referência)
```

---

## 1. Identificação e Casos de Teste como ICS

Para que o gerenciamento funcione, cada artefato precisa de uma etiqueta única no repositório.

* **Previsão no Plano de GCS:** O plano define o esquema de nomenclatura e hierarquia dos itens. Por exemplo: `PROJETO_MODULO_TIPO_VERSAO` (ex: `SISTEMA_LOGIN_CASOTESTE_v1.0`). Isso permite rastrear exatamente qual versão de um documento pertence a qual versão do código.
* **Caso de Teste como ICS:** Um caso de teste não é apenas um rascunho; ele é um **ICS fundamental**. Quando uma regra de negócio muda no código-fonte, o caso de teste correspondente também precisa ser versionado, revisado e aprovado. Manter casos de teste sob controle de configuração garante que os testes executados correspondam exatamente à versão do software que está sendo validada.

---

## 2. O Ciclo de Vida do ICS e as Referências (Detalhamento da Imagem)

A relação entre o trabalho diário da equipe, os itens de configuração e o **Banco de Dados do Projeto** (o repositório controlado). O fluxo opera em dois sentidos:

### Fluxo de Entrada (Criação e Modificação)
1. **Tarefas de Engenharia de Software:** Os desenvolvedores, arquitetos e testadores criam novos artefatos ou modificam itens existentes (`ICSs Modificados`).
2. **Revisões Técnicas:** Antes de qualquer alteração ser aceita oficialmente, os artefatos passam por inspeções e revisões formais (*Code Review*, revisão de documentos).
3. **Aprovação e Armazenamento:** Somente após serem validados, os itens tornam-se **ICSs Aprovados** e são gravados no **Banco de Dados do Projeto** (`Armazenado`). A partir desse momento, tornam-se uma **Referência (Baseline)** oficial.

### Fluxo de Saída (Extração para Novas Mudanças)
1. **Controles de ICS:** Uma vez que um item virou uma referência no banco de dados, ninguém pode alterá-lo livremente.
2. **Extração Controlada:** Para realizar uma nova manutenção ou evolução, o profissional solicita a extração do item (`ICSs Extraídos` / *check-out*).
3. **Novo Ciclo:** O item extraído volta para as tarefas de engenharia, reiniciando o ciclo de modificação, revisão técnica e nova aprovação.

---

## 3. Os Referenciais Mais Comuns (Baselines)

Quando um conjunto de ICSs é revisado, corrigido e aprovado, ele se torna uma **Referência (Baseline)** — um marco estável que serve de base para os próximos passos do projeto. Conforme destacado na imagem, os principais artefatos que formam essas referências são:

* **Especificações de Sistema:** Documentos de alto nível que definem o escopo global e o ambiente do sistema.
* **Requisitos de Software:** Detalhamento das funcionalidades e regras de negócio que o software deve atender.
* **Especificação de Projeto (Design):** Modelos arquiteturais, diagramas de classes, fluxos de dados e estrutura de interfaces.
* **Código-Fonte:** Todos os arquivos de programação escritos pela equipe para construir o sistema.
* **Planos de Teste, Procedimentos e Dados:** Roteiros de validação, casos de teste automatizados/manuais e massas de dados de teste.
* **Sistema Operacional e Ambiente:** Configurações de infraestrutura, bibliotecas de terceiros e ferramentas de compilação necessárias para rodar o software.
```
