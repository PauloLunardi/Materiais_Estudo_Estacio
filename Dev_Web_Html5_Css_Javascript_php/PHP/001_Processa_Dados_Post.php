<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <title>Dados Recebidos</title>
</head>
<body>

<?php

/*
    $_POST é um array associativo que contém
    todos os dados enviados pelo formulário
    utilizando o método POST.

    Os índices correspondem ao atributo "name"
    definido nos campos do formulário.
*/

// Armazena os dados recebidos em variáveis
$nome = $_POST["name"];
$email = $_POST["email"];

?>

<h2>Dados Recebidos</h2>

<!-- Exibe os dados enviados pelo usuário -->
<p>Bem-vindo <?php echo $nome; ?></p>

<p>Seu endereço de e-mail é: <?php echo $email; ?></p>

</body>
</html>
