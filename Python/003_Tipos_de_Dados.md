# Tipos de Dados em Python

## Introdução

Os **tipos de dados** definem quais valores uma variável pode armazenar e quais operações podem ser realizadas sobre esses valores.

Python possui diversos tipos de dados internos (*Built-in Types*), que são organizados em categorias como:

- Numéricos
- Booleanos
- Sequenciais
- Mapeamentos
- Conjuntos

Neste material, o foco será nos **tipos numéricos e booleanos**, conforme apresentado na disciplina, além de uma introdução aos tipos sequenciais.

---

# O que é um tipo de dado?

Um tipo de dado informa ao interpretador como determinado valor deve ser tratado.

Exemplo:

```python
idade = 30
nome = "Paulo"
altura = 1.80
```

Embora todos sejam armazenados em variáveis, cada um possui um tipo diferente.

Podemos verificar isso utilizando a função `type()`.

```python
print(type(idade))
print(type(nome))
print(type(altura))
```

Resultado

```
<class 'int'>
<class 'str'>
<class 'float'>
```

---

# Principais categorias de tipos em Python

Python possui diversos tipos internos.

| Categoria | Exemplos |
|------------|----------|
| Numéricos | int, float, complex |
| Booleanos | bool |
| Sequenciais | str, list, tuple, range |
| Mapeamento | dict |
| Conjuntos | set, frozenset |

Neste módulo estudaremos principalmente os tipos numéricos e booleanos.

---

# Tipo int (Inteiro)

Representa números inteiros positivos ou negativos.

Exemplos:

```python
idade = 37
saldo = -150
quantidade = 0
```

Verificando o tipo:

```python
print(type(37))
```

Resultado

```
<class 'int'>
```

---

## Características do tipo int

- Não possui parte decimal.
- Pode assumir valores muito grandes.
- O limite depende apenas da memória disponível.

Exemplo:

```python
numero = 999999999999999999999999999999999
```

Python consegue armazenar esse valor normalmente.

---

## Separador de milhares

Python permite utilizar underline (`_`) para facilitar a leitura.

```python
populacao = 1_000_000
```

O valor continua sendo um inteiro.

```python
print(populacao)
```

Resultado

```
1000000
```

---

# Tipo float

Representa números com parte decimal.

Exemplos:

```python
altura = 1.80
peso = 72.5
pi = 3.14159
```

Verificando o tipo:

```python
print(type(1.80))
```

Resultado

```
<class 'float'>
```

---

## Separador decimal

Em Python utiliza-se **ponto**, nunca vírgula.

Correto:

```python
x = 10.5
```

Errado:

```python
x = 10,5
```

Na verdade isso cria uma tupla.

```python
print(type(10,5))
```

Gerará erro se usado diretamente em `type()`, mas:

```python
x = 10,5
print(x)
```

Resultado

```
(10, 5)
```

---

# Operações com int e float

Quando apenas inteiros participam da operação:

```python
print(5 + 3)
```

Resultado

```
8
```

Tipo:

```
int
```

---

Quando existe pelo menos um float:

```python
print(5 + 3.0)
```

Resultado

```
8.0
```

Tipo:

```
float
```

---

# Divisão em Python

A divisão comum sempre retorna float.

```python
print(5 / 2)
```

Resultado

```
2.5
```

Mesmo que ambos sejam inteiros.

---

# Divisão inteira

Utiliza o operador `//`.

```python
print(5 // 2)
```

Resultado

```
2
```

---

# Resto da divisão

Utiliza `%`.

```python
print(5 % 2)
```

Resultado

```
1
```

Muito utilizado para verificar números pares.

```python
numero = 10

print(numero % 2 == 0)
```

Resultado

```
True
```

---

# Exponenciação

Em Python utiliza-se `**`.

```python
print(2 ** 3)
```

Resultado

```
8
```

Outro exemplo:

```python
print(5 ** 2)
```

Resultado

```
25
```

---

# Valor absoluto

A função `abs()` retorna o valor absoluto.

```python
print(abs(-15))
```

Resultado

```
15
```

---

# Tipo complex

Representa números complexos.

Sua forma geral é:

```
a + bj
```

Onde:

- a → parte real
- b → parte imaginária

Exemplo:

```python
z = 2 + 5j

print(type(z))
```

Resultado

```
<class 'complex'>
```

---

## Parte real

```python
z = 2 + 5j

print(z.real)
```

Resultado

```
2.0
```

---

## Parte imaginária

```python
print(z.imag)
```

Resultado

```
5.0
```

---

## Conjugado

```python
z = 2 + 5j

print(z.conjugate())
```

Resultado

```
(2-5j)
```

---

# Tipo bool

Representa valores lógicos.

Existem apenas dois valores possíveis.

```python
True
False
```

Verificando:

```python
print(type(True))
```

Resultado

```
<class 'bool'>
```

---

# Expressões booleanas

São expressões que retornam verdadeiro ou falso.

```python
print(2 < 3)
```

Resultado

```
True
```

Outro exemplo:

```python
print(10 > 20)
```

Resultado

```
False
```

---

# O operador not

Inverte um valor booleano.

```python
print(not True)
```

Resultado

```
False
```

Outro exemplo:

```python
print(not (2 < 3))
```

Resultado

```
False
```

---

# Operadores de comparação

| Operador | Significado |
|-----------|-------------|
| == | Igual |
| != | Diferente |
| > | Maior |
| >= | Maior ou igual |
| < | Menor |
| <= | Menor ou igual |

Exemplos:

```python
print(10 == 10)
```

```
True
```

```python
print(10 != 5)
```

```
True
```

```python
print(7 <= 4)
```

```
False
```

---

# Operadores booleanos

## and

Retorna verdadeiro apenas se todas as condições forem verdadeiras.

```python
idade = 20

print(idade >= 18 and idade <= 60)
```

Resultado

```
True
```

---

## or

Retorna verdadeiro se pelo menos uma condição for verdadeira.

```python
print(10 < 5 or 20 > 10)
```

Resultado

```
True
```

---

## not

Inverte o resultado.

```python
print(not False)
```

Resultado

```
True
```

---

# Operadores aritméticos

| Operador | Operação | Exemplo |
|-----------|----------|----------|
| + | Soma | 2 + 3 |
| - | Subtração | 8 - 5 |
| * | Multiplicação | 4 * 6 |
| / | Divisão | 9 / 2 |
| // | Divisão inteira | 9 // 2 |
| % | Resto | 9 % 2 |
| ** | Potência | 2 ** 5 |

---

# Tipos sequenciais (Introdução)

Além dos tipos numéricos, Python possui tipos que armazenam sequências de dados.

## String

Texto.

```python
nome = "Python"
```

---

## Lista

Coleção mutável.

```python
numeros = [1, 2, 3]
```

---

## Tupla

Coleção imutável.

```python
cores = ("Azul", "Verde")
```

---

## Range

Sequência utilizada principalmente em laços.

```python
range(5)
```

---

# Conversão entre tipos

Python permite converter tipos utilizando funções específicas.

## Para inteiro

```python
int("10")
```

Resultado

```
10
```

---

## Para float

```python
float("10")
```

Resultado

```
10.0
```

---

## Para string

```python
str(100)
```

Resultado

```
"100"
```

---

## Para booleano

```python
bool(1)
```

Resultado

```
True
```

```python
bool(0)
```

Resultado

```
False
```

---

# Curiosidade

Em Python, o tipo **bool** é considerado um subtipo de **int**.

Isso significa que:

```python
True == 1
```

Resultado

```
True
```

E:

```python
False == 0
```

Resultado

```
True
```

Além disso:

```python
print(True + True)
```

Resultado

```
2
```

Embora isso seja permitido, normalmente utilizamos `True` e `False` apenas para representar valores lógicos.

---

# Resumo

- Os tipos de dados definem como os valores serão armazenados e manipulados.
- Os principais tipos numéricos são **int**, **float** e **complex**.
- O tipo **bool** representa valores lógicos (`True` e `False`).
- A função `type()` identifica o tipo de uma variável.
- Python utiliza `.` como separador decimal.
- A divisão (`/`) sempre retorna um `float`.
- A divisão inteira utiliza `//`.
- O resto da divisão utiliza `%`.
- A potência utiliza `**`.
- Os operadores de comparação retornam valores booleanos.
- Python também possui tipos sequenciais como **str**, **list**, **tuple** e **range**, que serão estudados com mais detalhes posteriormente.
