<?php

/*
=========================================================
EXEMPLO DE UTILIZAÇÃO DO MÉTODO bindValue()
=========================================================

Caso Prático

Imagine um sistema de cadastro de clientes.

Desejamos consultar um cliente informando
seu código.

O método bindValue() associa um VALOR
diretamente ao parâmetro da consulta SQL.

Diferente do bindParam(), o valor é copiado
imediatamente no momento da chamada.

Mesmo que a variável seja alterada depois,
o valor enviado ao banco continuará sendo
o valor originalmente informado.

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


// Código do cliente que desejamos consultar
$codigoCliente = 2;


/*
---------------------------------------------------------
CONSULTA SQL

":codigo" representa um parâmetro nomeado.

---------------------------------------------------------
*/

$sql = "

    SELECT
        nome,
        cpf,
        telefone

    FROM Cliente

    WHERE codigo_cliente = :codigo

";


// Prepara a consulta
$stmt = $dsn->prepare($sql);


/*
---------------------------------------------------------
ASSOCIANDO O VALOR

bindValue()

Neste momento o valor da variável é copiado.

---------------------------------------------------------
*/

$stmt->bindValue(":codigo", $codigoCliente, PDO::PARAM_INT);


/*
---------------------------------------------------------
ALTERANDO A VARIÁVEL

Mesmo alterando o valor da variável,
o bindValue() continuará utilizando
o valor original (2).

---------------------------------------------------------
*/

$codigoCliente = 10;


/*
---------------------------------------------------------
EXECUTANDO A CONSULTA

A consulta continuará procurando
o cliente de código 2.

---------------------------------------------------------
*/

$stmt->execute();


/*
---------------------------------------------------------
RECUPERANDO O RESULTADO

fetch()

Retorna apenas um registro.

---------------------------------------------------------
*/

$cliente = $stmt->fetch();


if ($cliente) {

    echo "<h3>Cliente encontrado!</h3>";

    echo "<b>Nome:</b> " . $cliente["nome"] . "<br>";

    echo "<b>CPF:</b> " . $cliente["cpf"] . "<br>";

    echo "<b>Telefone:</b> " . $cliente["telefone"] . "<br>";

} else {

    echo "Cliente não encontrado.";

}

?>
