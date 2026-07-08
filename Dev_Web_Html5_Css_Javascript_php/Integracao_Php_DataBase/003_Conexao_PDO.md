# Conexão com Banco de Dados utilizando PDO

## Introdução

Antes que uma aplicação PHP possa consultar, inserir, atualizar ou excluir informações de um banco de dados, é necessário estabelecer uma conexão com o **Sistema Gerenciador de Banco de Dados (SGBD)**.

No PHP, a forma mais recomendada para realizar essa conexão é utilizando o **PDO (PHP Data Objects)**.

O PDO é uma extensão nativa do PHP que fornece uma interface única para acessar diferentes bancos de dados, tornando o código mais organizado, seguro e portável.

---

# O que é PDO?

PDO (**PHP Data Objects**) é uma classe responsável por criar conexões entre aplicações PHP e diversos bancos de dados relacionais.

Entre os bancos suportados estão:

- MySQL
- PostgreSQL
- SQLite
- Oracle
- Microsoft SQL Server

Uma das maiores vantagens do PDO é que, na maioria dos casos, basta alterar a string de conexão para utilizar outro banco de dados, sem modificar grande parte da aplicação.

---

# Estrutura da Conexão

Para criar uma conexão utilizando PDO são necessárias quatro informações básicas:

- Servidor (Host)
- Nome do banco de dados
- Usuário
- Senha

A conexão é criada através do construtor da classe `PDO`.

Sintaxe geral:

```php
$pdo = new PDO($dsn, $usuario, $senha);
```

Onde:

- **$dsn** → String de conexão (Data Source Name).
- **$usuario** → Usuário do banco.
- **$senha** → Senha do banco.

---

# Exemplo de Conexão com MySQL

```php
<?php

$host = "localhost";
$banco = "empresa";
$usuario = "root";
$senha = "";

try {

    $pdo = new PDO(
        "mysql:host=$host;dbname=$banco;charset=utf8",
        $usuario,
        $senha
    );

    echo "Conexão realizada com sucesso!";

} catch (PDOException $erro) {

    echo "Erro na conexão: " . $erro->getMessage();

}

?>
```

### Explicação

- `mysql:` informa que o banco utilizado é o MySQL.
- `host` indica o servidor onde o banco está localizado.
- `dbname` define o banco de dados.
- `charset=utf8` configura a codificação dos caracteres.
- O bloco `try...catch` captura possíveis erros durante a conexão.

---

# Exemplo de Conexão com PostgreSQL

```php
<?php

$host = "localhost";
$porta = "5432";
$banco = "empresa";
$usuario = "postgres";
$senha = "123456";

try {

    $pdo = new PDO(
        "pgsql:host=$host;port=$porta;dbname=$banco",
        $usuario,
        $senha
    );

    echo "Conectado ao PostgreSQL com sucesso!";

} catch (PDOException $erro) {

    echo "Erro: " . $erro->getMessage();

}

?>
```

Nesse exemplo:

- `pgsql:` indica que o banco utilizado é o PostgreSQL.
- Também é necessário informar a porta de conexão (geralmente **5432**).

---

# Tratamento de Erros

Sempre que possível, utilize `try...catch` para tratar erros de conexão.

```php
try {

    $pdo = new PDO(...);

} catch (PDOException $erro) {

    echo $erro->getMessage();

}
```

Dessa forma, caso ocorra algum problema, a aplicação poderá informar o erro sem ser encerrada abruptamente.

---

# Boas Práticas

- Utilize sempre **PDO** em novos projetos.
- Nunca deixe usuário e senha expostos em páginas públicas.
- Armazene as credenciais em arquivos de configuração.
- Utilize `charset=utf8` para evitar problemas de codificação.
- Sempre trate exceções utilizando `try...catch`.

---

# Vantagens do PDO

- Compatível com diversos bancos de dados.
- Código reutilizável e organizado.
- Suporte a **Prepared Statements** (consultas preparadas).
- Maior proteção contra ataques de **SQL Injection**.
- Melhor manutenção e portabilidade entre diferentes SGBDs.

---

# Resumo

A conexão com um banco de dados é o primeiro passo para que uma aplicação PHP possa manipular informações armazenadas em um SGBD. A utilização do **PDO** é considerada a melhor prática por oferecer compatibilidade com diversos bancos de dados, suporte a consultas preparadas e um mecanismo eficiente para tratamento de erros, tornando as aplicações mais seguras, organizadas e fáceis de manter.
