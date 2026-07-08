<?php

/*
=========================================================
EXEMPLO DE UTILIZAÇÃO DO MÉTODO fetchAll()
=========================================================

Caso Prático

Imagine um sistema de cadastro de clientes.

Desejamos consultar todos os clientes cadastrados
e armazenar o resultado em um único array.

Diferente do método fetch(), que retorna um
registro por vez, o método fetchAll() retorna
todos os registros da consulta de uma única vez.

=========================================================
*/


/*
---------------------------------------------------------
CONEXÃO COM O BANCO

A variável $dsn representa uma conexão PDO
criada anteriormente.

Exemplo:

$dsn = new PDO(...);

---------------------------------------------------------
*/


// Consulta SQL
$sql = "

    SELECT
        nome,
        cpf,
        telefone

    FROM Cliente

";


// Prepara a consulta
$stmt = $dsn->prepare($sql);


// Executa a consulta
$stmt->execute();


/*
---------------------------------------------------------
RECUPERANDO TODOS OS REGISTROS

fetchAll()

Retorna um array contendo todas
as linhas encontradas na consulta.

Cada posição do array representa
um registro da tabela.

---------------------------------------------------------
*/

$clientes = $stmt->fetchAll();


/*
---------------------------------------------------------
PERCORRENDO O ARRAY DE CLIENTES

Cada elemento do array $clientes
é um array associativo contendo
as colunas retornadas pelo SELECT.

---------------------------------------------------------
*/

foreach ($clientes as $cliente) {

    echo "<b>Nome:</b> " . $cliente["nome"] . "<br>";

    echo "<b>CPF:</b> " . $cliente["cpf"] . "<br>";

    echo "<b>Telefone:</b> " . $cliente["telefone"] . "<br>";

    echo "<hr>";

}

?>
