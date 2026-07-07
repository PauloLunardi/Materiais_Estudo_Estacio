# Introdução ao PHP e HTML

## Sobre o PHP

O PHP (Hypertext Preprocessor) é uma linguagem de programação amplamente utilizada para o desenvolvimento de páginas web dinâmicas. Sua principal característica é a execução no servidor, permitindo processar dados, acessar bancos de dados, validar formulários e gerar conteúdo HTML de forma dinâmica antes que a página seja enviada ao navegador.

O PHP pode ser incorporado diretamente em arquivos HTML, tornando-se uma ferramenta poderosa para a criação de aplicações web interativas.
---

# Principais Conceitos

## 1. Estrutura Básica de um Script PHP

Todo código PHP deve ser iniciado com a tag:

```php
<?php
```

E pode ser finalizado com:

```php
?>
```

Exemplo:

```php
<?php
echo "Olá Mundo!";
?>
```
---

## 2. Integração entre PHP e HTML

Uma das maiores vantagens do PHP é sua integração nativa com HTML.

Exemplo:

```php
<!DOCTYPE html>
<html>
<head>
    <title>Exemplo PHP</title>
</head>
<body>

<h1>Minha Página</h1>

<?php
echo "<p>Conteúdo gerado pelo PHP.</p>";
?>

</body>
</html>
```
---

## 3. Comentários

Comentários são utilizados para documentar o código e facilitar sua manutenção.

### Comentário de uma linha

```php
// Este é um comentário
```

### Comentário de múltiplas linhas

```php
/*
Comentário
de várias linhas
*/
```
---

## 4. Variáveis

As variáveis em PHP são definidas utilizando o símbolo `$`.

Exemplo:

```php
$nome = "Paulo";
$idade = 30;
```

Características:

- Não é necessário informar o tipo da variável.
- PHP é uma linguagem fracamente tipada.
- Os nomes são sensíveis a letras maiúsculas e minúsculas (case-sensitive).

Exemplo:

```php
$nome = "João";
$Nome = "Maria";
```

As duas variáveis são diferentes.
---

## 5. Regras para Nomes de Variáveis

Um nome de variável válido deve:

- Começar com letra ou underscore (_).
- Pode conter números após o primeiro caractere.
- Não pode conter espaços.
- Diferencia letras maiúsculas de minúsculas.

Exemplos válidos:

```php
$nome
$_usuario
$idade1
$valorTotal
```
---

## 6. Atribuição de Valores

A atribuição é feita utilizando o operador `=`.

Exemplo:

```php
$nome = "Paulo";
$idade = 25;
$altura = 1.75;
$ativo = true;
```

Tipos comuns:

| Tipo | Exemplo |
|--------|----------|
| String | "Texto" |
| Integer | 10 |
| Float | 10.5 |
| Boolean | true / false |
---

## 7. Exibição de Dados

O comando mais utilizado para exibir informações é o `echo`.

Exemplo:

```php
<?php
$nome = "Paulo";

echo "Bem-vindo, $nome!";
?>
```

Saída:

```text
Bem-vindo, Paulo!
```
---

## 8. Boas Práticas

- Sempre inicialize variáveis antes de utilizá-las.
- Utilize nomes de variáveis descritivos.
- Mantenha um padrão de nomenclatura em todo o projeto.
- Utilize comentários para explicar trechos importantes do código.
- Organize o código PHP e HTML para facilitar a manutenção.
---

# Principais Aplicações do PHP

O PHP é amplamente utilizado para:

- Desenvolvimento de sites dinâmicos.
- Sistemas de cadastro e login.
- Processamento de formulários.
- Integração com bancos de dados.
- APIs REST.
- Sistemas corporativos.
- Plataformas de e-commerce.
- Portais de conteúdo e blogs.
---

## Entrada de Dados e Requisições HTTP

### O que são Requisições HTTP?

Em aplicações web dinâmicas, é comum a utilização de formulários para coletar informações dos usuários. Quando um formulário é enviado, os dados são transmitidos ao servidor por meio de uma requisição HTTP.

O servidor recebe esses dados, realiza o processamento necessário e retorna uma resposta ao navegador, normalmente na forma de uma página HTML.

Cada informação enviada pode ser entendida como uma variável contendo:

- Nome
- Valor

Exemplo:

```text
nome=Paulo
idade=25
```
---

## Métodos de Requisição HTTP

O protocolo HTTP define diferentes métodos para comunicação entre clientes e servidores.

Os principais métodos são:

| Método | Função |
|----------|----------|
| GET | Solicitar dados de um recurso |
| POST | Enviar dados ao servidor |
| PUT | Atualizar recursos |
| DELETE | Remover recursos |
| PATCH | Atualizar parcialmente recursos |
| HEAD | Obter apenas cabeçalhos |
| OPTIONS | Consultar métodos suportados |
| TRACE | Diagnóstico de requisições |
| CONNECT | Estabelecer conexão de túnel |

Em aplicações PHP, os métodos mais utilizados são **GET** e **POST**.
---

## Método GET

O método GET é utilizado para solicitar informações ao servidor.

Os dados enviados ficam visíveis na URL através da chamada **Query String**.

Exemplo:

```text
https://site.com/script.php?nome=Paulo&idade=25
```

Nesse caso:

```text
nome = Paulo
idade = 25
```

#### Vantagens

- Fácil compartilhamento de URLs.
- Ideal para pesquisas e filtros.
- Pode ser armazenado em favoritos do navegador.

#### Desvantagens

- Dados ficam visíveis na URL.
- Não recomendado para informações sensíveis.
- Possui limite de tamanho dependendo do navegador e servidor.
---

## Método POST

O método POST é utilizado para enviar dados ao servidor para criação ou atualização de informações.

Diferentemente do GET, os dados são enviados no corpo da requisição.

Exemplo:

```html
<form method="POST" action="processar.php">
    <input type="text" name="nome">
    <button type="submit">Enviar</button>
</form>
```

#### Vantagens

- Dados não aparecem na URL.
- Permite envio de grandes volumes de informação.
- Mais adequado para formulários de cadastro e login.

#### Observação

Embora os dados não fiquem visíveis na barra de endereços, eles ainda podem ser visualizados por meio das ferramentas de desenvolvimento do navegador ou durante a análise da requisição.
---

## Superglobais do PHP

O PHP disponibiliza diversas variáveis predefinidas chamadas **Superglobais**.

Elas podem ser acessadas em qualquer parte do script.

As principais relacionadas às requisições HTTP são:

- `$_GET`
- `$_POST`
- `$_REQUEST`

---

## Variável $_GET

A variável `$_GET` é um array associativo que armazena os dados recebidos através do método GET.

Exemplo de URL:

```text
script.php?nome=Paulo
```

Código PHP:

```php
<?php

echo $_GET["nome"];

?>
```

Saída:

```text
Paulo
```
---

## Variável $_POST

A variável `$_POST` é um array associativo utilizado para acessar dados enviados por formulários que utilizam o método POST.

Exemplo:

```html
<form method="POST">
    <input type="text" name="nome">
</form>
```

Código PHP:

```php
<?php

echo $_POST["nome"];

?>
```
---

## Variável $_REQUEST

A variável `$_REQUEST` funciona como uma solução genérica para captura de dados.

Ela pode acessar informações provenientes de:

- `$_GET`
- `$_POST`
- `$_COOKIE`

Exemplo:

```php
<?php

echo $_REQUEST["nome"];

?>
```

Embora seja prática, muitos desenvolvedores preferem utilizar explicitamente `$_GET` ou `$_POST` para deixar o código mais claro e seguro.
---

## Exemplo Completo

### Formulário HTML

```html
<form method="POST" action="processar.php">
    <label>Nome:</label>
    <input type="text" name="nome">

    <button type="submit">
        Enviar
    </button>
</form>
```

### Arquivo processar.php

```php
<?php

$nome = $_POST["nome"];

echo "Olá, " . $nome;

?>
```

Resultado:

```text
Olá, Paulo
```
---

## Boas Práticas para Receber Dados

- Sempre valide os dados recebidos.
- Nunca confie diretamente em entradas do usuário.
- Utilize `isset()` para verificar se uma variável foi enviada.
- Faça tratamento contra ataques como SQL Injection e XSS.
- Prefira utilizar `$_GET` e `$_POST` explicitamente quando possível.
- Evite transmitir informações sensíveis por GET.

Exemplo seguro:

```php
<?php

if (isset($_POST["nome"])) {
    $nome = $_POST["nome"];
    echo "Olá, " . htmlspecialchars($nome);
}

?>
```
---

## Resumo

As requisições HTTP são a base da comunicação entre navegadores e servidores. Em PHP, os dados enviados pelos usuários podem ser acessados por meio das superglobais `$_GET`, `$_POST` e `$_REQUEST`, permitindo criar aplicações dinâmicas, formulários, sistemas de login, cadastros e diversas outras funcionalidades web.
---

# Conclusão

O PHP continua sendo uma das linguagens mais utilizadas no desenvolvimento web. Sua facilidade de integração com HTML, simplicidade de sintaxe e ampla comunidade tornam a linguagem uma excelente opção para iniciantes e profissionais que desejam criar aplicações web dinâmicas e robustas.
