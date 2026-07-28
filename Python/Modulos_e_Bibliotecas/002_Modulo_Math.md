# Módulo Math (Matemática Avançada)

O módulo `math` fornece funções voltadas para cálculos com números reais (float). Ele não oferece suporte para números complexos.

---

## 1. Funções de Arredondamento

Essenciais para regras de negócio que envolvem finanças, fretes ou divisões de estoques.

* **math.ceil(x):** Arredonda o número decimal estritamente para cima (teto), independente de quão pequena seja a casa decimal.
* **math.floor(x):** Arredonda o número decimal estritamente para baixo (chão), descartando qualquer fração.

```python
import math

print(math.ceil(4.1))   # Exibe: 5
print(math.floor(4.9))  # Exibe: 4
```

---

## 2. Funções Matemáticas Comuns

* **math.sqrt(x):** Retorna a raiz quadrada de x. O valor de x precisa ser positivo, caso contrário gerará um erro do tipo ValueError.
* **math.log(x, base):** Calcula o logaritmo de x na base informada. Se omitida, a base padrão adotada é o número de Euler (logaritmo natural).

```python
import math

print(math.sqrt(25))    # Exibe: 5.0
print(math.log(100, 10)) # Exibe: 2.0
```

---

## 3. Trigonometria e Constantes Nativas

O módulo já possui valores de alta precisão gravados em seu escopo, como `math.pi` (3.1415...) e `math.e` (2.7182...).

### A Pegadinha dos Radianos
As funções trigonométricas como `math.sin()`, `math.cos()` e `math.tan()` calculam o resultado baseando-se em **Radianos** e não em Graus. Se você passar o valor 90 diretamente para o cosseno, o Python retornará um valor incorreto para a física tradicional. Deve-se converter o ângulo primeiro usando `math.radians()`.

```python
import math

angulo_graus = 90
angulo_radianos = math.radians(angulo_graus)

# Agora o cálculo do cosseno trará o resultado correto (próximo a 0)
resultado = math.cos(angulo_radianos)
print(resultado)
```
