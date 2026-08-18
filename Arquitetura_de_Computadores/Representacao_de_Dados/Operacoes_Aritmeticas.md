# Aritmética Computacional: Operações em Qualquer Base Numérica

Este documento apresenta as regras lógicas e matemáticas que regem as operações de **Adição** e **Subtração** em diferentes bases numéricas (Decimal, Binária, Octal e Hexadecimal). No coração de qualquer processador (na Unidade Lógica e Aritmética - ULA), os circuitos digitais realizam esses cálculos manipulando bits por meio de transições de estados e transporte de sinais elétricos.

---

## 1. O Mecanismo Universal da Adição

Independentemente da base numérica escolhida, a adição segue um protocolo algorítmico único: as parcelas são somadas coluna por coluna, avançando **da direita para a esquerda** (da menor para a maior ordem posicional).

### 🔄 A Regra Geral do "Vai Um" (*Carry-Out*)
Ao somar os algarismos de uma coluna (mentalmente em decimal):
1.  Se o resultado for **menor** que o valor da base, registra-se o valor diretamente abaixo da coluna.
2.  Se o resultado for **igual ou maior** que o valor da base, calcula-se o excesso: $\text{Resultado} - \text{Valor da Base}$. O resto fica fixado na coluna atual e uma unidade de transporte (**"Vai 1"**) é repassada para ser somada à coluna imediatamente à esquerda.

### Exemplos Práticos por Base:

#### A. Base 10 (Decimal)
Mapeamento padrão do cotidiano.
$$\begin{array}{r@{\quad}l}
\ \scriptstyle 1\ \ \ \ \ \  & \text{(Carry)} \\
574 & \\
+\ \ 893 & \\
\hline
\mathbf{1467} & 
\end{array}$$
*   *Coluna 1:* $4 + 3 = 7$ (menor que 10).
*   *Coluna 2:* $7 + 9 = 16 \rightarrow 16 - 10 = \mathbf{6}$ (Vai 1).
*   *Coluna 3:* $1 + 5 + 8 = 14 \rightarrow 14 - 10 = \mathbf{4}$ (Vai 1).

#### B. Base 2 (Binária)
Em circuitos lógicos, as combinações básicas são: $1 + 1 = 10_2$ (Fica 0, Vai 1) e $1 + 1 + 1 = 11_2$ (Fica 1, Vai 1).
$$\begin{array}{r@{\quad}l}
\ \scriptstyle 1\ 1\ 1\ \ \  & \text{(Carry)} \\
1101 & (13_{10}) \\
+\ \ 0111 & (7_{10}) \\
\hline
\mathbf{10100} & (20_{10})
\end{array}$$
*   *Coluna 1:* $1 + 1 = 2 \rightarrow 2 - 2 = \mathbf{0}$ (Vai 1).
*   *Coluna 2:* $1 + 0 + 1 = 2 \rightarrow 2 - 2 = \mathbf{0}$ (Vai 1).
*   *Coluna 3:* $1 + 1 + 1 = 3 \rightarrow 3 - 2 = \mathbf{1}$ (Vai 1).
*   *Coluna 4:* $1 + 1 + 0 = 2 \rightarrow 2 - 2 = \mathbf{0}$ (Vai 1).

#### C. Base 8 (Octal)
O limite de contagem é o algarismo 7. Qualquer estouro sofre a redução por 8.
$$\begin{array}{r@{\quad}l}
\ \scriptstyle 1\ 1\ \ \ \  & \text{(Carry)} \\
64 & \\
+\ \ 35 & \\
\hline
\mathbf{121} & 
\end{array}$$
*   *Coluna 1:* $4 + 5 = 9 \rightarrow 9 - 8 = \mathbf{1}$ (Vai 1).
*   *Coluna 2:* $1 + 6 + 3 = 10 \rightarrow 10 - 8 = \mathbf{2}$ (Vai 1).

#### D. Base 16 (Hexadecimal)
Adota-se a conversão das letras (`A=10, B=11, C=12, D=13, E=14, F=15`) para processar os cálculos mentais em decimal antes de aplicar a redução por 16.
$$\begin{array}{r@{\quad}l}
\ \scriptstyle 1\ 1\ 1\ \ \  & \text{(Carry)} \\
\text{C D 9 4} & \\
+\ \ \text{8 E 7 7} & \\
\hline
\mathbf{15\text{C}0\text{B}} & 
\end{array}$$
*   *Coluna 1:* $4 + 7 = 11 \rightarrow \mathbf{B}$.
*   *Coluna 2:* $9 + 7 = 16 \rightarrow 16 - 16 = \mathbf{0}$ (Vai 1).
*   *Coluna 3:* $1 + \text{D} + \text{E} = 1 + 13 + 14 = 28 \rightarrow 29 - 16 = 12 \rightarrow \mathbf{C}$ (Vai 1). *Nota:* O enunciado original continha um pequeno erro de digitação no cálculo decimal ($1+13+14 = 28$, corrigido aqui para a consistência aritmética).
*   *Coluna 4:* $1 + \text{C} + 8 = 1 + 12 + 8 = 21 \rightarrow 21 - 16 = \mathbf{5}$ (Vai 1).

---

## 2. O Mecanismo Universal da Subtração

A subtração opera avaliando a relação entre o minuendo (algarismo superior) e o subtraendo (inferior) em cada coluna, avançando da direita para a esquerda.

### 🔑 A Regra do Empréstimo (*Borrow-In*)
*   **Minuendo $\ge$ Subtraendo:** A diferença é calculada e registrada diretamente.
*   **Minuendo $<$ Subtraendo:** É necessário subtrair uma unidade do algarismo ativo imediatamente à esquerda (**"Pedir 1 emprestado"**). O valor desse "1" emprestado equivale exatamente ao **valor total da base** do sistema numérico. Esse montante é somado ao minuendo atual para viabilizar a subtração.

### Exemplos Práticos por Base:

#### A. Base 16 (Hexadecimal)
O valor de cada empréstimo cedido pela coluna da esquerda adiciona **16 unidades** ao minuendo receptor.
$$\begin{array}{r@{\quad}l}
\text{C D 9 4} & \\
-\ \ \text{8 E 7 7} & \\
\hline
\mathbf{3\text{F}1\text{D}} & 
\end{array}$$
*   *Coluna 1 ($4 - 7$):* Inviável. Pede 1 ao 9 (que vira 8). O 4 recebe 16 unidades, tornando-se $20$. Cálculo: $20 - 7 = 13 \rightarrow \mathbf{D}$.
*   *Coluna 2 ($8 - 7$):* O antigo 9 agora vale 8. Cálculo: $8 - 7 = \mathbf{1}$.
*   *Coluna 3 ($\text{D} - \text{E}$):* Equivalente a $13 - 14$. Inviável. Pede 1 ao C (12, que vira 11). O D (13) recebe 16 unidades, tornando-se $29$. Cálculo: $29 - 14 = 15 \rightarrow \mathbf{F}$.
*   *Coluna 4 ($11 - 8$):* O antigo C (12) agora vale 11. Cálculo: $11 - 8 = \mathbf{3}$.

#### B. Base 2 (Binária)
No sistema binário, o empréstimo vale **2 unidades** decimais. Quando se pede emprestado passando por colunas zeradas, ocorre um efeito em cadeia.

> 💡 **Regra de Ouro do Empréstimo Binário:** Quando encontramos um cenário de $0 - 1$:
> 1. O zero da coluna atual que disparou a solicitação recebe o empréstimo e passa a valer **2**.
> 2. Todos os zeros intermediários à esquerda até encontrar o primeiro dígito ativo viram **1**.
> 3. O primeiro número `1` encontrado que cedeu o empréstimo é decrementado e passa a valer **0**.

$$\begin{array}{r@{\quad}l}
10001 & (17_{10}) \\
-\ \ 01110 & (14_{10}) \\
\hline
\mathbf{00011} & (3_{10})
\end{array}$$
*   *Coluna 1:* $1 - 0 = \mathbf{1}$.
*   *Coluna 2 ($0 - 1$):* Ativa o empréstimo em cadeia. O `1` da última coluna da esquerda vira `0`; os zeros das colunas 4 e 3 viram `1`; e o zero da coluna 2 recebe o peso e passa a valer `2`. Cálculo: $2 - 1 = \mathbf{1}$.
*   *Coluna 3:* O antigo zero virou 1. Cálculo: $1 - 1 = \mathbf{0}$.
*   *Coluna 4:* O antigo zero virou 1. Cálculo: $1 - 1 = \mathbf{0}$.
*   *Coluna 5:* O antigo 1 virou 0. Cálculo: $0 - 0 = \mathbf{0}$.

---

## 3. Visão Arquitetural: O Projetista de Máquinas

O estudo de baixo nível da aritmética de bases simula o pensamento dos engenheiros de computação da década de 1970, que projetavam softwares e sistemas complexos em restrições extremas de hardware utilizando linguagens como **Assembly**.

Compreender o comportamento do transporte de bits (*carry* e *borrow*) permite prever estouros de capacidade física de variáveis (*Overflow*), otimizar rotinas em sistemas embarcados modernos e entender o funcionamento interno de registradores e microcontroladores na manipulação direta da memória.

## Tabela de Equivalência Completa: Decimal (Base 10) vs. Hexadecimal (Base 16)

Abaixo está o mapeamento unificado juntando as duas partes do material didático, cobrindo toda a sequência do número 0 até o 47 para você entender o uso das letras de A a F e as viradas de bloco:

| Base Numérica | Valores e Correspondências Sequenciais (0 a 15) |
| :--- | :--- |
| **Base 10 (Decimal)** | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 |
| **Base 16 (Hexadecimal)** | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | A | B | C | D | E | F |
| | |
| **Base 10 (Decimal)** | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 |
| **Base 16 (Hexadecimal)** | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 1A | 1B | 1C | 1D | 1E | 1F |
| | |
| **Base 10 (Decimal)** | 32 | 33 | 34 | 35 | 36 | 37 | 38 | 39 | 40 | 41 | 42 | 43 | 44 | 45 | 46 | 47 |
| **Base 16 (Hexadecimal)** | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 2A | 2B | 2C | 2D | 2E | 2F |

*Nota de Estudo: Veja que os números de 10 a 15 viram as letras `A, B, C, D, E, F`. Quando chegamos no 16, a coluna da direita zera e "vai 1" para a esquerda, formando o `10`. Esse ciclo se repete perfeitamente em todas as linhas (10 a 1F, 20 a 2F).*

