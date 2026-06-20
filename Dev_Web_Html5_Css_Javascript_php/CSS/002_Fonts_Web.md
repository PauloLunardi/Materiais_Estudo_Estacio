# Web Fonts com CSS3

## Objetivo

Praticar a utilização de **Web Fonts** através da regra `@font-face`, introduzida no CSS3.

Antes desse recurso, os desenvolvedores dependiam das fontes instaladas no computador do usuário. Com o CSS3, tornou-se possível incorporar fontes externas, proporcionando maior controle visual e consistência na apresentação do conteúdo.

---

## Conceitos Praticados

* CSS3
* Web Fonts
* Regra `@font-face`
* Propriedade `font-family`
* Propriedade `src`
* Seletores CSS
* Estilização de textos

---

## Ferramentas Utilizadas

### Google Fonts

Utilizado para pesquisar e baixar fontes gratuitas.

https://fonts.google.com/

### CloudConvert

Utilizado para converter arquivos de fonte para formatos compatíveis com a web.

https://cloudconvert.com/

---

## Passo a Passo

### 1. Escolher uma fonte

Acessar o Google Fonts e selecionar uma fonte desejada.

Exemplo:

* Nunito
* Roboto
* Open Sans
* Montserrat

### 2. Baixar a fonte

Realizar o download da família de fontes escolhida.

### 3. Converter a fonte

Caso necessário, converter o arquivo para um formato mais adequado para web.

Formato recomendado:

```text
WOFF2
```

### 4. Salvar os arquivos

Salvar o arquivo da fonte na mesma pasta do projeto HTML ou em uma pasta específica para fontes.

Exemplo:

```text
Projeto/
│
├── 002_Fonts_Web.html
└── Nunito-VariableFont_wght.woff2
```

### 5. Declarar a fonte

Utilizar a regra `@font-face`.

Exemplo:

```css
@font-face {
    font-family: "Nunito";
    src: url("Nunito-VariableFont_wght.woff2") format("woff2");
}
```

### 6. Aplicar a fonte

Associar a fonte a um elemento HTML através da propriedade `font-family`.

Exemplo:

```css
#container {
    font-family: Nunito;
}
```

### 7. Testar no navegador

Abrir o arquivo HTML e verificar se a fonte foi carregada corretamente.

---

## Estrutura Básica

```css
@font-face {
    font-family: "MinhaFonte";
    src: url("MinhaFonte.woff2") format("woff2");
}

#container {
    font-family: MinhaFonte;
}
```

---

## Formatos de Fontes para Web

| Formato | Descrição                |
| ------- | ------------------------ |
| TTF     | TrueType Font            |
| OTF     | OpenType Font            |
| WOFF    | Web Open Font Format     |
| WOFF2   | Versão otimizada do WOFF |

### Recomendação

Sempre que possível utilizar:

```text
WOFF2
```

Vantagens:

* Melhor compressão
* Menor tamanho de arquivo
* Melhor desempenho
* Suporte aos navegadores modernos

---

## Observações

* O navegador precisa encontrar corretamente o arquivo da fonte.
* O caminho informado em `src` deve corresponder à localização real do arquivo.
* É recomendado definir fontes alternativas (fallbacks).

Exemplo:

```css
font-family: "Nunito", Arial, sans-serif;
```

Caso a fonte principal não seja carregada, o navegador utilizará a próxima disponível na lista.

---

## Resultado Esperado

Ao carregar a página, o navegador fará o download da fonte definida em `@font-face` e a utilizará para renderizar os elementos configurados com a propriedade `font-family`.
