<?php

/*
=========================================================
EXEMPLO DE UTILIZAÇÃO DO MÉTODO query()
=========================================================

Caso Prático

Imagine um sistema de cadastro de clientes.

Desejamos consultar todos os clientes cadastrados,
exibindo:

- Nome
- CPF
- Telefone

O método query() é utilizado para executar
consultas SQL que retornam registros,
como o comando SELECT.

O resultado da consulta é armazenado em um
objeto PDOStatement.

=========================================================
*/


// Comando SQL que será executado
$instrucaoSQL = "

    SELECT nome, cpf, telefone

    FROM Cliente

";


/*
    A variável $dsn representa a conexão
    com o banco de dados criada pelo PDO.

    Exemplo:

    $dsn = new PDO(...);
*/


// Executa a consulta SQL
$resultSet = $dsn->query($instrucaoSQL);


/*
=========================================================
PERCORRENDO O RESULTADO

fetch()

Retorna uma linha da consulta por vez.

Enquanto houver registros,
o laço while continuará executando.

=========================================================
*/

while ($row = $resultSet->fetch()) {

    /*
        $row é um array associativo.

        Cada índice corresponde ao nome
        da coluna retornada pelo SELECT.
    */

    echo "Nome: " . $row["nome"] . "<br>";

    echo "CPF: " . $row["cpf"] . "<br>";

    echo "Telefone: " . $row["telefone"] . "<br>";

    echo "<hr>";

}

?>
