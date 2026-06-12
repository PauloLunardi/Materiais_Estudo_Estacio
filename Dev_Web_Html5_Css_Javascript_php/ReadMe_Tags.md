# 📚 Resumo — Tags HTML Básicas

## 🎯 O que são Tags HTML?

Tags são elementos utilizados para estruturar e dar significado ao conteúdo de uma página web. Elas são escritas entre os símbolos `< >` e, na maioria dos casos, possuem abertura e fechamento.

Exemplo:

```html
<h1>Título</h1>
<p>Parágrafo de texto</p>
```

---

## ⚙️ Atributos

Atributos adicionam informações extras às tags.

Exemplo:

```html
<img src="imagem.jpg" alt="Descrição da imagem">
```

### Principais atributos

| Atributo | Função                                           |
| -------- | ------------------------------------------------ |
| `id`     | Identifica um elemento de forma única            |
| `class`  | Agrupa elementos com características semelhantes |
| `src`    | Define o caminho de uma imagem                   |
| `alt`    | Define um texto alternativo para imagens         |

---

## 📝 Tags Textuais

Utilizadas para exibir conteúdo textual, links e mídias.

| Tag             | Função                            |
| --------------- | --------------------------------- |
| `<h1>` a `<h6>` | Títulos e subtítulos hierárquicos |
| `<p>`           | Parágrafo                         |
| `<a>`           | Link para outra página ou recurso |
| `<img>`         | Inserção de imagens               |
| `<pre>`         | Texto pré-formatado               |
| `<br>`          | Quebra de linha                   |
| `<hr>`          | Linha horizontal de separação     |

### Exemplo

```html
<h1>Meu Site</h1>
<p>Bem-vindo ao meu site.</p>
<a href="https://exemplo.com">Clique aqui</a>
```

---

## 🏗️ Tags Semânticas

Introduzidas principalmente no HTML5 para organizar melhor a estrutura do conteúdo.

| Tag         | Função                                            |
| ----------- | ------------------------------------------------- |
| `<article>` | Conteúdo independente (artigo, postagem, notícia) |
| `<section>` | Agrupa conteúdos relacionados                     |
| `<header>`  | Cabeçalho da página ou seção                      |
| `<footer>`  | Rodapé da página ou seção                         |
| `<nav>`     | Área de navegação                                 |
| `<main>`    | Conteúdo principal da página                      |

### Benefícios

* Melhor organização do código
* Maior acessibilidade
* Melhor interpretação pelos mecanismos de busca (SEO)

---

## 📦 Tags de Agrupamento

Utilizadas para organizar elementos sem adicionar significado semântico específico.

| Tag      | Função               |
| -------- | -------------------- |
| `<div>`  | Agrupamento em bloco |
| `<span>` | Agrupamento em linha |

### Diferença

```html
<div>Cria uma nova seção</div>

<span>Agrupa conteúdo sem quebrar a linha</span>
```

---

## ✨ Tags de Formatação

Aplicam destaque ao conteúdo.

| Tag        | Função                            |
| ---------- | --------------------------------- |
| `<b>`      | Negrito visual                    |
| `<strong>` | Negrito com importância semântica |
| `<i>`      | Itálico visual                    |
| `<em>`     | Itálico com ênfase semântica      |

### Exemplo

```html
<strong>Texto importante</strong>

<em>Texto com ênfase</em>
```

---

## ⚠️ Tags Obsoletas

Devem ser evitadas porque foram substituídas por soluções mais modernas.

| Tag        | Motivo                             |
| ---------- | ---------------------------------- |
| `<center>` | Substituída por CSS                |
| `<font>`   | Estilização deve ser feita com CSS |
| `<applet>` | Tecnologia descontinuada           |
| `<dir>`    | Sem uso moderno                    |
| `<image>`  | Substituída por `<img>`            |

---

## 📌 Boas Práticas

* Utilizar tags de acordo com seu significado.
* Priorizar tags semânticas.
* Evitar tags obsoletas.
* Utilizar `id` e `class` para estilização e manipulação via CSS e JavaScript.
* Manter uma estrutura organizada e acessível.

---

## 🚀 Resumo Final

As tags HTML podem ser divididas em quatro grandes grupos:

* **Textuais:** exibem conteúdo (`<p>`, `<h1>`, `<a>`, `<img>`).
* **Semânticas:** organizam o significado da página (`<article>`, `<section>`).
* **Agrupamento:** estruturam elementos (`<div>`, `<span>`).
* **Formatação:** destacam conteúdo (`<strong>`, `<em>`).

A utilização correta dessas tags torna o código mais organizado, acessível e compatível com as boas práticas do desenvolvimento web.
