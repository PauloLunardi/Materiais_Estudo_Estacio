# Atividade

## Dada a expressão booleana a seguir, aplique passo a passo as propriedades fundamentais da álgebra de Boole para demonstrar sua simplificação completa:

 X = A · A + A · C + B · A + B · C

 Em sua resposta, apresente:

- A sequência de leis utilizadas (por exemplo, comutativa, distributiva, absorção etc.).
- O resultado de cada etapa intermediária.
- A forma final simplificada da expressão.

## 1. Sequência de leis utilizadas e resultados intermediários:

    Dada a expressão: X = A · A + A · C + B · A + B · C

Etapa 1: Aplicação da Lei de Idempotência
O termo (A · A) se simplifica para apenas A.

    -> Resultado: X = A + A · C + B · A + B · C

Etapa 2: Aplicação da Lei Comutativa
Organizando a ordem das letras no terceiro termo (B · A vira A · B) para facilitar o agrupamento.

    -> Resultado: X = A + A · C + A · B + B · C

Etapa 3: Aplicação da Lei Distributiva (Fatoração em evidência)
Colocamos a variável comum "A" em evidência nos três primeiros termos da soma.

    -> Resultado: X = A · (1 + C + B) + B · C

Etapa 4: Aplicação da Lei do Elemento Nulo
Na lógica OR, qualquer variável somada ao número 1 vira 1. Logo, (1 + C + B) = 1.

    -> Resultado: X = A · 1 + B · C

Etapa 5: Aplicação da Lei de Identidade
Qualquer variável multiplicada por 1 na lógica AND é ela mesma (A · 1 = A).

    -> Resultado final: X = A + B · C

## 2. Forma final simplificada:
    X = A + B · C
