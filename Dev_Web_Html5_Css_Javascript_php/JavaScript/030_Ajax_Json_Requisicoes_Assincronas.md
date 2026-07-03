# Requisições Assíncronas com AJAX e JSON

## Objetivo

Entender o funcionamento das requisições assíncronas em JavaScript utilizando AJAX, além de compreender o papel do JSON na troca de dados entre cliente e servidor.

---

## O que é uma requisição?

No ambiente web, uma requisição ocorre quando o navegador (cliente) solicita informações a um servidor.

Após processar a solicitação, o servidor retorna uma resposta ao cliente.

Exemplos comuns:

- Buscar dados de um usuário.
- Carregar produtos de uma loja virtual.
- Exibir novas publicações em redes sociais.
- Consultar informações em APIs.

---

## Tipos de Requisições

### Requisições Síncronas

Em uma requisição síncrona, o navegador fica bloqueado até que o servidor responda.

Fluxo:

1. Cliente envia a requisição.
2. Cliente aguarda a resposta.
3. Somente após a resposta novas ações podem ser realizadas.

Desvantagens:

- Travamento da interface.
- Experiência ruim para o usuário.
- Menor desempenho.

---

### Requisições Assíncronas

Em uma requisição assíncrona, o navegador continua funcionando enquanto aguarda a resposta do servidor.

Fluxo:

1. Cliente envia a requisição.
2. Usuário continua utilizando a aplicação.
3. Quando a resposta chega, os dados são atualizados.

Vantagens:

- Melhor desempenho.
- Interface mais fluida.
- Possibilidade de várias requisições simultâneas.

---

## Exemplo Prático

As redes sociais utilizam requisições assíncronas constantemente.

Quando o usuário rola a página:

- Novos conteúdos são solicitados ao servidor.
- Apenas os novos dados são carregados.
- Não é necessário recarregar toda a página.

Esse comportamento é possível graças ao AJAX.

---

# AJAX

AJAX significa:

**Asynchronous JavaScript and XML**

Apesar do nome, atualmente o formato mais utilizado não é XML, mas sim JSON.

O AJAX permite que páginas web realizem requisições ao servidor sem recarregar toda a página.

---

## Tecnologias Utilizadas pelo AJAX

O conceito AJAX envolve:

- HTML
- CSS
- JavaScript
- DOM
- XML
- JSON
- XMLHttpRequest

---

## Formatos de Dados Utilizados

Uma requisição AJAX pode receber diferentes tipos de resposta:

- HTML
- Texto simples
- XML
- JSON

Atualmente, JSON é o formato mais utilizado.

---

# XMLHttpRequest

Foi o primeiro recurso padrão utilizado para realizar requisições assíncronas em JavaScript.

---

## Criando uma requisição

```javascript
const xhr = new XMLHttpRequest();
```

---

## Configurando a requisição

```javascript
xhr.open("GET", url, true);
```

Parâmetros:

| Parâmetro | Descrição |
|-----------|------------|
| GET | Método HTTP |
| url | Endereço do recurso |
| true | Requisição assíncrona |

---

## Monitorando o estado da requisição

```javascript
xhr.onreadystatechange = function() {
    console.log(xhr.readyState);
};
```

### Estados do readyState

| Valor | Significado |
|---------|-------------|
| 0 | Não inicializado |
| 1 | Conexão aberta |
| 2 | Requisição recebida |
| 3 | Processando |
| 4 | Concluída |

---

## Exemplo de tratamento

```javascript
xhr.onreadystatechange = function() {

    if(xhr.readyState == 3){
        console.log("Carregando...");
    }

    if(xhr.readyState == 4){
        console.log("Finalizado!");
    }

};
```

---

## Enviando a requisição

```javascript
xhr.send();
```

ou

```javascript
xhr.send(null);
```

---

# Trabalhando com JSON

Muitas APIs retornam dados em formato JSON.

Exemplo:

```json
{
  "status": "success",
  "message": "https://imagem.com/foto.jpg"
}
```

---

## Convertendo JSON para Objeto JavaScript

Quando a resposta chega, ela normalmente vem como texto.

Para transformá-la em objeto JavaScript:

```javascript
const dados = JSON.parse(xhr.responseText);
```

---

## Acessando propriedades

```javascript
console.log(dados.status);
console.log(dados.message);
```

Saída:

```text
success
https://imagem.com/foto.jpg
```

---

# API Fetch

A Fetch API é a forma moderna de realizar requisições assíncronas.

Ela substitui o uso do XMLHttpRequest em muitos cenários.

---

## Principais vantagens

- Sintaxe mais simples.
- Utiliza Promises.
- Código mais legível.
- Melhor integração com tecnologias modernas.

---

## Exemplo básico

```javascript
fetch("https://dog.ceo/api/breeds/image/random")
    .then(response => response.json())
    .then(data => {
        console.log(data);
    });
```

---

## Como funciona?

### 1. Envia a requisição

```javascript
fetch(url)
```

### 2. Recebe a resposta

```javascript
.then(response => response.json())
```

### 3. Processa os dados

```javascript
.then(data => {
    console.log(data);
})
```

---

# JSON

JSON significa:

**JavaScript Object Notation**

É um formato leve para troca de dados entre sistemas.

Apesar do nome, pode ser utilizado por praticamente qualquer linguagem de programação.

---

## Estrutura Básica

```json
{
  "nome": "Paulo",
  "idade": 30
}
```

---

## Características

### Objetos

Utilizam chaves:

```json
{
  "nome": "Paulo"
}
```

---

### Pares Nome/Valor

```json
{
  "nome": "Paulo"
}
```

- nome → chave
- Paulo → valor

---

### Arrays

Utilizam colchetes:

```json
{
  "linguagens": [
    "JavaScript",
    "Python",
    "ABAP"
  ]
}
```

---

## Exemplo Completo

```json
{
  "nome": "Paulo",
  "idade": 30,
  "habilidades": [
    "JavaScript",
    "Python",
    "SAP MM"
  ]
}
```

---

# Resumo

- Requisições permitem comunicação entre cliente e servidor.
- Requisições síncronas bloqueiam a aplicação.
- Requisições assíncronas permitem maior desempenho.
- AJAX possibilita atualizar conteúdos sem recarregar a página.
- XMLHttpRequest foi o primeiro recurso padrão para AJAX.
- Fetch API é a abordagem moderna para requisições assíncronas.
- JSON é atualmente o formato mais utilizado para troca de dados.
- O método `JSON.parse()` converte texto JSON em objetos JavaScript.

---

## Conceitos Importantes

| Conceito | Função |
|-----------|---------|
| AJAX | Realizar requisições assíncronas |
| XMLHttpRequest | Objeto clássico para requisições |
| Fetch API | Forma moderna de realizar requisições |
| JSON | Formato de troca de dados |
| JSON.parse() | Converte JSON em objeto JavaScript |
| readyState | Estado da requisição |
| send() | Envia a requisição |
