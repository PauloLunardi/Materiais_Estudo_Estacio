# Avaliação de Expressões Lógicas e Ordem de Precedência

Este documento apresenta as diretrizes técnicas para a **Avaliação de Expressões Lógicas**, detalhando as regras de hierarquia operacional e o método para a construção de tabelas-verdade complexas com múltiplas variáveis de entrada.

---

## 1. A Hierarquia dos Operadores (Ordem de Precedência)

Assim como na aritmética matemática convencional (onde a multiplicação e a divisão precedem a soma e a subtração), a álgebra booleana adota uma ordem de prioridade rígida para resolver seus operadores. Respeitar essa sequência é indispensável para evitar ambiguidades e garantir a integridade dos circuitos digitais.

A ordem padrão de execução, da maior para a menor prioridade, é definida por:

1.  **1ª Prioridade ➔ Operação NOT (Inversão):** Avalia-se primeiro a negação/complemento das variáveis isoladas.
2.  **2ª Prioridade ➔ Operação AND (Conjunção):** Executa-se o produto lógico das variáveis e dos blocos intermediários.
3.  **3ª Prioridade ➔ Operação OR (Disjunção):** Realiza-se a soma lógica por último.

> 🧮 **A Regra dos Parênteses:** Os parênteses `( )` funcionam como uma quebra forçada de hierarquia. Qualquer operação ou bloco contido dentro de parênteses deve ser resolvido **obrigatoriamente primeiro**, independentemente do operador que esteja ali dentro.

---

## 2. Estudo de Caso Prático: Análise da Função $X = A + \bar{B} \cdot C$

Para entender o impacto da precedência na construção do hardware, analisaremos a expressão:
$$X = A + \bar{B} \cdot C$$
*(Lê-se: X é igual a A OR (NOT B) AND C)*

### Fluxo de Propagação do Sinal (Análise do Diagrama):
Fisicamente, as portas lógicas são encadeadas de forma a respeitar a precedência matemática:
1.  O sinal da entrada $B$ passa primeiro por uma porta **NOT**, gerando a saída intermediária $\bar{B}$.
2.  Essa saída $\bar{B}$ e a variável $C$ entram juntas como canais de uma porta **AND**, produzindo o bloco $(\bar{B} \cdot C)$.
3.  Por fim, o resultado desse produto e a variável $A$ entram em uma porta **OR**, entregando a saída final do sistema ($X$).

---

## 3. Construção Passo a Passo da Tabela-Verdade

Como a expressão possui 3 variáveis de entrada ($A, B, C$) com 2 valores possíveis para cada uma ($0$ e $1$), o número total de combinações de entrada (linhas) é dado por $2^3 = 8$. 

Para resolver a tabela de forma precisa e sem erros, decompõe-se a fórmula em colunas intermediárias seguindo a ordem de prioridade:

| $A$ | $B$ | $C$ | $\bar{B}$ *(NOT B)* | $\bar{B} \cdot C$ *(AND)* | $X = A + \bar{B} \cdot C$ *(OR Final)* |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 0 | 0 | 0 | 1 | 0 | **0** |
| 0 | 0 | 1 | 1 | 1 | **1** |
| 0 | 1 | 0 | 0 | 0 | **0** |
| 0 | 1 | 1 | 0 | 0 | **0** |
| 1 | 0 | 0 | 1 | 0 | **1** |
| 1 | 0 | 1 | 1 | 1 | **1** |
| 1 | 1 | 0 | 0 | 0 | **1** |
| 1 | 1 | 1 | 0 | 0 | **1** |

### Análise Crítica dos Resultados:
*   A coluna $\bar{B}$ simplesmente inverte os bits da coluna $B$.
*   A coluna $\bar{B} \cdot C$ só resulta em `1` nas linhas onde $\bar{B}$ **E** $C$ são simultaneamente verdadeiros (linhas 2 e 6).
*   A saída final $X$ assume o valor `1` se a coluna $A$ for verdadeira **OU** se a coluna intermediária $\bar{B} \cdot C$ for verdadeira.

---

## 4. Importância no Design de Sistemas Digitais

A avaliação correta de expressões booleanas permite mapear o comportamento exato de softwares e firmwares antes mesmo que os chips sejam fabricados. Esse alinhamento matemático blinda o projeto contra falhas lógicas e garante que as instruções de controle operem com total precisão, velocidade e sem colisões de sinais elétricos.
