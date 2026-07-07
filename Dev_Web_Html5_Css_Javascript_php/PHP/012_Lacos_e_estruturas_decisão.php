<?php

/*
    Caso Prático

    Uma turma possui 10 alunos e suas notas já foram
    cadastradas no sistema da instituição.

    O objetivo do programa é:

    1. Percorrer todas as notas da turma;
    2. Somar os valores;
    3. Calcular a média geral da turma;
    4. Exibir uma mensagem de acordo com o resultado.

    Regras:

    Média menor que 6.0:
    -> "Estude mais!"

    Média igual a 6.0:
    -> "Na média!"

    Média maior que 6.0:
    -> "Acima da média!"
*/

// Array contendo as notas dos alunos
$notas = [6.6, 8.4, 9.2, 7.8, 5.1, 7.9, 8.3, 7.7, 6.4, 8.6];

// Inicializa a variável que armazenará a soma das notas
$soma = 0;

/*
    Percorre todas as posições do array.

    A cada repetição:
    - O valor da nota atual é armazenado em $i
    - A nota é adicionada à variável $soma
*/
foreach ($notas as $i) {
    $soma += $i;
}

/*
    Calcula a média da turma.

    Soma total das notas ÷ quantidade de alunos
*/
$media = $soma / count($notas);

/*
    Estrutura de decisão responsável por
    analisar a média e exibir uma mensagem.
*/
if ($media < 6.0) {

    echo "Média da turma = " . $media . ". Estude mais!";

} elseif ($media == 6.0) {

    echo "Média da turma = " . $media . ". Na média!";

} else {

    echo "Média da turma = " . $media . ". Acima da média!";

}

?>
