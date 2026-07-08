<?php

/*
    Exemplo: Remoção de elementos de um array

    Neste exemplo serão demonstradas três formas de
    remover elementos de um array:

    1. Atribuindo um valor vazio ao elemento.
    2. Utilizando a função unset().
    3. Utilizando a função array_splice().
*/

// Cria um array com nomes de carros
$carros = ["Fusca", "Monza", "Passat", "Gol", "Civic"];

echo "<h2>Array Original</h2>";

// Exibe o array completo
print_r($carros);

// Exibe a quantidade de elementos
echo "<br>Total de elementos: " . count($carros);

echo "<hr>";

/* =====================================================
   1) Removendo o conteúdo de um elemento
   ===================================================== */

// Apenas esvazia o conteúdo da posição 1.
// O índice continua existindo.
$carros[1] = "";

echo "<h2>1 - Elemento esvaziado</h2>";

print_r($carros);

echo "<br>Total de elementos: " . count($carros);

echo "<hr>";

/* =====================================================
   2) Removendo um elemento com unset()
   ===================================================== */

// Remove completamente o índice 2
unset($carros[2]);

echo "<h2>2 - Utilizando unset()</h2>";

print_r($carros);

echo "<br>Total de elementos: " . count($carros);

echo "<hr>";

/*
    Observe que os índices ficam "quebrados".

    Exemplo:

    [0] Fusca
    [1]
    [3] Gol
    [4] Civic
*/

echo "<hr>";

/* =====================================================
   3) Removendo elementos com array_splice()
   ===================================================== */

// Cria um novo array para o exemplo
$frutas = ["Maçã", "Banana", "Laranja", "Uva", "Abacaxi"];

echo "<h2>Array Original de Frutas</h2>";

print_r($frutas);

echo "<br>Total de elementos: " . count($frutas);

echo "<hr>";

/*
    array_splice()

    Parâmetros:

    array_splice(array, posição_inicial, quantidade);

    Neste exemplo será removido:

    posição inicial = 1
    quantidade = 2

    Serão removidos:
    Banana
    Laranja
*/

array_splice($frutas, 1, 2);

echo "<h2>3 - Utilizando array_splice()</h2>";

print_r($frutas);

echo "<br>Total de elementos: " . count($frutas);

echo "<hr>";

/*
    Resultado:

    [0] Maçã
    [1] Uva
    [2] Abacaxi

    Observe que o array foi reorganizado
    automaticamente.
*/

?>
