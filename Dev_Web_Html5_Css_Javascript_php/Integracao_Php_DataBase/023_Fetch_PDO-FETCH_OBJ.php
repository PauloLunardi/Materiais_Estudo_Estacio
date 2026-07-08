<?php

/*
=========================================================
EXEMPLO DE UTILIZAÇÃO DA CONSTANTE PDO::FETCH_OBJ
=========================================================

Caso Prático

Imagine um sistema de controle de faturamento.

Desejamos buscar os dados de uma fatura específica
na tabela Fatura através do seu número de controle (ID).

Queremos receber os dados organizados em um Objeto Anônimo
(stdClass), permitindo acessar os valores das colunas do
banco de dados de forma direta, utilizando a sintaxe de seta.

Para isso utilizamos o método fetch(PDO::FETCH_OBJ).

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


// ID da fatura que desejamos buscar
$faturaId = 1045;


/*
---------------------------------------------------------
CONSULTA SQL

Busca a fatura filtrando pelo ID informado.

Utilizamos parâmetros nomeados (:id) para garantir
a segurança da consulta contra SQL Injection.

---------------------------------------------------------
*/

$sql = "

    SELECT id, valor, data_vencimento, status
    FROM Fatura
    WHERE id = :id

";


// Prepara a consulta
$stmt = $dsn->prepare($sql);


// Associa o valor ao parâmetro
$stmt->bindValue(":id", $faturaId);


// Executa a consulta SELECT
$stmt->execute();


/*
---------------------------------------------------------
OBTENDO O RESULTADO COMO OBJETO ANÔNIMO

fetch(PDO::FETCH_OBJ)

Retorna a próxima linha do resultado como um objeto comum (stdClass).
As colunas retornadas pelo banco viram propriedades desse objeto.

Se nenhum resultado for encontrado, ele retorna false.

---------------------------------------------------------
*/

$fatura = $stmt->fetch(PDO::FETCH_OBJ);


// Exibe o resultado mapeado

if ($fatura) {

    echo "<h3>Fatura Encontrada!</h3>";

    // Acessamos os dados usando a seta (->) de objeto
    echo "Fatura Nº: " . $fatura->id . "<br>";
    echo "Valor: R$ "   . number_format($fatura->valor, 2, ',', '.') . "<br>";
    echo "Vencimento: " . date("d/m/Y", strtotime($fatura->data_vencimento)) . "<br>";
    echo "Status: "     . $fatura->status . "<br>";

} else {

    echo "<h3>Fatura não encontrada.</h3>";

}

?>
