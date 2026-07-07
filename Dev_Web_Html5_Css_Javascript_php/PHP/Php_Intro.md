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

# Conclusão

O PHP continua sendo uma das linguagens mais utilizadas no desenvolvimento web. Sua facilidade de integração com HTML, simplicidade de sintaxe e ampla comunidade tornam a linguagem uma excelente opção para iniciantes e profissionais que desejam criar aplicações web dinâmicas e robustas.
