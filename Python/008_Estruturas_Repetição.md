# Estruturas de Repetição em Python

## Introdução

As **estruturas de repetição**, também chamadas de **laços (loops)**, permitem executar um bloco de código várias vezes, evitando a repetição de instruções e tornando os programas mais eficientes.

Em Python, existem dois principais laços de repetição:

- `for`
- `while`

Além disso, existem instruções que controlam o comportamento dos laços:

- `break`
- `continue`
- `pass`

---

# Estrutura `for`

O laço `for` é utilizado quando sabemos **quantas vezes** desejamos repetir uma ação ou quando queremos percorrer uma sequência de elementos.

## Sintaxe

```python
for variavel in sequencia:
    bloco_de_codigo
```

---

## Exemplo 1 – Contando de 1 a 5

```python
for numero in range(1, 6):
    print(numero)
```

**Saída**

```
1
2
3
4
5
```

---

## A função `range()`

A função `range()` gera uma sequência de números.

### Sintaxe

```python
range(inicio, fim, passo)
```

Onde:

- **início** → primeiro número da sequência.
- **fim** → último número **não incluído**.
- **passo** → incremento (opcional).

### Exemplos

```python
range(5)
```

Gera:

```
0 1 2 3 4
```

---

```python
range(1,6)
```

Gera:

```
1 2 3 4 5
```

---

```python
range(0,11,2)
```

Gera:

```
0 2 4 6 8 10
```

---

## Exemplo 2 – Percorrendo uma lista

```python
frutas = ["Maçã", "Banana", "Laranja"]

for fruta in frutas:
    print(fruta)
```

**Saída**

```
Maçã
Banana
Laranja
```

---

## Exemplo 3 – Percorrendo uma string

```python
texto = "Python"

for letra in texto:
    print(letra)
```

**Saída**

```
P
y
t
h
o
n
```

---

# Estrutura `while`

O laço `while` executa um bloco de código **enquanto uma condição for verdadeira**.

É indicado quando **não sabemos previamente quantas repetições serão necessárias**.

## Sintaxe

```python
while condicao:
    bloco_de_codigo
```

---

## Exemplo

```python
contador = 1

while contador <= 5:
    print(contador)
    contador += 1
```

**Saída**

```
1
2
3
4
5
```

Observe que a variável `contador` precisa ser atualizada para que a condição eventualmente se torne falsa.

---

# While Infinito

Um **laço infinito** ocorre quando a condição do `while` nunca deixa de ser verdadeira.

## Exemplo

```python
while True:
    print("Executando...")
```

Nesse caso:

- `True` é sempre verdadeiro.
- O programa continuará executando até ser interrompido.

Esse tipo de laço é muito utilizado em menus, servidores, jogos e programas que aguardam interação do usuário.

---

## Exemplo de menu

```python
while True:

    opcao = input("Digite S para sair: ")

    if opcao.upper() == "S":
        break
```

---

# Instrução `break`

O comando `break` interrompe imediatamente o laço.

Quando executado, o programa sai do `for` ou `while`.

## Exemplo

```python
for numero in range(1,11):

    if numero == 6:
        break

    print(numero)
```

**Saída**

```
1
2
3
4
5
```

Quando o número chega em 6, o laço é encerrado.

---

## Exemplo com `while`

```python
contador = 1

while True:

    print(contador)

    if contador == 5:
        break

    contador += 1
```

**Saída**

```
1
2
3
4
5
```

---

# Instrução `continue`

O comando `continue` faz o laço **pular a iteração atual**, passando imediatamente para a próxima repetição.

## Exemplo

```python
for numero in range(1,6):

    if numero == 3:
        continue

    print(numero)
```

**Saída**

```
1
2
4
5
```

O número 3 não foi impresso porque a execução voltou imediatamente para o início do laço.

---

## Outro exemplo

```python
for letra in "Python":

    if letra == "h":
        continue

    print(letra)
```

**Saída**

```
P
y
t
o
n
```

---

# Instrução `pass`

O comando `pass` **não faz absolutamente nada**.

Ele é utilizado quando o Python exige um bloco de código, mas o programador ainda não implementou a lógica.

## Exemplo

```python
if True:
    pass
```

O programa executa normalmente.

---

## Exemplo em função

```python
def calcular():

    pass
```

A função existe, mas ainda não possui implementação.

---

## Exemplo em laço

```python
for numero in range(5):

    pass

print("Fim do programa")
```

**Saída**

```
Fim do programa
```

O laço executa normalmente, porém nenhuma instrução é realizada.

---

# Diferença entre `break`, `continue` e `pass`

| Comando | O que faz |
|----------|-----------|
| `break` | Encerra imediatamente o laço. |
| `continue` | Pula a iteração atual e continua a próxima repetição. |
| `pass` | Não faz nada; serve apenas como marcador de posição. |

---

# Comparação entre `for` e `while`

| `for` | `while` |
|--------|----------|
| Utilizado quando sabemos quantas repetições ocorrerão. | Utilizado quando não sabemos quantas repetições serão necessárias. |
| Percorre listas, strings, tuplas e outras sequências. | Executa enquanto uma condição for verdadeira. |
| Geralmente utiliza `range()`. | Geralmente utiliza uma variável de controle. |

---

# Exemplo Comparativo

## Utilizando `for`

```python
for i in range(5):
    print(i)
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

## Utilizando `while`

```python
i = 0

while i < 5:
    print(i)
    i += 1
```

**Saída**

```
0
1
2
3
4
```

Ambos produzem o mesmo resultado.

---

# Fluxograma Simplificado

## Laço `for`

```
Início
   │
   ▼
Obtém próximo elemento
   │
   ▼
Executa o bloco
   │
   ▼
Existem mais elementos?
   │
 ┌─Sim────────────┐
 │                │
 └───────◄────────┘
   │
 Não
   │
   ▼
Fim
```

---

## Laço `while`

```
Início
   │
   ▼
Condição é verdadeira?
   │
 ┌─Sim────────────┐
 │                │
 ▼                │
Executa o bloco   │
 │                │
 └───────◄────────┘
   │
 Não
   │
   ▼
Fim
```

---

# Resumo Geral

| Estrutura | Finalidade |
|------------|------------|
| `for` | Percorrer sequências ou repetir um número conhecido de vezes. |
| `while` | Repetir enquanto uma condição for verdadeira. |
| `while True` | Criar um laço infinito até ocorrer um `break`. |
| `break` | Interromper o laço imediatamente. |
| `continue` | Ignorar a iteração atual e seguir para a próxima. |
| `pass` | Não executar nenhuma ação; usado como espaço reservado. |

---

# Boas Práticas

- Utilize **`for`** para percorrer listas, strings e intervalos de números.
- Utilize **`while`** quando a quantidade de repetições depender de uma condição.
- Tome cuidado para que um `while` tenha uma condição que possa se tornar falsa, evitando laços infinitos indesejados.
- Utilize **`break`** para interromper um laço quando uma condição específica for atendida.
- Utilize **`continue`** para ignorar apenas determinadas iterações.
- Utilize **`pass`** apenas como marcador temporário durante o desenvolvimento do programa.
