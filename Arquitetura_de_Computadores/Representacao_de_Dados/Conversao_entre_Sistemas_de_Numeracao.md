# Conversão entre Sistemas de Numeração e Casos Especiais

Este documento apresenta os métodos matemáticos e algorítmicos utilizados para realizar a conversão de valores entre diferentes bases numéricas (Decimal, Binária, Octal e Hexadecimal). Embora os computadores processem informações estritamente na base 2, a representação em bases múltiplas facilita a compactação e a visualização de dados estruturados na memória.

---

## 1. Tabela Universal de Equivalência de Valores

A matriz abaixo estabelece o alinhamento de contagem síncrona entre as quatro principais bases utilizadas na ciência da computação, ilustrando o uso de letras maiúsculas (`A` a `F`) para algarismos superiores a 9 na base 16:

| Base 2 (Binária) | Base 8 (Octal) | Base 10 (Decimal) | Base 16 (Hexadecimal) |
| :--- | :---: | :---: | :---: |
| `0` | 0 | 0 | 0 |
| `1` | 1 | 1 | 1 |
| `10` | 2 | 2 | 2 |
| `11` | 3 | 3 | 3 |
| `100` | 4 | 4 | 4 |
| `101` | 5 | 5 | 5 |
| `110` | 6 | 6 | 6 |
| `111` | 7 | 7 | 7 |
| `1000` | 10 | 8 | 8 |
| `1001` | 11 | 9 | 9 |
| `1010` | 12 | 10 | A |
| `1011` | 13 | 11 | B |
| `1100` | 14 | 12 | C |
| `1101` | 15 | 13 | D |
| `1110` | 16 | 14 | E |
| `1111` | 17 | 15 | F |
| `10000` | 20 | 16 | 10 |
| `10001` | 21 | 17 | 11 |

---

## 2. Conversão Geral: De uma Base X para uma Base Y

Quando não há uma relação de potência direta entre as duas bases (como converter da base 6 para a base 8), o algoritmo exige a utilização da **Base 10 como intermediária**, atuando em duas fases distintas:

```text
 FLUXO GERAL DE CONVERSÃO INTERMEDIÁRIA

  [ Fase 1: Expansão Polinomial ]         [ Fase 2: Divisões Sucessivas ]
       (Base X) ──➔ [ BASE 10 ] ──➔ (Base Y)
```

### Exemplo Prático: Converter $234_6$ para a Base 8

#### ➔ Fase 1: Converter da Base X (6) para a Base 10
O número é expresso na soma dos produtos de seus algarismos pela base elevada aos expoentes posicionais crescentes (da direita para a esquerda, iniciando em 0):
$$234_6 = (2 \times 6^2) + (3 \times 6^1) + (4 \times 6^0)$$
$$234_6 = (2 \times 36) + (3 \times 6) + (4 \times 1)$$
$$234_6 = 72 + 18 + 4 = \mathbf{94_{10}}$$

#### ➔ Fase 2: Converter da Base 10 (94) para a Base Y (8)
Realiza-se o processo inverso por meio de **divisões inteiras sucessivas** pela base de destino (8). Os restos das divisões formam o novo número, sendo lidos de baixo para cima (do último quociente/resto para o primeiro):

1.  $94 \div 8 = 11$ com **Resto = 6** *(Algarismo mais à direita / Unidades)*
2.  $11 \div 8 = 1$ com **Resto = 3**
3.  $1 \div 8 = 0$ com **Resto = 1** *(Condição de parada atingida: Quociente = 0)*

*Resultado:* Lendo os restos na ordem inversa (do último para o primeiro), obtemos: **$136_8$**.

---

## 3. Casos Especiais: Atalhos por Agrupamento de Bits

As conversões entre as bases **2, 8 e 16** dispensam a necessidade de passar pela base 10. Como $8 = 2^3$ e $16 = 2^4$, podemos realizar o mapeamento direto fatiando os dígitos em blocos de bits.

### O Conceito de Mapeamento Binário (Pesos dos Bits)
Cada posição de um bit possui um valor relativo fixo em decimal determinado por potências de 2. Colocar o dígito `1` equivale a "ligar" o peso daquela posição; colocar `0` equivale a "desligar".

| Peso Posicional | $2^0 = 1$ | $2^1 = 2$ | $2^2 = 4$ | $2^3 = 8$ | $2^4 = 16$ | $2^5 = 32$ | $2^6 = 64$ | $2^7 = 128$ |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |

> **Exemplo:** O binário `101` possui os bits das posições 2 ($2^2=4$) e 0 ($2^0=1$) ligados. Somando seus pesos: $4 + 1 = 5_{10}$.

### 📁 A. Conversão de Binário (Base 2) para Octal (Base 8)
Como $8 = 2^3$, dividimos o número binário em **grupos de 3 bits**, partindo da direita para a esquerda. Cada trio é convertido individualmente no seu algarismo correspondente:

$$\text{Binário:} \quad (111010111)_2 \longrightarrow \underbrace{(111)}_{7} \ \underbrace{(010)}_{2} \ \underbrace{(111)}_2$$
$$\text{Resultado:} \quad \mathbf{727_8}$$

### 📁 B. Conversão de Binário (Base 2) para Hexadecimal (Base 16)
Como $16 = 2^4$, dividimos o número binário em **grupos de 4 bits**, partindo da direita para a esquerda. Caso o último grupo à esquerda fique incompleto, preenche-se com zeros à esquerda:

$$\text{Binário:} \quad (1011011011)_2 \longrightarrow \underbrace{(0010)}_{2} \ \underbrace{(1101)}_{D} \ \underbrace{(1011)}_2$$
$$\text{Resultado:} \quad \mathbf{2DB_{16}}$$

### 📁 C. Conversão de Octal (Base 8) para Hexadecimal (Base 16)
Como não há uma potência inteira direta entre 8 e 16, a ponte mais eficiente é converter o número **primeiro para Binário (Base 2)** e, em seguida, agrupar o resultado de 4 em 4 bits para obter o Hexadecimal.

> **Problema Prático:** Converter $3174_8$ para a Base 16.

*   **Passo 1: Abrir cada algarismo octal em trios de 3 bits:**
    *   $3 \longrightarrow 011$
    *   $1 \longrightarrow 001$
    *   $7 \longrightarrow 111$
    *   $4 \longrightarrow 100$
    *   *Binário intermediário formado:* `(011001111100)_2`

*   **Passo 2: Reagrupar o binário em blocos de 4 bits (da direita para a esquerda):**
    $$\text{Blocos:} \quad \underbrace{(0110)}_{6} \ \underbrace{(0111)}_{7} \ \underbrace{(1100)}_{C}$$
    $$\text{Resultado Final:} \quad \mathbf{67C_{16}}$$
