# Fontes_Intro

## CSS3 e Recursos de Fontes

O CSS evoluiu ao longo dos anos até chegar à sua versão atual, o CSS3, trazendo diversos recursos para estilização de páginas web.

Entre os recursos mais utilizados estão:

* Manipulação de cores
* Estilização de textos
* Controle de fontes
* Utilização de Web Fonts

---

# Recursos de Cores

As cores podem ser aplicadas a diferentes elementos HTML, como textos, fundos, bordas e contornos.

## Formas de Definir Cores

### 1. Palavras-chave

Utiliza os nomes definidos pela especificação CSS.

```css
color: red;
background-color: blue;
```

### 2. Notação Hexadecimal

```css
color: #FFFFFF;
background-color: #000000;
```

### 3. Sistema RGB

Representa as cores através da combinação de:

* Red (Vermelho)
* Green (Verde)
* Blue (Azul)

```css
color: rgb(255, 0, 0);
```

### 4. Sistema RGBA

Mesmo conceito do RGB, porém adiciona transparência.

```css
color: rgba(255, 0, 0, 0.5);
```

### 5. Sistema HSL

Representa cores utilizando:

* Hue (Matiz)
* Saturation (Saturação)
* Lightness (Luminosidade)

```css
color: hsl(0, 100%, 50%);
```

### 6. Sistema HSLA

Versão do HSL com transparência.

```css
color: hsla(0, 100%, 50%, 0.5);
```

---

## Principais Propriedades de Cor

| Propriedade      | Função                  |
| ---------------- | ----------------------- |
| color            | Cor do texto            |
| background-color | Cor de fundo            |
| border-color     | Cor da borda            |
| outline-color    | Cor do contorno externo |

### Exemplos

```css
color: blue;
background-color: #cccccc;
border-color: black;
outline-color: red;
```

---

# Recursos de Texto

A estilização textual pode ser dividida em duas áreas:

## Layout do Texto

Controla:

* Alinhamento
* Espaçamento entre linhas
* Espaçamento entre letras
* Espaçamento entre palavras

## Estilo da Fonte

Controla:

* Família da fonte
* Tamanho
* Negrito
* Itálico
* Peso da fonte

---

# Alinhamento de Texto

A propriedade `text-align` controla o alinhamento do conteúdo dentro do elemento.

## Valores

```css
text-align: left;
text-align: right;
text-align: center;
text-align: justify;
```

| Valor   | Resultado         |
| ------- | ----------------- |
| left    | Alinha à esquerda |
| right   | Alinha à direita  |
| center  | Centraliza        |
| justify | Justifica o texto |

---

# Espaçamento Entre Linhas

A propriedade `line-height` controla a distância vertical entre linhas.

## Exemplo

```css
font-size: 12px;
line-height: 1.5;
```

Resultado:

```text
12px × 1.5 = 18px
```

### Formas de Definição

#### Valor padrão

```css
line-height: normal;
```

#### Valor numérico

```css
line-height: 1.5;
```

#### Unidade de medida

```css
line-height: 18px;
```

### Boa prática

Preferir valores numéricos:

```css
line-height: 1.5;
```

pois acompanham automaticamente alterações no tamanho da fonte.

---

# Espaçamento Entre Letras

Propriedade:

```css
letter-spacing
```

Exemplo:

```css
letter-spacing: 2px;
```

---

# Espaçamento Entre Palavras

Propriedade:

```css
word-spacing
```

Exemplo:

```css
word-spacing: 5px;
```

---

# Recursos de Fontes

## Font Family

Define qual fonte será utilizada.

### Exemplo

```css
font-family: Arial;
```

### Lista de Fontes

```css
font-family: Arial, Verdana, sans-serif;
```

Caso a primeira fonte não esteja disponível, o navegador utilizará a próxima da lista.

---

## Fontes Seguras para Web

Também chamadas de **Web Safe Fonts**.

Exemplos:

* Arial
* Verdana
* Times New Roman
* Georgia
* Courier New
* Tahoma

### Recomendação

Sempre definir uma lista de fontes e finalizar com uma família genérica:

```css
font-family: Arial, Verdana, sans-serif;
```

---

## Font Size

Define o tamanho do texto.

### Exemplo

```css
font-size: 16px;
```

Outras unidades comuns:

```css
font-size: 120%;
font-size: 1.2em;
font-size: 1rem;
```

---

## Font Style

Aplica efeitos de inclinação.

### Valores

```css
font-style: normal;
font-style: italic;
font-style: oblique;
```

| Valor   | Resultado            |
| ------- | -------------------- |
| normal  | Sem inclinação       |
| italic  | Itálico              |
| oblique | Inclinação acentuada |

---

## Font Weight

Controla o peso da fonte.

### Valores textuais

```css
font-weight: normal;
font-weight: bold;
font-weight: lighter;
font-weight: bolder;
```

### Escala Numérica

```css
font-weight: 100;
font-weight: 400;
font-weight: 700;
font-weight: 900;
```

| Valor | Peso         |
| ----- | ------------ |
| 100   | Muito fino   |
| 400   | Normal       |
| 700   | Negrito      |
| 900   | Muito pesado |

---

# Web Fonts

Antes do CSS3, o desenvolvedor dependia das fontes instaladas no computador do usuário.

Com a regra `@font-face`, tornou-se possível carregar fontes personalizadas diretamente pelo navegador.

## Vantagens

* Maior controle visual
* Melhor identidade visual
* Mais opções tipográficas
* Layout consistente entre dispositivos

---

# Regra @font-face

Permite importar fontes locais ou hospedadas na internet.

## Estrutura Básica

```css
@font-face {
    font-family: "MinhaFonte";
    src: url("fonte.woff2");
}
```

---

## Principais Propriedades

### font-family

Define o nome utilizado posteriormente no CSS.

```css
font-family: "Nunito";
```

### src

Indica o local onde a fonte está armazenada.

```css
src: url("Nunito.woff2");
```

---

## Utilização da Fonte

```css
body {
    font-family: "Nunito", sans-serif;
}
```

---

# Tipos de Web Fonts

| Formato | Descrição                             |
| ------- | ------------------------------------- |
| TTF     | TrueType Font                         |
| OTF     | OpenType Font                         |
| WOFF    | Web Open Font Format                  |
| WOFF2   | Versão otimizada do WOFF              |
| SVG     | Fontes vetoriais SVG                  |
| EOT     | Embedded OpenType (Internet Explorer) |

---

## Recomendação Atual

Sempre que possível utilizar:

```text
WOFF2
```

Motivos:

* Melhor compressão
* Arquivos menores
* Melhor desempenho
* Amplo suporte em navegadores modernos

---

# Boas Práticas

* Utilizar fontes seguras sempre que possível.
* Definir fontes de fallback.
* Priorizar formatos WOFF2.
* Evitar importar fontes desnecessárias.
* Utilizar Web Fonts apenas quando agregarem valor ao projeto.
* Sempre finalizar a lista de fontes com uma família genérica:

```css
font-family: "Nunito", Arial, sans-serif;
```
