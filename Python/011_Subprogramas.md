# Subprogramas (Funções) em Python

## Introdução

À medida que os programas crescem, torna-se importante organizar o código em partes menores e reutilizáveis. Em Python, essas partes são chamadas de **funções**, também conhecidas como **subprogramas**.

Uma função é um bloco de código criado para realizar uma tarefa específica. Ela pode ser chamada sempre que necessário, evitando a repetição de código e tornando o programa mais organizado.

---

# O que são Subprogramas?

Um **subprograma** é um conjunto de instruções que executa uma determinada tarefa dentro de um programa.

Em Python, os subprogramas recebem o nome de **funções**.

As funções permitem:

- Reutilizar código.
- Organizar programas grandes.
- Facilitar a manutenção.
- Melhorar a legibilidade do código.

---

# Características dos Subprogramas

As funções possuem algumas características importantes:

- Possuem um único ponto de entrada.
- Executam uma tarefa específica.
- Quando são chamadas, o programa principal fica temporariamente pausado.
- Após a execução da função, o programa continua exatamente do ponto onde ela foi chamada.

---

# Definindo uma Função

Em Python, utilizamos a palavra reservada **`def`** para criar uma função.

## Sintaxe

```python
def nome_da_funcao():
    # bloco de código
```

---

## Exemplo

```python
def diz_ola():
    print("Olá, Mundo!")
```

Neste exemplo:

- `def` indica a criação da função.
- `diz_ola` é o nome da função.
- Os parênteses `()` podem receber parâmetros.
- O código da função deve estar indentado.

---

# Chamando uma Função

Depois de definida, a função pode ser executada utilizando seu nome seguido de parênteses.

```python
def diz_ola():
    print("Olá, Mundo!")

diz_ola()
```

**Saída**

```
Olá, Mundo!
```

---

# Cabeçalho da Função

O cabeçalho é a primeira linha da definição da função.

```python
def minha_funcao(parametro1, parametro2):
```

Ele é composto por:

- Palavra-chave `def`
- Nome da função
- Lista de parâmetros (opcional)

---

# Parâmetros

Os parâmetros permitem enviar informações para a função.

## Exemplo

```python
def saudacao(nome):
    print(f"Olá, {nome}!")
```

Chamando a função:

```python
saudacao("Paulo")
```

**Saída**

```
Olá, Paulo!
```

Outro exemplo:

```python
saudacao("Maria")
```

**Saída**

```
Olá, Maria!
```

---

# Funções com Mais de um Parâmetro

```python
def soma(a, b):
    print(a + b)

soma(10, 5)
```

**Saída**

```
15
```

---

# Valor de Retorno (`return`)

Nem toda função apenas imprime informações.

Muitas vezes ela precisa devolver um resultado para quem a chamou.

Isso é feito utilizando a palavra **`return`**.

## Exemplo

```python
def soma(a, b):
    return a + b
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

O `return` encerra a execução da função e devolve o valor ao programa principal.

---

# Diferença entre `print()` e `return`

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

A função devolve o valor para ser utilizado em outras operações.

Exemplo:

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

# Exemplo Completo

```python
def calcular_media(nota1, nota2):

    media = (nota1 + nota2) / 2

    return media


resultado = calcular_media(8,6)

print(f"Média: {resultado}")
```

**Saída**

```
Média: 7.0
```

---

# Ordem de Execução

Em Python, a função deve ser definida antes de ser chamada.

Correto:

```python
def mensagem():
    print("Olá!")

mensagem()
```

Incorreto:

```python
mensagem()

def mensagem():
    print("Olá!")
```

Nesse caso ocorre um erro:

```
NameError
```

Porque a função ainda não existia quando foi chamada.

---

# Exemplo com Escolha do Usuário

```python
opcao = input("Digite 1 ou 2: ")

def func1(valor):
    return valor + 1

def func2(valor):
    return valor + 2

if opcao == "1":
    resultado = func1(10)
else:
    resultado = func2(10)

print(resultado)
```

### Entrada

```
1
```

**Saída**

```
11
```

### Entrada

```
2
```

**Saída**

```
12
```

---

# Fluxo de Execução

```
Programa Principal
        │
        ▼
Chamada da Função
        │
        ▼
Executa o código da função
        │
        ▼
Retorna ao programa principal
        │
        ▼
Continua a execução
```

---

# Vantagens das Funções

- Evitam repetição de código.
- Facilitam a reutilização.
- Melhoram a organização.
- Tornam a manutenção mais simples.
- Dividem problemas grandes em tarefas menores.

---

# Resumo

| Conceito | Descrição |
|----------|-----------|
| `def` | Define uma função. |
| Chamada da função | Executa a função utilizando seu nome seguido de `()`. |
| Parâmetros | Valores recebidos pela função. |
| `return` | Devolve um valor ao programa principal. |
| `print()` | Apenas exibe informações na tela. |

---

# Boas Práticas

- Escolha nomes de funções que indiquem claramente sua finalidade, como `calcular_media()` ou `mostrar_menu()`.
- Utilize funções para dividir programas grandes em tarefas menores.
- Prefira retornar valores com `return` quando o resultado precisar ser reutilizado.
- Evite criar funções muito longas; cada função deve realizar apenas uma tarefa.
- Defina todas as funções antes de chamá-las no programa principal.
