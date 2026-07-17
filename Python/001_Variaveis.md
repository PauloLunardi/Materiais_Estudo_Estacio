# Variáveis em Python

## Introdução

As variáveis são um dos conceitos mais importantes da programação. Em Python, elas são utilizadas para **armazenar informações temporariamente na memória**, permitindo que esses valores sejam utilizados, modificados e reutilizados durante a execução do programa.

Diferente de linguagens como C, C++ e Java, Python não exige que o tipo da variável seja declarado antes de utilizá-la. O interpretador identifica automaticamente o tipo do dado armazenado.

---

# O que é uma variável?

Uma variável é um **nome (identificador)** associado a um objeto armazenado na memória.

Ela funciona como um "apelido" para um valor.

```python
nome = "Paulo"
idade = 37
altura = 1.80
```

Nesse exemplo:

- `nome` referencia uma string;
- `idade` referencia um inteiro;
- `altura` referencia um número de ponto flutuante.

---

# Como criar uma variável

Em Python basta utilizar o operador de atribuição (`=`).

```python
x = 10
```

O valor `10` passa a ser armazenado na memória e poderá ser acessado pelo nome `x`.

```python
print(x)
```

Saída:

```
10
```

---

# Alterando o valor de uma variável

Uma variável pode receber outro valor a qualquer momento.

```python
x = 10

print(x)

x = 20

print(x)
```

Saída

```
10
20
```

A variável continua sendo `x`, apenas o valor armazenado mudou.

---

# O operador de atribuição (=)

É importante entender que o símbolo `=` **não representa igualdade matemática**, mas sim **atribuição**.

```python
x = 5
```

Significa:

> Armazene o valor 5 na variável chamada x.

Outro exemplo:

```python
idade = 18
idade = idade + 1

print(idade)
```

Saída

```
19
```

Neste caso:

1. idade recebe 18;
2. idade recebe o valor atual dela (18) + 1.

---

# Python possui tipagem dinâmica

Python identifica automaticamente o tipo da variável.

```python
numero = 10
```

Agora `numero` é um inteiro.

Depois:

```python
numero = "Dez"
```

Agora ela passou a armazenar uma string.

Isso é chamado de **Tipagem Dinâmica (Dynamic Typing)**.

---

# Verificando o tipo da variável

A função `type()` informa qual tipo está armazenado.

```python
nome = "Maria"

print(type(nome))
```

Resultado

```
<class 'str'>
```

Mais exemplos:

```python
print(type(10))
print(type(10.5))
print(type(True))
```

Resultado

```
<class 'int'>
<class 'float'>
<class 'bool'>
```

---

# Variáveis armazenam referências

Uma característica importante do Python é que as variáveis **não armazenam diretamente o valor**, mas sim uma referência para um objeto na memória.

Exemplo:

```python
a = 10
b = a

print(a)
print(b)
```

Saída

```
10
10
```

Quando fazemos:

```python
a = 20
```

A variável `b` continua apontando para o objeto anterior.

```python
print(a)
print(b)
```

Resultado

```
20
10
```

---

# Nomes de variáveis (identificadores)

Uma variável precisa seguir algumas regras.

## Permitidos

```python
idade
salario
valor_total
_media
produto1
cliente2025
```

---

## Não permitidos

Começar com número

```python
1idade
```

Conter espaços

```python
minha idade
```

Conter operadores

```python
salario-total
```

---

# Regras para nomes

Pode conter:

- letras
- números
- underline (_)

Não pode:

- começar por número;
- conter espaços;
- conter símbolos especiais.

---

# Python diferencia maiúsculas e minúsculas

Python é uma linguagem **Case Sensitive**.

Isso significa que:

```python
idade = 20
Idade = 30

print(idade)
print(Idade)
```

Resultado

```
20
30
```

São variáveis completamente diferentes.

---

# Boas práticas para nomes

Utilize nomes que representem o conteúdo armazenado.

Bom:

```python
salario
idade
total_vendas
nome_cliente
```

Ruim:

```python
a
b
x
z
```

Quanto mais descritivo o nome, mais fácil será entender o código.

---

# Convenção PEP 8

O padrão oficial do Python recomenda utilizar letras minúsculas e underline.

Exemplos:

```python
nome_cliente
valor_total
quantidade_produtos
media_final
```

Evite:

```python
NomeCliente
ValorTotal
MediaFinal
```

Esses formatos normalmente são utilizados para nomes de classes.

---

# Atribuição múltipla

Python permite criar várias variáveis em uma única linha.

```python
x, y, z = 10, 20, 30
```

Resultado

```
x = 10
y = 20
z = 30
```

Também é possível:

```python
nome, idade = "Carlos", 25
```

---

# Atribuindo o mesmo valor

Uma única atribuição pode inicializar várias variáveis.

```python
a = b = c = 100
```

Resultado

```
a = 100
b = 100
c = 100
```

---

# Trocando valores entre variáveis

Uma característica muito útil do Python.

Sem variável auxiliar.

```python
a = 10
b = 20

a, b = b, a

print(a)
print(b)
```

Resultado

```
20
10
```

---

# Variáveis e entrada de dados

Normalmente o usuário fornece valores utilizando `input()`.

```python
nome = input("Digite seu nome: ")

print(nome)
```

Como `input()` sempre retorna uma string, às vezes é necessário converter.

```python
idade = int(input("Digite sua idade: "))
```

---

# Variáveis numéricas

Inteiro

```python
idade = 35
```

Float

```python
altura = 1.78
```

Complexo

```python
numero = 4 + 3j
```

---

# Variáveis booleanas

Armazenam verdadeiro ou falso.

```python
ativo = True
```

```python
ligado = False
```

Muito utilizadas em decisões.

```python
if ativo:
    print("Sistema ativo")
```

---

# Variáveis de texto

Strings armazenam textos.

```python
nome = "Paulo"
```

Também podem usar aspas simples.

```python
cidade = 'Curitiba'
```

---

# Constantes (convenção)

Python não possui constantes verdadeiras.

Por convenção utilizamos letras maiúsculas.

```python
PI = 3.14159
TAXA_JUROS = 0.12
```

Nada impede alterar o valor, mas isso não é recomendado.

---

# Palavras reservadas

Não podem ser utilizadas como nome de variável.

Alguns exemplos:

```text
False
True
None
if
else
elif
for
while
break
continue
return
def
class
try
except
finally
import
from
pass
lambda
with
yield
global
nonlocal
and
or
not
is
in
```

Exemplo inválido:

```python
class = "Python"
```

Gera erro de sintaxe.

---

# Erros comuns

## Usar variável antes de criar

```python
print(nome)
```

Erro

```
NameError: name 'nome' is not defined
```

---

## Esquecer aspas

```python
nome = Paulo
```

O Python entende que `Paulo` é uma variável.

O correto:

```python
nome = "Paulo"
```

---

## Confundir = com ==

Atribuição

```python
x = 10
```

Comparação

```python
x == 10
```

---

# Exemplo completo

```python
nome = "Paulo"
idade = 37
altura = 1.80
estudando = True

print(nome)
print(idade)
print(altura)
print(estudando)

idade = idade + 1

print("Nova idade:", idade)
```

Saída

```
Paulo
37
1.8
True
Nova idade: 38
```

---

# Resumo

- Variáveis armazenam referências para objetos na memória.
- São criadas utilizando o operador `=`.
- Python possui tipagem dinâmica.
- Os nomes devem seguir regras específicas.
- Python diferencia letras maiúsculas e minúsculas.
- Utilize nomes descritivos para facilitar a leitura do código.
- É possível atribuir vários valores em uma única linha.
- Variáveis podem mudar de tipo durante a execução.
- Nunca utilize uma variável antes de atribuir um valor a ela.
- Siga a convenção PEP 8 para manter o código organizado.

---

# Curiosidade

Internamente, tudo em Python é um objeto. Isso significa que números, textos, listas e até funções podem ser armazenados em variáveis.

```python
x = 10
print(type(x))

x = "Python"
print(type(x))

x = [1, 2, 3]
print(type(x))
```

Saída

```
<class 'int'>
<class 'str'>
<class 'list'>
```

A variável continua sendo `x`; apenas o objeto referenciado muda.
