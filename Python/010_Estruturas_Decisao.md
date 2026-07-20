# Estruturas de Decisão e Repetição na Prática em Python

## Introdução

Neste exercício, utilizamos os conceitos de **estruturas de repetição (`for`)**, **estruturas de decisão (`if`)** e **operações matemáticas** para encontrar números especiais entre **1000 e 9999**.

O objetivo é identificar os números cuja **raiz quadrada é igual à soma dos dois primeiros algarismos com os dois últimos algarismos**.

Esse é um exercício clássico para praticar:

- Estrutura `for`
- Estrutura `if`
- Divisão inteira (`//`)
- Operador módulo (`%`)
- Potenciação (`**`)

---

# Problema

Encontrar todos os números entre **1000** e **9999** que satisfaçam a condição:

1. Separar os dois primeiros algarismos.
2. Separar os dois últimos algarismos.
3. Somar esses dois números.
4. Elevar essa soma ao quadrado.
5. Verificar se o resultado é igual ao número original.

Existem apenas **três números** que atendem essa condição.

---

# Exemplo

Considere o número:

```
2025
```

Separando:

```
20
25
```

Somando:

```
20 + 25 = 45
```

Elevando ao quadrado:

```
45² = 2025
```

Como o resultado é igual ao número original, **2025** atende à condição.

---

# Passo 1 – Percorrer todos os números

Utilizamos um laço `for`.

```python
for numero in range(1000,10000):
```

O `range(1000,10000)` gera todos os números entre:

```
1000
...
9999
```

O valor final (`10000`) não é incluído.

---

# Passo 2 – Separar os dois últimos algarismos

Utilizamos o operador módulo `%`.

```python
menos_significativos = numero % 100
```

Exemplo:

```python
numero = 3025

menos_significativos = numero % 100
```

Resultado:

```
25
```

O operador `%` retorna o resto da divisão.

---

# Passo 3 – Separar os dois primeiros algarismos

Utilizamos divisão inteira (`//`).

```python
mais_significativos = numero // 100
```

Exemplo:

```python
numero = 3025

mais_significativos = numero // 100
```

Resultado:

```
30
```

---

# Passo 4 – Somar os valores

```python
raiz = mais_significativos + menos_significativos
```

Exemplo:

```
30 + 25 = 55
```

---

# Passo 5 – Verificar a condição

Agora basta elevar a soma ao quadrado.

```python
if raiz ** 2 == numero:
```

ou

```python
if raiz * raiz == numero:
```

Se a condição for verdadeira, encontramos um dos números procurados.

---

# Passo 6 – Exibir o resultado

```python
print(numero)
print(mais_significativos)
print(menos_significativos)
print(raiz)
```

Ou utilizando uma **f-string**:

```python
print(f"Número: {numero}")
print(f"Parte superior: {mais_significativos}")
print(f"Parte inferior: {menos_significativos}")
print(f"Raiz: {raiz}")
```

---

# Passo 7 – Finalizar o programa

Após o término do laço, podemos informar que o processamento terminou.

```python
print("Fim do programa")
```

Também é possível mostrar o último valor utilizado pelo `for`.

```python
print(numero)
```

Resultado:

```
9999
```

---

# Programa Completo

```python
for numero in range(1000,10000):

    menos_significativos = numero % 100
    mais_significativos = numero // 100

    raiz = mais_significativos + menos_significativos

    if raiz ** 2 == numero:

        print(f"Número: {numero}")
        print(f"Mais significativos: {mais_significativos}")
        print(f"Menos significativos: {menos_significativos}")
        print(f"Soma: {raiz}")
        print()

print("Fim do programa")
print(f"Último valor do laço: {numero}")
```

---

# Saída Esperada

```
Número: 2025
Mais significativos: 20
Menos significativos: 25
Soma: 45

Número: 3025
Mais significativos: 30
Menos significativos: 25
Soma: 55

Número: 9801
Mais significativos: 98
Menos significativos: 1
Soma: 99

Fim do programa
Último valor do laço: 9999
```

---

# Conceitos Utilizados

## Estrutura de repetição

```python
for
```

Percorre todos os números entre 1000 e 9999.

---

## Estrutura de decisão

```python
if
```

Verifica se o número atende à condição proposta.

---

## Divisão inteira

```python
//
```

Obtém os dois primeiros algarismos.

Exemplo:

```python
3025 // 100
```

Resultado:

```
30
```

---

## Operador módulo

```python
%
```

Obtém os dois últimos algarismos.

Exemplo:

```python
3025 % 100
```

Resultado:

```
25
```

---

## Potenciação

```python
**
```

Eleva um número ao quadrado.

Exemplo:

```python
45 ** 2
```

Resultado:

```
2025
```

---

# Fluxo do Programa

```
Início
   │
   ▼
Gerar números de 1000 até 9999
   │
   ▼
Separar os dois primeiros algarismos
   │
   ▼
Separar os dois últimos algarismos
   │
   ▼
Somar os dois valores
   │
   ▼
Elevar a soma ao quadrado
   │
   ▼
É igual ao número?
   │
 ┌────Sim──────────┐
 │                 │
 ▼                 │
Exibir resultado   │
 │                 │
 └───────────◄─────┘
   │
 Não
   │
   ▼
Próximo número
   │
   ▼
Fim do laço
   │
   ▼
Exibir mensagem final
   │
   ▼
Fim
```

---

# Resumo

| Conceito | Utilização |
|----------|------------|
| `for` | Percorrer todos os números entre 1000 e 9999. |
| `if` | Verificar se o número atende à condição. |
| `//` | Obter os dois primeiros algarismos. |
| `%` | Obter os dois últimos algarismos. |
| `**` | Elevar a soma ao quadrado. |
| `print()` | Exibir os resultados encontrados. |

---

# Boas Práticas

- Utilize nomes de variáveis descritivos, como `mais_significativos` e `menos_significativos`.
- Use **f-strings** para facilitar a leitura da saída.
- Sempre organize o programa em etapas: entrada (quando houver), processamento e saída.
- Prefira comentários curtos para explicar trechos importantes do código.
- Teste o programa para garantir que os três números esperados (**2025**, **3025** e **9801**) sejam encontrados.
