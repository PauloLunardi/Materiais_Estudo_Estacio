# Formatação de Dados de Saída em Python

## Introdução

A formatação de dados de saída é o processo de organizar as informações exibidas pelo programa de maneira clara, organizada e legível para o usuário.

Em Python, a função responsável por exibir informações na tela é a **`print()`**, que oferece diversas formas de formatação, como concatenação de strings, método `format()` e **f-strings**, além de permitir a impressão de sequências e partes de strings.

Uma boa formatação torna o código mais fácil de entender e melhora a experiência do usuário.

---

# A função `print()`

A função `print()` exibe informações no console.

## Sintaxe

```python
print(valor)
```

ou

```python
print("Texto")
```

### Exemplo

```python
nome = "Paulo"
idade = 37

print(nome)
print(idade)
```

**Saída**

```
Paulo
37
```

---

# Concatenação de Strings

Uma das formas de montar uma saída é utilizando o operador `+` para concatenar textos.

### Exemplo

```python
hora = 10
minutos = 26
segundos = 18

print(str(hora) + ":" + str(minutos) + ":" + str(segundos))
```

**Saída**

```
10:26:18
```

### Observação

Como números não podem ser concatenados diretamente com strings, é necessário convertê-los utilizando `str()`.

---

# Método `format()`

O método `format()` permite inserir valores dentro de uma string utilizando chaves `{}`.

## Sintaxe

```python
print("texto {}".format(valor))
```

### Exemplo

```python
hora = 10
minutos = 26
segundos = 18

print("{}:{}:{}".format(hora, minutos, segundos))
```

**Saída**

```
10:26:18
```

As chaves `{}` indicam onde cada valor será inserido.

É importante que a quantidade de chaves seja igual à quantidade de argumentos passados para `format()`.

---

# f-Strings (Strings Formatadas)

As **f-strings** são a forma mais moderna e recomendada de formatar textos em Python.

Basta colocar a letra **`f`** antes da string e inserir as variáveis entre chaves.

## Sintaxe

```python
print(f"Texto {variavel}")
```

### Exemplo

```python
hora = 10
minutos = 26
segundos = 18

print(f"{hora}:{minutos}:{segundos}")
```

**Saída**

```
10:26:18
```

Outro exemplo:

```python
nome = "Maria"
idade = 22

print(f"Meu nome é {nome} e tenho {idade} anos.")
```

**Saída**

```
Meu nome é Maria e tenho 22 anos.
```

As f-strings são mais simples, legíveis e recomendadas para novos projetos.

---

# Definindo largura de campo

É possível reservar uma quantidade fixa de espaços para exibir um valor.

Isso é útil para organizar tabelas e relatórios.

## Exemplo

```python
numero1 = 10
numero2 = 100

print("{:4}".format(numero1))
print("{:5}".format(numero2))
```

**Saída**

```
  10
  100
```

Observe que:

- `{:4}` reserva quatro posições.
- `{:5}` reserva cinco posições.
- O alinhamento padrão é à direita.

---

# Formatando números de ponto flutuante

Também é possível controlar a quantidade de casas decimais.

## Exemplo

```python
pi = 3.14159265

print("{:.2f}".format(pi))
```

**Saída**

```
3.14
```

Nesse caso:

- `.2` indica duas casas decimais.
- `f` indica um número do tipo float.

Outro exemplo:

```python
valor = 15.987654

print("{:8.3f}".format(valor))
```

**Saída**

```
  15.988
```

Neste exemplo:

- `8` representa a largura total do campo.
- `3` representa três casas decimais.

---

# Impressão de sequências

Python permite imprimir listas, tuplas e strings diretamente utilizando `print()`.

## Exemplo com lista

```python
cores = ["Azul", "Verde", "Vermelho"]

print(cores)
```

**Saída**

```
['Azul', 'Verde', 'Vermelho']
```

---

# Impressão de Strings

As strings também podem ser tratadas como sequências de caracteres.

## Exemplo

```python
texto = "Python"

print(texto)
```

**Saída**

```
Python
```

---

# Substrings (Fatiamento)

É possível imprimir apenas parte de uma string utilizando índices.

## Sintaxe

```python
string[inicio:fim]
```

O índice final **não é incluído**.

### Exemplo

```python
texto = "Programação"

print(texto[0:4])
```

**Saída**

```
Prog
```

Outro exemplo

```python
texto = "Programação"

print(texto[2:8])
```

**Saída**

```
ograma
```

---

# Impressão em ordem inversa

Também é possível inverter uma string utilizando o operador de fatiamento.

## Sintaxe

```python
string[::-1]
```

### Exemplo

```python
texto = "Python"

print(texto[::-1])
```

**Saída**

```
nohtyP
```

O valor `-1` indica que a leitura será realizada do último caractere para o primeiro.

---

# Resumo

| Recurso | Finalidade | Exemplo |
|----------|------------|----------|
| `print()` | Exibir informações | `print("Olá")` |
| Concatenação | Unir textos | `"Nome: " + nome` |
| `format()` | Inserir valores em uma string | `"{}".format(valor)` |
| f-string | Formatação moderna | `f"{valor}"` |
| `{:4}` | Definir largura de campo | `"{:4}".format(10)` |
| `{:.2f}` | Definir casas decimais | `"{:.2f}".format(3.14159)` |
| `string[inicio:fim]` | Imprimir parte da string | `texto[0:4]` |
| `string[::-1]` | Inverter uma string | `texto[::-1]` |

---

# Boas práticas

- Utilize **f-strings** sempre que possível, pois são mais simples e legíveis.
- Use `format()` quando precisar de configurações mais avançadas de formatação.
- Controle a quantidade de casas decimais em valores monetários ou científicos.
- Utilize o fatiamento (`slice`) para manipular strings de forma prática.
- Evite concatenações excessivas com o operador `+`, principalmente quando houver muitas variáveis.
