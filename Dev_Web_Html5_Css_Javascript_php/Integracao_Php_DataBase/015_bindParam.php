<?php

/*
=========================================================
EXEMPLO DE UTILIZAÇÃO DO MÉTODO bindParam()
=========================================================

Caso Prático

Imagine um sistema de cadastro de clientes.

Desejamos consultar um cliente informando
seu código.

O método bindParam() associa uma VARIÁVEL
a um parâmetro da consulta SQL.

Diferente do bindValue(), o bindParam()
não copia o valor imediatamente.

Ele mantém uma referência para a variável,
utilizando seu valor somente quando execute()
for chamado.

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

Seu valor será informado posteriormente.

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
ASSOCIANDO O PARÂMETRO

bindParam()

Recebe uma variável por referência.

Isso significa que, se o valor da variável
mudar antes do execute(), o novo valor será
utilizado automaticamente.

---------------------------------------------------------
*/

$stmt->bindParam(":codigo", $codigoCliente, PDO::PARAM_INT);


/*
---------------------------------------------------------
EXECUTANDO A CONSULTA

Somente agora o valor da variável é enviado
para o banco de dados.

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
