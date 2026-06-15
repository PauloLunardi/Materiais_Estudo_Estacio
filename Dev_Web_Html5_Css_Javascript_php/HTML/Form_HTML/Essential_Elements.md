# Formulários HTML

## Elementos essenciais

1. Estrutura do formulário
2. Elementos e atributos do formulário
3. Atributos do formulário: atributo `type`
4. Novos atributos e tipos de entrada

---

## Motivação

* Um formulário HTML é uma ótima maneira de interagir com um usuário.
* Esses formulários foram o ponto de partida de diversos frameworks modernos.
* Permitem coletar, validar e enviar informações para um servidor.
* São amplamente utilizados em cadastros, pesquisas, logins e sistemas web.

---

## Estrutura Básica

A tag principal utilizada para criar formulários é:

```html
<form>
    <!-- Campos do formulário -->
</form>
```

### Principais atributos da tag `<form>`

| Atributo       | Função                                     |
| -------------- | ------------------------------------------ |
| `action`       | Define para onde os dados serão enviados   |
| `method`       | Define o método de envio (`GET` ou `POST`) |
| `name`         | Nome do formulário                         |
| `target`       | Define onde a resposta será exibida        |
| `autocomplete` | Ativa ou desativa sugestões automáticas    |
| `novalidate`   | Desabilita validações automáticas          |

### Exemplo

```html
<form action="/cadastro" method="post">
    ...
</form>
```

---

## Elementos de Formulário

### Campo de Entrada

```html
<input>
```

Utilizado para capturar informações do usuário.

### Rótulo

```html
<label>
```

Associa um texto descritivo a um campo.

Exemplo:

```html
<label for="nome">Nome:</label>
<input type="text" id="nome">
```

### Área de Texto

```html
<textarea>
```

Permite inserir textos longos.

### Lista Suspensa

```html
<select>
    <option>Opção 1</option>
    <option>Opção 2</option>
</select>
```

### Botão

```html
<button>
```

ou

```html
<input type="submit">
```

---

## Atributos Importantes dos Campos

| Atributo      | Função                                                |
| ------------- | ----------------------------------------------------- |
| `id`          | Identificador único                                   |
| `name`        | Nome enviado ao servidor                              |
| `value`       | Valor inicial                                         |
| `placeholder` | Exibe um texto de exemplo dentro do campo             |
| `required`    | Torna o preenchimento obrigatório                     |
| `autofocus`   | Define o campo que receberá foco ao carregar a página |
| `readonly`    | Permite apenas leitura                                |
| `disabled`    | Desabilita o campo                                    |
| `maxlength`   | Limita a quantidade máxima de caracteres              |
| `minlength`   | Define a quantidade mínima de caracteres              |
| `min`         | Valor mínimo permitido                                |
| `max`         | Valor máximo permitido                                |
| `pattern`     | Valida o conteúdo usando Expressões Regulares (RegEx) |

### Exemplos

```html
<input type="text" placeholder="Digite seu nome">

<input type="text" required>

<input type="text" autofocus>

<input type="tel" pattern="[0-9]{11}">
```

---

## Tipos do atributo `type`

### Texto
```html
<input type="text">
```
Campo para texto simples.

### Senha
```html
<input type="password">
```
Oculta os caracteres digitados.

### E-mail
```html
<input type="email">
```
Valida automaticamente o formato de e-mail.

### Número
```html
<input type="number">
```
Aceita apenas valores numéricos.

### Data
```html
<input type="date">
```
Exibe seletor de data.

### Telefone
```html
<input type="tel">
```
Utilizado para inserção de números de telefone.
**Observação:** recomenda-se utilizar juntamente com o atributo `pattern` para validar o formato esperado.

### Data e Hora
```html
<input type="datetime-local">
```
Permite informar data e hora.

### Data
```html
<input type="date">
```
Permite selecionar uma data através de um calendário fornecido pelo navegador.

### Número
```html
<input type="number">
```
Permite a entrada de valores numéricos.
**Observação:** normalmente apresenta controles de incremento e decremento através de setas no navegador.

### Arquivo
```html
<input type="file">
```
Permite upload de arquivos.

### Botão de Envio
```html
<input type="submit">
```
Envia os dados do formulário.

### Botão de Limpeza
```html
<input type="reset">
```
Limpa os campos preenchidos.

### Botão Comum
```html
<input type="button">
```
Utilizado normalmente com JavaScript.

---

## Seleção de Opções

### Checkbox

Permite selecionar múltiplas opções.

```html
<input type="checkbox">
```

### Radio Button

Permite selecionar apenas uma opção.

```html
<input type="radio">
```

---

## Novos Tipos de Entrada (HTML5)

| Tipo             | Função              |
| ---------------- | ------------------- |
| `email`          | Validação de e-mail |
| `url`            | Validação de URL    |
| `tel`            | Número de telefone  |
| `search`         | Campo de pesquisa   |
| `date`           | Data                |
| `time`           | Horário             |
| `datetime-local` | Data e hora         |
| `month`          | Mês                 |
| `week`           | Semana              |
| `color`          | Seletor de cores    |
| `range`          | Controle deslizante |
| `number`         | Valores numéricos   |

---

## Validação de Formulários

HTML5 oferece validações nativas sem necessidade de JavaScript.

### Campo obrigatório

```html
<input type="text" required>
```

### Limite mínimo e máximo

```html
<input type="number" min="1" max="100">
```

### Quantidade mínima de caracteres

```html
<input type="password" minlength="8">
```

### Expressões Regulares

```html
<input type="text" pattern="[A-Za-z]{3,}">
```

---

## Métodos de Envio

### GET

```html
<form method="get">
```

* Dados aparecem na URL.
* Indicado para pesquisas e filtros.

### POST

```html
<form method="post">
```

* Dados enviados no corpo da requisição.
* Mais seguro para formulários de cadastro e login.

---

## Tags Relacionadas

| Tag          | Função                    |
| ------------ | ------------------------- |
| `<form>`     | Container principal       |
| `<input>`    | Campo de entrada          |
| `<label>`    | Rótulo                    |
| `<textarea>` | Texto longo               |
| `<select>`   | Lista suspensa            |
| `<option>`   | Item da lista             |
| `<button>`   | Botão                     |
| `<fieldset>` | Agrupa campos             |
| `<legend>`   | Título do grupo de campos |

### Exemplo de Agrupamento

```html
<fieldset>
    <legend>Dados Pessoais</legend>

    <label>Nome:</label>
    <input type="text">
</fieldset>
```
