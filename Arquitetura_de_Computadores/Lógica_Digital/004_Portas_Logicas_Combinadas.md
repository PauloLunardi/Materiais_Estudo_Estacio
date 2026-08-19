# Portas Lógicas Combinadas e Especiais (NOR, NAND, XOR e XNOR)

Este documento apresenta a especificação técnica, expressões booleanas, cenários analógicos e métodos práticos de cálculo para as portas lógicas universais e especiais. Essas estruturas combinam as operações básicas (AND, OR, NOT) para construir funções de controle complexas essenciais em circuitos digitais de computadores.

---

## 1. Portas Lógicas Universais

As portas **NOR** e **NAND** são classificadas como portas universais. Elas aplicam a negação (inversão) diretamente sobre a saída de uma função básica, invertendo completamente os resultados do barramento. Na representação física do hardware, essa negação é simbolizada por um **pequeno círculo (bolha de negação)** na saída da porta gráfica.

### A. A Porta NOR (Não OU)
A porta NOR é o inverso exato da porta OR. Ela realiza a operação lógica OR entre as variáveis e nega o resultado final.

*   **Expressão Booleana:**  \(X = \overline{A + B}\) *(A barra de negação estende-se sobre toda a expressão)*
*   **Regra Lógica:** A saída só será `1` (Verdadeiro) se, e somente se, **todas as variáveis de entrada forem iguais a 0** (Falso). Para qualquer outra combinação, o resultado será `0`.

#### Tabela-Verdade da Porta NOR (2 Entradas)

| Entrada A | Entrada B | Saída X |
| :---: | :---: | :---: |
| 0 | 0 | **1** |
| 0 | 1 | **0** |
| 1 | 0 | **0** |
| 1 | 1 | **0** |

#### Representação Gráfica (Símbolo NOR)
O símbolo gráfico herda o formato curvado da porta OR, adicionando a bolha de negação na saída:
```text
  A ───\
        \────○───  X = overline(A + B)
  B ───/
```

### B. A Porta NAND (Não E)
A porta NAND é o inverso exato da porta AND. Ela realiza o produto lógico AND entre os sinais e inverte o bit final.

*   **Expressão Booleana:** \(X = \overline{A \cdot B}\)
*   **Regra Lógica:** A saída só será `0` (Falso) se, e somente se, **todas as variáveis de entrada forem iguais a 1** (Verdadeiro). Para todas as demais condições com pelo menos um bit em zero, o resultado de saída será `1`.

#### Tabela-Verdade da Porta NAND (2 Entradas)

| Entrada A | Entrada B | Saída X |
| :---: | :---: | :---: |
| 0 | 0 | **1** |
| 0 | 1 | **1** |
| 1 | 0 | **1** |
| 1 | 1 | **0** |

#### Representação Gráfica (Símbolo NAND)
O símbolo gráfico herda o formato de "D" da porta AND, adicionando a bolha de negação na ponta:
```text
  A ───|
       |─────○───  X = overline(A ∙ B)
  B ───|
```

### 🧠 Prática: Cálculo de Vetores de Bits em NAND
Para resolver expressões de vetores usando a porta NAND, processa-se primeiro a operação clássica AND bit a bit e, em seguida, inverte-se o resultado obtido.
*   **Dados:** \(A = 10010\), \(B = 11110\)

1.  *Etapa 1 (Produto lógico parcial AND):*
    ```text
       1 0 0 1 0  (A)
     ∙ 1 1 1 1 0  (B)
     ───────────
       1 0 0 1 0  (Resultado Parcial L)
    ```
2.  *Etapa 2 (Inversão dos bits via operação NOT):*
    \[\text{Inversão de } L \longrightarrow \overline{10010} = \mathbf{01101}\]
*   **Resultado Final:** \(X = 01101\)

---

## 2. Portas Lógicas Especiais (Exclusividade e Coincidência)

As portas **XOR** e **XNOR** operam avaliando o comportamento de paridade e igualdade matemática entre os sinais binários de entrada.

### A. A Porta XOR (OU Exclusivo)
A porta XOR (*Exclusive OR*) atua como um detector de diferenças. Ela avalia se as entradas possuem valores exclusivos e não compartilhados.

*   **Expressão Booleana:** \(X = A \oplus B\) *(O símbolo \(\oplus\) identifica a exclusividade)*
*   **Regra Lógica:** A porta produz saídas iguais a `1` (Verdadeiro) se as **entradas forem diferentes entre si**. Se todos os valores de entrada forem iguais (ambos zero ou ambos um), a saída será `0` (Falso).

#### Cenário Prático (Acionamento de Motor de Dois Locais)
Um motor elétrico industrial pode ser ligado por dois botões físicos instalados em salas diferentes. O motor só liga se apenas um dos botões for pressionado por vez. Se ninguém apertar nada ou se ambos os operadores apertarem os botões exatamente ao mesmo tempo, o motor desliga por segurança.

#### Tabela-Verdade da Porta XOR (2 Entradas)

| Entrada A | Entrada B | Saída X |
| :---: | :---: | :---: |
| 0 | 0 | **0** |
| 0 | 1 | **1** |
| 1 | 0 | **1** |
| 1 | 1 | **0** |

#### Representação Gráfica (Símbolo XOR)
Possui uma linha curvada dupla na entrada e extremidade pontiaguda na saída:
```text
  A ──)─\
         \─────  X = A ⊕ B
  B ──)─/
```

### B. A Porta XNOR (Coincidência / Não OU Exclusivo)
A porta XNOR é o inverso exato da porta XOR, funcionando como um circuito comparador de igualdade.

*   **Expressão Booleana:** \(X = A \odot B\) ou \(X = \overline{A \oplus B}\)
*   **Regra Lógica:** A porta produz saídas iguais a `1` (Verdadeiro) se, e somente se, **todas as entradas forem estritamente iguais** (coincidência de bits). Se houver discrepância entre os sinais, o resultado será `0`.

#### Tabela-Verdade da Porta XNOR (2 Entradas)

| Entrada A | Entrada B | Saída X |
| :---: | :---: | :---: |
| 0 | 0 | **1** |
| 0 | 1 | **0** |
| 1 | 0 | **0** |
| 1 | 1 | **1** |

#### Representação Gráfica (Símbolo XNOR)
Combina o arco duplo na entrada com a bolha de negação na saída:
```text
  A ──)─\
         \────○───  X = A ⊙ B
  B ──)─/
```
