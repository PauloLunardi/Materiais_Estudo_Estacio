<?php

/*
    Exemplo de Funções em PHP

    Uma função é um bloco de código criado para
    executar uma tarefa específica.

    Ela pode receber parâmetros e retornar um valor.
*/

echo "<h2>Exemplos de Funções em PHP</h2>";

/* ===========================================
   Função sem parâmetros
   =========================================== */

/*
    Esta função apenas exibe uma mensagem.
*/
function saudacao()
{
    echo "Olá! Seja bem-vindo ao PHP.<br><br>";
}

// Chamando a função
saudacao();


/* ===========================================
   Função com parâmetros
   =========================================== */

/*
    Recebe um nome como parâmetro e exibe
    uma mensagem personalizada.
*/
function apresentar($nome)
{
    echo "Meu nome é $nome.<br>";
}

// Chamando a função
apresentar("Paulo");
apresentar("Maria");

echo "<br>";


/* ===========================================
   Função que retorna um valor
   =========================================== */

/*
    Recebe duas notas,
    calcula a média
    e retorna o resultado.
*/
function calcularMedia($nota1, $nota2)
{
    $media = ($nota1 + $nota2) / 2;

    return $media;
}

// Armazena o valor retornado pela função
$mediaAluno = calcularMedia(8.5, 7.5);

echo "Média do aluno: $mediaAluno <br><br>";


/* ===========================================
   Função com estrutura de decisão
   =========================================== */

/*
    Recebe a média do aluno
    e informa sua situação.
*/
function verificarSituacao($media)
{

    if ($media >= 6) {
        return "Aprovado";
    } else {
        return "Reprovado";
    }

}

echo "Situação: " . verificarSituacao($mediaAluno);

echo "<hr>";

/* ===========================================
   Utilizando funções com arrays
   =========================================== */

$notas = [8.0, 7.5, 9.0, 6.5];

/*
    Esta função recebe um array de notas,
    soma todos os valores e retorna a média.
*/
function calcularMediaTurma($notas)
{

    $soma = 0;

    foreach ($notas as $nota) {
        $soma += $nota;
    }

    return $soma / count($notas);

}

$mediaTurma = calcularMediaTurma($notas);

echo "Média da turma: " . number_format($mediaTurma, 2);

?>
