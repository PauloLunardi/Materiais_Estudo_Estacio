# Operadores e Portas Lógicas Básicas (AND, OR e NOT)

Este documento apresenta as definições técnicas, expressões booleanas, cenários analógicos e métodos práticos de cálculo bit a bit para as três operações fundamentais da lógica digital. 

---

## 1. Fundamentos da Lógica Digital

Os **Operadores Lógicos** são ferramentas matemáticas que combinam valores booleanos (verdadeiro/falso, 1/0) para formar regras e fluxos de controle que governam algoritmos e processos automatizados.

As **Portas Lógicas** são a materialização desses operadores em hardware. São dispositivos eletrônicos microscópicos que processam sinais binários com base em faixas de tensão elétrica predefinidas (Tensão Alta = `1`, Tensão Baixa = `0`), funcionando como os blocos construtores de qualquer circuito integrado ou processador.

---

## 2. O Operador e a Porta OR (OU)

O operador OR avalia se **pelo menos uma** das condições de entrada é verdadeira para ativar a sua saída.

### Cenário Prático (Iluminação da Cabine do Carro)
A lâmpada do teto de um automóvel (\(X\)) deve acender se a porta for aberta (\(A\)) **OU** se o interruptor manual for acionado (\(B\)). A luz só permanecerá apagada se ambas as condições forem falsas (porta fechada e interruptor desligado).

*   **Expressão Booleana:**  \(X = A + B\) *(Lê-se: X é igual a A OR B)*
*   *Nota:* O sinal de adição (\(+\)) na álgebra booleana representa a conjunção lógica OR, não uma soma aritmética.

### Tabela-Verdade da Porta OR (2 Entradas)

| Entrada A | Entrada B | Saída X | Estado da Lâmpada |
| :---: | :---: | :---: | :--- |
| 0 | 0 | **0** | Porta fechada e Interruptor desligado ➔ **Apagada** |
| 0 | 1 | **1** | Porta fechada e Interruptor ligado ➔ **Acesa** |
| 1 | 0 | **1** | Porta aberta e Interruptor desligado ➔ **Acesa** |
| 1 | 1 | **1** | Porta aberta e Interruptor ligado ➔ **Acesa** |

### Representação Gráfica (Símbolo OR)
Fisicamente, a porta OR possui uma geometria curvada na entrada e pontiaguda na saída:

```text
  A ───\
        \─────  X = A + B
  B ───/
```

### Prática: Cálculo em Vetores de Bits com 3 Entradas
Para processar expressões com múltiplas entradas, como \(L = A + B + C\), o cálculo é realizado em etapas da esquerda para a direita.
*   **Dados:** \(A = 1100\), \(B = 1111\), \(C = 0001\)

*   **Etapa 1 (\(M = A + B\)):**
    ```text
       1 1 0 0  (A)
     + 1 1 1 1  (B)
     ─────────
       1 1 1 1  (M)
    ```
*   **Etapa 2 (\(L = M + C\)):**
    ```text
       1 1 1 1  (M)
     + 0 0 0 1  (C)
     ─────────
       1 1 1 1  (L)
    ```
*   **Resultado Final:** \(L = 1111\)

---

## 3. O Operador e a Porta AND (E)

O operador AND exige que **todas** as condições de entrada sejam simultaneamente verdadeiras para ativar a sua saída.

### Cenário Prático (Motor do Elevador)
A botoeira da cabine de um elevador (\(B\)) só deve acionar o motor (\(X\)) se, e somente se, o sensor de segurança indicar que a porta física está totalmente fechada (\(A\)). Se a porta estiver aberta, o acionamento do botão é ignorado, protegendo os usuários.

*   **Expressão Booleana:** \(X = A \cdot B\) *(Lê-se: X é igual a A AND B)*
*   *Nota:* O caractere de ponto (\(\cdot\)) representa o produto lógico AND, não uma multiplicação aritmética.

### Tabela-Verdade da Porta AND (2 Entradas)

| Entrada A | Entrada B | Saída X | Estado do Motor |
| :---: | :---: | :---: | :--- |
| 0 | 0 | **0** | Porta aberta e Botão solto ➔ **Desligado** |
| 0 | 1 | **0** | Porta aberta e Botão pressionado ➔ **Desligado** |
| 1 | 0 | **0** | Porta fechada e Botão solto ➔ **Desligado** |
| 1 | 1 | **1** | Porta fechada e Botão pressionado ➔ **Ligado** |

### Representação Gráfica (Símbolo AND)
Fisicamente, a porta AND possui uma geometria reta na entrada e arredondada na saída (formato de "D"):

```text
  A ───|
       |──────  X = A ∙ B
  B ───|
```

### Prática: Cálculo em Vetores de Bits (Operação Bit a Bit)
Na computação, o operador AND é aplicado alinhando as colunas e processando cada bit de forma independente.
*   **Dados:** \(A = 0110\), \(B = 1101\)

```text
   0 1 1 0  (A)
 ∙ 1 1 0 1  (B)
 ─────────
   0 1 0 0  (X)
```
*   *Análise:* Coluna 1 (\(0 \cdot 1 = 0\)); Coluna 2 (\(1 \cdot 0 = 0\)); Coluna 3 (\(1 \cdot 1 = 1\)); Coluna 4 (\(0 \cdot 1 = 0\)).
*   **Resultado Final:** \(X = 0100\)

---

## 4. O Operador e a Porta NOT (NÃO)

Diferente das portas anteriores, o operador NOT é **unário**, o que significa que ele atua sobre **uma única variável de entrada**, invertendo o seu nível lógico.

*   **Expressão Booleana:** \(X = \bar{A}\) ou \(X = A'\) *(Lê-se: X é igual a A negado ou inverso de A)*
*   **Aplicações:** Conhecido também como inversor ou complemento booleano.

### Tabela-Verdade da Porta NOT (1 Entrada)

| Entrada A | Saída X (\(\bar{A}\)) |
| :---: | :---: |
| 0 | **1** |
| 1 | **0** |

### Representação Gráfica (Símbolo NOT)
Fisicamente, a porta NOT é representada por um triângulo seguido de um **pequeno círculo invertido** na ponta (a bolha de negação), que simboliza a inversão do bit:

```text
  A ───►○───  X = Ā
```
