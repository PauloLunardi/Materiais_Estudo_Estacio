<?php

/*
=========================================================
EXEMPLO DE UTILIZAÇÃO DO MÉTODO exec()
=========================================================

Caso Prático

Imagine um sistema de cadastro de clientes.

Desejamos excluir um cliente cujo código seja igual a 1.

O método exec() é utilizado para executar comandos SQL
que NÃO retornam registros, como:

- INSERT
- UPDATE
- DELETE

Ele retorna a quantidade de linhas afetadas pela operação.

=========================================================
*/


/*
    A variável $dsn representa a conexão PDO
    criada anteriormente.

    Exemplo:

    $dsn = new PDO(...);
*/


// Executa o comando DELETE
$qtdeLinhasAfetadas = $dsn->exec(

    "DELETE FROM Cliente
     WHERE codigo_cliente = 1"

);


/*
    Exibe quantos registros foram removidos.

    Caso exista um cliente com código 1,
    o resultado normalmente será:

    Quantidade de linhas afetadas: 1

    Caso o cliente não exista:

    Quantidade de linhas afetadas: 0
*/

echo "Quantidade de linhas afetadas: "
    . $qtdeLinhasAfetadas;

?>
