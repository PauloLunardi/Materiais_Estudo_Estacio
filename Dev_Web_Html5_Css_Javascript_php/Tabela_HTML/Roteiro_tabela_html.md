# Tabelas HTML

## Roteiro na prática

### Considerações

1. Criar uma tabela simples.
2. Criar uma tabela que contenha título.
3. A tabela deve conter cabeçalho e rodapé.
4. A tabela deve possuir linhas e colunas expandidas.
5. Um case exemplo completo.

---

## Motivação

* Colocar os conhecimentos em prática.
* Consolidar o aprendizado.
* Notar oportunidade de melhorias.
* Organizar dados em formato tabular.
* Aprender a utilizar recursos semânticos do HTML.

---

## Estrutura Básica

A tag principal utilizada para criar tabelas é:

```html
<table>
    ...
</table>
```

Uma tabela é composta por:

* Linhas (`<tr>`)
* Colunas (`<td>`)
* Cabeçalhos (`<th>`)

### Exemplo

```html
<table border="1">
    <tr>
        <td>Nome</td>
        <td>Curso</td>
    </tr>

    <tr>
        <td>Paulo</td>
        <td>HTML</td>
    </tr>
</table>
```

---

## Principais Tags

| Tag         | Função                         |
| ----------- | ------------------------------ |
| `<table>`   | Container principal da tabela  |
| `<tr>`      | Define uma linha               |
| `<td>`      | Define uma célula comum        |
| `<th>`      | Define uma célula de cabeçalho |
| `<thead>`   | Cabeçalho da tabela            |
| `<tbody>`   | Corpo da tabela                |
| `<tfoot>`   | Rodapé da tabela               |
| `<caption>` | Título da tabela               |

---

## Tabela com Título

A tag `<caption>` adiciona um título à tabela.

### Exemplo

```html
<table border="1">

    <caption>Lista de Alunos</caption>

    <tr>
        <th>Nome</th>
        <th>Curso</th>
    </tr>

</table>
```

---

## Cabeçalho e Rodapé

Para melhorar a organização e a semântica da tabela, utilizamos:

* `<thead>` → Cabeçalho
* `<tbody>` → Corpo
* `<tfoot>` → Rodapé

### Exemplo

```html
<table border="1">

    <thead>
        <tr>
            <th>Produto</th>
            <th>Quantidade</th>
        </tr>
    </thead>

    <tbody>
        <tr>
            <td>Notebook</td>
            <td>10</td>
        </tr>
    </tbody>

    <tfoot>
        <tr>
            <td>Total</td>
            <td>10</td>
        </tr>
    </tfoot>

</table>
```

---

## Expansão de Colunas

Utilizamos o atributo `colspan`.

### Função

Permite que uma célula ocupe várias colunas.

### Exemplo

```html
<table border="1">

<tr>
    <th>Aluno</th>
    <th colspan="2">Disciplina</th>
</tr>

<tr>
    <td>Alex</td>
    <td>HTML</td>
    <td>Ambiente Web</td>
</tr>

</table>
```

### Observação

```html
colspan="2"
```

A célula ocupará o espaço equivalente a duas colunas.

---

## Expansão de Linhas

Utilizamos o atributo `rowspan`.

### Função

Permite que uma célula ocupe várias linhas.

### Exemplo

```html
<table border="1">

<tr>
    <td rowspan="2">Alex</td>
    <td>HTML</td>
</tr>

<tr>
    <td>Ambiente Web</td>
</tr>

</table>
```

### Observação

```html
rowspan="2"
```

A célula ocupará o espaço equivalente a duas linhas.

---

## Atributos Comuns

| Atributo  | Função                   |
| --------- | ------------------------ |
| `border`  | Define a borda da tabela |
| `width`   | Define largura           |
| `height`  | Define altura            |
| `colspan` | Expande colunas          |
| `rowspan` | Expande linhas           |

### Exemplo

```html
<table width="100%" border="1">
```

---

## Boas Práticas

* Utilizar `<th>` para títulos de colunas.
* Utilizar `<thead>`, `<tbody>` e `<tfoot>` para organização.
* Utilizar tabelas apenas para dados tabulares.
* Evitar utilizar tabelas para construir layouts.
* Priorizar semântica e acessibilidade.

---

## Exemplo Completo

```html
<table border="1" width="100%">

    <caption>Controle de Cursos</caption>

    <thead>
        <tr>
            <th>Aluno</th>
            <th>Curso</th>
            <th>Status</th>
        </tr>
    </thead>

    <tbody>
        <tr>
            <td>Paulo</td>
            <td>HTML</td>
            <td>Aprovado</td>
        </tr>

        <tr>
            <td>Maria</td>
            <td>CSS</td>
            <td>Em andamento</td>
        </tr>
    </tbody>

    <tfoot>
        <tr>
            <td colspan="3">
                Total de alunos: 2
            </td>
        </tr>
    </tfoot>

</table>
```

---

## Resumo das Tags

| Tag         | Descrição                     |
| ----------- | ----------------------------- |
| `<table>`   | Estrutura principal da tabela |
| `<caption>` | Título da tabela              |
| `<thead>`   | Cabeçalho                     |
| `<tbody>`   | Corpo                         |
| `<tfoot>`   | Rodapé                        |
| `<tr>`      | Linha                         |
| `<th>`      | Cabeçalho da coluna           |
| `<td>`      | Célula comum                  |
| `colspan`   | Expande colunas               |
| `rowspan`   | Expande linhas                |
