# Equivalência e Avaliação Complexa de Funções Lógicas

Este documento apresenta as diretrizes técnicas para identificar a **Equivalência Lógica** entre circuitos e o método estruturado para avaliar expressões booleanas complexas, tanto com variáveis isoladas quanto com palavras de múltiplos bits.

---

## 1. O Conceito de Equivalência Lógica

Duas ou mais funções lógicas são consideradas **equivalentes** se, e somente se, para todas as possíveis combinações de variáveis de entrada, elas produzirem exatamente os mesmos valores de saída. 

Na engenharia de hardware, identificar essa propriedade permite a **otimização de circuitos**: podemos substituir uma expressão longa e cara por uma versão simplificada que possui uma tabela-verdade idêntica, reduzindo o número de portas lógicas físicas e melhorando o consumo de energia e o tempo de resposta do processador.

> **Exemplo Prático (Idempotência):** Considere a função \(X = A \cdot A\) (Porta AND conectada com as duas entradas recebendo o mesmo sinal).
> * Se \(A = 0 \rightarrow X = 0 \cdot 0 = 0\)
> * Se \(A = 1 \rightarrow X = 1 \cdot 1 = 1\)
> 
> Como a tabela-verdade de \(X = A \cdot A\) é idêntica à da função \(Y = A\), dizemos que as duas expressões são logicamente equivalentes (\(A \cdot A \equiv A\)).

---

## 2. Engenharia Reversa e Substituição de Blocos

Para extrair e documentar circuitos com portas integradas (como a porta NAND), criamos saídas intermediárias de sinal (como \(T_1\)) a partir das entradas e fazemos substituições algébricas em direção à saída final (\(F\)).

### Exemplo de Circuito Integrado com Portas Universais
Considerando um diagrama contendo portas NAND encadeadas, o fluxo de simplificação matemática substitui os blocos intermediários respeitando as barras de negação estendidas:

1.  Mapeia-se o primeiro bloco de saída: \(T_1 = \overline{A \cdot \bar{B}}\)
2.  Mapeia-se o bloco final do circuito: \(X = \overline{T_1 \cdot \bar{B}}\)
3.  Substituindo \(T_1\) na equação final e aplicando os teoremas de De Morgan, a expressão unifica-se para:
    \[X = \overline{(\overline{A \cdot \bar{B}}) \cdot \bar{B}} = (A \cdot \bar{B}) + B = A + B\]

---

## 3. Prática de Avaliação com Variáveis Isoladas

Ao resolver expressões matemáticas mistas no tribunal lógico, devemos seguir rigorosamente a prioridade dos parênteses e a precedência dos operadores (\(\text{NOT} \rightarrow \text{AND} \rightarrow \text{OR} / \text{XOR}\)).

> **Problema de Teste:** Sejam \(A = 1, B = 0, C = 1, D = 1\). Calcule \(X = A + \overline{B \cdot C} \oplus D\).

*   **Etapa 1 (AND interno):** Calcula-se o produto lógico \(B \cdot C = 0 \cdot 1 = \mathbf{0}\).
*   **Etapa 2 (NOT):** Aplica-se a barra de inversão sobre o resultado anterior: \(\bar{0} = \mathbf{1}\).
*   **Etapa 3 (OR por prioridade à esquerda):** Soma-se o valor de \(A\): \(A + 1 = 1 + 1 = \mathbf{1}\).
*   **Etapa 4 (XOR Final):** Aplica-se o Ou Exclusivo com o dado de \(D\): \(1 \oplus 1 = \mathbf{0}\).
*   **Resultado do Sistema:** \(X = 0\)

---

## 4. Avaliação Vetorial Avançada (Múltiplos Bits)

Na computação prática, as operações lógicas tratam cadeias contíguas de dados (vetores de bits). O cálculo deve ser feito coluna por coluna, alinhando bit com bit.

> **Desafio Mestre:** Dados os vetores \(A = 1001, B = 0010, C = 1110, D = 1111\).  
> Calcule o valor final para a expressão: \(X = A \oplus (\overline{B \cdot C} + D) + (B \oplus \bar{D})\)

### Resolução Algorítmica Passo a Passo:

#### ➔ Fase 1: Solução do Primeiro Parêntese \((\overline{B \cdot C} + D)\)
*   **Passo A (Operação \(B \cdot C\)):**
    ```text
       0 0 1 0  (B)
     ∙ 1 1 1 0  (C)
     ─────────
       0 0 1 0  (T1 parcial)
    ```
*   **Passo B (Operação \(\overline{T_1}\)):** Inverte-se o vetor obtido: \(\overline{0010} = \mathbf{1101}\).
*   **Passo C (Operação \(\overline{T_1} + D\)):** Soma lógica OR com o vetor \(D\):
    ```text
       1 1 0 1  (T1 invertido)
     + 1 1 1 1  (D)
     ─────────
       1 1 1 1  (Bloco do 1º Parêntese concluído)
    ```

#### ➔ Fase 2: Solução do Segundo Parêntese \((B \oplus \bar{D})\)
*   **Passo D (Operação \(\bar{D}\)):** Inverte-se o vetor original de \(D\): \(\overline{1111} = \mathbf{0000}\).
*   **Passo E (OU Exclusivo \(B \oplus \bar{D}\)):** Retorna `1` apenas onde os bits forem diferentes.
    ```text
       0 0 1 0  (B)
     ⊕ 0 0 0 0  (D invertido)
     ─────────
       0 0 1 0  (Bloco do 2º Parêntese concluído)
    ```

#### ➔ Fase 3: Unificação dos Blocos e Veredito Final
*   **Passo F (Operação \(A \oplus \text{Parêntese 1}\)):**
    ```text
       1 0 0 1  (A)
     ⊕ 1 1 1 1  (Resultado da Fase 1)
     ─────────
       0 1 1 0  (Bloco da esquerda concluído)
    ```
*   **Passo G (Operação OR Final entre os dois blocos estruturados):**
    ```text
       0 1 1 0  (Resultado do Bloco da Esquerda)
     + 0 0 1 0  (Resultado do Bloco da Direita)
     ─────────
       0 1 1 0  (Vetor definitivo do sistema)
    ```

*   **Veredito:** O processamento completo das strings binárias resulta em **$X = 0110$**.
