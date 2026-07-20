# Parâmetros, Procedimentos e Funções em Python

## Introdução

As funções são blocos de código reutilizáveis que executam tarefas específicas dentro de um programa. Elas podem receber informações por meio de **parâmetros**, realizar algum processamento e, opcionalmente, **retornar um valor**.

O uso de funções torna o código mais organizado, reutilizável e fácil de manter.

---

# Parâmetros em Python

Uma função pode precisar de informações para realizar seu trabalho. Essas informações são chamadas de **parâmetros**.

Existem duas formas principais de uma função acessar dados:

- Utilizando variáveis globais.
- Recebendo os dados por parâmetros.

O uso de parâmetros é a forma mais recomendada, pois torna a função independente e reutilizável.

---

# Definindo uma Função com Parâmetros

## Sintaxe

```python
def nome_funcao(parametro1, parametro2):
    # bloco de código
```

### Exemplo

```python
def calcula_imc(peso, altura):
    imc = peso / (altura ** 2)
    print(imc)
```

Chamando a função:

```python
calcula_imc(70, 1.75)
```

**Saída**

```
22.86
```

Neste exemplo:

- `peso` e `altura` são parâmetros.
- `70` e `1.75` são os valores passados para a função.

---

# Parâmetros Formais e Reais

## Parâmetros Formais

São os parâmetros definidos no cabeçalho da função.

```python
def soma(a, b):
```

Neste exemplo:

- `a`
- `b`

são parâmetros formais.

---

## Parâmetros Reais (Argumentos)

São os valores enviados para a função quando ela é chamada.

```python
soma(10, 5)
```

Neste exemplo:

- `10`
- `5`

são os argumentos (parâmetros reais).

---

# Valores Padrão para Parâmetros

Podemos definir valores padrão para um parâmetro.

Assim, se o usuário não informar um valor, o padrão será utilizado.

## Sintaxe

```python
def funcao(parametro=valor):
```

---

## Exemplo

```python
def taximetro(distancia, multiplicador=1):

    valor = distancia * 5 * multiplicador

    return valor
```

Chamando a função:

```python
print(taximetro(3))
```

**Saída**

```
15
```

Como o parâmetro `multiplicador` não foi informado, foi utilizado o valor padrão **1**.

Também é possível informar outro valor:

```python
print(taximetro(3,2))
```

**Saída**

```
30
```

---

# A Palavra Reservada `return`

A instrução `return` encerra a execução da função e devolve um valor ao programa que a chamou.

## Exemplo

```python
def soma(a,b):

    return a+b
```

Chamando a função:

```python
resultado = soma(10,5)

print(resultado)
```

**Saída**

```
15
```

---

# Diferença entre `return` e `print()`

## Utilizando `print()`

```python
def soma(a,b):

    print(a+b)
```

A função apenas exibe o resultado.

---

## Utilizando `return`

```python
def soma(a,b):

    return a+b
```

A função devolve o resultado para ser utilizado posteriormente.

```python
resultado = soma(10,5)

dobro = resultado * 2

print(dobro)
```

**Saída**

```
30
```

---

# Procedimentos e Funções

Embora Python utilize apenas o termo **função**, podemos classificá-las em dois tipos.

## Procedimentos

São funções que **não retornam valores**.

### Exemplo

```python
def mensagem():

    print("Olá!")
```

Chamando:

```python
mensagem()
```

**Saída**

```
Olá!
```

Observe que não existe `return`.

---

## Funções

São funções que retornam um valor utilizando `return`.

### Exemplo

```python
def quadrado(numero):

    return numero ** 2
```

Chamando:

```python
resultado = quadrado(4)

print(resultado)
```

**Saída**

```
16
```

---

# Variáveis Locais

As variáveis criadas dentro de uma função existem apenas durante sua execução.

## Exemplo

```python
def exemplo():

    x = 10

    print(x)
```

A variável `x` só existe dentro da função.

Fora dela:

```python
print(x)
```

gera o erro:

```
NameError
```

---

# Variáveis Globais

São criadas fora das funções.

## Exemplo

```python
x = 100

def mostrar():

    print(x)

mostrar()
```

**Saída**

```
100
```

A função consegue acessar a variável global.

---

# Alterando Variáveis Globais

Para modificar uma variável global dentro da função, utiliza-se a palavra reservada **`global`**.

## Exemplo

```python
x = 0

def alterar():

    global x

    x = 20

alterar()

print(x)
```

**Saída**

```
20
```

Sem o uso de `global`, seria criada uma variável local com o mesmo nome.

---

# Escopo das Variáveis

```text
Variável Global
        │
        ▼
Pode ser utilizada pelas funções

------------------------------

Variável Local
        │
        ▼
Existe apenas dentro da função
```

---

# Funções Aninhadas

Python permite definir funções dentro de outras funções.

## Exemplo

```python
def externa():

    def interna():

        print("Função interna")

    interna()

externa()
```

**Saída**

```
Função interna
```

Esse recurso é útil quando uma função será utilizada apenas internamente.

---

# Passagem de Parâmetros

Quando chamamos uma função, os valores são enviados para seus parâmetros.

Exemplo:

```python
def dobro(numero):

    return numero * 2

x = 10

print(dobro(x))
```

**Saída**

```
20
```

Em Python, esse mecanismo é conhecido como **passagem por atribuição (pass-by-assignment)**.

Na prática:

- Tipos imutáveis (`int`, `float`, `str`, `tuple`) normalmente não são alterados pela função.
- Objetos mutáveis (`list`, `dict`, `set`) podem ser modificados dentro da função.

---

# Exemplo com Lista

```python
def adicionar(lista):

    lista.append(100)

numeros = [1,2,3]

adicionar(numeros)

print(numeros)
```

**Saída**

```
[1, 2, 3, 100]
```

A lista foi modificada porque listas são objetos mutáveis.

---

# Exemplo Completo

```python
def calcula_imc(peso, altura):

    imc = peso / (altura ** 2)

    return imc


peso = 70
altura = 1.75

resultado = calcula_imc(peso, altura)

print(f"IMC: {resultado:.2f}")
```

**Saída**

```
IMC: 22.86
```

---

# Resumo

| Conceito | Descrição |
|----------|-----------|
| Parâmetro | Informação recebida pela função. |
| Argumento | Valor enviado para a função. |
| Parâmetro formal | Variável definida no cabeçalho da função. |
| Parâmetro real | Valor passado durante a chamada da função. |
| Valor padrão | Valor utilizado quando nenhum argumento é informado. |
| `return` | Devolve um valor para o programa chamador. |
| Procedimento | Função que não retorna valor. |
| Função | Função que retorna valor. |
| Variável local | Existe apenas dentro da função. |
| Variável global | Existe durante toda a execução do programa. |
| `global` | Permite modificar uma variável global dentro da função. |
| Função aninhada | Função definida dentro de outra função. |

---

# Boas Práticas

- Utilize parâmetros em vez de depender de variáveis globais.
- Dê nomes claros às funções, indicando sua finalidade.
- Utilize `return` quando o resultado precisar ser reutilizado.
- Evite alterar variáveis globais, pois isso dificulta a manutenção do código.
- Prefira funções pequenas e com uma única responsabilidade.
- Utilize funções aninhadas apenas quando fizer sentido limitar seu uso ao escopo da função principal.
