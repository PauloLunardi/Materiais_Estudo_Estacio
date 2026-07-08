<?php

/*
=========================================================
EXEMPLO DE UTILIZAÇÃO DO MÉTODO fetch()
=========================================================

Caso Prático

Imagine um sistema de cadastro de clientes.

Desejamos consultar todos os clientes cadastrados.

O método fetch() retorna apenas UMA linha da consulta
por vez.

Cada vez que o método é chamado, ele avança para
o próximo registro do banco de dados.

=========================================================
*/


// Comando SQL
$sql = "SELECT nome, cpf, telefone FROM Cliente";


/*
    A variável $dsn representa a conexão
    com o banco de dados utilizando PDO.
*/

// Executa a consulta
$resultSet = $dsn->query($sql);


/*
=========================================================
LENDO OS REGISTROS COM fetch()

Enquanto houver registros na consulta,
o método fetch() retornará uma linha.

Quando não houver mais registros,
fetch() retorna FALSE e o laço termina.

=========================================================
*/

while ($cliente = $resultSet->fetch()) {

    /*
        A variável $cliente é um array associativo.

        Cada índice corresponde ao nome
        de uma coluna retornada pelo SELECT.
    */

    echo "<b>Nome:</b> " . $cliente["nome"] . "<br>";

    echo "<b>CPF:</b> " . $cliente["cpf"] . "<br>";

    echo "<b>Telefone:</b> " . $cliente["telefone"] . "<br>";

    echo "<hr>";

}

?>
