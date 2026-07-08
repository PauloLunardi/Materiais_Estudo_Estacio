<?php

// Definindo os parâmetros de conexão
define('HOST', '127.0.0.1');      // Local onde está o banco (IP ou hostname)
define('PORT', '5432');           // Porta de acesso ao banco
define('DBNAME', 'test');         // Nome do banco de dados
define('USER', 'user');           // Usuário de acesso
define('PASSWORD', 'psswd');      // Senha de acesso

// try...catch para tratamento de exceções
try {

    // Estabelecendo a conexão com o PostgreSQL
    $dsn = new PDO(
        "pgsql:host=" . HOST .
        ";port=" . PORT .
        ";dbname=" . DBNAME .
        ";user=" . USER .
        ";password=" . PASSWORD
    );

    echo "Conexão realizada com sucesso!";

} catch (PDOException $e) {

    echo "A conexão falhou e retornou a seguinte mensagem de erro: "
        . $e->getMessage();

}

// Encerrando a conexão
$dsn = null;

?>
