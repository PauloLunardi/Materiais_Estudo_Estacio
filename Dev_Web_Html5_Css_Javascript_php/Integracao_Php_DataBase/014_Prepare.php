<?php

/*
=========================================================
EXEMPLO DE UTILIZAÇÃO DO MÉTODO prepare()
=========================================================

Caso Prático

Imagine um sistema de cadastro de clientes.

Desejamos localizar um cliente informando
seu código.

Diferente do método query(), o método prepare()
permite criar consultas parametrizadas,
aumentando a segurança da aplicação contra
SQL Injection.

Fluxo:

1) Preparar a instrução SQL.
2) Associar os parâmetros.
3) Executar a consulta.
4) Ler o resultado.

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
$codigoCliente = 1;


/*
---------------------------------------------------------
PREPARANDO A CONSULTA

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


// Prepara a instrução SQL
$stmt = $dsn->prepare($sql);


/*
---------------------------------------------------------
ASSOCIANDO O PARÂMETRO

bindParam()

Associa a variável $codigoCliente ao parâmetro
:codigo presente na consulta.

Neste exemplo utilizamos bindValue() para deixar
o código mais simples.

(Em um próximo exemplo veremos bindParam().)

---------------------------------------------------------
*/

$stmt->bindValue(":codigo", $codigoCliente);


/*
---------------------------------------------------------
EXECUTANDO A CONSULTA

Somente agora a instrução SQL é enviada
ao banco de dados.

---------------------------------------------------------
*/

$stmt->execute();


/*
---------------------------------------------------------
RECUPERANDO O RESULTADO

fetch()

Retorna apenas um registro da consulta.

Caso o cliente não exista,
fetch() retornará FALSE.

---------------------------------------------------------
*/

$cliente = $stmt->fetch();


/*
---------------------------------------------------------
VERIFICANDO SE O CLIENTE FOI ENCONTRADO

---------------------------------------------------------
*/

if ($cliente) {

    echo "<h3>Cliente encontrado!</h3>";

    echo "<b>Nome:</b> " . $cliente["nome"] . "<br>";

    echo "<b>CPF:</b> " . $cliente["cpf"] . "<br>";

    echo "<b>Telefone:</b> " . $cliente["telefone"] . "<br>";

} else {

    echo "Cliente não encontrado.";

}

?>
