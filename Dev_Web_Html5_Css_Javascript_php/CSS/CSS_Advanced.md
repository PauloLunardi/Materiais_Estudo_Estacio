# CSS Advanced

## Conceitos Avançados

Após aprender a sintaxe básica do CSS, seus seletores e formas de integração com HTML, é possível explorar recursos mais avançados relacionados a layout, posicionamento e estilização de elementos.

## Tópicos Abordados

1. Box Model
2. Pseudoclasses
3. Pseudoelementos
4. Posicionamento
5. Layout em Colunas
6. Grid Layout

---

# Box Model

O Box Model (Modelo de Caixas) é um dos conceitos fundamentais do CSS.

Todo elemento HTML pode ser interpretado como uma caixa composta por quatro áreas principais:

1. Content (Conteúdo)
2. Padding (Preenchimento)
3. Border (Borda)
4. Margin (Margem)

## Estrutura do Box Model

```text
Margin
 └── Border
      └── Padding
           └── Content
```

---

## Content

Área onde o conteúdo do elemento é exibido.

Exemplos:

* Texto
* Imagens
* Links
* Formulários

---

## Padding

Define o espaço interno entre o conteúdo e a borda do elemento.

### Propriedades

```css
padding-top
padding-right
padding-bottom
padding-left
```

### Atalho

```css
padding: 20px;
```

### Observação

O padding aumenta as dimensões totais do elemento.

Exemplo:

```css
width: 400px;
padding: 50px;
```

Resultado:

```text
400 + 50 + 50 = 500px
```

---

## Border

Define a borda do elemento.

### Exemplo

```css
border: 1px solid black;
```

### Componentes

* Largura
* Tipo
* Cor

Exemplo:

```css
border-width: 2px;
border-style: solid;
border-color: blue;
```

---

## Margin

Define o espaço externo entre elementos.

### Propriedades

```css
margin-top
margin-right
margin-bottom
margin-left
```

### Atalho

```css
margin: 20px;
```

### Observação

A margin não altera o tamanho do elemento.

Ela apenas cria espaçamento ao redor dele.

---

# Pseudoclasses

Pseudoclasses permitem estilizar um elemento em um estado específico.

## Sintaxe

```css
seletor:pseudoclasse {
}
```

### Exemplo

```css
div:hover {
    background-color: black;
}
```

---

## Principais Pseudoclasses

### :hover

Executada quando o mouse passa sobre o elemento.

```css
button:hover {
    background-color: blue;
}
```

---

### :active

Aplica estilo ao elemento enquanto ele estiver ativo.

```css
a:active {
    color: red;
}
```

---

### :checked

Utilizada em inputs marcados.

```css
input:checked {
    border: 1px solid green;
}
```

---

### :first-child

Seleciona o primeiro filho de um elemento.

```css
li:first-child {
    font-weight: bold;
}
```

---

### :last-child

Seleciona o último filho de um elemento.

```css
li:last-child {
    color: red;
}
```

---

# Pseudoelementos

Permitem estilizar partes específicas de um elemento.

## Sintaxe

```css
seletor::pseudoelemento {
}
```

### Diferença

* Pseudoclasses → utilizam um ":"
* Pseudoelementos → utilizam "::"

---

## Principais Pseudoelementos

### ::before

Insere conteúdo antes do elemento.

```css
p::before {
    content: "➜ ";
}
```

---

### ::after

Insere conteúdo após o elemento.

```css
p::after {
    content: " ✓";
}
```

---

### ::first-letter

Estiliza a primeira letra.

```css
p::first-letter {
    font-size: 30px;
}
```

---

### ::first-line

Estiliza apenas a primeira linha.

```css
p::first-line {
    font-weight: bold;
}
```

---

### ::selection

Estiliza o texto selecionado pelo usuário.

```css
::selection {
    background: yellow;
}
```

---

# Posicionamento

A propriedade responsável pelo posicionamento dos elementos é:

```css
position
```

Ela normalmente é utilizada em conjunto com:

```css
top
right
bottom
left
```

---

# Position Static

Posicionamento padrão dos elementos.

```css
position: static;
```

### Características

* Fluxo normal da página.
* Ignora top, bottom, left e right.

---

# Position Relative

Posiciona o elemento relativamente à sua posição original.

```css
position: relative;
top: 20px;
left: 10px;
```

### Características

* Mantém seu espaço original.
* Permite pequenos deslocamentos.

---

# Position Absolute

Posiciona o elemento em relação ao ancestral posicionado mais próximo.

```css
position: absolute;
top: 50px;
left: 20px;
```

### Características

* Sai do fluxo normal.
* Pode sobrepor outros elementos.

---

# Position Fixed

Mantém o elemento fixo na tela.

```css
position: fixed;
top: 0;
right: 0;
```

### Características

* Não acompanha a rolagem da página.
* Muito utilizado em menus e botões flutuantes.

---

# Position Sticky

Mistura os comportamentos de Relative e Fixed.

```css
position: sticky;
top: 0;
```

### Características

* Inicialmente se comporta como Relative.
* Torna-se Fixed quando o scroll atinge determinada posição.

---

# Layout em Colunas

O CSS permite organizar elementos em múltiplas colunas.

Exemplo comum:

```text
Header
----------------

Menu | Conteúdo

----------------
Footer
```

Elementos frequentemente utilizados:

```html
<header>
<nav>
<section>
<aside>
<footer>
```

---

# Grid Layout

O CSS Grid é um sistema moderno de organização de layouts.

Permite criar:

* Linhas
* Colunas
* Áreas de conteúdo

### Exemplo

```css
display: grid;
```

### Vantagens

* Organização avançada de layouts.
* Controle preciso de linhas e colunas.
* Facilita a criação de interfaces responsivas.

---

# Conceitos Praticados

✔ Box Model

✔ Margin

✔ Border

✔ Padding

✔ Pseudoclasses

✔ Pseudoelementos

✔ Position

✔ Layout em Colunas

✔ Grid Layout

✔ Organização visual de páginas
