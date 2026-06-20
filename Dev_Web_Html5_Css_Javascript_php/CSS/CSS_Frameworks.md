# CSS Frameworks

## Motivação

À medida que os projetos web se tornam maiores e mais complexos, criar todo o CSS manualmente pode demandar muito tempo.

Para acelerar o desenvolvimento e promover a padronização do código, surgiram os **Frameworks CSS**, conjuntos de componentes, estilos e estruturas reutilizáveis que auxiliam na construção de interfaces modernas e responsivas.

O objetivo principal de um framework é evitar a necessidade de criar elementos comuns do zero, permitindo que o desenvolvedor concentre esforços na lógica e nas necessidades específicas do projeto.

---

## O que é um Framework CSS?

Um Framework CSS é um conjunto de arquivos e recursos prontos que fornecem:

* Sistema de grid
* Componentes visuais
* Classes utilitárias
* Layout responsivo
* Padronização visual
* Compatibilidade entre navegadores

Em vez de desenvolver cada elemento manualmente, o desenvolvedor utiliza classes e componentes previamente implementados pelo framework.

---

## Principais Características

### Reutilização de Código

Os componentes podem ser utilizados em diferentes páginas e projetos.

### Responsividade

A maioria dos frameworks modernos segue a abordagem:

```text
Mobile First
```

Ou seja, o desenvolvimento é pensado inicialmente para dispositivos móveis e posteriormente adaptado para telas maiores.

### Padronização

Mantém uma estrutura visual consistente ao longo do projeto.

### Compatibilidade

Reduz problemas relacionados às diferenças de renderização entre navegadores.

---

# Sistema de Grid

Uma das características mais importantes dos Frameworks CSS é o sistema de Grid.

---

## O que é Grid?

Grid é um recurso utilizado para organizar elementos visuais em linhas e colunas.

Seu objetivo é facilitar o alinhamento e distribuição dos conteúdos dentro da página.

---

## Sistema de Grid

Um sistema de grid é composto por:

* Containers
* Linhas (Rows)
* Colunas (Columns)

Exemplo simplificado:

```text
---------------------------------
|            Header             |
---------------------------------
| Menu |      Conteúdo          |
---------------------------------
|            Footer             |
---------------------------------
```

---

## Benefícios do Grid

* Organização do layout
* Melhor alinhamento visual
* Facilidade de manutenção
* Responsividade
* Reutilização de estruturas

---

# Bootstrap

## Visão Geral

O Bootstrap é o framework CSS mais popular do mercado.

Foi criado em 2011 pela equipe do Twitter e posteriormente tornou-se um projeto independente de código aberto.

---

## Características

* Open Source
* Mobile First
* Sistema de Grid
* Componentes prontos
* Grande comunidade
* Excelente documentação

---

## Componentes Disponíveis

Exemplos:

* Botões
* Formulários
* Tabelas
* Menus
* Modais
* Cards
* Alertas
* Navegação

---

## Sistema de Grid do Bootstrap

O Bootstrap utiliza:

```text
12 Colunas
```

para organizar os elementos da página.

---

## Breakpoints Responsivos

Os layouts são ajustados automaticamente conforme o tamanho da tela.

| Categoria   | Tamanho  |
| ----------- | -------- |
| Extra Small | < 576px  |
| Small       | ≥ 576px  |
| Medium      | ≥ 768px  |
| Large       | ≥ 992px  |
| Extra Large | ≥ 1200px |

---

## Como Utilizar

O Bootstrap pode ser adicionado através de:

* Arquivos CSS e JavaScript
* CDN
* npm
* Gerenciadores de pacotes

---

# Foundation

## Visão Geral

Framework criado em 2011 com foco em flexibilidade e desenvolvimento responsivo.

Também segue a abordagem Mobile First.

---

## Características

* Sistema de Grid avançado
* Integração com SASS
* Componentes responsivos
* Estrutura altamente customizável

---

## Destaque

Possui um recurso específico para criação de e-mails responsivos:

```text
Foundation for Emails
```

---

# Semantic UI

## Visão Geral

Framework que busca tornar o código mais intuitivo através de nomes de classes semânticos.

---

## Características

* Open Source
* Utiliza LESS
* Integração com jQuery
* Classes de fácil leitura

---

## Exemplo

```html
<div class="ui button">
  Salvar
</div>
```

A nomenclatura procura se aproximar da linguagem natural.

---

# Outros Frameworks Populares

## Pure CSS

Desenvolvido pela Yahoo.

### Características

* Leve
* Simples
* Pequeno tamanho

---

## Materialize CSS

Baseado no Material Design do Google.

### Características

* Visual moderno
* Componentes inspirados nos produtos Google
* Foco em experiência do usuário

---

## Bulma

Framework baseado exclusivamente em CSS.

### Características

* Não depende de JavaScript
* Fácil de aprender
* Estrutura moderna

---

## Skeleton

Framework minimalista.

### Características

* Poucas linhas de código
* Muito leve
* Ideal para projetos pequenos

---

# Vantagens dos Frameworks

## Padronização

Facilita o trabalho em equipe.

---

## Economia de Tempo

Reduz a necessidade de escrever CSS do zero.

---

## Responsividade

Grande parte dos componentes já é preparada para diferentes dispositivos.

---

## Compatibilidade

Funciona de maneira consistente entre navegadores.

---

## Documentação

Frameworks populares possuem ampla documentação e comunidade ativa.

---

# Desvantagens dos Frameworks

## Tamanho do Projeto

Pode adicionar arquivos e recursos desnecessários ao projeto.

---

## Curva de Aprendizado

É necessário aprender as convenções e estruturas próprias de cada framework.

---

## Menor Controle

Nem sempre é simples modificar comportamentos padrões dos componentes.

---

## Restrições de Design

Alguns layouts podem ficar limitados às estruturas impostas pelo framework.

---

# Quando Utilizar um Framework?

Frameworks são recomendados quando:

* O projeto precisa ser desenvolvido rapidamente.
* É necessário manter um padrão visual.
* A equipe trabalha de forma colaborativa.
* Existe necessidade de responsividade pronta.
* Deseja-se aproveitar componentes já testados.

---

# Conceitos Praticados

✔ Framework CSS

✔ Bootstrap

✔ Foundation

✔ Semantic UI

✔ Grid System

✔ Mobile First

✔ Responsividade

✔ Componentes Reutilizáveis

✔ Padronização de Layout

✔ Compatibilidade entre Navegadores
