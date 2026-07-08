<?php

/*
=========================================================
EXEMPLO DE UTILIZAÇÃO DO MÉTODO lastInsertId()
=========================================================

Caso Prático

Imagine um sistema de cadastro de clientes.

Desejamos cadastrar um novo cliente
na tabela Cliente.

Após realizar o INSERT, queremos descobrir
qual foi o código (ID) gerado automaticamente
pelo banco de dados.

Para isso utilizamos o método lastInsertId().

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


// Dados do novo cliente
$nome      = "Carlos Silva";
$cpf       = "123.456.789-00";
$telefone  = "(11) 99999-8888";


/*
---------------------------------------------------------
CONSULTA SQL

Insere um novo cliente na tabela.

Observe que NÃO informamos o código
do cliente.

O próprio banco irá gerar esse valor
(AUTO_INCREMENT no MySQL ou SERIAL/IDENTITY
no PostgreSQL).

---------------------------------------------------------
*/

$sql = "

    INSERT INTO Cliente
        (nome, cpf, telefone)

    VALUES
        (:nome, :cpf, :telefone)

";


// Prepara a consulta
$stmt = $dsn->prepare($sql);


// Associa os valores aos parâmetros
$stmt->bindValue(":nome", $nome);
$stmt->bindValue(":cpf", $cpf);
$stmt->bindValue(":telefone", $telefone);


// Executa o INSERT
$stmt->execute();


/*
---------------------------------------------------------
OBTENDO O ÚLTIMO ID GERADO

lastInsertId()

Retorna o identificador do último registro
inserido pelo banco de dados.

---------------------------------------------------------
*/

$ultimoId = $dsn->lastInsertId();


// Exibe o resultado

echo "<h3>Cliente cadastrado com sucesso!</h3>";

echo "Código gerado: " . $ultimoId;

?>
