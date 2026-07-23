# 🧮 Guia de Módulos: `math` & `random` em Python

Este documento serve como referência para entender como utilizar operações matemáticas avançadas e geração de valores aleatórios no Python.

---

## 🏛️ 1. O Módulo `math` (Matemática Avançada)

O módulo `math` fornece funções matemáticas para lidar com números reais. Ele é essencial quando precisamos ir além das operações básicas (+, -, *, /).

### 🔍 Aplicação Prática: Fórmula de Bhaskara
No cálculo de equações de segundo grau (\(ax^2 + bx + c = 0\)), usamos o `math.sqrt()` para extrair a raiz quadrada do discriminante (\(\Delta\)).

```python
import math

def calcular_raizes(a, b, c):
    delta = b ** 2 - 4 * a * c

    if delta > 0:
        # math.sqrt() extrai a raiz quadrada exata do delta positivo
        raiz1 = (-b + math.sqrt(delta)) / (2 * a)
        raiz2 = (-b - math.sqrt(delta)) / (2 * a)
        return (raiz1, raiz2)
        
    elif delta < 0:
        parte_real = -b / (2 * a)
        # Como delta é negativo, usamos '-delta' para torná-lo positivo antes da raiz.
        # Caso contrário, o math.sqrt() dispararia um erro de valor (ValueError).
        parte_imaginaria = math.sqrt(-delta) / (2 * a)
        
        # A função nativa complex() gera o número com a letra 'j' (padrão do Python)
        raiz1 = complex(parte_real, parte_imaginaria)
        return raiz1
```

### 🛠️ Funções Mais Comuns do `math`
* `math.sqrt(x)`: Retorna a raiz quadrada de `x`.
* `math.ceil(x)`: Arredonda o número para cima (ex: `3.1` vira `4`).
* `math.floor(x)`: Arredonda o número para baixo (ex: `3.9` vira `3`).
* `math.pow(x, y)`: Eleva `x` à potência de `y` (funciona como `x ** y`).

---

## 🎲 2. O Módulo `random` (Números Aleatórios)

O módulo `random` é utilizado quando precisamos de imprevisibilidade, como em jogos, sorteios, simulações ou testes de sistemas.

### 🔍 Aplicação Prática: Gerador de Coeficientes Aleatórios
Podemos usar o `random` para testar a nossa função de Bhaskara gerando valores automáticos para os coeficientes \(a\), \(b\) e \(c\) sem precisar digitá-los no terminal.

```python
import random

# Gera um número inteiro aleatório entre 1 e 10 para o coeficiente 'a'
# Evitamos o 0 para não causar divisão por zero na equação
a = random.randint(1, 10)

# Gera números inteiros aleatórios entre -5 e 5 para 'b' e 'c'
b = random.randint(-5, 5)
c = random.randint(-5, 5)

print(f"Coeficientes gerados aleatoriamente: a={a}, b={b}, c={c}")
```

### 🛠️ Funções Mais Comuns do `random`
* `random.randint(inicio, fim)`: Retorna um número **inteiro** aleatório dentro do intervalo incluindo os limites.
* `random.random()`: Retorna um número **decimal (float)** aleatório entre `0.0` e `1.0`.
* `random.choice(lista)`: Seleciona de forma aleatória **um elemento** de dentro de uma lista.
* `random.shuffle(lista)`: **Embaralha** a ordem dos elementos de uma lista original.
