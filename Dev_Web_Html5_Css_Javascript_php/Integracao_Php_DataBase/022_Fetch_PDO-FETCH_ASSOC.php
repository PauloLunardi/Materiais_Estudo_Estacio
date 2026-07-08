<?php

/*
=========================================================
EXEMPLO DE UTILIZAÇÃO DA CONSTANTE PDO::FETCH_ASSOC
=========================================================

Caso Prático

Imagine um sistema de busca de usuários.

Desejamos buscar os dados de um usuário específico
na tabela Usuario através do seu e-mail.

Queremos receber os dados organizados em um Array Associativo,
onde o nome de cada chave do array seja exatamente igual
ao nome da coluna na tabela do banco de dados.

Para isso utilizamos o método fetch(PDO::FETCH_ASSOC).

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


// E-mail do usuário que desejamos buscar
$emailBusca = "usuario@email.com";


/*
---------------------------------------------------------
CONSULTA SQL

Busca o usuário filtrando pelo e-mail informado.

Utilizamos parâmetros nomeados (:email) para garantir
a segurança da consulta contra SQL Injection.

---------------------------------------------------------
*/

$sql = "

    SELECT id, nome, email, perfil
    FROM Usuario
    WHERE email = :email

";


// Prepara a consulta
$stmt = $dsn->prepare($sql);


// Associa o valor ao parâmetro
$stmt->bindValue(":email", $emailBusca);


// Executa a consulta SELECT
$stmt->execute();


/*
---------------------------------------------------------
OBTENDO O RESULTADO COMO ARRAY ASSOCIATIVO

fetch(PDO::FETCH_ASSOC)

Retorna a próxima linha do resultado como um array comum,
mas indexado apenas pelos nomes das colunas.

Se nenhum resultado for encontrado, ele retorna false.

---------------------------------------------------------
*/

$usuario = $stmt->fetch(PDO::FETCH_ASSOC);


// Exibe o resultado mapeado

if ($usuario) {

    echo "<h3>Usuário Encontrado!</h3>";

    // Acessamos os dados usando as chaves ['nome_da_coluna']
    echo "Código: " . $usuario['id'] . "<br>";
    echo "Nome: "   . $usuario['nome'] . "<br>";
    echo "E-mail: " . $usuario['email'] . "<br>";
    echo "Perfil: " . $usuario['perfil'] . "<br>";

} else {

    echo "<h3>Usuário não encontrado.</h3>";

}

?>
