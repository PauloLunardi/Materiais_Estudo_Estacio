<?php

/*
=========================================================
EXEMPLO DE UTILIZAÇÃO DE TRANSAÇÕES (beginTransaction)
=========================================================

Caso Prático

Imagine um sistema de vendas.

Desejamos cadastrar um novo Pedido
e os Itens desse pedido ao mesmo tempo.

Se o cadastro do Pedido funcionar, mas o cadastro
dos Itens falhar, o banco ficará com dados incompletos.

Para evitar isso, usamos Transações.

Se tudo der certo, salvamos tudo (COMMIT).
Se algo falhar, cancelamos tudo (ROLLBACK).

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


// Dados do pedido e itens
$clienteId = 5;
$total     = 150.00;
$itens     = [
    ['produto_id' => 10, 'qtd' => 2, 'preco' => 50.00],
    ['produto_id' => 22, 'qtd' => 1, 'preco' => 50.00]
];


/*
---------------------------------------------------------
INÍCIO DA TRANSAÇÃO

beginTransaction()

Desativa o modo de salvamento automático (autocommit).
A partir daqui, nenhuma alteração é definitiva
até que o COMMIT seja chamado.

---------------------------------------------------------
*/

try {

    // Inicia a transação com o banco
    $dsn->beginTransaction();


    /*
    ---------------------------------------------------------
    PASSO 1: INSERIR O PEDIDO
    ---------------------------------------------------------
    */

    $sqlPedido = "
        INSERT INTO Pedido 
            (cliente_id, total, data_pedido)
        VALUES 
            (:cliente_id, :total, NOW())
    ";

    $stmtPedido = $dsn->prepare($sqlPedido);
    $stmtPedido->bindValue(":cliente_id", $clienteId);
    $stmtPedido->bindValue(":total", $total);
    $stmtPedido->execute();

    // Recupera o ID do pedido para usar nos itens
    $pedidoId = $dsn->lastInsertId();


    /*
    ---------------------------------------------------------
    PASSO 2: INSERIR OS ITENS DO PEDIDO
    ---------------------------------------------------------
    */

    $sqlItem = "
        INSERT INTO ItemPedido 
            (pedido_id, produto_id, quantidade, preco_unitario)
        VALUES 
            (:pedido_id, :produto_id, :quantidade, :preco)
    ";

    $stmtItem = $dsn->prepare($sqlItem);

    // Percorre a lista de itens para inserir um por um
    foreach ($itens as $item) {
        $stmtItem->bindValue(":pedido_id", $pedidoId);
        $stmtItem->bindValue(":produto_id", $item['produto_id']);
        $stmtItem->bindValue(":quantidade", $item['qtd']);
        $stmtItem->bindValue(":preco", $item['preco']);
        $stmtItem->execute();
    }


    /*
    ---------------------------------------------------------
    CONFIRMAÇÃO DOS DADOS

    commit()

    Se o código chegou até aqui sem erros,
    salva permanentemente todas as operações no banco.

    ---------------------------------------------------------
    */

    $dsn->commit();

    echo "<h3>Pedido e itens cadastrados com sucesso!</h3>";
    echo "Código do Pedido: " . $pedidoId;


} catch (Exception $e) {

    /*
    ---------------------------------------------------------
    CANCELAMENTO DOS DADOS

    rollBack()

    Se qualquer comando der erro dentro do bloco 'try',
    o banco desfaz tudo o que foi feito desde o beginTransaction().
    Nenhum dado incompleto será salvo.

    ---------------------------------------------------------
    */

    $dsn->rollBack();

    echo "<h3>Erro ao processar o pedido!</h3>";
    echo "O banco de dados desfez as alterações.<br>";
    echo "Detalhes do erro: " . $e->getMessage();

}

?>
