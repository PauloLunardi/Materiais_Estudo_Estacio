<?php

// Cria um array contendo os nomes dos carros
$carros = Array("Fusca", "Monza", "Passat");

/*
    FOREACH

    Percorre automaticamente todos os elementos
    do array, armazenando cada valor na variável
    $carro a cada repetição.
*/
foreach ($carros as $carro) {

    // Exibe o nome do carro atual
    echo $carro;

    // Quebra de linha
    echo "\n";
}

/*
    FOR

    Percorre o array utilizando índices.

    $i = 0                 -> inicia no primeiro índice
    $i < count($carros)    -> executa enquanto existir posição válida
    $i++                   -> incrementa 1 a cada repetição
*/
for ($i = 0; $i < count($carros); $i++) {

    // Exibe o valor armazenado na posição atual do array
    echo $carros[$i];

    // Quebra de linha
    echo "\n";
}

/*
    Saída:

    Fusca
    Monza
    Passat

    Fusca
    Monza
    Passat

    Observação:
    O foreach é mais simples quando queremos apenas
    percorrer os valores de um array.

    O for é útil quando precisamos trabalhar com
    os índices das posições.
*/
?>
