<?php

/*
=========================================================
EXEMPLO DE UTILIZAÇÃO DO MÉTODO rowCount()
=========================================================

Caso Prático

Imagine um sistema de cadastro de clientes.

Desejamos atualizar o telefone de um cliente.

Após executar o UPDATE, queremos saber
quantos registros foram alterados.

Para isso utilizamos o método rowCount().

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


// Dados utilizados na atualização
$codigoCliente = 1;
$novoTelefone = "(11) 99999-9999";


/*
---------------------------------------------------------
CONSULTA SQL

Atualiza o telefone do cliente informado.

---------------------------------------------------------
*/

$sql = "

    UPDATE Cliente

    SET telefone = :telefone

    WHERE codigo_cliente = :codigo

";


// Prepara a consulta
$stmt = $dsn->prepare($sql);


// Associa os valores aos parâmetros
$stmt->bindValue(":telefone", $novoTelefone);
$stmt->bindValue(":codigo", $codigoCliente);


// Executa a atualização
$stmt->execute();


/*
---------------------------------------------------------
VERIFICANDO O RESULTADO

rowCount()

Retorna a quantidade de linhas afetadas
pela instrução SQL.

---------------------------------------------------------
*/

$linhasAfetadas = $stmt->rowCount();


// Exibe o resultado

echo "<h3>Resultado da Atualização</h3>";

echo "Quantidade de registros alterados: "
    . $linhasAfetadas;

?>
