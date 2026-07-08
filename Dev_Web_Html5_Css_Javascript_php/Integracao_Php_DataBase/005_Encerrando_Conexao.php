<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <title>Encerrando uma Conexão PDO</title>
</head>
<body>

<h2>Exemplo de Conexão PDO</h2>

<?php

/*
=========================================================
CASO PRÁTICO

Imagine um sistema de cadastro de funcionários.

Para salvar ou consultar informações, primeiro
precisamos abrir uma conexão com o banco de dados.

Após finalizar as operações, é recomendado
encerrar essa conexão para liberar recursos.
=========================================================
*/


/* Dados do banco de dados */

$host = "127.0.0.1";      // Endereço do servidor
$porta = "3306";          // Porta padrão do MySQL
$banco = "empresa";       // Nome do banco
$usuario = "root";        // Usuário do banco
$senha = "";              // Senha do banco


try {

    /*
        Cria a conexão utilizando PDO.

        mysql:       -> Driver do banco
        host         -> Servidor
        port         -> Porta
        dbname       -> Nome do banco
        charset      -> Codificação UTF-8
    */

    $pdo = new PDO(

        "mysql:host=$host;port=$porta;dbname=$banco;charset=utf8",

        $usuario,

        $senha

    );


    /*
        Faz o PDO lançar exceções caso ocorra
        algum erro durante a conexão ou consultas.
    */

    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);


    echo "✅ Banco conectado com sucesso!<br><br>";


    /*
        Aqui normalmente seriam executadas
        consultas SQL.

        SELECT
        INSERT
        UPDATE
        DELETE
    */

    echo "Consultando dados do banco...<br>";
    echo "Consulta realizada com sucesso.<br><br>";


    /*
        Encerrando a conexão.

        Basta atribuir NULL à variável.

        O objeto PDO é destruído e a conexão
        é encerrada.
    */

    $pdo = null;

    echo "🔒 Conexão encerrada com sucesso.";

}


/*
    Caso aconteça algum erro durante
    a conexão, o programa entra aqui.
*/

catch(PDOException $erro){

    echo "Erro na conexão:<br>";

    echo $erro->getMessage();

}

?>

</body>
</html>
