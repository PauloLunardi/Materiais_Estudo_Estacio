<?php

class Fruta
{
    var $nome;
    var $tipo;

    public function __construct() { }

    public function setNome($nome)
    {
        $this->nome = $nome;
    }

    public function getNome()
    {
        return $this->nome;
    }

    public function setTipo($tipo)
    {
        $this->tipo = $tipo;
    }

    public function getTipo()
    {
        return $this->tipo;
    }
}

// Cria um objeto da classe Fruta
$fruta = new Fruta();

// Define os valores dos atributos
$fruta->setNome("Maçã");
$fruta->setTipo("Doce");

// Exibe os valores
echo "Fruta: " . $fruta->getNome() .
     ", Tipo: " . $fruta->getTipo();

?>
