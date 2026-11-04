# Planejamento da Qualidade: 

## SEI, Equipe de SQA, Organograma e Estrutura IEEE

O planejamento estratégico da qualidade define a estrutura organizacional, as responsabilidades e os planos de ação que guiarão a engenharia de software. 
Nesta seção, abordamos as diretrizes das maiores autoridades globais em processos de software: o **SEI (Software Engineering Institute)** e o **IEEE (Institute of Electrical and Electronics Engineers)**.

```
       [ DIRETRIZES TÉCNICAS E NORMATIVAS DE SQA ]
                           |
     +---------------------+---------------------+

     |                                           |
     v                                           v
 [ SEI (CMMI) ]                           [ IEEE 730 ]
Foco na maturidade dos processos          Estrutura formal do plano
e prevenção de defeitos.                  de garantia de qualidade.
```

---

## 1. O que o SEI Recomenda?
O **SEI (Software Engineering Institute)**, criador do modelo CMMI (Capability Maturity Model Integration), prega que a qualidade do software é uma consequência direta da maturidade dos processos da organização. As principais recomendações do SEI para o planejamento da qualidade incluem:

* **Foco na Prevenção:** Em vez de focar apenas em caçar defeitos na fase de testes, o planejamento deve focar em processos preventivos (revisões de requisitos, arquitetura e treinamento).
* **Gerenciamento Quantitativo:** Estabelecer metas numéricas de qualidade baseadas nas necessidades do negócio (ex: densidade máxima de 0.5 defeitos por KLOC - mil linhas de código).
* **Melhoria Contínua dos Processos:** Analisar continuamente as causas raiz dos problemas encontrados em produção para modificar e blindar o processo institucional de desenvolvimento.
* **Institucionalização:** Garantir que as práticas de SQA não dependam de heróis individuais, mas sim de rotinas padronizadas e documentadas que toda a empresa segue.

---

## 2. A Equipe de SQA (Software Quality Assurance)
A equipe de SQA desempenha o papel de guardiã dos processos de qualidade dentro da organização. Suas principais atribuições são:

* **Orientação e Consultoria:** Apoiar os times de desenvolvimento na escolha e adoção de padrões, ferramentas e métodos corretos.
* **Auditoria e Monitoramento:** Verificar se as equipes estão de fato seguindo as políticas organizacionais, os planos de teste e os padrões de codificação definidos.
* **Relatórios à Gerência:** Fornecer visibilidade objetiva para a alta liderança sobre o nível de aderência dos projetos aos requisitos de qualidade.

---

## 3. Modelo de Organograma da Qualidade
Para assegurar a eficácia e evitar conflitos de interesse, o SEI e as boas práticas de governança exigem que **a equipe de SQA possua independência gerencial**. O time de qualidade não deve responder diretamente ao gerente do projeto (focado em prazos), mas sim a uma diretoria ou gerência de qualidade isolada.

```
                  [ DIRETORIA EXECUTIVA / CEO ]
                                |
       +------------------------+------------------------+

       |                                                 |
       v                                                 v
[ GERÊNCIA DE DESENVOLVIMENTO ]                 [ GERÊNCIA DE QUALIDADE / SQA ]

       |                                                 |
       +--> Gerente de Projeto A                         +--> Analistas de Processos

       |       |                                         |
       |       +--> Desenvolvedores                      +--> Auditores internos

       |                                                 |
       +--> Gerente de Projeto B                         +--> Engenheiros de QA / Testes
```

---

## 4. Estrutura IEEE 730 e o que ela Recomenda
A **IEEE 730** é a norma internacional dedicada especificamente ao **Plano de Garantia da Qualidade de Software (SQAP)**. Ela recomenda uma estrutura documental padronizada para que nenhum aspecto crítico de qualidade seja esquecido no início de um projeto.

A estrutura formal recomendada para o sumário de um plano IEEE 730 segue as seções obrigatórias descritas abaixo:

```
ESTRUTURA DO PLANO DE QUALIDADE (IEEE 730)
  |
  +--> 1. Finalidade (Escopo, objetivos do software e aplicabilidade)
  |
  +--> 2. Documentos de Referência (Leis, normas, ISOs e políticas internas)
  |
  +--> 3. Gerenciamento (Organograma, papéis, responsabilidades e independência do SQA)
  |
  +--> 4. Documentação (Lista de todos os manuais e relatórios técnicos exigidos)
  |
  +--> 5. Padrões, Práticas, Convenções e Métricas (Linters, métricas de código)
  |
  +--> 6. Revisões de Software e Auditorias (Calendário e escopo de avaliações)
  |
  +--> 7. Testes (Tipos, estratégias de automação e critérios de aceitação)
  |
  +--> 8. Resolução de Problemas e Ação Corretiva (Fluxo de tratamento de bugs)
  |
  +--> 9. Ferramentas, Técnicas e Metodologias (Softwares de CI/CD, IDEs, SonarQube)
  |
  +--> 10. Controle de Mídia (Segurança de armazenamento, backup do código-fonte)
  |
  +--> 11. Controle de Código (Regras de versionamento do repositório Git)
  |
  +--> 12. Controle de Fornecedores (Como softwares externos integrados serão validados)
  |
  +--> 13. Registros, Coleta e Retenção de Dados (Manutenção do histórico de métricas)
  |
  +--> 14. Treinamento (Capacitações técnicas previstas para o time)
  |
  +--> 15. Gerenciamento de Riscos (Estratégias de mitigação técnica)
```
