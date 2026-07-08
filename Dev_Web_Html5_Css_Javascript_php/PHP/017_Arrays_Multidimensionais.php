<?php

/*
    Exemplo de Array Multidimensional

    Um array multidimensional é um array que contém
    outros arrays como elementos.
*/

// Cada aluno possui um nome, idade e nota
$alunos = [

    [
        "nome" => "Paulo",
        "idade" => 37,
        "nota" => 8.5
    ],

    [
        "nome" => "Maria",
        "idade" => 22,
        "nota" => 9.3
    ],

    [
        "nome" => "João",
        "idade" => 25,
        "nota" => 7.8
    ]

];

echo "<h2>Exibindo um único aluno</h2>";

// Acessa o primeiro aluno (índice 0)
echo "Nome: " . $alunos[0]["nome"] . "<br>";
echo "Idade: " . $alunos[0]["idade"] . "<br>";
echo "Nota: " . $alunos[0]["nota"] . "<br>";

echo "<hr>";

echo "<h2>Percorrendo todos os alunos</h2>";

/*
    O foreach percorre cada aluno do array.

    A cada repetição, a variável $aluno recebe
    um dos arrays internos.
*/
foreach ($alunos as $aluno) {

    echo "Nome: " . $aluno["nome"] . "<br>";
    echo "Idade: " . $aluno["idade"] . "<br>";
    echo "Nota: " . $aluno["nota"] . "<br>";

    echo "<br>";
}

echo "<hr>";

echo "<h2>Utilizando índices</h2>";

/*
    Também é possível acessar qualquer informação
    diretamente pelo índice.
*/

// Segundo aluno
echo "Segundo aluno: " . $alunos[1]["nome"] . "<br>";

// Nota do terceiro aluno
echo "Nota do terceiro aluno: " . $alunos[2]["nota"] . "<br>";

echo "<hr>";

echo "<h2>Calculando a média da turma</h2>";

$soma = 0;

/*
    Soma todas as notas utilizando foreach.
*/
foreach ($alunos as $aluno) {

    $soma += $aluno["nota"];

}

// Calcula a média utilizando a quantidade de alunos
$media = $soma / count($alunos);

echo "Média da turma: " . number_format($media, 2);

?>
