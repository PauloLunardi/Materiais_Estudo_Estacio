# Conceito de Amarração (Binding) em Python

## Introdução

O conceito de **amarração** (*Binding*, em inglês) refere-se à associação entre um **nome** e alguma entidade da programação, como uma variável, função, objeto, operador ou tipo.

Sempre que escrevemos um programa, diversas associações são criadas automaticamente pelo interpretador ou compilador. Essas associações permitem que o computador saiba exatamente a que cada nome se refere durante a execução do programa.

Em Python, o conceito de binding é especialmente importante porque a linguagem utiliza **tipagem dinâmica**, ou seja, uma variável pode ser associada a diferentes objetos e tipos ao longo da execução.

---

# O que é Binding?

Binding é o processo de **ligar (associar)** um identificador a alguma entidade.

Por exemplo:

```python
idade = 30
```

Neste momento ocorre uma amarração:

```
idade  ─────► 30
```

O nome `idade` passa a referenciar o objeto inteiro `30`.

---

# Exemplos de amarração

Uma amarração pode ocorrer entre diferentes elementos.

## Variável → Valor

```python
x = 10
```

```
x ─────► 10
```

---

## Variável → Objeto

```python
nome = "Paulo"
```

```
nome ─────► "Paulo"
```

---

## Função → Nome

```python
def soma(a, b):
    return a + b
```

Agora o nome `soma` está associado à função criada.

```
soma ─────► função
```

---

## Operador → Símbolo

Quando escrevemos:

```python
5 + 3
```

O símbolo `+` está associado à operação de adição.

---

## Palavra reservada

Quando utilizamos:

```python
if
```

A palavra `if` já possui uma associação (binding) definida pela linguagem para representar uma estrutura condicional.

---

# Tempo de Amarração (Binding Time)

Nem todas as associações acontecem no mesmo momento.

O instante em que uma associação é criada recebe o nome de **Tempo de Amarração (Binding Time).**

Dependendo da linguagem, ela pode ocorrer:

- durante o desenvolvimento da linguagem;
- durante a compilação;
- durante a ligação de módulos (linkedição);
- durante o carregamento do programa;
- durante a execução.

---

# Principais tempos de amarração

## 1. Tempo de projeto da linguagem (Language Design Time)

É quando os criadores da linguagem definem suas regras.

Exemplo:

O símbolo

```python
+
```

representará soma.

A palavra

```python
while
```

representará um laço de repetição.

Essas decisões fazem parte da definição da linguagem.

---

## 2. Tempo de implementação da linguagem

Ocorre quando o compilador ou interpretador define detalhes internos.

Exemplo:

- tamanho dos tipos;
- representação dos números;
- implementação das operações.

Em Python esses detalhes ficam ocultos do programador.

---

## 3. Tempo de compilação

Em linguagens compiladas (como C ou Java), muitas associações acontecem durante a compilação.

Exemplo em C:

```c
int idade;
```

Nesse momento a variável já fica associada ao tipo inteiro.

Python praticamente não utiliza esse tipo de binding para variáveis.

---

## 4. Tempo de ligação (Link Time)

Ocorre quando módulos diferentes são unidos.

Exemplo em Python:

```python
import math
```

A função

```python
math.sqrt()
```

passa a ficar disponível para utilização.

---

## 5. Tempo de carregamento (Load Time)

Quando o programa é carregado para a memória, alguns endereços são ajustados automaticamente.

Esse processo normalmente acontece de forma transparente ao programador.

---

## 6. Tempo de execução (Run Time)

É o mais importante em Python.

As associações acontecem enquanto o programa está sendo executado.

Exemplo:

```python
numero = 10
```

Depois:

```python
numero = 25
```

E depois:

```python
numero = "Python"
```

Durante a execução a variável muda sua associação diversas vezes.

---

# Binding em Python

Python utiliza **Binding Dinâmico**.

Isso significa que o nome da variável pode apontar para objetos diferentes ao longo da execução.

Exemplo:

```python
valor = 10

print(type(valor))
```

Resultado

```
<class 'int'>
```

Depois:

```python
valor = "Python"

print(type(valor))
```

Resultado

```
<class 'str'>
```

A variável continua sendo `valor`.

O objeto referenciado mudou.

---

# Binding de Tipo

Uma variável pode ser vinculada ao tipo do objeto armazenado.

Existem duas formas principais.

---

## Binding Estático

O tipo é definido antes da execução e não pode mudar.

Exemplo em C

```c
int idade;
```

A variável sempre será um inteiro.

Não é possível fazer:

```c
idade = "Paulo";
```

Isso gera erro.

---

## Binding Dinâmico

O tipo pode mudar durante a execução.

É exatamente como Python funciona.

```python
valor = 100

print(type(valor))
```

Resultado

```
<class 'int'>
```

Depois:

```python
valor = 25.5

print(type(valor))
```

Resultado

```
<class 'float'>
```

Depois:

```python
valor = False

print(type(valor))
```

Resultado

```
<class 'bool'>
```

A variável foi associada a três tipos diferentes durante a execução.

---

# Exemplo completo

```python
valor = 10

print(valor)
print(type(valor))

valor = 3.14

print(valor)
print(type(valor))

valor = "Python"

print(valor)
print(type(valor))
```

Saída

```
10
<class 'int'>

3.14
<class 'float'>

Python
<class 'str'>
```

---

# Binding não copia objetos

Observe:

```python
a = 10
b = a
```

Temos:

```
a ─────► 10
b ─────► 10
```

Agora:

```python
a = 20
```

A associação muda apenas para `a`.

```
a ─────► 20
b ─────► 10
```

Resultado

```python
print(a)
print(b)
```

```
20
10
```

---

# Objetos mutáveis

Quando o objeto é mutável (como listas), o comportamento muda.

```python
lista1 = [1, 2, 3]

lista2 = lista1
```

Agora ambas apontam para a mesma lista.

```
lista1 ─────► [1,2,3]
                ▲
lista2 ─────────┘
```

Se alterarmos:

```python
lista1.append(4)

print(lista2)
```

Resultado

```
[1, 2, 3, 4]
```

Isso acontece porque as duas variáveis estão associadas ao mesmo objeto.

---

# Early Binding (Amarração Antecipada)

Também chamado de **ligação antecipada**.

A associação acontece antes da execução.

Vantagens:

- maior desempenho;
- menos verificações durante a execução;
- maior otimização.

Desvantagens:

- menos flexibilidade.

Exemplo:

Linguagens como C utilizam binding estático para tipos.

---

# Late Binding (Amarração Tardia)

Também chamado de **ligação tardia**.

A associação acontece durante a execução.

É o comportamento predominante em Python.

Vantagens:

- maior flexibilidade;
- código mais dinâmico;
- facilidade para reutilização.

Desvantagens:

- pequena perda de desempenho devido às verificações em tempo de execução.

---

# Vantagens do Binding Dinâmico

- Código mais flexível.
- Menor quantidade de declarações.
- Programação mais simples.
- Facilita prototipação rápida.
- Permite reutilização de variáveis.

---

# Desvantagens

- Erros de tipo aparecem apenas durante a execução.
- Pode dificultar encontrar erros em programas grandes.
- Menor desempenho quando comparado ao binding estático.

---

# Curiosidade

Quando fazemos:

```python
x = 10
```

O número **10** já existia como um objeto.

O Python apenas faz o nome `x` apontar para esse objeto.

Depois:

```python
x = 20
```

O objeto `10` continua existindo (caso outra variável ainda o utilize), e `x` passa a apontar para outro objeto.

Por isso dizemos que:

> **Em Python, as variáveis não armazenam valores; elas armazenam referências para objetos.**

---

# Resumo

- **Binding (Amarração)** é a associação entre um nome e uma entidade da programação.
- Uma variável é ligada (associada) a um objeto.
- O momento em que essa associação ocorre chama-se **Tempo de Binding**.
- Python utiliza principalmente **Binding Dinâmico**, realizado durante a execução.
- Em Python, uma variável pode mudar de tipo várias vezes.
- O nome permanece o mesmo; apenas o objeto referenciado muda.
- Variáveis armazenam referências para objetos, e não os próprios valores.
- O Binding Dinâmico torna Python extremamente flexível, mas exige atenção para evitar erros de tipo durante a execução.
