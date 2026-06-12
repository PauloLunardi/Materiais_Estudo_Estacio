## 📋 Listas em HTML

As listas permitem organizar informações de forma estruturada e podem ser de três tipos.

| Tipo         | Tag Container | Tag Item | Descrição                      |
| ------------ | ------------- | -------- | ------------------------------ |
| Ordenada     | `<ol>`        | `<li>`   | Lista numerada ou alfabética   |
| Não Ordenada | `<ul>`        | `<li>`   | Lista com marcadores (bullets) |
| Definição    | `<dl>`        | `<dt>`   | Lista de termos e definições   |

### Exemplo

```html
<ol>
    <li>HTML</li>
    <li>CSS</li>
    <li>JavaScript</li>
</ol>
```

### Observações

* É possível criar listas dentro de listas (listas aninhadas).
* A aparência visual dos marcadores pode ser alterada com CSS.

---

## 📊 Tabelas em HTML

As tabelas são utilizadas para representar dados tabulares organizados em linhas e colunas.

### Estrutura Básica

| Tag       | Função                        |
| --------- | ----------------------------- |
| `<table>` | Container principal da tabela |
| `<tr>`    | Linha da tabela               |
| `<td>`    | Célula comum                  |
| `<th>`    | Cabeçalho da coluna           |
| `<thead>` | Cabeçalho da tabela           |
| `<tfoot>` | Rodapé da tabela              |

### Exemplo

```html
<table>
    <thead>
        <tr>
            <th>Nome</th>
            <th>Curso</th>
        </tr>
    </thead>

    <tr>
        <td>Paulo</td>
        <td>HTML</td>
    </tr>
</table>
```

### Mesclagem de Células

| Atributo  | Função          |
| --------- | --------------- |
| `colspan` | Expande colunas |
| `rowspan` | Expande linhas  |

### Boas Práticas

* Utilizar tabelas apenas para dados tabulares.
* Evitar usar tabelas para construir o layout da página.
* Priorizar a semântica com `<thead>`, `<tfoot>` e `<th>`.

---

## 🎥 Mídias em HTML

O HTML5 trouxe suporte nativo para vídeos e áudios através das tags semânticas de mídia.

| Tag       | Função             |
| --------- | ------------------ |
| `<video>` | Inserção de vídeos |
| `<audio>` | Inserção de áudios |

### Exemplo

```html
<video src="video.mp4" controls></video>

<audio src="audio.mp3" controls></audio>
```

### Principais Atributos

| Atributo   | Função                        |
| ---------- | ----------------------------- |
| `src`      | Caminho do arquivo            |
| `controls` | Exibe controles de reprodução |
| `autoplay` | Inicia automaticamente        |
| `loop`     | Repete continuamente          |

### Benefícios do HTML5

* Reprodução nativa de áudio e vídeo.
* Não depende de plugins externos.
* Integração com JavaScript através dos Media Events.
* Melhor compatibilidade com navegadores modernos.

---

## 🚀 Resumo Geral

Além das tags básicas, o HTML oferece recursos para:

* Organizar informações com **listas** (`<ol>`, `<ul>`, `<dl>`).
* Exibir dados estruturados em **tabelas** (`<table>`, `<tr>`, `<td>`, `<th>`).
* Incorporar **mídias** como vídeos e áudios (`<video>`, `<audio>`).

Esses elementos ampliam as possibilidades de criação de páginas web mais organizadas, acessíveis e interativas.
