# Operadores em PHP

## Introdução

Os operadores são elementos fundamentais em qualquer linguagem de programação. Em PHP, eles permitem realizar cálculos, atribuir valores, comparar informações e criar expressões lógicas para controlar o fluxo da aplicação.

De forma geral, um operador recebe um ou mais valores (operandos) e produz um resultado.

Exemplos simples:

```php
5 + 3
10 - 2
4 * 6
20 / 5
```

Os símbolos `+`, `-`, `*` e `/` são chamados de **operadores aritméticos**.

---

# Tipos de Operadores em PHP

Os principais grupos de operadores utilizados em PHP são:

- Operadores Aritméticos
- Operadores de Atribuição
- Operadores de Comparação
- Operadores Lógicos

---

# Operadores Aritméticos

São utilizados para realizar operações matemáticas.

| Operador | Descrição | Exemplo |
|-----------|------------|----------|
| + | Adição | `$a + $b` |
| - | Subtração | `$a - $b` |
| * | Multiplicação | `$a * $b` |
| / | Divisão | `$a / $b` |
| % | Módulo (resto da divisão) | `$a % $b` |
| ** | Potenciação | `$a ** $b` |

## Exemplos

```php
<?php

$a = 10;
$b = 3;

echo $a + $b; // 13
echo $a - $b; // 7
echo $a * $b; // 30
echo $a / $b; // 3.333...
echo $a % $b; // 1
echo $a ** $b; // 1000

?>
```

---

# Operador de Módulo (%)

Retorna o resto da divisão inteira.

Exemplo:

```php
<?php

echo 10 % 3;

?>
```

Resultado:

```text
1
```

Muito utilizado para verificar números pares e ímpares.

```php
<?php

$numero = 8;

if ($numero % 2 == 0) {
    echo "Número par";
}

?>
```

---

# Operador Exponencial (**)

Utilizado para calcular potências.

Exemplo:

```php
<?php

echo 2 ** 3;

?>
```

Resultado:

```text
8
```

---

# Operadores de Atribuição

São utilizados para armazenar valores em variáveis.

## Atribuição Simples

```php
<?php

$idade = 25;

?>
```

---

## Atribuição Combinada

PHP permite combinar operadores aritméticos com atribuição.

### Soma e atribuição

```php
<?php

$valor = 10;

$valor += 5;

echo $valor;

?>
```

Resultado:

```text
15
```

Equivale a:

```php
$valor = $valor + 5;
```

---

### Subtração e atribuição

```php
$valor -= 2;
```

Equivale a:

```php
$valor = $valor - 2;
```

---

### Multiplicação e atribuição

```php
$valor *= 3;
```

Equivale a:

```php
$valor = $valor * 3;
```

---

### Divisão e atribuição

```php
$valor /= 2;
```

Equivale a:

```php
$valor = $valor / 2;
```

---

### Módulo e atribuição

```php
$valor %= 2;
```

Equivale a:

```php
$valor = $valor % 2;
```

---

# Operadores de Comparação

São utilizados para comparar valores.

O resultado dessas comparações será sempre:

```php
true
```

ou

```php
false
```

---

## Igualdade (==)

Verifica se os valores são iguais.

```php
<?php

echo 10 == 10;

?>
```

Resultado:

```text
true
```

---

## Identidade (===)

Verifica valor e tipo.

```php
<?php

var_dump(10 === "10");

?>
```

Resultado:

```text
false
```

Apesar do valor ser o mesmo, os tipos são diferentes.

---

## Diferença (!=)

Verifica se os valores são diferentes.

```php
<?php

echo 10 != 5;

?>
```

Resultado:

```text
true
```

---

## Diferença Alternativa (<>)

Possui a mesma função de `!=`.

```php
<?php

echo 10 <> 5;

?>
```

Resultado:

```text
true
```

---

## Não Idêntico (!==)

Verifica se os valores ou tipos são diferentes.

```php
<?php

var_dump(10 !== "10");

?>
```

Resultado:

```text
true
```

---

## Menor que (<)

```php
<?php

echo 5 < 10;

?>
```

Resultado:

```text
true
```

---

## Maior que (>)

```php
<?php

echo 20 > 10;

?>
```

Resultado:

```text
true
```

---

## Menor ou Igual (<=)

```php
<?php

echo 10 <= 10;

?>
```

Resultado:

```text
true
```

---

## Maior ou Igual (>=)

```php
<?php

echo 15 >= 10;

?>
```

Resultado:

```text
true
```

---

# Operador Spaceship (<=>)

Disponível a partir do PHP 7.

Compara dois valores e retorna:

| Resultado | Significado |
|------------|-------------|
| -1 | Menor |
| 0 | Igual |
| 1 | Maior |

Exemplo:

```php
<?php

echo 5 <=> 10;

?>
```

Resultado:

```text
-1
```

Outro exemplo:

```php
<?php

echo 10 <=> 10;

?>
```

Resultado:

```text
0
```

---

# Operadores Lógicos

São utilizados para combinar expressões condicionais.

Muito comuns em estruturas `if`, `while` e validações.

---

## AND

Retorna verdadeiro apenas se ambas as condições forem verdadeiras.

```php
<?php

$idade = 20;
$ativo = true;

if ($idade >= 18 && $ativo) {
    echo "Acesso liberado";
}

?>
```

Operadores equivalentes:

```php
and
&&
```

---

## OR

Retorna verdadeiro se pelo menos uma condição for verdadeira.

```php
<?php

$admin = false;
$gerente = true;

if ($admin || $gerente) {
    echo "Acesso autorizado";
}

?>
```

Operadores equivalentes:

```php
or
||
```

---

## XOR

Retorna verdadeiro quando apenas uma das condições for verdadeira.

```php
<?php

var_dump(true xor false);

?>
```

Resultado:

```text
true
```

```php
<?php

var_dump(true xor true);

?>
```

Resultado:

```text
false
```

---

## NOT (!)

Inverte o valor lógico.

```php
<?php

$ativo = false;

if (!$ativo) {
    echo "Usuário inativo";
}

?>
```

---

# Exemplo Prático

```php
<?php

$idade = 25;
$possuiCarteira = true;

if ($idade >= 18 && $possuiCarteira) {
    echo "Pode dirigir.";
} else {
    echo "Não pode dirigir.";
}

?>
```

Resultado:

```text
Pode dirigir.
```

---

# Boas Práticas

- Utilize `===` sempre que possível para evitar comparações inesperadas.
- Prefira expressões simples e legíveis.
- Utilize parênteses em expressões complexas.
- Evite múltiplas comparações na mesma linha.
- Comente regras de negócio mais complexas.

---

# Resumo

Os operadores são recursos essenciais do PHP e permitem manipular valores, realizar cálculos, comparar informações e criar condições para controlar o comportamento da aplicação. Dominar operadores aritméticos, de atribuição, comparação e lógica é um passo fundamental para o desenvolvimento de aplicações web robustas e eficientes.
