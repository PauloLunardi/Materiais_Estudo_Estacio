# Tipos de Dados Sequenciais e Dicionários em Python

## Introdução

Em Python, existem estruturas de dados que permitem armazenar e organizar coleções de informações. Entre elas, destacam-se os **tipos sequenciais** e os **dicionários**.

Os principais tipos sequenciais são:

- `str` (String)
- `list` (Lista)
- `tuple` (Tupla)
- `range`

Além desses, Python possui os **dicionários (`dict`)**, que armazenam dados em pares **chave:valor**.

---

# Tipos Sequenciais

Os tipos sequenciais armazenam elementos em uma sequência ordenada.

Todos os elementos possuem um índice, permitindo acessar posições específicas.

## Índices

Em Python, a indexação começa em **0**.

Exemplo:

```python
texto = "teste"
```

| Índice | 0 | 1 | 2 | 3 | 4 |
|---------|---|---|---|---|---|
| Valor | t | e | s | t | e |

Python também permite índices negativos.

| Índice Negativo | -5 | -4 | -3 | -2 | -1 |
|-----------------|----|----|----|----|----|
| Valor | t | e | s | t | e |

O índice **-1** representa sempre o último elemento da sequência.

---

# Strings (`str`)

Strings representam textos.

Em Python não existe o tipo `char`.

Cada caractere é considerado uma string de tamanho 1.

## Criando Strings

Com aspas simples:

```python
nome = 'Python'
```

Com aspas duplas:

```python
nome = "Python"
```

Com aspas triplas:

```python
texto = """Este é
um texto
com várias linhas."""
```

---

# Acessando caracteres

```python
texto = "Python"

print(texto[0])
print(texto[3])
print(texto[-1])
```

**Saída**

```
P
h
n
```

---

# Fatiamento (Slice)

```python
texto = "Programação"

print(texto[0:4])
```

**Saída**

```
Prog
```

Outro exemplo:

```python
print(texto[3:8])
```

**Saída**

```
grama
```

---

# Métodos importantes para Strings

## `upper()`

Converte todas as letras para maiúsculas.

```python
texto = "Python"

print(texto.upper())
```

**Saída**

```
PYTHON
```

---

## `lower()`

Converte todas as letras para minúsculas.

```python
texto = "Python"

print(texto.lower())
```

**Saída**

```
python
```

---

## `split()`

Divide uma string em várias partes.

```python
frase = "Python é incrível"

lista = frase.split()

print(lista)
```

**Saída**

```
['Python', 'é', 'incrível']
```

Cada palavra torna-se um elemento da lista.

---

# Listas (`list`)

Listas armazenam coleções de elementos.

São **mutáveis**, ou seja, podem ser alteradas após sua criação.

## Criando listas

```python
numeros = [10,20,30]
```

ou

```python
nomes = ["Ana","Carlos","Paulo"]
```

Lista vazia:

```python
lista = []
```

---

## Criando listas com `list()`

```python
texto = "ABC"

lista = list(texto)

print(lista)
```

**Saída**

```
['A', 'B', 'C']
```

Outro exemplo:

```python
lista = list((1,2,3))
```

**Saída**

```
[1, 2, 3]
```

---

## Alterando listas

```python
cores = ["Azul","Verde","Vermelho"]

cores[1] = "Amarelo"

print(cores)
```

**Saída**

```
['Azul', 'Amarelo', 'Vermelho']
```

---

# Tuplas (`tuple`)

As tuplas são semelhantes às listas.

A principal diferença é que elas são **imutáveis**.

Depois de criadas, seus elementos não podem ser modificados.

---

## Criando tuplas

```python
dias = ("Seg","Ter","Qua")
```

ou

```python
dias = "Seg","Ter","Qua"
```

As vírgulas são o que realmente criam uma tupla.

---

## Criando tuplas com `tuple()`

```python
tupla = tuple([1,2,3])

print(tupla)
```

**Saída**

```
(1, 2, 3)
```

---

## Acessando elementos

```python
dias = ("Seg","Ter","Qua")

print(dias[0])
```

**Saída**

```
Seg
```

---

# Range (`range`)

O tipo `range` representa uma sequência de números.

É muito utilizado em laços `for`.

---

## Exemplo

```python
for numero in range(5):
    print(numero)
```

**Saída**

```
0
1
2
3
4
```

---

## Definindo início e fim

```python
for numero in range(2,7):
    print(numero)
```

**Saída**

```
2
3
4
5
6
```

---

## Definindo passo

```python
for numero in range(2,10,2):
    print(numero)
```

**Saída**

```
2
4
6
8
```

---

# Operadores Sequenciais

Python oferece operadores que funcionam em strings, listas, tuplas e outros tipos sequenciais.

---

## Operador `in`

Verifica se um elemento pertence à sequência.

```python
texto = "Python"

print("P" in texto)
```

**Saída**

```
True
```

---

## Operador `not in`

Verifica se um elemento não pertence à sequência.

```python
print("Z" not in texto)
```

**Saída**

```
True
```

---

## Concatenação (`+`)

```python
a = "Py"
b = "thon"

print(a + b)
```

**Saída**

```
Python
```

Também funciona com listas.

```python
lista1 = [1,2]
lista2 = [3,4]

print(lista1 + lista2)
```

**Saída**

```
[1, 2, 3, 4]
```

---

## Repetição (`*`)

```python
print("Oi "*3)
```

**Saída**

```
Oi Oi Oi
```

---

## Índice (`[]`)

```python
texto = "Python"

print(texto[2])
```

**Saída**

```
t
```

---

## Comprimento (`len()`)

```python
texto = "Python"

print(len(texto))
```

**Saída**

```
6
```

---

## Menor elemento (`min()`)

```python
letras = ["B","A","C"]

print(min(letras))
```

**Saída**

```
A
```

---

## Maior elemento (`max()`)

```python
letras = ["B","A","C"]

print(max(letras))
```

**Saída**

```
C
```

---

# Dicionários (`dict`)

Os dicionários armazenam informações em pares:

```
chave : valor
```

Cada chave deve ser única.

---

# Criando um dicionário

```python
aluno = {
    "nome":"Paulo",
    "idade":37,
    "curso":"ADS"
}
```

---

# Acessando valores

```python
print(aluno["nome"])
```

**Saída**

```
Paulo
```

---

# Adicionando um novo elemento

```python
aluno["cidade"] = "São Paulo"

print(aluno)
```

**Saída**

```
{
'nome':'Paulo',
'idade':37,
'curso':'ADS',
'cidade':'São Paulo'
}
```

---

# Alterando um valor

```python
aluno["idade"] = 38
```

---

# Exemplo utilizando CPF

```python
pessoas = {

    "11122233344": {
        "nome":"Ana",
        "sobrenome":"Silva"
    },

    "55566677788": {
        "nome":"Carlos",
        "sobrenome":"Souza"
    }
}
```

Acessando os dados:

```python
print(pessoas["11122233344"]["nome"])
print(pessoas["11122233344"]["sobrenome"])
```

**Saída**

```
Ana
Silva
```

---

# Comparação entre Lista, Tupla e Dicionário

| Estrutura | Ordenada | Mutável | Índice |
|-----------|----------|----------|---------|
| String | Sim | Não | Numérico |
| Lista | Sim | Sim | Numérico |
| Tupla | Sim | Não | Numérico |
| Range | Sim | Não | Numérico |
| Dicionário | Sim* | Sim | Chave |

> **Observação:** A partir do Python 3.7, os dicionários preservam a ordem de inserção dos elementos.

---

# Resumo

| Tipo | Utilização |
|--------|------------|
| `str` | Armazenar textos. |
| `list` | Armazenar coleções mutáveis de elementos. |
| `tuple` | Armazenar coleções imutáveis. |
| `range` | Gerar sequências numéricas. |
| `dict` | Armazenar pares chave:valor. |

---

# Boas Práticas

- Utilize **listas** quando precisar adicionar, remover ou modificar elementos.
- Utilize **tuplas** quando os dados não devem ser alterados.
- Utilize **strings** para manipulação de textos.
- Utilize **range()** em estruturas de repetição.
- Utilize **dicionários** para representar objetos ou registros identificados por uma chave (CPF, matrícula, código, e-mail, etc.).
- Escolha nomes de variáveis claros e descritivos para facilitar a leitura e manutenção do código.
