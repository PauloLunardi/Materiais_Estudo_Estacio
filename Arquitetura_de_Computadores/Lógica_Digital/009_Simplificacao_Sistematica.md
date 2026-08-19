# Simplificação Sistemática de Expressões Lógicas

Este documento apresenta os métodos práticos e algorítmicos para a **Simplificação de Expressões Lógicas** utilizando os postulados da Álgebra de Boole e os Teoremas de De Morgan. O objetivo central é eliminar redundâncias algébricas para projetar circuitos digitais otimizados, econômicos e de alta velocidade.

---

## 1. O Processo de Simplificação por Etapas

Cada componente contido em uma expressão booleana representa uma porta física no hardware. A simplificação sistemática reduz o custo de fabricação do chip e diminui o atraso de propagação dos sinais elétricos.

Abaixo estão detalhados os quatro estudos de caso práticos apresentados no material didático, acompanhados de correções técnicas nos pontos onde o texto original continha pequenos erros de digitação.

---

## 2. Práticas de Engenharia Reversa e Fatoração

### 📁 Prática 1: Desconstrução com De Morgan e Absorção
Análise e redução da expressão complexa:
$$X = \overline{( \bar{A} + B ) \cdot \bar{B}}$$

*   **Etapa A (Aplicação de De Morgan na conjunção externa):**
    O Teorema de De Morgan afirma que $\overline{Y \cdot Z} = \bar{Y} + \bar{Z}$. Aplicando essa regra para quebrar a barra de negação principal, temos:
    $$X = \overline{(\bar{A} + B)} + \overline{(\bar{B})}$$
*   **Etapa B (Aplicação de De Morgan no primeiro bloco):**
    Quebrando a segunda barra interna pela regra $\overline{Y + Z} = \bar{Y} \cdot \bar{Z}$:
    $$X = (\overline{\bar{A}} \cdot \bar{B}) + \overline{(\bar{B})}$$
*   **Etapa C (Lei da Involução):**
    Sabemos que a dupla negação se anula ($\overline{\bar{A}} = A$ e $\overline{\bar{B}} = B$). Substituindo os termos:
    $$X = (A \cdot \bar{B}) + B$$
*   **Etapa D (Comutatividade e Distribuição):**
    Rearranjando os termos de forma conveniente:
    $$X = B + (\bar{B} \cdot A)$$
    Aplicando a propriedade distributiva da soma sobre o produto:
    $$X = (B + \bar{B}) \cdot (B + A)$$
*   **Etapa E (Complemento e Identidade - Veredito):**
    Como $(B + \bar{B}) = 1$, a expressão reduz-se para $1 \cdot (B + A)$, resultando em:
    $$X = A + B$$

> 💡 **Impacto no Hardware:** Uma estrutura complexa que exigiria uma porta NAND, inversores (NOT) e uma porta OR foi completamente substituída por uma única porta **OR** convencional, mantendo a tabela-verdade intacta.

---

### 📁 Prática 2: Fatoração por Agrupamento
Fatoração de uma soma de produtos de três variáveis.
*(Nota de Correção: Ajustado o mapeamento de barras do texto original para a consistência matemática exata da redução).*

$$X = (A \cdot B \cdot \bar{C}) + (A \cdot B \cdot C) + (A \cdot \bar{B} \cdot C) + (A \cdot B \cdot C)$$

*   **Passo 1 (Colocar termos comuns em evidência):**
    Agrupamos os pares usando a propriedade distributiva:
    $$X = A \cdot B \cdot (\bar{C} + C) + A \cdot C \cdot (\bar{B} + B)$$
*   **Passo 2 (Aplicação do Complemento):**
    Sabemos que $(\bar{C} + C) = 1$ e $(\bar{B} + B) = 1$.
    $$X = (A \cdot B \cdot 1) + (A \cdot C \cdot 1)$$
*   **Passo 3 (Identidade - Veredito Final):**
    $$X = A \cdot B + A \cdot C$$

---

### 📁 Prática 3: Simplificação Avançada por Teoremas
Análise de absorção e agrupamento em cadeias longas.
*(Nota de Correção: Ajustada a aplicação metodológica do texto original para refletir o resultado final verdadeiro do postulado).*

$$X = (A \cdot B \cdot C) + (A \cdot \bar{C}) + (A \cdot B)$$

*   **Passo 1 (Colocar a variável comum $A$ em evidência):**
    $$X = A \cdot (B \cdot C + \bar{C} + B)$$
*   **Passo 2 (Reorganizar usando a lei da absorção interna):**
    O bloco $(B \cdot C + \bar{C})$ simplifica-se diretamente para $(B + \bar{C})$ por absorção. Substituindo na equação:
    $$X = A \cdot (B + \bar{C} + B)$$
*   **Passo 3 (Idempotência e Complemento):**
    Como $B + B = B$, o parêntese reduz-se a $(B + \bar{C})$.
    $$X = A \cdot (B + \bar{C})$$
*   **Passo 4 (Distribuição Final):**
    $$X = A \cdot B + A \cdot \bar{C}$$

---

### 📁 Prática 4: Aplicação Direta da Absorção
Redução imediata baseada nas regras de redundância de Boole:

$$X = A \cdot (A + B)$$

*   **Resolução:** Aplicando diretamente a **Lei de Absorção 2** (Regra J), o termo secundário $+B$ é completamente anulado pelo produto externo da própria variável.
*   **Veredito Final:**
    $$X = A$$

---

## 3. Matriz de Validação por Tabela-Verdade (Caso da Prática 1)

Para comprovar formalmente que a simplificação complexa da **Prática 1** está correta, confrontamos a tabela-verdade da expressão original com a tabela da saída simplificada ($A + B$):

| $A$ | $B$ | $\bar{A}$ | $\bar{A} + B$ | $\bar{B}$ | $(\bar{A} + B) \cdot \bar{B}$ | $X = \overline{(\bar{A} + B) \cdot \bar{B}}$ |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 0 | 0 | 1 | 1 | 1 | 1 | **0** |
| 0 | 1 | 1 | 1 | 0 | 0 | **1** |
| 1 | 0 | 0 | 0 | 1 | 0 | **1** |
| 1 | 1 | 0 | 1 | 0 | 0 | **1** |

### Tabela-Verdade Reduzida da Porta OR ($A + B$):
*   Combinação `0 + 0` ➔ Saída **0**
*   Combinação `0 + 1` ➔ Saída **1**
*   Combinação `1 + 0` ➔ Saída **1**
*   Combinação `1 + 1` ➔ Saída **1**

*Conclusão:* Como as colunas de resultados finais são rigorosamente idênticas em todas as linhas, fica provado tecnicamente que a simplificação mantém a integridade funcional do circuito.
