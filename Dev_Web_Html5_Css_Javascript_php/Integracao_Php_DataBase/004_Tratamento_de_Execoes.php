<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <title>Conexão PDO</title>
</head>
<body>

<h2>Exemplo de Conexão com PDO</h2>

<?php

/*
=========================================================
CONFIGURAÇÕES DE CONEXÃO
=========================================================
*/

// Servidor onde o banco está instalado
define("HOST", "127.0.0.1");

// Porta do banco de dados
define("PORT", "3306");

// Nome do banco
define("DBNAME", "test");

// Usuário do banco
define("USER", "root");

// Senha do banco
define("PASSWORD", "");

try {

    /*
    =========================================================
    CONEXÃO COM MYSQL
    =========================================================

    DSN:
    mysql:host=SERVIDOR;port=PORTA;dbname=BANCO;charset=utf8
    */

    $pdoMysql = new PDO(
        "mysql:host=" . HOST .
        ";port=" . PORT .
        ";dbname=" . DBNAME .
        ";charset=utf8",
        USER,
        PASSWORD
    );

    echo "<p>✅ Conectado ao MySQL com sucesso!</p>";

}
catch (PDOException $e) {

    echo "<p>Erro ao conectar no MySQL:</p>";
    echo $e->getMessage();

}

echo "<hr>";

/*
=========================================================
CONFIGURAÇÕES DO POSTGRESQL
=========================================================
*/

// Porta padrão do PostgreSQL
define("PG_PORT", "5432");

try {

    /*
    =========================================================
    CONEXÃO COM POSTGRESQL
    =========================================================

    DSN:
    pgsql:host=SERVIDOR;port=PORTA;dbname=BANCO
    */

    $pdoPostgres = new PDO(
        "pgsql:host=" . HOST .
        ";port=" . PG_PORT .
        ";dbname=" . DBNAME,
        USER,
        PASSWORD
    );

    echo "<p>✅ Conectado ao PostgreSQL com sucesso!</p>";

}
catch (PDOException $e) {

    echo "<p>Erro ao conectar no PostgreSQL:</p>";
    echo $e->getMessage();

}

?>

</body>
</html>
