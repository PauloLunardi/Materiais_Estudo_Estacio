<?php

/*
=========================================================
EXEMPLO DE UTILIZAÇÃO DO MÉTODO fetchObject()
=========================================================

Caso Prático

Imagine um sistema de busca de produtos.

Desejamos buscar as informações de um produto específico
na tabela Produto através do seu código (ID).

Em vez de receber os dados como uma lista comum (array),
queremos que o PDO transforme essa linha do banco
diretamente em um Objeto em PHP.

Para isso utilizamos o método fetchObject().

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


// ID do produto que desejamos buscar
$produtoId = 10;


/*
---------------------------------------------------------
CONSULTA SQL

Busca o produto filtrando pelo ID informado.

Utilizamos parâmetros nomeados (:id) para garantir
a segurança da consulta contra SQL Injection.

---------------------------------------------------------
*/

$sql = "

    SELECT id, nome, preco, estoque
    FROM Produto
    WHERE id = :id

";


// Prepara a consulta
$stmt = $dsn->prepare($sql);


// Associa o valor ao parâmetro
$stmt->bindValue(":id", $produtoId);


// Executa a consulta SELECT
$stmt->execute();


/*
---------------------------------------------------------
OBTENDO O RESULTADO COMO OBJETO

fetchObject()

Retorna a próxima linha do resultado como um objeto.
As colunas do banco viram propriedades desse objeto.

Se nenhum resultado for encontrado, ele retorna false.

---------------------------------------------------------
*/

$produto = $stmt->fetchObject();


// Exibe o resultado mapeado

if ($produto) {

    echo "<h3>Produto Encontrado!</h3>";

    // Acessamos os dados usando a seta (->) de objeto
    echo "Código: " . $produto->id . "<br>";
    echo "Nome: "   . $produto->nome . "<br>";
    echo "Preço: R$ " . number_format($produto->preco, 2, ',', '.') . "<br>";
    echo "Estoque: " . $produto->estoque . " unidades<br>";

} else {

    echo "<h3>Produto não encontrado.</h3>";

}

?>

