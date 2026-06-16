# CSS — Cascading Style Sheets

## O que é CSS?

CSS (Cascading Style Sheets) é uma linguagem utilizada para definir a aparência visual de páginas HTML.

Enquanto o HTML é responsável pela estrutura e conteúdo da página, o CSS é responsável pela apresentação visual, permitindo alterar cores, tamanhos, espaçamentos, posicionamentos e diversos outros aspectos do layout.

---

## Motivação

* Separar estrutura (HTML) de apresentação (CSS).
* Melhorar a aparência das páginas web.
* Facilitar a manutenção do código.
* Promover reutilização de estilos.
* Criar layouts responsivos e modernos.

---

## Assuntos Abordados

### 1. Sintaxe do CSS

Estrutura básica de uma regra CSS.

```css
seletor {
    propriedade: valor;
}
```

Exemplo:

```css
h1 {
    color: blue;
}
```

---

### 2. Formas de Aplicação

#### CSS Inline

Aplicado diretamente em uma tag HTML.

```html
<p style="color: blue;">Texto</p>
```

#### CSS Interno

Definido dentro da tag `<style>`.

```html
<style>
p {
    color: blue;
}
</style>
```

#### CSS Externo

Arquivo separado com extensão `.css`.

```html
<link rel="stylesheet" href="style.css">
```

---

### 3. Seletores

Utilizados para identificar quais elementos receberão os estilos.

#### Seletor de Elemento

```css
p {
    color: black;
}
```

#### Seletor de Classe

```css
.destaque {
    color: red;
}
```

```html
<p class="destaque">Texto</p>
```

#### Seletor de ID

```css
#titulo {
    color: blue;
}
```

```html
<h1 id="titulo">Título</h1>
```

---

### 4. Cores

Alteração das cores dos elementos.

```css
color: red;
background-color: yellow;
```

Formas de definir cores:

```css
color: blue;
color: #0000FF;
color: rgb(0, 0, 255);
```

---

### 5. Fontes e Textos

Manipulação da aparência dos textos.

```css
font-size: 20px;
font-family: Arial;
font-weight: bold;
text-align: center;
```

---

### 6. Espaçamentos

Controle dos espaços internos e externos.

#### Margin

Espaço externo ao elemento.

```css
margin: 20px;
```

#### Padding

Espaço interno do elemento.

```css
padding: 20px;
```

---

### 7. Bordas

Adiciona bordas aos elementos.

```css
border: 1px solid black;
```

Exemplo:

```css
div {
    border: 2px solid blue;
}
```

---

### 8. Dimensões

Controle de largura e altura.

```css
width: 300px;
height: 150px;
```

---

### 9. Box Model

Todo elemento HTML é tratado como uma caixa composta por:

* Content (conteúdo)
* Padding (espaçamento interno)
* Border (borda)
* Margin (espaçamento externo)

Representação:

```text
Margin
 └─ Border
     └─ Padding
         └─ Content
```

---

### 10. Posicionamento

Define como os elementos serão exibidos na página.

```css
position: static;
position: relative;
position: absolute;
position: fixed;
```

---

### 11. Flexbox

Ferramenta moderna para alinhamento e distribuição de elementos.

```css
display: flex;
```

Permite:

* Alinhamento horizontal.
* Alinhamento vertical.
* Distribuição automática de espaço.
* Criação de layouts responsivos.

---

### 12. Responsividade

Permite adaptar o layout para diferentes dispositivos.

```css
@media (max-width: 768px) {
    body {
        font-size: 14px;
    }
}
```

---

## Principais Propriedades

| Propriedade      | Função                      |
| ---------------- | --------------------------- |
| color            | Cor do texto                |
| background-color | Cor de fundo                |
| font-size        | Tamanho da fonte            |
| font-family      | Família da fonte            |
| text-align       | Alinhamento do texto        |
| width            | Largura                     |
| height           | Altura                      |
| margin           | Espaçamento externo         |
| padding          | Espaçamento interno         |
| border           | Borda                       |
| display          | Forma de exibição           |
| position         | Posicionamento              |
| flex             | Controle de layouts Flexbox |

---

## Arquivo CSS Externo

Exemplo de organização:

```text
Projeto
│
├── index.html
└── style.css
```

### index.html

```html
<link rel="stylesheet" href="style.css">
```

### style.css

```css
body {
    font-family: Arial;
}
```

