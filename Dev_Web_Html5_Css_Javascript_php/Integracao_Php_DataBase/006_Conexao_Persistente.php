<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <title>Conexão Persistente com PDO</title>
</head>
<body>

<h2>Exemplo de Conexão Persistente</h2>

<?php

/*
=========================================================

CASO PRÁTICO

Imagine um sistema de uma loja virtual.

Centenas de clientes acessam o sistema ao mesmo
tempo para consultar produtos, realizar compras
e acompanhar pedidos.

Se uma nova conexão com o banco fosse criada
a cada página acessada, o servidor gastaria
mais tempo e recursos.

Para reduzir esse custo, podemos utilizar
uma conexão persistente.

Ela permite que o PHP reutilize conexões
já existentes, quando possível.

=========================================================
*/


/* =====================================================
   Dados da conexão
   ===================================================== */

$host = "127.0.0.1";     // Servidor do banco
$porta = "3306";         // Porta padrão do MySQL
$banco = "empresa";      // Nome do banco de dados
$usuario = "root";       // Usuário
$senha = "";             // Senha


try {

    /*
    =====================================================

    Criando uma conexão persistente.

    O quarto parâmetro do construtor PDO recebe
    um array contendo configurações adicionais.

    PDO::ATTR_PERSISTENT => true

    Solicita ao PHP que reutilize conexões já
    abertas, sempre que possível.

    =====================================================
    */

    $pdo = new PDO(

        "mysql:host=$host;port=$porta;dbname=$banco;charset=utf8",

        $usuario,

        $senha,

        array(
            PDO::ATTR_PERSISTENT => true
        )

    );


    /*
        Configura o PDO para lançar exceções
        caso ocorra algum erro.
    */

    $pdo->setAttribute(
        PDO::ATTR_ERRMODE,
        PDO::ERRMODE_EXCEPTION
    );


    echo "✅ Conexão persistente criada com sucesso.<br><br>";


    /*
    =====================================================

    A partir daqui a aplicação funciona
    exatamente igual a uma conexão comum.

    Podemos executar:

    - SELECT
    - INSERT
    - UPDATE
    - DELETE

    =====================================================
    */

    echo "Executando consultas no banco...<br>";
    echo "Consulta executada com sucesso.<br><br>";


    /*
    =====================================================

    Liberando o objeto PDO.

    Observe que estamos destruindo apenas
    o objeto armazenado na variável.

    Em conexões persistentes, o servidor
    poderá manter essa conexão aberta para
    reutilização por futuras requisições.

    Ou seja:

    Conexão comum:
        Fecha totalmente.

    Conexão persistente:
        Pode permanecer aberta para ser
        reutilizada posteriormente.

    =====================================================
    */

    $pdo = null;

    echo "Objeto PDO liberado.<br>";
    echo "A conexão poderá ser reutilizada pelo servidor.";

}


/*
    Caso ocorra algum erro durante a conexão,
    o programa será desviado para este bloco.
*/

catch (PDOException $erro) {

    echo "Erro ao conectar ao banco de dados.<br>";

    echo $erro->getMessage();

}

?>

</body>
</html>
