# Árvore DOM (Document Object Model)

## Motivação

Ao desenvolver aplicações web, não basta apenas estruturar uma página com HTML e aplicar estilos com CSS.

Muitas vezes é necessário alterar conteúdos dinamicamente, responder às ações do usuário e modificar elementos da página durante sua execução.

Para isso, utilizamos o JavaScript em conjunto com a interface DOM (Document Object Model), que permite acessar e manipular os elementos presentes em um documento HTML.

---

# O que é DOM?

DOM significa:

```text
Document Object Model
```

ou

```text
Modelo de Objeto de Documento
```

Trata-se de uma interface que representa um documento HTML como uma estrutura hierárquica em forma de árvore.

Por meio dessa estrutura, os elementos HTML podem ser acessados, modificados, removidos ou criados dinamicamente utilizando JavaScript.

---

# A Tríade do Desenvolvimento Web

O ambiente web moderno é composto por três tecnologias principais:

## HTML

Responsável pela estrutura e conteúdo da página.

Exemplos:

* Títulos
* Parágrafos
* Imagens
* Tabelas
* Formulários

---

## CSS

Responsável pela apresentação visual.

Exemplos:

* Cores
* Fontes
* Espaçamentos
* Layout
* Animações

---

## JavaScript

Responsável pelo comportamento e pela interatividade.

Exemplos:

* Validação de formulários
* Manipulação de conteúdo
* Eventos de clique
* Atualização dinâmica da página

---

# O que é uma Árvore DOM?

Quando um navegador interpreta um arquivo HTML, ele converte todos os elementos em uma estrutura de objetos chamada Árvore DOM.

Exemplo:

```html
<html>
  <body>
    <h1>Título</h1>
    <p>Parágrafo</p>
  </body>
</html>
```

Representação simplificada:

```text
Document
│
└── html
    │
    └── body
        │
        ├── h1
        │   └── "Título"
        │
        └── p
            └── "Parágrafo"
```

Cada elemento da página torna-se um nó dentro da árvore.

---

# Nós da Árvore DOM

A estrutura DOM é composta por diferentes tipos de nós.

## Document

Representa todo o documento HTML.

```javascript
document
```

---

## Element Node

Representa uma tag HTML.

Exemplos:

```html
<h1>
<p>
<div>
<img>
```

---

## Text Node

Representa o conteúdo textual de um elemento.

Exemplo:

```html
<p>Olá Mundo</p>
```

O texto:

```text
Olá Mundo
```

é armazenado como um nó de texto.

---

## Attribute Node

Representa atributos dos elementos.

Exemplo:

```html
<input type="text" id="nome">
```

Atributos:

```text
type
id
```

---

# Estrutura Hierárquica

A árvore DOM segue uma relação de parentesco.

## Elemento Pai (Parent)

Elemento que contém outros elementos.

Exemplo:

```html
<div>
  <p>Texto</p>
</div>
```

O elemento:

```html
<div>
```

é pai do:

```html
<p>
```

---

## Elemento Filho (Child)

Elemento contido dentro de outro elemento.

Exemplo:

```html
<p>
```

é filho de:

```html
<div>
```

---

## Elementos Irmãos (Siblings)

Elementos que possuem o mesmo pai.

Exemplo:

```html
<div>
  <h1>Título</h1>
  <p>Texto</p>
</div>
```

Os elementos:

```html
<h1>
```

e

```html
<p>
```

são irmãos.

---

# Manipulando o DOM com JavaScript

Uma das principais funções do JavaScript é interagir com o DOM.

Por meio dele é possível:

* Criar elementos
* Alterar elementos
* Remover elementos
* Modificar estilos
* Alterar textos
* Responder a eventos do usuário

---

# Selecionando Elementos

## Por ID

```javascript
const titulo = document.getElementById("titulo");
```

---

## Por Classe

```javascript
const elemento = document.getElementsByClassName("card");
```

---

## Por Tag

```javascript
const paragrafos = document.getElementsByTagName("p");
```

---

## Query Selector

Seleciona o primeiro elemento encontrado.

```javascript
const titulo = document.querySelector("#titulo");
```

---

## Query Selector All

Seleciona todos os elementos correspondentes.

```javascript
const itens = document.querySelectorAll(".item");
```

---

# Alterando Conteúdo

## innerHTML

Permite alterar o conteúdo HTML.

```javascript
document.getElementById("titulo").innerHTML =
"Novo Título";
```

---

## textContent

Altera apenas o texto.

```javascript
document.getElementById("titulo").textContent =
"Novo Texto";
```

---

# Alterando Estilos

É possível modificar propriedades CSS diretamente pelo JavaScript.

Exemplo:

```javascript
const titulo =
document.getElementById("titulo");

titulo.style.color = "blue";
titulo.style.fontSize = "32px";
```

---

# Criando Elementos

Novos elementos podem ser inseridos durante a execução.

Exemplo:

```javascript
const paragrafo =
document.createElement("p");

paragrafo.textContent =
"Novo elemento criado";

document.body.appendChild(paragrafo);
```

---

# Removendo Elementos

Exemplo:

```javascript
const elemento =
document.getElementById("titulo");

elemento.remove();
```

---

# Eventos e DOM

Os eventos permitem que o JavaScript responda às ações do usuário.

Exemplos:

* Clique
* Teclado
* Movimento do mouse
* Envio de formulário

---

## Evento de Clique

```javascript
const botao =
document.getElementById("btn");

botao.addEventListener("click", function() {
  alert("Botão clicado!");
});
```

---

# Manipulação Dinâmica

Uma característica importante da DOM é que as alterações realizadas pelo JavaScript acontecem apenas durante a sessão atual do usuário.

Isso significa que:

* Elementos criados dinamicamente não ficam salvos permanentemente.
* Alterações desaparecem quando a página é recarregada.
* Novas modificações dependem da execução do JavaScript.

---

# DOM e JavaScript

É importante lembrar:

> O DOM não faz parte do JavaScript.

O DOM é uma interface disponibilizada pelo navegador.

O JavaScript apenas utiliza essa interface para acessar e manipular os elementos do documento.

Outras linguagens também podem interagir com o DOM.

---

# Conceitos Importantes

✔ Document Object Model (DOM)

✔ Estrutura em Árvore

✔ Nós (Nodes)

✔ Parent, Child e Siblings

✔ Seleção de Elementos

✔ Manipulação de Conteúdo

✔ Manipulação de Estilos

✔ Criação de Elementos

✔ Remoção de Elementos

✔ Eventos

✔ Interatividade com JavaScript

✔ Integração entre HTML, CSS e JavaScript
